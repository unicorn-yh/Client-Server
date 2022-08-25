#ifndef CHANGENAME_H
#define CHANGENAME_H

#include <QDialog>

namespace Ui {
class changeName;
}

class changeName : public QDialog
{
    Q_OBJECT

public:
    explicit changeName(QWidget *parent = nullptr);
    ~changeName();

private slots:
    void on_doneBtn_clicked();

    void on_returnBtn_clicked();

private:
    Ui::changeName *ui;
};

#endif // CHANGENAME_H
