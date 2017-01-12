#include "plotspec.h"
#include "ui_plotspec.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <QLineEdit>
#include <QPixmap>
#include <QLabel>
#include <QVector>
#include <QFile>
#include <QtDebug>
#include <QCheckBox>
#include <CCfits/CCfits>

using namespace std;

QString qSpPath, qspExtension, qspWavecol, qspIntenscol;
string spPath, spExtension, spWavecol, spIntenscol;
std::valarray<double> spwave;
std::valarray<double> spintens;

PlotSpec::PlotSpec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlotSpec)
{
    ui->setupUi(this);
    this->setWindowTitle("Spectrum Plotter");

    ui->lineEdit->setText("spectra_0.txt");
    ui->customPlot_3->xAxis->setLabel("wavelength axis");
    ui->customPlot_3->yAxis->setLabel("spectrum value");
    ui->checkBox->setChecked(true);
    ui->lineEdit_5->setText("/home/daniels/Observations/Tomer/single");
    qSpPath=ui->lineEdit_5->text();
    spPath = qSpPath.toUtf8().constData();

    ui->comboBox->addItem("ASCII");
    ui->comboBox->addItem("fits");

    ui->lineEdit_7->setText("DataVector");
    ui->lineEdit_8->setText("Arg");
    ui->lineEdit_9->setText("Fun");
    qspExtension=ui->lineEdit_7->text();
    spExtension = qspExtension.toUtf8().constData();
    qspWavecol=ui->lineEdit_8->text();
    spWavecol = qspWavecol.toUtf8().constData();
    qspIntenscol=ui->lineEdit_9->text();
    spIntenscol = qspIntenscol.toUtf8().constData();

    QFont legendFont = font();
    legendFont.setPointSize(16);
    ui->customPlot_3->axisRect()->setupFullAxesBox(true);
    ui->customPlot_3->xAxis->setLabelFont(legendFont);
    ui->customPlot_3->yAxis->setLabelFont(legendFont);
    ui->customPlot_3->xAxis->setTickLabelFont(legendFont);
    ui->customPlot_3->yAxis->setTickLabelFont(legendFont);
}



PlotSpec::~PlotSpec()
{
    delete ui;
}

string one, two, zeile;
double xs1, xs2, ys1, ys2;

//****************************************************************
//plot spectrum
//****************************************************************
void PlotSpec::on_pushButton_2_clicked()
{
    ui->customPlot_3->clearGraphs();

    QVector<double> a(1), b(1);

    if(ui->comboBox->currentIndex()==0){
    QString plot1=ui->lineEdit->text();
    string plot11 = plot1.toUtf8().constData();
    std::ostringstream datNameStream(plot11);
    datNameStream<<spPath<<"/"<<plot11;
    std::string datName = datNameStream.str();
    ifstream toplot1(datName.c_str());

    QFile checkfile(datName.c_str());

    if(!checkfile.exists()){
        qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+qSpPath+"/"+plot1+" does not exist!");
       return;
    }

    int number_of_lines =0;

    while(std::getline(toplot1, zeile))
       ++ number_of_lines;

    toplot1.clear();
    toplot1.seekg(0, ios::beg);

    a.resize(number_of_lines);
    b.resize(number_of_lines);

    for (int i=0; i<number_of_lines; i++){
    toplot1 >> one >>two;
    istringstream ist(one);
    ist >> a[i];
    istringstream ist2(two);
    ist2 >> b[i];
    }
    toplot1.close();
    }

    if(ui->comboBox->currentIndex()==1){
        QString input=ui->lineEdit->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<spPath<<"/"<<data;
        std::string datName = datNameStream.str();
        ifstream dat(datName.c_str());


        QFile checkfile1(datName.c_str());

        if(!checkfile1.exists()){
            qDebug()<<"Error 1: The file "<<checkfile1.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error1 ", "Error 1: File does not exist!");
            //check=1;
           return;
        }

        CCfits::FITS::setVerboseMode(true);

        try
        {

            //open file for reading
            auto_ptr<CCfits::FITS> input_file(new CCfits::FITS(datName.c_str(),CCfits::Read,true));

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

    ui->customPlot_3->addGraph();
    if(ui->checkBox_4->isChecked()){
    ui->customPlot_3->legend->setVisible(true);
    QFont legendFont = font();
    legendFont.setPointSize(9);
    ui->customPlot_3->legend->setFont(legendFont);
    ui->customPlot_3->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);
    QString label=ui->lineEdit_6->text();
    ui->customPlot_3->graph(0)->setName(label);
    }
    ui->customPlot_3->graph(0)->setData(a, b);
    ui->customPlot_3->xAxis->setRange(xs1, xs2);
    ui->customPlot_3->yAxis->setRange(ys1, ys2);
    ui->customPlot_3->replot();
}

//****************************************************************
//find values
//****************************************************************
void PlotSpec::on_pushButton_3_clicked()
{
    QVector<double> a(1), b(1);
    int number_of_lines=0;

    if(ui->comboBox->currentIndex()==0){
    QString plot1=ui->lineEdit->text();
    string plot11 = plot1.toUtf8().constData();
    std::ostringstream datNameStream(plot11);
    datNameStream<<spPath<<"/"<<plot11;
    std::string datName = datNameStream.str();
    ifstream toplot1(datName.c_str());

    QFile checkfile(datName.c_str());

    if(!checkfile.exists()){
        qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+qSpPath+"/"+plot1+" does not exist!");
       return;
    }

    while(std::getline(toplot1, zeile))
       ++ number_of_lines;

    toplot1.clear();
    toplot1.seekg(0, ios::beg);

    a.resize(number_of_lines);
    b.resize(number_of_lines);

    for (int i=0; i<number_of_lines; i++){
    toplot1 >> one >>two;
    istringstream ist(one);
    ist >> a[i];
    istringstream ist2(two);
    ist2 >> b[i];
    }
    toplot1.close();
    }

    if(ui->comboBox->currentIndex()==1){
        QString input=ui->lineEdit->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<spPath<<"/"<<data;
        std::string datName = datNameStream.str();
        ifstream dat(datName.c_str());

        QFile checkfile1(datName.c_str());

        if(!checkfile1.exists()){
            qDebug()<<"Error 1: The file "<<checkfile1.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error1 ", "Error 1: File does not exist!");
            //check=1;
           return;
        }

        CCfits::FITS::setVerboseMode(true);

        try
        {

            //open file for reading
            auto_ptr<CCfits::FITS> input_file(new CCfits::FITS(datName.c_str(),CCfits::Read,true));

            // Create pointer to extension
                CCfits::ExtHDU& datavector = input_file->extension(spExtension);

              // Read rows
              CCfits::Column& column = datavector.column(spWavecol);
              column.read(spwave, 1, column.rows());

              // Read rows
              CCfits::Column& column2 = datavector.column(spIntenscol);
              column2.read(spintens, 1, column2.rows());

              number_of_lines=spwave.size();

              a.resize(number_of_lines);
              b.resize(number_of_lines);

              for(int i=0; i<number_of_lines; i++){
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


    xs1=a[0];
    xs2=a[number_of_lines-1];
    for(int i=0; i<number_of_lines; i++){
        if(a[i]<xs1){
            xs1=a[i];
        }
    }

    for(int i=0; i<number_of_lines; i++){
        if(a[i]>xs2){
            xs2=a[i];
        }
    }

    ui->doubleSpinBox->setValue(xs1);
    ui->doubleSpinBox_2->setValue(xs2);

    ys1=b[0];
    ys2=b[number_of_lines-1];
    for(int i=0; i<number_of_lines; i++){
        if(b[i]<ys1){
            ys1=b[i];
        }
    }
    for(int i=0; i<number_of_lines; i++){
        if(b[i]>ys2){
            ys2=b[i];
        }
    }


    ui->doubleSpinBox_3->setValue(ys1);
    ui->doubleSpinBox_4->setValue(ys2);
}



void PlotSpec::on_doubleSpinBox_valueChanged()
{
    xs1=ui->doubleSpinBox->value();
}

void PlotSpec::on_doubleSpinBox_2_valueChanged()
{
    xs2=ui->doubleSpinBox_2->value();
}

void PlotSpec::on_doubleSpinBox_3_valueChanged()
{
    ys1=ui->doubleSpinBox_3->value();
}

void PlotSpec::on_doubleSpinBox_4_valueChanged()
{
    ys2=ui->doubleSpinBox_4->value();
}

void PlotSpec::on_lineEdit_2_editingFinished()
{
    QString xlabel=ui->lineEdit_2->text();
    ui->customPlot_3->xAxis->setLabel(xlabel);
}

void PlotSpec::on_lineEdit_3_editingFinished()
{
    QString ylabel=ui->lineEdit_3->text();
    ui->customPlot_3->yAxis->setLabel(ylabel);
}

void PlotSpec::on_pushButton_4_clicked()
{
    if(ui->checkBox->isChecked()){
        QString sav=ui->lineEdit_4->text();
        QString save=qSpPath+"/"+sav +".pdf";
        ui->customPlot_3->savePdf(save);
    }
    if(ui->checkBox_2->isChecked()){
        QString sav=ui->lineEdit_4->text();
        QString save=qSpPath+"/"+sav+".png";
        ui->customPlot_3->savePng(save);
    }
    if(ui->checkBox_3->isChecked()){
        QString sav=ui->lineEdit_4->text();
        QString save=qSpPath+"/"+sav+".jpg";
        ui->customPlot_3->saveJpg(save);
    }
}

void PlotSpec::on_checkBox_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
}

void PlotSpec::on_checkBox_2_clicked()
{
    ui->checkBox_3->setChecked(false);
    ui->checkBox->setChecked(false);
}

void PlotSpec::on_checkBox_3_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox->setChecked(false);
}

void PlotSpec::on_lineEdit_5_textEdited()
{
    qSpPath=ui->lineEdit_5->text();
    spPath = qSpPath.toUtf8().constData();
}

void PlotSpec::on_spinBox_valueChanged()
{
    QFont legendFont = font();
    legendFont.setPointSize(ui->spinBox->value());
    ui->customPlot_3->xAxis->setLabelFont(legendFont);
    ui->customPlot_3->yAxis->setLabelFont(legendFont);
    ui->customPlot_3->xAxis->setTickLabelFont(legendFont);
    ui->customPlot_3->yAxis->setTickLabelFont(legendFont);
}

void PlotSpec::on_lineEdit_7_textChanged()
{
    qspExtension=ui->lineEdit_7->text();
    spExtension = qspExtension.toUtf8().constData();
}

void PlotSpec::on_lineEdit_8_textChanged()
{
    qspWavecol=ui->lineEdit_8->text();
    spWavecol = qspWavecol.toUtf8().constData();
}

void PlotSpec::on_lineEdit_9_textChanged()
{
    qspIntenscol=ui->lineEdit_9->text();
    spIntenscol = qspIntenscol.toUtf8().constData();
}
