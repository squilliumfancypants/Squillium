#include "officialfield.h"
#include "ui_officialfield.h"

OfficialField::OfficialField(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OfficialField)
{
    ui->setupUi(this);
}

OfficialField::~OfficialField()
{
    delete ui;
}
