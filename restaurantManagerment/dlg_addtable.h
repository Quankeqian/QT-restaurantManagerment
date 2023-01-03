#ifndef DLG_ADDTABLE_H
#define DLG_ADDTABLE_H
#include "menusql.h"
#include <QDialog>

namespace Ui {
class dlg_addTable;
}

class dlg_addTable : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_addTable(QWidget *parent = nullptr);
    ~dlg_addTable();
    void setType(bool isAdd,tableInfo info={});  //不是add才传id以修改 修改
private slots:
    void on_btn_save_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::dlg_addTable *ui;
    bool m_isAdd;  //修改
    tableInfo m_info; //修改
};

#endif // DLG_ADDTABLE_H
