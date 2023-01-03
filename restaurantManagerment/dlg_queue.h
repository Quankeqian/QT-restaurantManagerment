#ifndef DLG_QUEUE_H
#define DLG_QUEUE_H

#include "dlg_line.h"
#include "dlg_seat.h"
#include "menusql.h"
#include <QDialog>

namespace Ui {
class dlg_queue;
}

class dlg_queue : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_queue(QWidget *parent = nullptr);
    ~dlg_queue();
    void updateTable1();
    void updateTable2();
    void updateTable3();
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_btn_del2_clicked();

    void on_btn_seat_clicked();

private:
    Ui::dlg_queue *ui;
    menusql *m_ptrmenusq;
    dlg_line m_dlgLine;
    dlg_seat m_dlgSeat;
};

#endif // DLG_QUEUE_H
