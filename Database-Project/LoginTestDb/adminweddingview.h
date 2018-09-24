#ifndef ADMINWEDDINGVIEW_H
#define ADMINWEDDINGVIEW_H

#include "admindialog.h"

#include <QDialog>
#include <QSqlRelationalTableModel>

namespace Ui {
class AdminWeddingView;
}

class AdminWeddingView : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWeddingView(QWidget *parent = 0);
    ~AdminWeddingView();

private:
    Ui::AdminWeddingView *ui;
    QSqlRelationalTableModel *weddingModel;
};

#endif // ADMINWEDDINGVIEW_H
