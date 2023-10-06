#include "blazecorr.h"
#include "ui_blazecorr.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <QVector>
#include <spline.h>
#include <vector>
#define ARMA_64BIT_WORD
#include <armadillo>
#include <CCfits/CCfits>
#include <stdio.h>
#include <QMessageBox>
#include <QVector>
#include <CCfits/CCfits>

using namespace std;
using std::vector;
using namespace arma;
using namespace arpack;


double g, thetabc, dbc, tot, lwbc, uwbc, fcam, pix, in, atbc, out, n1, n2, Il1, Il2, dout, powA, powB, scalef, gres, gres2;
int npix, nl, nu, nor, nmlines, bcorab=0;
QVector<double> eta(1), optval(1), Mi(1), Mw(1);
const double RAD = M_PI/180;
tk::spline s;
QString qBExt, qWCol, qICol;
string bExt, wCol, iCol;


BlazeCorr::BlazeCorr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BlazeCorr)
{
    ui->setupUi(this);

    this->setWindowTitle("Blaze Correction");

    ui->lineEdit->setText("master.dat");
    ui->lineEdit_3->setText("spline.dat");
    ui->lineEdit_4->setText("division.dat");
    ui->lineEdit_5->setText("spica.dat");
    ui->lineEdit_6->setText("splinefit.dat");

    ui->lineEdit_7->setText("zetuma_diff.txt");
    ui->lineEdit_10->setText("zeta_diff_");
    ui->lineEdit_11->setText("txt");

    ui->lineEdit_15->setText("cor");

    QFont legendFont = font();
    legendFont.setPointSize(16);
    ui->customPlot->axisRect()->setupFullAxesBox(true);
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);

    ui->progressBar->setValue(0);
}

BlazeCorr::~BlazeCorr()
{
    delete ui;
}

void BlazeCorr::seData(QString str)
{
    ui->lineEdit_2->setText(str);
}


//******************************************
// Plot spline
//******************************************
void BlazeCorr::on_pushButton_5_clicked()
{

    int smlines = 0, nplot=0;;
    string eins, zwei, line;

    QString inputA=ui->lineEdit_2->text()+"/"+ui->lineEdit->text();
    string dataA = inputA.toUtf8().constData();
    std::ostringstream datANameStream(dataA);
    datANameStream<<dataA;
    std::string datAName = datANameStream.str();

    QFile checkfile1(datAName.c_str());

    if(checkfile1.exists()){
        ifstream inA(datAName.c_str());

        while(std::getline(inA, line))
           ++smlines;

        inA.clear();
        inA.seekg(0, ios::beg);

        QVector<double> Msw(smlines), Msi(smlines);

        for(int i =0; i<smlines; i++){
            inA >> eins >>zwei;
            istringstream ist(eins);
            ist >> Msw[i];
            istringstream ist2(zwei);
            ist2 >> Msi[i];
        }
        inA.close();

        ui->customPlot->clearGraphs();

        ui->customPlot->addGraph();
        ui->customPlot->graph(nplot)->setData(Msw, Msi);
        if(nplot==0){
            ui->customPlot->graph(nplot)->rescaleAxes();
        }
        else{
            ui->customPlot->graph(nplot)->rescaleAxes(true);
        }
        ++nplot;
    }
    else{
        qDebug()<<"Error 1: The file "<<checkfile1.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error1 ", "Error 1: Spectrum "+checkfile1.fileName()+ " does not exist!");
        this->setCursor(QCursor(Qt::ArrowCursor));
        //return;
    }



    QString inputB=ui->lineEdit_2->text()+"/"+ui->lineEdit_3->text();
    string dataB = inputB.toUtf8().constData();
    std::ostringstream datBNameStream(dataB);
    datBNameStream<<dataB;
    std::string datBName = datBNameStream.str();

    QFile checkfile2(datBName.c_str());

    if(checkfile2.exists()){

        ifstream inB(datBName.c_str());

        smlines=0;

        while(std::getline(inB, line))
           ++smlines;

        inB.clear();
        inB.seekg(0, ios::beg);

        QVector<double>  sw(smlines), si(smlines);

        for(int i =0; i<smlines; i++){
            inB >> eins >>zwei;
            istringstream ist(eins);
            ist >> sw[i];
            istringstream ist2(zwei);
            ist2 >> si[i];
        }
        inB.close();

        QPen pen1;
        pen1.setColor(Qt::red);

        ui->customPlot->addGraph();
        ui->customPlot->graph(nplot)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(nplot)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->graph(nplot)->setPen(pen1);
        ui->customPlot->graph(nplot)->setData(sw, si);
        if(nplot==0){
            ui->customPlot->graph(nplot)->rescaleAxes();
        }
        else{
            ui->customPlot->graph(nplot)->rescaleAxes(true);
        }
        ++nplot;
    }
    else{
        qDebug()<<"Error 1: The file "<<checkfile2.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error1 ", "Error 1: Spline file "+checkfile2.fileName()+ " does not exist!");
        this->setCursor(QCursor(Qt::ArrowCursor));
        //return;
    }

    string dataC = (ui->lineEdit_2->text()+"/"+ui->lineEdit_6->text()).toUtf8().constData();
    std::ostringstream datCNameStream(dataC);
    datCNameStream<<dataC;
    string datCName = datCNameStream.str();

    QFile checkfile3(datCName.c_str());

    if(checkfile3.exists()){

        ifstream in(datCName.c_str());

        smlines=0;

        while(std::getline(in, line))
           ++smlines;

        in.clear();
        in.seekg(0, ios::beg);

        QVector<double>  sw(smlines), si(smlines);

        for(int i =0; i<smlines; i++){
            in >> eins >>zwei;
            istringstream ist(eins);
            ist >> sw[i];
            istringstream ist2(zwei);
            ist2 >> si[i];
        }
        in.close();

        QPen pen1;
        pen1.setColor(Qt::green);

        ui->customPlot->addGraph();
        ui->customPlot->graph(nplot)->setPen(pen1);
        ui->customPlot->graph(nplot)->setData(sw, si);
        if(nplot==0){
            ui->customPlot->graph(nplot)->rescaleAxes();
        }
        else{
            ui->customPlot->graph(nplot)->rescaleAxes(true);
        }
        ++nplot;
    }
    else{
        qDebug()<<"Error 1: The file "<<checkfile3.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error1 ", "Error 1: Spline file "+checkfile3.fileName()+ " does not exist!");
        this->setCursor(QCursor(Qt::ArrowCursor));
        //return;
    }

    ui->customPlot->replot();
}

//******************************************
// fit spline
//******************************************
void BlazeCorr::on_pushButton_4_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));

    ui->progressBar->setValue(0);

    int sppoi = ui->spinBox_2->value();
    int inter=0, counts=0;
    int smlines = 0, smlines2=0;
    string eins, zwei, line;
    double x;

    QString inputA=ui->lineEdit_2->text()+"/"+ui->lineEdit->text();
    string dataA = inputA.toUtf8().constData();
    std::ostringstream datANameStream(dataA);
    datANameStream<<dataA;
    std::string datAName = datANameStream.str();

    QFile checkfile1(datAName.c_str());

    if(!checkfile1.exists()){
        qDebug()<<"Error 1: The file "<<checkfile1.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error1 ", "Error 1: Flat spectrum "+checkfile1.fileName()+ " does not exist!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    ifstream inA(datAName.c_str());

    QString inputB=ui->lineEdit_2->text()+"/"+ui->lineEdit_3->text();
    string dataB = inputB.toUtf8().constData();
    std::ostringstream datBNameStream(dataB);
    datBNameStream<<dataB;
    std::string datBName = datBNameStream.str();

    QFile checkfile2(datBName.c_str());

    if(!checkfile2.exists()){
        qDebug()<<"Error 1: The file "<<checkfile2.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error1 ", "Error 1: Spline points file "+checkfile2.fileName()+ " does not exist!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    ifstream inB(datBName.c_str());

    while(std::getline(inA, line))
       ++smlines;

    inA.clear();
    inA.seekg(0, ios::beg);

    inter = smlines/sppoi;
    sppoi = smlines/inter+1;

    QVector<double> Msw(smlines), Msi(smlines), sw(smlines), si(smlines), stabw(sppoi);
    double tmean;

    for(int i =0; i<smlines; i++){
        inA >> eins >>zwei;
        istringstream ist(eins);
        ist >> Msw[i];
        istringstream ist2(zwei);
        ist2 >> Msi[i];
        sw[i]=Msw[i];
    }
    inA.close();

    counts = 0;
    cout<<"test"<<endl;

    for(int i = 0; i<smlines; i++){
        if(i == counts*inter){
            stabw[counts]=0;
            tmean=0;
            if(i==0){
                for(int e = 0; e<10; e++){
                    tmean += Msi[i+e]/10;
                }
                for(int e = 0; e<10; e++){
                    stabw[counts] += pow((tmean-Msi[i+e]),2);
                }
            }
            else{
                if(i>smlines-11){
                    for(int e = 0; e<10; e++){
                        tmean += Msi[i-e]/10;
                    }
                    for(int e = 0; e<10; e++){
                        stabw[counts] += pow((tmean-Msi[i-e]),2);
                    }
                }
                else if(i>4){
                    for(int e = -4; e<5; e++){
                         tmean += Msi[i+e]/10;
                    }
                    for(int e = 0; e<10; e++){
                        stabw[counts] +=pow((tmean-Msi[i+e]),2);
                    }
                }

            }
            stabw[counts]=sqrt(stabw[counts]/10);
            ++counts;
        }
    }
    tmean=0;


    while(std::getline(inB, line))
       ++smlines2;

    inB.clear();
    inB.seekg(0, ios::beg);

    vector<double> spw(smlines2), spi(smlines2);

    cout<<inter<<"\t"<<smlines<<"\t"<<sppoi<<"\t"<<smlines2<<endl;

    double clipa=ui->doubleSpinBox_3->value();
    double clipb=ui->doubleSpinBox_4->value();
    int clspace = ui->spinBox_4->value();

    for(int i =0; i<smlines2; i++){
        inB >> eins >>zwei;
        istringstream ist3(eins);
        istringstream ist4(zwei);
        ist3 >> spw[i];
        ist4 >> spi[i];
        if(i>0){
            if(spw[i]<spw[i-1]){
                cout<<"Wrong order at position: "<<i<<endl;
                spw[i]=spw[i-1];
                spw[i]=spi[i-1];
            }
        }
        else{
            ist3 >> spw[i];
            ist4 >> spi[i];
        }
        ist4 >> spi[i];
    }
    inB.close();

    int clipiter=1;
    if(ui->checkBox_6->isChecked()){
        clipiter=2;
    }
    else{
        clipiter=1;
    }

    int valr = smlines2;
    int upda=0, ccount=0, zaehler=3*smlines2;
    double resi=0;
    cout<<valr<<endl;
    int Ph, Pl, Psh, eval=0;
    double yh, ysh, yl, ym, yi, ys, yt;
    double gamma=2.0;	//expansion coeff.
    double alpha =1.0;	//reflection coeff.
    double beta=0.5;	//contraction coeff.
    double btot=0.5;	//total contraction coeff.
    mat Pm(valr+1,valr);
    mat e(valr+1,valr);

    for(int cl=0; cl<clipiter; cl++){

    upda=0;
    ccount=0;
    resi=0;
    eval=0;
    double Z[valr], C[valr], S[valr], Em[valr], X[valr], y[valr+1], step[valr];

    //initial points
    for(int i =0; i<valr; i++){
        Pm(0,i)=spi[i];
        if(cl==0){
            step[i]=2*stabw[i];
        }
        else{
            step[i]=tmean;
        }
    }

    for (int i=0; i<valr+1; i++){
        for (int j=0; j<valr; j++){
            if(i>0 & i-1==j){
                e(i,j)=1.0;
            }
            else{
                e(i,j)=0.0;
            }
            if(i==0){

                spi[j]=Pm(0,j);
            }

            if(i!=0){
                Pm(i,j)=Pm(0,j)+step[i]*e(i,j);
            }
             spi[j]=Pm(i,j);
        }

        qApp->processEvents(QEventLoop::AllEvents);
        if(bcorab==1){
            bcorab=0;
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }
        //*************************************
        // function
        s.set_points(spw,spi);
        tmean=0;
        for(int ef = 0; ef<smlines; ef++){
            x = Msw[ef];
            si[ef]=s(x);
            tmean += pow((si[ef]-Msi[ef]),2);
        }
        tmean = sqrt(tmean/smlines);
        //*************************************
        y[i]=tmean;
        if(i==0 or tmean<resi){
            resi = y[i];
            ++upda;
        }

        ui->progressBar->setValue(100*(i+1)/(2*(valr+1)));

        eval++;
    }

    //start main loop
         for (int tc=0; tc<zaehler; tc++){
             //cout<<"tmean: "<<tmean<<endl;
             ui->progressBar->setValue(100*(tc+valr+2)/(2*(valr+1)));

            //initialize next step
            ym=0;
            ys=0;
            for (int i=0; i<valr; i++){
               Z[i]=0;
            }

            //looking for highest value
            yh=y[0];
            for (int j=0; j<valr+1; j++){
               if(y[j]>=yh){
                   yh = y[j];
                   Ph = j;
               }
            }

            //looking for smallest value
            yl=yh;
            for (int j=0; j<valr+1; j++){
               if(y[j]<yl){
                   yl=y[j];
                   Pl = j;
               }
            }

            // second highest value
            ysh=yl;
            for (int j=0; j<valr+1; j++){
                if((y[j]>ysh) & (y[j]<yh) & (y[j]>yl) & (j !=Pl)){
                    ysh=y[j];
                    Psh=j;
                }
            }


            yh=y[Ph];
            yl=y[Pl];
            ysh=y[Psh];

            //computing mean and sigma
            for (int i=0; i<valr+1; i++){
               ym+=y[i]/(valr+1);
            }
            for (int i=0; i<valr+1; i++){
               ys+=sqrt(pow((y[i]-ym),2));
            }
            ys=ys/(valr);

            //compute centroid
            for (int j=0; j<valr; j++){
               for (int i=0; i<valr+1; i++){
                   if (i!=Ph){
                       Z[j]+=Pm(i,j)/valr;
                   }
               }
            }

            //reflect highest value at centroid
            for (int i=0; i<valr; i++){
               C[i]=Z[i]+alpha*(Z[i]-Pm(Ph,i));
               spi[i]=C[i];
            }
            //*************************************
            // function
            s.set_points(spw,spi);
            tmean=0;
            for(int ef = 0; ef<smlines; ef++){
                x = Msw[ef];
                si[ef]=s(x);
                tmean += pow((si[ef]-Msi[ef]),2);
            }
            tmean = sqrt(tmean/smlines);
            //*************************************
            yt=tmean;
            if(yt<resi){
                resi=yt;
                ++upda;
            }
            else{
                //
            }
            eval++;

            if(yi<yl){
               for (int i=0; i<valr; i++){
                   Em[i]=Z[i]+gamma*(C[i]-Z[i]);
                   spi[i]=Em[i];
                }
                //*************************************
                // function
                s.set_points(spw,spi);
                tmean=0;
                for(int ef = 0; ef<smlines; ef++){
                    x = Msw[ef];
                    si[ef]=s(x);
                    tmean += pow((si[ef]-Msi[ef]),2);
                }
                tmean = sqrt(tmean/smlines);
                //*************************************
                yt=tmean;
                if(yt<resi){
                    resi=yt;
                    ++upda;
                }
                else{
                    //
                }
                eval++;
                    if(yt<yl){
                       for (int i=0; i<valr; i++){
                           Pm(Ph,i)=Em[i];
                       }
                       y[Ph]=yt;//BTfunction(E);
                       //eval++;
                    }
                    if (yt>=yl){
                       for (int i=0; i<valr; i++){
                           Pm(Ph,i)=C[i];
                       }
                       eval++;
                       y[Ph]=yi;
                    }
                }

                if(yi>=yl){
                    if(yi<=ysh){
                       for(int i=0; i<valr; i++){
                          Pm(Ph,i)=C[i];
                       }
                       eval++;
                       y[Ph]=yi;
                    }
                    if(yi>ysh){
                        if(yi<=yh){
                            for(int i=0; i<valr; i++){
                                Pm(Ph,i)=C[i];
                        }
                        eval++;
                        y[Ph]=yi;
                        yh=y[Ph];
                    }
                    for(int i=0; i<valr; i++){
                        S[i]=Z[i]+beta*(Pm(Ph,i)-Z[i]);
                        spi[i]=S[i];
                    }
                    //*************************************
                    // function
                    s.set_points(spw,spi);
                    tmean=0;;
                    for(int ef = 0; ef<smlines; ef++){
                        x = Msw[ef];
                        si[ef]=s(x);
                        tmean += pow((si[ef]-Msi[ef]),2);
                    }
                    tmean = sqrt(tmean/smlines);
                    //*************************************
                    yt=tmean;
                    if(yt<resi){
                        resi=yt;
                        ++upda;
                    }
                    else{
                        //
                    }
                    eval++;
                    if(yt>yh){
                        for (int j=0; j<valr+1; j++){
                            for (int i=0; i<valr; i++){
                            Pm(j,i)=Pm(Pl,i)+btot*(Pm(j,i)-Pm(Pl,i)); //total contraction
                            X[i]=Pm(j,i);
                            spi[i]=X[i];
                         }
                         //*************************************
                         // function
                         s.set_points(spw,spi);
                         tmean=0;
                         for(int ef = 0; ef<smlines; ef++){
                             x = Msw[ef];
                             si[ef]=s(x);
                             tmean += pow((si[ef]-Msi[ef]),2);
                         }
                         tmean = sqrt(tmean/smlines);
                         //*************************************
                         y[j]=tmean;
                         if(y[j]<resi){
                             resi=y[j];
                             ++upda;
                         }
                         else{
                             //
                         }
                         eval++;
                         }
                    }

                    if(yt<=yh){
                        for(int i=0; i<valr; i++){
                           Pm(Ph,i)=S[i];
                         }
                         eval++;
                         y[Ph]=yt;
                    }
                }
            }
         }//end main loop

         //looking for highest value
         yh=y[0];
         for (int j=0; j<valr+1; j++){
            if(y[j]>=yh){
            yh = y[j];
            Ph = j;
            }
         }

         //looking for smallest value
         yl=yh;
         for (int j=0; j<valr+1; j++){
            if(y[j]<yl){
            yl=y[j];
            if(y[j]<resi){
                resi=y[j];
                ++upda;
            }
            Pl = j;
            }
         }

         //looking for second highest value
         ysh=yl;
         for (int j=0; j<valr+1; j++){
            if((y[j]>ysh) & (y[j]<yh)){
                ysh=y[j];
                Psh=j;
            }
         }

         QVector<double> spi2(smlines), spw2(smlines);


         if(ui->checkBox_6->isChecked() & (cl<clipiter-1)){
            ccount=0;
            for(int gg=0; gg<smlines; gg++){
                x = Msw[gg];
                si[gg]=s(x);
                if((Msi[gg]<si[gg]+tmean*clipa) & (Msi[gg]>si[gg]-tmean*clipb)){
                    spi2[ccount]=Msi[gg];
                    spw2[ccount]=Msw[gg];
                    ++ccount;
                    gg+=clspace;

                }
                else{
                    //cout<<"Clipping "<<clipiter<<" excluded point "<<gg<<endl;
                }
            }

            if(ccount==1){
                cout<<"All points excluded!"<<endl;
                this->setCursor(QCursor(Qt::ArrowCursor));
                return;
            }
            else if(ccount<3){
                cout<<"Not enough points left."<<endl;
                this->setCursor(QCursor(Qt::ArrowCursor));
                return;
            }

            valr=ccount;
            cout<<"clip: "<<cl<<"; ccount: "<<ccount<<endl;
            zaehler = 3*valr;
            spi.resize(valr);
            spw.resize(valr);

            for(int gg=0; gg<valr; gg++){
                spi[gg]=spi2[gg];
                spw[gg]=spw2[gg];
                //cout<<spw[gg]<<"\t"<<spi[gg]<<endl;
            }
         }

        } // end clipping

                 QString outputA=ui->lineEdit_2->text()+"/"+ui->lineEdit_3->text();
                 string dataoA = outputA.toUtf8().constData();
                 std::ostringstream datoANameStream(dataoA);
                 datoANameStream<<dataoA;
                 std::string datoAName = datoANameStream.str();
                 ofstream outA(datoAName.c_str());

                 for(int i =0; i<spi.size(); i++){
                     spi[i]=Pm(Pl,i);
                     outA<<setprecision(14)<<spw[i]<<"\t"<<spi[i]<<endl;
                 }

                 QString outputB=ui->lineEdit_2->text()+"/"+ui->lineEdit_6->text();
                 string dataoB = outputB.toUtf8().constData();
                 std::ostringstream datoBNameStream(dataoB);
                 datoBNameStream<<dataoB;
                 std::string datoBName = datoBNameStream.str();
                 ofstream outB(datoBName.c_str());

                 QVector<double> spla(smlines), splb(smlines);

                 s.set_points(spw,spi);
                 for(int i = 0; i<smlines; i++){
                     x = Msw[i];
                     si[i]=s(x);
                     outB<<setprecision(14)<<sw[i]<<"\t"<<si[i]<<endl;
                     spla[i]=si[i]+clipa*tmean;
                     splb[i]=si[i]-clipb*tmean;
                 }

                 QPen pen1;
                 pen1.setColor(Qt::red);

                 ui->customPlot->clearGraphs();
                 ui->customPlot->addGraph();
                 ui->customPlot->graph(0)->setData(Msw, Msi);
                 ui->customPlot->graph(0)->rescaleAxes();
                 ui->customPlot->addGraph();
                 ui->customPlot->graph(1)->setLineStyle(QCPGraph::lsNone);
                 ui->customPlot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
                 ui->customPlot->graph(1)->setPen(pen1);
                 ui->customPlot->graph(1)->setData(sw, si);
                 ui->customPlot->graph(1)->rescaleAxes(true);
                 if(ui->checkBox_6->isChecked()){
                     QPen pen2;
                     pen2.setColor(Qt::green);
                     QPen pen3;
                     pen3.setColor(Qt::black);
                     ui->customPlot->addGraph();
                     ui->customPlot->graph(2)->setPen(pen2);
                     ui->customPlot->graph(2)->setData(Msw, spla);
                     ui->customPlot->graph(2)->rescaleAxes(true);
                     ui->customPlot->addGraph();
                     ui->customPlot->graph(3)->setPen(pen3);
                     ui->customPlot->graph(3)->setData(Msw, splb);
                     ui->customPlot->graph(3)->rescaleAxes(true);
                 }
                 ui->customPlot->replot();
                 //QTimer::singleShot(1000, this, SLOT(yourSlot()));

                 ui->progressBar->setValue(100);
                 cout<<"upda: "<<upda<<endl;
                 if(ui->checkBox_4->isChecked() & (upda!=2)){
                     BlazeCorr::on_pushButton_4_clicked();
                 }

    this->setCursor(QCursor(Qt::ArrowCursor));

}

//**************************************
// Divide, add, subtract
//**************************************
void BlazeCorr::on_pushButton_6_clicked()
{
    string eins, zwei, line;
    int dslines1=0, dslines2=0;
    double x;

    QString inputA=ui->lineEdit_2->text()+"/"+ui->lineEdit_5->text();
    string dataA = inputA.toUtf8().constData();
    std::ostringstream datANameStream(dataA);
    datANameStream<<dataA;
    std::string datAName = datANameStream.str();

    QFile checkfile1(datAName.c_str());

    if(!checkfile1.exists()){
        qDebug()<<"Error 1: The file "<<checkfile1.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error1 ", "Error 1: Spectrum "+checkfile1.fileName()+ " does not exist!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    ifstream inA(datAName.c_str());

    QString outputA=ui->lineEdit_2->text()+"/"+ui->lineEdit_6->text();
    string dataoA = outputA.toUtf8().constData();
    std::ostringstream datoANameStream(dataoA);
    datoANameStream<<dataoA;
    std::string datoAName = datoANameStream.str();

    QFile checkfile2(datoAName.c_str());

    if(!checkfile2.exists()){
        qDebug()<<"Error 1: The file "<<checkfile2.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error1 ", "Error 1: Spectrum "+checkfile2.fileName()+ " does not exist!");
        this->setCursor(QCursor(Qt::ArrowCursor));
    }

    ifstream inB(datoAName.c_str());

    while(std::getline(inA, line))
       ++dslines1;

    inA.clear();
    inA.seekg(0, ios::beg);

    while(std::getline(inB, line))
       ++dslines2;

    inB.clear();
    inB.seekg(0, ios::beg);

    if(dslines1 != dslines2){
        dslines1=dslines2;
        QMessageBox::information(this, "Warning", "Spline and Measurement not the sampe samling.");
        cout<<dslines1<<"\t"<<dslines2<<endl;
        //return;
    }

    QString outA=ui->lineEdit_2->text()+"/"+ui->lineEdit_4->text();
    string dataB = outA.toUtf8().constData();
    std::ostringstream datBNameStream(dataB);
    datBNameStream<<dataB;
    std::string datBName = datBNameStream.str();
    ofstream outB(datBName.c_str());

    QVector<double> mw(dslines1), mi(dslines1), dw(dslines1), di(dslines1);// sw(dslines1), si(dslines1);

    for(int i =0; i<dslines1; i++){
        inA >> eins >>zwei;
        istringstream ist(eins);
        ist >> mw[i];
        x=mw[i];
        istringstream ist2(zwei);
        ist2 >> mi[i];
        /*inB >> eins >>zwei;
        istringstream ist3(eins);
        ist3 >> sw[i];
        istringstream ist4(zwei);
        ist4 >> si[i];*/
        if(ui->checkBox_3->isChecked()){
            di[i]=mi[i]-s(x);
        }
        else{
            if(ui->checkBox_2->isChecked()){
                di[i]=mi[i]/s(x);
            }
            else{
                if(ui->checkBox_5->isChecked()){
                    di[i]=mi[i]+s(x);
                }
                else{
                    //
                }
            }
        }
        dw[i]= mw[i];
        outB<<setprecision(14)<<dw[i]<<"\t"<<di[i]<<endl;
    }

    ui->customPlot->clearGraphs();
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(dw, di);
    ui->customPlot->graph(0)->rescaleAxes();
    ui->customPlot->replot();

}

//********************************************
// separate difference into single files
//********************************************
void BlazeCorr::on_pushButton_clicked()
{
    string eins, zwei, line;
    int dlines1=0, ndiff=0;

    QString inputA=ui->lineEdit_2->text()+"/"+ui->lineEdit_7->text();
    string dataA = inputA.toUtf8().constData();
    std::ostringstream datANameStream(dataA);
    datANameStream<<dataA;
    std::string datAName = datANameStream.str();

    QFile checkfile1(datAName.c_str());

    if(!checkfile1.exists()){
        qDebug()<<"Error 1: The file "<<checkfile1.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error1 ", "Error 1: Spectrum "+checkfile1.fileName()+ " does not exist!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    ifstream inA(datAName.c_str());

    while(std::getline(inA, line))
       ++dlines1;

    inA.clear();
    inA.seekg(0, ios::beg);

    QVector<double> diffw(dlines1), diffi(dlines1);
    int counter=0;
    double test=0;

    for(int i =0; i<dlines1; i++){

        inA >> eins >> zwei;
        istringstream str(eins);
        istringstream str2(zwei);
        str >> test;

        if(test>1){
            diffw[counter] = test;
            str2 >> diffi[counter];

            if((i>0) & (counter>=1)){
                if(diffw[counter]<diffw[counter-1]){
                    ++ndiff;
                }
            }

            else{
                // do nothing
            }
            ++counter;
        }
        else{
            // do nothing
        }
        cout<<"test: "<<i<<endl;

    }

    dlines1=counter;
    counter=0;
    diffw.resize(dlines1);
    diffi.resize(dlines1);

    cout<<"ndiff:"<<ndiff<<endl;

    vector<int> pdiff(ndiff+1);
    pdiff[0]=1;
    counter=0;

        for(int i =0; i<dlines1; i++){
            if(counter==0){
                if(i>0){
                    if(diffw[i]<diffw[i-1]){
                        pdiff[counter]=i;
                        cout<<pdiff[counter]<<endl;
                        ++counter;
                    }
                }
            }
            else{
                if((i>pdiff[counter-1]-1) & (i>0)){
                    if(diffw[i]<diffw[i-1]){
                        pdiff[counter]=i;
                        cout<<pdiff[counter]<<endl;
                        ++counter;
                    }
                }
            }
        }
        pdiff[ndiff]=dlines1-1;
        cout<<pdiff[ndiff+1]<<endl;


    for(int i =0; i<=ndiff; i++){
        cout<<i<<"\t"<<pdiff[i]<<endl;
        counter=0;

        QString outputA=ui->lineEdit_2->text()+"/"+ui->lineEdit_10->text();
        QString qExt = ui->lineEdit_11->text();
        string ext = qExt.toUtf8().constData();
        string outA = outputA.toUtf8().constData();
        std::ostringstream outANameStream(outA);
        outANameStream<<outA<<i<<"."<<ext;
        std::string outAName = outANameStream.str();
        ofstream ouA(outAName.c_str());

        for(int n =0; n<pdiff[i]; n++){
            if(i==0){
                ouA<<diffw[n]<<"\t"<<diffi[n]<<endl;
            }
            else{
                if(n>=pdiff[i-1]){
                    ouA<<setprecision(14)<<diffw[pdiff[i-1]+counter]<<"\t"<<diffi[pdiff[i-1]+counter]<<endl;
                    ++counter;
                }
                else{
                    // no nothing
                }
            }
        }
    }
}

//***********************************
// subtract spline fit from sequence
//***********************************
void BlazeCorr::on_pushButton_2_clicked()
{
    int fmin = ui->spinBox->value();
    int fmax = ui->spinBox_3->value();

    QString qBPath = ui->lineEdit_2->text();
    string bPath = qBPath.toUtf8().constData();

    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_5->setChecked(true);
    QString Qin, Qout, Qout2;

    for(int i =fmin; i<=fmax; i++){
        cout<<"File number: "<<i<<endl;

        QString ind=QString::number(i);

        Qin = ui->lineEdit_10->text()+ind+"."+ui->lineEdit_11->text();
        ui->lineEdit->setText(Qin);

        Qout = ui->lineEdit_8->text()+ind+"."+ui->lineEdit_9->text(); // individual spectra

        ui->lineEdit_5->setText(Qout);

        Qout2 = ui->lineEdit_8->text()+ui->lineEdit_15->text()+"_"+ind+"."+ui->lineEdit_9->text(); // corrected individual spectra
        ui->lineEdit_4->setText(Qout2);

        ui->lineEdit_3->setText("spline_"+ui->lineEdit_15->text()+"_"+ind+".dat");
        ui->lineEdit_6->setText("splinefit_"+ui->lineEdit_15->text()+"_"+ind+".dat");

        BlazeCorr::on_pushButton_3_clicked();
        //QTimer::singleShot(2000, this, SLOT(yourSlot()));
        BlazeCorr::on_pushButton_4_clicked();
        //QTimer::singleShot(2000, this, SLOT(yourSlot()));
        BlazeCorr::on_pushButton_6_clicked();
        //QTimer::singleShot(2000, this, SLOT(yourSlot()));
    }
}

void BlazeCorr::on_checkBox_2_clicked()
{
    if(ui->checkBox_2->isChecked()){
        ui->checkBox_3->setChecked(false);
    }
    else{
        ui->checkBox_3->setChecked(true);
    }
}

void BlazeCorr::on_checkBox_3_clicked()
{
    if(ui->checkBox_3->isChecked()){
        ui->checkBox_2->setChecked(false);
    }
    else{
        ui->checkBox_2->setChecked(true);
    }
}

//**********************************
// distribute points over flat
//**********************************
void BlazeCorr::on_pushButton_3_clicked()
{
    int sppoi = ui->spinBox_2->value();
    int inter=0, counts=0;
    int smlines = 0;
    string eins, zwei, line;

    QString inputA=ui->lineEdit_2->text()+"/"+ui->lineEdit->text();
    string dataA = inputA.toUtf8().constData();
    std::ostringstream datANameStream(dataA);
    datANameStream<<dataA;
    std::string datAName = datANameStream.str();

    QFile checkfile1(datAName.c_str());

    if(!checkfile1.exists()){
        qDebug()<<"Error 1: The file "<<checkfile1.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error1 ", "Error 1: Flat "+checkfile1.fileName()+ " does not exist!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    ifstream inA(datAName.c_str());

    QString outputA=ui->lineEdit_2->text()+"/"+ui->lineEdit_3->text();
    string dataoA = outputA.toUtf8().constData();
    std::ostringstream datoANameStream(dataoA);
    datoANameStream<<dataoA;
    std::string datoAName = datoANameStream.str();
    ofstream outA(datoAName.c_str());

    while(std::getline(inA, line))
       ++smlines;

    inA.clear();
    inA.seekg(0, ios::beg);

    inter = smlines/sppoi;
    sppoi = smlines/inter+1;
    cout<<inter<<"\t"<<smlines<<"\t"<<sppoi<<endl;

    QVector<double> Msw(smlines), Msi(smlines), sw(sppoi), si(sppoi);

    for(int i =0; i<smlines; i++){
        inA >> eins >>zwei;
        istringstream ist(eins);
        ist >> Msw[i];
        istringstream ist2(zwei);
        ist2 >> Msi[i];
        if(i == counts*inter){
            sw[counts] = Msw[i];
            si[counts] = Msi[i];

            outA<<setprecision(14)<<sw[counts]<<"\t"<<si[counts]<<endl;
            ++counts;
        }
    }
    inA.close();
    outA.close();
}
