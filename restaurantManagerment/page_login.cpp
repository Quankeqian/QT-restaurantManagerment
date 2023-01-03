#include "page_login.h"
#include "ui_page_login.h"
#include "menusql.h"
#include<QMessageBox>
#include<QSqlQuery> //sql查询语句
Page_Login::Page_Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page_Login)
{
    ui->setupUi(this);
}

Page_Login::~Page_Login()
{
    delete ui;
}

void Page_Login::on_btn_login_clicked()
{
    //获取输入信息
    userInfo info;
    //auto ptr = menusql::getinstance();
    info.account = ui->le_userID->text();
    info.password = ui->le_password->text();
    //数据库查找用户名和密码
    QSqlQuery query;
    QString strSql = QString("select * from user where account = '%1' and password = '%2'").
            arg(info.account).
            arg(info.password);
    //失败则提示
    if(!query.exec(strSql)){
        qDebug()<<query.exec(strSql);
        return;
    }

    //成功进入主界面
    if(query.next()){
        emit sendLoginSuccess(); //进入主界面并发一个消息
        this->hide(); //隐藏登录界面
    }
    else{
         QMessageBox::information(nullptr,"信息","账号或密码错误");
    }


}


void Page_Login::on_btn_exit_clicked()
{
    exit(0);//退出
}




void Page_Login::on_btn_reg_clicked()
{

    userInfo info;
    auto ptr = menusql::getinstance();
    info.account = ui->le_userID->text();
    info.password = ui->le_password->text();
    ptr->adduser(info);

//    if(m_isAdd){
//        ptr->addDish(info);
//    }
//    else{
//        ptr ->updateDish(info);
//    }
    QMessageBox::information(nullptr,"注册","注册成功");

}

