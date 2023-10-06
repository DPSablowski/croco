#include "splinefit.h"
#include "ui_splinefit.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <spline.h>

using namespace std;

double xsf, ysf;
QString qspPath, qspExt, qspFile, qsdFile, qrFile, qsp2File;
string splPath, spExt, spFile, sdFile, rFile, sp2File;
tk::spline s;


SplineFit::SplineFit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SplineFit)
{
    ui->setupUi(this);
    this->setWindowTitle("Spline Fit");

    ui->spinBox_3->setEnabled(false);

    ui->lineEdit->setText("observation_");
    ui->lineEdit_3->setText(".txt");
    ui->lineEdit_4->setText("splinedat_");
    ui->lineEdit_5->setText("ncam_");
    ui->lineEdit_6->setText("splinepoints.dat");

    ui->lineEdit_8->setText("template.txt");

    QFont legendFont = font();
    legendFont.setPointSize(16);
    ui->customPlot->axisRect()->setupFullAxesBox(true);
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);

    connect(ui->customPlot, SIGNAL(mouseMove(QMouseEvent*)), this ,SLOT(showPointToolTip(QMouseEvent*)));
    connect(ui->customPlot, SIGNAL(mousePress(QMouseEvent*)), this,SLOT(writeCoords(QMouseEvent*)));

}

SplineFit::~SplineFit()
{
    delete ui;
}

void SplineFit::seData(QString str)
{
    ui->lineEdit_2->setText(str);
}

//********************************************************
//show mouse coordinates
//********************************************************
void SplineFit::showPointToolTip(QMouseEvent *event)
{

    xsf = ui->customPlot->xAxis->pixelToCoord(event->pos().x());
    ysf = ui->customPlot->yAxis->pixelToCoord(event->pos().y());

    setToolTip(QString("%1 , %2").arg(xsf).arg(ysf));
}

//********************************************************
//write coordinates to file for spline fit
//********************************************************
void SplineFit::writeCoords(QMouseEvent *event){


    qspPath = ui->lineEdit_2->text();
    splPath = qspPath.toUtf8().constData();

    if(ui->checkBox_3->isChecked()){
        qsp2File = ui->lineEdit_7->text();
        sp2File = qsp2File.toUtf8().constData();
        QString qlFile = qspPath+"/"+qsp2File;
        QFileInfo QLFile(qlFile);

        std::ostringstream dat1NameStream(sp2File);
        dat1NameStream<<splPath<<"/"<<sp2File;
        std::string dat1Name = dat1NameStream.str();
        ofstream spline;

        if(QLFile.exists()){
            spline.open(dat1Name.c_str(), std::ios_base::app);
        }
        else{
            spline.open(dat1Name.c_str());
        }

        xsf = ui->customPlot->xAxis->pixelToCoord(event->pos().x());

        spline<<setprecision(10)<<xsf<<" "<<ysf<<endl;

        int ngraph=ui->customPlot->graphCount();
        if(ngraph == 0){
            ui->customPlot->addGraph();
        }
        else{

        }
        ngraph=ui->customPlot->graphCount();

        ui->customPlot->graph(ngraph-1)->addData(xsf, ysf);
        ui->customPlot->graph(ngraph-1)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(ngraph-1)->setPen(QPen(Qt::magenta));
        ui->customPlot->graph(ngraph-1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssPlus, ui->spinBox->value()));
        ui->customPlot->replot();

    }
    else{
        qsp2File = ui->lineEdit_6->text();
        sp2File = qsp2File.toUtf8().constData();
        QString qlFile = qspPath+"/"+qsp2File;
        QFileInfo QLFile(qlFile);

        std::ostringstream dat1NameStream(sp2File);
        dat1NameStream<<splPath<<"/"<<sp2File;
        std::string dat1Name = dat1NameStream.str();
        ofstream spline;

        if(QLFile.exists()){
            spline.open(dat1Name.c_str(), std::ios_base::app);
        }
        else{
            spline.open(dat1Name.c_str());
        }

        xsf = ui->customPlot->xAxis->pixelToCoord(event->pos().x());
        ysf = ui->customPlot->yAxis->pixelToCoord(event->pos().y());

        spline<<setprecision(10)<<xsf<<" "<<ysf<<endl;

        int ngraph=ui->customPlot->graphCount();
        if(ngraph == 0){
            ui->customPlot->addGraph();
        }
        else{

        }
        ngraph=ui->customPlot->graphCount();

        ui->customPlot->graph(ngraph-1)->addData(xsf, ysf);
        ui->customPlot->graph(ngraph-1)->setPen(QPen(Qt::magenta));
        ui->customPlot->graph(ngraph-1)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(ngraph-1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssPlus, ui->spinBox->value()));
        ui->customPlot->replot();
    }
}

//****************************************
// plot
//****************************************
void SplineFit::on_pushButton_clicked()
{
    qspFile = ui->lineEdit->text();
    spFile = qspFile.toUtf8().constData();
    qspPath = ui->lineEdit_2->text();
    splPath = qspPath.toUtf8().constData();
    qspExt = ui->lineEdit_3->text();
    spExt = qspExt.toUtf8().constData();
    qsdFile = ui->lineEdit_4->text();
    sdFile = qsdFile.toUtf8().constData();

    string line, eins, zwei;

    ui->customPlot->clearGraphs();

    // sequence
    if(ui->checkBox->isChecked()){

    }

    // single file
    else{

        int g = ui->spinBox_2->value();

        std::ostringstream dat1NameStream(spFile);
        dat1NameStream<<splPath<<"/"<<spFile<<g<<spExt;
        std::string dat1Name = dat1NameStream.str();

        QFile checkfile1(dat1Name.c_str());

        if(!checkfile1.exists()){
            qDebug()<<"The file "<<checkfile1.fileName()<<" does not exist.";
            QString gnum = QString::number(g);
            QMessageBox::information(this, "Error", "File "+qspPath+"/"+qspFile+gnum+qspExt+" does not exist!");
           return;
        }

        ifstream file1(dat1Name.c_str());

        std::ostringstream dat2NameStream(sdFile);
        dat2NameStream<<splPath<<"/"<<sdFile<<g<<".dat";
        std::string dat2Name = dat2NameStream.str();

        QFile checkfile2(dat2Name.c_str());

        if(!checkfile2.exists()){
            qDebug()<<"The file "<<checkfile2.fileName()<<" does not exist.";
            QString gnum = QString::number(g);
            QMessageBox::information(this, "Error", "File "+checkfile2.fileName()+" does not exist!");
           return;
        }

        ifstream file2(dat2Name.c_str());

        /*
        QFile checkfile2(dat2Name.c_str());

        if(!checkfile2.exists()){
            qDebug()<<"The file "<<checkfile2.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File "+qspPath+"/splinedat.dat does not exist!");
           return;
        }
        */

        int nlines=0;

        while(std::getline(file1, line))
                   ++ nlines;

                file1.clear();
                file1.seekg(0, ios::beg);

                QVector<double> xda(nlines), yda(nlines);


                for(int i=0; i<nlines; i++){
                    file1 >> eins >> zwei;
                    istringstream ist(eins);
                    ist >> xda[i];
                    istringstream ist2(zwei);
                    ist2 >> yda[i];
                }

                file1.close();

                int nlines2=0;

                while(std::getline(file2, line))
                        ++ nlines2;

                file2.clear();
                file2.seekg(0, ios::beg);

                QVector<double> xspl(nlines2), yspl(nlines2);

                for(int i=0; i<nlines2; i++){
                     file2 >> eins >> zwei;
                     istringstream ist3(eins);
                     ist3 >> xspl[i];
                     istringstream ist4(zwei);
                     ist4 >> yspl[i];
                }

                file2.close();

                ui->customPlot->addGraph();
                ui->customPlot->graph(0)->setData(xda, yda);
                if(ui->checkBox_2->isChecked()){
                    ui->customPlot->graph(0)->rescaleAxes();
                    ui->doubleSpinBox_3->setValue(xda[0]);
                    ui->doubleSpinBox_4->setValue(xda[nlines-1]);
                }
                else{
                     ui->customPlot->xAxis->setRange(ui->doubleSpinBox_3->value(), ui->doubleSpinBox_4->value());
                     ui->customPlot->yAxis->setRange(ui->doubleSpinBox_5->value(), ui->doubleSpinBox_6->value());
                }
                ui->customPlot->addGraph();
                ui->customPlot->graph(1)->setData(xspl, yspl);
                ui->customPlot->graph(1)->setPen(QPen(Qt::red));
                ui->customPlot->replot();

                if(ui->checkBox_7->isChecked()){
                      string stemp = ui->lineEdit_8->text().toUtf8().constData();

                      std::ostringstream tempNameStream(stemp);
                      tempNameStream<<splPath<<"/"<<stemp;
                      std::string tempName = tempNameStream.str();
                      QFile checktemp(tempName.c_str());

                      if(!checktemp.exists()){
                           qDebug()<<"The file "<<checktemp.fileName()<<" does not exist.";
                           QMessageBox::information(this, "Error", "File "+checktemp.fileName()+" does not exist!");
                           return;
                      }

                      ifstream temp(tempName.c_str());

                      int ntemp=0;

                      while(std::getline(temp, line))
                            ++ ntemp;

                      temp.clear();
                      temp.seekg(0, ios::beg);

                      QVector<double> xte(ntemp), yte(ntemp);

                      for(int i=0; i<ntemp; i++){
                           temp >> eins >> zwei;
                           istringstream ist(eins);
                           ist >> xte[i];
                           istringstream ist2(zwei);
                           ist2 >> yte[i];
                      }

                      temp.close();
                      ui->customPlot->addGraph();
                      ui->customPlot->graph(2)->setData(xte, yte);
                      ui->customPlot->graph(2)->setPen(QPen(Qt::green));
                      ui->customPlot->rescaleAxes(true);
                      ui->customPlot->replot();
                  }

    }
}

//***************************************
// fit spline
//***************************************
void SplineFit::on_pushButton_2_clicked()
{
    ui->customPlot->clearGraphs();

    qspFile = ui->lineEdit->text();
    spFile = qspFile.toUtf8().constData();
    qspPath = ui->lineEdit_2->text();
    splPath = qspPath.toUtf8().constData();
    qspExt = ui->lineEdit_3->text();
    spExt = qspExt.toUtf8().constData();
    qsdFile = ui->lineEdit_4->text();
    sdFile = qsdFile.toUtf8().constData();
    qrFile = ui->lineEdit_5->text();
    rFile = qrFile.toUtf8().constData();
    qsp2File = ui->lineEdit_6->text();
    sp2File = qsp2File.toUtf8().constData();

    string eins, zwei, line;
    int points =0, nlines=0;

    double mean=0, stabw=0;

    //sequence
    if(ui->checkBox->isChecked()){

        for(int n = 0; n<ui->spinBox_3->value()-ui->spinBox_2->value()+1; n++){

            int g = ui->spinBox_2->value() + n;

            points = 0; nlines=0;

            std::ostringstream dat1NameStream(spFile);
            dat1NameStream<<splPath<<"/"<<spFile<<g<<spExt;
            std::string dat1Name = dat1NameStream.str();

            QFile checkfile1(dat1Name.c_str());

            if(!checkfile1.exists()){
                qDebug()<<"The file "<<checkfile1.fileName()<<" does not exist.";
                QString gnum = QString::number(g);
                QMessageBox::information(this, "Error", "File "+qspPath+"/"+qspFile+gnum+qspExt+" does not exist!");
                return;
            }
            ifstream file1(dat1Name.c_str());

            while(std::getline(file1, line))
                       ++ nlines;

                    file1.clear();
                    file1.seekg(0, ios::beg);

                    QVector<double> xSpl(nlines), ySpl(nlines), ySpd(nlines), ySpp(nlines);

                    for(int i=0; i<nlines; i++){
                        file1 >> eins >> zwei;
                        istringstream ist(eins);
                        ist >> xSpl[i];
                        istringstream ist2(zwei);
                        ist2 >> ySpl[i];

                    }

                    file1.close();

                    std::ostringstream spNameStream(sp2File);
                    spNameStream<<splPath<<"/"<<sp2File;
                    std::string spName = spNameStream.str();

                    QFile checkfile2(spName.c_str());

                    if(!checkfile2.exists()){
                        qDebug()<<"The file "<<checkfile2.fileName()<<" does not exist.";
                        QString gnum = QString::number(g);
                        QMessageBox::information(this, "Error", "File "+checkfile2.fileName()+" does not exist!");
                        return;
                    }

                    ifstream sdat(spName.c_str());

                    while(std::getline(sdat, line))
                       ++ points;

                    sdat.clear();
                    sdat.seekg(0, ios::beg);

                    if(points < 3){
                        QMessageBox::information(this, "Error", "Not enough data points for cubic spline fit.");
                        return;
                    }

                    vector<double> XC(points), YC(points);
                    QVector<double> Xc(points), Yc(points);

                    for (int i=0; i<points; i++){
                        sdat >> eins >>zwei;
                        istringstream ist(eins);
                        ist >> XC[i];
                        Xc[i]=XC[i];
                        if(i>0){
                            if(XC[i]<XC[i-1]){
                                QString sIndex = QString::number(i);
                                QMessageBox::information(this, "Error", "Points for spline fit are not sorted in ascending order. Failed at point "+sIndex+".");
                                return;
                            }
                        }
                        istringstream ist2(zwei);
                        ist2 >> YC[i];
                        for(int e = 0; e<nlines-1; e++){
                            if((XC[i]>=xSpl[e]) & (XC[i]<=xSpl[e+1])){
                                YC[i]=ySpl[e];
                                e=nlines;
                            }
                        }

                        if(ui->checkBox_4->isChecked()){
                            Yc[i]=2-Yc[i];
                            YC[i]=2-YC[i];
                        }
                        if(ui->checkBox_5->isChecked()){
                            Yc[i]=1/Yc[i];
                            YC[i]=1/YC[i];
                        }
                        else{
                            Yc[i]=YC[i];
                        }
                    }
                    sdat.close();

                    s.set_points(XC,YC);

                    std::ostringstream dat2NameStream(sdFile);
                    dat2NameStream<<splPath<<"/"<<sdFile<<g<<spExt;
                    std::string dat2Name = dat2NameStream.str();
                    ofstream file2(dat2Name.c_str());

                    std::ostringstream dat3NameStream(rFile);
                    dat3NameStream<<splPath<<"/"<<rFile<<g<<spExt;
                    std::string dat3Name = dat3NameStream.str();
                    ofstream file3(dat3Name.c_str());

                    double x;

                    for(int i=0; i<nlines; i++){

                        x = xSpl[i];
                        file2<<x<<"\t"<<s(x)<<endl;
                        ySpd[i]=s(x);

                        mean+=ySpl[i]/nlines;
                        ySpp[i]=ySpl[i]/s(x);
                        file3<<setprecision(14)<<xSpl[i]<<"\t"<<ySpp[i]<<endl;
                    }

                    file1.close();
                    file2.close();
                    file3.close();

                    for(int i = 0; i<nlines; i++){
                        stabw += pow((mean-ySpl[i]),2);
                    }
                    stabw = sqrt(stabw/(nlines-1));

                    ui->customPlot->addGraph();
                    ui->customPlot->graph(0)->setData(xSpl, ySpl);
                    ui->customPlot->graph(0)->rescaleAxes();
                    ui->customPlot->addGraph();
                    ui->customPlot->graph(1)->setData(xSpl, ySpp);
                    ui->customPlot->graph(1)->setPen(QPen(Qt::red));
                    ui->customPlot->graph(1)->rescaleAxes(true);
                    ui->customPlot->addGraph();
                    ui->customPlot->graph(2)->setData(xSpl, ySpd);
                    ui->customPlot->graph(2)->setPen(QPen(Qt::black));
                    ui->customPlot->graph(2)->rescaleAxes(true);

                    if(ui->checkBox_7->isChecked()){
                        string stemp = ui->lineEdit_8->text().toUtf8().constData();

                        std::ostringstream tempNameStream(stemp);
                        tempNameStream<<splPath<<"/"<<stemp;
                        std::string tempName = tempNameStream.str();

                        QFile checktemp(tempName.c_str());

                        if(!checktemp.exists()){
                            qDebug()<<"The file "<<checktemp.fileName()<<" does not exist.";
                            QMessageBox::information(this, "Error", "File "+checktemp.fileName()+" does not exist!");
                            return;
                        }

                        ifstream temp(tempName.c_str());

                        int ntemp=0;

                        while(std::getline(temp, line))
                                   ++ ntemp;

                                temp.clear();
                                temp.seekg(0, ios::beg);

                                QVector<double> xte(ntemp), yte(ntemp);

                                for(int i=0; i<ntemp; i++){
                                    temp >> eins >> zwei;
                                    istringstream ist(eins);
                                    ist >> xte[i];
                                    istringstream ist2(zwei);
                                    ist2 >> yte[i];
                                }

                                temp.close();

                                ui->customPlot->addGraph();
                                int ngraph = ui->customPlot->graphCount()-1;
                                ui->customPlot->graph(ngraph)->setData(xte, yte);
                                ui->customPlot->graph(ngraph)->setPen(QPen(Qt::green));
                                ui->customPlot->rescaleAxes(true);
                    }
                    ui->customPlot->replot();

        }

    }

    // single file
    else{

        int g = ui->spinBox_2->value();

        std::ostringstream dat1NameStream(spFile);
        dat1NameStream<<splPath<<"/"<<spFile<<g<<spExt;
        std::string dat1Name = dat1NameStream.str();

        QFile checkfile1(dat1Name.c_str());

        if(!checkfile1.exists()){
            qDebug()<<"The file "<<checkfile1.fileName()<<" does not exist.";
            QString gnum = QString::number(g);
            QMessageBox::information(this, "Error", "File "+qspPath+"/"+qspFile+gnum+qspExt+" does not exist!");
            return;
        }
        ifstream file1(dat1Name.c_str());

        while(std::getline(file1, line))
                   ++ nlines;

                file1.clear();
                file1.seekg(0, ios::beg);

                QVector<double> xSpl(nlines), ySpl(nlines), ySpd(nlines), ySpp(nlines);

                std::ostringstream spNameStream(sp2File);
                spNameStream<<splPath<<"/"<<sp2File;
                std::string spName = spNameStream.str();
                ifstream sdat(spName.c_str());

                while(std::getline(sdat, line))
                   ++ points;

                sdat.clear();
                sdat.seekg(0, ios::beg);

                if(points < 3){
                    QMessageBox::information(this, "Error", "Not enough data points for cubic spline fit.");
                    return;
                }

                vector<double> XC(points), YC(points);
                QVector<double> Xc(points), Yc(points);

                for (int i=0; i<points; i++){
                    sdat >> eins >>zwei;
                    istringstream ist(eins);
                    ist >> XC[i];
                    Xc[i]=XC[i];
                    if(i>0){
                        if(XC[i]<XC[i-1]){
                            QString sIndex = QString::number(i);
                            QMessageBox::information(this, "Error", "Points for spline fit are not sorted in ascending order. Failed at point "+sIndex+".");
                            return;
                        }
                    }
                    istringstream ist2(zwei);
                    ist2 >> YC[i];
                    Yc[i]=YC[i];
                }
                sdat.close();

                s.set_points(XC,YC);

                std::ostringstream dat2NameStream(sdFile);
                dat2NameStream<<splPath<<"/"<<sdFile<<g<<".dat";
                std::string dat2Name = dat2NameStream.str();
                ofstream file2(dat2Name.c_str());

                std::ostringstream dat3NameStream(rFile);
                dat3NameStream<<splPath<<"/"<<rFile<<g<<spExt;
                std::string dat3Name = dat3NameStream.str();
                ofstream file3(dat3Name.c_str());

                double x;

                for(int i=0; i<nlines; i++){
                    file1 >> eins >> zwei;
                    istringstream ist(eins);
                    ist >> xSpl[i];
                    x = xSpl[i];
                    file2<<x<<"\t"<<s(x)<<endl;
                    ySpd[i]=s(x);
                    istringstream ist2(zwei);
                    ist2 >> ySpl[i];
                    mean+=ySpl[i]/nlines;
                    if(ui->checkBox_4->isChecked()){
                        ySpp[i]=ySpl[i]-(s(x)-1);
                    }
                    else{
                        if(ui->checkBox_6->isChecked()){
                            ySpp[i]=ySpl[i]+(s(x)-1);
                        }
                        else{
                            ySpp[i]=ySpl[i]/s(x);
                        }
                    }
                    file3<<setprecision(14)<<xSpl[i]<<"\t"<<ySpp[i]<<endl;
                }

                file1.close();

                for(int i = 0; i<nlines; i++){
                    stabw += pow((mean-ySpl[i]),2);
                }
                stabw = sqrt(stabw/(nlines-1));

                ui->customPlot->addGraph();
                ui->customPlot->graph(0)->setData(xSpl, ySpl);
                ui->customPlot->graph(0)->rescaleAxes();
                ui->customPlot->addGraph();
                ui->customPlot->graph(1)->setData(xSpl, ySpp);
                ui->customPlot->graph(1)->setPen(QPen(Qt::red));
                ui->customPlot->graph(1)->rescaleAxes(true);
                ui->customPlot->addGraph();
                ui->customPlot->graph(2)->setData(xSpl, ySpd);
                ui->customPlot->graph(2)->setPen(QPen(Qt::black));
                ui->customPlot->graph(2)->rescaleAxes(true);

                if(ui->checkBox_7->isChecked()){
                    string stemp = ui->lineEdit_8->text().toUtf8().constData();

                    std::ostringstream tempNameStream(stemp);
                    tempNameStream<<splPath<<"/"<<stemp;
                    std::string tempName = tempNameStream.str();

                    QFile checktemp(tempName.c_str());

                    if(!checktemp.exists()){
                        qDebug()<<"The file "<<checktemp.fileName()<<" does not exist.";
                        QMessageBox::information(this, "Error", "File "+checktemp.fileName()+" does not exist!");
                        return;
                    }

                    ifstream temp(tempName.c_str());

                    int ntemp=0;

                    while(std::getline(temp, line))
                           ++ ntemp;

                    temp.clear();
                    temp.seekg(0, ios::beg);

                    QVector<double> xte(ntemp), yte(ntemp);

                    for(int i=0; i<ntemp; i++){
                         temp >> eins >> zwei;
                         istringstream ist(eins);
                         ist >> xte[i];
                         istringstream ist2(zwei);
                         ist2 >> yte[i];
                    }
                    temp.close();

                    ui->customPlot->addGraph();
                    int ngraph = ui->customPlot->graphCount()-1;
                    ui->customPlot->graph(ngraph)->setData(xte, yte);
                    ui->customPlot->graph(ngraph)->setPen(QPen(Qt::green));
                    ui->customPlot->rescaleAxes(true);
                }

                ui->customPlot->replot();

                /*
                cout<<"mean: "<<mean<<" stabw: "<<stabw<<endl;

                int sppcount=0;

                std::ostringstream dat2NameStream("/splinedat.dat");
                dat2NameStream<<splPath<<"/splinedat.dat";
                std::string dat2Name = dat2NameStream.str();
                ofstream file2(dat2Name.c_str());

                for(int i =0; i<nlines; i++){

                    if(ySpl[i]>mean-stabw*sigmalo & (ySpl[i]<mean+stabw*sigmaup)){
                        xSpp[sppcount]=xSpl[i];
                        ySpp[sppcount]=ySpl[i];
                        file2<<xSpp[sppcount]<<"\t"<<ySpp[sppcount]<<endl;
                        sppcount+=1;
                    }

                }

                file2.close();

                vector<double> XSpp(sppcount), YSpp(sppcount);

                double xx;

                for(int i =0; i<sppcount; i++){

                    XSpp[i] = xSpp[i];
                    YSpp[i] = ySpp[i];

                }

                s.set_points(XSpp,YSpp);

                QVector<double> qXSpp(sppcount), qYSpp(sppcount);

                for(int i =0; i<sppcount; i++){

                    xx = XSpp[i];
                    qXSpp[i] = xx;
                    qYSpp[i] = s(xx);

                }


                ui->doubleSpinBox_3->setValue(xSpl[0]);
                ui->doubleSpinBox_4->setValue(xSpl[nlines-1]);
                ui->doubleSpinBox_5->setValue(0);
                ui->doubleSpinBox_6->setValue(mean+stabw*sigmaup);

                ui->customPlot->addGraph();
                ui->customPlot->graph(0)->setData(xSpp, ySpp);
                ui->customPlot->xAxis->setRange(xSpl[0], xSpl[nlines-1]);
                ui->customPlot->addGraph();
                ui->customPlot->graph(1)->setData(qXSpp, qYSpp);
                ui->customPlot->graph(1)->setPen(QPen(Qt::red));
                ui->customPlot->yAxis->setRange(0, mean+stabw*sigmaup);
                ui->customPlot->replot();
                */

    }

}


void SplineFit::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked()){
        ui->spinBox_3->setEnabled(true);
    }

    else{
        ui->spinBox_3->setEnabled(false);
    }
}

//************************
// Reset spline data
//************************
void SplineFit::on_pushButton_3_clicked()
{
    qsp2File = ui->lineEdit_6->text();
    sp2File = qsp2File.toUtf8().constData();
    qspPath = ui->lineEdit_2->text();
    splPath = qspPath.toUtf8().constData();

    std::ostringstream dat1NameStream(sp2File);
    dat1NameStream<<splPath<<"/"<<sp2File;
    std::string dat1Name = dat1NameStream.str();
    remove(dat1Name.c_str());

    ui->customPlot->graph(1)->data()->clear();
}


//***********************
// Reset adaptive file
//***********************
void SplineFit::on_pushButton_5_clicked()
{
    qsp2File = ui->lineEdit_7->text();
    sp2File = qsp2File.toUtf8().constData();
    qspPath = ui->lineEdit_2->text();
    splPath = qspPath.toUtf8().constData();

    std::ostringstream dat1NameStream(sp2File);
    dat1NameStream<<splPath<<"/"<<sp2File;
    std::string dat1Name = dat1NameStream.str();
    remove(dat1Name.c_str());
}


//*********************************
// find y values
//*********************************
void SplineFit::on_pushButton_4_clicked()
{
    qsp2File = ui->lineEdit_7->text();      // file with x values
    sp2File = qsp2File.toUtf8().constData();
    qspPath = ui->lineEdit_2->text();
    splPath = qspPath.toUtf8().constData();

    std::ostringstream dat1NameStream(sp2File);
    dat1NameStream<<splPath<<"/"<<sp2File;
    std::string dat1Name = dat1NameStream.str();

    QFile checkfile1(dat1Name.c_str());

    if(!checkfile1.exists()){
        qDebug()<<"The file "<<checkfile1.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+qspPath+"/"+qspFile+" does not exist!");
        return;
    }
    ifstream file1(dat1Name.c_str());

    qsp2File = ui->lineEdit_6->text();      // Spline Points
    sp2File = qsp2File.toUtf8().constData();

    std::ostringstream dat2NameStream(sp2File);
    dat2NameStream<<splPath<<"/"<<sp2File;
    std::string dat2Name = dat2NameStream.str();

    QFile checkfile2(dat2Name.c_str());

    if(checkfile2.exists()){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Warning!", "The file "+checkfile2.fileName()+ " already exists. \n\n Do you want to overwrite it?",
                                  QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
        qDebug() << "Overwrite spline data data.";
        }
        else{
            qDebug()<< "Aborted.";
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }
    }
    else{
        cout<<"Create new spline point data."<<endl;
    }
    ofstream file2(dat2Name.c_str());


            qsp2File = ui->lineEdit->text();        // File
            sp2File = qsp2File.toUtf8().constData();
            qspExt = ui->lineEdit_3->text();        // Extension
            spExt = qsp2File.toUtf8().constData();

            std::ostringstream dat3NameStream(sp2File);
            dat3NameStream<<splPath<<"/"<<sp2File<<spExt;
            std::string dat3Name = dat3NameStream.str();

            QFile checkfile3(dat3Name.c_str());

            if(!checkfile3.exists()){
                qDebug()<<"The file "<<checkfile3.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error", "File "+checkfile3.fileName()+" does not exist!");
               return;
            }
            ifstream file3(dat3Name.c_str());

            int lines=0, count=0;
            string eins, zwei, line;

            while(std::getline(file1, line))
                 ++ lines;

            file1.clear();
            file1.seekg(0, ios::beg);

            QVector<double> xVal(lines);

            for(int i=0; i<lines; i++){
                file1 >> eins;
                istringstream ist(eins);
                ist >> xVal[i];
            }

            file1.close();

            lines =0;

            while(std::getline(file3, line))
                   ++ lines;
            file3.clear();
            file3.seekg(0, ios::beg);

            QVector<double> ySpec(lines), xSpec(lines);

            for(int i=0; i<lines; i++){
                 file3 >> eins >> zwei;
                 istringstream ist2(eins);
                 ist2 >> xSpec[i];
                 istringstream ist3(zwei);
                 ist3 >> ySpec[i];
                 if(i>0){
                     if((xSpec[i-1]<xVal[count]) & (xSpec[i]>=xVal[count])){
                        ++count;
                        file2<<xSpec[i]<<"\t"<<ySpec[i]<<endl;
                     }
                 }
                 else{
                     // do nothing
                 }
             }
            file3.close();
}


//**************************************
// sigma clipping spline fit
//**************************************
void SplineFit::on_pushButton_6_clicked()
{
    tk::spline cs;
    ui->customPlot->clearGraphs();

    qspFile = ui->lineEdit->text();
    spFile = qspFile.toUtf8().constData();
    qspPath = ui->lineEdit_2->text();
    splPath = qspPath.toUtf8().constData();
    qspExt = ui->lineEdit_3->text();
    spExt = qspExt.toUtf8().constData();
    qsdFile = ui->lineEdit_4->text();
    sdFile = qsdFile.toUtf8().constData();
    qrFile = ui->lineEdit_5->text();
    rFile = qrFile.toUtf8().constData();
    qsp2File = ui->lineEdit_6->text();
    sp2File = qsp2File.toUtf8().constData();

    string eins, zwei, line;
    int points =0, nlines=0, itera=10;

    double mean=0, stabw=0, meana=0, meanu=0, mean2=0;

    double clipa = ui->doubleSpinBox->value();
    double clipu = ui->doubleSpinBox_2->value();

    //sequence
    if(ui->checkBox->isChecked()){
        for(int n = 0; n<ui->spinBox_3->value()-ui->spinBox_2->value()+1; n++){

            int g = ui->spinBox_2->value() + n;
            mean=0;

            points = 0; nlines=0;

            std::ostringstream dat1NameStream(spFile);
            dat1NameStream<<splPath<<"/"<<spFile<<g<<spExt;
            std::string dat1Name = dat1NameStream.str();
            ifstream file1(dat1Name.c_str());

            QFile checkfile1(dat1Name.c_str());

            if(!checkfile1.exists()){
                qDebug()<<"The file "<<checkfile1.fileName()<<" does not exist.";
                QString gnum = QString::number(g);
                QMessageBox::information(this, "Error", "File "+qspPath+"/"+qspFile+gnum+qspExt+" does not exist!");
               return;
            }

            while(std::getline(file1, line))
                 ++ nlines;

            file1.clear();
            file1.seekg(0, ios::beg);

            QVector<double> xSpl(nlines), ySpl(nlines), ySpd(nlines), xSpd(nlines);

            for(int i=0; i<nlines; i++){
                file1 >> eins >> zwei;
                istringstream ist(eins);
                ist >> xSpl[i];
                istringstream ist2(zwei);
                ist2 >> ySpl[i];
                mean+=ySpl[i];
             }
             file1.close();
             mean=mean/nlines;
             for(int i=0; i<nlines; i++){
                 stabw+=pow((ySpl[i]-mean),2);
             }
             stabw=sqrt(stabw/nlines);
             meanu = mean-clipu*stabw;
             meana = mean+clipa*stabw;

             for(int n=0; n<itera; n++){

                 int count=0;

                 for(int i=0; i<nlines; i++){
                      if((ySpl[i]>meanu) & (ySpl[i]<meana)){
                            ySpd[count]=ySpl[i];
                            xSpd[count]=xSpl[i];
                            ++count;
                        }
                        else{

                        }
                    }

                    mean=0;
                    stabw=0;
                    ySpd.resize(count);
                    xSpd.resize(count);

                    for(int i=0; i<count; i++){
                        mean+=ySpd[i];
                    }
                    mean=mean/count;

                    for(int i=0; i<count; i++){
                        stabw+=pow((ySpd[i]-mean),2);
                    }

                    stabw=sqrt(stabw/count);
                    cout<<n<<"\t"<<mean<<"\t"<<stabw<<endl;
                    meanu = mean-clipu*stabw;
                    meana = mean+clipa*stabw;

                    if(n>0){
                        if(mean==mean2){
                            cout<<"Clipping converged."<<endl;
                            n=itera;
                        }
                        else{
                            if(n>200){
                                cout<<"Clipping not converged after 200 iterations."<<endl;
                                n=itera;
                            }
                            else{
                                ++itera;
                            }
                        }
                    }
                    else{

                    }
                }

                std::ostringstream dat2NameStream(sp2File);
                dat2NameStream<<splPath<<"/"<<sp2File<<g<<spExt;
                std::string dat2Name = dat2NameStream.str();
                ofstream file2(dat2Name.c_str());

                for(int i =0; i<xSpd.size(); i++){
                    file2<<xSpd[i]<<"\t"<<ySpd[i]<<endl;
                }

                ui->customPlot->addGraph();
                ui->customPlot->graph(0)->addData(xSpl, ySpl);
                ui->customPlot->rescaleAxes();
                ui->customPlot->addGraph();
                ui->customPlot->graph(1)->addData(xSpd, ySpd);
                ui->customPlot->graph(1)->setPen(QPen(Qt::red));
                ui->customPlot->rescaleAxes(true);
                ui->customPlot->replot();

        }
    }

    // single file
    else{
        mean=0;
        stabw=0;

        points = 0; nlines=0;

        int g = ui->spinBox_2->value();

        std::ostringstream dat1NameStream(spFile);
        dat1NameStream<<splPath<<"/"<<spFile<<g<<spExt;
        std::string dat1Name = dat1NameStream.str();

        QFile checkfile1(dat1Name.c_str());

        if(!checkfile1.exists()){
            qDebug()<<"The file "<<checkfile1.fileName()<<" does not exist.";
            QString gnum = QString::number(g);
            QMessageBox::information(this, "Error", "File "+qspPath+"/"+qspFile+gnum+qspExt+" does not exist!");
           return;
        }
        ifstream file1(dat1Name.c_str());

        while(std::getline(file1, line))
                   ++ nlines;

                file1.clear();
                file1.seekg(0, ios::beg);

                QVector<double> xSpl(nlines), ySpl(nlines), ySpd(nlines), xSpd(nlines);
                vector<double> sx(nlines), sy(nlines);

                for(int i=0; i<nlines; i++){
                    file1 >> eins >> zwei;
                    istringstream ist(eins);
                    ist >> xSpl[i];
                    sx[i]=xSpl[i];
                    istringstream ist2(zwei);
                    ist2 >> ySpl[i];
                    sy[i]=ySpl[i];
                    mean+=ySpl[i];
                }
                file1.close();
                mean=mean/nlines;

                cs.set_points(sx,sy);

                for(int i=0; i<nlines; i++){
                    stabw+=pow((ySpl[i]-mean),2);
                }
                stabw=sqrt(stabw/nlines);
                meanu = mean-clipu*stabw;
                meana = mean+clipa*stabw;
                cout<<mean<<"\t"<<stabw<<endl;

            for(int n=0; n<itera; n++){

                int count=0;
                mean2=mean;

                for(int i=0; i<nlines; i++){
                    if((ySpl[i]>meanu) & (ySpl[i]<meana)){
                        ySpd[count]=ySpl[i];
                        xSpd[count]=xSpl[i];
                        ++count;
                    }
                    else{

                    }
                }

                mean=0;
                stabw=0;
                ySpd.resize(count);
                xSpd.resize(count);

                for(int i=0; i<count; i++){
                    mean+=ySpd[i];
                }
                mean=mean/count;

                for(int i=0; i<count; i++){
                    stabw+=pow((ySpd[i]-mean),2);
                }

                stabw=sqrt(stabw/count);
                cout<<n<<"\t"<<mean<<"\t"<<stabw<<"\t"<<count<<endl;
                meanu = mean-clipu*stabw;
                meana = mean+clipa*stabw;

                if(n>0){
                    if(mean==mean2){
                        cout<<"Clipping converged."<<endl;
                        n=itera;
                    }
                    else{
                        if(n>200){
                            cout<<"Clipping not converged after 200 iterations."<<endl;
                            n=itera;
                        }
                        else{
                            ++itera;
                        }
                    }
                }
                else{

                }
            }

            std::ostringstream dat2NameStream(sp2File);
            dat2NameStream<<splPath<<"/"<<sp2File;
            std::string dat2Name = dat2NameStream.str();
            ofstream file2(dat2Name.c_str());

            for(int i =0; i<xSpd.size(); i++){
                file2<<xSpd[i]<<"\t"<<ySpd[i]<<endl;
            }

            ui->customPlot->addGraph();
            ui->customPlot->graph(0)->addData(xSpl, ySpl);
            ui->customPlot->rescaleAxes();
            ui->customPlot->addGraph();
            ui->customPlot->graph(1)->addData(xSpd, ySpd);
            ui->customPlot->graph(1)->setPen(QPen(Qt::red));
            ui->customPlot->rescaleAxes(true);
            ui->customPlot->replot();

    }
}


void SplineFit::on_checkBox_5_clicked()
{
    if(ui->checkBox_5->isChecked()){
        ui->checkBox_4->setChecked(false);
        ui->checkBox_6->setChecked(false);
    }
    else{
        ui->checkBox_4->setChecked(true);
        ui->checkBox_6->setChecked(false);
    }
}

void SplineFit::on_checkBox_4_clicked()
{
    if(ui->checkBox_4->isChecked()){
        ui->checkBox_5->setChecked(false);
        ui->checkBox_6->setChecked(false);
    }
    else{
        ui->checkBox_5->setChecked(true);
        ui->checkBox_6->setChecked(false);
    }
}

void SplineFit::on_checkBox_6_clicked()
{
    if(ui->checkBox_6->isChecked()){
        ui->checkBox_4->setChecked(false);
        ui->checkBox_5->setChecked(false);
    }
    else{
        ui->checkBox_5->setChecked(true);
        ui->checkBox_4->setChecked(false);
    }
}

//*************************************
// normalize with a template
//*************************************
void SplineFit::on_pushButton_7_clicked()
{
    string spPoints = ui->lineEdit_6->text().toUtf8().constData();
    string spTempl = ui->lineEdit_8->text().toUtf8().constData();
    string spSpec = (ui->lineEdit->text()+QString::number(ui->spinBox_2->value())+ui->lineEdit_3->text()).toUtf8().constData();
    qspPath = ui->lineEdit_2->text();
    splPath = qspPath.toUtf8().constData();

    std::ostringstream dat1NameStream(spPoints);
    dat1NameStream<<splPath<<"/"<<spPoints;
    std::string dat1Name = dat1NameStream.str();

    std::ostringstream dat2NameStream(spTempl);
    dat2NameStream<<splPath<<"/"<<spTempl;
    std::string dat2Name = dat2NameStream.str();

    std::ostringstream dat3NameStream(spSpec);
    dat3NameStream<<splPath<<"/"<<spSpec;
    std::string dat3Name = dat3NameStream.str();

    QFile checkfile1(dat1Name.c_str());
    QFile checkfile2(dat2Name.c_str());
    QFile checkfile3(dat3Name.c_str());

    if(!checkfile1.exists()){
        qDebug()<<"The file "<<checkfile1.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+checkfile1.fileName()+" does not exist!");
        return;
    }
    else if(!checkfile2.exists()){
        qDebug()<<"The file "<<checkfile2.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+checkfile2.fileName()+" does not exist!");
        return;
    }
    else if(!checkfile3.exists()){
        qDebug()<<"The file "<<checkfile3.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+checkfile3.fileName()+" does not exist!");
        return;
    }
    ifstream file1(dat1Name.c_str());

    int nspoints=0, eonum;
    string line, one, two;

    while(std::getline(file1, line))
         ++ nspoints;

    file1.clear();
    file1.seekg(0, ios::beg);

    eonum = nspoints % 2;
    if(eonum == 0){

    }
    else{
        QMessageBox::information(this, "Error", "Odd number of points in file "+checkfile1.fileName());
        return;
    }

    QVector<double> sPointsl(nspoints/2), sPointsr(nspoints/2), sWave(nspoints/2), sWavel(nspoints/2), sWaver(nspoints/2);
    int lcount=0, rcount=0;

    for(int i=0; i<nspoints; i++){
        file1 >> one >> two;
        istringstream ist(one);
        istringstream is(two);
        if(i%2==0){
            ist >> sWavel[lcount];
            is >> sPointsl[lcount];
            //cout<<"left; i = "<<i<<";\t"<<sPointsl[lcount]<<endl;
            ++lcount;
        }
        else{
            ist >> sWaver[rcount];
            is >> sPointsr[rcount];
            //cout<<"right; i = "<<i<<";\t"<<sPointsr[rcount]<<endl;
            ++rcount;
        }
    }
    file1.close();
    cout<<endl;

    for(int i =0; i<nspoints/2; i++){
        sWave[i]=(sWavel[i]+sWaver[i])/2;
        //cout<<sWave[i]<<endl;
    }

    QVector<double> specy(nspoints/2), tempy(nspoints/2);

    ifstream file2(dat3Name.c_str());
    int nspec=0;

    while(std::getline(file2, line))
               ++ nspec;

            file2.clear();
            file2.seekg(0, ios::beg);

    QVector<double> sy(nspec), sx(nspec);

    for(int i=0; i<nspec; i++){
        file2 >> one >> two;
        istringstream ist(one);
        ist >> sx[i];
        istringstream ist2(two);
        ist2 >> sy[i];
    }
    file2.close();

    int count=0;

            for(int i=0; i<nspoints/2; i++){
                specy[i]=0;
                for(int e=0; e<nspec; e++){
                    if((sx[e]>=sWavel[i]) & (sx[e]<=sWaver[i])){
                        specy[i]+=sy[e];
                        ++count;
                    }
                    else{

                    }
                }
                if(count==0){
                    specy[i]=(sPointsl[i]+sPointsr[i])/2;
                }
                else{
                    specy[i]=specy[i]/count;
                }
                count=0;
                //cout<<specy[i]<<endl;
            }

            ifstream file3(dat2Name.c_str());
            int ntemp=0;

            while(std::getline(file3, line))
                 ++ ntemp;

            file3.clear();
            file3.seekg(0, ios::beg);

            QVector<double> ty(ntemp), tx(ntemp);

            for(int i=0; i<ntemp; i++){
                file3 >> one >> two;
                istringstream ist(one);
                ist >> tx[i];
                istringstream ist2(two);
                ist2 >> ty[i];
                //cout<<tx[i]<<"\t"<<ty[i]<<endl;
            }
            file3.close();
            count=0;

            for(int i=0; i<nspoints/2; i++){
                tempy[i]=0;
                for(int e=0; e<ntemp; e++){
                    if((tx[e]>=sWavel[i]) & (tx[e]<=sWaver[i])){
                        tempy[i]+=ty[e];
                        ++count;
                    }
                    else{

                    }
                }
                tempy[i]=tempy[i]/count;
                count=0;
                //cout<<tempy[i]<<endl;
            }

            ofstream out(dat1Name.c_str());

            for(int i=0; i<nspoints/2; i++){
                out<<sWave[i]<<"\t"<<(1-(tempy[i]-specy[i]))<<endl;
            }
            out.close();
}

//*********************************
// plot spline points as crosses
//*********************************
void SplineFit::on_pushButton_8_clicked()
{
    string spPoints = ui->lineEdit_6->text().toUtf8().constData();
    qspPath = ui->lineEdit_2->text();
    splPath = qspPath.toUtf8().constData();

    std::ostringstream dat1NameStream(spPoints);
    dat1NameStream<<splPath<<"/"<<spPoints;
    std::string dat1Name = dat1NameStream.str();

    QFile checkfile1(dat1Name.c_str());

    if(!checkfile1.exists()){
        qDebug()<<"The file "<<checkfile1.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+checkfile1.fileName()+" does not exist!");
        return;
    }

    ifstream file1(dat1Name.c_str());

    int nspoints=0;
    string line, one, two;

    while(std::getline(file1, line))
        ++ nspoints;

    file1.clear();
    file1.seekg(0, ios::beg);

    QVector<double> sPoints(nspoints), sWave(nspoints);

    for(int i=0; i<nspoints; i++){
        file1 >> one >> two;
        istringstream ist(one);
        ist >> sWave[i];
        istringstream is(two);
        is >> sPoints[i];
    }
    file1.close();

    ui->customPlot->addGraph();
    int ngraph=ui->customPlot->graphCount();

    ui->customPlot->graph(ngraph-1)->addData(sWave, sPoints);
    ui->customPlot->graph(ngraph-1)->setLineStyle(QCPGraph::lsNone);
    ui->customPlot->graph(ngraph-1)->setPen(QPen(Qt::magenta));
    ui->customPlot->graph(ngraph-1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssPlus, ui->spinBox->value()));
    ui->customPlot->replot();
}

//*************************
// sort spline points
//*************************
void SplineFit::on_pushButton_9_clicked()
{
    string spPoints = ui->lineEdit_6->text().toUtf8().constData();
    qspPath = ui->lineEdit_2->text();
    splPath = qspPath.toUtf8().constData();

    std::ostringstream dat1NameStream(spPoints);
    dat1NameStream<<splPath<<"/"<<spPoints;
    std::string dat1Name = dat1NameStream.str();

    QFile checkfile1(dat1Name.c_str());

    if(!checkfile1.exists()){
        qDebug()<<"The file "<<checkfile1.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+checkfile1.fileName()+" does not exist!");
        return;
    }

    ifstream file1(dat1Name.c_str());

    int nspoints=0;
    string line, one, two;

    while(std::getline(file1, line))
           ++ nspoints;

            file1.clear();
            file1.seekg(0, ios::beg);

            QVector<double> sPoints(nspoints), sWave(nspoints), nPoints(nspoints), nWave(nspoints);

            for(int i=0; i<nspoints; i++){
                file1 >> one >> two;
                istringstream ist(one);
                ist >> sWave[i];
                istringstream is(two);
                is >> sPoints[i];
            }
            file1.close();

            double wmax=0.0;

            for(int i =0; i<nspoints; i++){
                if(sWave[i]>wmax){
                    wmax=sWave[i];
                }
                else{

                }
            }

            ofstream out(dat1Name.c_str());

            for(int i =0; i<nspoints; i++){
                nWave[i]=wmax;
                for(int e=0; e<nspoints; e++){
                    if(i==0){
                        if(sWave[e]<nWave[i]){
                            nWave[i]=sWave[e];
                            nPoints[i]=sPoints[e];
                        }
                        else{

                        }
                    }
                    else{
                        if((sWave[e]<=nWave[i]) & (sWave[e]>nWave[i-1])){
                            nWave[i]=sWave[e];
                            nPoints[i]=sPoints[e];
                        }
                        else{

                        }
                    }
                }
                out<<nWave[i]<<"\t"<<nPoints[i]<<endl;
            }
}

void SplineFit::on_pushButton_10_clicked()
{
    ui->customPlot->clearGraphs();
}
