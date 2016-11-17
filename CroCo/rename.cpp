#include "rename.h"
#include "ui_rename.h"
#include <dirent.h>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

int tabRC;

Rename::Rename(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rename)
{
    ui->setupUi(this);

    ui->lineEdit->setText("/home/daniels/test/test/");
    ui->lineEdit_3->setText(".dat");
}

Rename::~Rename()
{
    delete ui;
}

//**************************************
//List files
//**************************************
void Rename::on_pushButton_clicked()
{   
    QString direc=ui->lineEdit->text();
    string directory = direc.toUtf8().constData();

    QString qRExt = ui->lineEdit_3->text();
    string rExt = qRExt.toUtf8().constData();

    DIR *pdir = NULL;
    struct dirent *pent = NULL;
    const char * DIRECTORY;

    // convert directory string to const char
    DIRECTORY = directory.c_str();

    pdir = opendir (DIRECTORY);

    int i = 0, e=0;
    QString name=ui->lineEdit_2->text();

    std::string oldname, newname, nename;
    nename = name.toUtf8().constData();

    const char * OLDNAME, * NEWNAME;

    while (pent = readdir(pdir))
    {
        if(ui->checkBox->isChecked()){

        if(i!=ui->spinBox_2->value() & (i!=ui->spinBox_3->value()) & (i!=ui->spinBox_4->value())){

        // convert int i to str s
        string s = to_string(e);

        oldname = (std::string(DIRECTORY)+pent->d_name).c_str();
        newname = (std::string(DIRECTORY)+nename + s + rExt).c_str();

        OLDNAME = oldname.c_str();
        QString qold = QString::fromStdString(pent->d_name);
        NEWNAME = newname.c_str();
        QString qnew = QString::fromStdString(nename+s+rExt);

        ui->tableWidget->setItem(e, 0, new QTableWidgetItem(qold));
        ui->tableWidget->setItem(e, 1, new QTableWidgetItem(qnew));
        e+=1;

        //rename(OLDNAME, NEWNAME);
    }}

        else{

            // convert int i to str s
            string s = to_string(e);

            oldname = (std::string(DIRECTORY)+pent->d_name).c_str();
            newname = (std::string(DIRECTORY)+nename + s + rExt).c_str();

            OLDNAME = oldname.c_str();
            QString qold = QString::fromStdString(pent->d_name);
            NEWNAME = newname.c_str();
            QString qnew = QString::fromStdString(nename+s+rExt);

            ui->tableWidget->setItem(e, 0, new QTableWidgetItem(qold));
            ui->tableWidget->setItem(e, 1, new QTableWidgetItem(qnew));
            e+=1;

            //rename(OLDNAME, NEWNAME);
        }
        i+=1;
    }
}

void Rename::on_spinBox_valueChanged()
{
    tabRC=ui->spinBox->value();
    ui->tableWidget->setRowCount(tabRC);
}

//**********************************
// Rename files
//**********************************
void Rename::on_pushButton_2_clicked()
{
    int nfiles = ui->spinBox->value();

    QString qRPath=ui->lineEdit->text();
    QString qOld, qNew;
    string rPath = qRPath.toUtf8().constData();
    QTableWidgetItem *qTOld, *qTNew;
    string Old, New;
    const char *OLD, *NEW;

    for(int i=0; i<nfiles; i++){
        qTOld = ui->tableWidget->item(i,0);
        qOld = qTOld->text();
        qTNew = ui->tableWidget->item(i,1);
        qNew = qTNew->text();

        string Oldstr = qOld.toUtf8().constData();
        ostringstream datNameStream(Oldstr);
        datNameStream<<rPath<<"/"<<Oldstr;
        Old = datNameStream.str();
        OLD = Old.c_str();

        string Newstr = qNew.toUtf8().constData();
        ostringstream dat2NameStream(Newstr);
        dat2NameStream<<rPath<<"/"<<Newstr;
        New = dat2NameStream.str();
        NEW = New.c_str();

        rename(OLD,NEW);
    }

}
