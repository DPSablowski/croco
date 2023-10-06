#include "telluric.h"
#include "ui_telluric.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <CCfits/CCfits>

using namespace std;

double tintens, tshift, twidth, tcont, tx1, tx2, ty1, ty2, sas;
string tellPath;
QString qTellPath;
QString qteExtension, qteWavecol, qteIntenscol;
string teExtension, teWavecol, teIntenscol;
QVector<double> at(1), bt(1), ct(1), dt(1), et(1), ft(1), dt2(1), et2(1), ct2(1);
int number_of_lines, place, cindex, number_of_tellurics, linei;
std::valarray<double> tewave;
std::valarray<double> teintens;
const double c0t = 299792.458;

Telluric::Telluric(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Telluric)
{
    ui->setupUi(this);
    this->setWindowTitle("Telluric Tool");

    ui->checkBox_2->setChecked(true);

    ui->doubleSpinBox->setValue(1.0);
    tintens=ui->doubleSpinBox->value();

    ui->doubleSpinBox_2->setValue(1.0);
    twidth=ui->doubleSpinBox_2->value();

    ui->doubleSpinBox_3->setValue(0.999774);
    tshift=ui->doubleSpinBox_3->value();

    ui->doubleSpinBox_4->setValue(1.0);
    tcont=ui->doubleSpinBox_4->value();

    ui->lineEdit->setText("epsAur.txt");
    ui->lineEdit_6->setText("/home/daniels/work1/Disentangling/Template_Method/Log/Qt_LogCC/Data");
    qTellPath=ui->lineEdit_6->text();
    tellPath = qTellPath.toUtf8().constData();

    ui->comboBox->addItem("txt");
    ui->comboBox->addItem("fits");

    ui->lineEdit_3->setText("DataVector");
    ui->lineEdit_4->setText("Arg");
    ui->lineEdit_5->setText("Fun");

    ui->comboBox_2->addItem("HITRAN O2");
    ui->comboBox_2->addItem("HITRAN H2O");
    ui->comboBox_2->addItem("HITRAN O2 + H2O");
    ui->comboBox_2->addItem("Orion");
    ui->comboBox_2->addItem("UVES Hanuschik");

    QFont legendFont = font();
    legendFont.setPointSize(16);
    ui->customPlot->axisRect()->setupFullAxesBox(true);
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);

}

Telluric::~Telluric()
{
    delete ui;
}

void Telluric::seData(QString str1, QString str2, QString str3)
{
    ui->lineEdit_6->setText(str1);
    qTellPath=ui->lineEdit_6->text();
    tellPath = qTellPath.toUtf8().constData();

    ui->lineEdit->setText(str2+str3);

}

//***********************************
// Read
//***********************************
void Telluric::tellRead(){

    string zeile, one, two, three, four;
    QString com, com1;

    ui->comboBox_3->clear();

    if(ui->comboBox->currentIndex()==0){
        QString plot1=ui->lineEdit->text();
        string plot11 = plot1.toUtf8().constData();
        std::ostringstream datNameStream(plot11);
        datNameStream<<tellPath<<"/"<<plot11;
        std::string datName = datNameStream.str();

        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File "+qTellPath+"/"+plot1+" does not exist!");
            return;
        }
        ifstream toplot1(datName.c_str());

        number_of_lines =0;

        while(std::getline(toplot1, zeile))
           ++ number_of_lines;

        toplot1.clear();
        toplot1.seekg(0, ios::beg);

        at.resize(number_of_lines);
        bt.resize(number_of_lines);
        ft.resize(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
            toplot1 >> one >>two;
            istringstream ist(one);
            ist >> at[i];
            istringstream ist2(two);
            ist2 >> bt[i];
        }
        toplot1.close();
    }

    if(ui->comboBox->currentIndex()==1){

        QString input=ui->lineEdit->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<tellPath<<"/"<<data;
        std::string datName = datNameStream.str();

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
            qteExtension=ui->lineEdit_3->text();
            teExtension = qteExtension.toUtf8().constData();
            qteWavecol=ui->lineEdit_4->text();
            teWavecol = qteWavecol.toUtf8().constData();
            qteIntenscol=ui->lineEdit_5->text();
            teIntenscol = qteIntenscol.toUtf8().constData();

            //open file for reading
            shared_ptr<CCfits::FITS> input_file(new CCfits::FITS(datName.c_str(),CCfits::Read,true));

            // Create pointer to extension
                CCfits::ExtHDU& datavector = input_file->extension(teExtension);

              // Read rows
              CCfits::Column& column = datavector.column(teWavecol);
              column.read(tewave, 1, column.rows());

              // Read rows
              CCfits::Column& column2 = datavector.column(teIntenscol);
              column2.read(teintens, 1, column2.rows());

              int bini=tewave.size();

              at.resize(bini);
              bt.resize(bini);
              ft.resize(bini);

              for(int i=0; i<bini; i++){
              bt[i]=teintens[i];
              at[i]=tewave[i];
              }


        }
            catch (CCfits::FitsException&)

             {
              std::cerr << " Fits Exception Thrown by test function \n";
              }


           // return;

    }

    linei=0;
    QString plot2;

    if(ui->comboBox_2->currentIndex()==0){
        plot2 = "oxygen.dat";
        linei=1;
    }
    if(ui->comboBox_2->currentIndex()==1){
        plot2 = "water.dat";
        linei=2;
    }
    if(ui->comboBox_2->currentIndex()==2){
        plot2 = "telluric.dat";
        linei=3;
    }
    if(ui->comboBox_2->currentIndex()==3){
        plot2 = "orion.dat";
        linei=4;
    }
    if(ui->comboBox_2->currentIndex()==4){
        plot2 = "hanuschik.dat";
        linei=5;
    }

    string plot12 = plot2.toUtf8().constData();
    std::ostringstream dat2NameStream(plot12);
    dat2NameStream<<tellPath<<"/"<<plot12;
    std::string dat2Name = dat2NameStream.str();

    QFile checkfile2(dat2Name.c_str());

    if(!checkfile2.exists()){
        qDebug()<<"The file "<<checkfile2.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+qTellPath+"/"+plot2+" does not exist!");
       return;
    }
    ifstream toplot2(dat2Name.c_str());

   int number_of_lines2 =0;

    while(std::getline(toplot2, zeile))
       ++ number_of_lines2;

    toplot2.clear();
    toplot2.seekg(0, ios::beg);
    number_of_tellurics=number_of_lines2;

    ct.resize(number_of_lines2);
    ct2.resize(number_of_lines2);
    dt.resize(number_of_lines2);
    dt2.resize(number_of_lines2);
    et.resize(number_of_lines2);
    et2.resize(number_of_lines2);
    double telll=0.0, HWHMair=0.0, HWHMself=0.0;
    place=0;

    for (int i=0; i<number_of_lines2; i++){
        toplot2 >> one >> two >> three >> four;
        istringstream ist3(one);
        ist3 >> telll;
        if(ui->comboBox_2->currentIndex()==4){
            //telll=telll;
        }
        else{
            telll = 1/telll*100000000;
        }
        if((telll>=at[0]) & (telll<=at[number_of_lines-1])){
            ct[place]=telll;
            ct2[place]=telll;
            istringstream ist4(two);
            ist4 >> dt[place];
            com = QString::number(ct[place]);
            com1 = QString::number(dt[place]);
            ui->comboBox_3->addItem(com+";"+com1);
            if((linei==1) or (linei==2) or(linei==3)){
                dt2[place]=dt[place]*pow(10,27);
            }
            else{
                dt2[place]=dt[place];
            }
            dt[place]=0;
            istringstream ist5(three);
            ist5 >> HWHMair;
            istringstream ist6(four);
            ist6 >> HWHMself;
            et2[place]=sqrt(pow(HWHMair,2)+pow(HWHMself,2))*2;
            et[place]=0.0;
            ++place;
        }
    }
    toplot2.close();
    \
    sas=0;

    for(int j=0; j<number_of_lines; j++){
        ft[j]=0;

        for(int i=0; i<place; i++){
            if(ui->checkBox_2->isChecked()){    // Gauss
                sas=dt[i]*exp(-2.77254/(pow(et[i],2))*pow((ct[i]-at[j]),2));
            }
            else{   // Lorentz
                sas = dt[i]*pow(et[i],2)*ct[i]/(pow((pow(at[j],2)-pow(ct[i],2)),2)+pow(et[i],2)*pow(ct[i],2));
            }
            ft[j]+=sas;
        }
        ft[j]=tcont-ft[j];

    }


}

//***********************************
//plot data
//***********************************
void Telluric::tellPlot(){

    tx1=ui->doubleSpinBox_5->value();
    tx2=ui->doubleSpinBox_6->value();
    ty1=ui->doubleSpinBox_7->value();
    ty2=ui->doubleSpinBox_8->value();

    ui->customPlot->clearGraphs();

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(at, bt);
    ui->customPlot->addGraph();
    ui->customPlot->graph(1)->setData(at, ft);
    ui->customPlot->graph(1)->setPen(QPen(Qt::red));
    ui->customPlot->xAxis->setRange(tx1, tx2);
    ui->customPlot->yAxis->setRange(ty1, ty2);
    ui->customPlot->replot();
}

//***********************************
//line intensity
//***********************************
void Telluric::on_doubleSpinBox_valueChanged()
{
    tintens=ui->doubleSpinBox->value();
    if(ui->checkBox->isChecked()){
        for(int i=0; i<number_of_tellurics; i++){
            dt[i]=dt2[i]*tintens;
        }
    }
    else{
        dt[cindex]=dt2[cindex]*tintens;
    }
    for(int j=0; j<number_of_lines; j++){
        ft[j]=0;

        for(int i=0; i<place; i++){
            if(ui->checkBox_2->isChecked()){    // Gauss
                sas=dt[i]*exp(-2.77254/(pow(et[i],2))*pow((ct[i]-at[j]),2));
            }
            else{   // Lorentz

                sas = dt[i]*pow(et[i],2)*ct[i]/(pow((pow(at[j],2)-pow(ct[i],2)),2)+pow(et[i],2)*pow(ct[i],2));
            }
            ft[j]+=sas;
        }
        ft[j]=tcont-ft[j];

    }
    Telluric::tellPlot();

}

void Telluric::on_lineEdit_6_textChanged()
{
    qTellPath=ui->lineEdit_6->text();
    tellPath = qTellPath.toUtf8().constData();
}

//***********************************
//line width
//***********************************
void Telluric::on_doubleSpinBox_2_valueChanged()
{
    twidth=ui->doubleSpinBox_2->value();
    if(ui->checkBox->isChecked()){
        for(int i=0; i<number_of_tellurics; i++){
            et[i]=et2[i]*twidth;
        }
    }
    else{
        et[cindex]=et2[cindex]*twidth;
    }

    for(int j=0; j<number_of_lines; j++){
        ft[j]=0;

        for(int i=0; i<place; i++){
            if(ui->checkBox_2->isChecked()){    // Gauss
                sas=dt[i]*exp(-2.77254/(pow(et[i],2))*pow((ct[i]-at[j]),2));
            }
            else{   // Lorentz
                sas = dt[i]*pow(et[i],2)*ct[i]/(pow((pow(at[j],2)-pow(ct[i],2)),2)+pow(et[i],2)*pow(ct[i],2));
            }
            ft[j]+=sas;
        }
        ft[j]=tcont-ft[j];

    }
    Telluric::tellPlot();
}

//***********************************
//line shift
//***********************************
void Telluric::on_doubleSpinBox_3_valueChanged()
{
    tshift=ui->doubleSpinBox_3->value();
    if(ui->checkBox->isChecked()){
        for(int i=0; i<number_of_tellurics; i++){
            ct[i]=ct2[i]*tshift;
        }
    }
    else{
        ct[cindex]=ct2[cindex]*tshift;
    }
    for(int j=0; j<number_of_lines; j++){
        ft[j]=0;

        for(int i=0; i<place; i++){
            if(ui->checkBox_2->isChecked()){    // Gauss
                sas=dt[i]*exp(-2.77254/(pow(et[i],2))*pow((ct[i]-at[j]),2));
            }
            else{
                sas = dt[i]*pow(et[i],2)*ct[i]/(pow((pow(at[j],2)-pow(ct[i],2)),2)+pow(et[i],2)*pow(ct[i],2));
            }
            ft[j]+=sas;
        }
        ft[j]=tcont-ft[j];

    }
    Telluric::tellPlot();
}

//***************************************************
//subtract
//***************************************************
void Telluric::on_pushButton_2_clicked()
{
    for(int i=0; i<at.size(); i++){
        bt[i]=bt[i]-(ft[i]-tcont);
    }

     ui->customPlot->clearGraphs();
     ui->customPlot->addGraph();
     ui->customPlot->graph(0)->setData(at, bt);
     //ui->customPlot->xAxis->rescale();
     //ui->customPlot->yAxis->rescale();
     ui->customPlot->replot();
}

void Telluric::on_doubleSpinBox_4_valueChanged()
{
    tcont=ui->doubleSpinBox_4->value();
    Telluric::tellPlot();
}


//*************************************************************
//save
//*************************************************************
void Telluric::on_pushButton_3_clicked()
{
    QString output11=ui->lineEdit_6->text()+"/"+ui->lineEdit_7->text();
    string output1 = output11.toUtf8().constData();
    std::ostringstream output1NameStream(output1);
    output1NameStream<<output1;
    std::string output1Name = output1NameStream.str();
    ofstream file1(output1Name.c_str());

    for(int i=0; i<at.size(); i++){
        file1<<at[i]<<" "<<bt[i]<<endl;
    }
}

//**************************
// find values
//**************************
void Telluric::on_pushButton_4_clicked()
{
    Telluric::tellRead();

    tx1=at[0];
    tx2=at[0];
    ty1=bt[0];
    ty2=bt[0];

    for(int i=0; i<at.size(); i++){
        if(at[i]<tx1){
            tx1=at[i];
        }
        if(at[i]>tx2){
            tx2=at[i];
        }
        if(bt[i]<ty1){
            ty1=bt[i];
        }
        if(bt[i]>ty2){
            ty2=bt[i];
        }
        if(ft[i]<ty1){
            ty1=bt[i];
        }
        if(ft[i]>ty2){
            ty2=bt[i];
        }
    }
    ui->doubleSpinBox_5->setValue(tx1);
    ui->doubleSpinBox_6->setValue(tx2);
    ui->doubleSpinBox_7->setValue(ty1);
    ui->doubleSpinBox_8->setValue(ty2);
}

//******************************
// Apply
//******************************
void Telluric::on_pushButton_5_clicked()
{
        sas=0;
        for(int j=0; j<number_of_lines; j++){
            ft[j]=0;

            for(int i=0; i<place; i++){
                ct[i]=ct[i]*tshift;
                sas=dt[i]*exp(-2.77254/(pow(et[i],2))*pow((ct[i]-at[j]),2));
                ft[j]+=sas;
            }
            ft[j]=tcont-ft[j];
        }

    Telluric::tellPlot();

    ui->doubleSpinBox->setValue(0);
    ui->doubleSpinBox_2->setValue(0);
    ui->doubleSpinBox_3->setValue(1);
}

//****************************
// Read
//****************************
void Telluric::on_pushButton_6_clicked()
{
    Telluric::tellRead();
}

void Telluric::on_comboBox_3_currentIndexChanged()
{
    cindex=ui->comboBox_3->currentIndex();
}


//save line data
void Telluric::on_pushButton_7_clicked()
{
    QString output11=ui->lineEdit_2->text();
    string output1 = output11.toUtf8().constData();
    std::ostringstream output1NameStream(output1);
    output1NameStream<<tellPath<<"/"<<output1;
    std::string output1Name = output1NameStream.str();
    ofstream file1(output1Name.c_str());

    for(int i=0; i<place; i++){
        file1<<ct[i]<<" "<<dt[i]<<" "<<et[i]<<endl;
    }
}

//******************************
// Gauss
//******************************
void Telluric::on_checkBox_2_clicked()
{
    if(ui->checkBox_2->isChecked()){
        ui->checkBox_3->setChecked(false);
    }
    else{
        //
    }
}

//**********************************
// Lorentz
//**********************************
void Telluric::on_checkBox_3_clicked()
{
    if(ui->checkBox_3->isChecked()){
        ui->checkBox_2->setChecked(false);
    }
    else{
        //
    }
}
