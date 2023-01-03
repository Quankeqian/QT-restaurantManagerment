#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,m_ptrmenusql(nullptr)
{
    ui->setupUi(this);
    m_dlgLogin.show(); //阻塞一下
    //this->hide(); //隐藏主界面
    auto f = [&](){
        this->show();
    };
    connect(&m_dlgLogin,&Page_Login::sendLoginSuccess,this,f);  //收到发送成功，自动跳到主界面
//    ui->treeWidget->clear(); //我
//    ui->treeWidget->setColumnCount(1); //设置列数

//    QStringList l;
//    l<<"业务服务";
//    QTreeWidgetItem *pf = new QTreeWidgetItem(ui->treeWidget,l);
//    ui->treeWidget->addTopLevelItem(pf); //设置选项

//    l.clear();
//    l<<"菜品管理";
//    QTreeWidgetItem *p1 = new QTreeWidgetItem(pf,l);

//    l.clear();
//    l<<"餐桌管理";
//    QTreeWidgetItem *p2 = new QTreeWidgetItem(pf,l);

//    l.clear();
//    l<<"点菜";
//    QTreeWidgetItem *p3 = new QTreeWidgetItem(pf,l);

//    l.clear();
//    l<<"排座";
//    QTreeWidgetItem *p4 = new QTreeWidgetItem(pf,l);

//    l.clear();
//    l<<"排队";
//    QTreeWidgetItem *p5 = new QTreeWidgetItem(pf,l);

//    l.clear();
//    l<<"收银";
//    QTreeWidgetItem *p6 = new QTreeWidgetItem(pf,l);

//    pf->addChild(p1);
//    pf->addChild(p2);
//    pf->addChild(p3);
//    pf->addChild(p4);
//    pf->addChild(p5);
//    pf->addChild(p6);
//    ui->treeWidget->expandAll(); //默认展开目录

    m_ptrmenusql = menusql::getinstance();
    m_ptrmenusql->init();

//    //显示表格内容
//    QList<dishInfo> ldishes = m_ptrmenusql->getAllDish();
//    ui ->tableWidget ->setRowCount(ldishes.size());
//    for(int i = 0;i<ldishes.size();i++){
//        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(ldishes[i].id )));
//        ui->tableWidget->setItem(i,1,new QTableWidgetItem(ldishes[i].name ));
//        ui->tableWidget->setItem(i,2,new QTableWidgetItem(ldishes[i].type ));
//        ui->tableWidget->setItem(i,3,new QTableWidgetItem(ldishes[i].material ));
//        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(ldishes[i].price )));
//    }
    updateTable();
    updateTable2();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_exit_clicked()
{
    exit(0);
}

//增加菜品
void MainWindow::on_btn_addDish_clicked()
{
    m_dlgAdddish.setType(true);
    m_dlgAdddish.exec();    //显示添加菜品界面并阻塞（禁止其他界面操作）
    updateTable();
}

//更新菜品表格
void MainWindow::updateTable()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(6);
    QStringList l;
    l<<"菜品编号"<<"菜品名称"<<"类别"<<"原材料"<<"价格"<<"折扣";
    ui->tableWidget->setHorizontalHeaderLabels(l);

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); // 只选中行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //显示表格内容
    QList<dishInfo> ldishes = m_ptrmenusql->getAllDish();
    ui ->tableWidget ->setRowCount(ldishes.size());
    for(int i = 0;i<ldishes.size();i++){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(ldishes[i].id )));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(ldishes[i].name ));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(ldishes[i].type ));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(ldishes[i].material ));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(ldishes[i].price )));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(ldishes[i].discount )));
    }
}

//更新餐桌表格
void MainWindow::updateTable2()
{
    ui->tableWidget_2->clear();
    ui->tableWidget_2->setColumnCount(3);
    QStringList l;
    l<<"餐桌序号"<<"餐桌容量"<<"餐桌状态";
    ui->tableWidget_2->setHorizontalHeaderLabels(l);

    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows); // 只选中行
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //显示表格内容
    QList<tableInfo> ltables = m_ptrmenusql->getAlltable();
    ui ->tableWidget_2 ->setRowCount(ltables.size());
    for(int i = 0;i<ltables.size();i++){
        ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(ltables[i].id ));
        ui->tableWidget_2->setItem(i,1,new QTableWidgetItem(QString::number(ltables[i].capacity)));
        ui->tableWidget_2->setItem(i,2,new QTableWidgetItem(ltables[i].status ));
    }
}

//删除菜品
void MainWindow::on_btn_delDish_clicked()
{
    int i = ui->tableWidget->currentRow();
    qDebug()<<i;
    if(i > 0){
        //int id = ui->tableWidget->item(i,1)->text().toUInt(); //有问题 无法正常获取id
        int id=i+1;
        qDebug()<<id;
        m_ptrmenusql->delDish(id); //直接用行号代替了id  要求id务必和行号相同
        updateTable();
        QMessageBox::information(nullptr,"信息","删除成功");
    }
}

//更新菜品
void MainWindow::on_btn_updDish_clicked()
{
    dishInfo info;
    int i = ui->tableWidget->currentRow();
    if(i>=0){
        info.id = ui->tableWidget->item(i,0)->text().toUInt();
        info.name = ui->tableWidget->item(i,1)->text();
        info.type = ui->tableWidget->item(i,2)->text();
        info.material = ui->tableWidget->item(i,3)->text();
        info.price = ui->tableWidget->item(i,4)->text().toUInt();
        m_dlgAdddish.setType(false,info);
        m_dlgAdddish.exec();
        updateTable();
    }
}




void MainWindow::on_btn_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_btn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_btn_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

//增加餐桌
void MainWindow::on_btn_addTable_clicked()
{
    m_dlgAddtable.setType(true);
    m_dlgAddtable.exec();    //显示添加菜品界面并阻塞（禁止其他界面操作）
    updateTable2();
}

//修改餐桌
void MainWindow::on_btn_updTable_clicked()
{
    tableInfo info;
    int i = ui->tableWidget_2->currentRow();
    if(i>=0){
        info.id = ui->tableWidget_2->item(i,0)->text();
        info.capacity = ui->tableWidget_2->item(i,1)->text().toUInt();
        info.status = ui->tableWidget_2->item(i,2)->text();
        m_dlgAddtable.setType(false,info);
        m_dlgAddtable.exec();
        updateTable2();
    }
}

//删除餐桌
void MainWindow::on_btn_delTable_clicked()
{
    int i = ui->tableWidget_2->currentRow();
    qDebug()<<i;
    if(i > 0){
        QString id = ui->tableWidget_2->item(i,0)->text();
        //int id=i+1;
        qDebug()<<id;
        m_ptrmenusql->delTable(id); //直接用行号代替了id  要求id务必和行号相同
        updateTable2();
        QMessageBox::information(nullptr,"信息","删除成功");
    }
}


void MainWindow::on_btn_queue_clicked()
{
    m_dlgQueue.exec();
}


//搜索菜品
void MainWindow::on_btn_search_clicked()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(5);
    QStringList l;
    l<<"菜品编号"<<"菜品名称"<<"类别"<<"原材料"<<"价格";
    ui->tableWidget->setHorizontalHeaderLabels(l);

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); // 只选中行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //显示表格内容
    QList<dishInfo> ldishes = m_ptrmenusql->getAllDish();
    ui ->tableWidget ->setRowCount(ldishes.size());

    QString strFiter = ui->lineEdit_search->text();
    int index = 0;
    for(int i = 0;i<ldishes.size();i++){
        if(!ldishes[i].name.contains(strFiter)){
            continue;
        }
        ui->tableWidget->setItem(index,0,new QTableWidgetItem(QString::number(ldishes[i].id )));
        ui->tableWidget->setItem(index,1,new QTableWidgetItem(ldishes[i].name ));
        ui->tableWidget->setItem(index,2,new QTableWidgetItem(ldishes[i].type ));
        ui->tableWidget->setItem(index,3,new QTableWidgetItem(ldishes[i].material ));
        ui->tableWidget->setItem(index,4,new QTableWidgetItem(QString::number(ldishes[i].price )));
        index++;
    }
}


void MainWindow::on_btn_search2_clicked()
{
    ui->tableWidget_2->clear();
    ui->tableWidget_2->setColumnCount(3);
    QStringList l;
    l<<"餐桌序号"<<"餐桌容量"<<"餐桌状态";
    ui->tableWidget_2->setHorizontalHeaderLabels(l);

    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows); // 只选中行
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //显示表格内容
    QList<tableInfo> ltables = m_ptrmenusql->getAlltable();

    ui ->tableWidget_2 ->setRowCount(ltables.size());
    QString strFiter = ui->lineEdit_search2->text();
    int index = 0;
    for(int i = 0;i<ltables.size();i++){
        if(!ltables[i].id.contains(strFiter)){
            continue;
        }
        ui->tableWidget_2->setItem(index,0,new QTableWidgetItem(ltables[i].id ));
        ui->tableWidget_2->setItem(index,1,new QTableWidgetItem(QString::number(ltables[i].capacity)));
        ui->tableWidget_2->setItem(index,2,new QTableWidgetItem(ltables[i].status ));
        index++;
    }
}

