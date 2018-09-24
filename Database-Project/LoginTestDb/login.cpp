#include "login.h"
#include "ui_login.h"
#include "admindialog.h"
#include "bridedialog.h"
#include "groomdialog.h"
#include "officialdialog.h"
#include "healthcaredialog.h"

#include <QtSql>
#include <QSqlDatabase>
#include <QDialog>
#include <QSqlRelationalTableModel>

#include <QMessageBox>

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    //connect to database
    db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");

    db.setDatabaseName("test");

    db.setUserName("root");

    db.setPassword("");

    if (db.open()){
        ui->label->setText("Connected Successfully");
    }

    else{
        ui->label->setText("Failed to Connect");
    }


}

Login::~Login()
{
    delete ui;
}



void Login::on_btnLogin_clicked()
{
    //store username and password in strings for comparison
    QString uDname = ui->fieldUsername->text();
    QString uDpass = ui->fieldPassword->text();

    QSqlQuery qry;

    qry.exec("SELECT * FROM administrators WHERE username = '"+ uDname +"' and password = '"+ uDpass +"'");

    if (!qry.isActive()){
        QMessageBox::critical(this, "SQL Error", qry.lastError().text());
    }

    else{

        //login success
        if(qry.next()){
            QMessageBox::information(this,"Success", "Successfully Logged in");

            //create new dialog populated with info in database for admin who logged in
            ui->label->setText("Login Successful");

            hide();
            dbInfo = new AdminDialog(this);
            dbInfo->show();

        }

            //login failed, check bride info
            else{
                qry.exec("SELECT * FROM bride WHERE username = '"+ uDname +"' and password = '"+ uDpass +"'");

                if (!qry.isActive()){
                    QMessageBox::critical(this, "SQL Error", qry.lastError().text());
                }

            else{

                    //login success
                    if(qry.next()){
                        QMessageBox::information(this,"Success", "Successfully Logged in");

                        //get the role of the user


                        //create new dialog populated with info in database for user(bride) who logged in
                        ui->label->setText("Login Successful");

                        hide();
                        brideInfo = new BrideDialog(this);
                        brideInfo->putLoginCredentials(uDname, uDpass);
                        brideInfo->show();
                        brideInfo->setWindowTitle("Bride's Info");

            }

                //login failed, check groom info
                else{
                    qry.exec("SELECT * FROM groom WHERE username = '"+ uDname +"' and password = '"+ uDpass +"'");

                        if (!qry.isActive()){
                            QMessageBox::critical(this, "SQL Error", qry.lastError().text());
                        }

                        else{

                            //login success
                            if(qry.next()){
                                QMessageBox::information(this,"Success", "Successfully Logged in");

                                //create new dialog populated with info in database for user(groom) who logged in
                                ui->label->setText("Login Successful");

                                hide();
                                groomInfo = new GroomDialog(this);
                                groomInfo->show();
                                groomInfo->setWindowTitle("Groom's Info");
                            }

                        //login failed, check official info
                        else{
                            qry.exec("SELECT * FROM official WHERE username = '"+ uDname +"' and password = '"+ uDpass +"'");

                            if (!qry.isActive()){
                                QMessageBox::critical(this, "SQL Error", qry.lastError().text());
                            }

                            else{
                                //login success
                                if(qry.next()){
                                    QMessageBox::information(this,"Success", "Successfully Logged in");

                                    //create new dialog populated with info in database for user(groom) who logged in
                                    ui->label->setText("Login Successful");

                                    hide();
                                    officialInfo = new OfficialDialog(this);
                                    officialInfo->show();
                                    officialInfo->setWindowTitle("Official's Page");
                                }

                                //login failed, check healthcare info
                                else{
                                    qry.exec("SELECT * FROM healthcare WHERE username = '"+ uDname +"' and password = '"+ uDpass +"'");

                                    if (!qry.isActive()){
                                        QMessageBox::critical(this, "SQL Error", qry.lastError().text());
                                    }

                                    else{

                                        //login success
                                        if(qry.next()){
                                            QMessageBox::information(this,"Success", "Successfully Logged in");

                                            //create new dialog populated with info in database for user(groom) who logged in
                                            ui->label->setText("Login Successful");

                                            hide();
                                            hcUserInfo = new HealthcareDialog(this);
                                            hcUserInfo->show();
                                            hcUserInfo->setWindowTitle("Healthcare Worker's Page");
                                        }

                                       //all logins failed, print error message
                                       else{

                                       QMessageBox::critical(this,"Login Error", "Username/Password Not Found");
                                       }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


/*
 *
 *Remnents from previous idea
 *
if (role.exec("SELECT role FROM administrators WHERE username = '"+ uDname +"' and password = '"+ uDpass +"'")){
    //create new dialog populated with info in database for admin who logged in
    ui->label->setText("Login Successful");

    hide();
    dbInfo = new AdminDialog(this);
    dbInfo->show();
}

else if (role.exec("SELECT role FROM bride WHERE username = '"+ uDname +"' and password = '"+ uDpass +"'")){
    //create new dialog populated with info of user (bride) who logged in
    ui->label->setText("Login Successful");

    hide();
    userInfo = new UserDialog(this);
    userInfo->show();
}

else if (role.exec("SELECT role FROM groom WHERE username = '"+ uDname +"' and password = '"+ uDpass +"'")){
    //create new dialog populated with info of user (groom) who logged in
    ui->label->setText("Login Successful");

    hide();
    userInfo = new UserDialog(this);
    userInfo->show();
}

else if (role.exec("SELECT role FROM official WHERE username = '"+ uDname +"' and password = '"+ uDpass +"'")){
    //create new dialog populated with info of official who logged in
    ui->label->setText("Login Successful");

    hide();
    officialInfo = new OfficialDialog(this);
    officialInfo->show();
}

else if (role.exec("SELECT role FROM healthcare WHERE username = '"+ uDname +"' and password = '"+ uDpass +"'")){
    //create new dialog populated with info of healthcare who logged in
    ui->label->setText("Login Successful");

    hide();
    hcUserInfo = new HealthcareDialog(this);
    hcUserInfo->show();
}

numRole = role.exec("SELECT role FROM bride WHERE username = '"+ uDname +"' and password = '"+ uDpass +"' UNION SELECT role FROM groom WHERE username = '"+ uDname +"' and password = '"+ uDpass +"'");

switch (numRole){

case 1 : //create new dialog populated with info of admin who logged in
        ui->label->setText("Login Successful");

        hide();
        dbInfo = new AdminDialog(this);
        dbInfo->show();

    break;

case 2 : //create new dialog populated with info of user who logged in
        ui->label->setText("Login Successful");

        hide();

        userInfo = new UserDialog(this);
        userInfo->show();
    break;

case 3 : //create new dialog populated with info of official who logged in
    ui->label->setText("Login Successful");

    hide();

    officialInfo = new OfficialDialog(this);
    officialInfo->show();

    break;

case 4 : //create new dialog populated with info of healthcare who logged in
    ui->label->setText("Login Successful");

    hide();

    hcUserInfo = new HealthcareDialog(this);
    hcUserInfo->show();

    break;
}
*/
