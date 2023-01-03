#ifndef DLG_SEAT_H
#define DLG_SEAT_H

#include <QDialog>
#include "menusql.h"
namespace Ui {
class dlg_seat;
}

class dlg_seat : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_seat(QWidget *parent = nullptr);
    ~dlg_seat();
    void updateTable();
private slots:
    void on_btn_exit_clicked();

private:
    Ui::dlg_seat *ui;
    menusql *m_ptrmenusq;
};

#endif // DLG_SEAT_H
