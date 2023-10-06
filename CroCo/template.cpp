#include "template.h"
#include "ui_template.h"
#include <string>;
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <QLineEdit>
#include <QString>
#include <QVector>

using namespace std;

inline double std_rand()
{
       return rand() / (RAND_MAX + 1.0);
}

double gauss (){
       double p1, p2, u, e1, e2;
       do {
           p1 = std_rand()-1.0;
           p2 = std_rand()-1.0;
           u = p1*p1 + p2*p2;
           } while (u >= 1.0);
           u = sqrt((-2.0 * log(u))/u);
           return e1 = p1 * u;
           e2 = p2 * u;
           }

int linesA=1, linesB=1;
double dw, wsteps, uw, lw, w, tempiA, tempiB, vsinA, vsinB, noise, xt1, xt2, yt1, yt2, RVA, RVB, toffset, y1add, y2add, y3add, multsum;
QVector<double> linwA(linesA), linwB(linesB), liniA(linesA), liniB(linesB), temiA(linesA), temiB(linesB);
string tpath;
QString qtpath;
const double c0 = 299792.458;


Template::Template(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Template)



{
    ui->setupUi(this);
    this->setWindowTitle("Template Toy");

    ui->lineEdit_4->setText("mizara_lines.txt");
    ui->lineEdit_5->setText("mizarb_lines.txt");
    ui->lineEdit_2->setText("templateA.txt");
    ui->lineEdit_3->setText("templateB.txt");
    ui->lineEdit_6->setText("templateA.txt");
    ui->lineEdit_7->setText("templateB.txt");
    ui->lineEdit_8->setText("mizar_3.txt");
    ui->doubleSpinBox_8->setValue(36);
    ui->doubleSpinBox_9->setValue(36);
    ui->doubleSpinBox_7->setValue(0.1);
    ui->doubleSpinBox_5->setValue(6340);
    ui->doubleSpinBox_6->setValue(6380);
    ui->doubleSpinBox_10->setValue(0);
    ui->doubleSpinBox_11->setValue(0);
    RVA=ui->doubleSpinBox_10->value();
    RVB=ui->doubleSpinBox_11->value();
    dw=ui->doubleSpinBox_7->value();
    toffset=ui->doubleSpinBox_13->value();
    ui->doubleSpinBox_17->setValue(1);
    multsum=ui->doubleSpinBox_17->value();

    ui->lineEdit->setText(QDir::currentPath());
    qtpath=ui->lineEdit->text();
    tpath = qtpath.toUtf8().constData();

    QFont legendFont = font();
    legendFont.setPointSize(16);
    ui->qCustomPlot->axisRect()->setupFullAxesBox(true);
    ui->qCustomPlot->xAxis->setLabelFont(legendFont);
    ui->qCustomPlot->yAxis->setLabelFont(legendFont);
    ui->qCustomPlot->xAxis->setTickLabelFont(legendFont);
    ui->qCustomPlot->yAxis->setTickLabelFont(legendFont);

}

Template::~Template()
{
    delete ui;
}

void Template::seData(QString str1)
{
    ui->lineEdit->setText(str1);
    qtpath=ui->lineEdit_4->text();
    tpath = qtpath.toUtf8().constData();


}

//***********************************************************
//button do it
//generate templates
//***********************************************************
void Template::on_pushButton_4_clicked()
{
    string eins, zwei, line;
    //read line list A
    QString input1=ui->lineEdit_4->text();
    string data1 = input1.toUtf8().constData();
    std::ostringstream dat1NameStream(data1);
    dat1NameStream<<tpath<<"/"<<data1;
    std::string dat1Name = dat1NameStream.str();

    QFile checkfile1(dat1Name.c_str());

    if(!checkfile1.exists()){
        qDebug()<<"The file "<<checkfile1.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+qtpath+"/"+input1+" does not exist!");
        return;
    }
    ifstream dat1(dat1Name.c_str());

    linesA=0;

    while(std::getline(dat1, line))
       ++ linesA;

    dat1.clear();
    dat1.seekg(0, ios::beg);

    linwA.resize(linesA);
    liniA.resize(linesA);
    temiA.resize(linesA);

    for (int i =0; i < linesA; i++){
        dat1 >> eins >> zwei;
        istringstream istr1(eins);
        istr1 >> linwA[i];
        istringstream istr2(zwei);
        istr2 >> liniA[i];
    }
    dat1.close();

    //read line list B
    QString input2=ui->lineEdit_5->text();
    string data2 = input2.toUtf8().constData();
    std::ostringstream dat2NameStream(data2);
    dat2NameStream<<tpath<<"/"<<data2;
    std::string dat2Name = dat2NameStream.str();

    QFile checkfile2(dat2Name.c_str());

    if(!checkfile2.exists()){
        qDebug()<<"The file "<<checkfile2.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+qtpath+"/"+input2+".txt does not exist!");
       return;
    }
    ifstream dat2(dat2Name.c_str());

    linesB=0;

    while(std::getline(dat2, line))
       ++ linesB;

    dat2.clear();
    dat2.seekg(0, ios::beg);

    linwB.resize(linesB);
    liniB.resize(linesB);
    temiB.resize(linesB);

    for (int i =0; i < linesB; i++){
        dat2 >> eins >> zwei;
        istringstream istr3(eins);
        istr3 >> linwB[i];
        istringstream istr4(zwei);
        istr4 >> liniB[i];
    }
    dat2.close();

    QString output11=ui->lineEdit_6->text();
    string output1 = output11.toUtf8().constData();
    std::ostringstream output1NameStream(output1);
    output1NameStream<<tpath<<"/"<<output1;
    std::string output1Name = output1NameStream.str();
    ofstream file1(output1Name.c_str());

    QString output12=ui->lineEdit_7->text();
    string output2 = output12.toUtf8().constData();
    std::ostringstream output2NameStream(output2);
    output2NameStream<<tpath<<"/"<<output2;
    std::string output2Name = output2NameStream.str();
    ofstream file2(output2Name.c_str());

    lw=ui->doubleSpinBox_5->value();
    uw=ui->doubleSpinBox_6->value();
    dw=ui->doubleSpinBox_7->value();
    wsteps=(uw-lw)/dw;

    vsinA=ui->doubleSpinBox_8->value();
    vsinB=ui->doubleSpinBox_9->value();
    noise=ui->doubleSpinBox_12->value();

    for(int i=0; i<wsteps; i++){
        w=lw+i*dw;
        file1<<w<<" ";
        file2<<w<<" ";



        for(int n=0; n < linesA; n++){
            temiA[n]=((1+noise)-liniA[n]*linesA*exp(-5.545/2/(vsinA/c0*2*linwA[n]*0.83255)*pow((linwA[n]-w),2)))/linesA+gauss()*noise/2;
            tempiA+=temiA[n];
        }

        for(int n=0; n < linesB; n++){
            temiB[n]=((1+noise)-liniB[n]*linesB*exp(-5.545/2/(vsinB/c0*2*linwB[n]*0.83255)*pow((linwB[n]-w),2)))/linesB+gauss()*noise/2;
            tempiB+=temiB[n];
        }

        file1<<tempiA<<"\n";
        file2<<tempiB<<"\n";
        tempiA=0;
        tempiB=0;
    }

}

void Template::on_lineEdit_editingFinished()
{
    qtpath=ui->lineEdit->text();
    tpath = qtpath.toUtf8().constData();
}

//***********************************************************
//find values
//***********************************************************
void Template::on_pushButton_2_clicked()
{
    string zeile, one, two;
    double xA1, xA2, yA1, yA2, xB1, xB2, yB1, yB2;

    QString plot1=ui->lineEdit_2->text();
    string plot11 = plot1.toUtf8().constData();
    std::ostringstream datNameStream(plot11);
    datNameStream<<tpath<<"/"<<plot11;
    std::string datName = datNameStream.str();

    QFile checkfile(datName.c_str());

    if(!checkfile.exists()){
        qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+qtpath+"/"+plot1+" does not exist!");
       return;
    }
    ifstream toplot1(datName.c_str());

    int number_of_lines=0;

    while(std::getline(toplot1, zeile))
       ++ number_of_lines;

    toplot1.clear();
    toplot1.seekg(0, ios::beg);

    QVector<double> a(number_of_lines), b(number_of_lines);

    for (int i=0; i<number_of_lines; i++){
        toplot1 >> one >>two;
        istringstream ist(one);
        ist >> a[i];
        a[i]=a[i]*(1+RVA/c0);
        if(ui->checkBox->isChecked()){
            a[i]=log10(a[i]);
        }
        istringstream ist2(two);
        ist2 >> b[i];
        if(ui->checkBox_4->isChecked()){
            b[i]=b[i]+y1add;
        }
    }
    toplot1.close();

    xA1=a[0];
    xA2=a[number_of_lines-1];
    for(int i=0; i<number_of_lines; i++){
        if(a[i]<xA1){
            xA1=a[i];
        }
    }

    for(int i=0; i<number_of_lines; i++){
        if(a[i]>xA2){
            xA2=a[i];
        }
    }

    yA1=b[0];
    yA2=b[number_of_lines-1];
    for(int i=0; i<number_of_lines; i++){
        if(b[i]<yA1){
            yA1=b[i];
        }
    }
    for(int i=0; i<number_of_lines; i++){
        if(b[i]>yA2){
            yA2=b[i];
        }
    }

    QString plot2=ui->lineEdit_3->text();
    string plot12 = plot2.toUtf8().constData();
    std::ostringstream dat2NameStream(plot12);
    dat2NameStream<<tpath<<"/"<<plot12;
    std::string dat2Name = dat2NameStream.str();

    QFile checkfile2(dat2Name.c_str());

    if(!checkfile2.exists()){
        qDebug()<<"The file "<<checkfile2.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+qtpath+"/"+plot2+" does not exist!");
       return;
    }
    ifstream toplot2(dat2Name.c_str());

    number_of_lines=0;

    while(std::getline(toplot2, zeile))
       ++ number_of_lines;

    toplot2.clear();
    toplot2.seekg(0, ios::beg);

    a.resize(number_of_lines);
    b.reserve(number_of_lines);

    for (int i=0; i<number_of_lines; i++){
        toplot2 >> one >>two;
        istringstream ist3(one);
        ist3 >> a[i];
        a[i]=a[i]*(1+RVB/c0);
        if(ui->checkBox_2->isChecked()){
            a[i]=log10(a[i]);
        }
        istringstream ist4(two);
        ist4 >> b[i];
        b[i]=b[i]+toffset;
        if(ui->checkBox_5->isCheckable()){
            b[i]=b[i]+y2add;
        }
    }
    toplot2.close();

    xB1=a[0];
    xB2=a[number_of_lines-1];
    for(int i=0; i<number_of_lines; i++){
        if(a[i]<xB1){
            xB1=a[i];
        }
    }

    for(int i=0; i<number_of_lines; i++){
        if(a[i]>xB2){
            xB2=a[i];
        }
    }

    yB1=b[0];
    yB2=b[number_of_lines-1];
    for(int i=0; i<number_of_lines; i++){
        if(b[i]<yB1){
            yB1=b[i];
        }
    }
    for(int i=0; i<number_of_lines; i++){
        if(b[i]>yB2){
            yB2=b[i];
        }
    }

    if(xA1<xB1){
        xt1=xA1;
    }
    else{
        xt1=xB1;
    }
    if(xA2>xB2){
        xt2=xA2;
    }
    else{
        xt2=xB2;
    }

    if(yA1<yB1){
        yt1=yA1;
    }
    else{
        yt1=yB1;
    }
    if(yA2>yB2){
        yt2=yA2;
    }
    else{
        yt2=yB2;
    }
    ui->doubleSpinBox->setValue(xt1);
    ui->doubleSpinBox_2->setValue(xt2);
    ui->doubleSpinBox_3->setValue(yt1);
    ui->doubleSpinBox_4->setValue(yt2);
}


//***********************************************************
//plot templates
//***********************************************************
void Template::on_pushButton_3_clicked()
{
    ui->qCustomPlot->clearGraphs();

    string zeile, one, two;

    QString plot1=ui->lineEdit_2->text();
    string plot11 = plot1.toUtf8().constData();
    std::ostringstream datNameStream(plot11);
    datNameStream<<tpath<<"/"<<plot11;
    std::string datName = datNameStream.str();

    QFile checkfile(datName.c_str());

    if(!checkfile.exists()){
        qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+qtpath+"/"+plot1+" does not exist!");
       return;
    }
    ifstream toplot1(datName.c_str());

    int number_of_lines =0;


    while(std::getline(toplot1, zeile))
       ++ number_of_lines;

    toplot1.clear();
    toplot1.seekg(0, ios::beg);

    QVector<double> a(number_of_lines), b(number_of_lines), RshiftA(number_of_lines);

    for (int i=0; i<number_of_lines; i++){
        toplot1 >> one >>two;
        istringstream ist(one);
        ist >> a[i];
        a[i]=a[i]*(1+RVA/c0);
        if(ui->checkBox->isChecked()){
            a[i]=log10(a[i]);
        }
        istringstream ist2(two);
        ist2 >> b[i];
        if(ui->checkBox_4->isChecked()){
            b[i]=b[i]+y1add;
        }
    }
    toplot1.close();

    for(int i=0;i<number_of_lines; i++){
        RshiftA[i]=a[i]*RVA/c0/(a[1]-a[0]);
    }

    QString plot2=ui->lineEdit_3->text();
    string plot12 = plot2.toUtf8().constData();
    std::ostringstream dat2NameStream(plot12);
    dat2NameStream<<tpath<<"/"<<plot12;
    std::string dat2Name = dat2NameStream.str();

    QFile checkfile2(dat2Name.c_str());

    if(!checkfile2.exists()){
        qDebug()<<"The file "<<checkfile2.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+qtpath+"/"+plot2+" does not exist!");
       return;
    }
    ifstream toplot2(dat2Name.c_str());

    number_of_lines =0;

    while(std::getline(toplot2, zeile))
       ++ number_of_lines;

    toplot2.clear();
    toplot2.seekg(0, ios::beg);

    QVector<double> c(number_of_lines), d(number_of_lines), e(number_of_lines), f(number_of_lines), RshiftB(number_of_lines);;

    for (int i=0; i<number_of_lines; i++){
        toplot2 >> one >>two;
        istringstream ist3(one);
        ist3 >> c[i];
        if(ui->checkBox_2->isChecked()){
            f[i]=log10(c[i]);
        }
        else{
          f[i]=c[i];
        }
        c[i]=c[i]*(1+RVB/c0);
        if(ui->checkBox_2->isChecked()){
            c[i]=log10(c[i]);
        }
        istringstream ist4(two);
        ist4 >> d[i];
        d[i]=d[i]+toffset;
        if(ui->checkBox_5->isChecked()){
            d[i]=d[i]+y2add;
        }
    }
    toplot2.close();

    for(int i=0;i<number_of_lines; i++){
        RshiftB[i]=c[i]*RVB/c0/(c[1]-c[0]);
    }

    for (int i=0; i<number_of_lines; i++){
        if((i-RshiftA[i]>0)&(i-RshiftB[i]>0)&(i-RshiftA[i]<number_of_lines)&(i-RshiftB[i]<number_of_lines)){
            e[i]=b[i-RshiftA[i]]+d[i-RshiftB[i]]+toffset;
        }

        else{
            e[i]=1+toffset;
        }
        if(ui->checkBox_7->isChecked()){
            e[i]=e[i]*multsum;
        }
    }

    //File 3
    QString plot3=ui->lineEdit_8->text();
    string plot13 = plot3.toUtf8().constData();
    std::ostringstream dat3NameStream(plot13);
    dat3NameStream<<tpath<<"/"<<plot13;
    std::string dat3Name = dat3NameStream.str();

    QFile checkfile3(dat3Name.c_str());

    if(!checkfile3.exists()){
        qDebug()<<"The file "<<checkfile3.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+qtpath+"/"+plot3+" does not exist!");
        return;
    }
    ifstream toplot3(dat3Name.c_str());

    number_of_lines =0;

    while(std::getline(toplot3, zeile))
       ++ number_of_lines;

    toplot3.clear();
    toplot3.seekg(0, ios::beg);

    QVector<double> g(number_of_lines), h(number_of_lines);

    for (int i=0; i<number_of_lines; i++){
        toplot3 >> one >>two;
        istringstream ist5(one);
        ist5 >> g[i];
        if(ui->checkBox_3->isChecked()){
            g[i]=log10(g[i]);
        }
        istringstream ist6(two);
        ist6 >> h[i];
        h[i]=h[i]+3*toffset;
        if(ui->checkBox_6->isChecked()){
            h[i]=h[i]+y3add;
        }
    }
    toplot3.close();

    ui->qCustomPlot->addGraph();
    ui->qCustomPlot->addGraph();
    ui->qCustomPlot->addGraph();
    ui->qCustomPlot->addGraph();
    ui->qCustomPlot->graph(0)->setData(a, b);
    ui->qCustomPlot->graph(1)->setPen(QPen(Qt::red));
    ui->qCustomPlot->graph(1)->setData(c, d);
    ui->qCustomPlot->graph(2)->setData(f, e);
    ui->qCustomPlot->graph(2)->setPen(QPen(Qt::green));
    ui->qCustomPlot->graph(3)->setData(g, h);
    ui->qCustomPlot->graph(3)->setPen(QPen(Qt::black));
    ui->qCustomPlot->xAxis->setLabel("wavelength");
    ui->qCustomPlot->yAxis->setLabel("spectrum value");
    ui->qCustomPlot->xAxis->setRange(xt1, xt2);
    ui->qCustomPlot->yAxis->setRange(yt1, yt2);
    ui->qCustomPlot->replot();

}

void Template::on_doubleSpinBox_valueChanged()
{
    xt1=ui->doubleSpinBox->value();
}

void Template::on_doubleSpinBox_2_valueChanged()
{
    xt2=ui->doubleSpinBox_2->value();
}

void Template::on_doubleSpinBox_3_valueChanged()
{
    yt1=ui->doubleSpinBox_3->value();
}

void Template::on_doubleSpinBox_4_valueChanged()
{
    yt2=ui->doubleSpinBox_4->value();
}

void Template::on_doubleSpinBox_10_valueChanged()
{
    RVA=ui->doubleSpinBox_10->value();
}

void Template::on_doubleSpinBox_11_valueChanged()
{
    RVB=ui->doubleSpinBox_11->value();
}

void Template::on_doubleSpinBox_5_valueChanged()
{
    lw=ui->doubleSpinBox_5->value();
}

void Template::on_doubleSpinBox_6_valueChanged()
{
    uw=ui->doubleSpinBox_6->value();
}

void Template::on_doubleSpinBox_13_valueChanged()
{
    toffset=ui->doubleSpinBox_13->value();
}

void Template::on_doubleSpinBox_14_valueChanged()
{
    y1add=ui->doubleSpinBox_14->value();
}

void Template::on_doubleSpinBox_15_valueChanged()
{
    y2add=ui->doubleSpinBox_15->value();
}

void Template::on_doubleSpinBox_16_valueChanged()
{
    y3add=ui->doubleSpinBox_16->value();
}

void Template::on_doubleSpinBox_7_valueChanged()
{
    dw=ui->doubleSpinBox_7->value();
}

void Template::on_doubleSpinBox_17_valueChanged()
{
    multsum=ui->doubleSpinBox_17->value();
}
