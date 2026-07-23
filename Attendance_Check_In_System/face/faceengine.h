#ifndef FACEENGINE_H
#define FACEENGINE_H

#include <QObject>
#include <QImage>
#include <QRect>
#include <vector>
#include <string>

class FaceEngine : public QObject
{
    Q_OBJECT
public:
    ~FaceEngine();

    //懒汉单例模式，模型只加载一次，全局共享
    static FaceEngine* instance();
    static void release();

    //加载三个模型文件
    bool init(const std::string &modelPath);

    //检测人脸+提取特征向量，用于录入对比
    bool detectFace(const QImage &image,std::vector<float> &feature,QRect &faceRect);
    bool detectFace(const QImage &image, std::vector<float> &feature);

    // 1:1 比对相似度（0.0 ~ 1.0）
    float compare(const std::vector<float> &f1, const std::vector<float> &f2);

private:
    explicit FaceEngine(QObject *parent = nullptr);
    FaceEngine(const FaceEngine&) = delete;
    FaceEngine& operator=(const FaceEngine&) = delete;
    static FaceEngine *s_inst;
    class Impl;
    Impl *d;
signals:

public slots:
};

#endif // FACEENGINE_H
