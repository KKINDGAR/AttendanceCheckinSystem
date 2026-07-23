#ifndef FACEDIALOG_H
#define FACEDIALOG_H

#include <QDialog>
#include <QLabel>

// ============================================
// FaceDialog — 独立人脸预览窗口（640×480）
// 非模态，不阻塞主界面，可自由拖动
// ============================================
class FaceDialog : public QDialog
{
    Q_OBJECT
public:
    explicit FaceDialog(QWidget *parent = nullptr);

public slots:
    void onFrame(const QImage &image);  // 接收摄像头帧

    // 设置人脸框+姓名叠印
    void setFaceOverlay(const QRect &faceRect, const QString &name, bool matched);

private:
    QLabel *m_videoLabel;
    QRect   m_faceRect;     // 检测到的人脸框（原图坐标）
    QString m_faceName;     // 匹配到的职员姓名
    bool    m_faceMatched;  // 是否匹配成功
};

#endif // FACEDIALOG_H
