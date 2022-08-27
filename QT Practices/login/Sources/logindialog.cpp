#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QDebug>

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
    //open database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("im.db");
    if(!db.open()){
        qDebug() << "open database error";
        return;
    }

    //create table
    QSqlQuery query;
    query.exec("create table login(id int NOT NULL UNIQUE, \
                                    username vchar(32), \
                                    password vchar(32), \
                                    PRIMARY KEY(id))");

    //insert data
    QString username = ui->usrLineEdit->text().trimmed();
    QString password = ui->pwdLineEdit->text();
    query.exec("select * from login");
    bool userExist = false;
    bool credential = false;
    int row = 0;
    while(query.next()){
        row++;
        qDebug() << query.value(0).toInt() << query.value(1).toString() << query.value(2).toString();
        if(query.value(1).toString()==username){
            userExist = true;
            if(query.value(2).toString()==password){
                credential = true;
                break;
            }
        }
    }

    if(!userExist){
        if(username!= ""){
            int id = 1 + row;
            QString insertSql = QString("insert into %1(id,username,password) \
                                    values('%2','%3','%4')").arg("login",QString::number(id),username,password);
            qDebug() << insertSql;
            query.exec(insertSql);
        }
    }
    //%1: 1st argument, value="login"
    //%2: 2nd argument, value=username
    //%3: 3rd argument, value=password

    //login status
    if(userExist && credential){
        QMessageBox::information(NULL, tr("Note"), tr("Login success!"));
        accept();
    }
    else if(userExist && credential==false){
        QMessageBox::warning(this, tr("warning"),
                             tr("password error!"), QMessageBox::Yes);
        ui->pwdLineEdit->clear();
        ui->pwdLineEdit->setFocus();
    }
    else{
        QMessageBox::information(NULL, tr("Info"), tr("New account registered! Please login."));
        ui->usrLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->usrLineEdit->setFocus();
    }
}

