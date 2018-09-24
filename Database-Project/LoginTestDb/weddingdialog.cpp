#include "weddingdialog.h"
#include "ui_weddingdialog.h"

WeddingDialog::WeddingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WeddingDialog)
{
    ui->setupUi(this);
}

WeddingDialog::~WeddingDialog()
{
    delete ui;
}
