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
    ui->lineEdit_6->setEnabled(false);
    ui->spinBox_2->setEnabled(false);


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
                QMessageBox::information(this, "Error", "File"+checkfile1.fileName()+" does not exist!");
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
        QMessageBox::information(this, "Error", "File"+checkfile1.fileName()+" does not exist!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    ifstream inA(datAName.c_str());

    QString inputB=ui->lineEdit_2->text();

    if(inputB.isEmpty()){
        if((ui->checkBox->isChecked()) or (ui->checkBox_2->isChecked()) or (ui->checkBox_3->isChecked()) or (ui->checkBox_4->isChecked())){
            QMessageBox::information(this, "Error", "There is no file B given.");
            return;
        }
        else{
            //
        }

    }
    else{
        //
    }

    string dataB = inputB.toUtf8().constData();
    std::ostringstream datBNameStream(dataB);
    datBNameStream<<aPath<<"/"<<dataB;
    std::string datBName = datBNameStream.str();

    QFile checkfile2(datBName.c_str());

    if(!checkfile2.exists()){
        QMessageBox::information(this, "Error", "File"+checkfile2.fileName()+" does not exist!");
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
        else{

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

if((ui->checkBox->isChecked()) or (ui->checkBox_2->isChecked()) or (ui->checkBox_3->isChecked()) or (ui->checkBox_4->isChecked())){
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
        else{
            for(int g=0; g<b.size(); g++){
                if(ui->checkBox_5->isChecked()){
                QString qValue = ui->lineEdit_5->text();
                bool ok = false;
                double value = qValue.toDouble(&ok);
                b[g]=b[g]+value;
            }
                if(ui->checkBox_6->isChecked()){
                    QString qValue = ui->lineEdit_5->text();
                    bool ok = false;
                    double value = qValue.toDouble(&ok);
                    b[g]=b[g]*value;
                }
                if(ui->checkBox_8->isChecked()){
                    a[g]=log10(a[g]);
                }
                if(ui->checkBox_9->isChecked()){
                    a[g]=pow(10,a[g]);
                }
                outp<<scientific<<a[g]<<" "<<b[g]<<endl;
            }
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

//************************************************
// Flux ratio changed, update continuum values
//************************************************
void Arithmetic::on_doubleSpinBox_3_valueChanged(const QString &arg1)
{
    double kAB = ui->doubleSpinBox_3->value();
    double fA = kAB/(1+kAB);
    double fB = 1/(1+kAB);

    ui->lineEdit_16->setText(QString::number(fA));
    ui->lineEdit_17->setText(QString::number(fB));
}

//****************************************
// Correct for flux ratio
//****************************************
void Arithmetic::on_pushButton_5_clicked()
{
    double kAB = ui->doubleSpinBox_3->value();
    double fA = kAB/(1+kAB);
    double fB = 1/(1+kAB);

    QString inputA=ui->lineEdit->text();
    string dataA = inputA.toUtf8().constData();
    std::ostringstream datANameStream(dataA);
    datANameStream<<aPath<<"/"<<dataA;
    std::string datAName = datANameStream.str();

    QFile checkfile1(datAName.c_str());

    if(!checkfile1.exists()){
        QMessageBox::information(this, "Error", "File"+checkfile1.fileName()+" does not exist!");
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
        QMessageBox::information(this, "Error", "File"+checkfile2.fileName()+" does not exist!");
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

    QVector<double> a(numpixA), b(numpixA), c(numpixB), d(numpixB);

    QString output=ui->lineEdit_12->text();
    string out = output.toUtf8().constData();
    std::ostringstream outNameStream(out);
    outNameStream<<aPath<<"/"<<out;
    std::string outName = outNameStream.str();
    ofstream outp(outName.c_str());

    QString output2=ui->lineEdit_13->text();
    string out2 = output2.toUtf8().constData();
    std::ostringstream out2NameStream(out2);
    out2NameStream<<aPath<<"/"<<out2;
    std::string out2Name = out2NameStream.str();
    ofstream outp2(out2Name.c_str());

    for(int g=0; g<numpixA; g++){
        inA >> eins >>zwei;
        istringstream ist(eins);
        ist >> a[g];
        istringstream ist2(zwei);
        ist2 >> b[g];
        b[g]=(0.5*b[g]+(fA-0.5))/fA;
        outp<<setprecision(14)<<a[g]<<"\t"<<b[g]<<endl;
    }

    inA.close();
    outp.close();

    for(int g=0; g<numpixB; g++){
        inB >> eins >>zwei;
        istringstream ist3(eins);
        ist3 >> c[g];
        istringstream ist4(zwei);
        ist4 >> d[g];
        d[g]=(0.5*d[g]+(fB-0.5))/fB;
        outp2<<setprecision(14)<<c[g]<<"\t"<<d[g]<<endl;
    }
    inB.close();
    outp2.close();

}

//***********************************
// Help button
//***********************************
void Arithmetic::on_pushButton_6_clicked()
{
    QMessageBox::information(this, "Help", "This windows allowes arithmetic manipulation of 1d spectra in ASCII format.\n"
                                           "Specify the name of output on line 4. The sequence check box works only on spectrum A. Pushing Do will execute arithmetic on these files\n"
                                           "Add Error Column will add a third column to the file given in A and write to file given in line editor next to the Add Error Column push button."
                                           "Shift will shift the spectra A or/and B by the values given by the double spin boxes top right. They can be computed by specifying a wavelength 0 and the wavelengths A and/orB of that line within the files\n"
                                           "Normalize is a two point normalization which can be used to force a line within a sequence of spectra on the same continuum.\n"
                                           "Correct Flux allowes to correct component spectra from disentangling to a given flux ratio. We assume spectra normalized to 1 with an initial specified flux ratio of 1.");
}

// sequnce
void Arithmetic::on_checkBox_7_clicked()
{
    if(ui->checkBox_7->isChecked()){
        ui->lineEdit_6->setEnabled(true);
        ui->spinBox_2->setEnabled(true);
    }
    else{
        ui->lineEdit_6->setEnabled(false);
        ui->spinBox_2->setEnabled(false);
    }
}

//*****************************************************
// add error column to file and add header for iSpec
//*****************************************************
void Arithmetic::on_pushButton_7_clicked()
{
    double errora = ui->doubleSpinBox_4->value();

    QString inputA=ui->lineEdit->text();
    string dataA = inputA.toUtf8().constData();
    std::ostringstream datANameStream(dataA);
    datANameStream<<aPath<<"/"<<dataA;
    std::string datAName = datANameStream.str();

    QFile checkfile1(datAName.c_str());

    if(!checkfile1.exists()){
        QMessageBox::information(this, "Error", "File"+checkfile1.fileName()+" does not exist!");
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

    QString output2=ui->lineEdit_18->text();
    string out2 = output2.toUtf8().constData();
    std::ostringstream out2NameStream(out2);
    out2NameStream<<aPath<<"/"<<out2;
    std::string out2Name = out2NameStream.str();
    ofstream outp2(out2Name.c_str());

    if(ui->checkBox_16->isChecked()){
        outp2<<"waveobs\tflux\terr"<<endl;
    }
    else{
        //
    }
    for(int g=0; g<numpixA; g++){
        inA >> eins >>zwei;
        istringstream ist(eins);
        ist >> a[g];
        if(ui->checkBox_17->isChecked()){
            a[g]=a[g]/10;
        }
        istringstream ist2(zwei);
        ist2 >> b[g];
        outp2<<setprecision(14)<<a[g]<<"\t"<<b[g]<<"\t"<<errora<<endl;
    }
    outp2.close();
    inA.close();
}
