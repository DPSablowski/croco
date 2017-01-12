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
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <CCfits/CCfits>

using namespace std;

int tabRC;

Rename::Rename(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rename)
{
    ui->setupUi(this);

    ui->lineEdit->setText("/home/daniels/Observations/Capella/Set_13/spectra");
    ui->lineEdit_3->setText(".dat");
    ui->lineEdit_4->setText("table.dat");

    ui->lineEdit_5->setText("DataVector");
    ui->lineEdit_6->setText("Arg");
    ui->lineEdit_7->setText("Fun");

    ui->comboBox->addItem("ASCII");
    ui->comboBox->addItem("fits");

    ui->doubleSpinBox->setValue(3900);
    ui->doubleSpinBox_2->setValue(8500);
    ui->doubleSpinBox_3->setValue(0);
    ui->doubleSpinBox_4->setValue(1.5);

    ui->customPlot->axisRect()->setupFullAxesBox(true);
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

        if(i!=ui->spinBox_2->value()-1 & (i!=ui->spinBox_3->value()-1) & (i!=ui->spinBox_4->value()-1)){

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
    QString qTab=ui->lineEdit_4->text();
    string Tab = qTab.toUtf8().constData();
    string rPath = qRPath.toUtf8().constData();
    QTableWidgetItem *qTOld, *qTNew;
    string Old, New;
    const char *OLD, *NEW;

    ostringstream dat3NameStream(Tab);
    dat3NameStream<<rPath<<"/"<<Tab;
    std::string dat3Name = dat3NameStream.str();
    ofstream outp(dat3Name.c_str());
    outp<<"Old \t New"<<endl;

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

        outp<<Old<<"\t"<<New<<endl;

        rename(OLD,NEW);
    }

}



void Rename::on_spinBox_5_valueChanged()
{
    ui->customPlot->clearGraphs();
    int i = ui->spinBox_5->value()-1;

    if(i>ui->spinBox->value()-1){
        return;
    }

    QString qRPath=ui->lineEdit->text();
    string rPath = qRPath.toUtf8().constData();

    QVector<double> a(2), b(2);


    QTableWidgetItem *qtoplot;
    qtoplot= ui->tableWidget->item(i, 0);
    QString qplot = qtoplot->text();
    ui->lineEdit_8->setText(qplot);
    string toplot = qplot.toUtf8().constData();
    ostringstream dat4NameStream(toplot);
    dat4NameStream<<rPath<<"/"<<toplot;
    std::string dat4Name = dat4NameStream.str();
    ifstream plot(dat4Name.c_str());

    QFile checkfile(dat4Name.c_str());

    if(!checkfile.exists()){
        qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+qRPath+"/"+qplot+" does not exist!");
       return;
    }

    if(ui->comboBox->currentIndex()==0){

    string one, two, zeile;

    int number_of_lines =0;

    while(std::getline(plot, zeile))
       ++ number_of_lines;

    plot.clear();
    plot.seekg(0, ios::beg);

    a.resize(number_of_lines);
    b.resize(number_of_lines);

    for (int i=0; i<number_of_lines; i++){
    plot >> one >>two;
    istringstream ist(one);
    ist >> a[i];
    istringstream ist2(two);
    ist2 >> b[i];
    }
    plot.close();
    }

    if(ui->comboBox->currentIndex()==1){

        QString qspExtension, qspWavecol, qspIntenscol;
        string spExtension, spWavecol, spIntenscol;
        std::valarray<double> spwave;
        std::valarray<double> spintens;


        qspExtension=ui->lineEdit_5->text();
        spExtension = qspExtension.toUtf8().constData();
        qspWavecol=ui->lineEdit_6->text();
        spWavecol = qspWavecol.toUtf8().constData();
        qspIntenscol=ui->lineEdit_7->text();
        spIntenscol = qspIntenscol.toUtf8().constData();


        CCfits::FITS::setVerboseMode(true);

        try
        {

            //open file for reading
            auto_ptr<CCfits::FITS> input_file(new CCfits::FITS(dat4Name.c_str(),CCfits::Read,true));

            // Create pointer to extension
                CCfits::ExtHDU& datavector = input_file->extension(spExtension);

              // Read rows
              CCfits::Column& column = datavector.column(spWavecol);
              column.read(spwave, 1, column.rows());

              // Read rows
              CCfits::Column& column2 = datavector.column(spIntenscol);
              column2.read(spintens, 1, column2.rows());

              int bini=spwave.size();

              a.resize(bini);
              b.resize(bini);

              for(int i=0; i<bini; i++){
              b[i]=spintens[i];
              a[i]=spwave[i];
              }


        }
            catch (CCfits::FitsException&)

             {
              std::cerr << " Fits Exception Thrown by test function \n";
              }


           // return;

    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(a, b);
    ui->customPlot->xAxis->setRange(ui->doubleSpinBox->value(), ui->doubleSpinBox_2->value());
    ui->customPlot->yAxis->setRange(ui->doubleSpinBox_3->value(), ui->doubleSpinBox_4->value());
    ui->customPlot->replot();


}
