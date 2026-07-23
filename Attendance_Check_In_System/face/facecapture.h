#ifndef FACECAPTURE_H
#define FACECAPTURE_H

#include <QObject>
#include <QCamera>
#include <QCameraImageCapture>
#include <QTimer>
#include <QLabel>
#include <QImage>

class FaceCapture : public QObject
{
    Q_OBJECT

public:
    ~FaceCapture();
    static FaceCapture* instance();

    void start();                        // 开始定时抓帧
    void stop();                         // 停止
    void setDisplay(QLabel *label);      // 摄像头画面显示目标
    QImage currentFrame() const;         // 最新一帧

signals:
    void frameCaptured(const QImage &image);  // 每一帧

private slots:
    void onCapture(int id, const QImage &img);
    void onTick();

private:
    explicit FaceCapture(QObject *parent = nullptr);
    bool initCamera();

    static FaceCapture *s_inst;
    bool                 m_cameraOk = false;
    QCamera             *m_camera = nullptr;
    QCameraImageCapture *m_capture = nullptr;
    QTimer              *m_timer  = nullptr;
    QLabel              *m_label  = nullptr;
    QImage               m_frame;
};
#endif
