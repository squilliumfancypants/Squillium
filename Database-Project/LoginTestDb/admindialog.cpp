#include "admindialog.h"
#include "ui_admindialog.h"
#include "adminweddingview.h"

#include <QtSql>
#include <QSqlRelationalTableModel>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>


AdminDialog::AdminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminDialog)
{
    ui->setupUi(this);

}

AdminDialog::~AdminDialog()
{
    delete ui;
}

void AdminDialog::on_btnWedding_clicked()
{
    weddingView = new AdminWeddingView(this);
    weddingView->show();
}

void AdminDialog::on_btnAdmin_clicked()
{

}

void AdminDialog::on_btnBrides_clicked()
{

}

void AdminDialog::on_btnGrooms_clicked()
{

}

void AdminDialog::on_btnOfficials_clicked()
{

}

void AdminDialog::on_btnHealthcare_clicked()
{

}
