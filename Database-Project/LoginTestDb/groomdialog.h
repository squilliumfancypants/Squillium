#ifndef GROOMDIALOG_H
#define GROOMDIALOG_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class GroomDialog;
}

class GroomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GroomDialog(QWidget *parent = 0);
    ~GroomDialog();

private:
    Ui::GroomDialog *ui;
    QSqlQueryModel *groomProfile;
};

#endif // GROOMDIALOG_H
