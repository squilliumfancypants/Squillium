//this dialog is for the admin to enter a new brides info, after a new wedding has been created

#ifndef WEDDINGFIELD_H
#define WEDDINGFIELD_H

#include <QDialog>

namespace Ui {
class WeddingField;
}

class WeddingField : public QDialog
{
    Q_OBJECT

public:
    explicit WeddingField(QWidget *parent = 0);
    ~WeddingField();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::WeddingField *ui;
};

#endif // WeddingField_H
