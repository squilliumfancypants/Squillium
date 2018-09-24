#include "dialog.h"
#include "ui_dialog.h"
#include <QtSql>
#include <QSqlRelationalTableModel>
#include <QSqlDatabase>
#include "infofield.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //create the model
    model = new QSqlRelationalTableModel(this);

    //set the table
    model->setTable("students");

    //fill the model with the data from the table
    model->select();

    //display
    ui->tableView->setModel(model);


}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnAdd_clicked()
{

    info = new infoField(this);

    info->show();

}
