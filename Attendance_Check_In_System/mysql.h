#ifndef MYSQL_H
#define MYSQL_H

#include <QObject>
#include <QSqlDatabase> //数据库核心头文件
#include <QSqlQuery>    //数据库操作语句头文件
#include <QSqlError>    //数据库错误捕获头文件
#include <QString>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QFile>
#include <seeta/FaceDetector.h>  //人脸检测头文件
#include <seeta/FaceLandmarker.h>//关键点定位头文件
#include <seeta/FaceRecognizer.h>//特征提取 + 1:1比对头文件
#include <seeta/Common/Struct.h> //人脸数据结构头文件
//数据库类
class MySql : public QObject
{
    Q_OBJECT
private:
    explicit MySql(QObject *parent = nullptr);
    MySql(QString dbName,QObject *parent = nullptr);
    ~MySql();
private:
    //定义一个静态的指针成员保存唯一的实例地址(类中定义，类外实现)
    static MySql *p;
public:
    //创建表
    void creatTable();
    // 插入管理员(卡号，姓名，密码)
    void insertData(QString adminCard, QString name, QString pwd);
    // 刷卡登录(仅验证卡号，无需密码)
    bool adminLoginByCard(QString adminCard);
    // 密码登录(卡号+密码)
    bool adminIsExits(QString adminCard, QString pwd);
    // 密码登录(姓名+密码)
    bool adminLoginByName(QString name, QString pwd);
    // 获取管理员姓名
    bool getAdminName(QString adminCard, QString &name);
    // 修改管理员密码
    bool updateAdminPwd(QString adminCard, QString newPwd);
    // 删除管理员
    bool deleteAdmin(QString adminCard);
    // 注册新员工
    bool insertUser(QString card, QString name, int age, QString sex, QString registerTime);
    // 修改员工信息(卡号不可改)
    bool updateUser(QString card, QString name, int age, QString sex);
    // 删除员工
    bool deleteUser(QString card);
    // 检查员工是否存在
    bool userExists(QString card);
    // 根据卡号获取员工全部信息
    bool getUserByCard(QString card, QString &name, int &age, QString &sex, QString &registerTime, double &balance);
    //根据卡号获取员工的姓名和余额
    bool getUserNameAndBalanceByCard(QString card,QString &name,double &balance);
    // 获取员工余额
    double getUserBalance(QString card);
    //获取员工注册日期
    QString getUserRegisterTime(QString card);
    // 更新员工余额(充值/扣款后)
    bool updateUserBalance(QString card, double newBalance);
    // 签到
    bool checkIn(QString card, QString name, QString date, QString time);
    // 签退
    bool checkOut(QString card, QString date, QString time);
    // 根据卡号检查当天签到状态
    bool isCheckedInTodayByCard(QString card, QString date);
    //根据姓名查询当天状态签到
    bool isCheckedInTodayByName(QString name,QString date);
    //交易记录表(records)
    // 添加交易记录(充值/扣款)
    bool addTransaction(QString card, QString name, QString type, double amount, double balanceAfter, QString remark = "");

    //追加功能：人脸识别
    //更新人脸数据,vector<float> &feature存储人脸数据向量
    bool updateUserFace(QString card,const std::vector<float> &feature);
    //获取所有人脸数据，用于1：N比对
    bool getAllUserFaces(std::vector<std::tuple<QString,QString,std::vector<float>>> &users);
    //定义公共的静态函数来获取唯一的数据库
    static MySql *getMySql(void);

signals:

public slots:
};

#endif // MYSQL_H
