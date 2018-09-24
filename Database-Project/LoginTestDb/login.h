#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QDialog>
#include <QSqlRelationalTableModel>
#include "admindialog.h"
#include "bridedialog.h"
#include "groomdialog.h"
#include "officialdialog.h"
#include "healthcaredialog.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:

    void on_btnLogin_clicked();

private:
    Ui::Login *ui;
    QSqlDatabase db;
    QSqlRelationalTableModel *model;
    AdminDialog *dbInfo;
    BrideDialog *brideInfo;
    GroomDialog *groomInfo;
    OfficialDialog *officialInfo;
    HealthcareDialog *hcUserInfo;
};

#endif // LOGIN_H
