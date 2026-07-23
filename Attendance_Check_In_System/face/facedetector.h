#ifndef FACEDETECTOR_H
#define FACEDETECTOR_H

#include <QObject>
#include <QImage>
#include <QRect>
#include <vector>

// ============================================
// FaceDetector — 工作线程中的人脸检测+识别
// 所有重活异步执行，不阻塞主线程 UI
// ============================================
class FaceDetector : public QObject
{
    Q_OBJECT
public:
    explicit FaceDetector(QObject *parent = nullptr);
    ~FaceDetector();

public slots:
    void processFrame(const QImage &image);   // 主线程发来一帧

signals:
    void faceDetected(const QImage &image, const QRect &faceRect); // 检测到人脸
    void matchResult(const QString &card, const QString &name, float score); // 比对结果
    void noMatch(float bestScore);            // 比对失败
    void noFace();                            // 无人脸
    void noUsers();                           // 无人脸库

private:
    int m_skipCount = 0;
};

#endif // FACEDETECTOR_H
