#include "facecapture.h"
#include <QCameraInfo>
#include <QMessageBox>

FaceCapture *FaceCapture::s_inst = nullptr;

FaceCapture::FaceCapture(QObject *parent) : QObject(parent)
{
    m_cameraOk = initCamera();
    if (!m_cameraOk)
        qDebug() << "FaceCapture: 摄像头初始化失败（无设备或未连接）";

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
    m_camera->start();
    return true;
}

void FaceCapture::start()  { if (m_timer) m_timer->start(300); }   // 300ms 间隔
void FaceCapture::stop()   { if (m_timer) m_timer->stop(); }

void FaceCapture::setDisplay(QLabel *label) { m_label = label; }
QImage FaceCapture::currentFrame() const    { return m_frame; }

void FaceCapture::onCapture(int id, const QImage &img)
{
    Q_UNUSED(id);
    m_frame = img;
    if (m_label && !img.isNull())
        m_label->setPixmap(QPixmap::fromImage(img)
            .scaled(m_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    emit frameCaptured(img);
}

void FaceCapture::onTick()
{
    if (m_cameraOk && m_camera && m_capture && m_camera->state() == QCamera::ActiveState)
        m_capture->capture();
}
