#ifndef INFOFIELD_H
#define INFOFIELD_H

#include <QDialog>

namespace Ui {
class infoField;
}

class infoField : public QDialog
{
    Q_OBJECT

public:
    explicit infoField(QWidget *parent = 0);
    ~infoField();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::infoField *ui;
};

#endif // INFOFIELD_H
