#include "groomdialog.h"
#include "ui_groomdialog.h"

#include <QSqlQueryModel>

GroomDialog::GroomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GroomDialog)
{
    ui->setupUi(this);

    //create model
    this->groomProfile = new QSqlQueryModel();

    //query db for users info
    groomProfile->setQuery("SELECT `first_name`, `last_name`, `birthdate`, `username`, `email`, `phone`, `hiv_status`, `motherFN`, `fatherFN` FROM groom WHERE 1");

    ui->tableView->setModel(groomProfile);
}

GroomDialog::~GroomDialog()
{
    delete ui;
}
