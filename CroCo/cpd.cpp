#include "cpd.h"
#include "ui_cpd.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <QMessageBox>
#include <QFile>
#include <QtDebug>


using namespace std;

QString qCPDPath, qCPDExt;
string CPDPath, CPDExt;

CPD::CPD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CPD)
{
    ui->setupUi(this);

    this->setWindowTitle("Continuum Point Definition");

    ui->checkBox_2->setEnabled(false);
    ui->checkBox_3->setEnabled(false);

    ui->lineEdit_5->setText("/home/daniels/Observations/Tomer/Added/Disentangled");
    ui->lineEdit->setText("bin_");
    ui->lineEdit_2->setText(".txt");
    ui->lineEdit_3->setText("binc_");
    ui->lineEdit_4->setText("velocities.dat");

    qCPDPath = ui->lineEdit_5->text();
    CPDPath = qCPDPath.toUtf8().constData();

}

CPD::~CPD()
{
    delete ui;
}

void CPD::seData(QString str1, QString str2, QString str3)
{
    ui->lineEdit_5->setText(str1);
    qCPDPath=ui->lineEdit_5->text();
    CPDPath = qCPDPath.toUtf8().constData();

    ui->lineEdit->setText(str2);
    ui->lineEdit_2->setText(str3);

}


void CPD::on_pushButton_2_clicked()
{
    string line;

    this->setCursor(QCursor(Qt::WaitCursor));
    int min = ui->spinBox->value();
    int max = ui->spinBox_2->value();

    int Nspec = max - min + 1;

    int Nwin=0, num_lines=0;

    double wp1l, wp1r, wp2l, wp2r, wp3l, wp3r, ws1l, ws1r, ws2l, ws2r, ws3l, ws3r, vp1, vp2, vp3, vs1, vs2, vs3, wp1l0, wp1r0, wp2l0, wp2r0, wp3l0, wp3r0, ws1l0, ws1r0, ws2l0, ws2r0, ws3l0, ws3r0;
    QVector<double> RVp(Nspec), RVs(Nspec);
    const double light =  299792.458;
    string eins, zwei, cline;

    if(ui->checkBox->isChecked()){
        Nwin=1;
        if(ui->checkBox_2->isChecked()){
            Nwin=2;
            if(ui->checkBox_3->isChecked()){
                Nwin=3;
            }
        }
    }
    else{
        QMessageBox::information(this, "Error", "Select an speficy at least window 1.");
         this->setCursor(QCursor(Qt::ArrowCursor));
        return;
    }

    qCPDExt = ui->lineEdit_2->text();
    CPDExt = qCPDExt.toUtf8().constData();

    wp1l0 = ui->doubleSpinBox->value();
    wp1r0 = ui->doubleSpinBox_2->value();
    wp2l0 = ui->doubleSpinBox_3->value();
    wp2r0 = ui->doubleSpinBox_4->value();
    wp3l0 = ui->doubleSpinBox_5->value();
    wp3r0 = ui->doubleSpinBox_6->value();

    ws1l0 = ui->doubleSpinBox_7->value();
    ws1r0 = ui->doubleSpinBox_8->value();
    ws2l0 = ui->doubleSpinBox_9->value();
    ws2r0 = ui->doubleSpinBox_10->value();
    ws3l0 = ui->doubleSpinBox_11->value();
    ws3r0 = ui->doubleSpinBox_12->value();

    vp1 = ui->doubleSpinBox_13->value();
    vp2 = ui->doubleSpinBox_14->value();
    vp3 = ui->doubleSpinBox_15->value();

    vs1 = ui->doubleSpinBox_16->value();
    vs2 = ui->doubleSpinBox_17->value();
    vs3 = ui->doubleSpinBox_18->value();

    //read RV datan

        QString input=ui->lineEdit_4->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<CPDPath<<"/"<<data;
        std::string datName = datNameStream.str();

        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            QMessageBox::information(this, "Error", "The file "+checkfile.fileName()+" does note exist.");
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }

        ifstream dat(datName.c_str());

        int bini=0;

        while(std::getline(dat, cline))
           ++ bini;

        dat.clear();
        dat.seekg(0, ios::beg);

        if(bini!=Nspec){
            QMessageBox::information(this, "Error", "The specified number of spectra does not match to the number of given RVs in the RV-file.");
             this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }

        for(int i =0; i<Nspec; i++){
            dat >> eins>>zwei;
            istringstream str(eins);
            str >> RVp[i];
            istringstream str1(zwei);
            str1 >> RVs[i];
        }



    // Modify spectra
    for(int i = 0; i<Nspec; i++){

        QString output=ui->lineEdit_3->text();
        string data3 = output.toUtf8().constData();
        std::ostringstream dat3NameStream(data3);
        dat3NameStream<<CPDPath<<"/"<<data3<<min+i<<CPDExt;
        std::string dat3Name = dat3NameStream.str();
        ofstream dat3(dat3Name.c_str());

        //One Window
        if(Nwin==1){

            wp1l=wp1l0*(1+RVp[i]/light);
            wp1r=wp1r0*(1+RVp[i]/light);
            ws1l=ws1l0*(1+RVs[i]/light);
            ws1r=ws1r0*(1+RVs[i]/light);

            QString input2=ui->lineEdit->text();
            string data2 = input2.toUtf8().constData();
            std::ostringstream dat2NameStream(data2);
            dat2NameStream<<CPDPath<<"/"<<data2<<min+i<<CPDExt;
            std::string dat2Name = dat2NameStream.str();

            QFile checkfile2(dat2Name.c_str());

            if(!checkfile2.exists()){
                QMessageBox::information(this, "Error", "The file "+checkfile2.fileName()+" does note exist.");
                this->setCursor(QCursor(Qt::ArrowCursor));
                return;
            }

            ifstream dat2(dat2Name.c_str());


            while(std::getline(dat2, cline))
               ++num_lines;

            dat2.clear();
            dat2.seekg(0, ios::beg);

            QVector<double> Wavel(num_lines), Intensi(num_lines);

            for(int i=0; i<num_lines;i++){
                dat2 >> eins >> zwei;
                istringstream str2(eins);
                str2 >> Wavel[i];
                istringstream str3(zwei);
                str3 >> Intensi[i];
                if((Wavel[i]>wp1l) & (Wavel[i]<wp1r)){
                    Intensi[i]=vp1;
                }
                if((Wavel[i]>ws1l) & (Wavel[i]<ws1r)){
                    Intensi[i]=vs1;
                }
                dat3<<Wavel[i]<<" "<<Intensi[i]<<endl;
            }
        }
        //Two Windows
        if(Nwin==2){

            wp1l=wp1l0*(1+RVp[i]/light);
            wp1r=wp1r0*(1+RVp[i]/light);
            wp2l=wp2l0*(1+RVp[i]/light);
            wp2r=wp2r0*(1+RVp[i]/light);
            ws1l=ws1l0*(1+RVs[i]/light);
            ws1r=ws1r0*(1+RVs[i]/light);
            ws2l=ws2l0*(1+RVs[i]/light);
            ws2r=ws2r0*(1+RVs[i]/light);

            QString input2=ui->lineEdit->text();
            string data2 = input2.toUtf8().constData();
            std::ostringstream dat2NameStream(data2);
            dat2NameStream<<CPDPath<<"/"<<data2<<min+i<<CPDExt;
            std::string dat2Name = dat2NameStream.str();

            QFile checkfile(dat2Name.c_str());

            if(!checkfile.exists()){
                QMessageBox::information(this, "Error", "The file "+checkfile.fileName()+" does note exist.");
                this->setCursor(QCursor(Qt::ArrowCursor));
                return;
            }

            ifstream dat2(dat2Name.c_str());


            while(std::getline(dat2, cline))
               ++ num_lines;

            dat2.clear();
            dat2.seekg(0, ios::beg);

            QVector<double> Wavel(num_lines), Intensi(num_lines);

            for(int i=0; i<num_lines;i++){
                dat2 >> eins >> zwei;
                istringstream str2(eins);
                str2 >> Wavel[i];
                istringstream str3(zwei);

                if((Wavel[i]>wp1l) & (Wavel[i]<wp1r)){
                    Intensi[i]=vp1;
                }
                else{
                    str3 >> Intensi[i];
                }
                if((Wavel[i]>wp2l) & (Wavel[i]<wp2r)){
                    Intensi[i]=vp2;
                }
                else{
                    str3 >> Intensi[i];
                }


                if((Wavel[i]>ws1l) & (Wavel[i]<ws1r)){
                    Intensi[i]=vs1;
                }
                else{
                    str3 >> Intensi[i];
                }
                if((Wavel[i]>ws2l) & (Wavel[i]<ws2r)){
                    Intensi[i]=vs2;
                }
                else{
                    str3 >> Intensi[i];
                }

                dat3<<Wavel[i]<<" "<<Intensi[i]<<endl;

            }

        }
        //Three Windows
        if(Nwin==3){

            wp1l=wp1l0*(1+RVp[i]/light);
            wp1r=wp1r0*(1+RVp[i]/light);
            ws2l=ws2l0*(1+RVs[i]/light);
            ws2r=ws2r0*(1+RVs[i]/light);
            wp1l=wp1l0*(1+RVp[i]/light);
            wp1r=wp1r0*(1+RVp[i]/light);
            ws2l=ws2l0*(1+RVs[i]/light);
            ws2r=ws2r0*(1+RVs[i]/light);
            wp3l=wp3l0*(1+RVp[i]/light);
            wp3r=wp3r0*(1+RVp[i]/light);
            ws3l=ws3l0*(1+RVs[i]/light);
            ws3r=ws3r0*(1+RVs[i]/light);

            QString input2=ui->lineEdit->text();
            string data2 = input2.toUtf8().constData();
            std::ostringstream dat2NameStream(data2);
            dat2NameStream<<CPDPath<<"/"<<data2<<min+i<<CPDExt;
            std::string dat2Name = dat2NameStream.str();

            QFile checkfile(dat2Name.c_str());

            if(!checkfile.exists()){
                QMessageBox::information(this, "Error", "The file "+checkfile.fileName()+" does note exist.");
                this->setCursor(QCursor(Qt::ArrowCursor));
                return;
            }

            ifstream dat2(dat2Name.c_str());


            while(std::getline(dat2, cline))
               ++ num_lines;

            dat2.clear();
            dat2.seekg(0, ios::beg);

            QVector<double> Wavel(num_lines), Intensi(num_lines);

            for(int i=0; i<num_lines;i++){
                dat2 >> eins >> zwei;
                istringstream str2(eins);
                str2 >> Wavel[i];
                istringstream str3(zwei);

                if((Wavel[i]>wp1l) & (Wavel[i]<wp1r)){
                    Intensi[i]=vp1;
                }
                else{
                    str3 >> Intensi[i];
                }
                if((Wavel[i]>wp2l) & (Wavel[i]<wp2r)){
                    Intensi[i]=vp2;
                }
                else{
                    str3 >> Intensi[i];
                }
                if((Wavel[i]>wp3l) & (Wavel[i]<wp3r)){
                    Intensi[i]=vp3;
                }
                else{
                    str3 >> Intensi[i];
                }

                if((Wavel[i]>ws1l) & (Wavel[i]<ws1r)){
                    Intensi[i]=vs1;
                }
                else{
                    str3 >> Intensi[i];
                }
                if((Wavel[i]>ws2l) & (Wavel[i]<ws2r)){
                    Intensi[i]=vs2;
                }
                else{
                    str3 >> Intensi[i];
                }
                if((Wavel[i]>ws3l) & (Wavel[i]<ws3r)){
                    Intensi[i]=vs3;
                }
                else{
                    str3 >> Intensi[i];
                }

                dat3<<Wavel[i]<<" "<<Intensi[i]<<endl;

            }

        }

    }

    this->setCursor(QCursor(Qt::ArrowCursor));
}

void CPD::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked()){

        ui->checkBox_2->setEnabled(true);

    }
    else{
        ui->checkBox_2->setChecked(false);
        ui->checkBox_2->setEnabled(false);
    }

}

void CPD::on_checkBox_2_clicked()
{
    if(ui->checkBox_2->isChecked()){

        ui->checkBox_3->setEnabled(true);

    }
    else{
        ui->checkBox_3->setChecked(false);
        ui->checkBox_3->setEnabled(false);
    }
}

void CPD::on_lineEdit_5_textChanged()
{
    qCPDPath = ui->lineEdit_5->text();
    CPDPath = qCPDPath.toUtf8().constData();
}

