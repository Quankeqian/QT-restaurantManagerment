#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "menusql.h"
#include <QMainWindow>
#include "page_login.h"
#include "dlg_adddish.h"
#include "dlg_addtable.h"
#include "dlg_queue.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_exit_clicked();

    void on_btn_addDish_clicked();

    void on_btn_delDish_clicked();

    void on_btn_updDish_clicked();

    void on_btn_1_clicked();

    void on_btn_2_clicked();

    void on_btn_3_clicked();

    void on_btn_addTable_clicked();

    void on_btn_updTable_clicked();

    void on_btn_delTable_clicked();

    void on_btn_queue_clicked();

    void on_btn_search_clicked();

    void on_btn_search2_clicked();

private:
    void updateTable();
    void updateTable2();
private:
    Ui::MainWindow *ui;
    Page_Login m_dlgLogin;
    menusql *m_ptrmenusql;
    Dlg_addDish m_dlgAdddish;
    dlg_addTable m_dlgAddtable;
    dlg_queue m_dlgQueue;
};
#endif // MAINWINDOW_H
