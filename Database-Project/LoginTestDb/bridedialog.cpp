#include "bridedialog.h"
#include "ui_bridedialog.h"

#include <QSqlQueryModel>
#include <QtSql>
#include <QSqlDatabase>
#include <QString>

BrideDialog::BrideDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrideDialog)
{
    ui->setupUi(this);

    //create model
    this->brideProfile = new QSqlQueryModel();

    //query db for users info
    brideProfile->setQuery("SELECT `first_name`, `last_name`, `birthdate`, `username`, `email`, `phone`, `hiv_status`, `motherFN`, `fatherFN` FROM bride WHERE 1");

    ui->tableView->setModel(brideProfile);

}

BrideDialog::~BrideDialog()
{
    delete ui;
}

//gets username from login page
void BrideDialog::putLoginCredentials(QString un, QString pw){
    username = un;
    password = pw;
}

QString BrideDialog::getLoginCredentialsUN() const{
    return username;
}

QString BrideDialog::getLoginCredentialsPW() const{
    return password;
}




