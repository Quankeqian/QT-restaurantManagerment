#include "dlg_addtable.h"
#include "ui_dlg_addtable.h"
#include "menusql.h"
#include "QMessageBox"
dlg_addTable::dlg_addTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_addTable)
{
    ui->setupUi(this);
}

dlg_addTable::~dlg_addTable()
{
    delete ui;
}

void dlg_addTable::setType(bool isAdd, tableInfo info)
{
    m_isAdd = isAdd;
    m_info = info;
    ui->lineEdit_id->setText(info.id);
    ui->lineEdit_cap->setText(QString::number(info.capacity));
    ui->lineEdit_status->setText(info.status);
}

void dlg_addTable::on_btn_save_clicked()
{
    tableInfo info;
    auto ptr = menusql::getinstance();
    info.id = ui->lineEdit_id->text();
    info.capacity = ui->lineEdit_cap->text().toUInt();
    info.status = ui->lineEdit_status->text();

    if(m_isAdd){
        ptr->addTable(info);
    }
    else{
        ptr ->updateTable(info);
    }

    QMessageBox::information(nullptr,"信息","存储成功");
    this->hide(); //隐藏添加菜品界面
}


void dlg_addTable::on_btn_cancel_clicked()
{
    this->hide();
}

