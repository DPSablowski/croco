#include "rvcurve.h"
#include "ui_rvcurve.h"
#include <string>
#include <sstream>
#include <fstream>
#include <QtDebug>
#include <QMessageBox>

using namespace std;

QString QwPath, velocity, doppler, zeit, sum;
string wPath;
QVector<double> otime(1), RV1(1), RV2(1), RV3(1), sinus(1);
double xrv1, xrv2, yrv1, yrv2, sin1, sin2, sin3;

RvCurve::RvCurve(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RvCurve)
{
    ui->setupUi(this);
    this->setWindowTitle("RV Curve");

    ui->lineEdit->setText("rv_");
    ui->lineEdit_3->setText("time.txt");
    ui->lineEdit_2->setText("/home/daniels/work1/Disentangling/Template_Method/Log/Qt_LogCC/Data");
    QwPath=ui->lineEdit_2->text();
    wPath = QwPath.toUtf8().constData();
    sin1=ui->doubleSpinBox_5->value();
    sin2=ui->doubleSpinBox_6->value();
    sin3=ui->doubleSpinBox_7->value();

    QFont legendFont = font();
    legendFont.setPointSize(16);
    ui->customPlot->axisRect()->setupFullAxesBox(true);
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);
    ui->customPlot->legend->setFont(legendFont);

}

RvCurve::~RvCurve()
{
    delete ui;
}

//****************************************************************
//get RV data
//****************************************************************
void RvCurve::on_pushButton_2_clicked()
{
    ui->plainTextEdit->clear();

    string eins, zwei;

    int min=ui->spinBox->value();
    int max=ui->spinBox_2->value();
    RV1.resize(max-min+1);
    RV2.resize(max-min+1);
    RV3.resize(max-min+1);

    for(int u=min; u<=max; u++){

        QString input=ui->lineEdit->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<wPath<<"/"<<data<<u<<".txt";
        std::string datName = datNameStream.str();
        ifstream dat(datName.c_str());

        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QString fError= QString::number(u);
            QMessageBox::information(this, "Error", "File "+QwPath+"/"+input+fError+".txt does not exist!");
           return;
        }

        dat >> eins >>zwei;
        istringstream ist(eins);
        ist >> RV1[u];
        istringstream ist2(zwei);
        ist2 >> RV2[u];
        RV3[u]=RV1[u]+RV2[u];
        if(ui->checkBox_7->isChecked()){
            RV1[u]=-RV1[u];
            RV3[u]=-RV3[u];
        }

        QString index= QString::number(u);
        velocity=QString::number(RV1[u]);
        doppler=QString::number(RV2[u]);
        sum=QString::number(RV3[u]);
        ui->plainTextEdit->appendPlainText(index+" "+velocity+" "+doppler+" "+sum);
    }
}


void RvCurve::on_lineEdit_2_textEdited()
{
    QwPath=ui->lineEdit_2->text();
    wPath = QwPath.toUtf8().constData();
}

//****************************************************************
// get time data
//****************************************************************
void RvCurve::on_pushButton_3_clicked()
{
    ui->plainTextEdit_2->clear();

    string eins;

    int min=ui->spinBox->value();
    int max=ui->spinBox_2->value();

    otime.resize(max-min+1);

        QString input=ui->lineEdit_3->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<wPath<<"/"<<data;
        std::string datName = datNameStream.str();
        ifstream dat(datName.c_str());

        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File "+QwPath+"/"+input+" does not exist!");
           return;
        }

           for(int u=min; u<=max; u++){

               dat >> eins;
               istringstream ist3(eins);
               ist3 >> otime[u];

               QString index= QString::number(u);
               zeit=QString::number(otime[u]);

               ui->plainTextEdit_2->appendPlainText(index+" "+zeit);
        }

}

//****************************************************************
//plot RV data
//****************************************************************
void RvCurve::on_pushButton_4_clicked()
{
    ui->customPlot->clearGraphs();

    string eins, zwei;
    int min=ui->spinBox->value();
    int max=ui->spinBox_2->value();

    otime.resize(max-min+1);

        QString input=ui->lineEdit_3->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<wPath<<"/"<<data;
        std::string datName = datNameStream.str();
        ifstream dat(datName.c_str());

        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File "+QwPath+"/"+input+" does not exist!");
           return;
        }
        for(int u=min; u<=max; u++){

            dat >> eins;
            istringstream ist3(eins);
            ist3 >> otime[u];
     }

           RV1.resize(max-min+1);
           RV2.resize(max-min+1);
           RV3.resize(max-min+1);
           sinus.resize(max-min+1);

           for(int u=min; u<=max; u++){

               QString input2=ui->lineEdit->text();
               string data2 = input2.toUtf8().constData();
               std::ostringstream dat2NameStream(data2);
               dat2NameStream<<wPath<<"/"<<data2<<u<<".txt";
               std::string dat2Name = dat2NameStream.str();
               ifstream dat2(dat2Name.c_str());

               QFile checkfile(dat2Name.c_str());

               if(!checkfile.exists()){
                   qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
                   QString fError= QString::number(u);
                   QMessageBox::information(this, "Error", "File "+QwPath+"/"+input+fError+".txt does not exist!");
                  return;
               }

               dat2 >> eins >>zwei;
               istringstream ist(eins);
               ist >> RV1[u];
               if(ui->checkBox->isChecked()){
                RV1[u]=RV1[u]*(-1);
               }
               istringstream ist2(zwei);
               ist2 >> RV2[u];
               if(ui->checkBox_2->isChecked()){
                RV2[u]=RV2[u]*(-1);
               }
               RV3[u]=RV1[u]+RV2[u];
               sinus[u]=sin1+sin2*sin(6.28*sin3*otime[u]);
           }

      xrv1=ui->doubleSpinBox->value();
      xrv2=ui->doubleSpinBox_2->value();
      yrv1=ui->doubleSpinBox_3->value();
      yrv2=ui->doubleSpinBox_4->value();

      QPen pen;
      pen.setWidth(2);
      pen.setColor(Qt::red);
      QPen pen2;
      pen2.setWidth(2);
      pen2.setColor(Qt::green);
      QPen pen3;
      pen3.setWidth(2);
      pen3.setColor(Qt::blue);
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignLeft);
    ui->customPlot->addGraph();
    ui->customPlot->addGraph();
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setName("RV1");
    ui->customPlot->graph(2)->setName("RV1+RV2");
    ui->customPlot->graph(1)->setName("RV2");
    ui->customPlot->graph(0)->setPen(pen3);
    ui->customPlot->graph(0)->setData(otime, RV1);
    ui->customPlot->graph(1)->setPen(pen);
    ui->customPlot->graph(1)->setData(otime, RV2);
    ui->customPlot->graph(2)->setPen(pen2);
    ui->customPlot->graph(2)->setData(otime, RV3);

    if(ui->checkBox_3->isChecked()){
    ui->customPlot->addGraph();
    ui->customPlot->graph(3)->setName("f(x)");
    ui->customPlot->graph(3)->setPen(QPen(Qt::black));
    ui->customPlot->graph(3)->setData(otime, sinus);
        }

    ui->customPlot->xAxis->setLabel("time/phase");
    ui->customPlot->yAxis->setLabel("RV [km/s]");
    ui->customPlot->xAxis->setRange(xrv1, xrv2);
    ui->customPlot->yAxis->setRange(yrv1, yrv2);
    ui->customPlot->replot();
}

//****************************************************************
//find values
//****************************************************************
void RvCurve::on_pushButton_5_clicked()
{
    string eins, zwei;
    int min=ui->spinBox->value();
    int max=ui->spinBox_2->value();

    otime.resize(max-min+1);

        QString input=ui->lineEdit_3->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<wPath<<"/"<<data;
        std::string datName = datNameStream.str();
        ifstream dat(datName.c_str());

        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File "+QwPath+"/"+input+" does not exist!");
           return;
        }

           for(int u=min; u<=max; u++){
               dat >> eins;
               istringstream ist3(eins);
               ist3 >> otime[u];
        }

           xrv1=otime[0];
           xrv2=otime[max-min];

           for(int u=min; u<=max; u++){
               if(otime[u]<xrv1){
                   xrv1=otime[u];
               }
           }

           for(int u=min; u<=max; u++){
               if(otime[u]>xrv2){
                   xrv2=otime[u];
               }
           }

           RV1.resize(max-min+1);
           RV2.resize(max-min+1);
           RV3.resize(max-min+1);

           for(int u=min; u<=max; u++){

               QString input2=ui->lineEdit->text();
               string data2 = input2.toUtf8().constData();
               std::ostringstream dat2NameStream(data2);
               dat2NameStream<<wPath<<"/"<<data2<<u<<".txt";
               std::string dat2Name = dat2NameStream.str();
               ifstream dat2(dat2Name.c_str());

               QFile checkfile(dat2Name.c_str());

               if(!checkfile.exists()){
                   qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
                   QString fError= QString::number(u);
                   QMessageBox::information(this, "Error", "File "+QwPath+"/"+input+fError+".txt does not exist!");
                  return;
               }

               dat2 >> eins >>zwei;
               istringstream ist(eins);
               ist >> RV1[u];
               if(ui->checkBox->isChecked()){
                RV1[u]=RV1[u]*(-1);
               }
               istringstream ist2(zwei);
               ist2 >> RV2[u];
               if(ui->checkBox_2->isChecked()){
                RV2[u]=RV2[u]*(-1);
               }
               RV3[u]=RV1[u]+RV2[u];
           }

           yrv1=RV1[0];
           yrv2=RV1[max-min];

           for(int u=min; u<=max; u++){
               if(RV1[u]<yrv1){
                   yrv1=RV1[u];
               }
           }

           for(int u=min; u<=max; u++){
               if(RV2[u]<yrv1){
                   yrv1=RV2[u];
               }
           }
           for(int u=min; u<=max; u++){
               if(RV3[u]<yrv1){
                   yrv1=RV3[u];
               }
           }

           for(int u=min; u<=max; u++){
               if(RV1[u]>yrv2){
                   yrv2=RV1[u];
               }
           }

           for(int u=min; u<=max; u++){
               if(RV2[u]>yrv2){
                   yrv2=RV2[u];
               }
           }
           for(int u=min; u<=max; u++){
               if(RV3[u]>yrv2){
                   yrv2=RV3[u];
               }
           }

           ui->doubleSpinBox->setValue(xrv1);
           ui->doubleSpinBox_2->setValue(xrv2);
           ui->doubleSpinBox_3->setValue(yrv1);
           ui->doubleSpinBox_4->setValue(yrv2);
}

void RvCurve::on_doubleSpinBox_5_valueChanged()
{
    sin1=ui->doubleSpinBox_5->value();
}

void RvCurve::on_doubleSpinBox_6_valueChanged()
{
    sin2=ui->doubleSpinBox_6->value();
}

void RvCurve::on_doubleSpinBox_7_valueChanged()
{
    sin3=ui->doubleSpinBox_7->value();
}

void RvCurve::on_pushButton_6_clicked()
{
    if(ui->checkBox_4->isChecked()){
        QString sav=ui->lineEdit_4->text();
        QString save=QwPath+"/"+sav+".pdf";
        ui->customPlot->savePdf(save);
    }
    if(ui->checkBox_5->isChecked()){
        QString sav=ui->lineEdit_4->text();
        QString save=QwPath+"/"+sav+".png";
        ui->customPlot->savePng(save);
    }
    if(ui->checkBox_6->isChecked()){
        QString sav=ui->lineEdit_4->text();
        QString save=QwPath+"/"+sav+".jpg";
        ui->customPlot->saveJpg(save);
    }
}

void RvCurve::on_checkBox_4_clicked()
{
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);
}

void RvCurve::on_checkBox_5_clicked()
{
    ui->checkBox_4->setChecked(false);
    ui->checkBox_6->setChecked(false);
}

void RvCurve::on_checkBox_6_clicked()
{
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
}

void RvCurve::on_spinBox_3_valueChanged()
{
    QFont legendFont = font();
    legendFont.setPointSize(ui->spinBox_3->value());
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);
}
