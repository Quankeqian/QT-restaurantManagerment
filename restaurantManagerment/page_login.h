#ifndef PAGE_LOGIN_H
#define PAGE_LOGIN_H

#include <QWidget>

namespace Ui {
class Page_Login;
}

class Page_Login : public QWidget
{
    Q_OBJECT

public:
    explicit Page_Login(QWidget *parent = nullptr);
    ~Page_Login();

private slots:
    void on_btn_login_clicked();

    void on_btn_exit_clicked();
    void on_pushButton_clicked();

    void on_btn_reg_clicked();

signals:
    void sendLoginSuccess();

private:
    Ui::Page_Login *ui;
};

#endif // PAGE_LOGIN_H
