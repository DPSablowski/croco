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

int abcrop=0;
QVector<double> rangea(1), rangeb(1);

Crop::Crop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Crop)
{
    ui->setupUi(this);

    this->setWindowTitle("Crop Spectra");

    ui->comboBox->addItem("ASCII");
    ui->comboBox->addItem("FITS");

    ui->lineEdit_2->setText("txt");
    ui->lineEdit_8->setText("txt");

    ui->doubleSpinBox->setValue(6255.7);
    ui->doubleSpinBox_2->setValue(6262.2);

}

Crop::~Crop()
{
    delete ui;
}

void Crop::seData(QString str, QString str2, QString str3, QString str4, QString str5)
{
    ui->lineEdit_7->setText(str);
    ui->lineEdit->setText(str2);
    ui->lineEdit_4->setText(str3);
    ui->lineEdit_3->setText(str4);
    ui->lineEdit_5->setText(str5);
}


//******************************************
// crop spectra
//******************************************
void Crop::on_pushButton_2_clicked()
{
    if(ui->checkBox_2->isChecked()){
        QString qCrPath = ui->lineEdit_7->text();
        string crPath = qCrPath.toUtf8().constData();

        QString qinfile = ui->lineEdit_9->text();
        string infile = qinfile.toUtf8().constData();

        std::ostringstream datNameStream(infile);
        datNameStream<<crPath<<"/"<<infile;
        std::string datName = datNameStream.str();

        QFile checkfile0(datName.c_str());

        if(!checkfile0.exists()){
            QMessageBox::information(this, "Error", "File "+checkfile0.fileName()+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }
        else{
            ifstream range(datName.c_str());

            string lines, one, two;
            int nrange=0;

            while(std::getline(range, lines))
            ++nrange;

            range.clear();
            range.seekg(0, ios::beg);

            rangea.resize(nrange);
            rangeb.resize(nrange);

            for(int g=0; g<nrange; g++){
                range >> one >>two;
                istringstream ist(one);
                ist >> rangea[g];
                istringstream ist2(two);
                ist2 >> rangeb[g];
            }
            range.close();
        }
        Crop::cropSpectra();
    }
    else{
        Crop::cropSpectra();
    }
}
void Crop::cropSpectra()
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

    QString qoExt = ui->lineEdit_8->text();
    string oExt = qoExt.toUtf8().constData();

    if(ui->comboBox->currentIndex()==0){

        for(int i =min; i<=max; i++){

            qApp->processEvents(QEventLoop::AllEvents);
            if(abcrop==1){
                abcrop=0;
                return;
            }

            QString inputA=ui->lineEdit->text();
            string dataA = inputA.toUtf8().constData();
            std::ostringstream datANameStream(dataA);
            datANameStream<<crPath<<"/"<<dataA<<i<<"."<<ext;
            std::string datAName = datANameStream.str();

            QFile checkfile1(datAName.c_str());

            if(!checkfile1.exists()){
                QMessageBox::information(this, "Error", "File "+checkfile1.fileName()+" does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
                return;
            }

            ifstream inA(datAName.c_str());

            string line, eins, zwei;

            while(std::getline(inA, line))
            ++numpix;

            inA.clear();
            inA.seekg(0, ios::beg);

            QVector<double> a(numpix), b(numpix);

            QString output=ui->lineEdit_6->text();
            string out = output.toUtf8().constData();
            std::ostringstream outNameStream(out);
            outNameStream<<crPath<<"/"<<out<<i<<"."<<oExt;
            std::string outName = outNameStream.str();

            for(int g=0; g<numpix; g++){
                inA >> eins >>zwei;
                istringstream ist(eins);
                ist >> a[g];
                istringstream ist2(zwei);
                ist2 >> b[g];
            }

            ofstream outp(outName.c_str());

            if(ui->checkBox_2->isChecked()){
                for(int zu=0; zu<rangea.size(); zu++){
                    for(int g =0; g<numpix;g++){
                        if((a[g]>=rangea[zu]) & (a[g]<=rangeb[zu])){
                            outp<<setprecision(14)<<a[g]<<"\t"<<b[g]<<endl;
                        }
                        else{
                            //
                        }
                    }
                }
            }
            else{
                for(int g =0; g<numpix;g++){
                    if((a[g]>=wlow) & (a[g]<=wupp)){
                        outp<<setprecision(14)<<a[g]<<"\t"<<b[g]<<endl;
                    }
                    else{
                        //
                    }
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
            datNameStream<<crPath<<"/"<<data<<i<<"."<<ext;
            std::string datName = datNameStream.str();

            QFile checkfile1(datName.c_str());

            if(!checkfile1.exists()){
                QMessageBox::information(this, "Error1 ", "Error 1: Spectrum "+checkfile1.fileName()+" does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
                return;
            }

            QString output=ui->lineEdit_6->text();
            string out = output.toUtf8().constData();
            std::ostringstream outNameStream(out);
            outNameStream<<crPath<<"/"<<out<<i<<"."<<oExt;
            std::string outName = outNameStream.str();

            CCfits::FITS::setVerboseMode(true);

            try
            {
                QString qExtension=ui->lineEdit_4->text();
                string Extension = qExtension.toUtf8().constData();
                QString qWavecol=ui->lineEdit_3->text();
                string Wavecol = qWavecol.toUtf8().constData();
                QString qIntenscol=ui->lineEdit_5->text();
                string Intenscol = qIntenscol.toUtf8().constData();

            //open file for reading
            shared_ptr<CCfits::FITS> input_file(new CCfits::FITS(datName.c_str(),CCfits::Read,true));

            // Create pointer to extension
                CCfits::ExtHDU& datavector = input_file->extension(Extension);

              // Read rows
              CCfits::Column& column = datavector.column(Wavecol);
              column.read(cwave, 1, column.rows());

              // Read rows
              CCfits::Column& column2 = datavector.column(Intenscol);
              column2.read(cintens, 1, column2.rows());

              numpix=cwave.size();

              ofstream outp(outName.c_str());

              for(int i=0; i<numpix; i++){
                  if(cwave[i]>=wlow & (cwave[i]<=wupp)){
                        outp<<setprecision(14)<<cwave[i]<<"\t"<<cintens[i]<<endl;
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

//********************************
// bin data
//********************************
void Crop::on_pushButton_3_clicked()
{
    if(ui->spinBox_3->value()==0 or ui->spinBox_3->value()==1){
        QMessageBox::information(this, "Nothing to do.", "Specify binning > 1.");
        return;
    }

    this->setCursor(QCursor(Qt::WaitCursor));

    double wlow=ui->doubleSpinBox->value();
    double wupp=ui->doubleSpinBox_2->value();

    int min=ui->spinBox->value();
    int max=ui->spinBox_2->value();
    int numpix=0;

    QString qCrPath = ui->lineEdit_7->text();
    string crPath = qCrPath.toUtf8().constData();

    QString Qext=ui->lineEdit_2->text();
    string ext = Qext.toUtf8().constData();

    QString Qext2=ui->lineEdit_8->text();
    string ext2 = Qext2.toUtf8().constData();

    if(ui->comboBox->currentIndex()==0){

        for(int i =min; i<=max; i++){

            qApp->processEvents(QEventLoop::AllEvents);
            if(abcrop==1){
                abcrop=0;
                return;
            }

            QString inputA=ui->lineEdit->text();
            string dataA = inputA.toUtf8().constData();
            std::ostringstream datANameStream(dataA);
            datANameStream<<crPath<<"/"<<dataA<<i<<"."<<ext;
            std::string datAName = datANameStream.str();

            QFile checkfile1(datAName.c_str());

            if(!checkfile1.exists()){
                QMessageBox::information(this, "Error", "File"+checkfile1.fileName()+" does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
                return;
            }
            ifstream inA(datAName.c_str());

            string line, eins, zwei;

            while(std::getline(inA, line))
                ++numpix;

            inA.clear();
            inA.seekg(0, ios::beg);

            QVector<double> a(numpix), b(numpix);

            QString output=ui->lineEdit_6->text();
            string out = output.toUtf8().constData();
            std::ostringstream outNameStream(out);
            outNameStream<<crPath<<"/"<<out<<i<<"."<<ext2;
            std::string outName = outNameStream.str();

            for(int g=0; g<numpix; g++){
                inA >> eins >>zwei;
                istringstream ist(eins);
                ist >> a[g];
                istringstream ist2(zwei);
                ist2 >> b[g];
            }

            double binint=0, biniwa=0;
            double binst=ui->spinBox_3->value();

            ofstream outp(outName.c_str());

            for(int g =0; g<numpix-(binst-1); g++){
                for(int i=0; i<binst; i++){
                    biniwa+=a[g+i];
                    binint+=b[g+i];
                }
                g=g+binst-1;
                binint=binint/binst;
                biniwa=biniwa/binst;
                if(ui->checkBox->isChecked()){
                    if((a[g]>=wlow) & (a[g]<=wupp)){
                        outp<<setprecision(14)<<biniwa<<"\t"<<binint<<endl;
                    }
                    else{
                        //
                    }
                }
                else{
                    outp<<setprecision(14)<<biniwa<<"\t"<<binint<<endl;
                }
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

            qApp->processEvents(QEventLoop::AllEvents);
            if(abcrop==1){
                abcrop=0;
                return;
            }

            QString input=ui->lineEdit->text();
            string data = input.toUtf8().constData();
            std::ostringstream datNameStream(data);
            datNameStream<<crPath<<"/"<<data<<i<<"."<<ext;
            std::string datName = datNameStream.str();

            QFile checkfile1(datName.c_str());

            if(!checkfile1.exists()){
                QMessageBox::information(this, "Error1 ", "Error 1: Spectrum "+checkfile1.fileName()+" does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
                return;
            }

            QString output=ui->lineEdit_6->text();
            string out = output.toUtf8().constData();
            std::ostringstream outNameStream(out);
            outNameStream<<crPath<<"/"<<out<<i<<"."<<ext2;
            std::string outName = outNameStream.str();

            CCfits::FITS::setVerboseMode(true);

            try
            {
                QString qExtension=ui->lineEdit_4->text();
                string Extension = qExtension.toUtf8().constData();
                QString qWavecol=ui->lineEdit_3->text();
                string Wavecol = qWavecol.toUtf8().constData();
                QString qIntenscol=ui->lineEdit_5->text();
                string Intenscol = qIntenscol.toUtf8().constData();

                //open file for reading
                shared_ptr<CCfits::FITS> input_file(new CCfits::FITS(datName.c_str(),CCfits::Read,true));

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

                ofstream outp(outName.c_str());

                for(int g =0; g<numpix-(binst-1); g++){
                    for(int i=0; i<binst; i++){
                        biniwa+=cwave[g+i];
                        binint+=cintens[g+i];
                    }
                    g=g+binst-1;
                    binint=binint/binst;
                    biniwa=biniwa/binst;
                    outp<<setprecision(14)<<biniwa<<"\t"<<binint<<endl;
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


void Crop::on_pushButton_4_clicked()
{
    abcrop=1;
}
