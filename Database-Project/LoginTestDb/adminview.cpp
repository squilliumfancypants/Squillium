#include "adminview.h"
#include "ui_adminview.h"
#include "admindialog.h"
#include "weddingfield.h"

#include <QtSql>
#include <QSqlRelationalTableModel>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>


AdminView::AdminView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminView)
{
    ui->setupUi(this);

    //create the model

}

AdminView::~AdminView()
{
    delete ui;
}
