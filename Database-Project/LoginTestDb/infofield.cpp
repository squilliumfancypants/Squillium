#include "infofield.h"
#include "ui_infofield.h"

infoField::infoField(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infoField)
{
    ui->setupUi(this);
}

infoField::~infoField()
{
    delete ui;
}

void infoField::on_buttonBox_accepted()
{

}

void infoField::on_buttonBox_rejected()
{

}
