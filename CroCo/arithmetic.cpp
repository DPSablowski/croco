#include "arithmetic.h"
#include "ui_arithmetic.h"
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <QMessageBox>
#include <QFile>
#include <iostream>
#include <iomanip>

using namespace std;

QString qAPath;
string aPath;
double lspeed = 299792.458;

Arithmetic::Arithmetic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Arithmetic)
{
    ui->setupUi(this);

    this->setWindowTitle("Arithmetic");

    ui->label_9->setText(QString::fromUtf8("\u03BB<sub>0"));
    ui->label_10->setText(QString::fromUtf8("\u03BB<sub>A"));
    ui->label_11->setText(QString::fromUtf8("\u03BB<sub>B"));

    ui->lineEdit->setText("Hb_vel_1.txt");
    ui->lineEdit_2->setText("Hb_vel_2.txt");
    ui->lineEdit_7->setText("4861.327");
    ui->lineEdit_12->setText("Hb_vel_shift_1.txt");
    ui->lineEdit_13->setText("Hb_vel_shift_2.txt");
    ui->lineEdit_11->setText("rein_vel_shift_times.dat");
    ui->lineEdit_10->setText("rein_vel_times.dat");


}

Arithmetic::~Arithmetic()
{
    delete ui;
}

void Arithmetic::seData(QString str1, QString str2, QString str3)
{
    ui->lineEdit_4->setText(str1);
    qAPath=ui->lineEdit_4->text();
    aPath = qAPath.toUtf8().constData();

    ui->lineEdit->setText(str2);
    ui->lineEdit_6->setText(str3);

}

//**********************************
// Button Do
//**********************************
void Arithmetic::on_pushButton_2_clicked()
{

    this->setCursor(QCursor(Qt::WaitCursor));

    // Sequence
    if(ui->checkBox_7->isChecked()){

        QString qValue = ui->lineEdit_5->text();
        bool ok = false;
        double value = qValue.toDouble(&ok);

        QString inputA=ui->lineEdit->text();
        string dataA = inputA.toUtf8().constData();

        QString qExt=ui->lineEdit_6->text();
        string ext = qExt.toUtf8().constData();

        QString output=ui->lineEdit_3->text();
        string out = output.toUtf8().constData();

        int minf = ui->spinBox->value();
        int maxf = ui->spinBox_2->value();

        for(int i = 0; i<maxf-minf+1; i++){

            std::ostringstream datANameStream(dataA);
            datANameStream<<aPath<<"/"<<dataA<<minf+i<<ext;
            std::string datAName = datANameStream.str();
            ifstream inA(datAName.c_str());

            QFile checkfile1(datAName.c_str());

            if(!checkfile1.exists()){
                QMessageBox::information(this, "Error", "File"+qAPath+"/"+inputA+" does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }

            int numpixA=0;

            string line, eins, zwei;

            while(std::getline(inA, line))
               ++numpixA;

            inA.clear();
            inA.seekg(0, ios::beg);

            QVector<double> a(numpixA), b(numpixA);

            std::ostringstream outNameStream(out);
            outNameStream<<aPath<<"/"<<out<<minf+i<<ext;
            std::string outName = outNameStream.str();
            ofstream outp(outName.c_str());

            for(int g=0; g<numpixA; g++){
            inA >> eins >>zwei;
            istringstream ist(eins);
            ist >> a[g];
            if(ui->checkBox_10->isChecked()){
                a[g]=a[g]*(1+ui->doubleSpinBox->value()/lspeed);
            }
            else{

            }
            istringstream ist2(zwei);
            ist2 >> b[g];
            // Add
            if(ui->checkBox_5->isChecked()){
                b[g] = b[g]+value;
            }
            else{
                // Multiply
                if(ui->checkBox_6->isChecked()){
                    b[g] = b[g]*value;
                }
                // no nothing
                else{
                    b[g] = b[g];
                }
            }

            outp<<setprecision(14)<<a[g]<<"\t"<<b[g]<<endl;
            }
            inA.close();

        }

    }

    else{
    QString inputA=ui->lineEdit->text();
    string dataA = inputA.toUtf8().constData();
    std::ostringstream datANameStream(dataA);
    datANameStream<<aPath<<"/"<<dataA;
    std::string datAName = datANameStream.str();

    QFile checkfile1(datAName.c_str());

    if(!checkfile1.exists()){
        QMessageBox::information(this, "Error", "File"+qAPath+"/"+inputA+" does not exist!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    ifstream inA(datAName.c_str());

    QString inputB=ui->lineEdit_2->text();
    string dataB = inputB.toUtf8().constData();
    std::ostringstream datBNameStream(dataB);
    datBNameStream<<aPath<<"/"<<dataB;
    std::string datBName = datBNameStream.str();

    QFile checkfile2(datBName.c_str());

    if(!checkfile2.exists()){
        QMessageBox::information(this, "Error", "File"+qAPath+"/"+inputB+" does not exist!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    ifstream inB(datBName.c_str());

    int numpixA=0;
    int numpixB=0;
    string line, eins, zwei;

    while(std::getline(inA, line))
       ++numpixA;

    inA.clear();
    inA.seekg(0, ios::beg);

    while(std::getline(inB, line))
       ++numpixB;

    inB.clear();
    inB.seekg(0, ios::beg);

    /*
    if(numpixA!=numpixB){
        QMessageBox::information(this, "Error", "Unequal length of data.");
        this->setCursor(QCursor(Qt::ArrowCursor));
        return;
    }*/

    QVector<double> a(numpixA), b(numpixA), c(numpixB), d(numpixB), e(numpixA), f(numpixA);

    for(int g=0; g<numpixA; g++){
    inA >> eins >>zwei;
    istringstream ist(eins);
    ist >> a[g];
    if(ui->checkBox_10->isChecked()){
        a[g]=a[g]*(1+ui->doubleSpinBox->value()/lspeed);
    }
    e[g]=a[g];
    istringstream ist2(zwei);
    ist2 >> b[g];
    }

    inA.close();

    for(int g=0; g<numpixB; g++){
    inB >> eins >>zwei;
    istringstream ist3(eins);
    ist3 >> c[g];
    if(ui->checkBox_11->isChecked()){
        c[g]=c[g]*(1+ui->doubleSpinBox_2->value()/lspeed);
    }
    istringstream ist4(zwei);
    ist4 >> d[g];
    }

    QString output=ui->lineEdit_3->text();
    string out = output.toUtf8().constData();
    std::ostringstream outNameStream(out);
    outNameStream<<aPath<<"/"<<out;
    std::string outName = outNameStream.str();
    ofstream outp(outName.c_str());

    int aa=0;
    double dinter=0;

        for(int g=0; g<numpixA; g++){
            for(int i=0; i<numpixB; i++){
                if(c[i]<=a[g] & (c[i+1]>a[g])){
                    dinter=d[i]+(e[g]-c[i])/(c[i+1]-c[i])*(d[i+1]-d[i]);
                    //aa=i-1;
                }
            }

            if(ui->checkBox->isChecked()){
                f[g]=b[g]+dinter;
            }
            if(ui->checkBox_2->isChecked()){
                f[g]=b[g]-dinter;
            }
            if(ui->checkBox_3->isChecked()){
                f[g]=b[g]*dinter;
            }
            if(ui->checkBox_4->isChecked()){
                f[g]=b[g]/dinter;
            }
            if(ui->checkBox_5->isChecked()){
                QString qValue = ui->lineEdit_5->text();
                bool ok = false;
                double value = qValue.toDouble(&ok);
                f[g]=b[g]+value;
            }
            if(ui->checkBox_6->isChecked()){
                QString qValue = ui->lineEdit_5->text();
                bool ok = false;
                double value = qValue.toDouble(&ok);
                f[g]=b[g]*value;
            }
            if(ui->checkBox_8->isChecked()){
                e[g]=log10(a[g]);
                f[g] = b[g];
            }
            if(ui->checkBox_9->isChecked()){
                e[g]=pow(10,a[g]);
                f[g] = b[g];
            }
            outp<<scientific<<e[g]<<" "<<f[g]<<endl;
        }
    }


    this->setCursor(QCursor(Qt::ArrowCursor));

}

void Arithmetic::on_lineEdit_4_textChanged()
{
    qAPath=ui->lineEdit_4->text();
    aPath = qAPath.toUtf8().constData();
}

void Arithmetic::on_checkBox_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->checkBox_9->setChecked(false);
    ui->checkBox_8->setChecked(false);
}

void Arithmetic::on_checkBox_2_clicked()
{
    ui->checkBox->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->checkBox_9->setChecked(false);
    ui->checkBox_8->setChecked(false);
}

void Arithmetic::on_checkBox_3_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->checkBox_9->setChecked(false);
    ui->checkBox_8->setChecked(false);
}

void Arithmetic::on_checkBox_4_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->checkBox_9->setChecked(false);
    ui->checkBox_8->setChecked(false);
}

void Arithmetic::on_checkBox_5_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->checkBox_9->setChecked(false);
    ui->checkBox_8->setChecked(false);
}

void Arithmetic::on_checkBox_6_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_7->setChecked(false);
    ui->checkBox_8->setChecked(false);
}


void Arithmetic::on_checkBox_8_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_9->setChecked(false);
    ui->checkBox_6->setChecked(false);
}

void Arithmetic::on_checkBox_9_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->checkBox_8->setChecked(false);
}

void Arithmetic::on_lineEdit_8_editingFinished()
{
    double L0 = ui->lineEdit_7->text().toDouble();
    double L1 = ui->lineEdit_8->text().toDouble();
    double val = (L1-L0)/L0*lspeed;

    ui->doubleSpinBox->setValue(val);
}

void Arithmetic::on_lineEdit_9_editingFinished()
{
    double L0 = ui->lineEdit_7->text().toDouble();
    double L2 = ui->lineEdit_9->text().toDouble();
    double val = (L2-L0)/L0*lspeed;

    ui->doubleSpinBox_2->setValue(val);
}


//*********************************
// Shift
//*********************************
void Arithmetic::on_pushButton_3_clicked()
{

    // Shift A
    if(ui->checkBox_12->isChecked()){

        double vshi=ui->doubleSpinBox->value();
        if(ui->checkBox_15->isChecked()){
            vshi = -vshi;
        }

        QString inputA=ui->lineEdit->text();
        string dataA = inputA.toUtf8().constData();
        std::ostringstream datANameStream(dataA);
        datANameStream<<aPath<<"/"<<dataA;
        std::string datAName = datANameStream.str();

        QFile checkfile1(datAName.c_str());

        if(!checkfile1.exists()){
            QMessageBox::information(this, "Error", "File"+qAPath+"/"+inputA+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }
        ifstream inA(datAName.c_str());

        int numpixA=0;

        string line, eins, zwei;

        while(std::getline(inA, line))
           ++numpixA;

        inA.clear();
        inA.seekg(0, ios::beg);


        QVector<double> a(numpixA), b(numpixA);

        QString output=ui->lineEdit_12->text();
        string out = output.toUtf8().constData();
        std::ostringstream outNameStream(out);
        outNameStream<<aPath<<"/"<<out;
        std::string outName = outNameStream.str();
        ofstream outp(outName.c_str());

        for(int g=0; g<numpixA; g++){
        inA >> eins >>zwei;
        istringstream ist(eins);
        ist >> a[g];
            a[g]=a[g]*(1+vshi/lspeed);
            istringstream istr1(zwei);
            istr1 >> b[g];
            outp<<setprecision(14)<<a[g]<<"\t"<<b[g]<<endl;
        }


    }
    else{

    }

    // Shift B
    if(ui->checkBox_13->isChecked()){

        double vshi=ui->doubleSpinBox_2->value();
        if(ui->checkBox_15->isChecked()){
            vshi = -vshi;
        }

        QString inputA=ui->lineEdit_2->text();
        string dataA = inputA.toUtf8().constData();
        std::ostringstream datANameStream(dataA);
        datANameStream<<aPath<<"/"<<dataA;
        std::string datAName = datANameStream.str();

        QFile checkfile1(datAName.c_str());

        if(!checkfile1.exists()){
            QMessageBox::information(this, "Error", "File"+qAPath+"/"+inputA+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }
        ifstream inA(datAName.c_str());

        int numpixA=0;

        string line, eins, zwei;

        while(std::getline(inA, line))
           ++numpixA;

        inA.clear();
        inA.seekg(0, ios::beg);


        QVector<double> a(numpixA), b(numpixA);

        QString output=ui->lineEdit_13->text();
        string out = output.toUtf8().constData();
        std::ostringstream outNameStream(out);
        outNameStream<<aPath<<"/"<<out;
        std::string outName = outNameStream.str();
        ofstream outp(outName.c_str());

        for(int g=0; g<numpixA; g++){
        inA >> eins >>zwei;
        istringstream ist(eins);
        ist >> a[g];
            a[g]=a[g]*(1+vshi/lspeed);
            istringstream istr1(zwei);
            istr1 >> b[g];
            outp<<setprecision(14)<<a[g]<<"\t"<<b[g]<<endl;
        }

    }
    else{

    }

    // correct velocities
    if(ui->checkBox_14->isChecked()){

        double vshiA=ui->doubleSpinBox->value();
        if(ui->checkBox_15->isChecked()){
            vshiA = -vshiA;
        }
        double vshiB=ui->doubleSpinBox_2->value();
        if(ui->checkBox_15->isChecked()){
            vshiB = -vshiB;
        }


        QString inputA=ui->lineEdit_10->text();
        string dataA = inputA.toUtf8().constData();
        std::ostringstream datANameStream(dataA);
        datANameStream<<aPath<<"/"<<dataA;
        std::string datAName = datANameStream.str();

        QFile checkfile1(datAName.c_str());

        if(!checkfile1.exists()){
            QMessageBox::information(this, "Error", "File"+qAPath+"/"+inputA+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }
        ifstream inA(datAName.c_str());

        int numpixA=0;

        string line, eins, zwei, drei;

        while(std::getline(inA, line))
           ++numpixA;

        inA.clear();
        inA.seekg(0, ios::beg);

        QString output=ui->lineEdit_11->text();
        string out = output.toUtf8().constData();
        std::ostringstream outNameStream(out);
        outNameStream<<aPath<<"/"<<out;
        std::string outName = outNameStream.str();
        ofstream outp(outName.c_str());

        double velA=0.0, velB=0.0, tim=0.0;

        for(int i =0; i< numpixA; i++){
            inA >> eins >> zwei >> drei;
            istringstream str1(eins);
            str1 >> tim;
            istringstream str2(zwei);
            str2 >> velA;
            velA = velA+vshiA;
            istringstream str3(drei);
            str3 >> velB;
            velB = velB+vshiB;
            outp<<setprecision(14)<<tim<<"\t"<<velA<<"\t"<<velB<<endl;
        }
    }
}

//***********************************
// normalize by two points
//***********************************
void Arithmetic::on_pushButton_4_clicked()
{
    // Sequence
    if(ui->checkBox_7->isChecked()){

        QString inputA=ui->lineEdit->text();
        string dataA = inputA.toUtf8().constData();

        QString qExt=ui->lineEdit_6->text();
        string ext = qExt.toUtf8().constData();

        QString output=ui->lineEdit_3->text();
        string out = output.toUtf8().constData();

        double left=ui->lineEdit_14->text().toDouble();
        double right=ui->lineEdit_15->text().toDouble();
        double lave=0.0, rave=0.0;

        int minf = ui->spinBox->value();
        int maxf = ui->spinBox_2->value();

        for(int i=minf; i<maxf+1; i++){

            double dpll=ui->spinBox_3->value();
            double dplr=ui->spinBox_3->value();
            double dprl=ui->spinBox_3->value();
            double dprr=ui->spinBox_3->value();
            rave=0.0;
            lave=0.0;

            std::ostringstream datANameStream(dataA);
            datANameStream<<aPath<<"/"<<dataA<<minf+i<<ext;
            std::string datAName = datANameStream.str();

            QFile checkfile1(datAName.c_str());

            if(!checkfile1.exists()){
                QMessageBox::information(this, "Error", "File"+qAPath+"/"+inputA+" does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }
            ifstream inA(datAName.c_str());

            int numpixA=0;

            string line, eins, zwei;

            while(std::getline(inA, line))
               ++numpixA;

            inA.clear();
            inA.seekg(0, ios::beg);

            QVector<double> a(numpixA), b(numpixA);

            std::ostringstream outNameStream(out);
            outNameStream<<aPath<<"/"<<out<<minf+i<<ext;
            std::string outName = outNameStream.str();
            ofstream outp(outName.c_str());

            for(int g=0; g<numpixA; g++){
                inA >> eins >>zwei;
                istringstream ist(eins);
                ist >> a[g];
                istringstream ist2(zwei);
                ist2 >> b[g];
            }
            inA.close();

            int posl=0;
            int posr=0;

            for(int g=0; g<numpixA; g++){
                if((a[g]<=left) & (a[g+1]>=left)){
                    posl=g;
                    if(g<dpll){
                        dpll=g;
                    }
                    else{
                        if(g>numpixA-dplr){
                            dplr=numpixA-g-1;
                        }
                    }
                    //g=numpixA;
                }
                else{
                    if((a[g]<=right) & (a[g+1]>=right)){
                        posr=g;
                        if(g<dprl){
                            dprl=g;
                        }
                        else{
                            if(g>numpixA-dprr){
                                dprr=numpixA-g-1;
                            }
                        }
                    }
                    else{

                    }
                }
            }


            for(int g=0; g<=dpll+dplr; g++){
                lave+=b[posl-dplr+g];
            }
            for(int g=0; g<=dprl+dprr; g++){
                rave+=b[posr-dprr+g];
            }
            lave=lave/(dpll+dplr+1);
            rave=rave/(dprl+dprr+1);

            double m=(rave-lave)/(a[posr]-a[posl]);
            double k=rave-m*a[posr];

            cout<<rave<<"\t"<<lave<<"\t"<<m<<"\t"<<k<<endl;

            for(int g=0; g<numpixA; g++){
                b[g]=b[g]/(m*a[g]+k);
                outp<<setprecision(14)<<a[g]<<"\t"<<b[g]<<endl;
            }
            outp.close();

        }
    }

    // single spectrum
    else{

    }
}
