//this dialog is for the admin to enter a new grooms info, after a new wedding has been created

#ifndef GROOMFIELD_H
#define GROOMFIELD_H

#include <QDialog>

namespace Ui {
class GroomField;
}

class GroomField : public QDialog
{
    Q_OBJECT

public:
    explicit GroomField(QWidget *parent = 0);
    ~GroomField();

private:
    Ui::GroomField *ui;
};

#endif // GROOMFIELD_H
