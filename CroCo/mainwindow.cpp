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


//running man icon from: https://cdn2.iconfinder.com/data/icons/windows-8-metro-style/512/running_man.png
//croco logo from: http://tux.crystalxp.net/de.id.1626-fcys14-tux-croco.html

using namespace std;
namespace fit=CCfits;


int num=1, bini=5, logbin=5, aa, d2, b2, d, b, dn, don, ssteps, counter, dosteps, vsteps, binia=5, binib=5, infilei=0, check=0;
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

    ui->lineEdit->setText("FLAMES_");
    ui->lineEdit_2->setText("vega");
    ui->lineEdit_3->setText("vega");
    ui->lineEdit_4->setText("binarym_0.txt");
    ui->lineEdit_5->setText("croped_0.txt");
    ui->lineEdit_6->setText("tempmB.txt");
    ui->lineEdit_7->setText("binarym_");
    ui->lineEdit_8->setText("binaryrv_");
    ui->lineEdit_10->setText("tempmA");
    ui->lineEdit_11->setText("tempmB");
    ui->lineEdit_14->setText("ccf_0_");
    increment=ui->doubleSpinBox_12->value();

    ui->spinBox->setValue(0);      //default for numbers of spectra
    ui->spinBox_2->setValue(60);    //default for doppler shift
    ui->spinBox_3->setValue(100);   //default for velocity shift
    ui->spinBox_4->setValue(0);     //default first cc file
    ui->spinBox_5->setValue(1);     //default last cc file

    ui->doubleSpinBox_5->setValue(-50);
    ui->doubleSpinBox_6->setValue(50);
    ui->doubleSpinBox_7->setValue(0);
    ui->doubleSpinBox_8->setValue(1);
    ui->doubleSpinBox_13->setValue(1);
    ui->doubleSpinBox_14->setValue(1);
    ui->doubleSpinBox_16->setValue(0.5);
    ui->lineEdit_15->setText("/home/daniels/Observations/Tomer/single");
    qpath=ui->lineEdit_15->text();
    path = qpath.toUtf8().constData();

    ui->checkBox_9->setChecked(false);
    ui->checkBox_10->setChecked(true);

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
    ui->label_25->setStyleSheet("QLabel{background: transparent;}");
    ui->label_26->setStyleSheet("QLabel{background: transparent;}");
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

void MainWindow::ReadMeasured(int gg){

    QString fext = ui->lineEdit_21->text();
    string sfext = fext.toUtf8().constData();

    if(ui->comboBox->currentIndex()==0){ // fits-file
        QString input=ui->lineEdit->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<path<<"/"<<data<<gg<<sfext;
        std::string datName = datNameStream.str();
        ifstream dat(datName.c_str());

        QFile checkfile1(datName.c_str());

        if(!checkfile1.exists()){
            qDebug()<<"Error 1: The file "<<checkfile1.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error1 ", "Error 1: Spectrum "+input+ +gg+ " does not exist!");
            check=1;
           return;
        }

        CCfits::FITS::setVerboseMode(true);

        try
        {

            //open file for reading
            auto_ptr<CCfits::FITS> input_file(new CCfits::FITS(datName.c_str(),CCfits::Read,true));

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
ifstream dat(datName.c_str());

QFile checkfile1(datName.c_str());

if(!checkfile1.exists()){
    qDebug()<<"Error 2: The file "<<checkfile1.fileName()<<" does not exist.";
    QMessageBox::information(this, "Error 2:", "Spectrum  "+input+ +gg+" does not exist!");
     check=1;
   return;
}

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

    if(ui->checkBox_11->isChecked()){

        if(absminw>ui->doubleSpinBox_17->value()){
            qDebug()<<"Error : At least one spectrum starts at a higher wavelength.";
            QString absmi=QString::number(absminw);
            QMessageBox::information(this, "Error ", "Error : At least one spectrum starts at a higher wavelength. The common value is "+absmi+".");

            return;
        }

        if(absmaxw<ui->doubleSpinBox_18->value()){
            qDebug()<<"Error : At least one spectrum ends at a lower wavelength.";
            QString absma=QString::number(absmaxw);
            QMessageBox::information(this, "Error ", "Error : At least one spectrum ends at a lower value. The common vale is "+absma+".");

            return;
        }

        absminw=ui->doubleSpinBox_17->value();
        absmaxw=ui->doubleSpinBox_18->value();

    }

    //looking for global smallest difference log(lambda)
    diff=dif[0];
    for (int g=0; g<num; g++){
        if(ui->checkBox_4->isChecked()){
            g=ui->spinBox->value();
        }
        if(dif[g]<diff){
            diff=dif[g];
            //cout<<diff<<endl;
        }
    }
    diff=diff*increment;

    dv=(pow(10,diff)-1)*c0;
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

        QString output11="croped_";
        string output1 = output11.toUtf8().constData();
        std::ostringstream output1NameStream(output1);
        output1NameStream<<path<<"/"<<output1<<g<<".txt";
        std::string output1Name = output1NameStream.str();
        ofstream file1(output1Name.c_str());

        for(int i=0; i<bini; i++){
        if((measw[i]>=absminw) & (measw[i]<=absmaxw)){
            file1<<measw[i]<<" "<<measi[i]<<endl;
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
        dat2NameStream<<path<<"/"<<data12<<".txt";
        std::string dat2Name = dat2NameStream.str();
        ifstream dat2(dat2Name.c_str());

        QFile checkfile2(dat2Name.c_str());

        if(!checkfile2.exists()){
            qDebug()<<"Error 3: The file "<<checkfile2.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "Error 3: Template A does not exist!");
           return;
        }

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
            QMessageBox::information(this, "Error", "Error 4: Template A starts at higher wavelength than all spectra.");
                    return;
        }
        if((i==bini-1)& (tempw1[bini-1]<absmaxw)){
            QMessageBox::information(this, "Error", "Error 5: Template A ends at lower wavelength than all spectra.");
            return;
        }
        }
        dat2.close();

        QString output12="cropedt1";
        string output2 = output12.toUtf8().constData();
        std::ostringstream output2NameStream(output2);
        output2NameStream<<path<<"/"<<output2<<".txt";
        std::string output2Name = output2NameStream.str();
        ofstream file2(output2Name.c_str());

        for(int i=0; i<bini; i++){
        if((tempw1[i]>=absminw) & (tempw1[i]<=absmaxw)){
            file2<<tempw1[i]<<" "<<tempi1[i]<<endl;
        }
        }

        //template2
        QString input13=ui->lineEdit_3->text();
        string data13 = input13.toUtf8().constData();
        std::ostringstream dat3NameStream(data13);
        dat3NameStream<<path<<"/"<<data13<<".txt";
        std::string dat3Name = dat3NameStream.str();
        ifstream dat3(dat3Name.c_str());

        QFile checkfile3(dat3Name.c_str());

        if(!checkfile3.exists()){
            qDebug()<<"Error 6: The file "<<checkfile3.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "Error 6: Template B does not exist!");
           return;
        }

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
            QMessageBox::information(this, "Error", "Error 7: Template B starts at higher wavelength than all spectra.");
                    return;
        }
        if((i==bini-1)& (tempw2[bini-1]<absmaxw)){
            QMessageBox::information(this, "Error", "Error 8: Template B ends at lower wavelength than all spectra.");
            return;
        }
        }
        dat3.close();

        QString output13="cropedt2";
        string output3 = output13.toUtf8().constData();
        std::ostringstream output3NameStream(output3);
        output3NameStream<<path<<"/"<<output3<<".txt";
        std::string output3Name = output3NameStream.str();
        ofstream file3(output3Name.c_str());

        for(int i=0; i<bini; i++){
        if((tempw2[i]>=absminw) & (tempw2[i]<=absmaxw)){
            file3<<tempw2[i]<<" "<<tempi2[i]<<endl;
        }
        }}



//******************************************************
//rebinning
//******************************************************
        this->setCursor(QCursor(Qt::WaitCursor));
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

         measn=ui->doubleSpinBox_13->value();
         tempn=ui->doubleSpinBox_14->value();
         tempn2=ui->doubleSpinBox_16->value();

         //read measured spectrum

       QString input="croped_";

        string data1 = input.toUtf8().constData();
         std::ostringstream dat1NameStream(data1);
         dat1NameStream<<path<<"/"<<data1<<g<<".txt";
         std::string dat1Name = dat1NameStream.str();
         ifstream dat1(dat1Name.c_str());

         QFile checkfile1(dat1Name.c_str());

         if(!checkfile1.exists()){
             qDebug()<<"Error 9: The file "<<checkfile1.fileName()<<" does not exist.";
             QMessageBox::information(this, "Error", "Error 9: Spectrum "+checkfile1.fileName()+" does not exist!");
             this->setCursor(QCursor(Qt::ArrowCursor));
            return;
         }

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

         aa=0;

         for(int i=0; i<logbin; i++){

             resamw[i]=measw[0]+i*diff;
             resami[i]=0;

             for(int e=aa; e<aa+5; e++){

                 if(measw[e]==resamw[i]){
                     resami[i]=measi[e];
                     aa=e;
                 }
                 if((measw[e]<resamw[i])&(measw[e+1]>resamw[i])){
                     resami[i]=measi[e]+(resamw[i]-measw[e])/(measw[e+1]-measw[e])*(measi[e+1]-measi[e]);
                     aa=e;
                 }
             }
             file1<<std::setprecision(8)<<resamw[i]<<" "<<resami[i]<<endl;
         }
         file1.close();


                 for (int i=0; i+1<bini; i++){
                 mi+=(measw[i+1]-measw[i])*((measi[i]+measi[i+1])/2);
                 }
                 for (int i=0; i+1<logbin; i++){
                 ri+=(resamw[i+1]-resamw[i])*((resami[i]+resami[i+1])/2);
                 }
                 ui->progressBar->setValue(100/num*(g+1));
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
                 ui->customPlot->yAxis->setRange(yy1, yy2);
                 ui->customPlot->replot();

        }

                 if(ui->checkBox_9->isChecked()){
                 //read primary template
                 QString input2=ui->lineEdit_2->text();

                 if(ui->checkBox_10->isChecked()){
                     input2="cropedt1";
                 }

                 string data2 = input2.toUtf8().constData();
                 std::ostringstream dat2NameStream(data2);
                 dat2NameStream<<path<<"/"<<data2<<".txt";
                 std::string dat2Name = dat2NameStream.str();
                 ifstream dat2(dat2Name.c_str());

                 QFile checkfile2(dat2Name.c_str());

                 if(!checkfile2.exists()){
                     qDebug()<<"Error 10: The file "<<checkfile2.fileName()<<" does not exist.";
                     QMessageBox::information(this, "Error", "Error 10: Template A does not exist!");
                     this->setCursor(QCursor(Qt::ArrowCursor));
                    return;
                 }

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


                 if(bini<binia){
                     QMessageBox::information(this, "Error", "Error 12: Sampling of Template A to high!");
                     this->setCursor(QCursor(Qt::ArrowCursor));
                    return;
                 }

                 tempi1.resize(binia);
                 tempw1.resize(binia);

                 QString output21=ui->lineEdit_10->text();
                 string output2 = output21.toUtf8().constData();
                 std::ostringstream file2NameStream(output2);
                 file2NameStream<<path<<"/"<<output2<<".txt";
                 std::string file2Name = file2NameStream.str();
                 ofstream file2(file2Name.c_str());

                 for (int i =0; i < bini; i++){
                 dat2 >> eins >> zwei;
                 istringstream istr4(eins);
                 istr4 >> tempw1[i];
                 tempw1[i]=log10(tempw1[i]);
                 istringstream istr5(zwei);
                 istr5 >> tempi1[i];
                 tempi1[i]=(tempi1[i]-tempn);
                 }
                 dat2.close();

                 //read secondary template
                 QString input3=ui->lineEdit_3->text();

                 if(ui->checkBox_10->isChecked()){
                 input3="cropedt2";
                 }

                 string data3 = input3.toUtf8().constData();
                 std::ostringstream dat3NameStream(data3);
                 dat3NameStream<<path<<"/"<<data3<<".txt";
                 std::string dat3Name = dat3NameStream.str();
                 ifstream dat3(dat3Name.c_str());

                 QFile checkfile3(dat3Name.c_str());

                 if(!checkfile3.exists()){
                     qDebug()<<"The file "<<checkfile3.fileName()<<" does not exist.";
                     QMessageBox::information(this, "Error", "Error 13: Template B does not exist!");
                     this->setCursor(QCursor(Qt::ArrowCursor));
                    return;
                 }

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


                 if(bini<binib){
                     QMessageBox::information(this, "Error", "Error 15: Sampling of template B to high!");
                     this->setCursor(QCursor(Qt::ArrowCursor));
                    return;
                 }

                 tempi2.resize(binib);
                 tempw2.resize(binib);

                 for (int i =0; i < bini; i++){
                 dat3 >> eins >> zwei;
                 istringstream istr7(eins);
                 istr7 >> tempw2[i];
                 tempw2[i]=log10(tempw2[i]);
                 istringstream istr8(zwei);
                 istr8 >> tempi2[i];
                 tempi2[i]=(tempi2[i]-tempn2);
                 }
                 dat3.close();

                 QString output31=ui->lineEdit_11->text();
                 string output3 = output31.toUtf8().constData();
                 std::ostringstream file3NameStream(output3);
                 file3NameStream<<path<<"/"<<output3<<".txt";
                 std::string file3Name = file3NameStream.str();
                 ofstream file3(file3Name.c_str());

        //interpolation primary template

        retw1.resize(logbin);
        reti1.resize(logbin);

        aa=0;

        for(int i=0; i<logbin; i++){

            retw1[i]=tempw1[0]+i*diff;
            reti1[i]=0;

            for(int e=aa; e<aa+5; e++){

                if(tempw1[e]==reti1[i]){
                    reti1[i]=tempi1[e];
                    aa=e;
                }
                if((tempw1[e]<retw1[i])&(tempw1[e+1]>retw1[i])){
                    reti1[i]=tempi1[e]+(retw1[i]-tempw1[e])/(tempw1[e+1]-tempw1[e])*(tempi1[e+1]-tempi1[e]);
                    aa=e;
                }
            }
            file2<<std::setprecision(8)<<retw1[i]<<" "<<reti1[i]<<endl;
        }
        file2.close();



        //interpolation secondary template
        retw2.resize(logbin);
        reti2.resize(logbin);

        aa=0;

        for(int i=0; i<logbin; i++){

            retw2[i]=tempw2[0]+i*diff;
            reti2[i]=0;

            for(int e=aa; e<aa+5; e++){

                if(tempw2[e]==reti2[i]){
                    reti2[i]=tempi2[e];
                    aa=e;
                }
                if((tempw2[e]<retw2[i])&(tempw2[e+1]>retw2[i])){
                    reti2[i]=tempi2[e]+(retw2[i]-tempw2[e])/(tempw2[e+1]-tempw2[e])*(tempi2[e+1]-tempi2[e]);
                    aa=e;
                }
            }
            file3<<std::setprecision(8)<<retw2[i]<<" "<<reti2[i]<<endl;
        }
        file3.close();

                 }


    ui->progressBar->setValue(100);
    this->setCursor(QCursor(Qt::ArrowCursor));
}

//*******************************************************************
//Read fits header or extension header
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
    ifstream toplot1(dat1Name.c_str());

    QFile checkfile1(dat1Name.c_str());

    if(!checkfile1.exists()){
        qDebug()<<"Error 16: The file "<<checkfile1.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "Error 16: File 1 does not exist!");
       return;
    }

    QString plot2=ui->lineEdit_5->text();
    string plot12 = plot2.toUtf8().constData();
    std::ostringstream dat2NameStream(plot12);
    dat2NameStream<<path<<"/"<<plot12;
    std::string dat2Name = dat2NameStream.str();
    ifstream toplot2(dat2Name.c_str());

    QFile checkfile2(dat2Name.c_str());

    if(!checkfile2.exists()){
        qDebug()<<"Error 17: The file "<<checkfile2.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "Error 17: File 2 does not exist!");
       return;
    }

    QString plot3=ui->lineEdit_6->text();
    string plot13 = plot3.toUtf8().constData();
    std::ostringstream dat3NameStream(plot13);
    dat3NameStream<<path<<"/"<<plot13;
    std::string dat3Name = dat3NameStream.str();
    ifstream toplot3(dat3Name.c_str());

    QFile checkfile3(dat3Name.c_str());

    if(!checkfile3.exists()){
        qDebug()<<"Error 18: The file "<<checkfile3.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "Error 18: File 3 does not exist!");
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

    //read rebined template A
    QString input2=ui->lineEdit_10->text();
    string data2 = input2.toUtf8().constData();
    std::ostringstream dat2NameStream(data2);
    dat2NameStream<<path<<"/"<<data2<<".txt";
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
    dat3NameStream<<path<<"/"<<data3<<".txt";
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

        //read rebined spectra
        QString input=ui->lineEdit_7->text();
        string data1 = input.toUtf8().constData();
        std::ostringstream dat1NameStream(data1);
        dat1NameStream<<path<<"/"<<data1<<g<<".txt";
        std::string dat1Name = dat1NameStream.str();
        ifstream dat1(dat1Name.c_str());

        QFile checkfile1(dat1Name.c_str());

        if(!checkfile1.exists()){
            qDebug()<<"Error 21: The file "<<checkfile1.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "Error 21: File for rebined spectra does not exist!");
           return;
        }

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
            ccf[n][m]=0;
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
            }}
            }}

    if(ui->checkBox_12->isChecked()){
    for(int m=0; m<2*dosteps; m++){
    std::ostringstream file5NameStream("ccf_");
    file5NameStream<<path<<"/ccf_"<<g<<"_"<<m<<".txt";
    std::string file5Name = file5NameStream.str();
    ofstream file5(file5Name.c_str());

    for(int n=0; n<2*vsteps; n++){
        if((ccf[n][m]<1) &(ccf[n][m]>0)){
        file5<<(-1)*(vsteps - n)*dv<<" "<<ccf[n][m]<<endl;
    }}
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
            }}
            }

    std::ostringstream file6NameStream("ccfmax_");
    file6NameStream<<path<<"/ccfmax_"<<g<<".txt";
    std::string file6Name = file6NameStream.str();
    ofstream file6(file6Name.c_str());

    for(int i=0; i<2*vsteps; i++){
        file6<<(-1)*(vsteps - i)*dv<<" "<<ccf[i][d]<<endl;
    }

    QString hift= QString::number((-1)*shift);
    ui->lineEdit_12->setText(hift);

    QString epa= QString::number((-1)*sepa);
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

    rvfile<<(-1)*shift<<" "<<(-1)*sepa<<endl;

    ui->progressBar->setValue(100/num*(g+1));
    qApp->processEvents(QEventLoop::AllEvents);

    this->setCursor(QCursor(Qt::ArrowCursor));

}
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
    pSpec->show();
}

void MainWindow::on_actionSequence_Plotter_triggered()
{
    pSequ = new PlotSequ(this);
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
    qTell->show();
}

void MainWindow::on_action2D_Map_Plot_triggered()
{
    qMPlot = new MapPlot(this);
    qMPlot->show();
}

void MainWindow::on_actionRV_Calculator_triggered()
{
    qRVCalc = new RVCalc(this);
    qRVCalc->show();
}

void MainWindow::on_actionRaname_Files_triggered()
{
    qRename = new Rename(this);
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
    qCPD->show();
}

void MainWindow::on_actionArithmetic_triggered()
{
    qArith = new Arithmetic(this);
    qArith->show();
}
