#include "binarytool.h"
#include "ui_binarytool.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <random>

using namespace std;

double e, E1, E2, dE1, dE2, a1, dx=0.00001, xx, dphi, a2, t1, V, w1, w2, K1, K2, theta, E, IF, T0, P;
QVector<double> t(1), V1(1), V2(1);
QString list1, list2;
QString qBPath;
string BPath;
QVector<double> rvb1(1), rvb2(1), rvb3(1), rvb4(1), rvb5(1), cctimes(1);


BinaryTool::BinaryTool(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BinaryTool)
{
    ui->setupUi(this);
    this->setWindowTitle("Binary Tool");

    ui->doubleSpinBox_3->setValue(0.537);
    e=ui->doubleSpinBox_3->value();

    ui->doubleSpinBox_4->setValue(106.16);
    w1=ui->doubleSpinBox_4->value()*M_PI/180;

    w2=w1+M_PI;

    ui->doubleSpinBox_5->setValue(36997);
    T0=ui->doubleSpinBox_5->value();

    ui->doubleSpinBox_6->setValue(68.6);
    K1=ui->doubleSpinBox_6->value();

    ui->doubleSpinBox_7->setValue(67.6);
    K2=ui->doubleSpinBox_7->value();

    ui->doubleSpinBox_8->setValue(-5.6);
    V=ui->doubleSpinBox_8->value();

    ui->doubleSpinBox_10->setValue(0.05);
    dphi=ui->doubleSpinBox_10->value();

    ui->doubleSpinBox_14->setValue(5);
    ui->doubleSpinBox_15->setValue(35);

    ui->doubleSpinBox_17->setValue(20.54);
    P=ui->doubleSpinBox_17->value();

    ui->doubleSpinBox_2->setValue(1);
    IF=ui->doubleSpinBox_2->value();

    ui->lineEdit->setText("Li_lines.dat");
    ui->lineEdit_2->setText("Li_lines.dat");

    ui->comboBox->addItem("HITRAN O2");
    ui->comboBox->addItem("HITRAN H2O");
    ui->comboBox->addItem("HITRAN O2 + H2O");
    ui->comboBox->addItem("Orion");
    ui->comboBox->addItem("UVES Hanuschik");

    ui->lineEdit_4->setText("sun2.txt");
    ui->lineEdit_5->setText("sun2.txt");

    ui->lineEdit_6->setText("binaryrv_");

    ui->lineEdit_7->setText("binary_");

    ui->spinBox_3->setValue(19);

    ui->lineEdit_3->setText("/home/daniels/Disentangling/Artificial/ErrorTest/SN100");
    qBPath=ui->lineEdit_3->text();
    BPath = qBPath.toUtf8().constData();

    QFont legendFont = font();
    legendFont.setPointSize(16);
    ui->customPlot->axisRect()->setupFullAxesBox(true);
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);

    connect(ui->customPlot, SIGNAL(mouseMove(QMouseEvent*)), this ,SLOT(showPointToolTip(QMouseEvent*)));

}

BinaryTool::~BinaryTool()
{
    delete ui;
}

//********************************************************
//show mouse coordinates
//********************************************************
void BinaryTool::showPointToolTip(QMouseEvent *event)
{

    double xc = ui->customPlot->xAxis->pixelToCoord(event->pos().x());
    double yc = ui->customPlot->yAxis->pixelToCoord(event->pos().y());

    setToolTip(QString("%1 , %2").arg(xc).arg(yc));
}


void BinaryTool::on_doubleSpinBox_4_valueChanged()
{
    w1=ui->doubleSpinBox_4->value()*M_PI/180;
    w2=w1+M_PI;
}

void BinaryTool::on_doubleSpinBox_3_valueChanged()
{
   e=ui->doubleSpinBox_3->value();
}

void BinaryTool::on_doubleSpinBox_5_valueChanged()
{
    T0=ui->doubleSpinBox_5->value();
}

void BinaryTool::on_doubleSpinBox_6_valueChanged()
{
    K1=ui->doubleSpinBox_6->value();
}

void BinaryTool::on_doubleSpinBox_7_valueChanged()
{
    K2=ui->doubleSpinBox_7->value();
}

void BinaryTool::on_doubleSpinBox_8_valueChanged()
{
    V=ui->doubleSpinBox_8->value();
}


void BinaryTool::on_doubleSpinBox_10_valueChanged()
{
    dphi=ui->doubleSpinBox_10->value();
}

//*************************************************
// calculate RVs
//*************************************************
void BinaryTool::on_pushButton_2_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));


    QString output1="rvcurve.dat";
    string out1 = output1.toUtf8().constData();
    std::ostringstream dat1NameStream(out1);
    dat1NameStream<<BPath<<"/"<<out1;
    std::string dat1Name = dat1NameStream.str();
    ofstream file(dat1Name.c_str());

    QString output2="velocities.dat";
    string out2 = output2.toUtf8().constData();
    std::ostringstream dat2NameStream(out2);
    dat2NameStream<<BPath<<"/"<<out2;
    std::string dat2Name = dat2NameStream.str();
    ofstream file2(dat2Name.c_str());

    QString output3="otimes.dat";
    string out3 = output3.toUtf8().constData();
    std::ostringstream dat3NameStream(out3);
    dat3NameStream<<BPath<<"/"<<out3;
    std::string dat3Name = dat3NameStream.str();
    ofstream file3(dat3Name.c_str());


        ui->customPlot->clearGraphs();

    V1.resize(1.0/dphi);
    V2.resize(1.0/dphi);
    t.resize(1.0/dphi);
    int phistep = 1.0/dphi;

    for(int m=0; m<phistep; m++){

    t[m]=T0+(m+1)*dphi*P;

    if(e!=0){
    a1=M_PI*(t[m]-T0)/P-3*e;
    a2=2*M_PI*(t[m]-T0)/P+3*e;
    dE2=0;

    for(int i=0; i<(a2-a1)/dx; i++){
    xx=a1+i*dx;
    E1=xx;
    E2=e*sin(xx)+2*M_PI*(t[m]-T0)/P;
    dE1=E1-E2;
    //cout <<x<<"\t"<<E1-E2<<"\n";
    /*if(m==0){
       E=0;
        i=(a2-a1)/dx;
    }*/
    if((dE1<0) & (dE2>0)){
    E=xx-dx;
    //cout <<"E = "<<x-dx-a1<<" + "<<a1<<"\n";
    i=(a2-a1)/dx;
    }
    if((dE1>0) & (dE2<0)){
    E=xx-dx;
    //cout <<"E = "<<x-dx-a1<<" + "<<a1<<"\n";
    i=(a2-a1)/dx;
    }
    dE2=E1-E2;
    }
    theta=2*(atan(tan(E/2)*sqrt((1+e)/(1-e))));
    }
    else{
        E = M_PI*(t[m]-T0)/P;
        theta=2*(atan(tan(E/2)));
    }


    V1[m] = V + K1*(cos(theta+w1)+e*cos(w1));
    V2[m] = V + K2*(cos(theta+w2)+e*cos(w2));

    file<<setprecision(14)<<t[m]<<" "<<V1[m]<<" "<<V2[m]<<endl;
    file2<<setprecision(14)<<V1[m]<<" "<<V2[m]<<endl;
    file3<<setprecision(14)<<t[m]<<endl;
    }

    file.close();

    if(ui->checkBox->isChecked()){

    string eins, zwei, line;

    int min=ui->spinBox_2->value();
    int max=ui->spinBox_3->value();
    int rvs = max-min+1;
    rvb1.resize(rvs);
    rvb2.resize(rvs);
    rvb3.resize(rvs);
    rvb4.resize(rvs);
    rvb5.resize(rvs);

    for(int u=min; u<=max; u++){

        QString input=ui->lineEdit_6->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<BPath<<"/"<<data<<u<<".txt";
        std::string datName = datNameStream.str();
        ifstream dat(datName.c_str());

        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QString fError= QString::number(u);
            QMessageBox::information(this, "Error", "File "+qBPath+"/"+input+fError+".txt does not exist!");
           return;
        }

        dat >> eins >>zwei;
        istringstream ist(eins);
        ist >> rvb1[u];
        istringstream ist2(zwei);
        ist2 >> rvb2[u];
        rvb3[u]=rvb1[u]+rvb2[u];
        if(ui->checkBox_4->isChecked()){
        rvb3[u]=-rvb3[u];
        rvb1[u]=-rvb1[u];
        }
        rvb4[u]=rvb1[u]-V1[u];
        rvb5[u]=rvb3[u]-V2[u];

        dat.close();

    }

    QString inputt=ui->lineEdit_9->text();
    string data2 = inputt.toUtf8().constData();
    ostringstream dat2NameStream(data2);
    dat2NameStream<<BPath<<"/"<<data2;
    string dat2Name = dat2NameStream.str();
    ifstream dat2(dat2Name.c_str());

    QFile checkfile2(dat2Name.c_str());

    if(!checkfile2.exists()){
        qDebug()<<"The file "<<checkfile2.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "Time file "+qBPath+"/"+inputt+" does not exist!");
       return;
    }

    int nlines=0;

    while(std::getline(dat2, line))
               ++ nlines;

            dat2.clear();
            dat2.seekg(0, ios::beg);

            cctimes.resize(nlines);

            for(int i=0; i<nlines; i++){
                dat2 >> eins;
                istringstream ist3(eins);
                ist3 >> cctimes[i];
            }

            dat2.close();

            if(ui->checkBox_7->isChecked()){


                std::ostringstream file2NameStream("croco_rv.dat");
                file2NameStream<<BPath<<"/"<<"croco_rv.dat";
                std::string file2Name = file2NameStream.str();
                ofstream file2(file2Name.c_str());

                for(int i =0; i<nlines; i++){
                file2<<setprecision(14)<<cctimes[i]<<" "<<rvb1[i]<<" "<<rvb3[i]<<endl;
                }

                file2.close();

            }

    }

     QPen pen;
     pen.setWidth(2);
     pen.setColor(Qt::red);
     QPen pen2;
     pen2.setWidth(2);
     pen2.setColor(Qt::blue);
     QPen pen3;
     pen3.setWidth(2);
     pen3.setColor(Qt::green);
     QPen pen4;
     pen4.setWidth(2);
     pen4.setColor(Qt::black);
     ui->customPlot->addGraph();
     ui->customPlot->graph(0)->setData(t, V1);
     ui->customPlot->addGraph();
     ui->customPlot->graph(1)->setData(t, V2);
     ui->customPlot->addGraph();
     ui->customPlot->graph(2)->setLineStyle(QCPGraph::lsNone);
     ui->customPlot->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
     ui->customPlot->graph(2)->setData(cctimes, rvb1);
     ui->customPlot->addGraph();
     ui->customPlot->graph(3)->setLineStyle(QCPGraph::lsNone);
     ui->customPlot->graph(3)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
     ui->customPlot->graph(3)->setData(cctimes, rvb3);
     ui->customPlot->addGraph();
     ui->customPlot->graph(4)->setData(cctimes, rvb4);
     ui->customPlot->addGraph();
     ui->customPlot->graph(5)->setData(cctimes, rvb5);
     ui->customPlot->graph(0)->setPen(pen);
     ui->customPlot->graph(1)->setPen(pen);
     ui->customPlot->graph(2)->setPen(pen2);
     ui->customPlot->graph(3)->setPen(pen2);
     ui->customPlot->graph(4)->setPen(pen3);
     ui->customPlot->graph(5)->setPen(pen4);
     ui->customPlot->graph(0)->rescaleAxes();
     ui->customPlot->graph(1)->rescaleAxes(true);
     ui->customPlot->graph(2)->rescaleAxes(true);
     ui->customPlot->graph(3)->rescaleAxes(true);

     ui->customPlot->xAxis->setLabel("Time");
     ui->customPlot->yAxis->setLabel("Velocity [km/s]");
     ui->customPlot->replot();

     this->setCursor(QCursor(Qt::ArrowCursor));

}

//*************************************************
// create simple SB2 data
//*************************************************
void BinaryTool::on_pushButton_3_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));

    int num_lines1=0, wsteps;
    int num_lines2=0;
    int num_lines3=0;
    int place=0;
    QVector<double> lineswt(num_lines3);
    QVector<double> linesit(num_lines3);
    QVector<double> intenst(num_lines3);
    QVector<double> FWHMt(num_lines3);
    QVector<double> FWHMn(num_lines2);
    double lw, uw, dw, w, vsi1, vsi2, Intensi=0, tempi1=0, tempi2=0, SNR, c=299792.458;

    lw=ui->doubleSpinBox_11->value();
    uw=ui->doubleSpinBox_12->value();
    dw=ui->doubleSpinBox_13->value();
    vsi1=ui->doubleSpinBox_14->value();
    vsi2=ui->doubleSpinBox_15->value();
    SNR=ui->spinBox->value();

    wsteps = (uw-lw)/dw;

    string line, eins, zwei, drei, vier;

    std::ostringstream file2NameStream("templateA.txt");
    file2NameStream<<BPath<<"/"<<"templateA.txt";
    std::string file2Name = file2NameStream.str();
    ofstream file2(file2Name.c_str());

    std::ostringstream file3NameStream("templateB.txt");
    file3NameStream<<BPath<<"/"<<"templateB.txt";
    std::string file3Name = file3NameStream.str();
    ofstream file3(file3Name.c_str());

    V1.resize(1/dphi);
    V2.resize(1/dphi);
    t.resize(1/dphi);

    QString output3="times.dat";
    string out3 = output3.toUtf8().constData();
    std::ostringstream dat3NameStream(out3);
    dat3NameStream<<BPath<<"/"<<out3;
    std::string dat3Name = dat3NameStream.str();
    ofstream file4(dat3Name.c_str());

    list1 = ui->lineEdit->text();
    string input11 = list1.toUtf8().constData();
    ostringstream input11NameStream(input11);
    input11NameStream<<BPath<<"/"<<input11;
    string input1Name = input11NameStream.str();
    ifstream input1(input1Name.c_str());

    QFile checkfile1(input1Name.c_str());

            if(!checkfile1.exists()){
                qDebug()<<"Error 1: The file "<<checkfile1.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error", "Error 1: Line list "+qBPath+"/"+list1 +" for primary does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }
            while(std::getline(input1, line))
                       ++ num_lines1;

                    input1.clear();
                    input1.seekg(0, ios::beg);



                    double linesw1[num_lines1];	// wavelengths of lines spectrum one
                    double linesw01[num_lines1];	// rest wavelengths of lines
                    double linesi1[num_lines1];	// line intensities
                    double intens1[num_lines1];	// resulting continuum intensity for each line-pair
                    //double FWHM1[num_lines1];	// FWHM of lines spectrum one
                    double temi1[num_lines1];	// intensity of primary template for each line
                    double spoti1[num_lines1];
                    //double intensspot1[num_lines1];
                    //double spotw1[num_lines1];


                    for (int i =0; i < num_lines1; i++){
                         input1 >> eins >> zwei >> drei;
                         istringstream istr(eins+" "+zwei+" "+drei);
                         istr >> linesw01[i];
                         istringstream istr2(zwei);
                         istr2 >> linesi1[i];
                         istringstream istr3(drei);
                         istr3 >> spoti1[i];;
                            }


    list2 = ui->lineEdit_2->text();
    string input22 = list2.toUtf8().constData();
    ostringstream input22NameStream(input22);
    input22NameStream<<BPath<<"/"<<input22;
    string input2Name = input22NameStream.str();
    ifstream input2(input2Name.c_str());

    QFile checkfile2(input2Name.c_str());

            if(!checkfile2.exists()){
                qDebug()<<"Error 2: The file "<<checkfile2.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error", "Error 2: Line list "+qBPath+"/"+list2 +" for secondary does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }

            while(std::getline(input2, line))
                       ++ num_lines2;

                    input2.clear();
                    input2.seekg(0, ios::beg);

                    double linesw2[num_lines2];	// wavelengths of lines spectrum two
                    double linesw02[num_lines2];	// rest wavelengths of lines
                    double linesi2[num_lines2];	// line intensities
                    double intens2[num_lines2];	// resulting continuum intensity for each line-pair
                    //double FWHM2[num_lines2];	// FWHM of lines spectrum two
                    double temi2[num_lines2];	// intensity of secondary template for each line
                    double spoti2[num_lines2];
                    //double intensspot2[num_lines2];
                    //double spotw2[num_lines2];

                    for (int i =0; i < num_lines2; i++){
                        input2 >> eins >> zwei >> drei;
                        istringstream istr5(eins+" "+zwei+" "+drei);
                        istr5 >> linesw02[i];
                        istringstream istr6(zwei);
                        istr6 >> linesi2[i];
                        istringstream istr7(drei);
                        istr7 >> spoti2[i];
                        }

                    if(ui->checkBox_2->isChecked()){
                    QString list3;

                    if(ui->comboBox->currentIndex()==0){
                        list3 = "oxy.dat";
                    }
                    if(ui->comboBox->currentIndex()==1){
                        list3 = "water.dat";
                    }
                    if(ui->comboBox->currentIndex()==2){
                        list3 = "telluric.dat";
                    }
                    if(ui->comboBox->currentIndex()==3){
                        list3 = "orion.dat";
                    }
                    if(ui->comboBox->currentIndex()==4){
                        list3 = "hanuschik.dat";
                    }

                    string input23 = list3.toUtf8().constData();
                    ostringstream input23NameStream(input23);
                    input23NameStream<<input23;
                    string input3Name = input23NameStream.str();
                    ifstream input3(input3Name.c_str());

                    QFile checkfile3(input3Name.c_str());

                          if(!checkfile3.exists()){
                            qDebug()<<"Error: The file "<<checkfile3.fileName()<<" does not exist.";
                            QMessageBox::information(this, "Error", "Error: Line list telluric features does not exist!");
                            this->setCursor(QCursor(Qt::ArrowCursor));
                            return;
                                   }

                          while(std::getline(input3, line))
                               ++ num_lines3;

                               input3.clear();
                               input3.seekg(0, ios::beg);

                          lineswt.resize(num_lines3);
                          linesit.resize(num_lines3);
                          intenst.resize(num_lines3);
                          FWHMt.resize(num_lines3);
                          FWHMn.resize(num_lines3);

                          double ltell;

                          for (int i =0; i < num_lines3; i++){
                              input3 >> eins >> zwei >> drei;
                              istringstream istr8(eins+" "+zwei+" "+drei);
                              istr8 >> ltell;
                              if((ltell>=lw)&(ltell<=uw)){
                              lineswt[place]=ltell;
                              istringstream istr9(zwei);
                              istr9 >> linesit[place];
                              linesit[place]=linesit[place]*IF;
                              istringstream istr11(drei);
                              istr11 >> FWHMt[place];
                              ++place;
                              }
                              }
                    }


    for(int m=0; m<1/dphi; m++){
    t[m]=T0+(m+1)*dphi*P;

    file4<<setprecision(14)<<t[m]<<endl;

    if(e!=0){
    a1=M_PI*(t[m]-T0)/P-2*e;
    a2=2*M_PI*(t[m]-T0)/P+3*e;
    dE2=0;
    for(int i=0; i<(a2-a1)/dx; i++){
    xx=a1+i*dx;
    E1=xx;
    E2=e*sin(xx)+2*M_PI*(t[m]-T0)/P;
    dE1=E1-E2;
    if((dE1<0) & (dE2>0)){
    E=xx-dx;
    i=(a2-a1)/dx;
    }
    if((dE1>0) & (dE2<0)){
    E=xx-dx;
    i=(a2-a1)/dx;
    }
    dE2=E1-E2;
    }}

    else{
        E = M_PI*(t[m]-T0)/P;
    }

    theta=2*(atan(tan(E/2)*sqrt((1+e)/(1-e))));

    V1[m] = V + K1*(cos(theta+w1)+e*cos(w1));
    V2[m] = V + K2*(cos(theta+w2)+e*cos(w2));

    for(int n=0; n < num_lines1; n++){
        linesw1[n]=(V1[m]/c+1)*linesw01[n];
        }
    for(int n=0; n < num_lines2; n++){
        linesw2[n]=(V2[m]/c+1)*linesw02[n];
        }

    std::ostringstream file1NameStream("spectra_");
    file1NameStream<<BPath<<"/"<<"spectra_"<<m<<".txt";
    std::string file1Name = file1NameStream.str();
    ofstream file1(file1Name.c_str());

    for(int e=0; e<wsteps; e++){
        w=dw*e+lw;

        file1 <<w<< "\t";

        for(int n=0; n < num_lines1; n++){
        intens1[n]=linesi1[n]*exp(-0.25/(pow((vsi1/c*linesw1[n]),2))*pow((linesw1[n]-w),2));
        Intensi+=intens1[n];
        }

        for(int n=0; n < num_lines2; n++){
        intens2[n]=linesi2[n]*exp(-0.25/(pow((vsi2/c*linesw2[n]),2))*pow((linesw2[n]-w),2));
        Intensi+=intens2[n];
        }

        if(m==1){ // generate template
            for(int n=0; n < num_lines1; n++){
                temi1[n]=(1-linesi1[n]*num_lines1*exp(-0.25/(pow((vsi1/c*linesw01[n]),2))*pow((linesw01[n]-w),2)))/num_lines1;
                tempi1+=temi1[n];
                }
                for(int n=0; n < num_lines2; n++){
                temi2[n]=(1-linesi2[n]*num_lines2*exp(-0.25/(pow((vsi2/c*linesw02[n]),2))*pow((linesw02[n]-w),2)))/num_lines2;
                tempi2+=temi2[n];
                }

                file2<<w<< "\t"<<tempi1/2<<"\n";
                file3<<w<< "\t"<<tempi2/2<<"\n";
                tempi1=0;
                tempi2=0;
        }

        if(ui->checkBox_2->isChecked()){
            for(int n=0; n<place; n++){
            intenst[n]=linesit[n]*exp(-2.77254/(pow(FWHMt[n],2)+pow((2*dw),2))*pow((lineswt[n]-w),2));
            Intensi+=intenst[n];
            }
        }

        if(ui->checkBox_2->isChecked()){
        file1<<1-Intensi/3+gauss()/SNR+1/SNR<<"\n";
        }
        else {
            file1<<1-Intensi/2+gauss()/SNR+1/SNR<<"\n";
        }
        Intensi=0;

    }
        file1.close();
    }
    file2.close();
    file3.close();

    this->setCursor(QCursor(Qt::ArrowCursor));
}

//*************************************************
// random numbers
//*************************************************
double BinaryTool::std_rand()
{
       return rand() / (RAND_MAX + 1.0);
}

//*************************************************
// gaussian distributed random numbers
//*************************************************
double BinaryTool::gauss(){

       double p1, p2, u, e1;
       do {
           p1 = std_rand()-1.0;
           p2 = std_rand()-1.0;
           u = p1*p1 + p2*p2;
           } while (u >= 1.0);
           u = sqrt((-5.5451 * log(u))/u);
           return e1 = p1 * u;


           }

void BinaryTool::on_lineEdit_3_textChanged()
{
    qBPath=ui->lineEdit_3->text();
    BPath = qBPath.toUtf8().constData();
}

//*****************************************************
//combine given spectra
//*****************************************************
void BinaryTool::on_pushButton_4_clicked()
{
    BinaryTool::on_pushButton_2_clicked();

    this->setCursor(QCursor(Qt::WaitCursor));

    string line, eins, zwei;
    const double c=299792.458;
    double ratio=ui->doubleSpinBox->value();//+1;

    QString comp1 = ui->lineEdit_4->text();
    string input11 = comp1.toUtf8().constData();
    ostringstream input1NameStream(input11);
    input1NameStream<<BPath<<"/"<<input11;
    string input1Name = input1NameStream.str();
    ifstream input1(input1Name.c_str());

    QFile checkfile1(input1Name.c_str());

            if(!checkfile1.exists()){
                qDebug()<<"Error 3: The file "<<checkfile1.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error", "Error 3: Spectrum "+qBPath+"/" +comp1+ " of primary does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }

            int number=0;

            while(std::getline(input1, line))
                       ++ number;

             input1.clear();
             input1.seekg(0, ios::beg);

    QVector<double> WC1(number), IC1(number);


    for (int i =0; i < number; i++){
        input1 >> eins >> zwei;
        istringstream istr3(eins+" "+zwei);
        istr3 >> WC1[i];
        istringstream istr4(zwei);
        istr4 >> IC1[i];
        IC1[i]=IC1[i];//*(1-1/ratio);
        }

    input1.close();

    QString comp2 = ui->lineEdit_5->text();
    string input22 = comp2.toUtf8().constData();
    ostringstream input2NameStream(input22);
    input2NameStream<<BPath<<"/"<<input22;
    string input2Name = input2NameStream.str();
    ifstream input2(input2Name.c_str());

    QFile checkfile2(input2Name.c_str());

            if(!checkfile2.exists()){
                qDebug()<<"Error 4: The file "<<checkfile2.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error", "Error 4: Spectrum "+qBPath+"/" +comp2+ " of secondary does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }

            int number2 =0;

            while(std::getline(input2, line))
                       ++ number2;

             input2.clear();
             input2.seekg(0, ios::beg);

             if(number!=number2){
                 qDebug()<<"Error 5: Different data size";
                 QMessageBox::information(this, "Error", "Error 5: Different size of data");
                 this->setCursor(QCursor(Qt::ArrowCursor));
                 return;
             }

    QVector<double> WC2(number2), IC2(number2);

                    for (int i =0; i < number2; i++){
                        input2 >> eins >> zwei;
                        istringstream istr5(eins+" "+zwei);
                        istr5 >> WC2[i];
                        istringstream istr6(zwei);
                        istr6 >> IC2[i];
                        IC2[i]=IC2[i]/ratio;
                        }

                    input2.close();

           if(WC1[1]-WC1[0]!=WC2[1]-WC2[0]){
               qDebug()<<"Error 6: Data with unequal binning!";
               QMessageBox::information(this, "Error", "Error 6: Data with unequal binning!");
               this->setCursor(QCursor(Qt::ArrowCursor));
               return;
           }

           if(WC1[0]!=WC2[0]){
               qDebug()<<"Error 7: Data with unequal start wavelength!";
               QMessageBox::information(this, "Error", "Error 7: Data with unequal start wavelength!");
               this->setCursor(QCursor(Qt::ArrowCursor));
               return;
           }

           std::ostringstream filet1NameStream("tempA.txt");
           filet1NameStream<<BPath<<"/"<<"tempA.txt";
           std::string filet1Name = filet1NameStream.str();
           ofstream tem1(filet1Name.c_str());

           for(int i=0; i<number2; i++){
           tem1<<WC1[i]<<" "<<IC1[i]<<endl;
       }

               std::ostringstream filetNameStream("tempB.txt");
               filetNameStream<<BPath<<"/"<<"tempB.txt";
               std::string filetName = filetNameStream.str();
               ofstream tem(filetName.c_str());

               for(int i=0; i<number2; i++){
               tem<<WC2[i]<<" "<<IC2[i]<<endl;
           }

           std::ostringstream timeNameStream("time.txt");
           timeNameStream<<BPath<<"/"<<"time.txt";
           std::string timeName = timeNameStream.str();
           ofstream tim(timeName.c_str());

           int shift1, shift2, aa=0;
           //double diff=WC1[1]-WC1[0];
           QVector<double> WCs1(number), WCs2(number2), CI(number);

           for(int i=0; i<t.size(); i++){

               tim<<setprecision(14)<<t[i]<<endl;

               QString binar = ui->lineEdit_7->text();
               string bina = binar.toUtf8().constData();
               ostringstream out2NameStream(bina);
               out2NameStream<<BPath<<"/"<<bina<<i<<".txt";
               string out2Name = out2NameStream.str();
               ofstream file1(out2Name.c_str());

               for(int n = 0; n<WC1.size(); n++){
                   WCs1[n]=WC1[n]*(1+V1[i]/c);
               }

               for(int n = 0; n<WC2.size(); n++){
                   WCs2[n]=WC2[n]*(1+V2[i]/c);
               }

               aa = 0;

               for(int e=0; e<number; e++){
                   for(int u=aa; u<aa+500; u++){

                    if((WCs1[u]==WC1[e])){
                        CI[e]=IC1[u];

                        aa=u;
                    }
                    if((WCs1[u]<WC1[e]) & (WCs1[u+1]>WC1[e])){
                        CI[e]=IC1[u]+(WC1[e]-WCs1[u])/(WCs1[u+1]-WCs1[u])*(IC1[u+1]-IC1[u]);

                        aa=u;
                    }
                   }
               }


               aa=0;

               for(int e=0; e<number; e++){
                   for(int u=aa; u<aa+500; u++){

                    if((WCs2[u]==WC1[e])){
                        CI[e]+=IC2[u];
                        aa=u;
                    }
                    if((WCs2[u]<WC1[e]) & (WCs2[u+1]>WC1[e])){
                        CI[e]+=IC2[u]+(WC1[e]-WCs2[u])/(WCs2[u+1]-WCs2[u])*(IC2[u+1]-IC2[u]);
                        aa=u;
                    }
                   }
               }

                for(int e=0; e<number; e++){
                    file1<<WC1[e]<<" "<<CI[e]*ratio/(ratio+1)<<endl;
                }

           }

           tim.close();

           this->setCursor(QCursor(Qt::ArrowCursor));

}


//*****************************************************
// simple spectra for SB1 system
//*****************************************************
void BinaryTool::on_pushButton_5_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));

    int num_lines1=0, wsteps;
    int num_lines2=0;
    int num_lines3=0;
    int place=0;
    QVector<double> lineswt(num_lines3);
    QVector<double> linesit(num_lines3);
    QVector<double> intenst(num_lines3);
    QVector<double> FWHMt(num_lines3);
    QVector<double> FWHMn(num_lines2);
    double lw, uw, dw, w, vsi1, Intensi=0, tempi1=0, SNR, c=299792.458, vsi11, pulP, pulA;
    pulP=ui->doubleSpinBox_16->value();
    pulA=ui->doubleSpinBox_9->value();

    lw=ui->doubleSpinBox_11->value();
    uw=ui->doubleSpinBox_12->value();
    dw=ui->doubleSpinBox_13->value();
    vsi1=ui->doubleSpinBox_14->value();
    SNR=ui->spinBox->value();

    wsteps = (uw-lw)/dw;

    string line, eins, zwei, drei;

    std::ostringstream file2NameStream("templateA.txt");
    file2NameStream<<BPath<<"/"<<"templateA.txt";
    std::string file2Name = file2NameStream.str();
    ofstream file2(file2Name.c_str());

    V1.resize(1/dphi);
    V2.resize(1/dphi);
    t.resize(1/dphi);


    list1 = ui->lineEdit->text();
    string input11 = list1.toUtf8().constData();
    ostringstream input11NameStream(input11);
    input11NameStream<<input11;
    string input1Name = input11NameStream.str();
    ifstream input1(input1Name.c_str());

    QFile checkfile1(input1Name.c_str());

            if(!checkfile1.exists()){
                qDebug()<<"Error 1: The file "<<checkfile1.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error", "Error 1: Line List for primary does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }
            while(std::getline(input1, line))
                       ++ num_lines1;

                    input1.clear();
                    input1.seekg(0, ios::beg);



                    double linesw1[num_lines1];	// wavelengths of lines spectrum one
                    double linesw01[num_lines1];	// rest wavelengths of lines
                    double linesi1[num_lines1];	// line intensities
                    double intens1[num_lines1];	// resulting continuum intensity for each line-pair
                    //double FWHM1[num_lines1];	// FWHM of lines spectrum one
                    double temi1[num_lines1];	// intensity of primary template for each line
                    double spoti1[num_lines1];
                    //double intensspot1[num_lines1];
                    //double spotw1[num_lines1];


                    for (int i =0; i < num_lines1; i++){
                         input1 >> eins >> zwei >> drei;
                         istringstream istr(eins+" "+zwei+" "+drei);
                         istr >> linesw01[i];
                         istringstream istr2(zwei);
                         istr2 >> linesi1[i];
                         istringstream istr3(drei);
                         istr3 >> spoti1[i];;
                            }
                    if(ui->checkBox_2->isChecked()){
                    QString list3;
                    if(ui->comboBox->currentIndex()==0){
                        list3 = "oxy.dat";
                    }
                    if(ui->comboBox->currentIndex()==1){
                        list3 = "water.dat";
                    }
                    if(ui->comboBox->currentIndex()==2){
                        list3 = "telluric.dat";
                    }
                    if(ui->comboBox->currentIndex()==3){
                        list3 = "orion.dat";
                    }
                    if(ui->comboBox->currentIndex()==4){
                        list3 = "hanuschik.dat";
                    }

                    string input23 = list3.toUtf8().constData();
                    ostringstream input23NameStream(input23);
                    input23NameStream<<input23;
                    string input3Name = input23NameStream.str();
                    ifstream input3(input3Name.c_str());

                    QFile checkfile3(input3Name.c_str());

                          if(!checkfile3.exists()){
                            qDebug()<<"Error: The file "<<checkfile3.fileName()<<" does not exist.";
                            QMessageBox::information(this, "Error", "Error: Line list "+list3+" features does not exist!");
                            this->setCursor(QCursor(Qt::ArrowCursor));
                            return;
                                   }

                          while(std::getline(input3, line))
                               ++ num_lines3;

                               input3.clear();
                               input3.seekg(0, ios::beg);

                          lineswt.resize(num_lines3);
                          linesit.resize(num_lines3);
                          intenst.resize(num_lines3);
                          FWHMt.resize(num_lines3);
                          FWHMn.resize(num_lines3);

                          double ltell;

                          for (int i =0; i < num_lines3; i++){
                              input3 >> eins >> zwei >> drei;
                              istringstream istr8(eins+" "+zwei+" "+drei);
                              istr8 >> ltell;
                              if((ltell>=lw)&(ltell<=uw)){
                              lineswt[place]=ltell;
                              istringstream istr9(zwei);
                              istr9 >> linesit[place];
                              linesit[place]=linesit[place]*IF;
                              istringstream istr11(drei);
                              istr11 >> FWHMt[place];
                              ++place;
                              }
                              }
                    }

                    std::ostringstream rvNameStream("velocities.txt");
                    rvNameStream<<BPath<<"/"<<"velocities.txt";
                    std::string rvName = rvNameStream.str();
                    ofstream rv(rvName.c_str());

                    //double varii;

                  for(int m=0; m<1/dphi; m++){

                     /* if(m % 2){
                          varii=0.5;
                      }
                      else varii =1;*/

                  t[m]=T0+(m+1)*dphi*P;

                  if(e!=0){
                  a1=M_PI*(t[m]-T0)/P-2*e;
                  a2=2*M_PI*(t[m]-T0)/P+3*e;
                  dE2=0;
                  for(int i=0; i<(a2-a1)/dx; i++){
                  xx=a1+i*dx;
                  E1=xx;
                  E2=e*sin(xx)+2*M_PI*(t[m]-T0)/P;
                  dE1=E1-E2;
                  if((dE1<0) & (dE2>0)){
                  E=xx-dx;
                  i=(a2-a1)/dx;
                  }
                  if((dE1>0) & (dE2<0)){
                  E=xx-dx;
                  i=(a2-a1)/dx;
                  }
                  dE2=E1-E2;
                  }}
                  else{
                      E=M_PI*(t[m]-T0)/P;
                  }

                  theta=2*(atan(tan(E/2)*sqrt((1+e)/(1-e))));

                  V1[m] = V + K1*(cos(theta+w1)+e*cos(w1));

                  rv<<V1[m]<<endl;

                  if(ui->checkBox_3->isChecked()){
                  vsi11=vsi1+pulA*sin(2*M_PI*pulP*t[m]);
                  }
                  else vsi11=vsi1;

                  for(int n=0; n < num_lines1; n++){
                      linesw1[n]=(V1[m]/c+1)*linesw01[n];
                      }

                  std::ostringstream file1NameStream("spectra_");
                  file1NameStream<<BPath<<"/"<<"spectra_"<<m<<".txt";
                  std::string file1Name = file1NameStream.str();
                  ofstream file1(file1Name.c_str());

                  for(int e=0; e<wsteps; e++){
                      w=dw*e+lw;
                      file1 <<w<< "\t";
                      file2 <<w<< "\t";

                      for(int n=0; n < num_lines1; n++){
                      intens1[n]=linesi1[n]*exp(-0.25/(pow((vsi11/c*linesw1[n]),2))*pow((linesw1[n]-w),2));
                      Intensi+=intens1[n];
                      }

                      if(m==1){ // generate template
                          for(int n=0; n < num_lines1; n++){
                              temi1[n]=linesi1[n]*exp(-0.25/(pow((vsi1/c*linesw01[n]),2))*pow((linesw01[n]-w),2));
                              tempi1+=temi1[n];
                              }

                              file2<<1-tempi1<<"\n";
                              tempi1=0;
                      }

                      if(ui->checkBox_2->isChecked()){
                          for(int n=0; n<place; n++){
                          intenst[n]=linesit[n]*exp(-2.77254/(pow(FWHMt[n],2)+pow((2*dw),2))*pow((lineswt[n]-w),2));
                          Intensi+=intenst[n];
                          }
                      }

                      if(ui->checkBox_2->isChecked()){
                      file1<<1-Intensi/2+gauss()/SNR+1/SNR/2<<"\n";
                      }
                      else {
                          file1<<1-Intensi+gauss()/SNR+1/SNR/2<<"\n";
                      }
                      Intensi=0;

                  }
                    file1.close();
                  }
                  file2.close();

                  this->setCursor(QCursor(Qt::ArrowCursor));
}

void BinaryTool::on_doubleSpinBox_2_valueChanged()
{
    IF=ui->doubleSpinBox_2->value();
}

//*************************************************
//Save as
//*************************************************
void BinaryTool::on_pushButton_6_clicked()
{
    if(ui->checkBox_5->isChecked()){
        QString sav=ui->lineEdit_8->text();
        QString save=qBPath+"/"+sav+".pdf";
        ui->customPlot->savePdf(save);
    }
    if(ui->checkBox_6->isChecked()){
        QString sav=ui->lineEdit_8->text();
        QString save=qBPath+"/"+sav+".png";
        ui->customPlot->savePng(save);
    }
}

void BinaryTool::on_spinBox_4_valueChanged()
{
    QFont legendFont = font();
    legendFont.setPointSize(ui->spinBox_4->value());
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);
}


void BinaryTool::on_doubleSpinBox_17_valueChanged()
{
    P = ui->doubleSpinBox_17->value();
}
