#ifndef OFFICIALDIALOG_H
#define OFFICIALDIALOG_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class OfficialDialog;
}

class OfficialDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OfficialDialog(QWidget *parent = 0);
    ~OfficialDialog();

private:
    Ui::OfficialDialog *ui;
    QSqlQueryModel *officialProfile;
};

#endif // OFFICIALDIALOG_H
