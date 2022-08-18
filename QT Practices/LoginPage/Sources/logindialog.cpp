#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->usrLineEdit->setFocus();
}

LoginDialog::~LoginDialog()
{
    delete ui;
}


void LoginDialog::on_loginBtn_clicked()
{
    //accept();
    if(ui->usrLineEdit->text().trimmed() == tr("user") &&
            ui->pwdLineEdit->text().trimmed() == tr("123")){
        QMessageBox::information(NULL, tr("Note"), tr("Login success!"));
        accept();
    }
    else{
        QMessageBox::warning(this, tr("warning"),
                             tr("username or password error!"), QMessageBox::Yes);
        ui->usrLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->usrLineEdit->setFocus();
    }
}