#include "officialdialog.h"
#include "ui_officialdialog.h"

OfficialDialog::OfficialDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OfficialDialog)
{
    ui->setupUi(this);

    //create model
    this->officialProfile = new QSqlQueryModel();

    //query db for users info
    officialProfile->setQuery("SELECT `first_name`, `last_name`, `birthdate`, `username`, `email`, `phone`, `hiv_status`, `motherFN`, `fatherFN` FROM groom WHERE 1");

    ui->tableView->setModel(officialProfile);
}

OfficialDialog::~OfficialDialog()
{
    delete ui;
}
