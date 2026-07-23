#include "facedialog.h"
#include <QVBoxLayout>
#include <QPainter>
#include <QDebug>

FaceDialog::FaceDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("人脸识别窗口");
    setMinimumSize(660, 520);
    resize(660, 520);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(5, 5, 5, 5);

    m_videoLabel = new QLabel(this);
    m_videoLabel->setAlignment(Qt::AlignCenter);
    m_videoLabel->setMinimumSize(640, 480);
    m_videoLabel->setStyleSheet(
        "QLabel{ border: 2px solid #3498DB; border-radius: 8px; background: black; "
        "color: #888; font-size:18px; }");
    m_videoLabel->setText("等待摄像头...");
    layout->addWidget(m_videoLabel);
}

void FaceDialog::onFrame(const QImage &image)
{
    if (image.isNull()) return;

    QImage display = image.copy();
    int iw = image.width(), ih = image.height();

    // 在当前帧上画人脸框+姓名
    if (m_faceRect.isValid() && m_faceRect.x() < iw && m_faceRect.y() < ih) {
        QPainter p(&display);
        QColor color = m_faceMatched ? QColor(39, 174, 96) : QColor(231, 76, 60);
        p.setPen(QPen(color, 3));
        p.drawRect(m_faceRect);

        if (!m_faceName.isEmpty()) {
            // 文字背景
            QString text = m_faceMatched ? m_faceName : QString("未知 (%1)").arg(m_faceName);
            QFont font("Microsoft YaHei", 16, QFont::Bold);
            p.setFont(font);
            QFontMetrics fm(font);
            int tw = fm.horizontalAdvance(text) + 20;
            int th = fm.height() + 8;
            int tx = m_faceRect.x();
            int ty = m_faceRect.y() - th - 5;
            if (ty < 5) ty = m_faceRect.bottom() + 5;

            p.fillRect(tx, ty, tw, th, color);
            p.setPen(Qt::white);
            p.drawText(tx + 10, ty + fm.ascent() + 4, text);
        }
        p.end();
    }

    m_videoLabel->setPixmap(
        QPixmap::fromImage(display)
            .scaled(m_videoLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void FaceDialog::setFaceOverlay(const QRect &faceRect, const QString &name, bool matched)
{
    m_faceRect = faceRect;
    m_faceName = name;
    m_faceMatched = matched;
}
