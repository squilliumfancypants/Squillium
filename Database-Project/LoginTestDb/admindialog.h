#ifndef ADMINDIALOG_H
#define ADMINDIALOG_H

#include "adminweddingview.h"
#include "adminview.h"

#include <QDialog>
#include <QSqlRelationalTableModel>
#include <QtSql>
#include <QSqlDatabase>


namespace Ui {
class AdminDialog;
}

class AdminWeddingView;

class AdminDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdminDialog(QWidget *parent = 0);
    ~AdminDialog();

private slots:
    void on_btnWedding_clicked();

    void on_btnAdmin_clicked();

    void on_btnBrides_clicked();

    void on_btnGrooms_clicked();

    void on_btnOfficials_clicked();

    void on_btnHealthcare_clicked();

private:
    Ui::AdminDialog *ui;
    QSqlRelationalTableModel *userModel;
    QSqlQueryModel *administratorModel;
    AdminDialog *dbInfo;
    AdminWeddingView *weddingView;

};

#endif // AdminDialog_H
