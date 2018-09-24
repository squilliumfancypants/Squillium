#ifndef BRIDEDIALOG_H
#define BRIDEDIALOG_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class BrideDialog;
}

class BrideDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BrideDialog(QWidget *parent = 0);
    ~BrideDialog();

    //functions for getting and putting user login credentials
    void putLoginCredentials(QString un, QString pw);

    QString getLoginCredentialsUN() const;

    QString getLoginCredentialsPW() const;


private:
    Ui::BrideDialog *ui;
    QSqlQueryModel *brideProfile;
    QString username;
    QString password;

};

#endif // BRIDEDIALOG_H
