#include "mysql.h"
#include <QDebug>

MySql * const MySql::p = new MySql("AttendanceSystem.db");

MySql::MySql(QObject *parent) : QObject(parent)
{

}

MySql::MySql(QString dbName, QObject *parent) : QObject (parent)
{
    //安装sqlite驱动
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //创建具体的基于SQlite的数据库名称
    db.setDatabaseName(dbName);
    //判断打开数据库
    if(db.open())
    {
        // 启用WAL模式：允许多线程并发读写，避免database is locked
        QSqlQuery q(db);
        q.exec("PRAGMA journal_mode=WAL");
qDebug()<<"OK"<<endl;
    }
    else
    {
qDebug()<<"error:"<<db.lastError().text()<<endl;
    }
}

MySql::~MySql()
{
}


void MySql::creatTable()
{
    QSqlQuery query;//sql语句预处理对象
    QString sql;

    // 管理员表
    sql = "CREATE TABLE IF NOT EXISTS admin("
              "adminCard TEXT NOT NULL PRIMARY KEY,"
              "pwd TEXT NOT NULL,"
              "name TEXT NOT NULL)";
    if(query.exec(sql))
    {
qDebug()<<"admin is ok"<<endl;
    }
    else
    {
qDebug()<<"admin is error:"<<query.lastError().text()<<endl;
    }

    // 员工表
    sql = "CREATE TABLE IF NOT EXISTS user("
              "card TEXT NOT NULL PRIMARY KEY,"
              "name TEXT NOT NULL,"
              "age INT NOT NULL CHECK(age>=0 AND age<=100),"
              "sex TEXT NOT NULL CHECK(sex IN('男','女')),"
              "registerTime TEXT NOT NULL,"
              "balance REAL NOT NULL DEFAULT 0.00,"
              "faceFeature BLOB"
          ")";
    if(query.exec(sql))
    {
qDebug()<<"user is ok"<<endl;
    }
    else
    {
qDebug()<<"user is error:"<<query.lastError().text()<<endl;
    }
    // 兼容旧库：如果表已存在但没有 faceFeature 列，则追加
    query.exec("ALTER TABLE user ADD COLUMN faceFeature BLOB");

    // 考勤记录表
    sql = "CREATE TABLE IF NOT EXISTS card("
              "id INTEGER PRIMARY KEY AUTOINCREMENT,"
              "card TEXT NOT NULL,"
              "name TEXT NOT NULL,"
              "date TEXT NOT NULL,"
              "checkInTime TEXT DEFAULT '',"
              "checkOutTime TEXT DEFAULT '',"
              "status TEXT NOT NULL DEFAULT '正常' CHECK(status IN('正常','迟到','早退','缺勤'))"
          ")";
    if(query.exec(sql))
    {
qDebug()<<"card is ok"<<endl;
    }
    else
    {
qDebug()<<"card is error:"<<query.lastError().text()<<endl;
    }

    // 充值扣款记录表
    sql = "CREATE TABLE IF NOT EXISTS records("
              "id INTEGER PRIMARY KEY AUTOINCREMENT,"
              "card TEXT NOT NULL,"
              "name TEXT NOT NULL,"
              "type TEXT NOT NULL CHECK(type IN('充值','扣款')),"
              "amount REAL NOT NULL,"
              "balanceAfter REAL NOT NULL,"
              "remark TEXT DEFAULT ''"
          ")";
    if(query.exec(sql))
    {
qDebug()<<"transaction is ok"<<endl;
    }
    else
    {
qDebug()<<"transaction is error:"<<query.lastError().text()<<endl;
    }
    // 兼容旧库：如果 records 表已存在但没有 remark 列，则追加
    query.exec("ALTER TABLE records ADD COLUMN remark TEXT DEFAULT ''");

    // 超级管理员初始化：首次建表时自动插入默认 root 账户
    QSqlQuery countQ;
    if (countQ.exec("SELECT COUNT(*) FROM admin") && countQ.next() && countQ.value(0).toInt() == 0) {
        insertData("c2-23-d6-e9", "root", "123456");
qDebug() << "Super admin initialized: root/123456";
    }
}


// 插入管理员(卡号，姓名，密码)
void MySql::insertData(QString adminCard, QString name, QString pwd)
{
    QSqlQuery query;
    query.prepare("INSERT INTO admin VALUES(:adminCard,:pwd,:name)");
    query.bindValue(":adminCard",adminCard);
    query.bindValue(":pwd",pwd);
    query.bindValue(":name",name);
    if(query.exec())
    {
qDebug()<<"执行插入语句成功,新纪录的ID:"<<query.lastInsertId().toInt()<<endl;
    }
    else
    {
qDebug()<<"执行插入语句失败,error:"<<query.lastError().text()<<endl;
    }
}

// 刷卡登录(仅验证卡号是否存在，无需密码)
bool MySql::adminLoginByCard(QString adminCard)
{
    QSqlQuery query;
    query.prepare("SELECT adminCard FROM admin WHERE adminCard=:adminCard");
    query.bindValue(":adminCard",adminCard);
    if(query.exec() && query.next())
    {
qDebug()<<"刷卡登录成功"<<endl;
        return true;
    }
qDebug()<<"刷卡登录失败,卡号不存在"<<endl;
    return false;
}

// 密码登录(卡号+密码)
bool MySql::adminIsExits(QString adminCard, QString pwd)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM admin WHERE adminCard=:adminCard AND pwd=:pwd");
    query.bindValue(":adminCard",adminCard);
    query.bindValue(":pwd",pwd);
    if(query.exec())
    {
qDebug()<<"执行查询语句成功"<<endl;
    }
    else
    {
qDebug()<<"执行查询语句失败,error:"<<endl;
    }

    //遍历查询结果（是否存在adminCard和pwd）
    while(query.next())
    {
        return true;//找到一行
    }
    return false;
}

// 密码登录(姓名+密码)
bool MySql::adminLoginByName(QString name, QString pwd)
{
    QSqlQuery query;
    query.prepare("SELECT name FROM admin WHERE name=:name AND pwd=:pwd");
    query.bindValue(":name",name);
    query.bindValue(":pwd",pwd);
    if(query.exec() && query.next())
    {
qDebug()<<"姓名密码登录成功"<<endl;
        return true;
    }
qDebug()<<"姓名密码登录失败"<<endl;
    return false;
}

// 获取管理员姓名
bool MySql::getAdminName(QString adminCard, QString &name)
{
    QSqlQuery query;
    query.prepare("SELECT name FROM admin WHERE adminCard=:adminCard");
    query.bindValue(":adminCard",adminCard);
    if(query.exec() && query.next())
    {
        name = query.value(0).toString();
        return true;
    }
    return false;
}

// 修改管理员密码
bool MySql::updateAdminPwd(QString adminCard, QString newPwd)
{
    QSqlQuery query;
    query.prepare("UPDATE admin SET pwd=:pwd WHERE adminCard=:adminCard");
    query.bindValue(":pwd",newPwd);
    query.bindValue(":adminCard",adminCard);
    if(query.exec())
    {
qDebug()<<"管理员密码修改成功"<<endl;
        return true;
    }
qDebug()<<"管理员密码修改失败:"<<query.lastError().text()<<endl;
    return false;
}

// 删除管理员
bool MySql::deleteAdmin(QString adminCard)
{
    QSqlQuery query;
    query.prepare("DELETE FROM admin WHERE adminCard=:adminCard");
    query.bindValue(":adminCard",adminCard);
    if(query.exec())
    {
qDebug()<<"管理员删除成功"<<endl;
        return true;
    }
qDebug()<<"管理员删除失败:"<<query.lastError().text()<<endl;
    return false;
}


// 注册新员工
bool MySql::insertUser(QString card, QString name, int age, QString sex, QString registerTime)
{
    QSqlQuery query;
    query.prepare("INSERT INTO user(card,name,age,sex,registerTime,balance,faceFeature) VALUES(:card,:name,:age,:sex,:registerTime,0.00,NULL)");
    query.bindValue(":card",card);
    query.bindValue(":name",name);
    query.bindValue(":age",age);
    query.bindValue(":sex",sex);
    query.bindValue(":registerTime",registerTime);
    if(query.exec())
    {
qDebug()<<"员工注册成功"<<endl;
        return true;
    }
qDebug()<<"员工注册失败:"<<query.lastError().text()<<endl;
    return false;
}

// 修改员工信息(只允许改姓名、年龄、性别)
bool MySql::updateUser(QString card, QString name, int age, QString sex)
{
    QSqlQuery query;
    query.prepare("UPDATE user SET name=:name, age=:age, sex=:sex WHERE card=:card");
    query.bindValue(":name",name);
    query.bindValue(":age",age);
    query.bindValue(":sex",sex);
    query.bindValue(":card",card);
    if(query.exec())
    {
qDebug()<<"员工信息修改成功"<<endl;
        return true;
    }
qDebug()<<"员工信息修改失败:"<<query.lastError().text()<<endl;
    return false;
}

// 删除员工
bool MySql::deleteUser(QString card)
{
    QSqlQuery query;
    query.prepare("DELETE FROM user WHERE card=:card");
    query.bindValue(":card",card);
    if(query.exec())
    {
qDebug()<<"员工删除成功"<<endl;
        return true;
    }
qDebug()<<"员工删除失败:"<<query.lastError().text()<<endl;
    return false;
}

// 检查员工是否存在
bool MySql::userExists(QString card)
{
    QSqlQuery query;
    query.prepare("SELECT card FROM user WHERE card=:card");
    query.bindValue(":card",card);
    if(query.exec() && query.next())
        return true;
    return false;
}

// 根据卡号获取员工全部信息
bool MySql::getUserByCard(QString card, QString &name, int &age, QString &sex, QString &registerTime, double &balance)
{
    QSqlQuery query;
    query.prepare("SELECT name,age,sex,registerTime,balance FROM user WHERE card=:card");
    query.bindValue(":card",card);
    if(query.exec() && query.next())
    {
        name = query.value(0).toString();
        age = query.value(1).toInt();
        sex = query.value(2).toString();
        registerTime = query.value(3).toString();
        balance = query.value(4).toDouble();
        return true;
    }
    return false;
}

//根据卡号获取员工姓名和余额
bool MySql::getUserNameAndBalanceByCard(QString card,QString &name,double &balance)
{
    QSqlQuery query;
    query.prepare("SELECT name,balance FROM user WHERE card=:card");
    query.bindValue(":card",card);
    if(query.exec() && query.next())
    {
        name = query.value(0).toString();
        balance = query.value(1).toDouble();
        return true;
    }
    return false;
}
// 获取员工余额
double MySql::getUserBalance(QString card)
{
    QSqlQuery query;
    query.prepare("SELECT balance FROM user WHERE card=:card");
    query.bindValue(":card",card);
    if(query.exec() && query.next())
        return query.value(0).toDouble();
    return 0.00;
}


//获取注册时间
QString MySql::getUserRegisterTime(QString card)
{
    QSqlQuery query;
    query.prepare("SELECT registerTime FROM user WHERE card=:card");
    query.bindValue("card:",card);
    if(query.exec()&&query.next())
    {
        return  query.value(0).toString();
    }
    return "error";
}

// 更新员工余额(充值/扣款后)
bool MySql::updateUserBalance(QString card, double newBalance)
{
    QSqlQuery query;
    query.prepare("UPDATE user SET balance=:balance WHERE card=:card");
    query.bindValue(":balance",newBalance);
    query.bindValue(":card",card);
    if(query.exec())
    {
qDebug()<<"余额更新成功"<<endl;
        return true;
    }
qDebug()<<"余额更新失败:"<<query.lastError().text()<<endl;
    return false;
}


// 签到
bool MySql::checkIn(QString card, QString name, QString date, QString time)
{
    QSqlQuery query;
    // 状态判断：<09:00 正常，≥09:00 迟到
    QString status = (time < "09:00") ? "正常" : "迟到";
    query.prepare("INSERT INTO card(card,name,date,checkInTime,status) VALUES(:card,:name,:date,:time,:st)");
    query.bindValue(":card",card);
    query.bindValue(":name",name);
    query.bindValue(":date",date);
    query.bindValue(":time",time);
    query.bindValue(":st",status);
    if(query.exec())
    {
qDebug()<<"签到成功("<<status<<")"<<endl;
        return true;
    }
qDebug()<<"签到失败:"<<query.lastError().text()<<endl;
    return false;
}

// 签退（含早退判断）
bool MySql::checkOut(QString card, QString date, QString time)
{
    QSqlQuery query;
    // 签退时更新状态：<18:00 早退，≥18:00 保持签到状态
    QString st = (time < "18:00") ? "早退" : "";
    if (st.isEmpty()) {
        query.prepare("UPDATE card SET checkOutTime=:time WHERE card=:card AND date=:date AND checkOutTime=''");
    } else {
        query.prepare("UPDATE card SET checkOutTime=:time, status=:st WHERE card=:card AND date=:date AND checkOutTime=''");
        query.bindValue(":st",st);
    }
    query.bindValue(":time",time);
    query.bindValue(":card",card);
    query.bindValue(":date",date);
    if(query.exec() && query.numRowsAffected() > 0)
    {
qDebug()<<"签退成功("<<st<<")"<<endl;
        return true;
    }
qDebug()<<"签退失败(无签到记录或已签退):"<<endl;
    return false;
}


// 根据卡号检查当天签到状态
bool MySql::isCheckedInTodayByCard(QString card, QString date)
{
    QSqlQuery query;
    query.prepare("SELECT id FROM card WHERE card=:card AND date=:date");
    query.bindValue(":card",card);
    query.bindValue(":date",date);
    if(query.exec() && query.next())
        return true;
    return false;
}

bool MySql::isCheckedInTodayByName(QString name, QString date)
{
    QSqlQuery query;
    query.prepare("SELECT id FROM card WHERE name=:name AND date=:date");
    query.bindValue(":name",name);
    query.bindValue(":date",date);
    if(query.exec() && query.next())
        return true;
    return false;
}

// 添加交易记录(充值/扣款)
bool MySql::addTransaction(QString card, QString name, QString type, double amount, double balanceAfter, QString remark)
{
    QSqlQuery query;
    // id为自增主键，不指定则SQLite自动分配
    query.prepare("INSERT INTO records(card,name,type,amount,balanceAfter,remark) VALUES(:card,:name,:type,:amount,:balanceAfter,:remark)");
    query.bindValue(":card",card);
    query.bindValue(":name",name);
    query.bindValue(":type",type);
    query.bindValue(":amount",amount);
    query.bindValue(":balanceAfter",balanceAfter);
    query.bindValue(":remark",remark);
    if(query.exec())
    {
qDebug()<<"交易记录添加成功"<<endl;
        return true;
    }
qDebug()<<"交易记录添加失败:"<<query.lastError().text()<<endl;
    return false;
}

bool MySql::updateUserFace(QString card, const std::vector<float> &feature)
{
    QSqlQuery query;
    query.prepare("UPDATE user SET faceFeature=:feat WHERE card=:card");
    QByteArray blob(reinterpret_cast<const char*>(feature.data()),feature.size() * sizeof(float));
    query.bindValue(":feat", blob);
    query.bindValue(":card", card);
    return query.exec();
}

bool MySql::getAllUserFaces(std::vector<std::tuple<QString, QString, std::vector<float> > > &users)
{
    QSqlQuery query;
        query.exec("SELECT card, name, faceFeature FROM user WHERE faceFeature IS NOT NULL");
        while (query.next()) {
            QString card = query.value(0).toString();
            QString name = query.value(1).toString();
            QByteArray blob = query.value(2).toByteArray();
            std::vector<float> feat(blob.size() / sizeof(float));
            memcpy(feat.data(), blob.data(), blob.size());
            users.emplace_back(card, name, feat);
        }
        return true;
}

MySql *MySql::getMySql()
{
    return p;
}
