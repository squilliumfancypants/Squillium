#ifndef HEALTHCAREDIALOG_H
#define HEALTHCAREDIALOG_H

#include <QDialog>
#include <QSqlRelationalTableModel>
#include <QSqlQueryModel>

namespace Ui {
class HealthcareDialog;
}

class HealthcareDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HealthcareDialog(QWidget *parent = 0);
    ~HealthcareDialog();

private:
    Ui::HealthcareDialog *ui;
    QSqlQueryModel *healthcareMainMenu;
};

#endif // HEALTHCAREDIALOG_H
