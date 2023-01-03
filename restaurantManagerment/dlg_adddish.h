#ifndef DLG_ADDDISH_H
#define DLG_ADDDISH_H

#include "menusql.h"
#include <QDialog>

namespace Ui {
class Dlg_addDish;
}

class Dlg_addDish : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_addDish(QWidget *parent = nullptr);
    ~Dlg_addDish();

    void setType(bool isAdd,dishInfo info={});  //不是add才传id以修改 修改
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dlg_addDish *ui;
    bool m_isAdd;  //修改
    //int m_id;
    dishInfo m_info; //修改
};

#endif // DLG_ADDDISH_H
