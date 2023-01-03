#ifndef MENUSQL_H
#define MENUSQL_H

#include <QObject>
#include<QSqlDatabase>
struct dishInfo{
    int id;
    QString name;
    QString type;
    QString material;
    float price;
    float discount;
};
struct userInfo{
    QString account;
    QString password;
};

struct tableInfo{
    QString id;
    int capacity;
    QString status;
};

struct queInfo{
    QString qno;
    QString qcno;
    int qnum;
    QString qstate;
    QString qontime;
    QString qofftime;
};

class menusql : public QObject
{
    Q_OBJECT
public:
    static menusql *ptrmenuSql;
    static menusql *getinstance(){
        if(nullptr == ptrmenuSql){
            ptrmenuSql = new menusql;
        }
        return ptrmenuSql;
    }
    explicit menusql(QObject *parent = nullptr);
    //初始化数据库
    void init();

    //菜品函数
    //1.查看现有菜品信息
    QList<dishInfo> getAllDish();
    //2.增加研制的新菜品
    bool addDish(dishInfo info);
    //3.删除不方便供应旧菜品
    bool delDish(int id);
    //4.修改现有菜品信息
    void updateDish(dishInfo info);

    //用户函数
    //用户注册（添加用户）
    bool adduser(userInfo info);

    //餐桌函数
    //1.查看餐桌信息
    QList<tableInfo> getAlltable();
    //2.增加餐桌
    bool addTable(tableInfo info);
    //3.修改餐桌
    void updateTable(tableInfo info);
    //4.删除不方便供应旧菜品
     bool delTable(QString id);
    //5.获取空闲餐桌
    QList<tableInfo> getFreetable();

    //获取二人桌排队数据
    QList<queInfo> getq1();
    //获取四人桌排队数据
    QList<queInfo> getq2();
    //获取圆桌排队数据
    QList<queInfo> getq3();
    //增加排队数据
    bool addLine(queInfo info);
    //入座时修改排队信息修改餐桌状态
    void updateLine(tableInfo infot,queInfo infoq);
    //删除排队记录
    bool delLine(QString qno);
signals:
private:
    QSqlDatabase m_db;  //声明QSqlDatabase的成员变量
};

#endif // MENUSQL_H
