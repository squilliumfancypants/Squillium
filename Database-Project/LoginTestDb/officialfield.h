#ifndef OFFICIALFIELD_H
#define OFFICIALFIELD_H

#include <QDialog>

namespace Ui {
class OfficialField;
}

class OfficialField : public QDialog
{
    Q_OBJECT

public:
    explicit OfficialField(QWidget *parent = 0);
    ~OfficialField();

private:
    Ui::OfficialField *ui;
};

#endif // OFFICIALFIELD_H
