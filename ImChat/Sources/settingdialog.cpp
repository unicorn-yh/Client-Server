#include "settingdialog.h"
#include "ui_settingdialog.h"
#include "mylabel.h"
#include "changename.h"
#include "changepassword.h"
#include "blacklist.h"

settingDialog::settingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settingDialog)
{
    ui->setupUi(this);
    connect(ui->changeName,SIGNAL(Mouse_Pressed()),this,SLOT(change_Name()));
    connect(ui->changePassword,SIGNAL(Mouse_Pressed()),this,SLOT(change_Password()));
    connect(ui->blacklist,SIGNAL(Mouse_Pressed()),this,SLOT(black_list()));
    connect(ui->logout,SIGNAL(Mouse_Pressed()),this,SLOT(log_out()));


}

settingDialog::~settingDialog()
{
    delete ui;
}

void settingDialog::change_Name()
{
   qDebug() << "进入修改用户名界面" ;
   changeName c;
   c.setWindowTitle("修改用户名");
   if(c.exec() == QDialog::Accepted){
       qDebug() << "更换用户名成功！";
       qDebug() << "退出修改用户名界面";
   }
}

void settingDialog::change_Password()
{
   qDebug() << "进入修改用户密码界面" ;
   changePassword c;
   c.setWindowTitle("修改用户密码");
   if(c.exec() == QDialog::Accepted){
       qDebug() << "更换用户密码成功！";
       qDebug() << "退出修改用户密码界面";
   }
}

void settingDialog::black_list()
{
    qDebug() << "进入修改用户密码界面" ;
    blackList c;
    c.setWindowTitle("黑名单");
    if(c.exec() == QDialog::Accepted){
        qDebug() << "成功把好友拉出黑名单！";
        qDebug() << "退出黑名单界面";
    }
}

