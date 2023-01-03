#ifndef DLG_LINE_H
#define DLG_LINE_H

#include <QDialog>

namespace Ui {
class dlg_line;
}

class dlg_line : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_line(QWidget *parent = nullptr);
    ~dlg_line();

private slots:
    void on_btn_exit_clicked();

    void on_btn_save_clicked();

private:
    Ui::dlg_line *ui;
};

#endif // DLG_LINE_H
