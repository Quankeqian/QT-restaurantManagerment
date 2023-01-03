#include "mainwindow.h"
#include <QApplication>
#include <menusql.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();
    menusql sql;
    if (QSqlDatabase::drivers().isEmpty())
        qDebug()<<"No database drivers found";

    //连接数据库
    QSqlDatabase m_db;
    m_db = QSqlDatabase::addDatabase("QSQLITE"); //建立连接
/*
    auto str = QCoreApplication::applicationDirPath()+"data.db"; //获取数据库文件路径
    qDebug()<<str; //输出
*/
    m_db.setDatabaseName("D:\\databases\\data.db");   //关联数据库
    if(!m_db.open())                          //打开数据库
        qDebug()<<"database open failed";
    return a.exec();
}
