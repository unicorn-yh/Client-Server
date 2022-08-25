#include "changepassword.h"
#include "ui_changepassword.h"
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>

changePassword::changePassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changePassword)
{
    ui->setupUi(this);
}

changePassword::~changePassword()
{
    delete ui;
}


void changePassword::on_doneBtn2_clicked()
{
    bool validPassword = true;
    QString newPassword = ui->newPassword->text();
    QString newPassword2 = ui->newPassword2->text();
    int size = newPassword.size();
    int size2 = newPassword2.size();

    //open database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("im.db");
    if(!db.open()){
        qDebug() << "open database error";
        return;
    }
    QSqlQuery query;

    if(newPassword=="" || newPassword2==""){
        qDebug() << "更换用户密码失败！";
        QMessageBox::warning(this, tr("警告"), tr("密码不能为空！"), QMessageBox::Yes);
        ui->newPassword->setFocus();
        return;
    }
    for(int i=0;i<size;i++){
        if(!(newPassword[i].isDigit())){
            qDebug() << "更换用户密码失败！";
            QMessageBox::warning(this, tr("警告"), tr("密码只能包含数字！"), QMessageBox::Yes);
            ui->newPassword->setFocus();
            return;
        }
    }
    if(size<6 || size>12 || size2<6 || size2>12){
        qDebug() << "更换用户密码失败！";
        QMessageBox::warning(this, tr("警告"), tr("密码长度需介于6-12之间！"), QMessageBox::Yes);
        ui->newPassword->setFocus();
        return;
    }
    if(newPassword != newPassword2){
        qDebug() << "更换用户密码失败！";
        QMessageBox::warning(this, tr("警告"), tr("输入密码不相同！"), QMessageBox::Yes);
        ui->newPassword->clear();
        ui->newPassword2->clear();
        ui->newPassword->setFocus();
        return;
    }


    if(validPassword == true){
        int id = 1;
        query.prepare("UPDATE user SET password=:pwd WHERE id=:id2");  //更新数据库的用户密码
        query.bindValue(":pwd", newPassword);
        query.bindValue(":id2", id);
        query.exec();
        QMessageBox::information(NULL, tr("提示"), tr("更换用户密码成功！"));
        accept();
    }
}


void changePassword::on_returnBtn2_clicked()
{
    close();
    qDebug() << "退出修改用户密码界面";
}

