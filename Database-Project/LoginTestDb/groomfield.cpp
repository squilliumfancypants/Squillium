#include "groomfield.h"
#include "ui_groomfield.h"

GroomField::GroomField(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GroomField)
{
    ui->setupUi(this);
}

GroomField::~GroomField()
{
    delete ui;
}
