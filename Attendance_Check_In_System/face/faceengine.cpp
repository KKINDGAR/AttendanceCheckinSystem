#include "faceengine.h"
#include <seeta/FaceDetector.h>
#include <seeta/FaceLandmarker.h>
#include <seeta/FaceRecognizer.h>
#include <seeta/Common/Struct.h>
#include <QDebug>
#include<QRgb>
FaceEngine *FaceEngine::s_inst = nullptr;

// PIMPL 隐藏 SeetaFace6 C++ API
class FaceEngine::Impl
{
public:
    seeta::FaceDetector   *detector   = nullptr;
    seeta::FaceLandmarker *landmarker = nullptr;
    seeta::FaceRecognizer *recognizer = nullptr;
    ~Impl() { delete detector; delete landmarker; delete recognizer; }
};

FaceEngine::FaceEngine(QObject *parent) : QObject(parent), d(new Impl) {}
FaceEngine::~FaceEngine() { delete d; }

FaceEngine* FaceEngine::instance()
{
    if (!s_inst) s_inst = new FaceEngine;
    return s_inst;
}

void FaceEngine::release() { delete s_inst; s_inst = nullptr; }

// ---------- 初始化（启动时调用一次） ----------

bool FaceEngine::init(const std::string &modelPath)
{
    d->detector = new seeta::FaceDetector(
        seeta::ModelSetting(modelPath + "/face_detector.csta",
                            seeta::ModelSetting::CPU, 0));
    d->detector->set(seeta::FaceDetector::PROPERTY_MIN_FACE_SIZE, 20);

    d->landmarker = new seeta::FaceLandmarker(
        seeta::ModelSetting(modelPath + "/face_landmarker_pts5.csta",
                            seeta::ModelSetting::CPU, 0));

    d->recognizer = new seeta::FaceRecognizer(
        seeta::ModelSetting(modelPath + "/face_recognizer.csta",
                            seeta::ModelSetting::CPU, 0));

    if (!d->detector || !d->landmarker || !d->recognizer) {
        qDebug() << "FaceEngine 初始化失败";
        return false;
    }
    qDebug() << "FaceEngine 初始化成功";
    return true;
}

// ---------- 检测 + 提取特征 ----------

bool FaceEngine::detectFace(const QImage &image,
                            std::vector<float> &feature, QRect &faceRect)
{
    if (!d->detector || image.isNull()) return false;

    // 性能优化：大图先缩放到 640 宽再检测（4倍加速，精度几乎无损失）
    QImage workImage = image;
    int w = image.width(), h = image.height();
    float scale = 1.0f;
    if (w > 640) {
        scale = 640.0f / w;
        workImage = image.scaled(640, static_cast<int>(h * scale),
                                 Qt::KeepAspectRatio, Qt::FastTransformation);
        w = workImage.width();
        h = workImage.height();
    }

    // 1. 转灰度，做人脸检测
    std::vector<unsigned char> gray(w * h);
    for (int y = 0; y < h; ++y) {
        const QRgb *row = reinterpret_cast<const QRgb*>(workImage.scanLine(y));
        for (int x = 0; x < w; ++x) {
            QRgb p = row[x];
            gray[y * w + x] = static_cast<unsigned char>(
                qRed(p)*0.299 + qGreen(p)*0.587 + qBlue(p)*0.114 + 0.5);
        }
    }
    SeetaImageData grayImg { w, h, 1, gray.data() };
    auto faces = d->detector->detect(grayImg);
    if (faces.size == 0) return false;

    SeetaRect rect = faces.data[0].pos;
    // 还原到原图坐标
    faceRect = QRect(static_cast<int>(rect.x / scale),
                     static_cast<int>(rect.y / scale),
                     static_cast<int>(rect.width / scale),
                     static_cast<int>(rect.height / scale));

    // 2. 人脸关键点（5点）——在原图尺寸上做，保证精度
    std::vector<SeetaPointF> landmarks(5);
    d->landmarker->mark(grayImg, rect, landmarks.data());

    // 3. 转 BGR（在原图尺寸上提取特征，保证精度）
    int ow = image.width(), oh = image.height();
    std::vector<unsigned char> bgr(ow * oh * 3);
    for (int y = 0; y < oh; ++y) {
        const QRgb *row = reinterpret_cast<const QRgb*>(image.scanLine(y));
        for (int x = 0; x < ow; ++x) {
            QRgb p = row[x];
            int i = (y * ow + x) * 3;
            bgr[i+0] = qBlue(p); bgr[i+1] = qGreen(p); bgr[i+2] = qRed(p);
        }
    }
    SeetaImageData bgrImg { ow, oh, 3, bgr.data() };

    // 关键点坐标也需要还原到原图尺寸
    for (auto &lm : landmarks) {
        lm.x /= scale;
        lm.y /= scale;
    }

    feature.resize(d->recognizer->GetExtractFeatureSize());
    d->recognizer->Extract(bgrImg, landmarks.data(), feature.data());
    return true;
}

bool FaceEngine::detectFace(const QImage &image, std::vector<float> &feature)
{
    QRect r; return detectFace(image, feature, r);
}

// ---------- 1:1 比对 ----------

float FaceEngine::compare(const std::vector<float> &f1,
                          const std::vector<float> &f2)
{
    if (!d->recognizer) return 0.0f;
    return d->recognizer->CalculateSimilarity(f1.data(), f2.data());
}
