#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSqlRelationalTableModel>
#include <QtSql>
#include <QSqlDatabase>
#include "infofield.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_btnAdd_clicked();

private:
    Ui::Dialog *ui;
    QSqlRelationalTableModel *model;
    Dialog *studentInfo;
    infoField *info;
};

#endif // DIALOG_H
