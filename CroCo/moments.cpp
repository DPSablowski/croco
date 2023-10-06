#include "moments.h"
#include "ui_moments.h"
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <QMessageBox>
#include <QFile>
#include <iostream>
#include <iomanip>
#include <QDebug>

using namespace std;

QString qMoPath;
string moPath;
int mrow=3;

Moments::Moments(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Moments)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(mrow);

    ui->lineEdit->setText("/home/daniel/Observations/Capella/Analysis/Mg4571/Moments");//25, 25, 26,20,22,22,26,23
    ui->lineEdit_2->setText("NaD2_moments.dat");
    ui->lineEdit_3->setText("NaD2_moments_cor.dat");


}

Moments::~Moments()
{
    delete ui;
}

void Moments::seData(QString qstr){
    ui->lineEdit->setText(qstr);
}

void Moments::on_spinBox_valueChanged()
{
    mrow=ui->spinBox->value();
    ui->tableWidget->setRowCount(mrow);
}

//*********************************
// correct values for mean
//*********************************
void Moments::on_pushButton_2_clicked()
{
    qMoPath = ui->lineEdit->text();
    moPath = qMoPath.toUtf8().constData();
    QString qIn = ui->lineEdit_2->text();
    string In = qIn.toUtf8().constData();
    QString qOut = ui->lineEdit_3->text();
    string Out = qOut.toUtf8().constData();

    std::ostringstream inputNameStream(In);
    inputNameStream<<moPath<<"/"<<In;
    std::string inputName = inputNameStream.str();
    QFile check1(qMoPath+"/"+qIn);

    if(!check1.exists()){
        QMessageBox::information(this, "Error", "The file "+qMoPath+"/"+qIn+" does not exist.");
        return;
    }
    ifstream input(inputName.c_str());

    std::ostringstream outputNameStream(Out);
    outputNameStream<<moPath<<"/"<<Out;
    std::string outputName = outputNameStream.str();
    ofstream output(outputName.c_str());

    int nlines=0;
    string zeile, eins, zwei, drei, vier, fuenf, sechs, sieben, acht, neun;

    while(std::getline(input, zeile))
       ++ nlines;

    input.clear();
    input.seekg(0, ios::beg);

    QVector<double> hjd(nlines), suma(nlines), ewa(nlines), m1a(nlines), m2a(nlines), sumb(nlines), ewb(nlines), m1b(nlines), m2b(nlines);
    double avsuma=0.0, avewa=0.0, avm1a=0.0, avm2a=0.0, avsumb=0.0, avewb=0.0, avm1b=0.0, avm2b=0.0;
    double avsuma2=0.0, avewa2=0.0, avm1a2=0.0, avm2a2=0.0, avsumb2=0.0, avewb2=0.0, avm1b2=0.0, avm2b2=0.0;

    QTableWidgetItem *item;
    QVector<int> sets(mrow);
    int nsets=0;

    for(int i=0; i<mrow; i++){
        item=ui->tableWidget->item(i,0);
        sets[i]=item->text().toDouble();
        nsets=nsets+sets[i];
    }
    QVector<double> hjd1(sets[0]), suma1(sets[0]), ewa1(sets[0]), m1a1(sets[0]), m2a1(sets[0]), sumb1(sets[0]), ewb1(sets[0]), m1b1(sets[0]), m2b1(sets[0]);

    if(nlines!=nsets){
        QMessageBox::information(this, "Error", "The number "+QString::number(nlines)+" of rows in "+qMoPath+"/"+qIn+" is not equal with the summed number "+QString::number(nsets)+" of all sets.");
        return;
    }

    for(int i=0; i<nlines; i++){
        input>>eins>>zwei>>drei>>vier>>fuenf>>sechs>>sieben>>acht>>neun;
        istringstream str1(eins);
        str1 >> hjd[i];
        istringstream str2(zwei);
        str2 >> suma[i];
        istringstream str3(drei);
        str3 >> ewa[i];
        istringstream str4(vier);
        str4 >> m1a[i];
        istringstream str5(fuenf);
        str5 >> m2a[i];
        istringstream str6(sechs);
        str6 >> sumb[i];
        istringstream str7(sieben);
        str7 >> ewb[i];
        istringstream str8(acht);
        str8 >> m1b[i];
        istringstream str9(neun);
        str9 >> m2b[i];
        if(i<sets[0]){
            hjd1[i]=hjd[i];
            suma1[i]=suma[i];
            ewa1[i]=ewa[i];
            m1a1[i]=m1a[i];
            m2a1[i]=m2a[i];

            sumb1[i]=sumb[i];
            ewb1[i]=ewb[i];
            m1b1[i]=m1b[i];
            m2b1[i]=m2b[i];

            /*avsuma+=suma[i];
            avewa+=ewa[i];
            avm1a+=m1a[i];
            avm2a+=m2a[i];

            avsumb+=sumb[i];
            avewb+=ewb[i];
            avm1b+=m1b[i];
            avm2b+=m2b[i];*/
        }
        else{
        }
    }
    sort(suma1.begin(), suma1.end());
    sort(ewa1.begin(), ewa1.end());
    sort(m1a1.begin(), m1a1.end());
    sort(m2a1.begin(), m2a1.end());
    sort(sumb1.begin(), sumb1.end());
    sort(ewb1.begin(), ewb1.end());
    sort(m1b1.begin(), m1b1.end());
    sort(m2b1.begin(), m2b1.end());

    int med1=suma1.size()/2, med2=suma1.size()/2-1;

    if(abs(med1-suma1.size()/2)!=0.0){
        avsuma=(suma1[med1]+suma1[med2])/2;
        avewa=(ewa1[med1]+ewa1[med2])/2;
        avm1a=(m1a1[med1]+m1a1[med2])/2;
        avm2a=(m2a1[med1]+m2a1[med2])/2;

        avsumb=(sumb1[med1]+sumb1[med2])/2;
        avewb=(ewb1[med1]+ewb1[med2])/2;
        avm1b=(m1b1[med1]+m1b1[med2])/2;
        avm2b=(m2b1[med1]+m2b1[med2])/2;
    }
    else{
        avsuma=suma1[med1];
        avewa=ewa1[med1];
        avm1a=m1a1[med1];
        avm2a=m2a1[med1];

        avsumb=sumb1[med1];
        avewb=ewb1[med1];
        avm1b=m1b1[med1];
        avm2b=m2b1[med1];
    }

/*
    avsuma=avsuma/sets[0];
    avewa=avewa/sets[0];
    avm1a=avm1a/sets[0];
    avm2a=avm2a/sets[0];

    avsumb=avsumb/sets[0];
    avewb=avewb/sets[0];
    avm1b=avm1b/sets[0];
    avm2b=avm2b/sets[0];
*/

    int length=sets[0];
    int length1=0;
    int counter=0;

    for(int i=0; i<mrow-1; i++){
        length+=sets[i+1];
        length1+=sets[i];
        hjd1.resize(sets[i+1]);
        suma1.resize(sets[i+1]);
        ewa1.resize(sets[i+1]);
        m1a1.resize(sets[i+1]);
        m2a1.resize(sets[i+1]);
        sumb1.resize(sets[i+1]);
        ewb1.resize(sets[i+1]);
        m1b1.resize(sets[i+1]);
        m2b1.resize(sets[i+1]);
        counter=0;

        for(int n=length1; n<length; n++){
            hjd1[counter]=hjd[n];
            suma1[counter]=suma[n];
            ewa1[counter]=ewa[n];
            m1a1[counter]=m1a[n];
            m2a1[counter]=m2a[n];

            sumb1[counter]=sumb[n];
            ewb1[counter]=ewb[n];
            m1b1[counter]=m1b[n];
            m2b1[counter]=m2b[n];
            ++counter;

            /*avsuma2+=suma[n];
            avewa2+=ewa[n];
            avm1a2+=m1a[n];
            avm2a2+=m2a[n];

            avsumb2+=sumb[n];
            avewb2+=ewb[n];
            avm1b2+=m1b[n];
            avm2b2+=m2b[n];*/
        }
        sort(suma1.begin(), suma1.end());
        sort(ewa1.begin(), ewa1.end());
        sort(m1a1.begin(), m1a1.end());
        sort(m2a1.begin(), m2a1.end());
        sort(sumb1.begin(), sumb1.end());
        sort(ewb1.begin(), ewb1.end());
        sort(m1b1.begin(), m1b1.end());
        sort(m2b1.begin(), m2b1.end());

        med1=suma1.size()/2;
        med2=suma1.size()/2-1;

        if(abs(med1-suma1.size()/2)!=0.0){
            avsuma2=(suma1[med1]+suma1[med2])/2;
            avewa2=(ewa1[med1]+ewa1[med2])/2;
            avm1a2=(m1a1[med1]+m1a1[med2])/2;
            avm2a2=(m2a1[med1]+m2a1[med2])/2;

            avsumb2=(sumb1[med1]+sumb1[med2])/2;
            avewb2=(ewb1[med1]+ewb1[med2])/2;
            avm1b2=(m1b1[med1]+m1b1[med2])/2;
            avm2b2=(m2b1[med1]+m2b1[med2])/2;
        }
        else{
            avsuma2=suma1[med1];
            avewa2=ewa1[med1];
            avm1a2=m1a1[med1];
            avm2a2=m2a1[med1];

            avsumb2=sumb1[med1];
            avewb2=ewb1[med1];
            avm1b2=m1b1[med1];
            avm2b2=m2b1[med1];
        }

        /*avsuma2=avsuma2/sets[i+1];
        avewa2=avewa2/sets[i+1];
        avm1a2=avm1a2/sets[i+1];
        avm2a2=avm2a2/sets[i+1];

        avsumb2=avsumb2/sets[i+1];
        avewb2=avewb2/sets[i+1];
        avm1b2=avm1b2/sets[i+1];
        avm2b2=avm2b2/sets[i+1];*/

        for(int n=length1; n<length; n++){
            suma[n]=suma[n]+avsuma-avsuma2;
            ewa[n]=ewa[n]+avewa-avewa2;
            m1a[n]=m1a[n]+avm1a-avm1a2;
            m2a[n]=m2a[n]+avm2a-avm2a2;

            sumb[n]=sumb[n]+avsumb-avsumb2;
            ewb[n]=ewb[n]+avewb-avewb2;
            m1b[n]=m1b[n]+avm1b-avm1b2;
            m2b[n]=m2b[n]+avm2b-avm2b2;
        }
        /*avsuma2=0.0;
        avewa2=0.0;
        avm1a2=0.0;
        avm2a2=0.0;

        avsumb2=0.0;
        avewb2=0.0;
        avm1b2=0.0;
        avm2b2=0.0;*/
    }

    for(int i=0; i<nlines; i++){
        output<<setprecision(14)<<hjd[i]<<"\t"<<suma[i]<<"\t"<<ewa[i]<<"\t"<<m1a[i]<<"\t"<<m2a[i]<<"\t"<<sumb[i]<<"\t"<<ewb[i]<<"\t"<<m1b[i]<<"\t"<<m2b[i]<<endl;
    }

}

//*********************************
// merge two files with moments
//*********************************
void Moments::on_pushButton_3_clicked()
{
    qMoPath = ui->lineEdit->text();
    moPath = qMoPath.toUtf8().constData();
    QString qIn = ui->lineEdit_2->text();
    string In = qIn.toUtf8().constData();
    QString qIn2 = ui->lineEdit_4->text();
    string In2 = qIn2.toUtf8().constData();
    QString qOut = ui->lineEdit_5->text();
    string Out = qOut.toUtf8().constData();

    std::ostringstream inputNameStream(In);
    inputNameStream<<moPath<<"/"<<In;
    std::string inputName = inputNameStream.str();

    QFile check1(qMoPath+"/"+qIn);
    if(!check1.exists()){
        QMessageBox::information(this, "Error", "The file "+qMoPath+"/"+qIn+" does not exist.");
        return;
    }
    ifstream input1(inputName.c_str());

    std::ostringstream input2NameStream(In2);
    input2NameStream<<moPath<<"/"<<In2;
    std::string input2Name = input2NameStream.str();

    QFile check2(qMoPath+"/"+qIn2);
    if(!check2.exists()){
        QMessageBox::information(this, "Error", "The file "+qMoPath+"/"+qIn2+" does not exist.");
        return;
    }
    ifstream input2(input2Name.c_str());

    std::ostringstream outputNameStream(Out);
    outputNameStream<<moPath<<"/"<<Out;
    std::string outputName = outputNameStream.str();

    QFile qOutc(outputName.c_str());

    if(qOutc.exists()){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Warning!", "The file "+qMoPath+"/"+qOut+" already exists. \n\n Do you want to overwrite it?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
          qDebug() << "Yes was clicked";
        }

        else {
            qDebug() << "Yes was *not* clicked";
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }
    }

    ofstream output(outputName.c_str());

    int nlines1=0;
    string zeile, eins, zwei, drei, vier, fuenf, sechs, sieben;

    while(std::getline(input1, zeile))
       ++ nlines1;

    input1.clear();
    input1.seekg(0, ios::beg);

    int nlines2=0;

    while(std::getline(input2, zeile))
       ++ nlines2;

    input2.clear();
    input2.seekg(0, ios::beg);

    if(nlines1!=nlines2){
        QMessageBox::information(this, "Error", "Number of rows different in both input files.");
        return;
    }
    else{
        int igno=0;
        if(ui->checkBox->isChecked()){
            igno=ui->spinBox_4->value();
            for(int i=0; i < igno; ++i){
                input1.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                input2.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }
        }
        else{
            igno=0;
        }

        nlines1=nlines1-igno;
        QVector<double> hjd(nlines1), suma(nlines1), ewa(nlines1), m1a(nlines1), m2a(nlines1), sumb(nlines1), ewb(nlines1), m1b(nlines1), m2b(nlines1);

        for(int i =0; i < nlines1; i++){
            input1>>eins>>zwei>>drei>>vier>>fuenf;//>>sechs>>sieben;
            istringstream str1(eins);
            str1 >> hjd[i];
            istringstream str2(zwei);
            str2 >> suma[i];
            istringstream str3(drei);
            str3 >> ewa[i];
            istringstream str4(vier);
            str4 >> m1a[i];
            istringstream str5(fuenf);
            str5 >> m2a[i];
            //istringstream str6(sechs);
            //istringstream str7(sieben);
        }
        input1.close();

        for(int i =0; i < nlines1; i++){
            input2>>eins>>zwei>>drei>>vier>>fuenf;//>>sechs>>sieben;
            istringstream str1(eins);
            str1 >> hjd[i];
            istringstream str2(zwei);
            str2 >> sumb[i];
            istringstream str3(drei);
            str3 >> ewb[i];
            istringstream str4(vier);
            str4 >> m1b[i];
            istringstream str5(fuenf);
            str5 >> m2b[i];
            //istringstream str6(sechs);
            //istringstream str7(sieben);
            output<<setprecision(14)<<hjd[i]<<"\t"<<suma[i]<<"\t"<<ewa[i]<<"\t"<<m1a[i]<<"\t"<<m2a[i]<<"\t"<<sumb[i]<<"\t"<<ewb[i]<<"\t"<<m1b[i]<<"\t"<<m2b[i]<<endl;
        }
        input2.close();
        output.close();
    }

}

//*********************************
// combine set of files
//*********************************
void Moments::on_pushButton_4_clicked()
{
    qMoPath = ui->lineEdit->text();
    moPath = qMoPath.toUtf8().constData();
    QString qOut = ui->lineEdit_3->text();
    string Out = qOut.toUtf8().constData();
    std::ostringstream outputNameStream(Out);
    outputNameStream<<moPath<<"/"<<Out;
    std::string outputName = outputNameStream.str();

    QFile qOutc(outputName.c_str());

    if(qOutc.exists()){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Warning!", "The file "+qMoPath+"/"+qOut+" already exists. \n\n Do you want to overwrite it?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
          qDebug() << "Yes was clicked";
        }
        else {
            qDebug() << "Yes was *not* clicked";
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }
    }

    ofstream output(outputName.c_str());

    int min = ui->spinBox_2->value();
    int max = ui->spinBox_3->value();

    QString qIn = ui->lineEdit_6->text();
    string In = qIn.toUtf8().constData();
    QString qExt = ui->lineEdit_7->text();
    string ext = qExt.toUtf8().constData();

    ui->tableWidget->setRowCount(max-min+1);
    mrow=max-min+1;

    for(int i =0; i< max-min+1; i++){
        std::ostringstream inputNameStream(In);
        inputNameStream<<moPath<<"/"<<In<<i+min<<ext;
        std::string inputName = inputNameStream.str();
        QString qnu = QString::number(i+min);

        QFile check1(qMoPath+"/"+qIn+qnu+qExt);
        if(!check1.exists()){
            QMessageBox::information(this, "Error", "The file "+qMoPath+"/"+qIn+qnu+qExt+" does not exist.");
            return;
        }

        ifstream input1(inputName.c_str());

        int nlines1=0;
        string zeile, eins, zwei, drei, vier, fuenf, sechs, sieben, acht, neun;

        while(std::getline(input1, zeile))
           ++ nlines1;

        input1.clear();
        input1.seekg(0, ios::beg);

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(nlines1)));

        QVector<double> hjd(nlines1), suma(nlines1), ewa(nlines1), m1a(nlines1), m2a(nlines1), sumb(nlines1), ewb(nlines1), m1b(nlines1), m2b(nlines1);

        for(int i =0; i < nlines1; i++){
            input1>>eins>>zwei>>drei>>vier>>fuenf>>sechs>>sieben>>acht>>neun;
            istringstream str1(eins);
            str1 >> hjd[i];
            istringstream str2(zwei);
            str2 >> suma[i];
            istringstream str3(drei);
            str3 >> ewa[i];
            istringstream str4(vier);
            str4 >> m1a[i];
            istringstream str5(fuenf);
            str5 >> m2a[i];
            istringstream str6(sechs);
            str6 >> sumb[i];
            istringstream str7(sieben);
            str7 >> ewb[i];
            istringstream str8(acht);
            str8 >> m1b[i];
            istringstream str9(neun);
            str9 >> m2b[i];
            output<<setprecision(14)<<hjd[i]<<"\t"<<suma[i]<<"\t"<<ewa[i]<<"\t"<<m1a[i]<<"\t"<<m2a[i]<<"\t"<<sumb[i]<<"\t"<<ewb[i]<<"\t"<<m1b[i]<<"\t"<<m2b[i]<<endl;
        }
        input1.close();
    }
    output.close();
}
