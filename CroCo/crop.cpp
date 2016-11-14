#include "crop.h"
#include "ui_crop.h"
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <QMessageBox>
#include <QFile>
#include <iostream>
#include <CCfits/CCfits>

using namespace std;

Crop::Crop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Crop)
{
    ui->setupUi(this);

    this->setWindowTitle("Crop Spectra");

    ui->comboBox->addItem("ASCII");
    ui->comboBox->addItem("FITS");

    ui->lineEdit->setText("car_");
    ui->lineEdit_2->setText(".dat");
    ui->lineEdit_3->setText("Arg");
    ui->lineEdit_4->setText("DataVector");
    ui->lineEdit_5->setText("Fun");
    ui->lineEdit_7->setText("/home/daniels/Observations/Capella/Set_4/Ca_UV");

    ui->doubleSpinBox->setValue(6255.7);
    ui->doubleSpinBox_2->setValue(6262.2    );

}

Crop::~Crop()
{
    delete ui;
}

void Crop::on_pushButton_2_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));

    int min=ui->spinBox->value();
    int max=ui->spinBox_2->value();
    int numpix=0;

    double wlow=ui->doubleSpinBox->value();
    double wupp=ui->doubleSpinBox_2->value();

    QString qCrPath = ui->lineEdit_7->text();
    string crPath = qCrPath.toUtf8().constData();

    QString Qext=ui->lineEdit_2->text();
    string ext = Qext.toUtf8().constData();

    QString qExtension=ui->lineEdit_4->text();
    string Extension = qExtension.toUtf8().constData();
    QString qWavecol=ui->lineEdit_3->text();
    string Wavecol = qWavecol.toUtf8().constData();
    QString qIntenscol=ui->lineEdit_5->text();
    string Intenscol = qIntenscol.toUtf8().constData();

    if(ui->comboBox->currentIndex()==0){

        for(int i =min; i<=max; i++){
        QString inputA=ui->lineEdit->text();
        string dataA = inputA.toUtf8().constData();
        std::ostringstream datANameStream(dataA);
        datANameStream<<crPath<<"/"<<dataA<<i<<ext;
        std::string datAName = datANameStream.str();
        ifstream inA(datAName.c_str());

        QFile checkfile1(datAName.c_str());

        if(!checkfile1.exists()){
            QMessageBox::information(this, "Error", "File"+qCrPath+"/"+inputA+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }


        string line, eins, zwei;

        while(std::getline(inA, line))
           ++numpix;

        inA.clear();
        inA.seekg(0, ios::beg);

        QVector<double> a(numpix), b(numpix);

        QString output=ui->lineEdit_6->text();
        string out = output.toUtf8().constData();
        std::ostringstream outNameStream(out);
        outNameStream<<crPath<<"/"<<out<<i<<".dat";
        std::string outName = outNameStream.str();
        ofstream outp(outName.c_str());

        for(int g=0; g<numpix; g++){
        inA >> eins >>zwei;
        istringstream ist(eins);
        ist >> a[g];
        istringstream ist2(zwei);
        ist2 >> b[g];

        if((a[g]>=wlow) & (a[g]<=wupp)){
            outp<<setprecision(12)<<a[g]<<"\t"<<b[g]<<endl;
        }
        }
        numpix=0;

        inA.close();
        outp.close();

        }

    }

    if(ui->comboBox->currentIndex()==1){

        std::valarray<double> cwave;
        std::valarray<double> cintens;

        for(int i =min; i<=max; i++){
        QString input=ui->lineEdit->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<crPath<<"/"<<data<<i<<ext;
        std::string datName = datNameStream.str();
        ifstream dat(datName.c_str());

        QFile checkfile1(datName.c_str());

        if(!checkfile1.exists()){
            QMessageBox::information(this, "Error1 ", "Error 1: Spectrum "+input+ +i+ " does not exist!");
           return;
        }

        QString output=ui->lineEdit_6->text();
        string out = output.toUtf8().constData();
        std::ostringstream outNameStream(out);
        outNameStream<<crPath<<"/"<<out<<i<<".dat";
        std::string outName = outNameStream.str();
        ofstream outp(outName.c_str());

        CCfits::FITS::setVerboseMode(true);

        try
        {

            //open file for reading
            auto_ptr<CCfits::FITS> input_file(new CCfits::FITS(datName.c_str(),CCfits::Read,true));

            // Create pointer to extension
                CCfits::ExtHDU& datavector = input_file->extension(Extension);

              // Read rows
              CCfits::Column& column = datavector.column(Wavecol);
              column.read(cwave, 1, column.rows());

              // Read rows
              CCfits::Column& column2 = datavector.column(Intenscol);
              column2.read(cintens, 1, column2.rows());

              numpix=cwave.size();

              for(int i=0; i<numpix; i++){
                  if(cwave[i]>=wlow & (cwave[i]<=wupp)){
                outp<<setprecision(12)<<cwave[i]<<"\t"<<cintens[i]<<endl;
                  }
              }


        }
            catch (CCfits::FitsException&)

             {
              std::cerr << " Fits Exception Thrown by test function \n";
              }


           // return;

        }

    }

    this->setCursor(QCursor(Qt::ArrowCursor));

}

void Crop::on_pushButton_3_clicked()
{
    if(ui->spinBox_3->value()==0 or ui->spinBox_3->value()==1){
        QMessageBox::information(this, "Nothing to do.", "Specify binning > 1.");
        return;
    }

    this->setCursor(QCursor(Qt::WaitCursor));

    int min=ui->spinBox->value();
    int max=ui->spinBox_2->value();
    int numpix=0;

    double wlow=ui->doubleSpinBox->value();
    double wupp=ui->doubleSpinBox_2->value();

    QString qCrPath = ui->lineEdit_7->text();
    string crPath = qCrPath.toUtf8().constData();

    QString Qext=ui->lineEdit_2->text();
    string ext = Qext.toUtf8().constData();

    QString qExtension=ui->lineEdit_4->text();
    string Extension = qExtension.toUtf8().constData();
    QString qWavecol=ui->lineEdit_3->text();
    string Wavecol = qWavecol.toUtf8().constData();
    QString qIntenscol=ui->lineEdit_5->text();
    string Intenscol = qIntenscol.toUtf8().constData();

    if(ui->comboBox->currentIndex()==0){

        for(int i =min; i<=max; i++){
        QString inputA=ui->lineEdit->text();
        string dataA = inputA.toUtf8().constData();
        std::ostringstream datANameStream(dataA);
        datANameStream<<crPath<<"/"<<dataA<<i<<ext;
        std::string datAName = datANameStream.str();
        ifstream inA(datAName.c_str());

        QFile checkfile1(datAName.c_str());

        if(!checkfile1.exists()){
            QMessageBox::information(this, "Error", "File"+qCrPath+"/"+inputA+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }


        string line, eins, zwei;

        while(std::getline(inA, line))
           ++numpix;

        inA.clear();
        inA.seekg(0, ios::beg);

        QVector<double> a(numpix), b(numpix);

        QString output=ui->lineEdit_6->text();
        string out = output.toUtf8().constData();
        std::ostringstream outNameStream(out);
        outNameStream<<crPath<<"/"<<out<<i<<".dat";
        std::string outName = outNameStream.str();
        ofstream outp(outName.c_str());

        for(int g=0; g<numpix; g++){
        inA >> eins >>zwei;
        istringstream ist(eins);
        ist >> a[g];
        istringstream ist2(zwei);
        ist2 >> b[g];
        }

        double binint=0, biniwa=0;
        double binst=ui->spinBox_3->value();

        for(int g =0; g<numpix-(binst-1); g++){
            for(int i=0; i<binst; i++){
                biniwa+=a[g+i];
                binint+=b[g+i];
            }
            g=g+binst-1;
            binint=binint/binst;
            biniwa=biniwa/binst;
            outp<<setprecision(12)<<biniwa<<"\t"<<binint<<endl;
            binint=0;
            biniwa=0;
        }
        numpix=0;

        inA.close();
        outp.close();

        }

    }

    if(ui->comboBox->currentIndex()==1){

        std::valarray<double> cwave;
        std::valarray<double> cintens;

        for(int i =min; i<=max; i++){
        QString input=ui->lineEdit->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<crPath<<"/"<<data<<i<<ext;
        std::string datName = datNameStream.str();
        ifstream dat(datName.c_str());

        QFile checkfile1(datName.c_str());

        if(!checkfile1.exists()){
            QMessageBox::information(this, "Error1 ", "Error 1: Spectrum "+input+ +i+ " does not exist!");
           return;
        }

        QString output=ui->lineEdit_6->text();
        string out = output.toUtf8().constData();
        std::ostringstream outNameStream(out);
        outNameStream<<crPath<<"/"<<out<<i<<".dat";
        std::string outName = outNameStream.str();
        ofstream outp(outName.c_str());

        CCfits::FITS::setVerboseMode(true);

        try
        {

            //open file for reading
            auto_ptr<CCfits::FITS> input_file(new CCfits::FITS(datName.c_str(),CCfits::Read,true));

            // Create pointer to extension
                CCfits::ExtHDU& datavector = input_file->extension(Extension);

              // Read rows
              CCfits::Column& column = datavector.column(Wavecol);
              column.read(cwave, 1, column.rows());

              // Read rows
              CCfits::Column& column2 = datavector.column(Intenscol);
              column2.read(cintens, 1, column2.rows());

              numpix=cwave.size();

              double binint=0, biniwa=0;
              double binst=ui->spinBox_3->value();

              for(int g =0; g<numpix-(binst-1); g++){
                  for(int i=0; i<binst; i++){
                      biniwa+=cwave[g+i];
                      binint+=cintens[g+i];
                  }
                  g=g+binst-1;
                  binint=binint/binst;
                  biniwa=biniwa/binst;
                  outp<<setprecision(12)<<biniwa<<"\t"<<binint<<endl;
                  binint=0;
                  biniwa=0;
              }
              numpix=0;


        }
            catch (CCfits::FitsException&)

             {
              std::cerr << " Fits Exception Thrown by test function \n";
              }


           // return;

        }

    }

    this->setCursor(QCursor(Qt::ArrowCursor));

}
