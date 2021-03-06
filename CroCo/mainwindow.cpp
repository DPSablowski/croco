#include "mainwindow.h"
#include "ui_mainwindow.h"
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
#include "plotspec.h"
#include "plotsequ.h"
#include <QFileDialog>
#include <QPlainTextEdit>
#include "rvcurve.h"
#include "template.h"
#include "binarytool.h"
#include <CCfits/CCfits>
#include <cpd.h>
#include <splinefit.h>
#include <moments.h>
#include <thread>
#include <omp.h>
#include <algorithm>
#include <spline.h>

//running man icon from: https://cdn2.iconfinder.com/data/icons/windows-8-metro-style/512/running_man.png

using namespace std;
using namespace CCfits;

int num=1, stopreb=0, stopcor=0, bini=5, logbin=5, aa, d2, b2, d, b, dn, don, ssteps, counter, dosteps, vsteps, binia=5, binib=5, infilei=0, check=0;
double doshift, vshift, increment, Phi, measn, diff, tempn, tempn2, x1, x2, yy1, yy2, xc1, oset, xc2, yc1, yc2, Phi1, Phi2, min, meant, means, sigmat, sigmas, low, high, sepa, shift, de, di, ratio, inl, inh, mi, ri, t1i, t2i, dv, ccfmax, absminw, absmaxw;
string eins, zwei, line, path, Extension, Wavecol, Intenscol;
const double c0 = 299792.458;
QVector<double> measi(bini), measw(bini), tempw1(bini), tempw2(bini), tempi1(bini), tempi2(bini), temp(logbin), retw1(logbin), reti1(logbin), resamw(logbin), resami(logbin), retw2(logbin), reti2(logbin), minw(num), maxw(num), dif(num);
QString qpath, qExtension, qWavecol, qIntenscol;
std::valarray<double> wave;
std::valarray<double> intens;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    this->setWindowTitle("CroCo: 2D Cross-Correlation");

    ui->comboBox->addItem("fits");
    ui->comboBox->addItem("ASCII");

    ui->lineEdit_18->setText("DataVector");
    ui->lineEdit_19->setText("Arg");
    ui->lineEdit_20->setText("Fun");
    qExtension=ui->lineEdit_18->text();
    Extension = qExtension.toUtf8().constData();
    qWavecol=ui->lineEdit_19->text();
    Wavecol = qWavecol.toUtf8().constData();
    qIntenscol=ui->lineEdit_20->text();
    Intenscol = qIntenscol.toUtf8().constData();

    ui->lineEdit->setText("Average_");
    ui->lineEdit_2->setText("5344_5370_shift2_1.txt");
    ui->lineEdit_3->setText("5344_5370_shift_2.txt");
    ui->lineEdit_4->setText("binarym_0.txt");
    ui->lineEdit_5->setText("croped_0.txt");
    ui->lineEdit_6->setText("tempmB.txt");
    ui->lineEdit_7->setText("Averagem_");
    ui->lineEdit_8->setText("binaryrv_");
    ui->lineEdit_10->setText("tempmA.txt");
    ui->lineEdit_11->setText("tempmB.txt");
    ui->lineEdit_14->setText("ccf_0_");
    ui->lineEdit_26->setText("subA_2_");
    increment=ui->doubleSpinBox_12->value();

    ui->spinBox->setValue(0);      //default for numbers of spectra
    ui->spinBox_2->setValue(30);    //default for doppler shift
    ui->spinBox_3->setValue(70);   //default for velocity shift
    ui->spinBox_4->setValue(0);     //default first cc file
    ui->spinBox_5->setValue(1);     //default last cc file

    ui->doubleSpinBox_5->setValue(-50);
    ui->doubleSpinBox_6->setValue(50);
    ui->doubleSpinBox_7->setValue(0);
    ui->doubleSpinBox_8->setValue(1);
    ui->doubleSpinBox_13->setValue(1);
    ui->doubleSpinBox_14->setValue(1);
    ui->doubleSpinBox_16->setValue(1);
    ui->lineEdit_15->setText(QDir::currentPath());
    qpath=ui->lineEdit_15->text();
    path = qpath.toUtf8().constData();

    ui->checkBox_9->setChecked(false);
    ui->checkBox_10->setChecked(true);
    ui->checkBox_24->setChecked(true);
    ui->checkBox_27->setChecked(true);

    ui->plainTextEdit->setStyleSheet("QPlainTextEdit{background: transparent;}");

    ui->lineEdit->setStyleSheet("QLineEdit{background: transparent; border: 1px solid green;}");
    ui->lineEdit_2->setStyleSheet("QLineEdit{background: transparent; border: 1px solid green;}");
    ui->lineEdit_3->setStyleSheet("QLineEdit{background: transparent; border: 1px solid green;}");
    ui->lineEdit_4->setStyleSheet("QLineEdit{background: transparent; border: 1px solid green;}");
    ui->lineEdit_5->setStyleSheet("QLineEdit{background: transparent; border: 1px solid green;}");
    ui->lineEdit_6->setStyleSheet("QLineEdit{background: transparent; border: 1px solid green;}");
    ui->lineEdit_7->setStyleSheet("QLineEdit{background: transparent; border: 1px solid green;}");
    ui->lineEdit_8->setStyleSheet("QLineEdit{background: transparent; border: 1px solid green;}");
    ui->lineEdit_9->setStyleSheet("QLineEdit{background: transparent; border: 1px solid green;}");
    ui->lineEdit_10->setStyleSheet("QLineEdit{background: transparent; border: 1px solid green;}");
    ui->lineEdit_11->setStyleSheet("QLineEdit{background: transparent; border: 1px solid green;}");
    ui->lineEdit_12->setStyleSheet("QLineEdit{background: transparent;  border: 1px solid green;}");
    ui->lineEdit_13->setStyleSheet("QLineEdit{background: transparent; border: 1px solid green;}");
    ui->lineEdit_14->setStyleSheet("QLineEdit{background: transparent; border: 1px solid green;}");
    ui->lineEdit_15->setStyleSheet("QLineEdit{background: transparent; border: 1px solid green;}");
    ui->lineEdit_16->setStyleSheet("QLineEdit{background: transparent; border: 1px solid green;}");
    ui->lineEdit_17->setStyleSheet("QLineEdit{background: transparent; border: 1px solid green;}");
    ui->lineEdit_18->setStyleSheet("QLineEdit{background: transparent; border: 1px solid green;}");
    ui->lineEdit_19->setStyleSheet("QLineEdit{background: transparent; border: 1px solid green;}");
    ui->lineEdit_20->setStyleSheet("QLineEdit{background: transparent; border: 1px solid green;}");
    ui->lineEdit_21->setStyleSheet("QLineEdit{background: transparent; border: 1px solid green;}");

    ui->pushButton->setStyleSheet("QPushButton{border: 2px solid green;}");
    ui->pushButton_2->setStyleSheet("QPushButton{border: 2px solid green;}");
    ui->pushButton_3->setStyleSheet("QPushButton{border: 2px solid green;}");
    ui->pushButton_4->setStyleSheet("QPushButton{border: 2px solid green;}");
    ui->pushButton_5->setStyleSheet("QPushButton{border: 2px solid green;}");
    ui->pushButton_6->setStyleSheet("QPushButton{border: 2px solid green;}");
    ui->pushButton_7->setStyleSheet("QPushButton{border: 2px solid green;}");
    ui->pushButton_8->setStyleSheet("QPushButton{border: 2px solid green;}");
    ui->pushButton_9->setStyleSheet("QPushButton{border: 2px solid green;}");
    ui->pushButton_10->setStyleSheet("QPushButton{border: 2px solid green;}");

    ui->label->setStyleSheet("QLabel{background: transparent;}");
    ui->label_2->setStyleSheet("QLabel{background: transparent;}");
    ui->label_3->setStyleSheet("QLabel{background: transparent;}");
    ui->label_4->setStyleSheet("QLabel{background: transparent;}");
    ui->label_5->setStyleSheet("QLabel{background: transparent;}");
    ui->label_6->setStyleSheet("QLabel{background: transparent;}");
    ui->label_7->setStyleSheet("QLabel{background: transparent;}");
    ui->label_8->setStyleSheet("QLabel{background: transparent;}");
    ui->label_9->setStyleSheet("QLabel{background: transparent;}");
    ui->label_10->setStyleSheet("QLabel{background: transparent;}");
    ui->label_11->setStyleSheet("QLabel{background: transparent;}");
    ui->label_12->setStyleSheet("QLabel{background: transparent;}");
    ui->label_13->setStyleSheet("QLabel{background: transparent;}");
    ui->label_14->setStyleSheet("QLabel{background: transparent;}");
    ui->label_15->setStyleSheet("QLabel{background: transparent;}");
    ui->label_16->setStyleSheet("QLabel{background: transparent;}");
    ui->label_17->setStyleSheet("QLabel{background: transparent;}");
    ui->label_18->setStyleSheet("QLabel{background: transparent;}");
    ui->label_19->setStyleSheet("QLabel{background: transparent;}");
    ui->label_20->setStyleSheet("QLabel{background: transparent;}");
    ui->label_21->setStyleSheet("QLabel{background: transparent;}");
    ui->label_22->setStyleSheet("QLabel{background: transparent;}");
    ui->label_23->setStyleSheet("QLabel{background: transparent;}");
    ui->label_24->setStyleSheet("QLabel{background: transparent;}");
    ui->label_27->setStyleSheet("QLabel{background: transparent;}");
    ui->label_28->setStyleSheet("QLabel{background: transparent;}");
    ui->label_29->setStyleSheet("QLabel{background: transparent;}");
    ui->label_30->setStyleSheet("QLabel{background: transparent;}");
    ui->label_31->setStyleSheet("QLabel{background: transparent;}");
    ui->label_32->setStyleSheet("QLabel{background: transparent;}");
    ui->label_33->setStyleSheet("QLabel{background: transparent;}");
    ui->label_34->setStyleSheet("QLabel{background: transparent;}");
    ui->label_35->setStyleSheet("QLabel{background: transparent;}");
    ui->label_36->setStyleSheet("QLabel{background: transparent;}");
    ui->label_37->setStyleSheet("QLabel{background: transparent;}");
    ui->label_38->setStyleSheet("QLabel{background: transparent;}");
    ui->label_39->setStyleSheet("QLabel{background: transparent;}");
    ui->label_40->setStyleSheet("QLabel{background: transparent;}");
    ui->label_41->setStyleSheet("QLabel{background: transparent;}");
    ui->label_42->setStyleSheet("QLabel{background: transparent;}");
    ui->label_43->setStyleSheet("QLabel{background: transparent;}");
    ui->label_44->setStyleSheet("QLabel{background: transparent;}");
    ui->label_45->setStyleSheet("QLabel{background: transparent;}");
    ui->label_46->setStyleSheet("QLabel{background: transparent;}");
    ui->label_47->setStyleSheet("QLabel{background: transparent;}");
    ui->label_48->setStyleSheet("QLabel{background: transparent;}");

    /*
    ui->checkBox->setStyleSheet("QCheckBox{background: transparent;}");
    ui->checkBox_2->setStyleSheet("QCheckBox{background: transparent;}");
    ui->checkBox_3->setStyleSheet("QCheckBox{background: transparent;}");
    ui->checkBox_4->setStyleSheet("QCheckBox{background: transparent;}");
    ui->checkBox_5->setStyleSheet("QCheckBox{background: transparent;}");
    ui->checkBox_6->setStyleSheet("QCheckBox{background: transparent;}");
    ui->checkBox_7->setStyleSheet("QCheckBox{background: transparent;}");
    ui->checkBox_8->setStyleSheet("QCheckBox{background: transparent;}");
    ui->checkBox_9->setStyleSheet("QCheckBox{background: transparent;}");
    ui->checkBox_10->setStyleSheet("QCheckBox{background: transparent;}");
    ui->checkBox_11->setStyleSheet("QCheckBox{background: transparent;}");
    */


    ui->customPlot->axisRect()->setupFullAxesBox(true);
    ui->customPlot_2->axisRect()->setupFullAxesBox(true);

#pragma omp parallel
    {
    omp_set_dynamic(0);
    ui->spinBox_10->setValue(omp_get_num_threads());
    ui->spinBox_11->setValue(omp_get_num_threads());
    ui->spinBox_11->setMaximum(omp_get_num_threads());
    }

}


MainWindow::~MainWindow()
{
    delete ui;
}


//number of spectra
void MainWindow::on_spinBox_valueChanged()
{
    num=ui->spinBox->value();
}

//doppler shift
void MainWindow::on_spinBox_2_valueChanged()
{
    doshift=ui->spinBox_2->value();
}

//velocity shift
void MainWindow::on_spinBox_3_valueChanged()
{
    vshift=ui->spinBox_3->value();
}

// read data
void MainWindow::ReadMeasured(int gg){

    QString fext = ui->lineEdit_21->text();
    string sfext = fext.toUtf8().constData();

    if(ui->comboBox->currentIndex()==0){ // fits-file
        QString input=ui->lineEdit->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<path<<"/"<<data<<gg<<sfext;
        std::string datName = datNameStream.str();

        QFile checkfile1(datName.c_str());

        if(!checkfile1.exists()){
            qDebug()<<"Error 1: The file "<<checkfile1.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error1 ", "Error 1: Spectrum "+input+ +gg+ " does not exist!");
            check=1;
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        CCfits::FITS::setVerboseMode(true);

        try
        {
            qExtension=ui->lineEdit_18->text();
            Extension = qExtension.toUtf8().constData();
            qWavecol=ui->lineEdit_19->text();
            Wavecol = qWavecol.toUtf8().constData();
            qIntenscol=ui->lineEdit_20->text();
            Intenscol = qIntenscol.toUtf8().constData();

            //open file for reading
            shared_ptr<CCfits::FITS> input_file(new CCfits::FITS(datName.c_str(),CCfits::Read,true));

            // Create pointer to extension
                CCfits::ExtHDU& datavector = input_file->extension(Extension);

              // Read rows
              CCfits::Column& column = datavector.column(Wavecol);
              column.read(wave, 1, column.rows());

              // Read rows
              CCfits::Column& column2 = datavector.column(Intenscol);
              column2.read(intens, 1, column2.rows());

              bini=wave.size();

              measw.resize(bini);
              measi.resize(bini);

              for(int i=0; i<bini; i++){
              measi[i]=intens[i];
              measw[i]=wave[i];
              }


        }
            catch (CCfits::FitsException&)

             {
              std::cerr << " Fits Exception Thrown by test function \n";
              }


           // return;


    }

    if(ui->comboBox->currentIndex()==1){
        QString input=ui->lineEdit->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<path<<"/"<<data<<gg<<sfext;
        std::string datName = datNameStream.str();

        QFile checkfile1(datName.c_str());

        if(!checkfile1.exists()){
            qDebug()<<"Error 2: The file "<<checkfile1.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error 2:", "Spectrum  "+checkfile1.fileName()+" does not exist!");
            check=1;
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }
        ifstream dat(datName.c_str());

        bini=0;

        while(std::getline(dat, line))
        ++ bini;

        dat.clear();
        dat.seekg(0, ios::beg);

        measw.resize(bini);
        measi.resize(bini);

        for (int i =0; i < bini; i++){
            dat >> eins >> zwei;
            istringstream istr7(eins);
            istr7 >> measw[i];
            istringstream istr8(zwei);
            istr8 >> measi[i];
        }
        dat.close();
    }
}

//****************************************************************
//logarithmic rebinning
//****************************************************************
void MainWindow::on_pushButton_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));

// Logfile
    QString qLogFile = "logarithmicbin.log";
    QString qlFile = qpath+"/"+qLogFile;
    QFileInfo QLFile(qlFile);
    string lFile = qLogFile.toUtf8().constData();
    std::ostringstream lFileNameStream(lFile);
    lFileNameStream<<path<<"/"<<lFile;
    std::string lFileName = lFileNameStream.str();
    ofstream LogFile;

    struct tm *ts;
    time_t t;

    t = time(NULL);
    ts = localtime(&t);

    if(QLFile.exists()){
        LogFile.open(lFileName.c_str(), std::ios_base::app);
        LogFile<<endl;
        LogFile<<"__________________________________________________"<<endl;
        LogFile<<" "<<asctime(ts)<<endl;
        LogFile<<endl;
    }

    else{
        LogFile.open(lFileName.c_str());
        LogFile<<"******************************"<<endl;
        LogFile<<"  Logarithmic Binning Log-File"<<endl;
        LogFile<<"******************************"<<endl;
    }

    LogFile<<"Input files: "<<ui->lineEdit->text().toUtf8().constData()<<"*"<<ui->lineEdit_21->text().toUtf8().constData()<<endl;
    LogFile<<"Output files: "<<ui->lineEdit_7->text().toUtf8().constData()<<"*.txt"<<endl;
    LogFile<<"Files from "<<ui->spinBox->value()<<" to "<<ui->spinBox_8->value()<<endl;
    LogFile<<"Rebinning step size: "<<ui->doubleSpinBox_12->value()<<endl;

    num=ui->spinBox_8->value() - ui->spinBox->value()+1;

    if(ui->checkBox_4->isChecked()){
        num = 1;
    }

    minw.resize(num);
    maxw.resize(num);
    dif.resize(num);

//find largest common wavelength range of measured spectra
    for(int g=0; g<num; g++){

        int gg = g+ui->spinBox->value();

        if(ui->checkBox_4->isChecked()){
            g=ui->spinBox->value();
            gg=g;
        }


    //read measuremens
    MainWindow::ReadMeasured(gg);
    cout<<"read spectrum no. "<<gg<<endl;

    if(check==1){
        check=0;
        return;
    }

    minw[g]=measw[0];
    maxw[g]=measw[bini-1];

    //looking for smallest difference log(lambda)
    dif[g] = log10(measw[1])-log10(measw[0]);
    for (int i=0; i<bini-1; i++){
    if ((abs(log10(measw[i+1])-log10(measw[i])))<abs(dif[g])){
    dif[g] = (log10(measw[i+1])-log10(measw[i]));
    }
            }
    cout<<dif[g]<<endl;
    }

    absminw=minw[0];
    absmaxw=maxw[0];

    for(int i=0; i<num; i++){
        if(minw[i]>absminw){
            absminw=minw[i];
        }
        if(maxw[i]<absmaxw){
            absmaxw=maxw[i];
        }
    }

    if(ui->checkBox_10->isChecked()){
         LogFile<<"Use common wavelength range; lower: "<<absminw<<"; upper: "<<absmaxw<<endl;
    }

    else{
        if(ui->checkBox_11->isChecked()){

        if(absminw>ui->doubleSpinBox_17->value()){
            qDebug()<<"Error : At least one spectrum starts at a higher wavelength.";
            QString absmi=QString::number(absminw);
            QMessageBox::information(this, "Error ", "Error : At least one spectrum starts at a higher wavelength. The common value is "+absmi+".");
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }

        if(absmaxw<ui->doubleSpinBox_18->value()){
            qDebug()<<"Error : At least one spectrum ends at a lower wavelength.";
            QString absma=QString::number(absmaxw);
            QMessageBox::information(this, "Error ", "Error : At least one spectrum ends at a lower value. The common value is "+absma+".");
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }

        absminw=ui->doubleSpinBox_17->value();
        absmaxw=ui->doubleSpinBox_18->value();
        LogFile<<"Use wavelength range; lower: "<<absminw<<"; upper: "<<absmaxw<<endl;

    }
    }

    //looking for global smallest difference log(lambda)
    if(ui->checkBox_22->isChecked()){
        diff=1.0;
        for (int g=0; g<num; g++){
            if(ui->checkBox_4->isChecked()){
                g=ui->spinBox->value();
            }
            if((dif[g]<diff) & (dif[g]>0)){
                diff=dif[g];
                //cout<<diff<<endl;
            }
        }
        LogFile<<"Using global minimum for new step size."<<endl;
    }
    else{
        // compute average of differences
        if(ui->checkBox_23->isChecked()){
            diff=0.0;
            int ndiff=0;
            for (int g=0; g<num; g++){
                if(ui->checkBox_4->isChecked()){
                    g=ui->spinBox->value();
                }
                if((dif[g]<diff) & (dif[g]>0)){
                    diff+=dif[g];
                    ++ndiff;
                    //cout<<diff<<endl;
                }
            }
        diff=diff/ndiff;
        LogFile<<"Using average for new step size."<<endl;
        }
        else{
            // compute median of differences
            sort(dif.begin(), dif.end());

            int med1=dif.size()/2, med2=dif.size()/2-1;

            if(abs(med1-dif.size()/2)!=0.0){
                diff=(dif[med1]+dif[med2])/2;
            }
            else{
                diff=dif[med1];
            }
            LogFile<<"Using median for new step size."<<endl;
        }
    }


    cout<<"global min diff: "<<diff<<endl;

    if(ui->checkBox_14->isChecked()){
        //diff = abs(log10(absminw+ui->doubleSpinBox_19->value())-log10(absminw));
        diff = ui->lineEdit_28->text().toDouble();
        LogFile<<"Use custom step size: "<<diff<<endl;
    }

    else{
        diff=diff*increment;
        LogFile<<setprecision(14)<<"Use step size: "<<diff<<endl;
    }

    cout<<"new step size: "<<diff<<endl;

    if(diff==0){
        cout<<"step size is zero! Rebinning aborted."<<endl;
        QMessageBox::information(this, "Error", "Step size is zero! Rebinning aborted.");
        this->setCursor(QCursor(Qt::ArrowCursor));
        LogFile<<"Step size is zero, rebinning aborted."<<endl;
        return;
    }

    dv=(pow(10,diff)-1)*c0;
    LogFile<<"Step size in velocity: "<<dv<<" km/s"<<endl;
    QString Vsize=QString::number(dv);
    ui->lineEdit_16->setText(Vsize);

    for(int g=0; g<num; g++){

        int gg = g + ui->spinBox->value();

        if(ui->checkBox_4->isChecked()){
            g=ui->spinBox->value();
            gg = g;
        }

        //crop files
        //measured
        MainWindow::ReadMeasured(gg);

        QString output11="croped1_";
        string output1 = output11.toUtf8().constData();
        std::ostringstream output1NameStream(output1);
        output1NameStream<<path<<"/"<<output1<<g<<".txt";
        std::string output1Name = output1NameStream.str();
        ofstream file1(output1Name.c_str());

        for(int i=0; i<bini; i++){
            if((measw[i]>=absminw) & (measw[i]<=absmaxw)){
                file1<<setprecision(14)<<measw[i]<<" "<<measi[i]<<endl;
            }
        }

        ifstream dat1(output1Name.c_str());
        bini=0;

        while(std::getline(dat1, line))
           ++ bini;

        dat1.clear();
        dat1.seekg(0, ios::beg);

        measw.resize(bini);
        measi.resize(bini);

        for (int i =0; i < bini; i++){
            dat1 >> eins >> zwei;
            istringstream istr7(eins);
            istr7 >> measw[i];
            istringstream istr8(zwei);
            istr8 >> measi[i];
        }
        dat1.close();
    }

        if(ui->checkBox_9->isChecked()){
        //template1
        QString input12=ui->lineEdit_2->text();
        string data12 = input12.toUtf8().constData();
        std::ostringstream dat2NameStream(data12);
        dat2NameStream<<path<<"/"<<data12;
        std::string dat2Name = dat2NameStream.str();

        QFile checkfile2(dat2Name.c_str());

        if(!checkfile2.exists()){
            qDebug()<<"Error 3: The file "<<checkfile2.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "Error 3: Template A does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }
        ifstream dat2(dat2Name.c_str());

        bini=0;

        while(std::getline(dat2, line))
           ++ bini;

        dat2.clear();
        dat2.seekg(0, ios::beg);

        tempw1.resize(bini);
        tempi1.resize(bini);

        for (int i =0; i < bini; i++){
            dat2 >> eins >> zwei;
            istringstream istr5(eins);
            istr5 >> tempw1[i];
            istringstream istr6(zwei);
            istr6 >> tempi1[i];
            if((i==0) & (tempw1[0]>absminw)){
                QMessageBox::information(this, "Error", "Error 4: Template A starts at higher wavelength "+QString::number(tempw1[0])+" than all spectra. " +absminw);
                this->setCursor(QCursor(Qt::ArrowCursor));
                return;
            }
            if((i==bini-1)& (tempw1[bini-1]<absmaxw)){
                QMessageBox::information(this, "Error", "Error 5: Template A ends at lower wavelength "+QString::number(tempw1[i])+" than all spectra. "+absmaxw);
                this->setCursor(QCursor(Qt::ArrowCursor));
                return;
            }
        }
        dat2.close();

        QString output12="cropedt1.txt";
        string output2 = output12.toUtf8().constData();
        std::ostringstream output2NameStream(output2);
        output2NameStream<<path<<"/"<<output2;
        std::string output2Name = output2NameStream.str();
        ofstream file2(output2Name.c_str());

        for(int i=0; i<bini; i++){
            if((tempw1[i]>=absminw) & (tempw1[i]<=absmaxw)){
                file2<<setprecision(14)<<tempw1[i]<<" "<<tempi1[i]<<endl;
            }
        }

        //template2
        QString input13=ui->lineEdit_3->text();
        string data13 = input13.toUtf8().constData();
        std::ostringstream dat3NameStream(data13);
        dat3NameStream<<path<<"/"<<data13;
        std::string dat3Name = dat3NameStream.str();

        QFile checkfile3(dat3Name.c_str());

        if(!checkfile3.exists()){
            qDebug()<<"Error 6: The file "<<checkfile3.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "Error 6: Template B does not exist!");
            return;
        }
        ifstream dat3(dat3Name.c_str());

        bini=0;

        while(std::getline(dat3, line))
           ++ bini;

        dat3.clear();
        dat3.seekg(0, ios::beg);

        tempw2.resize(bini);
        tempi2.resize(bini);

        for (int i =0; i < bini; i++){
            dat3 >> eins >> zwei;
            istringstream istr3(eins);
            istr3 >> tempw2[i];
            istringstream istr4(zwei);
            istr4 >> tempi2[i];
            if((i==0) & (tempw2[0]>absminw)){
                QMessageBox::information(this, "Error", "Error 7: Template B starts at higher wavelength "+QString::number(tempw2[0])+" than all spectra. "+absminw);
                this->setCursor(QCursor(Qt::ArrowCursor));
                return;
            }
            if((i==bini-1)& (tempw2[bini-1]<absmaxw)){
                QMessageBox::information(this, "Error", "Error 8: Template B ends at lower wavelength "+QString::number(tempw2[i])+" than all spectra. "+absmaxw);
                this->setCursor(QCursor(Qt::ArrowCursor));
                return;
            }
        }
        dat3.close();

        QString output13="cropedt2.txt";
        string output3 = output13.toUtf8().constData();
        std::ostringstream output3NameStream(output3);
        output3NameStream<<path<<"/"<<output3;
        std::string output3Name = output3NameStream.str();
        ofstream file3(output3Name.c_str());

        for(int i=0; i<bini; i++){
            if((tempw2[i]>=absminw) & (tempw2[i]<=absmaxw)){
                file3<<setprecision(14)<<tempw2[i]<<" "<<tempi2[i]<<endl;
            }
        }
     }



//******************************************************
//rebinning
//******************************************************

        ui->progressBar->setValue(0);
        tk::spline sp;
        vector<double> Ys(4), Xs(4);
        ui->progressBar->setValue(0);

    for(int g=0; g<num; g++){

    ui->customPlot->clearGraphs();



        if(ui->checkBox_4->isChecked()){
            g=num-1;
        }

         counter=(g+1);
         QString progress= QString::number(counter);
         ui->lineEdit_9->setText(progress);
         qApp->processEvents(QEventLoop::AllEvents);

         if(stopreb==1){
             stopreb=0;
             this->setCursor(QCursor(Qt::ArrowCursor));
             return;
         }
         else{
             //
         }

         measn=ui->doubleSpinBox_13->value();
         tempn=ui->doubleSpinBox_14->value();
         tempn2=ui->doubleSpinBox_16->value();

         //read measured spectrum

       QString input="croped1_";

        string data1 = input.toUtf8().constData();
         std::ostringstream dat1NameStream(data1);
         dat1NameStream<<path<<"/"<<data1<<g<<".txt";
         std::string dat1Name = dat1NameStream.str();

         QFile checkfile1(dat1Name.c_str());

         if(!checkfile1.exists()){
             qDebug()<<"Error 9: The file "<<checkfile1.fileName()<<" does not exist.";
             QMessageBox::information(this, "Error", "Error 9: Spectrum "+checkfile1.fileName()+" does not exist!");
             this->setCursor(QCursor(Qt::ArrowCursor));
            return;
         }
         ifstream dat1(dat1Name.c_str());

         bini=0;

         while(std::getline(dat1, line))
            ++ bini;

         dat1.clear();
         dat1.seekg(0, ios::beg);

         measi.resize(bini);
         measw.resize(bini);

         for (int i=0; i<bini; i++){
            dat1 >> eins >>zwei;
            istringstream istr(eins);
            istr >> measw[i];
            measw[i]=log10(measw[i]);
            istringstream istr2(zwei);
            istr2 >> measi[i];
            measi[i]=measi[i];
         }
         dat1.close();

         logbin=abs((measw[bini-1]-measw[0])/diff);

         if(logbin<0){
        cout<<diff<<" "<<logbin<<" "<<(measw[bini-1]-measw[0])<<endl;
         QMessageBox::information(this, "Error 28", "Error 28: Negative number of logarithmic bins. Check file structure (empty last row?).");
         this->setCursor(QCursor(Qt::ArrowCursor));
         return;
         }

         //interpolation measured

         QString output11=ui->lineEdit_7->text();
         string output1 = output11.toUtf8().constData();
         std::ostringstream output1NameStream(output1);
         output1NameStream<<path<<"/"<<output1<<g<<".txt";
         std::string output1Name = output1NameStream.str();
         ofstream file1(output1Name.c_str());

         resamw.resize(logbin);
         resami.resize(logbin);
         double coefa=0.0, coefb=0.0, coefc=0.0;

         aa=0;

         for(int i=0; i<logbin; i++){

             resamw[i]=measw[0]+i*diff;
             resami[i]=0.0;

             for(int e=0; e<bini; e++){

                 // linear interpolation
                 if(ui->checkBox_27->isChecked()){
                    if(measw[e]==resamw[i]){
                        resami[i]=measi[e];
                        aa=e;
                    }
                    else{
                        if((measw[e]<resamw[i])&(measw[e+1]>resamw[i])){
                            resami[i]=measi[e]+(resamw[i]-measw[e])/(measw[e+1]-measw[e])*(measi[e+1]-measi[e]);
                            aa=e;
                        }
                        else{
                            //
                        }
                    }
                }
                // spline interpolation
                 else{
                     if(resamw[i]<measw[4]){ // use first three data points
                        /* with coefficients
                         coefa = (measw[0]*(measi[1]-measi[2])+measw[1]*(measi[2]-measi[0])+measw[2]*(measi[0]-measi[1]))/((measw[0]-measw[1])*(measw[0]-measw[2])*(measw[2]-measw[1]));
                         coefb = -(pow(measw[0],2)*(measi[1]-measi[2])+pow(measw[1],2)*(measi[2]-measi[0])+pow(measw[2],2)*(measi[0]-measi[1]))/((measw[0]-measw[1])*(measw[0]-measw[2])*(measw[2]-measw[1]));
                         coefc = -(pow(measw[0],2)*(measw[1]*measi[2]-measw[2]*measi[1])+measw[0]*(pow(measw[2],2)*measi[1]-pow(measw[1],2)*measi[2])+measw[1]*measw[2]*measi[0]*(measw[1]-measw[2]))/((measw[0]-measw[1])*(measw[0]-measw[2])*(measw[2]-measw[1]));
                         resami[i]=coefc+coefb*resamw[i]+coefa*pow(resamw[i],2);
                         if((i==0) & (e==0)){
                            cout<<coefa<<"\t"<<coefb<<"\t"<<coefc<<endl;
                            cout<<resamw[i]<<"\t"<<resami[i]<<endl;
                            cout<<endl;
                         }*/
                         //resami[i]=measi[1]+((measi[2]+measi[0])/2*(resamw[i]-measw[1])/diff)+((measi[2]-2*measi[1]+measi[0])/4*pow(((resamw[i]-measw[1])/diff),2));
                         Xs[0]=measw[0];
                         Xs[1]=measw[1];
                         Xs[2]=measw[2];
                         Xs[3]=measw[3];
                         Ys[0]=measi[0];
                         Ys[1]=measi[1];
                         Ys[2]=measi[2];
                         Ys[3]=measi[3];
                         coefa=resamw[i];
                         sp.set_points(Xs,Ys);
                         resami[i]=sp(coefa);
                         e=bini;
                         aa=0;
                     }
                     else{
                         if(resamw[i]>(measw[bini-4])){  // use last three data points
                             /*coefa = (measw[bini-3]*(measi[bini-2]-measi[bini-1])+measw[bini-2]*(measi[bini-1]-measi[bini-3])+measw[bini-1]*(measi[bini-3]-measi[bini-2]))/((measw[bini-3]-measw[bini-2])*(measw[bini-3]-measw[bini-1])*(measw[bini-1]-measw[bini-2]));
                             coefb = -(pow(measw[bini-3],2)*(measi[bini-2]-measi[bini-1])+pow(measw[bini-2],2)*(measi[bini-1]-measi[bini-3])+pow(measw[bini-1],2)*(measi[bini-3]-measi[bini-2]))/((measw[bini-3]-measw[bini-2])*(measw[bini-3]-measw[bini-1])*(measw[bini-1]-measw[bini-2]));
                             coefc = -(pow(measw[bini-3],2)*(measw[bini-2]*measi[bini-1]-measw[bini-1]*measi[bini-2])+measw[bini-3]*(pow(measw[bini-1],2)*measi[bini-2]-pow(measw[bini-2],2)*measi[bini-1])+measw[bini-2]*measw[bini-1]*measi[bini-3]*(measw[bini-2]-measw[bini-1]))/((measw[bini-3]-measw[bini-2])*(measw[bini-3]-measw[bini-1])*(measw[bini-1]-measw[bini-2]));
                             resami[i]=coefc+coefb*resamw[i]+coefa*pow(resamw[i],2);*/
                             //resami[i]=measi[bini-2]+((measi[bini-1]+measi[bini-3])/2*(resamw[i]-measw[bini-2])/diff)+((measi[bini-1]-2*measi[bini-2]+measi[bini-3])/4*pow(((resamw[i]-measw[bini-2])/diff),2));
                             Xs[0]=measw[bini-4];
                             Xs[1]=measw[bini-3];
                             Xs[2]=measw[bini-2];
                             Xs[3]=measw[bini-1];
                             Ys[0]=measi[bini-4];
                             Ys[1]=measi[bini-3];
                             Ys[2]=measi[bini-2];
                             Ys[3]=measi[bini-1];
                             coefa=resamw[i];
                             sp.set_points(Xs,Ys);
                             resami[i]=sp(coefa);
                             e=bini;
                         }
                         else{
                             if(resamw[i]==measw[e]){
                                 resami[i]=measi[e];
                                 aa=e;
                                 e=bini;
                             }
                             else{
                                if((resamw[i]>measw[e]-diff/2) & (resamw[i]<measw[e]+diff/2)){
                                    /* coefa = (measw[e-1]*(measi[e]-measi[e+1])+measw[e]*(measi[e+1]-measi[e-1])+measw[e+1]*(measi[e-1]-measi[e]))/((measw[e-1]-measw[e])*(measw[e-1]-measw[e+1])*(measw[e+1]-measw[e]));
                                    coefb = -(pow(measw[e-1],2)*(measi[e]-measi[e+1])+pow(measw[e],2)*(measi[e+1]-measi[e-1])+pow(measw[e+1],2)*(measi[e-1]-measi[e]))/((measw[e-1]-measw[e])*(measw[e-1]-measw[e+1])*(measw[e+1]-measw[e]));
                                    coefc = -(pow(measw[e-1],2)*(measw[e]*measi[e+1]-measw[e+1]*measi[e])+measw[e-1]*(pow(measw[e+1],2)*measi[e]-pow(measw[e],2)*measi[e+1])+measw[e]*measw[e+1]*measi[e-1]*(measw[e]-measw[e+1]))/((measw[e-1]-measw[e])*(measw[e-1]-measw[e+1])*(measw[e+1]-measw[e]));
                                    resami[i]=coefc+coefb*resamw[i]+coefa*pow(resamw[i],2);*/
                                    //resami[i]=measi[e]+((measi[e+1]+measi[e-1])*(resamw[i]-measw[e])/(2*diff))+((measi[e+1]-2*measi[e]+measi[e-1])/4*pow(((resamw[i]-measw[e])/diff),2));
                                    Xs[0]=measw[e-1];
                                    Xs[1]=measw[e];
                                    Xs[2]=measw[e+1];
                                    Xs[3]=measw[e+2];
                                    Ys[0]=measi[e-1];
                                    Ys[1]=measi[e];
                                    Ys[2]=measi[e+1];
                                    Ys[3]=measi[e+2];
                                    coefa=resamw[i];
                                    sp.set_points(Xs,Ys);
                                    resami[i]=sp(coefa);
                                    aa=e;
                                    e=bini;
                                }
                                else{

                                }
                             }
                         }
                     }
                 }
             }
             if((resami[i]==0.0)){
                 resami[i]=measi[aa];
             }
             file1<<std::setprecision(14)<<resamw[i]<<"\t"<<resami[i]<<endl;

         }
         file1.close();


                 for (int i=0; i+1<bini; i++){
                    mi+=(measw[i+1]-measw[i])*((measi[i]+measi[i+1])/2);
                 }
                 for (int i=0; i+1<logbin; i++){
                    ri+=(resamw[i+1]-resamw[i])*((resami[i]+resami[i+1])/2);
                 }
                 ui->progressBar->setValue(100*(g+1)/num);
                 qApp->processEvents(QEventLoop::AllEvents);


                 //plot spectra
                 ui->doubleSpinBox->setValue(measw[0]);
                 x1=measw[0];
                 ui->doubleSpinBox_2->setValue(measw[bini-1]);
                 x2=measw[bini-1];


                 ui->customPlot->legend->setVisible(true);
                 QFont legendFont = font();
                 legendFont.setPointSize(9);
                 ui->customPlot->legend->setFont(legendFont);
                 ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
                 ui->customPlot->addGraph();
                 ui->customPlot->addGraph();
                 ui->customPlot->graph(0)->setData(measw, measi);
                 ui->customPlot->graph(1)->setPen(QPen(Qt::red));
                 ui->customPlot->graph(1)->setData(resamw, resami);
                 ui->customPlot->xAxis->setLabel("wavelength axis");
                 ui->customPlot->yAxis->setLabel("spectrum value");
                 ui->customPlot->xAxis->rescale();
                 ui->customPlot->graph(0)->rescaleAxes();
                 ui->customPlot->graph(1)->rescaleAxes(true);
                 ui->customPlot->replot();

        }

                 if(ui->checkBox_9->isChecked()){
                    //read primary template
                    QString input2=ui->lineEdit_2->text();

                    if(ui->checkBox_10->isChecked()){
                         //input2="cropedt1";
                    }

                    string data2 = input2.toUtf8().constData();
                    std::ostringstream dat2NameStream(data2);
                    dat2NameStream<<path<<"/"<<data2;
                    std::string dat2Name = dat2NameStream.str();

                 QFile checkfile2(dat2Name.c_str());

                 if(!checkfile2.exists()){
                     qDebug()<<"Error 10: The file "<<checkfile2.fileName()<<" does not exist.";
                     QMessageBox::information(this, "Error", "Error 10: Template A does not exist!");
                     this->setCursor(QCursor(Qt::ArrowCursor));
                    return;
                 }
                 ifstream dat2(dat2Name.c_str());

                 binia=0;

                 while(std::getline(dat2, line))
                    ++ binia;

                 dat2.clear();
                 dat2.seekg(0, ios::beg);

                 if(binia==0){
                     QMessageBox::information(this, "Error", "Error 11: Check template A, it is empty. It may be that the template has a different wavelength range.");
                     this->setCursor(QCursor(Qt::ArrowCursor));
                    return;
                 }


                 /*
                 if(bini<binia){
                     QMessageBox::information(this, "Error", "Error 12: Sampling of Template A to high!");
                     this->setCursor(QCursor(Qt::ArrowCursor));
                    return;
                 }*/

                 tempi1.resize(binia);
                 tempw1.resize(binia);

                 QString output21=ui->lineEdit_10->text();
                 string output2 = output21.toUtf8().constData();
                 std::ostringstream file2NameStream(output2);
                 file2NameStream<<path<<"/"<<output2;
                 std::string file2Name = file2NameStream.str();
                 ofstream file2(file2Name.c_str());

                 for (int i =0; i < binia; i++){
                    dat2 >> eins >> zwei;
                    istringstream istr4(eins);
                    istr4 >> tempw1[i];
                    tempw1[i]=log10(tempw1[i]);
                    istringstream istr5(zwei);
                    istr5 >> tempi1[i];
                    tempi1[i]=(tempi1[i]-tempn);
                    if(ui->checkBox_15->isChecked()){
                        tempi1[i]=tempi1[i]*ui->lineEdit_24->text().toDouble();
                    }
                 }
                 dat2.close();

                 //read secondary template
                 QString input3=ui->lineEdit_3->text();

                 if(ui->checkBox_10->isChecked()){
                    //input3="cropedt2";
                 }

                 string data3 = input3.toUtf8().constData();
                 std::ostringstream dat3NameStream(data3);
                 dat3NameStream<<path<<"/"<<data3;
                 std::string dat3Name = dat3NameStream.str();

                 QFile checkfile3(dat3Name.c_str());

                 if(!checkfile3.exists()){
                     qDebug()<<"The file "<<checkfile3.fileName()<<" does not exist.";
                     QMessageBox::information(this, "Error", "Error 13: Template B does not exist!");
                     this->setCursor(QCursor(Qt::ArrowCursor));
                    return;
                 }
                 ifstream dat3(dat3Name.c_str());

                 this->setCursor(QCursor(Qt::WaitCursor));

                 binib=0;

                 while(std::getline(dat3, line))
                    ++ binib;

                 dat3.clear();
                 dat3.seekg(0, ios::beg);

                 if(binib==0){
                     QMessageBox::information(this, "Error", "Error 14: Check template B, it is empty. It may be that the template has a different wavelength range.");
                     this->setCursor(QCursor(Qt::ArrowCursor));
                    return;
                 }

                 /*
                 if(bini<binib){
                     QMessageBox::information(this, "Error", "Error 15: Sampling of template B to high!");
                     this->setCursor(QCursor(Qt::ArrowCursor));
                    return;
                 }*/

                 tempi2.resize(binib);
                 tempw2.resize(binib);

                 for (int i =0; i < binib; i++){
                    dat3 >> eins >> zwei;
                    istringstream istr7(eins);
                    istr7 >> tempw2[i];
                    tempw2[i]=log10(tempw2[i]);
                    istringstream istr8(zwei);
                    istr8 >> tempi2[i];
                    tempi2[i]=(tempi2[i]-tempn2);
                    if(ui->checkBox_16->isChecked()){
                        tempi2[i]=tempi2[i]*ui->lineEdit_25->text().toDouble();
                    }
                 }
                 dat3.close();

                 QString output31=ui->lineEdit_11->text();
                 string output3 = output31.toUtf8().constData();
                 std::ostringstream file3NameStream(output3);
                 file3NameStream<<path<<"/"<<output3;
                 std::string file3Name = file3NameStream.str();
                 ofstream file3(file3Name.c_str());

        //interpolation primary template

        retw1.resize(logbin);
        reti1.resize(logbin);

        aa=0;

        for(int i=0; i<logbin; i++){

            retw1[i]=resamw[i]; //tempw1[0]+i*diff;
            reti1[i]=0;

            for(int e=0; e<binia; e++){

                if(tempw1[e]==retw1[i]){
                    reti1[i]=tempi1[e];
                    aa=e;
                }
                if((tempw1[e]<retw1[i])&(tempw1[e+1]>retw1[i])){
                    reti1[i]=tempi1[e]+(retw1[i]-tempw1[e])/(tempw1[e+1]-tempw1[e])*(tempi1[e+1]-tempi1[e]);
                    aa=e;
                }
            }
            file2<<std::setprecision(14)<<resamw[i]<<"\t"<<reti1[i]<<endl;
        }
        file2.close();



        //interpolation secondary template
        retw2.resize(logbin);
        reti2.resize(logbin);

        aa=0;

        for(int i=0; i<logbin; i++){

            retw2[i]=resamw[i]; //tempw2[0]+i*diff;
            reti2[i]=0;

            for(int e=aa; e<binib; e++){

                if(tempw2[e]==retw2[i]){
                    reti2[i]=tempi2[e];
                    aa=e;
                }
                if((tempw2[e]<retw2[i])&(tempw2[e+1]>retw2[i])){
                    reti2[i]=tempi2[e]+(retw2[i]-tempw2[e])/(tempw2[e+1]-tempw2[e])*(tempi2[e+1]-tempi2[e]);
                    aa=e;
                }
            }
            file3<<std::setprecision(14)<<resamw[i]<<"\t"<<reti2[i]<<endl;
        }
        file3.close();

                 }


    ui->progressBar->setValue(100);
    this->setCursor(QCursor(Qt::ArrowCursor));
}

//*******************************************************************
//Read fits header or extension header, from example program listhead.c
//*******************************************************************
void MainWindow::ReadHeader(int argc,   char *argv[])
{
    ui->plainTextEdit->clear();
    fitsfile *fptr;         /* FITS file pointer, defined in fitsio.h */
    char card[FLEN_CARD];   /* Standard string lengths defined in fitsio.h */
    int status = 0;   /* CFITSIO status value MUST be initialized to zero! */
    int single = 0, hdupos, nkeys, ii;

    if (argc != 2) {
        ui->plainTextEdit->appendPlainText("Usage: filename[ext]\n"
                                           "\n"
                                           "List the FITS header keywords in a single extension, of, if\n"
                                           "ext is not given, list the keywords in all the extensions.\n"
                                           "\n"
                                           "Examples: \n"
                                           "   listhead file.fits      - list every header in the file \n"
                                           "   listhead file.fits[0]   - list primary array header \n"
                                           "   listhead file.fits[2]   - list header of 2nd extension \n"
                                           "   listhead file.fits+2    - same as above \n"
                                           "   listhead file.fits[GTI] - list header of GTI extension\n");

      return;
    }

    if (!fits_open_file(&fptr, argv[1], READONLY, &status))
    {
      fits_get_hdu_num(fptr, &hdupos);  /* Get the current HDU position */

      /* List only a single header if a specific extension was given */
      if (hdupos != 1 || strchr(argv[1], '[')) single = 1;

      for (; !status; hdupos++)  /* Main loop through each extension */
      {
        fits_get_hdrspace(fptr, &nkeys, NULL, &status); /* get # of keywords */

        QString dg=QString::number(hdupos);
        ui->plainTextEdit->appendPlainText("Header listing for HDU #"+dg+":");

        for (ii = 1; ii <= nkeys; ii++) { /* Read and print each keywords */

           if (fits_read_record(fptr, ii, card, &status))break;
          QString car(card);
           ui->plainTextEdit->appendPlainText(car);
        }
        ui->plainTextEdit->appendPlainText("END\n\n");  /* terminate listing with END */

        if (single) break;  /* quit if only listing a single header */

        fits_movrel_hdu(fptr, 1, NULL, &status);  /* try to move to next HDU */
      }

      if (status == END_OF_FILE)  status = 0; /* Reset after normal error */

      fits_close_file(fptr, &status);
    }

    if (status) fits_report_error(stderr, status); /* print any error message */

    return;
}

//****************************************************************
//Plot spectra button
//****************************************************************
void MainWindow::on_pushButton_3_clicked()
{
    ui->customPlot->clearGraphs();

    QString plot1=ui->lineEdit_4->text();
    string plot11 = plot1.toUtf8().constData();
    std::ostringstream dat1NameStream(plot11);
    dat1NameStream<<path<<"/"<<plot11;
    std::string dat1Name = dat1NameStream.str();

    QFile checkfile1(dat1Name.c_str());

    if(!checkfile1.exists()){
        qDebug()<<"Error 16: The file "<<checkfile1.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "Error 16: File 1 does not exist!");
       return;
    }
    ifstream toplot1(dat1Name.c_str());

    QString plot2=ui->lineEdit_5->text();
    string plot12 = plot2.toUtf8().constData();
    std::ostringstream dat2NameStream(plot12);
    dat2NameStream<<path<<"/"<<plot12;
    std::string dat2Name = dat2NameStream.str();

    QFile checkfile2(dat2Name.c_str());

    if(!checkfile2.exists()){
        qDebug()<<"Error 17: The file "<<checkfile2.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "Error 17: File 2 does not exist!");
       return;
    }
    ifstream toplot2(dat2Name.c_str());

    QString plot3=ui->lineEdit_6->text();
    string plot13 = plot3.toUtf8().constData();
    std::ostringstream dat3NameStream(plot13);
    dat3NameStream<<path<<"/"<<plot13;
    std::string dat3Name = dat3NameStream.str();

    QFile checkfile3(dat3Name.c_str());

    if(!checkfile3.exists()){
        qDebug()<<"Error 18: The file "<<checkfile3.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "Error 18: File 3 does not exist!");
       return;
    }
    ifstream toplot3(dat3Name.c_str());

    int number_of_lines =0;

    while(std::getline(toplot1, line))
       ++ number_of_lines;

    toplot1.clear();
    toplot1.seekg(0, ios::beg);

    QVector<double> a(number_of_lines), b(number_of_lines);

    for (int i=0; i<number_of_lines; i++){
    toplot1 >> eins >>zwei;
    istringstream ist(eins);
    ist >> a[i];
    if(ui->checkBox->isChecked()){
        a[i]=log10(a[i]);
    }
    istringstream ist2(zwei);
    ist2 >> b[i];
    if(ui->checkBox_5->isChecked()){
        double yadd1=ui->doubleSpinBox_9->value();
        b[i]=b[i]+yadd1;
    }
    }
    toplot1.close();

    number_of_lines=0;
    while(std::getline(toplot2, line))
       ++ number_of_lines;

    toplot2.clear();
    toplot2.seekg(0, ios::beg);

    QVector<double> c(number_of_lines), d(number_of_lines);

    for (int i=0; i<number_of_lines; i++){
    toplot2 >> eins >>zwei;
    istringstream ist3(eins);
    ist3 >> c[i];
    if(ui->checkBox_2->isChecked()){
        c[i]=log10(c[i]);
    }
    istringstream ist4(zwei);
    ist4 >> d[i];
    if(ui->checkBox_6->isChecked()){
        double yadd2=ui->doubleSpinBox_10->value();
        d[i]=d[i]+yadd2;
    }
    }
    toplot2.close();

    number_of_lines=0;
    while(std::getline(toplot3, line))
       ++ number_of_lines;

    toplot3.clear();
    toplot3.seekg(0, ios::beg);

    QVector<double> e(number_of_lines), f(number_of_lines);

    for (int i=0; i<number_of_lines; i++){
    toplot3 >> eins >>zwei;
    istringstream ist5(eins);
    ist5 >> e[i];
    if(ui->checkBox_3->isChecked()){
        e[i]=log10(e[i]);
    }
    istringstream ist6(zwei);
    ist6 >> f[i];
    if(ui->checkBox_7->isChecked()){
        double yadd3=ui->doubleSpinBox_11->value();
        f[i]=f[i]+yadd3;
    }
    }
    toplot3.close();

    ui->customPlot->legend->setVisible(true);
    QFont legendFont = font();
    legendFont.setPointSize(9);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
    ui->customPlot->addGraph();
    ui->customPlot->addGraph();
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setName("File 1");
    ui->customPlot->graph(1)->setName("File 2");
    ui->customPlot->graph(2)->setName("File 3");
    ui->customPlot->graph(0)->setData(a, b);
    ui->customPlot->graph(1)->setPen(QPen(Qt::red));
    ui->customPlot->graph(1)->setData(c, d);
    ui->customPlot->graph(2)->setPen(QPen(Qt::green));
    ui->customPlot->graph(2)->setData(e, f);
    ui->customPlot->xAxis->setLabel("wavelength axis");
    ui->customPlot->yAxis->setLabel("spectrum value");
    ui->customPlot->xAxis->setRange(x1, x2);
    ui->customPlot->yAxis->setRange(yy1, yy2);
    ui->customPlot->replot();
}

void MainWindow::on_doubleSpinBox_valueChanged()
{
    x1=ui->doubleSpinBox->value();
}

void MainWindow::on_doubleSpinBox_2_valueChanged()
{
    x2=ui->doubleSpinBox_2->value();
}

void MainWindow::on_doubleSpinBox_3_valueChanged()
{
    yy1=ui->doubleSpinBox_3->value();
}

void MainWindow::on_doubleSpinBox_4_valueChanged()
{
    yy2=ui->doubleSpinBox_4->value();
}

//****************************************************************
//cross-correlation
//****************************************************************
void MainWindow::on_pushButton_4_clicked()
{
    measn=ui->doubleSpinBox_13->value();
    tempn=ui->doubleSpinBox_14->value();
    tempn2=ui->doubleSpinBox_16->value();
    ui->progressBar->setValue(0);

    //read rebined template A
    QString input2=ui->lineEdit_10->text();
    string data2 = input2.toUtf8().constData();
    std::ostringstream dat2NameStream(data2);
    dat2NameStream<<path<<"/"<<data2;
    std::string dat2Name = dat2NameStream.str();
    ifstream dat2(dat2Name.c_str());

    QFile checkfile2(dat2Name.c_str());

    if(!checkfile2.exists()){
        qDebug()<<"Error 19: The file "<<checkfile2.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "Error 19: File for rebined template A does not exist!");
       return;
    }

    for (int i=0; i<logbin; i++){
        dat2 >> eins >>zwei;
        istringstream istr3(eins);
        istr3 >> retw1[i];
        istringstream istr4(zwei);
        istr4 >> reti1[i];
    }
    dat2.close();

    //read rebined template B
    QString input3=ui->lineEdit_11->text();
    string data3 = input3.toUtf8().constData();
    std::ostringstream dat3NameStream(data3);
    dat3NameStream<<path<<"/"<<data3;
    std::string dat3Name = dat3NameStream.str();
    ifstream dat3(dat3Name.c_str());

    QFile checkfile3(dat3Name.c_str());

    if(!checkfile3.exists()){
        qDebug()<<"Error 20: The file "<<checkfile3.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "Error 20: File for rebined template B does not exist!");
       return;
    }

    for (int i=0; i<logbin; i++){
        dat3 >> eins >>zwei;
        istringstream istr5(eins);
        istr5 >> retw2[i];
        istringstream istr6(zwei);
        istr6 >> reti2[i];
    }
    dat3.close();
    int min, max;

    if(ui->checkBox_8->isChecked()){
        min=ui->spinBox_6->value();
        max=ui->spinBox_6->value();
    }
    else{
        min=ui->spinBox_6->value();
        max=ui->spinBox_7->value();
    }
    num=max-min;

    for(int g=min; g<=max; g++){

        qApp->processEvents(QEventLoop::AllEvents);
        ui->customPlot_2->clearGraphs();

        if(stopcor==1){
            stopcor=0;
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }
        else{
            //
        }

        //read rebined spectra
        QString input=ui->lineEdit_7->text();
        string data1 = input.toUtf8().constData();
        std::ostringstream dat1NameStream(data1);
        dat1NameStream<<path<<"/"<<data1<<g<<".txt";
        std::string dat1Name = dat1NameStream.str();

        QFile checkfile1(dat1Name.c_str());

        if(!checkfile1.exists()){
            qDebug()<<"Error 21: The file "<<checkfile1.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "Error 21: File for rebined spectra does not exist!");
           return;
        }
        ifstream dat1(dat1Name.c_str());

        logbin=0;
        while(std::getline(dat1, line))
           ++logbin;

        dat1.clear();
        dat1.seekg(0, ios::beg);

        temp.resize(logbin);
        resamw.resize(logbin);
        resami.resize(logbin);
        retw1.resize(logbin);
        retw2.resize(logbin);
        reti1.resize(logbin);
        reti2.resize(logbin);

        for (int i=0; i<logbin; i++){
            dat1 >> eins >>zwei;
            istringstream istr(eins);
            istr >> resamw[i];
            istringstream istr2(zwei);
            istr2 >> resami[i];
            resami[i]=resami[i]-measn;
        }
        dat1.close();
/*
        //read rebined template A
        QString input2=ui->lineEdit_10->text();
        string data2 = input2.toUtf8().constData();
        std::ostringstream dat2NameStream(data2);
        dat2NameStream<<path<<"/"<<data2<<g<<".txt";
        std::string dat2Name = dat2NameStream.str();
        ifstream dat2(dat2Name.c_str());

        QFile checkfile2(dat2Name.c_str());

        if(!checkfile2.exists()){
            qDebug()<<"The file "<<checkfile2.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File for rebined template A does not exist!");
           return;
        }

        for (int i=0; i<logbin; i++){
        dat2 >> eins >>zwei;
        istringstream istr3(eins);
        istr3 >> retw1[i];
        istringstream istr4(zwei);
        istr4 >> reti1[i];
        }
        dat2.close();

        //read rebined template B
        QString input3=ui->lineEdit_11->text();
        string data3 = input3.toUtf8().constData();
        std::ostringstream dat3NameStream(data3);
        dat3NameStream<<path<<"/"<<data3<<g<<".txt";
        std::string dat3Name = dat3NameStream.str();
        ifstream dat3(dat3Name.c_str());

        QFile checkfile3(dat3Name.c_str());

        if(!checkfile3.exists()){
            qDebug()<<"The file "<<checkfile3.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File for rebined template B does not exist!");
           return;
        }

        for (int i=0; i<logbin; i++){
        dat3 >> eins >>zwei;
        istringstream istr5(eins);
        istr5 >> retw2[i];
        istringstream istr6(zwei);
        istr6 >> reti2[i];
        }
        dat3.close();

        //read spectra non-rebined
        QString input4=ui->lineEdit->text();
        string data4 = input4.toUtf8().constData();
        std::ostringstream dat4NameStream(data4);
        dat4NameStream<<path<<"/"<<data4<<g<<".txt";
        std::string dat4Name = dat4NameStream.str();
        ifstream dat4(dat4Name.c_str());

        QFile checkfile4(dat4Name.c_str());

        if(!checkfile4.exists()){
            qDebug()<<"The file "<<checkfile4.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File for spectra does not exist!");
           return;
        }

        //QMessageBox::information(this, "", "All files found :) Press OK to start cross-correlation.");

        bini=0;

        while(std::getline(dat4, line))
           ++ bini;

        dat4.clear();
        dat4.seekg(0, ios::beg);

        measw.resize(bini);
        measi.resize(bini);

        for (int i=0; i<bini; i++){
        dat4 >> eins >>zwei;
        istringstream istr7(eins);
        istr7 >> measw[i];
        measw[i]=log10(measw[i]);
        istringstream istr8(zwei);
        istr8 >> measi[i];
        }
        dat4.close();

        //looking for lowest delta_log(lambda)
        diff = measw[1]-measw[0];
        for (int i=0; i+1<bini; i++){
        if ((measw[i+1]-measw[i])<diff){
        diff = (measw[i+1]-measw[i]);
        }
        }
        diff=diff*increment;*/

        this->setCursor(QCursor(Qt::WaitCursor));

    dv=(pow(10,(resamw[5]-resamw[4]))-1)*c0;
    dosteps=doshift/dv;
    vsteps=vshift/dv;

    /*
    // summing up doppler separated templates and write to file
    for(int m=0;m<2*dosteps; m++){

        std::ostringstream file7NameStream("/temps_");
        file7NameStream<<path<<"/temps_"<<g<<"_"<<m<<".txt";
        std::string file7Name = file7NameStream.str();
        ofstream file7(file7Name.c_str());
        don=dosteps-m;
        for (int i=0; i<logbin; i++){
        if((i+don<=logbin) & (i+don>=0)){
        temp[i]=reti1[i]+reti2[i+don];
        }
        else{
        temp[i]=0;
        }
        file7<<std::setprecision(8)<<resamw[i]<<" "<<temp[i]<<"\n";
        }

        }*/

    QString Vsize=QString::number(dv);
    ui->lineEdit_16->setText(Vsize);

    double ccf[2*vsteps][2*dosteps];

    for (int n=0; n<2*vsteps; n++){
            for(int m=0; m<2*dosteps; m++){
                ccf[n][m]=0.0;
            }
         }

    for (int n=0; n<2*vsteps; n++){
        //cout<<(vsteps-n)*dv<<endl;

        for(int m=0; m<2*dosteps; m++){

        don=dosteps-m;

            for (int i=0; i<logbin; i++){
                if((i+don<logbin) &(i+don>0)){
                    temp[i]=reti1[i]+reti2[i+don];
                }
                else{
                    temp[i]=0;
                }
            }

            meant=0;
            means=0;
            for(int i=0; i<logbin; i++){
                meant+=temp[i]/logbin;
                means+=resami[i]/logbin;
            }

            sigmas=0;
            sigmat=0;
            for(int i=0; i<logbin; i++){
                sigmat+=pow((temp[i]-meant),2);
                sigmas+=pow((resami[i]-means),2);
            }
            sigmat=sqrt(sigmat/(logbin-1));
            sigmas=sqrt(sigmas/(logbin-1));

            // correlation
            dn=vsteps-n;
            for(int i=0; i<logbin; i++){
                if((i+dn<logbin) &(i+dn>0)){
                    ccf[n][m]+=(resami[i]-means)*(temp[i+dn]-meant)/logbin/sigmat/sigmas;
                }
                else{
                    ccf[n][m]+=0.0;
                }
            }
            if(ccf[n][m]<1){
                if(ccf[n][m]>0){
                    //file4<<(dosteps-m)*dv<<" "<<(vsteps-n)*dv<<" "<<ccf[n][m]<<"\n";
                }
            }
        }
    }

    if(ui->checkBox_12->isChecked()){
        for(int m=0; m<2*dosteps; m++){
            std::ostringstream file5NameStream("ccf_");
            file5NameStream<<path<<"/ccf_"<<g<<"_"<<m<<".txt";
            std::string file5Name = file5NameStream.str();
            ofstream file5(file5Name.c_str());

            for(int n=0; n<2*vsteps; n++){
                if((ccf[n][m]<1) &(ccf[n][m]>0)){
                    file5<<(-1)*(vsteps - n)*dv<<" "<<ccf[n][m]<<endl;
                }
            }
            file5.close();
        }
    }

    ccfmax=0;
    for(int m=0; m<2*dosteps; m++){
       for(int n=0; n<2*vsteps; n++){
           if((ccf[n][m]>ccfmax) &(ccf[n][m]<1)){
               ccfmax=ccf[n][m];
               shift = (vsteps - n)*dv;
               sepa=(dosteps-m)*dv;
               b=n;
               d=m;
           }
        }
    }


    std::ostringstream file6NameStream("ccfmax_");
    file6NameStream<<path<<"/ccfmax_"<<g<<".txt";
    std::string file6Name = file6NameStream.str();
    ofstream file6(file6Name.c_str());
    QVector<double> ccfx(2*vsteps), ccfy(2*vsteps);

    for(int i=0; i<2*vsteps; i++){
        file6<<(-1)*(vsteps - i)*dv<<" "<<ccf[i][d]<<endl;
        ccfx[i]=(-1)*(vsteps - i)*dv;
        ccfy[i]=ccf[i][d];
    }

    ui->customPlot_2->addGraph();
    ui->customPlot_2->graph()->addData(ccfx, ccfy);
    ui->customPlot_2->rescaleAxes();
    ui->customPlot_2->replot();

    QString hift= QString::number(shift);
    ui->lineEdit_12->setText(hift);

    QString epa= QString::number(sepa);
    ui->lineEdit_13->setText(epa);

    ui->spinBox_5->setValue(2*dosteps-1);

    counter=g+1;
    QString process= QString::number(counter);
    ui->lineEdit_9->setText(process);

    QString rv1=ui->lineEdit_8->text();
    string rv = rv1.toUtf8().constData();
    std::ostringstream rvNameStream(rv);
    rvNameStream<<path<<"/"<<rv<<g<<".txt";
    std::string rvName = rvNameStream.str();
    ofstream rvfile(rvName.c_str());

    rvfile<<-shift<<" "<<(-1)*sepa-shift<<endl;
    cout<<-shift<<" "<<(-1)*sepa-shift<<endl;

    ui->progressBar->setValue(100*(g+1)/num);
    qApp->processEvents(QEventLoop::AllEvents);

    this->setCursor(QCursor(Qt::ArrowCursor));

}
    ui->progressBar->setValue(100);
}

//****************************************************************
//set value file 1
//****************************************************************
void MainWindow::on_pushButton_5_clicked()
{


    QString plot1=ui->lineEdit_4->text();
    string plot11 = plot1.toUtf8().constData();
    std::ostringstream dat1NameStream(plot11);
    dat1NameStream<<path<<"/"<<plot11;
    std::string dat1Name = dat1NameStream.str();
    ifstream toplot1(dat1Name.c_str());

    QFile checkfile(dat1Name.c_str());

    if(!checkfile.exists()){
        qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error 22", "Error 22: File 1 does not exist!");
       return;
    }


    int number_of_lines=0;

    while(std::getline(toplot1, line))
       ++ number_of_lines;

    toplot1.clear();
    toplot1.seekg(0, ios::beg);

    QVector<double> a(number_of_lines), b(number_of_lines);

    for (int i=0; i<number_of_lines; i++){
    toplot1 >> eins >>zwei;
    istringstream ist(eins);
    ist >> a[i];
    istringstream ist2(zwei);
    ist2 >> b[i];
    }
    toplot1.close();

    x1=a[0];
    x2=a[number_of_lines-1];
    for(int i=0; i<number_of_lines; i++){
        if(a[i]<x1){
            x1=a[i];
        }
    }

    for(int i=0; i<number_of_lines; i++){
        if(a[i]>x2){
            x2=a[i];
        }
    }
    if(ui->checkBox->isChecked()){
        x1=log10(x1);
        x2=log10(x2);
    }
    ui->doubleSpinBox->setValue(x1);
    ui->doubleSpinBox_2->setValue(x2);

    yy1=b[0];
    yy2=b[number_of_lines-1];
    for(int i=0; i<number_of_lines; i++){
        if(b[i]<yy1){
            yy1=b[i];
        }
    }
    for(int i=0; i<number_of_lines; i++){
        if(b[i]>yy2){
            yy2=b[i];
        }
    }
    if(ui->checkBox_5->isChecked()){
        double yadd1=ui->doubleSpinBox_9->value();
        yy1=yy1+yadd1;
        yy2=yy2+yadd1;
    }

    ui->doubleSpinBox_3->setValue(yy1);
    ui->doubleSpinBox_4->setValue(yy2);
}

//****************************************************************
//set value file 2
//****************************************************************
void MainWindow::on_pushButton_6_clicked()
{

    QString plot1=ui->lineEdit_5->text();
    string plot11 = plot1.toUtf8().constData();
    std::ostringstream dat1NameStream(plot11);
    dat1NameStream<<path<<"/"<<plot11;
    std::string dat1Name = dat1NameStream.str();
    ifstream toplot1(dat1Name.c_str());

    QFile checkfile(dat1Name.c_str());

    if(!checkfile.exists()){
        qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error 23", "Error 23: File 2 does not exist!");
       return;
    }

    int number_of_lines =0;

    while(std::getline(toplot1, line))
       ++ number_of_lines;

    toplot1.clear();
    toplot1.seekg(0, ios::beg);

    QVector<double> a(number_of_lines), b(number_of_lines);

    for (int i=0; i<number_of_lines; i++){
    toplot1 >> eins >>zwei;
    istringstream ist(eins);
    ist >> a[i];
    istringstream ist2(zwei);
    ist2 >> b[i];
    }
    toplot1.close();

    x1=a[0];
    x2=a[number_of_lines-1];
    for(int i=0; i<number_of_lines; i++){
        if(a[i]<x1){
            x1=a[i];
        }
    }
    for(int i=0; i<number_of_lines; i++){
        if(a[i]>x2){
            x2=a[i];
        }
    }
    if(ui->checkBox_2->isChecked()){
        x1=log10(x1);
        x2=log10(x2);
    }
    ui->doubleSpinBox->setValue(x1);
    ui->doubleSpinBox_2->setValue(x2);
    yy1=b[0];
    yy2=b[number_of_lines-1];
    for(int i=0; i<number_of_lines; i++){
        if(b[i]<yy1){
            yy1=b[i];
        }
    }
    for(int i=0; i<number_of_lines; i++){
        if(b[i]>yy2){
            yy2=b[i];
        }
    }
    if(ui->checkBox_6->isChecked()){
        double yadd2=ui->doubleSpinBox_10->value();
        yy1=yy1+yadd2;
        yy2=yy2+yadd2;
    }

    ui->doubleSpinBox_3->setValue(yy1);
    ui->doubleSpinBox_4->setValue(yy2);
}

//****************************************************************
//set value file 3
//****************************************************************
void MainWindow::on_pushButton_7_clicked()
{
    QString plot1=ui->lineEdit_6->text();
    string plot11 = plot1.toUtf8().constData();
    std::ostringstream dat1NameStream(plot11);
    dat1NameStream<<path<<"/"<<plot11;
    std::string dat1Name = dat1NameStream.str();
    ifstream toplot1(dat1Name.c_str());

    QFile checkfile(dat1Name.c_str());

    if(!checkfile.exists()){
        qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error 24", "Error 24: File 3 does not exist!");
       return;
    }

    int number_of_lines =0;


    while(std::getline(toplot1, line))
       ++ number_of_lines;

    toplot1.clear();
    toplot1.seekg(0, ios::beg);

    QVector<double> a(number_of_lines), b(number_of_lines);

    for (int i=0; i<number_of_lines; i++){
    toplot1 >> eins >>zwei;
    istringstream ist(eins);
    ist >> a[i];
    istringstream ist2(zwei);
    ist2 >> b[i];
    }
    toplot1.close();

    x1=a[0];
    x2=a[number_of_lines-1];
    for(int i=0; i<number_of_lines; i++){
        if(a[i]<x1){
            x1=a[i];
        }
    }
    for(int i=0; i<number_of_lines; i++){
        if(a[i]>x2){
            x2=a[i];
        }
    }
    if(ui->checkBox_3->isChecked()){
        x1=log10(x1);
        x2=log10(x2);
    }
    ui->doubleSpinBox->setValue(x1);
    ui->doubleSpinBox_2->setValue(x2);
    yy1=b[0];
    yy2=b[number_of_lines-1];
    for(int i=0; i<number_of_lines; i++){
        if(b[i]<yy1){
            yy1=b[i];
        }
    }
    for(int i=0; i<number_of_lines; i++){
        if(b[i]>yy2){
            yy2=b[i];
        }
    }
    if(ui->checkBox_7->isChecked()){
        double yadd3=ui->doubleSpinBox_11->value();
        yy1=yy1+yadd3;
        yy2=yy2+yadd3;
    }

    ui->doubleSpinBox_3->setValue(yy1);
    ui->doubleSpinBox_4->setValue(yy2);
}

void MainWindow::on_doubleSpinBox_5_valueChanged()
{
    xc1=ui->doubleSpinBox_5->value();
}

void MainWindow::on_doubleSpinBox_6_valueChanged()
{
    xc2=ui->doubleSpinBox_6->value();
}

void MainWindow::on_doubleSpinBox_7_valueChanged()
{
    yc1=ui->doubleSpinBox_7->value();
}

void MainWindow::on_doubleSpinBox_8_valueChanged()
{
    yc2=ui->doubleSpinBox_8->value();
}

//****************************************************************
//plot cc's
//****************************************************************
void MainWindow::on_pushButton_8_clicked()
{
    ui->customPlot_2->clearGraphs();

    int min=ui->spinBox_4->value();
    int max=ui->spinBox_5->value();

    for (int u=min; u<=max; u++){

        QString input=ui->lineEdit_14->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<path<<"/"<<data<<u<<".txt";
        std::string datName = datNameStream.str();
        ifstream dat(datName.c_str());

        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QString fError= QString::number(u);
            QMessageBox::information(this, "Error 25", "Error 25: File "+qpath+"/"+input+fError+".txt does not exist!");
           return;
            }

        int number_of_lines =0;

        while(std::getline(dat, line))
           ++ number_of_lines;

        dat.clear();
        dat.seekg(0, ios::beg);

        QVector<double> a(number_of_lines), b(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        dat >> eins >>zwei;
        istringstream ist(eins);
        ist >> a[i];
        istringstream ist2(zwei);
        ist2 >> b[i];
        b[i]=b[i]+oset*(u-min);
        }
        dat.close();

        ui->customPlot_2->addGraph();
        ui->customPlot_2->graph()->setData(a, b);
    }

    ui->customPlot_2->xAxis->setLabel("Velocity shift");
    ui->customPlot_2->yAxis->setLabel("CCF Value");
    ui->customPlot_2->xAxis->setRange(xc1, xc2);
    ui->customPlot_2->yAxis->setRange(yc1, yc2);
    ui->customPlot_2->replot();

}
//****************************************************************
//set values for cc-sums
//****************************************************************
void MainWindow::on_pushButton_9_clicked()
{
    int min=ui->spinBox_4->value();
    int max=ui->spinBox_5->value();

    for (int u=min; u<=max; u++){


    QString input=ui->lineEdit_14->text();
    string data = input.toUtf8().constData();
    std::ostringstream datNameStream(data);
    datNameStream<<path<<"/"<<data<<u<<".txt";
    std::string datName = datNameStream.str();
    ifstream dat(datName.c_str());


    QFile checkfile(datName.c_str());

    if(!checkfile.exists()){
        qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
        QString fError= QString::number(u);
        QMessageBox::information(this, "Error 26", "Error 26: File "+qpath+"/"+input+fError+".txt does not exist!");
       return;
        }

    int number_of_lines =0;


    while(std::getline(dat, line))
       ++ number_of_lines;

    dat.clear();
    dat.seekg(0, ios::beg);

    QVector<double> a(number_of_lines), b(number_of_lines);

    for (int i=0; i<number_of_lines; i++){
    dat >> eins >>zwei;
    istringstream ist(eins);
    ist >> a[i];
    istringstream ist2(zwei);
    ist2 >> b[i];
    b[i]=b[i]+oset*(u-min);
    }
    dat.close();
    if(u==min){
    xc1=a[0];
    xc2=a[number_of_lines-1];
    }

    for(int i=0; i<number_of_lines; i++){
        if(a[i]<xc1){
            xc1=a[i];
        }
    }
    for(int i=0; i<number_of_lines; i++){
        if(a[i]>xc2){
            xc2=a[i];
        }
    }
    ui->doubleSpinBox_5->setValue(xc1);
     ui->doubleSpinBox_6->setValue(xc2);

     if(u==min){
     yc1=b[0];
     yc2=b[number_of_lines-1];
     }
    for(int i=0; i<number_of_lines; i++){
        if(b[i]<yc1){
            yc1=b[i];
        }
    }
    for(int i=0; i<number_of_lines; i++){
        if(b[i]>yc2){
            yc2=b[i];
        }
    }

     ui->doubleSpinBox_7->setValue(yc1);
     ui->doubleSpinBox_8->setValue(yc2);
}
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, "About", "This open-source software was developed at Leibniz-Institute for Astrophysics Potsdam, Germany\n\n"
                                            "by D. P. Sablowski\n\n"
                                            "Licenced under the Apache 2.0 licence. The program is provided AS IS with NO WARRANTY OF ANY KIND.");
}

void MainWindow::on_actionBug_Report_triggered()
{
    QMessageBox::information(this, "Bug Report", "Please contact: dsablowski@aip.de");
}


void MainWindow::on_actionPlot_triggered()
{

    pSpec =new PlotSpec(this);
    pSpec->seData(ui->lineEdit_15->text(), ui->lineEdit->text(), ui->lineEdit_18->text(), ui->lineEdit_19->text(), ui->lineEdit_20->text());
    pSpec->show();
}

void MainWindow::on_actionSequence_Plotter_triggered()
{
    pSequ = new PlotSequ(this);
    pSequ->seData(ui->lineEdit_15->text(), ui->lineEdit->text(), ui->lineEdit_18->text(), ui->lineEdit_19->text(), ui->lineEdit_20->text());
    pSequ->show();
}

//****************************************************************
//save file as
//****************************************************************
void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(
                this,
                "CC - Save as",
                "/home",
                "text files (*.txt)::All files(*.*)");

    if(fileName.isEmpty()){
         curFile=fileName;
        saveFile();
    }
}

void MainWindow::saveFile()
{
    QFile file(curFile);
    if(file.open(QFile::WriteOnly)){
        file.write(ui->plainTextEdit->toPlainText().toUtf8());
    }
    else{
        QMessageBox::warning(this, "CC", tr("cannot write to file %1.\nError: %2").arg(curFile).arg(file.errorString()));
    }
}

void MainWindow::on_lineEdit_15_textEdited()
{
    qpath=ui->lineEdit_15->text();
    path = qpath.toUtf8().constData();
}

void MainWindow::on_actionRV_Curve_triggered()
{
    qCurve = new RvCurve(this);
    qCurve->show();
}


void MainWindow::on_checkBox_8_pressed()
{
    if(ui->checkBox_8->isChecked()){
    ui->spinBox_7->setEnabled(true);
    }
    else{
        ui->spinBox_7->setEnabled(false);
    }
}


void MainWindow::on_doubleSpinBox_12_valueChanged()
{
    increment=ui->doubleSpinBox_12->value();
}

void MainWindow::on_doubleSpinBox_13_valueChanged()
{
    measn=ui->doubleSpinBox_13->value();
}

void MainWindow::on_doubleSpinBox_14_valueChanged()
{
    tempn=ui->doubleSpinBox_14->value();
}

void MainWindow::on_actionTemplate_Generator_triggered()
{
    qTemplate = new Template(this);
    qTemplate->seData(ui->lineEdit_15->text());
    qTemplate->show();
}

void MainWindow::on_doubleSpinBox_15_valueChanged()
{
    oset=ui->doubleSpinBox_15->value();
}

void MainWindow::on_pushButton_10_clicked()
{
    QString ffits=qpath+"/"+ui->lineEdit_17->text();
    QByteArray qfits=ffits.toLatin1();
    char *c_qfits=qfits.data();

    char *testf[]={"",c_qfits};
    int exten=2;
    MainWindow::ReadHeader(exten, testf);
}

void MainWindow::on_lineEdit_18_textChanged()
{
    qExtension=ui->lineEdit_18->text();
    Extension = qExtension.toUtf8().constData();
}

void MainWindow::on_lineEdit_19_textChanged()
{
    qWavecol=ui->lineEdit_19->text();
    Wavecol = qWavecol.toUtf8().constData();
}

void MainWindow::on_lineEdit_20_textChanged()
{
    qIntenscol=ui->lineEdit_20->text();
    Intenscol = qIntenscol.toUtf8().constData();
}

void MainWindow::on_actionBinary_Tool_triggered()
{
    qBinary = new BinaryTool(this);
    qBinary->seData(ui->lineEdit_15->text());
    qBinary->show();
}

void MainWindow::on_checkBox_10_clicked()
{
    ui->checkBox_11->setChecked(false);
}

void MainWindow::on_checkBox_11_clicked()
{
    ui->checkBox_10->setChecked(false);
}

void MainWindow::on_actionTelluric_triggered()
{
    qTell = new Telluric(this);
    qTell->seData(ui->lineEdit_15->text(), ui->lineEdit->text(), ui->lineEdit_21->text());
    qTell->show();
}

void MainWindow::on_action2D_Map_Plot_triggered()
{
    qMPlot = new MapPlot(this);
    qMPlot->seData(ui->lineEdit_15->text());
    qMPlot->show();
}

void MainWindow::on_actionRV_Calculator_triggered()
{
    qRVCalc = new RVCalc(this);
    qRVCalc->seData(ui->lineEdit_15->text(), ui->lineEdit_21->text());
    qRVCalc->show();
}

void MainWindow::on_actionRaname_Files_triggered()
{
    qRename = new Rename(this);
    qRename->seData(ui->lineEdit_15->text(), ui->lineEdit->text(), ui->lineEdit_18->text(), ui->lineEdit_19->text(), ui->lineEdit_20->text());
    qRename->show();
}

void MainWindow::on_comboBox_currentIndexChanged()
{
    if(ui->comboBox->currentIndex()==0){
        ui->lineEdit_20->setEnabled(true);
        ui->lineEdit_19->setEnabled(true);
        ui->lineEdit_18->setEnabled(true);
        ui->lineEdit_21->setText(".fits");
        infilei=0;
    }

    else {
        ui->lineEdit_20->setEnabled(false);
        ui->lineEdit_19->setEnabled(false);
        ui->lineEdit_18->setEnabled(false);
        ui->lineEdit_21->setText(".txt");
        infilei=1;
    }
}

void MainWindow::on_actionCPD_triggered()
{
    qCPD = new CPD(this);
    qCPD->seData(ui->lineEdit_15->text(), ui->lineEdit->text(), ui->lineEdit_21->text());
    qCPD->show();
}

void MainWindow::on_actionArithmetic_triggered()
{
    qArith = new Arithmetic(this);
    qArith->seData(ui->lineEdit_15->text(), ui->lineEdit->text(), ui->lineEdit_21->text());
    qArith->show();
}

void MainWindow::on_actionCrop_triggered()
{
    qCrop = new Crop(this);
    qCrop->seData(ui->lineEdit_15->text(), ui->lineEdit->text(), ui->lineEdit_18->text(), ui->lineEdit_19->text(), ui->lineEdit_20->text());
    qCrop->show();
}

void MainWindow::on_actionSpline_Fit_triggered()
{
    qSpline = new SplineFit(this);
    qSpline->seData(ui->lineEdit_15->text());
    qSpline->show();
}

//*****************************************
// Craete Sequence
//*****************************************
void MainWindow::on_pushButton_11_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));

    int maxbin = ui->spinBox_9->value();
    double minwave, maxwave;

    if(maxbin == 0){
        QMessageBox::information(this, "Error", "Please give max number of bins.");
        return;
    }

    int maxnu =0;
    QString sequ;

    num=ui->spinBox_8->value() - ui->spinBox->value()+1;

    if(ui->checkBox_4->isChecked()){
        num = 1;
    }

    for (int g=0; g<num; g++){

        int gg = g+ui->spinBox->value();

        if(ui->checkBox_4->isChecked()){
            g=ui->spinBox->value();
            gg=g;
        }


    //read measuremens
    MainWindow::ReadMeasured(gg);
    //cout<<"read spectrum no. "<<gg<<endl;

    if(check==1){
        check=0;
        return;
    }
    else{
        //
    }

    if(g==0){
        minwave = measw[0];
        maxwave = measw[bini-1];
    }
    else{
        if(measw[0]>minwave){
            minwave = measw[0];
        }
        if(measw[bini-1]<maxwave){
            maxwave = measw[bini-1];
        }
    }

    }
    cout<<"minwave: "<<minwave<<"; maxwave: "<<maxwave<<endl;

    for (int g=0; g<num; g++){

        int gg = g+ui->spinBox->value();

        if(ui->checkBox_4->isChecked()){
            g=ui->spinBox->value();
            gg=g;
        }


        //read measuremens
        MainWindow::ReadMeasured(gg);
        //cout<<"read spectrum no. "<<gg<<endl;

        if(check==1){
            check=0;
            return;
        }
        else{
            //
        }

        QString output11="crspec_";
        string output1 = output11.toUtf8().constData();
        std::ostringstream output1NameStream(output1);
        output1NameStream<<path<<"/"<<output1<<gg<<".txt";
        std::string output1Name = output1NameStream.str();
        ofstream file2(output1Name.c_str());

        for(int i=0; i<bini; i++){
            if(measw[i]>= minwave & measw[i]<=maxwave){
                file2<<measw[i]<<"\t"<<measi[i]<<endl;
            }
        }

    }

    ui->lineEdit->setText("crspec_");

    ui->comboBox->setCurrentIndex(1);
    ui->lineEdit_21->setText(".txt");

    QVector<double> lowave(1), upwave(1);

    for (int g=0; g<num; g++){

        int gg = g+ui->spinBox->value();

        if(ui->checkBox_4->isChecked()){
            g=ui->spinBox->value();
            gg=g;
        }


    //read measuremens
    MainWindow::ReadMeasured(gg);
    //cout<<"read spectrum no. "<<gg<<endl;

    if(check==1){
        check=0;
        return;
    }
    else{
        //
    }

    if(g==0){

        maxnu = bini/maxbin;
        lowave.resize(maxnu);
        upwave.resize(maxnu);

        for(int s=0; s<maxnu; s++){
            lowave[s]=measw[s*maxbin];
            upwave[s]=measw[(s+1)*(maxbin-1)];
            cout<<lowave[s]<<" "<<upwave[s]<<endl;
        }
    }

     cout<<"Number of sequences: "<<maxnu<<endl;

    for (int s=0; s<maxnu; s++){

        QString output11="sequence_";
        string output1 = output11.toUtf8().constData();
        std::ostringstream output1NameStream(output1);
        output1NameStream<<path<<"/"<<output1<<s<<"_"<<gg<<".txt";
        std::string output1Name = output1NameStream.str();
        ofstream file1(output1Name.c_str());

        for(int i =0; i<measw.size(); i++){

            if((measw[i]>=lowave[s]) & (measw[i]<=upwave[s])){
                file1<<measw[i]<<"\t"<<measi[i]<<endl;
            }

        }

    }

    }

    if(ui->checkBox_13->isChecked()){

        ui->checkBox_10->setChecked(true);
        ui->checkBox_11->setChecked(false);
        QString seqm = ui->lineEdit_7->text();

        for(int s=0; s<maxnu; s++){

            sequ = QString::number(s);

            ui->lineEdit->setText("sequence_"+sequ+"_");
            ui->lineEdit_7->setText(seqm+sequ+"_");

            MainWindow::on_pushButton_clicked();

        }
    }

    this->setCursor(QCursor(Qt::ArrowCursor));


}


void MainWindow::on_pushButton_12_clicked()
{
    QString kword = ui->lineEdit_22->text();

    QString output12=ui->lineEdit_23->text();
    string output2 = output12.toUtf8().constData();
    std::ostringstream output2NameStream(output2);
    output2NameStream<<path<<"/"<<output2;
    std::string output2Name = output2NameStream.str();
    ofstream file2(output2Name.c_str());

    QString fext = ui->lineEdit_21->text();

    for(int i = ui->spinBox->value(); i<=ui->spinBox_8->value(); i++){

        QString s = QString::number(i);
    QString output11=qpath+"/"+ui->lineEdit->text()+s+fext;
    QByteArray qfits = output11.toLatin1();
    char *c_qfits=qfits.data();

    char *testf[]={"",c_qfits};
    int argc=3;
    cout<<c_qfits<<"\t"<<testf<<endl;


    fitsfile *fptr;         /* FITS file pointer, defined in fitsio.h */
    char card[FLEN_CARD], newcard[FLEN_CARD];
    char oldvalue[FLEN_VALUE], comment[FLEN_COMMENT];
    int status = 0;   /*  CFITSIO status value MUST be initialized to zero!  */
    int iomode=READONLY, keytype;

    if (!fits_open_file(&fptr, testf[1], iomode, &status))
    {
      if (fits_read_card(fptr,testf[2], card, &status))
      {
        printf("Keyword does not exist\n");
        card[0] = '\0';
        comment[0] = '\0';
        status = 0;  /* reset status after error */
      }
      else
        printf("%s\n",card);

      if (argc == 4)  /* write or overwrite the keyword */
      {
          /* check if this is a protected keyword that must not be changed */
          if (*card && fits_get_keyclass(card) == TYP_STRUC_KEY)
          {
            printf("Protected keyword cannot be modified.\n");
          }
          else
          {
            /* get the comment string */
            if (*card)fits_parse_value(card, oldvalue, comment, &status);

            /* construct template for new keyword */
            strcpy(newcard, testf[2]);     /* copy keyword name */
            strcat(newcard, " = ");       /* '=' value delimiter */
            strcat(newcard, testf[3]);     /* new value */
            if (*comment) {
              strcat(newcard, " / ");  /* comment delimiter */
              strcat(newcard, comment);     /* append the comment */
            }

            /* reformat the keyword string to conform to FITS rules */
            fits_parse_template(newcard, card, &keytype, &status);

            /* overwrite the keyword with the new value */
            fits_update_card(fptr, testf[2], card, &status);

            printf("Keyword has been changed to:\n");
            printf("%s\n",card);
          }
      }  /* if argc == 4 */
      fits_close_file(fptr, &status);
    }    /* open_file */

    /* if error occured, print out error message */
    if (status) fits_report_error(stderr, status);
    return;

    }
}

void MainWindow::on_actionBlaze_Correction_triggered()
{
    qBCorr = new BlazeCorr(this);
    qBCorr->seData(ui->lineEdit_15->text());
    qBCorr->show();

}


void MainWindow::on_actionMoments_triggered()
{
    qMom = new Moments(this);
    qMom->seData(ui->lineEdit_15->text());
    qMom->show();
}

// stop rebinning
void MainWindow::on_pushButton_13_clicked()
{
    stopreb=1;
}

// stop correlation
void MainWindow::on_pushButton_14_clicked()
{
    stopcor=1;
}


//***********************************************************
// subtract templates using velocities from cross correlattion
//***********************************************************
void MainWindow::on_pushButton_15_clicked()
{
    int min=ui->spinBox_6->value();
    int max=ui->spinBox_7->value();
    int adiff=0;
    double velst=ui->lineEdit_16->text().toDouble(), rv1=0.0, rv2=0.0, tbina=0.0, tbinb=0.0;
    double irv1=0.0, irv2=0.0, xs=0.0;

    double kAB = ui->doubleSpinBox_21->value();
    double fA = kAB/(1+kAB);
    double fB = 1/(1+kAB);

    string  eins, zwei;
    tk::spline sp;
    vector<double> Ys(3), Xs(3);

    if(velst==0){
        QMessageBox::information(this, "Error", "Velocity step size is zero. Did you executed CC first?");
        return;
    }
    this->setCursor(QCursor(Qt::WaitCursor));

    //read rebined template A
    QString temp1=ui->lineEdit_10->text();
    string tempa = temp1.toUtf8().constData();
    std::ostringstream dataNameStream(tempa);
    dataNameStream<<path<<"/"<<tempa;
    std::string dataName = dataNameStream.str();

    QFile checkfilea(dataName.c_str());

    if(!checkfilea.exists()){
        QMessageBox::information(this, "Error", "The template file "+checkfilea.fileName()+" does not exist.");
        qDebug()<<"The file "<<checkfilea.fileName()<<" does not exist.";
        this->setCursor(QCursor(Qt::ArrowCursor));
        return;
    }

    ifstream data(dataName.c_str());

    int numbera =0;

    while(std::getline(data, line))
       ++ numbera;

    data.clear();
    data.seekg(0, ios::beg);

    QVector<double> wta(numbera), ita(numbera);

    for(int i=0; i<numbera; i++){
        data >> eins >> zwei;
        istringstream str(eins);
        str >> wta[i];
        istringstream str2(zwei);
        str2 >> ita[i];
        if(i==1){
            tbina=wta[1]-wta[0];
        }
        else{
            //
        }
    }

    // read rebined template B
    QString temp2=ui->lineEdit_11->text();
    string tempb = temp2.toUtf8().constData();
    std::ostringstream datbNameStream(tempb);
    datbNameStream<<path<<"/"<<tempb;
    std::string datbName = datbNameStream.str();

    QFile checkfileb(datbName.c_str());

    if(!checkfileb.exists()){
        QMessageBox::information(this, "Error", "The template file "+checkfileb.fileName()+" does not exist.");
        qDebug()<<"The file "<<checkfileb.fileName()<<" does not exist.";
        this->setCursor(QCursor(Qt::ArrowCursor));
        return;
    }

    ifstream datb(datbName.c_str());

    int numberb =0;

    while(std::getline(datb, line))
       ++ numberb;

    datb.clear();
    datb.seekg(0, ios::beg);

    if(numberb!=numbera){
        QMessageBox::information(this, "Warning", "Templates have different length.");
    }
    else{
        //
    }

    QVector<double> wtb(numberb), itb(numberb);

    for(int i=0; i<numberb; i++){
        datb >> eins >> zwei;
        istringstream str(eins);
        str >> wtb[i];
        istringstream str2(zwei);
        str2 >> itb[i];
        if(i==1){
            tbinb=wtb[1]-wtb[0];
        }
        else{
            //
        }
    }
    if(tbina!=tbinb){
        QMessageBox::information(this, "Warning", "Templates have different binning.");
    }
    else{
        //
    }
    QVector<double> wt(1), it(1);
    int tbin=0;
    data.close();
    datb.close();

    if(ui->checkBox_17->isChecked()){
        wt.resize(numbera);
        it.resize(numbera);
        tbin=numbera;
    }
    else{
        wt.resize(numberb);
        it.resize(numberb);
        tbin=numberb;
    }

    QVector<double> sysshift(1);

    // read file with shifts for subtraction
    if(ui->checkBox_25->isChecked()){
        QString inputs=ui->lineEdit_27->text();
        string datas = inputs.toUtf8().constData();
        std::ostringstream datsNameStream(datas);
        datsNameStream<<path<<"/"<<datas;
        std::string datsName = datsNameStream.str();

        QFile checkfiles(datsName.c_str());

        if(!checkfiles.exists()){
            QMessageBox::information(this, "Error", "The file "+checkfiles.fileName()+" does not exist.");
            qDebug()<<"The file "<<checkfiles.fileName()<<" does not exist.";
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }

        ifstream dats(datsName.c_str());

        int nshift =0;

        while(std::getline(dats, line))
           ++ nshift;

        dats.clear();
        dats.seekg(0, ios::beg);

        if(nshift!=(max-min+1)){
            QMessageBox::information(this, "Error", "Number of entries in file "+checkfiles.fileName()+"does not equal number of spectra.");
            return;
        }

        sysshift.resize(nshift);

        for(int g=0; g<nshift; g++){
            dats >> eins;
            istringstream str(eins);
            str >> sysshift[g];

        }
        dats.close();

    }
    else{
        //single file
        if(ui->checkBox_26->isChecked()){
            sysshift[0]=ui->doubleSpinBox_20->value();
        }
        else{
            //
        }
    }
    int count=0;

    for(int i =min; i<=max; i++){

        QString input=ui->lineEdit_8->text();
        string data1 = input.toUtf8().constData();
        std::ostringstream dat1NameStream(data1);
        dat1NameStream<<path<<"/"<<data1<<i<<".txt";
        std::string dat1Name = dat1NameStream.str();

        QFile checkfile1(dat1Name.c_str());

        if(!checkfile1.exists()){
            QMessageBox::information(this, "Error", "The file "+checkfile1.fileName()+" does not exist.");
            qDebug()<<"The file "<<checkfile1.fileName()<<" does not exist.";
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }

        ifstream dat1(dat1Name.c_str());

        dat1 >> eins >>zwei;
        istringstream ist(eins);
        ist >> rv1;
        istringstream ist2(zwei);
        ist2 >> rv2;
        // add systematic shift
        if(ui->checkBox_25->isChecked()){
            irv1=(rv1+sysshift[count])/velst;
            irv2=(rv2+sysshift[count])/velst;
        }
        else{
            if(ui->checkBox_26->isChecked()){
                irv1=(rv1+sysshift[0])/velst;
                irv2=(rv2+sysshift[0])/velst;
            }
            else{
                irv1=rv1/velst;
                irv2=rv2/velst;
            }
        }
        cout<<rv1<<"\t"<<rv2<<endl;
        cout<<irv1<<"\t"<<irv2<<endl;
        cout<<irv1*tbina<<"\t"<<rv2*tbina<<endl;
        double tdiff=0.0;

        dat1.close();

        double multiA =ui->lineEdit_24->text().toDouble();
        double multiB =ui->lineEdit_25->text().toDouble();

        if(ui->checkBox_17->isChecked()){
            for(int g=0; g<numbera; g++){
                wt[g]=wta[g]+irv1*tbina;
                it[g]=ita[g]+fA;
                if(ui->checkBox_15->isChecked()){
                    it[g]=it[g]*multiA;
                }
                tdiff=tbina;
            }
        }
        else{
            for(int g=0; g<numberb; g++){
                wt[g]=wtb[g]+irv2*tbinb;
                it[g]=itb[g]+fB;
                if(ui->checkBox_16->isChecked()){
                    it[g]=it[g]*multiB;
                }
                tdiff=tbinb;
            }
        }

        QString input2=ui->lineEdit_7->text();
        string data2 = input2.toUtf8().constData();
        std::ostringstream dat2NameStream(data1);
        dat2NameStream<<path<<"/"<<data2<<i<<".txt";
        std::string dat2Name = dat2NameStream.str();

        QFile checkfile2(dat2Name.c_str());

        if(!checkfile2.exists()){
            QMessageBox::information(this, "Error", "The file "+checkfile2.fileName()+" does not exist.");
            qDebug()<<"The file "<<checkfile2.fileName()<<" does not exist.";
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }

        ifstream dat2(dat2Name.c_str());

        int number =0;

        while(std::getline(dat2, line))
           ++ number;

        dat2.clear();
        dat2.seekg(0, ios::beg);
        QVector<double> ws(number), is(number);

        for(int g=0; g<number; g++){
            dat2 >> eins >> zwei;
            istringstream str(eins);
            str >> ws[g];
            istringstream str2(zwei);
            str2 >> is[g];
        }
        dat2.close();

        QString out=ui->lineEdit_26->text();
        string out1 = out.toUtf8().constData();
        std::ostringstream out1NameStream(data1);
        out1NameStream<<path<<"/"<<out1<<i<<".txt";
        std::string out1Name = out1NameStream.str();
        ofstream sub1(out1Name.c_str());

        double inter=0.0;

        for(int g=0; g<number; g++){

            for(int n=0; n<tbin; n++){
                if((n+1)<=wt.size()){

                    if(ui->checkBox_27->isChecked()){ // linear interpolation
                        if((ws[g]>=wt[n])&(ws[g]<=wt[n+1])){
                            inter = is[g]-(it[n]+(ws[g]-wt[n])/(wt[n+1]-wt[n])*(it[n+1]-it[n]));
                            if(ui->checkBox_17->isChecked()){
                                inter = inter/fB;
                            }
                            else{
                                if(ui->checkBox_18->isChecked()){
                                    inter = inter/fA;
                                }
                                else{
                                    //inter = inter;
                                }
                            }
                            if(ui->checkBox_20->isChecked()){   // shift by A
                                sub1<<setprecision(14)<<pow(10,(ws[g]-irv1*tbina))<<"\t"<<inter<<endl;
                            }
                            else{
                                if(ui->checkBox_21->isChecked()){   // shift by B
                                    sub1<<setprecision(14)<<pow(10,(ws[g]-irv2*tbinb))<<"\t"<<inter<<endl;
                                }
                                else{
                                    sub1<<setprecision(14)<<pow(10,ws[g])<<"\t"<<inter<<endl;
                                }
                            }
                            n=tbin;
                        }
                        else{
                            //
                        }
                    }
                    else{ // spline interpolation
                        if(ws[g]<wt[3]){    // using first three points
                            Xs[0]=wt[0];
                            Xs[1]=wt[1];
                            Xs[2]=wt[2];
                            //Xs[3]=wt[3];
                            Ys[0]=it[0];
                            Ys[1]=it[1];
                            Ys[2]=it[2];
                            //Ys[3]=measi[3];
                            xs=ws[g];
                            sp.set_points(Xs,Ys);
                            inter=is[g]-sp(xs);
                            n=tbin;
                            adiff=0;
                        }
                        else{
                            if(ws[g]>wt[tbin-3]){
                                Xs[0]=wt[tbin-3];
                                Xs[1]=wt[tbin-2];
                                Xs[2]=wt[tbin-1];
                                //Xs[3]=wt[3];
                                Ys[0]=it[tbin-3];
                                Ys[1]=it[tbin-2];
                                Ys[2]=it[tbin-1];
                                //Ys[3]=measi[3];
                                xs=ws[g];
                                sp.set_points(Xs,Ys);
                                inter=is[g]-sp(xs);

                                n=tbin;
                            }
                            else{
                                if((ws[g]>wt[n]-tdiff/2) & (ws[g]<wt[n]+tdiff/2)){
                                    Xs[0]=wt[n-1];
                                    Xs[1]=wt[n];
                                    Xs[2]=wt[n+1];
                                    //Xs[3]=wt[n+2];
                                    Ys[0]=it[n-1];
                                    Ys[1]=it[n];
                                    Ys[2]=it[n+1];
                                    //Ys[3]=measi[n+2];
                                    xs=ws[g];
                                    sp.set_points(Xs,Ys);
                                    inter=is[g]-sp(xs);
                                    adiff=n;
                                    n=tbin;
                                }
                                else{
                                    //
                                }
                            }
                        }
                        if(inter==0){
                            inter=it[adiff];
                        }
                        else{
                            //
                        }
                        if(ui->checkBox_17->isChecked()){
                            inter = inter/fB;
                        }
                        else{
                            if(ui->checkBox_18->isChecked()){
                                inter = inter/fA;
                            }
                            else{
                                //inter = inter;
                            }
                        }
                        if(ui->checkBox_20->isChecked()){   // shift by A
                            sub1<<setprecision(14)<<pow(10,(ws[g]-irv1*tbina))<<"\t"<<inter<<endl;
                        }
                        else{
                            if(ui->checkBox_21->isChecked()){   // shift by B
                                sub1<<setprecision(14)<<pow(10,(ws[g]-irv2*tbinb))<<"\t"<<inter<<endl;
                            }
                            else{
                                sub1<<setprecision(14)<<pow(10,ws[g])<<"\t"<<inter<<endl;
                            }
                        }
                    }
                }
                else{
                    //
                }
            }
        }
        ++count;

    }
    this->setCursor(QCursor(Qt::ArrowCursor));
}

void MainWindow::on_checkBox_20_stateChanged()
{
    if(ui->checkBox_20->isChecked()){
        ui->checkBox_21->setChecked(false);
    }
}

void MainWindow::on_checkBox_21_stateChanged()
{
    if(ui->checkBox_21->isChecked()){
        ui->checkBox_20->setChecked(false);
    }
}

void MainWindow::on_checkBox_22_clicked()
{
    if(ui->checkBox_22->isChecked()){
        ui->checkBox_23->setChecked(false);
        ui->checkBox_24->setChecked(false);
    }
    else{
        ui->checkBox_23->setChecked(false);
        ui->checkBox_24->setChecked(true);
    }
}

void MainWindow::on_checkBox_23_clicked()
{
    if(ui->checkBox_23->isChecked()){
        ui->checkBox_22->setChecked(false);
        ui->checkBox_24->setChecked(false);
    }
    else{
        ui->checkBox_22->setChecked(false);
        ui->checkBox_24->setChecked(true);
    }
}

void MainWindow::on_checkBox_24_clicked()
{
    if(ui->checkBox_24->isChecked()){
        ui->checkBox_23->setChecked(false);
        ui->checkBox_22->setChecked(false);
    }
    else{
        ui->checkBox_23->setChecked(false);
        ui->checkBox_22->setChecked(true);
    }
}

void MainWindow::on_doubleSpinBox_20_valueChanged()
{
    if(ui->checkBox_26->isChecked()){
        ui->spinBox_7->setValue(ui->spinBox_6->value());
        ui->spinBox_4->setValue(ui->spinBox_6->value());
        ui->spinBox_5->setValue(ui->spinBox_6->value());

        MainWindow::on_pushButton_15_clicked();

        ui->lineEdit_14->setText(ui->lineEdit_26->text());
        MainWindow::on_pushButton_9_clicked();
        MainWindow::on_pushButton_8_clicked();
    }
    else{

    }
}

void MainWindow::on_checkBox_27_clicked()
{
    if(ui->checkBox_27->isChecked()){
        ui->checkBox_28->setChecked(false);
    }
    else{
        ui->checkBox_28->setChecked(true);
    }
}

void MainWindow::on_checkBox_28_clicked()
{
    if(ui->checkBox_28->isChecked()){
        ui->checkBox_27->setChecked(false);
    }
    else{
        ui->checkBox_27->setChecked(true);
    }
}

//********************************************
// subtract full spline
//********************************************
void MainWindow::on_pushButton_16_clicked()
{
    int min=ui->spinBox_6->value();
    int max=ui->spinBox_7->value();
    int adiff=0;
    double velst=ui->lineEdit_16->text().toDouble(), rv1=0.0, rv2=0.0, tbina=0.0, tbinb=0.0;
    double irv1=0.0, irv2=0.0, xs=0.0;

    double kAB = ui->doubleSpinBox_21->value();
    double fA = kAB/(1+kAB);
    double fB = 1/(1+kAB);

    string  eins, zwei;
    tk::spline sp;

    if(velst==0){
        QMessageBox::information(this, "Error", "Velocity step size is zero. Did you executed CC first?");
        return;
    }
    this->setCursor(QCursor(Qt::WaitCursor));

    //read rebined template A
    QString temp1;
    if(ui->checkBox_17->isChecked()){
        temp1=ui->lineEdit_10->text();
    }
    else{
        if(ui->checkBox_18->isChecked()){
            temp1=ui->lineEdit_11->text();
        }
        else{
            QMessageBox::information(this, "Error", "Nothing to subtract. Choose either A or B.");
            return;
        }
    }

    string tempa = temp1.toUtf8().constData();
    std::ostringstream dataNameStream(tempa);
    dataNameStream<<path<<"/"<<tempa;
    std::string dataName = dataNameStream.str();

    QFile checkfilea(dataName.c_str());

    if(!checkfilea.exists()){
        QMessageBox::information(this, "Error", "The template file "+checkfilea.fileName()+" does not exist.");
        qDebug()<<"The file "<<checkfilea.fileName()<<" does not exist.";
        this->setCursor(QCursor(Qt::ArrowCursor));
        return;
    }

    ifstream data(dataName.c_str());

    int numbera =0;

    while(std::getline(data, line))
       ++ numbera;

    data.clear();
    data.seekg(0, ios::beg);

    QVector<double> wta(numbera), ita(numbera);
     vector<double> Ys(numbera), Xs(numbera);

    for(int i=0; i<numbera; i++){
        data >> eins >> zwei;
        istringstream str(eins);
        str >> wta[i];
        istringstream str2(zwei);
        str2 >> ita[i];
        if(i==1){
            tbina=wta[1]-wta[0];
        }
        else{
            //
        }
    }

    QVector<double> sysshift(1);

    // read file with shifts for subtraction
    if(ui->checkBox_25->isChecked()){
        QString inputs=ui->lineEdit_27->text();
        string datas = inputs.toUtf8().constData();
        std::ostringstream datsNameStream(datas);
        datsNameStream<<path<<"/"<<datas;
        std::string datsName = datsNameStream.str();

        QFile checkfiles(datsName.c_str());

        if(!checkfiles.exists()){
            QMessageBox::information(this, "Error", "The file "+checkfiles.fileName()+" does not exist.");
            qDebug()<<"The file "<<checkfiles.fileName()<<" does not exist.";
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }

        ifstream dats(datsName.c_str());

        int nshift =0;

        while(std::getline(dats, line))
           ++ nshift;

        dats.clear();
        dats.seekg(0, ios::beg);

        if(nshift!=(max-min+1)){
            QMessageBox::information(this, "Error", "Number of entries in file "+checkfiles.fileName()+"does not equal number of spectra.");
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }

        sysshift.resize(nshift);

        for(int g=0; g<nshift; g++){
            dats >> eins;
            istringstream str(eins);
            str >> sysshift[g];

        }
        dats.close();

    }
    else{
        //single file
        if(ui->checkBox_26->isChecked()){
            sysshift[0]=ui->doubleSpinBox_20->value();
        }
        else{
            //
        }
    }
    int count=0;

    for(int i =min; i<=max; i++){

        QString input=ui->lineEdit_8->text();
        string data1 = input.toUtf8().constData();
        std::ostringstream dat1NameStream(data1);
        dat1NameStream<<path<<"/"<<data1<<i<<".txt";
        std::string dat1Name = dat1NameStream.str();

        QFile checkfile1(dat1Name.c_str());

        if(!checkfile1.exists()){
            QMessageBox::information(this, "Error", "The file "+checkfile1.fileName()+" does not exist.");
            qDebug()<<"The file "<<checkfile1.fileName()<<" does not exist.";
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }

        ifstream dat1(dat1Name.c_str());

        dat1 >> eins >>zwei;
        istringstream ist(eins);
        ist >> rv1;
        istringstream ist2(zwei);
        ist2 >> rv2;
        // add systematic shift
        if(ui->checkBox_25->isChecked()){
            irv1=(rv1+sysshift[count])/velst;
            irv2=(rv2+sysshift[count])/velst;
        }
        else{
            if(ui->checkBox_26->isChecked()){
                irv1=(rv1+sysshift[0])/velst;
                irv2=(rv2+sysshift[0])/velst;
            }
            else{
                irv1=rv1/velst;
                irv2=rv2/velst;
            }
        }
        cout<<rv1<<"\t"<<rv2<<endl;
        cout<<irv1<<"\t"<<irv2<<endl;
        cout<<irv1*tbina<<"\t"<<rv2*tbina<<endl;
        double tdiff=0.0;

        dat1.close();

        double multiA =ui->lineEdit_24->text().toDouble();
        double multiB =ui->lineEdit_25->text().toDouble();

        if(ui->checkBox_17->isChecked()){
            for(int g=0; g<numbera; g++){
                Xs[g]=wta[g]+irv1*tbina;
                Ys[g]=ita[g]+fA;
                if(ui->checkBox_15->isChecked()){
                    Ys[g]=ita[g]*multiA;
                }
                tdiff=tbina;
            }
        }
        else{
            for(int g=0; g<numbera; g++){
                Xs[g]=wta[g]+irv2*tbinb;
                Ys[g]=ita[g]+fB;
                if(ui->checkBox_16->isChecked()){
                    Ys[g]=ita[g]*multiB;
                }
                tdiff=tbinb;
            }
        }

        QString input2=ui->lineEdit_7->text();
        string data2 = input2.toUtf8().constData();
        std::ostringstream dat2NameStream(data1);
        dat2NameStream<<path<<"/"<<data2<<i<<".txt";
        std::string dat2Name = dat2NameStream.str();

        QFile checkfile2(dat2Name.c_str());

        if(!checkfile2.exists()){
            QMessageBox::information(this, "Error", "The file "+checkfile2.fileName()+" does not exist.");
            qDebug()<<"The file "<<checkfile2.fileName()<<" does not exist.";
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }

        ifstream dat2(dat2Name.c_str());

        int number =0;

        while(std::getline(dat2, line))
           ++ number;

        dat2.clear();
        dat2.seekg(0, ios::beg);
        QVector<double> ws(number), is(number);

        for(int g=0; g<number; g++){
            dat2 >> eins >> zwei;
            istringstream str(eins);
            str >> ws[g];
            istringstream str2(zwei);
            str2 >> is[g];
        }
        dat2.close();

        QString out=ui->lineEdit_26->text();
        string out1 = out.toUtf8().constData();
        std::ostringstream out1NameStream(data1);
        out1NameStream<<path<<"/"<<out1<<i<<".txt";
        std::string out1Name = out1NameStream.str();
        ofstream sub1(out1Name.c_str());

        sp.set_points(Xs,Ys);

        for(int g=0; g<number; g++){
            xs=ws[g];
            sub1<<ws[g]<<"\t";
            if(ui->checkBox_17->isChecked()){
                sub1<<(is[g]-sp(xs))/fB<<endl;
            }
            else{
                if(ui->checkBox_18->isChecked()){
                    sub1<<(is[g]-sp(xs))/fA<<endl;
                }
                else{

                }
            }
        }
        sub1.close();
    }
    this->setCursor(QCursor(Qt::ArrowCursor));
}
