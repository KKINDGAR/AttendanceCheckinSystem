#include "facecapture.h"
#include <QCameraInfo>
#include <QMessageBox>

FaceCapture *FaceCapture::s_inst = nullptr;

FaceCapture::FaceCapture(QObject *parent) : QObject(parent)
{
    m_cameraOk = initCamera();
    if (!m_cameraOk)
//        qDebug() << "FaceCapture: 摄像头初始化失败（无设备或未连接）";

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &FaceCapture::onTick);
}

FaceCapture::~FaceCapture() { stop(); }

FaceCapture* FaceCapture::instance()
{
    if (!s_inst) s_inst = new FaceCapture;
    return s_inst;
}

bool FaceCapture::initCamera()
{
    auto cams = QCameraInfo::availableCameras();
    if (cams.isEmpty()) return false;

    m_camera  = new QCamera(cams[0]);
    m_capture = new QCameraImageCapture(m_camera);

    connect(m_capture, &QCameraImageCapture::imageCaptured,
            this, &FaceCapture::onCapture);

    m_camera->setCaptureMode(QCamera::CaptureStillImage);
    // 不在此处 start()，由 FaceCapture::start() 按需控制
    return true;
}

void FaceCapture::start()
{
    m_refCount++;
    if (m_refCount == 1 && m_cameraOk && m_camera) {
        m_camera->start();                     // 真正打开摄像头硬件
        if (m_timer) m_timer->start(120);      // 启动定时抓帧
//        qDebug() << "[摄像头] 硬件打开";
    }
}

void FaceCapture::stop()
{
    m_refCount--;
    if (m_refCount <= 0) {
        m_refCount = 0;
        if (m_timer) m_timer->stop();          // 停止定时抓帧
        if (m_cameraOk && m_camera) {
            m_camera->stop();                  // 真正关闭摄像头硬件
//            qDebug() << "[摄像头] 硬件关闭";
        }
    }
}

void FaceCapture::setDisplay(QLabel *label) { m_label = label; }
QImage FaceCapture::currentFrame() const    { return m_frame; }

void FaceCapture::onCapture(int id, const QImage &img)
{
    Q_UNUSED(id);
    // 缩小到 640 宽存为帧（平衡流畅度和检测精度）
    m_frame = img.scaledToWidth(640, Qt::FastTransformation);

    if (m_label && !m_frame.isNull())
        m_label->setPixmap(QPixmap::fromImage(m_frame));

    emit frameCaptured(m_frame);
}

void FaceCapture::onTick()
{
    if (m_cameraOk && m_camera && m_capture && m_camera->state() == QCamera::ActiveState)
        m_capture->capture();
}
