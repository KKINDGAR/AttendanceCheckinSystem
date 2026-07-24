#include "facedetector.h"
#include "faceengine.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <cstring>

static bool s_dbReady = false;

FaceDetector::FaceDetector(QObject *parent) : QObject(parent) {}
FaceDetector::~FaceDetector() {}

void FaceDetector::processFrame(const QImage &image)
{
    if (++m_skipCount < 5) return;
    m_skipCount = 0;
    if (image.isNull()) return;

    // 首次使用时在此线程中创建独立数据库连接
    if (!s_dbReady) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "face_worker");
        db.setDatabaseName("AttendanceSystem.db");
        s_dbReady = db.open();
        if (s_dbReady) {
            QSqlQuery q(db); q.exec("PRAGMA journal_mode=WAL");
        }
qDebug() << "[Worker] DB连接:" << (s_dbReady ? "成功" : "失败");
    }
    if (!s_dbReady) return;

    static int procCount = 0;
qDebug() << "[Worker] 处理帧" << ++procCount << "尺寸:" << image.width() << "x" << image.height();

    std::vector<float> feat;
    QRect faceRect;
    if (!FaceEngine::instance()->detectFace(image, feat, faceRect)) {
qDebug() << "[Worker] 未检测到人脸";
        emit noFace();
        return;
    }

qDebug() << "[Worker] 检测到人脸:" << faceRect;
    emit faceDetected(image, faceRect);

    // 查人脸库
    std::vector<std::tuple<QString, QString, std::vector<float>>> users;
    {
        QSqlDatabase db = QSqlDatabase::database("face_worker");
        QSqlQuery query(db);
        query.exec("SELECT card, name, faceFeature FROM user WHERE faceFeature IS NOT NULL");
        while (query.next()) {
            QString card = query.value(0).toString();
            QString name = query.value(1).toString();
            QByteArray blob = query.value(2).toByteArray();
            std::vector<float> f(blob.size() / sizeof(float));
            memcpy(f.data(), blob.data(), blob.size());
            users.emplace_back(card, name, f);
        }
    }

qDebug() << "[Worker] 人脸库:" << users.size() << "条";

    if (users.empty()) {
        emit noUsers();
        return;
    }

    float bestScore = 0.0f;
    QString bestCard, bestName;
    FaceEngine *fe = FaceEngine::instance();

    for (const auto &u : users) {
        float s = fe->compare(feat, std::get<2>(u));
        if (s > bestScore) { bestScore = s; bestCard = std::get<0>(u); bestName = std::get<1>(u); }
    }

qDebug() << "[Worker] 最佳:" << bestName << bestScore;

    if (bestScore >= 0.75f)
        emit matchResult(bestCard, bestName, bestScore);
    else
        emit noMatch(bestScore);
}
