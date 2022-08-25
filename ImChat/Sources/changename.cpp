#include "changename.h"
#include "ui_changename.h"
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>

changeName::changeName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changeName)
{
    ui->setupUi(this);
}

changeName::~changeName()
{
    delete ui;
}

void changeName::on_doneBtn_clicked()
{
    bool validName = true;
    bool nameExist = false;
    bool containDigit = false;
    bool containAlpha = false;
    QString newName = ui->newName->text();
    int size = newName.size();

    //open database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("im.db");
    if(!db.open()){
        qDebug() << "open database error";
        return;
    }

    //create table
    QSqlQuery query;
    //创建用户个人资料数据库
   /* query.exec("create table user(id int NOT NULL UNIQUE, \
                                    username vchar(32), \
                                    password vchar(32), \
                                    sex vchar(2), \
                                    phone vchar(15), \
                                    PRIMARY KEY(id))");

    //用户个人聊天记录数据库
    query.exec("create table friend(id1 int NOT NULL UNIQUE, \
                                    id2 int NOT NULL UNIQUE, \
                                     chat_history vchar(32), \
                                     PRIMARY KEY(id1,id2), \
                                     FOREIGN KEY(id1) REFERENCES user(id), \
                                     FOREIGN KEY(id2) REFERENCES user(id))");*/

    query.exec("select id,username from user");
    while(query.next()){
        if(query.value(1).toString() == newName){  //查询数据库得知该用户名是否被使用过
            nameExist = true;
        }
    }
    if(newName==""){
        qDebug() << "更换用户名失败！";
        QMessageBox::warning(this, tr("警告"), tr("用户名不能为空！"), QMessageBox::Yes);
        return;
    }
    if(size<8 || size>20){
        qDebug() << "更换用户名失败！";
        QMessageBox::warning(this, tr("警告"), tr("用户名长度需介于8-20之间！"), QMessageBox::Yes);
        return;
    }
    if(newName.contains(" ")){
        qDebug() << "更换用户名失败！";
        QMessageBox::warning(this, tr("警告"), tr("该用户名无法使用！"), QMessageBox::Yes);
        return;
    }
    for(int i=0;i<size;i++){       //判断用户名是否包含字母和数字
        if(newName[i].isDigit()){
            containDigit = true;
        }
        else if(newName[i].isLetter()){
            containAlpha = true;
        }
    }
    if(!containAlpha || !containDigit){
        qDebug() << "更换用户名失败！";
        QMessageBox::warning(this, tr("警告"), tr("用户名需包含字母和数字！"), QMessageBox::Yes);
        return;
    }

    if(nameExist){
        qDebug() << "更换用户名失败！";
        QMessageBox::warning(this, tr("警告"), tr("该用户名已被其它用户使用！"), QMessageBox::Yes);
        return;
    }


    if(validName == true){
        int id = 1;
        query.prepare("UPDATE user SET username=:name WHERE id=:id2");  //更新数据库的用户名
        query.bindValue(":name", newName);
        query.bindValue(":id2", id);
        query.exec();
        QMessageBox::information(NULL, tr("提示"), tr("更换用户名成功！"));
        accept();
    }

}


void changeName::on_returnBtn_clicked()
{
    close();
    qDebug() << "退出修改用户名界面";
}

