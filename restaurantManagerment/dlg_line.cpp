#include "dlg_line.h"
#include "ui_dlg_line.h"
#include "menusql.h"
#include "QMessageBox"
#include<QTime>
dlg_line::dlg_line(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_line)
{
    ui->setupUi(this);
}

dlg_line::~dlg_line()
{
    delete ui;
}

void dlg_line::on_btn_exit_clicked()
{
    this->hide();
}


void dlg_line::on_btn_save_clicked()
{
    QTime time = QTime::currentTime(); //获取系统时间
    queInfo info;
    auto ptr = menusql::getinstance();
    info.qno = ui->lineEdit_qno->text();
    info.qcno = ui->lineEdit_cno->text();
    info.qnum = ui->lineEdit_qnum->text().toUInt();
    info.qstate = "排队中";
    info.qontime =time.toString("hh:mm:ss");
    ptr->addLine(info);
    QMessageBox::information(nullptr,"信息","存储成功");
    this->hide(); //隐藏添加菜品界面
}

