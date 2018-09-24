#include <QCoreApplication>

int main(){
    QCoreApplication app();
    QWidget *pushButton=new QWidget;
    pushButton->setWindowTitle("Enter Your Age: ");

    return app.exec();
}
