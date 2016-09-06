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

Rename::Rename(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rename)
{
    ui->setupUi(this);
}

Rename::~Rename()
{
    delete ui;
}

void Rename::on_pushButton_clicked()
{
    std::string directory;
    QString direc=ui->lineEdit->text();
    directory = direc.toUtf8().constData();


    DIR *pdir = NULL;
    struct dirent *pent = NULL;
    const char * DIRECTORY;

    // convert directory string to const char
    DIRECTORY = directory.c_str();

    pdir = opendir (DIRECTORY);

    int i = 0;
    QString name=ui->lineEdit_2->text();

    std::string s, oldname, newname, nename;
    nename = name.toUtf8().constData();

    const char * OLDNAME, * NEWNAME;

    while (pent = readdir (pdir))
    {
        // convert int i to str s
        std::stringstream out;
        out << i;
        s = out.str();

        oldname = (std::string(DIRECTORY)+pent->d_name).c_str();
        newname = (std::string(DIRECTORY)+nename + s +".fits").c_str();

        OLDNAME = oldname.c_str();
        NEWNAME = newname.c_str();

        rename(OLDNAME, NEWNAME);

        i++;
    }
}
