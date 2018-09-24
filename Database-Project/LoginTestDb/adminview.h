#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include "weddingfield.h"

#include <QDialog>
#include <QSqlRelationalTableModel>
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class AdminView;
}

class AdminView : public QDialog
{
    Q_OBJECT

public:
    explicit AdminView(QWidget *parent = 0);
    ~AdminView();

private:
    Ui::AdminView *ui;
    QSqlQueryModel *weddingModel;
    WeddingField *newWeddingField;
};

#endif // ADMINVIEW_H
