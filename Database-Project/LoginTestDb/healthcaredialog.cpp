#include "healthcaredialog.h"
#include "ui_healthcaredialog.h"

#include <QSqlQueryModel>

HealthcareDialog::HealthcareDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HealthcareDialog)
{
    ui->setupUi(this);

    QString fn = "sharry", ln, dob;

    //create model
    this->healthcareMainMenu = new QSqlQueryModel();

    //query db for users info
    healthcareMainMenu->setQuery("SELECT `first_name`, `last_name`, `birthdate`, `username`, `email`, `phone`, `hiv_status`, `motherFN`, `fatherFN` FROM bride WHERE first_name = '"+ fn +"'");

    ui->tableViewBride->setModel(healthcareMainMenu);
}

HealthcareDialog::~HealthcareDialog()
{
    delete ui;
}
