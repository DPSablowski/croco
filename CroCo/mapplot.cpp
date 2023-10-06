#include "mapplot.h"
#include "ui_mapplot.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

string MPath;
QString qMPath;
QFont legendFont;

MapPlot::MapPlot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MapPlot)
{
    ui->setupUi(this);
    this->setWindowTitle("2D Map Plot");

    ui->lineEdit->setText("ccf_0_");


    legendFont = font();
    legendFont.setPointSize(22);
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);

    ui->lineEdit_2->setText("/home/daniels/work1/Disentangling/Template_Method/Log/Qt_LogCC/Data");
    qMPath=ui->lineEdit_2->text();
    MPath = qMPath.toUtf8().constData();
}

MapPlot::~MapPlot()
{
    delete ui;
}

void MapPlot::seData(QString str1)
{
    ui->lineEdit_2->setText(str1);
    qMPath=ui->lineEdit_2->text();
    MPath = qMPath.toUtf8().constData();

}

void MapPlot::on_pushButton_2_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));
    ui->customPlot->clearGraphs();
    ui->customPlot->clearPlottables();

    int min=ui->spinBox->value();
    int max=ui->spinBox_2->value();
    int lines=0, lly=0;
    int number=0, maxi=0;
    double vxmax=0, vxmin=0;
    QVector<double> length(max-min+1);

    string zeile, one, two;

    for(int i=0; i<max-min; i++){

        number=0;

        QString plot1=ui->lineEdit->text();
        string plot11 = plot1.toUtf8().constData();
        std::ostringstream datNameStream(plot11);
        datNameStream<<MPath<<"/"<<plot11<<min+i<<".txt";
        std::string datName = datNameStream.str();

        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QString Cfile = QString::number(min+1);
            QMessageBox::information(this, "Error", "File "+qMPath+ "/"+plot1+Cfile+".txt does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }
        ifstream toplot1(datName.c_str());

        while(std::getline(toplot1, zeile)){
            ++lines;
            ++number;
        }

        toplot1.clear();
        toplot1.seekg(0, ios::beg);

        length[i]=number;

        if(number>lly){
            lly=number;
            maxi=i;
        }
    }


    QVector<double> vx(lines), ccf(lines), vxm(lly);
    int place=0;

    for(int i=0; i<max-min; i++){

        QString plot1=ui->lineEdit->text();
        string plot11 = plot1.toUtf8().constData();
        std::ostringstream datNameStream(plot11);
        datNameStream<<MPath<<"/"<<plot11<<min+i<<".txt";
        std::string datName = datNameStream.str();

        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            QMessageBox::information(this, "Error", "The file "+checkfile.fileName()+" does not exist.");
            return;
        }

        ifstream toplot1(datName.c_str());

        for(int e=0; e<length[i]; e++){
            toplot1 >> one >>two;
            istringstream str1(one);
            str1 >> vx[e+place];
            istringstream str2(two);
            str2 >> ccf[e+place];
            if(i==maxi){
                vxm[e]=vx[e+place];
            }
        }

        if(vx[place]<vxmin){
            vxmin=vx[place];
        }
        if(vx[length[i]+place-1]>vxmax){
            vxmax=vx[length[i]+place-1];
        }

        place+=length[i];
        toplot1.close();

    }
    cout<<vxmin<<" "<<vxmax<<endl;
    int llx=max-min;
    place=0;

    cout<<lines<<endl;
    ui->customPlot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom);
    ui->customPlot->axisRect()->setupFullAxesBox(true);
    QCPColorMap *colorMap = new QCPColorMap(ui->customPlot->xAxis, ui->customPlot->yAxis);
    ui->customPlot->addPlottable(colorMap);
    colorMap->data()->setSize(llx, lly);
    colorMap->data()->setRange(QCPRange(0, llx), QCPRange(vxmin, vxmax));

    int counter=0;

    for(int i=0; i<llx; i++){
        counter=0;
        for(int e=0; e<lly; e++){
            if(vx[place+counter]>=vxm[e]){
            colorMap->data()->setCell(i, e, ccf[place+counter]);
            ++counter;
            }
           else{
                colorMap->data()->setCell(i, e, 0);
            }
        }
        place+=length[i];
    }

    QCPColorScale *colorScale = new QCPColorScale(ui->customPlot);
    ui->customPlot->plotLayout()->addElement(0, 1, colorScale);
    colorScale->setType(QCPAxis::atRight);
    colorMap->setColorScale(colorScale);
    colorScale->axis()->setLabelFont(legendFont);
    colorScale->axis()->setTickLabelFont(legendFont);
    colorScale->axis()->setLabel("CCF Value");

    colorMap->setGradient(QCPColorGradient::gpPolar);
    colorMap->rescaleDataRange();
    QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->customPlot);
    ui->customPlot->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
    colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
    ui->customPlot->yAxis->setLabel("Velocity [km/s]");

    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();

    this->setCursor(QCursor(Qt::ArrowCursor));
}

void MapPlot::on_pushButton_3_clicked()
{
    if(ui->checkBox->isChecked()){
        QString sav=ui->lineEdit_3->text();
        QString save=qMPath+"/"+sav+".pdf";
        ui->customPlot->savePdf(save);
    }
    if(ui->checkBox_2->isChecked()){
        QString sav=ui->lineEdit_3->text();
        QString save=qMPath+"/"+sav+".png";
        ui->customPlot->savePng(save);
    }
}

void MapPlot::on_lineEdit_2_textChanged()
{
    qMPath=ui->lineEdit_2->text();
    MPath = qMPath.toUtf8().constData();
}

void MapPlot::on_spinBox_3_valueChanged()
{
    legendFont = font();
    legendFont.setPointSize(ui->spinBox_3->value());
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);
}
