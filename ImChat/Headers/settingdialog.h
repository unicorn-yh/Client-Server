#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>

namespace Ui {
class settingDialog;
}

class settingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit settingDialog(QWidget *parent = nullptr);
    ~settingDialog();

private slots:
    void change_Name();
    void change_Password();
    void black_list();

private:
    Ui::settingDialog *ui;
};

#endif // SETTINGDIALOG_H
