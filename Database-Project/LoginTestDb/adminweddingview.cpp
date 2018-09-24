#include "adminweddingview.h"
#include "ui_adminweddingview.h"
#include "admindialog.h"

#include <QSqlDatabase>
#include <QSql>
#include <QSqlRelationalTableModel>

AdminWeddingView::AdminWeddingView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminWeddingView)
{
    ui->setupUi(this);

    //create the weddingModel
    weddingModel = new QSqlRelationalTableModel(this);

    //set the table
    weddingModel->setTable("wedding");

    /* The db has relations built-in, I made the model a QSqlRelationalTableModel in case we want to
     * utilize this feature
    //set the relations, col 2 is bride, col 3 is groom, col 4 is official
    weddingModel->setRelation(2, QSqlRelation("bride","id", "first_name"));
    weddingModel->setRelation(3, QSqlRelation("groom", "id", "first_name"));
    weddingModel->setRelation(4, QSqlRelation("official", "id", "first_name"));
    */
    //fill the weddingModel with the data from the table
    weddingModel->select();

    //display
    ui->tableView->setModel(weddingModel);
}

AdminWeddingView::~AdminWeddingView()
{
    delete ui;
}
