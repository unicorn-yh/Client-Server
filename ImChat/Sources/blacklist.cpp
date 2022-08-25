#include "blacklist.h"
#include "ui_blacklist.h"
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include "qpushbutton.h"
#include "qframe.h"
#include <QFrame>

blackList::blackList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::blackList)
{
    ui->setupUi(this);
    displayBlackListUser();
}

blackList::~blackList()
{
    delete ui;
}

void blackList::displayBlackListUser()
{
    //open database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("im.db");
    if(!db.open()){
        qDebug() << "open database error";
        return;
    }
    QSqlQuery query;
    query.exec("select id, username from user");

   /* QString insertSql = QString("insert into %1(id,username,password,sex,phone) values('%2','%3','%4','%5','%6')").arg("user",QString::number(2),QString("user12345"),QString("password123"),QString("女"),QString("18944567724"));
    qDebug() << insertSql;
    query.exec(insertSql);*/

    int y_coord = 87;
    int y_coord2 = 110;
    while(query.next()){
        QLabel *label = new QLabel(this);
        label->setText(query.value(1).toString());
        QFont font = label->font();
        font.setPointSize(16);
        label->setFont(font);
        label->move(40,y_coord);
        QPushButton *btn = new QPushButton(tr("拉出黑名单"),this);
        int id = query.value(0).toInt();
        QString s = QString::number(id);
        btn->setObjectName(s);
        qDebug() << s;
        btn->move(250,y_coord);
        btn->text().resize(20);
        btn->resize(100,33),
        connect(btn,SIGNAL(clicked()),this,SLOT(outBtn()));
        y_coord += 66;
        /*QFrame *line = new QFrame(this);
        line->HLine;
        line->move(20,110);
        y_coord2 += 66;*/
    }
}

void blackList::outBtn(){
    QString btnName = this->objectName();
    qDebug() << btnName;
}

