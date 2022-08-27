#include "mainwindow.h"
#include "settingdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    settingDialog dlg;
    if(dlg.exec() == QDialog::Accepted){
        w.show();
        return a.exec();
    }
    else return 0;
}
