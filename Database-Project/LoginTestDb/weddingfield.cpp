#include "weddingfield.h"
#include "ui_weddingfield.h"
#include <QSqlQuery>
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QDialog>

WeddingField::WeddingField(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WeddingField)
{
    ui->setupUi(this);
}

WeddingField::~WeddingField()
{
    delete ui;
}

void WeddingField::on_buttonBox_accepted()
{
    /*
     * --------------------------------- Bride and Groom db format -----------------------------------
     *
     * id, first_name VARCHAR, last_name VARCHAR, birthdate DATE (YYYY-MM-DD), username VARCHAR, password VARCHAR, email VARCHAR, phone INT,
     * hiv_status ENUM('positive', 'negative'), mother VARCHAR, father VARCHAR,  role INT
     *
     * --------------------------------- Wedding db format---------------------------------------------
     *
     *id, date DATE, bride INT, groom INT, official INT
     *
     * ----------------------------- Bride and Groom Parents db format --------------------------------
     *
     * id , first_name VARCHAR, last_name VARCHAR, birthdate DATE
    */


    QSqlQuery qry;
    QString sQryB = "INSERT INTO bride (first_name, last_name, birthdate, username, password, email, phone)"
                   " VALUES(:first_name, :last_name, :birthdate, :username, :password, :email, :phone)";

    //qry for bride data
    QString first_name, last_name, birthdate, username, password, email, phone;


    //qry for bride mother and father data
    QString mother_first_name, mother_last_name, mother_birthdate, father_first_name, father_last_name, father_birthdate;


    //qry for wedding data
    QString date, official;

    //capture bride data from the fields
    first_name = ui->fieldFirstNameBride->text();
    last_name = ui->fieldLastNameBride->text();
    birthdate = ui->fieldDOBBride->text();
    username = ui->fieldUserNameBride->text();
    password = ui->fieldPasswordBride->text();
    email = ui->fieldEmailBride->text();
    phone = ui->fieldPhoneBride->text();

    //prepare the query with the string
    qry.prepare(sQryB);

    //bind captured data to the query
    qry.bindValue(":first_name", first_name);
    qry.bindValue(":last_name", last_name);
    qry.bindValue(":birthdate", birthdate);
    qry.bindValue(":username", username);
    qry.bindValue(":password", password);
    qry.bindValue(":email", email);
    qry.bindValue(":phone", phone);

    //execute the query
    if(qry.exec()){
        QMessageBox::information(this,"Connection Status", "Successfully Connected");
    }

    else{
        QMessageBox::critical(this,"Connection Status", qry.lastError().text());
    }



    sQryB = ("INSERT INTO bride_parents(mother_first_name, mother_last_name, mother_birthdate, father_first_name, father_last_name, father_birthdate) "
             "VALUES(:mother_first_name, :mother_last_name, :mother_birthdate, :father_first_name, :father_last_name, :father_birthdate)");

    //capture values from fields
    mother_first_name = ui->fieldMotherBrideFN->text();
    mother_last_name = ui->fieldMotherBrideLN->text();
    mother_birthdate = ui->fieldMotherBrideDOB->text();
    father_first_name = ui->fieldFatherBrideFN->text();
    father_last_name = ui->fieldFatherBrideLN->text();
    father_birthdate = ui->fieldFatherBrideDOB->text();

    //prepare the query
    qry.prepare(sQryB);

    //bind values
    qry.bindValue(":mother_first_name", mother_first_name);
    qry.bindValue(":mother_last_name", mother_last_name);
    qry.bindValue(":mother_birthdate", mother_birthdate);
    qry.bindValue(":father_first_name", father_first_name);
    qry.bindValue("father_last_name", father_last_name);
    qry.bindValue(":father_birthdate", father_birthdate);

    //execute the query
    if(qry.exec()){
        QMessageBox::information(this,"Connection Status", "Successfully Connected");
    }

    else{
        QMessageBox::critical(this,"Connection Status", qry.lastError().text());
    }

    //make qry for groom info
    QString sQryG = "INSERT INTO groom (first_name, last_name, birthdate, username, password, email, phone)"
                   " VALUES(:first_name, :last_name, :birthdate, :username, :password, :email, :phone )";

    //capture groom data from the fields
    first_name = ui->fieldFirstNameGroom->text();
    last_name = ui->fieldLastNameGroom->text();
    birthdate = ui->fieldDOBGroom->text();
    username = ui->fieldUserNameGroom->text();
    password = ui->fieldPasswordGroom->text();
    email = ui->fieldEmailGroom->text();
    phone = ui->fieldPhoneGroom->text();

    //prepare the query with the string
    qry.prepare(sQryG);

    //bind captured data to the query
    qry.bindValue(":first_name", first_name);
    qry.bindValue(":last_name", last_name);
    qry.bindValue(":birthdate", birthdate);
    qry.bindValue(":username", username);
    qry.bindValue(":password", password);
    qry.bindValue(":email", email);
    qry.bindValue(":phone", phone);

    //execute the query
    if(qry.exec()){
        QMessageBox::information(this,"Connection Status", "Successfully Connected");
    }

    else{
        QMessageBox::information(this,"Connection Status", qry.lastError().text());
    }

    sQryG = ("INSERT INTO groom_parents(mother_first_name, mother_last_name, mother_birthdate, father_first_name, father_last_name, father_birthdate) "
             "VALUES(:mother_first_name, :mother_last_name, :mother_birthdate, :father_first_name, :father_last_name, :father_birthdate)");

    //capture values from fields of grooms parents
    mother_first_name = ui->fieldMotherGroomFN->text();
    mother_last_name = ui->fieldMotherGroomLN->text();
    mother_birthdate = ui->fieldMotherGroomDOB->text();
    father_first_name = ui->fieldFatherGroomFN->text();
    father_last_name = ui->fieldFatherGroomLN->text();
    father_birthdate = ui->fieldFatherGroomDOB->text();

    //prepare the query
    qry.prepare(sQryG);

    //bind values
    qry.bindValue(":mother_first_name", mother_first_name);
    qry.bindValue(":mother_last_name", mother_last_name);
    qry.bindValue(":mother_birthdate", mother_birthdate);
    qry.bindValue(":father_first_name", father_first_name);
    qry.bindValue("father_last_name", father_last_name);
    qry.bindValue(":father_birthdate", father_birthdate);

    //execute the query
    if(qry.exec()){
        QMessageBox::information(this,"Connection Status", "Successfully Connected");
    }

    else{
        QMessageBox::information(this,"Connection Status", qry.lastError().text());
    }

    /*
    //make a qry for wedding info
    QString sQryW = "INSERT INTO wedding(date, official) VALUES(:date, :official)";

    //capture values from fields


    //prepare the query
    qry.prepare(sQryW);

    //bind values to the query
    qry.bindValue(":date");
    */

    accept();


}

void WeddingField::on_buttonBox_rejected()
{
    reject();
}



