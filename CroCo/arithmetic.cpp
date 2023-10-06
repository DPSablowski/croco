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
#include <QDebug>
#include <CCfits/CCfits>

using namespace std;

QString qAPath;
string aPath;
double lspeed = 299792.458;
QVector<double> lwaves(1), arrangea(1), arrangeb(1);
int arabor=0;

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

    ui->lineEdit_20->setText("4943");
    ui->lineEdit_21->setText("5694");
    ui->lineEdit_22->setText("1.04782");

    ui->comboBox_2->addItem("ASCII");
    ui->comboBox_2->addItem("fits");

    string sbin = "SpectralLines.dat";

    QFile qBin(sbin.c_str());

    if(!qBin.exists()){
        qDebug()<<"No data base file of spectral lines not present.";
        QMessageBox::information(this, "Error", "Data base "+qBin.fileName()+" of spectral lines not present.");
    }


    else{
        ifstream slines(sbin.c_str());
        int lines=0;
        string zeile1, eins1, zwei1;

        while(std::getline(slines, zeile1))
        ++ lines;

        slines.clear();
        slines.seekg(0, ios::beg);

        QVector<string> names(lines);

        lwaves.resize(lines);

        for(int i=0; i < lines; i++){
            slines >> eins1 >> zwei1;
            istringstream str1(eins1);
            str1 >> names[i];
            QString qstr = QString::fromStdString(str1.str());
            ui->comboBox->addItem(qstr);
            istringstream str2(zwei1);
            str2 >> lwaves[i];
        }
        ui->lineEdit_7->setText(QString::number(lwaves[0]));
    }


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
            datANameStream<<aPath<<"/"<<dataA<<minf+i<<"."<<ext;
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
            outNameStream<<aPath<<"/"<<out<<minf+i<<"."<<ext;
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

if((ui->checkBox->isChecked()) or (ui->checkBox_2->isChecked()) or (ui->checkBox_3->isChecked()) or (ui->checkBox_4->isChecked()) or (ui->checkBox_18->isChecked())){
    double dinter=0.0;
    double resi=0.0;
    double residuum=0.0;
    double wmin = ui->doubleSpinBox_5->value();
    double wmax = ui->doubleSpinBox_6->value();
    int wcount=0;

        for(int g=0; g<numpixA; g++){
            for(int i=0; i<numpixB; i++){
                if((c[i]<=a[g]) & (c[i+1]>=a[g])){
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
            if(ui->checkBox_18->isChecked()){  // residuum
                if(a[g]>=wmin & a[g]<=wmax){
                    resi=(b[g]-dinter);
                    residuum += pow(resi,2);
                    cout<<g<<"\t"<<b[g]<<"\t"<<resi<<"\t"<<residuum<<"\t"<<wcount<<endl;
                    ++wcount;
                }
                else{

                }
            }
            if(ui->checkBox_18->isChecked()){
                //
            }
            else{
                outp<<scientific<<e[g]<<" "<<f[g]<<endl;
            }
        }
        if(ui->checkBox_18->isChecked()){
            residuum = sqrt(residuum/(wcount-1));
            ui->lineEdit_19->setText(QString::number(residuum));
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
    ui->checkBox_18->setChecked(false);
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
    ui->checkBox_18->setChecked(false);
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
    ui->checkBox_18->setChecked(false);
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
    ui->checkBox_18->setChecked(false);
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
    ui->checkBox_18->setChecked(false);
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
    ui->checkBox_18->setChecked(false);
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
    ui->checkBox_18->setChecked(false);
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
    ui->checkBox_18->setChecked(false);
}

void Arithmetic::on_checkBox_18_clicked()
{
    if(ui->checkBox_18->isChecked()){
        ui->checkBox_2->setChecked(false);
        ui->checkBox_3->setChecked(false);
        ui->checkBox->setChecked(false);
        ui->checkBox_4->setChecked(false);
        ui->checkBox_5->setChecked(false);
        ui->checkBox_6->setChecked(false);
        ui->checkBox_8->setChecked(false);
        ui->checkBox_9->setChecked(false);
    }
    else{
        ui->checkBox_2->setChecked(false);
        ui->checkBox_3->setChecked(false);
        ui->checkBox->setChecked(true);
        ui->checkBox_4->setChecked(false);
        ui->checkBox_5->setChecked(false);
        ui->checkBox_6->setChecked(false);
        ui->checkBox_8->setChecked(false);
        ui->checkBox_9->setChecked(false);
    }
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

    // Sequence
    if(ui->checkBox_7->isChecked()){

        for(int i=minf; i<maxf+1; i++){

            double dpll=ui->spinBox_3->value();
            double dplr=ui->spinBox_3->value();
            double dprl=ui->spinBox_3->value();
            double dprr=ui->spinBox_3->value();
            rave=0.0;
            lave=0.0;

            std::ostringstream datANameStream(dataA);
            datANameStream<<aPath<<"/"<<dataA<<minf+i<<"."<<ext;
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
            outNameStream<<aPath<<"/"<<out<<minf+i<<"."<<ext;
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
        double dpll=ui->spinBox_3->value();
        double dplr=ui->spinBox_3->value();
        double dprl=ui->spinBox_3->value();
        double dprr=ui->spinBox_3->value();
        rave=0.0;
        lave=0.0;

        std::ostringstream datANameStream(dataA);
        datANameStream<<aPath<<"/"<<dataA<<"."<<ext;
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

        for(int g=0; g<numpixA; g++){
            inA >> eins >>zwei;
            istringstream ist(eins);
            ist >> a[g];
            istringstream ist2(zwei);
            ist2 >> b[g];
        }
        inA.close();

        std::ostringstream outNameStream(out);
        outNameStream<<aPath<<"/"<<out<<"."<<ext;
        std::string outName = outNameStream.str();
        ofstream outp(outName.c_str());

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

//************************************************
// Flux ratio changed, update continuum values
//************************************************
void Arithmetic::on_doubleSpinBox_3_valueChanged()
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
    QMessageBox::information(this, "Help", "This window allowes arithmetic manipulation of 1d spectra in ASCII format.\n"
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


void Arithmetic::on_comboBox_currentIndexChanged()
{
    ui->lineEdit_7->setText(QString::number(lwaves[ui->comboBox->currentIndex()]));
}

//*****************************************
// correct flux wavelength dependent
//*****************************************
void Arithmetic::on_pushButton_8_clicked()
{
    double TA = ui->lineEdit_20->text().toDouble();
    double TB = ui->lineEdit_21->text().toDouble();
    double scale = ui->lineEdit_22->text().toDouble();
    double kB = 1.380648e-23;
    double c0=299792458;
    double h = 6.626e-34;

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

    int numpixA=0;
    string line, eins, zwei, drei;

    while(std::getline(inA, line))
       ++numpixA;

    inA.clear();
    inA.seekg(0, ios::beg);

    QString output=ui->lineEdit_3->text();
    string out = output.toUtf8().constData();
    std::ostringstream outNameStream(out);
    outNameStream<<aPath<<"/"<<out;
    std::string outName = outNameStream.str();
    ofstream outp(outName.c_str());


    string out2 = "ratioAtoB.dat";
    std::ostringstream out2NameStream(out2);
    out2NameStream<<aPath<<"/"<<out2;
    std::string out2Name = out2NameStream.str();
    ofstream out2p(out2Name.c_str());

    string out3 = "strengthA.dat";
    std::ostringstream out3NameStream(out3);
    out3NameStream<<aPath<<"/"<<out3;
    std::string out3Name = out3NameStream.str();
    ofstream out3p(out3Name.c_str());

    string out4 = "strengthB.dat";
    std::ostringstream out4NameStream(out4);
    out4NameStream<<aPath<<"/"<<out4;
    std::string out4Name = out4NameStream.str();
    ofstream out4p(out4Name.c_str());

    QVector<double> a(numpixA), b(numpixA), c(numpixA);

    for(int g=0; g<numpixA; g++){
        if(g!=0){
            inA >> eins >>zwei >> drei;
            istringstream ist(eins);
            ist >> a[g];
            a[g]=a[g]/1000000000;
            istringstream ist2(zwei);
            kAB = scale*pow(TB,4)*(exp(h*c0/kB/a[g]/TB)-1)/(pow(TA,4)*exp(h*c0/kB/a[g]/TA)-1);
            a[g]=a[g]*1000000000;
            ist2 >> b[g];
            if(ui->checkBox_19->isChecked()){
                kAB=kAB/pow(scale,2);
                fA = kAB/(1+kAB);
                fB = 1/(1+kAB);

                b[g]=(b[g]-fA)/fB;
            }
            else{
                fA = kAB/(1+kAB);
                fB = 1/(1+kAB);
                b[g]=(b[g]-fB)/fA;
            }
            outp<<setprecision(14)<<a[g]<<"\t"<<b[g]<<"\t"<<c[g]<<endl;
            out2p<<setprecision(14)<<a[g]<<"\t"<<kAB<<endl;
            out3p<<setprecision(14)<<a[g]<<"\t"<<fA<<endl;
            out4p<<setprecision(14)<<a[g]<<"\t"<<fB<<endl;
        }
        else{
            std::getline(inA, line);
            outp<<line<<endl;
        }
    }

    inA.close();
    outp.close();
    out2p.close();
    out3p.close();
    out4p.close();
}

//***************************************************
// Crop Spectra
//***************************************************
void Arithmetic::on_pushButton_9_clicked()
{
    if(ui->checkBox_21->isChecked()){
        QString qCrPath = ui->lineEdit_4->text();
        string crPath = qCrPath.toUtf8().constData();

        QString qinfile = ui->lineEdit_25->text();
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

            arrangea.resize(nrange);
            arrangeb.resize(nrange);

            for(int g=0; g<nrange; g++){
                range >> one >>two;
                istringstream ist(one);
                ist >> arrangea[g];
                istringstream ist2(two);
                ist2 >> arrangeb[g];
            }
            range.close();
        }
        Arithmetic::cropSpectra();
    }
    else{
        Arithmetic::cropSpectra();
    }
}

void Arithmetic::cropSpectra()
{
    this->setCursor(QCursor(Qt::WaitCursor));

    int min=ui->spinBox->value();
    int max=ui->spinBox_2->value();
    int numpix=0;

    double wlow=ui->lineEdit_23->text().toDouble();
    double wupp=ui->lineEdit_24->text().toDouble();

    QString qCrPath = ui->lineEdit_4->text();
    string crPath = qCrPath.toUtf8().constData();

    QString Qext=ui->lineEdit_6->text();
    string ext = Qext.toUtf8().constData();

    QString qoExt = ui->lineEdit_6->text();
    string oExt = qoExt.toUtf8().constData();

    if(ui->comboBox->currentIndex()==0){

        for(int i =min; i<=max; i++){

            qApp->processEvents(QEventLoop::AllEvents);
            if(arabor==1){
                arabor=0;
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

            QString output=ui->lineEdit_3->text();
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

            if(ui->checkBox_21->isChecked()){
                for(int zu=0; zu<arrangea.size(); zu++){
                    for(int g =0; g<numpix;g++){
                        if((a[g]>=arrangea[zu]) & (a[g]<=arrangeb[zu])){
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
            QString input=ui->lineEdit_3->text();
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
                  if((cwave[i]>=wlow) & (cwave[i]<=wupp)){
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

//***********************************
// Bin Spectra
//***********************************
void Arithmetic::on_pushButton_10_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));

    double wlow=ui->lineEdit_23->text().toDouble();
    double wupp=ui->lineEdit_24->text().toDouble();

    int min=ui->spinBox->value();
    int max=ui->spinBox_2->value();
    int numpix=0;

    QString qCrPath = ui->lineEdit_4->text();
    string crPath = qCrPath.toUtf8().constData();

    QString Qext=ui->lineEdit_6->text();
    string ext = Qext.toUtf8().constData();

    QString Qext2=ui->lineEdit_6->text();
    string ext2 = Qext2.toUtf8().constData();

    if(ui->comboBox_2->currentIndex()==0){

        if(ui->checkBox_7->isChecked()){
        for(int i =min; i<=max; i++){

            qApp->processEvents(QEventLoop::AllEvents);
            if(arabor==1){
                arabor=0;
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

            QString output=ui->lineEdit_3->text();
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
            double binst=ui->spinBox_4->value();

            ofstream outp(outName.c_str());

            for(int g =0; g<numpix-(binst-1); g++){
                for(int i=0; i<binst; i++){
                    biniwa+=a[g+i];
                    binint+=b[g+i];
                }
                g=g+binst-1;
                binint=binint/binst;
                biniwa=biniwa/binst;
                if(ui->checkBox_22->isChecked()){
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
        else{   // single file
            QString inputA=ui->lineEdit->text();
            string dataA = inputA.toUtf8().constData();
            std::ostringstream datANameStream(dataA);
            datANameStream<<crPath<<"/"<<dataA;
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

            QString output=ui->lineEdit_3->text();
            string out = output.toUtf8().constData();
            std::ostringstream outNameStream(out);
            outNameStream<<crPath<<"/"<<out;
            std::string outName = outNameStream.str();

            for(int g=0; g<numpix; g++){
                inA >> eins >>zwei;
                istringstream ist(eins);
                ist >> a[g];
                istringstream ist2(zwei);
                ist2 >> b[g];
            }

            double binint=0, biniwa=0;
            double binst=ui->spinBox_4->value();

            ofstream outp(outName.c_str());

            for(int g =0; g<numpix-(binst-1); g++){
                for(int i=0; i<binst; i++){
                    biniwa+=a[g+i];
                    binint+=b[g+i];
                }
                g=g+binst-1;
                binint=binint/binst;
                biniwa=biniwa/binst;
                if(ui->checkBox_22->isChecked()){
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

    else if(ui->comboBox_2->currentIndex()==1){

        std::valarray<double> cwave;
        std::valarray<double> cintens;

        if(ui->checkBox_7->isChecked()){    // sequence of files
        for(int i =min; i<=max; i++){

            qApp->processEvents(QEventLoop::AllEvents);
            if(arabor==1){
                arabor=0;
                return;
            }

            QString input=ui->lineEdit_3->text();
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
                double binst=ui->spinBox_4->value();

                ofstream outp(outName.c_str());

                for(int g =0; g<numpix-(binst-1); g++){
                    for(int i=0; i<binst; i++){
                        biniwa+=cwave[g+i];
                        binint+=cintens[g+i];
                    }
                    g=g+binst-1;
                    binint=binint/binst;
                    biniwa=biniwa/binst;
                    if(ui->checkBox_22->isChecked()){
                        if((biniwa>=wlow) & (biniwa<=wupp)){
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
            }
                catch (CCfits::FitsException&)

                {
                std::cerr << " Fits Exception Thrown by test function \n";
                }
                // return;
        }
        }
        else{   // single file
            QString input=ui->lineEdit_3->text();
            string data = input.toUtf8().constData();
            std::ostringstream datNameStream(data);
            datNameStream<<crPath<<"/"<<data;
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
            outNameStream<<crPath<<"/"<<out;
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
                double binst=ui->spinBox_4->value();

                ofstream outp(outName.c_str());

                for(int g =0; g<numpix-(binst-1); g++){
                    for(int i=0; i<binst; i++){
                        biniwa+=cwave[g+i];
                        binint+=cintens[g+i];
                    }
                    g=g+binst-1;
                    binint=binint/binst;
                    biniwa=biniwa/binst;
                    if(ui->checkBox_22->isChecked()){
                        if((biniwa>=wlow) & (biniwa<=wupp)){
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

void Arithmetic::on_pushButton_11_clicked()
{
    arabor=1;
}

void Arithmetic::on_comboBox_2_currentIndexChanged(int index)
{
    if(ui->comboBox_2->currentIndex()==0){
        ui->lineEdit_6->setText("txt");
    }
    else{
        ui->lineEdit_6->setText("fits");
    }
}
