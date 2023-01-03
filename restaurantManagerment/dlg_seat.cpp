#include "dlg_seat.h"
#include "ui_dlg_seat.h"

dlg_seat::dlg_seat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_seat)
{
    ui->setupUi(this);
    m_ptrmenusq = menusql::getinstance();
    m_ptrmenusq->init();
    updateTable();
}

dlg_seat::~dlg_seat()
{
    delete ui;
}

void dlg_seat::updateTable()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(2);
    QStringList l;
    l<<"餐桌序号"<<"餐桌容量";
    ui->tableWidget->setHorizontalHeaderLabels(l);

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); // 只选中行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //显示表格内容
    QList<tableInfo> ltables = m_ptrmenusq->getFreetable();
    ui ->tableWidget ->setRowCount(ltables.size());
    for(int i = 0;i<ltables.size();i++){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(ltables[i].id ));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(ltables[i].capacity)));
    }
}

void dlg_seat::on_btn_exit_clicked()
{
    this->hide();  //隐藏添加菜品界面
}

