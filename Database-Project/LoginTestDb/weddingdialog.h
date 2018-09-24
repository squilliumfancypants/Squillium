#ifndef WEDDINGDIALOG_H
#define WEDDINGDIALOG_H

#include <QDialog>

namespace Ui {
class WeddingDialog;
}

class WeddingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WeddingDialog(QWidget *parent = 0);
    ~WeddingDialog();

private:
    Ui::WeddingDialog *ui;
};

#endif // WEDDINGDIALOG_H
