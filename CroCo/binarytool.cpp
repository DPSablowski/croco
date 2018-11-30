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

double BTe, dphi, t1, V, w1, w2, K1, K2, theta, BTE, IF, BTT0, BTP, BTt, E;
QVector<double> t(1), V1(1), V2(1);
QString list1, list2;
QString qBPath;
string BPath;
QVector<double> rvb1(1), rvb2(1), rvb3(1), rvb4(1), rvb5(1), cctimes(1);
QVector<double> PERa(1), ECCa(1), AMPAa(1), AMPBa(1), GAMa(1), PERIa(1), LPERIa(1);


BinaryTool::BinaryTool(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BinaryTool)
{
    ui->setupUi(this);
    this->setWindowTitle("Binary Tool");

    string sbin = "BinaryData.dat";

    QFile qBin(sbin.c_str());

    if(!qBin.exists()){
        qDebug()<<"No data base file for orbits of binaries present.";
        QMessageBox::information(this, "Error", "Data base "+qBin.fileName()+" of orbital elements not present.");
    }


    else{
        ifstream binaries(sbin.c_str());
        int lines=0;
        string zeile1, eins1, zwei1, drei1, vier1, fuenf1, sechs1, sieben1, acht1;

        while(std::getline(binaries, zeile1))
        ++ lines;

        binaries.clear();
        binaries.seekg(0, ios::beg);

        QVector<string> names(lines);

        PERa.resize(lines);
        ECCa.resize(lines);
        AMPAa.resize(lines);
        AMPBa.resize(lines);
        GAMa.resize(lines);
        PERIa.resize(lines);
        LPERIa.resize(lines);

        for(int i=0; i < lines; i++){
            binaries >> eins1 >> zwei1 >> drei1 >> vier1 >> fuenf1 >> sechs1 >> sieben1 >> acht1;
            istringstream str1(eins1);
            str1 >> names[i];
            QString qstr = QString::fromStdString(str1.str());
            ui->comboBox_2->addItem(qstr);
            istringstream str2(zwei1);
            str2 >> PERa[i];
            istringstream str3(drei1);
            str3 >> ECCa[i];
            istringstream str4(vier1);
            str4 >> AMPAa[i];
            istringstream str5(fuenf1);
            str5 >> AMPBa[i];
            istringstream str6(sechs1);
            str6 >> GAMa[i];
            istringstream str7(sieben1);
            str7 >> PERIa[i];
            istringstream str8(acht1);
            str8 >> LPERIa[i];
        }

        ui->doubleSpinBox_17->setValue(PERa[0]);
        ui->doubleSpinBox_3->setValue(ECCa[0]);
        ui->doubleSpinBox_6->setValue(AMPAa[0]);
        ui->doubleSpinBox_7->setValue(AMPBa[0]);
        ui->doubleSpinBox_8->setValue(GAMa[0]);
        ui->doubleSpinBox_5->setValue(PERIa[0]);
        ui->doubleSpinBox_4->setValue(LPERIa[0]);
    }

    ui->lineEdit->setText("Li_list.dat");
    ui->lineEdit_2->setText("Li2_list.dat");

    ui->doubleSpinBox_10->setValue(0.05);
    ui->doubleSpinBox_14->setValue(20);
    ui->doubleSpinBox_15->setValue(5);
    ui->doubleSpinBox_9->setValue(0.2);
    ui->doubleSpinBox_16->setValue(5);

    ui->comboBox->addItem("HITRAN O2");
    ui->comboBox->addItem("HITRAN H2O");
    ui->comboBox->addItem("HITRAN O2 + H2O");
    ui->comboBox->addItem("Orion");
    ui->comboBox->addItem("UVES Hanuschik");

    ui->lineEdit_4->setText("phase_");
    ui->lineEdit_5->setText("templateB.txt");
    ui->lineEdit_6->setText("binaryrv_");
    ui->lineEdit_7->setText("spot_");
    ui->lineEdit_10->setText("ratios.dat");
    ui->lineEdit_11->setText(".dat");

    ui->spinBox_6->setEnabled(false);
    ui->spinBox_7->setEnabled(false);
    ui->lineEdit_11->setEnabled(false);

    ui->spinBox_3->setValue(19);

    ui->lineEdit_3->setText(QDir::currentPath());
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

void BinaryTool::seData(QString str1)
{
    ui->lineEdit_3->setText(str1);
    qBPath=ui->lineEdit_3->text();
    BPath = qBPath.toUtf8().constData();
}

double BTfunction (double X[], double RVCt, double RVCT0, double RVCP, double RVCe){
    double func;

    func= abs(RVCe*sin(X[0])+2*M_PI*(RVCt-RVCT0)/RVCP-X[0]);

    return func;

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
   BTe=ui->doubleSpinBox_3->value();
}

void BinaryTool::on_doubleSpinBox_5_valueChanged()
{
    BTT0=ui->doubleSpinBox_5->value();
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
    if(dphi>0.0){
        ui->spinBox_5->setMaximum(1/dphi-1);
    }
}

//*************************************************
// calculate RVs
//*************************************************
void BinaryTool::CalcRVs(){

    K1=ui->doubleSpinBox_6->value();
    BTT0=ui->doubleSpinBox_5->value();
    BTe=ui->doubleSpinBox_3->value();
    w1=ui->doubleSpinBox_4->value()*M_PI/180;
    w2=w1+M_PI;
    K2=ui->doubleSpinBox_7->value();
    V=ui->doubleSpinBox_8->value();


    string eins, zwei, drei, line;
    int number=0;

    QString qratio = ui->lineEdit_10->text();
    string sratio = qratio.toUtf8().constData();
    ostringstream sratioNameStream(sratio);
    sratioNameStream<<BPath<<"/"<<sratio;
    string sratioName = sratioNameStream.str();

    QFile checkfile(sratioName.c_str());

            if(!checkfile.exists()){
                qDebug()<<"Error 3: The file "<<checkfile.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error", "Error 3: Spectrum "+checkfile.fileName()+" of primary does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }
            ifstream sRatio(sratioName.c_str());

            while(std::getline(sRatio, line))
                       ++ number;

             sRatio.clear();
             sRatio.seekg(0, ios::beg);

    QVector<double> phas(number), ratio1(number), ratio2(number);

    for (int i =0; i < number; i++){
        sRatio >> eins >> zwei >> drei;
        istringstream ist(eins);
        ist >> phas[i];
        istringstream ist2(zwei);
        ist2 >> ratio1[i];
        istringstream ist3(drei);
        ist3 >> ratio2[2];
        }
    sRatio.close();

    V1.resize(number);
    V2.resize(number);
    t.resize(number);

    for(int m=0; m<number; m++){

        if(ui->checkBox_13->isChecked()){
            t[m]=BTT0+phas[m]*BTP;
        }
        else{
            t[m]=phas[m];
        }

        if(BTe!=0){
            BTt=t[m];
            BinaryTool::BTfindroot();
            E=BTE;

        theta=2*(atan(tan(E/2)*sqrt((1+BTe)/(1-BTe))));
        }
        else{
            E = M_PI*(t[m]-BTT0)/BTP;
            theta=2*(atan(tan(E/2)));
        }

        V1[m] = V + K1*(cos(theta+w1)+BTe*cos(w1));
        V2[m] = V + K2*(cos(theta+w2)+BTe*cos(w2));
        cout<<t[m]<<"\t"<<phas[m]<<"\t"<<V1[m]<<"\t"<<V2[m]<<endl;
    }
}

//*************************************************
// calculate RVs for plotting curve
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

    t[m]=BTT0+(m+1)*dphi*BTP;

    if(BTe!=0){
        BTt=t[m];
        BinaryTool::BTfindroot();
        E=BTE;

    theta=2*(atan(tan(E/2)*sqrt((1+BTe)/(1-BTe))));
    }
    else{
        E = M_PI*(t[m]-BTT0)/BTP;
        theta=2*(atan(tan(E/2)));
    }


    V1[m] = V + K1*(cos(theta+w1)+BTe*cos(w1));
    V2[m] = V + K2*(cos(theta+w2)+BTe*cos(w2));

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

        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QString fError= QString::number(u);
            QMessageBox::information(this, "Error", "File "+qBPath+"/"+input+fError+".txt does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }
        ifstream dat(datName.c_str());

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
        this->setCursor(QCursor(Qt::ArrowCursor));
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
     ui->customPlot->graph(0)->rescaleAxes();
     ui->customPlot->graph(1)->setData(t, V2);
     ui->customPlot->graph(1)->rescaleAxes(true);
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
    double lw, uw, dw, w, vsi1, vsi2, spotA, spotP, spotF, Intensi=0, tempi1=0, tempi2=0, SNR, c=299792.458, pulA, pulP, vsi11, pulP2, pulA2, vsi12;

    lw=ui->doubleSpinBox_11->value();
    uw=ui->doubleSpinBox_12->value();
    dw=ui->doubleSpinBox_13->value();
    vsi1=ui->doubleSpinBox_14->value();
    vsi2=ui->doubleSpinBox_15->value();
    SNR=ui->spinBox->value();
    pulP=ui->doubleSpinBox_16->value();
    pulA=ui->doubleSpinBox_9->value();
    pulA2 = ui->doubleSpinBox->value();
    pulP2 = ui->doubleSpinBox_18->value();
    spotA = ui->doubleSpinBox_19->value();
    spotP = ui->doubleSpinBox_20->value();
    spotF = ui->doubleSpinBox_21->value();
    int phisteps=1/dphi;
    cout<<phisteps<<endl;

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

    QFile checkfile2(input2Name.c_str());

            if(!checkfile2.exists()){
                qDebug()<<"Error 2: The file "<<checkfile2.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error", "Error 2: Line list "+qBPath+"/"+list2 +" for secondary does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }
            ifstream input2(input2Name.c_str());

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

                    QFile checkfile3(input3Name.c_str());

                          if(!checkfile3.exists()){
                            qDebug()<<"Error: The file "<<checkfile3.fileName()<<" does not exist.";
                            QMessageBox::information(this, "Error", "Error: Line list "+checkfile3.fileName()+" for static features does not exist!");
                            this->setCursor(QCursor(Qt::ArrowCursor));
                            return;
                          }
                          ifstream input3(input3Name.c_str());

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

                    QVector<double> spotw(num_lines1), spoti(num_lines1);

                    std::ostringstream rvNameStream("velocities.txt");
                    rvNameStream<<BPath<<"/"<<"velocities.txt";
                    std::string rvName = rvNameStream.str();
                    ofstream rv(rvName.c_str());

                    double spotd=0;

    for(int m=0; m<phisteps; m++){
    t[m]=BTT0+m*dphi*BTP;

    file4<<setprecision(14)<<t[m]<<endl;

    if(BTe!=0){
        BTt=t[m];
        BinaryTool::BTfindroot();
        E=BTE;

    }

    else{
        E = M_PI*(t[m]-BTT0)/BTP;
    }

    theta=2*(atan(tan(E/2)*sqrt((1+BTe)/(1-BTe))));

    V1[m] = V + K1*(cos(theta+w1)+BTe*cos(w1));
    V2[m] = V + K2*(cos(theta+w2)+BTe*cos(w2));

    rv<<V1[m]<<"\t"<<V2[m]<<endl;

    // Pulsation primary
    if(ui->checkBox_3->isChecked()){
      vsi11=vsi1+pulA*sin(2*M_PI/pulP*(t[m]-BTT0));
    }
    else vsi11=vsi1;

    // Pulsation secondary
    if(ui->checkBox_8->isChecked()){
        vsi12=vsi2+pulA2*sin(2*M_PI/pulP2*(t[m]-BTT0));
    }
    else vsi12 = vsi2;

    for(int n=0; n < num_lines1; n++){
        linesw1[n]=(V1[m]/c+1)*linesw01[n];
            if(ui->checkBox_9->isChecked()){    // spot wavelength position
                spotw[n]=((V1[m]-1.4*vsi11*cos(2*M_PI/spotP*(t[m]-BTT0-spotd)))/c+1)*linesw01[n];
                cout<<spotw[n]<<"\t"<<((V1[m]-vsi11*cos(2*M_PI/spotP*(t[m]-BTT0-spotd)))/c+1)<<endl;
                if((t[m]-BTT0-spotd)>=spotP/2){
                    spotd += spotP/2;
                }
            }
        }
    for(int n=0; n < num_lines2; n++){
        linesw2[n]=(V2[m]/c+1)*linesw02[n];
        }

    if(m==ui->spinBox_5->value()){
        if(ui->checkBox_10->isChecked()){ // damp line intensities
            for(int e=0; e<num_lines1; e++){
                linesi1[e]=linesi1[e]*ui->doubleSpinBox_22->value();
            }
        }
        else{
            if(ui->checkBox_11->isChecked()){ // broaden line
                vsi11 = vsi11 * ui->doubleSpinBox_22->value();
            }
            else{

            }
        }
    }
    else{

    }
    if(m==ui->spinBox_5->value()+1){
        if(ui->checkBox_10->isChecked()){ // damp line intensities
            for(int e=0; e<num_lines1; e++){
                linesi1[e]=linesi1[e]/ui->doubleSpinBox_22->value();
            }
        }
        else{
            if(ui->checkBox_11->isChecked()){ // broaden line
                vsi11 = vsi11 / ui->doubleSpinBox_22->value();
            }
            else{

            }
        }
    }
    else{

    }

    std::ostringstream file1NameStream("spectra_");
    file1NameStream<<BPath<<"/"<<"spectra_"<<m<<".txt";
    std::string file1Name = file1NameStream.str();
    ofstream file1(file1Name.c_str());

    std::ostringstream file4NameStream("componentA_");
    file4NameStream<<BPath<<"/"<<"componentA_"<<m<<".txt";
    std::string file4Name = file4NameStream.str();
    ofstream file4(file4Name.c_str());

    std::ostringstream file5NameStream("componentB_");
    file5NameStream<<BPath<<"/"<<"componentB_"<<m<<".txt";
    std::string file5Name = file5NameStream.str();
    ofstream file5(file5Name.c_str());

    for(int e=0; e<wsteps; e++){
        w=dw*e+lw;

        file1 <<w<< "\t";
        double Int1=0.0;
        double Int2=0.0;

        for(int n=0; n < num_lines1; n++){
        intens1[n]=linesi1[n]*exp(-0.25/(pow((vsi11/c*linesw1[n]),2))*pow((linesw1[n]-w),2));
        Intensi+=intens1[n];
        Int1+=intens1[n];
        }
        if(ui->checkBox_9->isChecked()){    // add spot signal
            for(int n = 0; n< num_lines1; n++){
                spoti[n] = spotA*exp(-0.25/(pow((spotF/c*spotw[n]),2))*pow((spotw[n]-w),2));
                Intensi -= spoti[n];
                Int1-=spoti[n];
            }
        }
        file4<<w*(1-V1[m]/c)<<"\t"<<1-Int1+gauss()/SNR+1/SNR<<endl;

        for(int n=0; n < num_lines2; n++){
        intens2[n]=linesi2[n]*exp(-0.25/(pow((vsi12/c*linesw2[n]),2))*pow((linesw2[n]-w),2));
        Intensi+=intens2[n];
        Int2+=intens2[n];
        }
        file5<<w<<"\t"<<1-Int2+gauss()/SNR+1/SNR<<endl;

        if(m==1){ // generate template
            for(int n=0; n < num_lines1; n++){
                    temi1[n]=(1-linesi1[n]*num_lines1*exp(-0.25/(pow((vsi11/c*linesw01[n]),2))*pow((linesw01[n]-w),2)))/num_lines1;
                    tempi1+=temi1[n];
                }
                for(int n=0; n < num_lines2; n++){
                    temi2[n]=(1-linesi2[n]*num_lines2*exp(-0.25/(pow((vsi12/c*linesw02[n]),2))*pow((linesw02[n]-w),2)))/num_lines2;
                    tempi2+=temi2[n];
                }

                if(ui->checkBox_14->isChecked()){
                    file2<<w<< "\t"<<tempi1+gauss()/SNR+1/SNR<<"\n";
                    file3<<w<< "\t"<<tempi2+gauss()/SNR+1/SNR<<"\n";
                }
                else{
                    file2<<w<< "\t"<<tempi1/2<<"\n";
                    file3<<w<< "\t"<<tempi2/2<<"\n";
                }
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
    this->setCursor(QCursor(Qt::WaitCursor));

    BinaryTool::CalcRVs();

    string line, eins, zwei, drei;
    const double c=299792.458;
    int number=0;

    QString qratio = ui->lineEdit_10->text();
    string sratio = qratio.toUtf8().constData();
    ostringstream sratioNameStream(sratio);
    sratioNameStream<<BPath<<"/"<<sratio;
    string sratioName = sratioNameStream.str();

    QFile checkfile(sratioName.c_str());

    if(!checkfile.exists()){
       qDebug()<<"Error 3: The file "<<checkfile.fileName()<<" does not exist.";
       QMessageBox::information(this, "Error", "Error 3: Spectrum "+checkfile.fileName()+ " of primary does not exist!");
       this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    ifstream sRatio(sratioName.c_str());

    number=0;

    while(std::getline(sRatio, line))
          ++ number;

    sRatio.clear();
    sRatio.seekg(0, ios::beg);

    QVector<double> phas(number), ratio1(number), ratio2(number);

    for (int i =0; i < number; i++){
        sRatio >> eins >> zwei >> drei;
        istringstream ist(eins);
        ist >> phas[i];
        istringstream ist2(zwei);
        ist2 >> ratio1[i];
        istringstream ist3(drei);
        ist3 >> ratio2[i];
        cout<<phas[i]<<"\t"<<ratio1[i]<<"\t"<<ratio2[i]<<endl;
    }
    sRatio.close();

    QString comp2 = ui->lineEdit_5->text();
    string input22 = comp2.toUtf8().constData();
    ostringstream input2NameStream(input22);
    input2NameStream<<BPath<<"/"<<input22;
    string input2Name = input2NameStream.str();

    QFile checkfile2(input2Name.c_str());

    if(!checkfile2.exists()){
       qDebug()<<"Error 4: The file "<<checkfile2.fileName()<<" does not exist.";
       QMessageBox::information(this, "Error", "Error 4: Spectrum "+qBPath+"/" +comp2+" of secondary does not exist!");
       this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    ifstream input2(input2Name.c_str());

    int number2 =0;

    while(std::getline(input2, line))
         ++ number2;

    input2.clear();
    input2.seekg(0, ios::beg);

    /*
    if(number!=number2){
       qDebug()<<"Warning: Different data size";
       QMessageBox::information(this, "Warning", "Warning: Different size of data");
       this->setCursor(QCursor(Qt::ArrowCursor));
       //return;
    }*/

    QVector<double> WC2(number2), IC2(number2);

    for (int i =0; i < number2; i++){
        input2 >> eins >> zwei;
        istringstream istr5(eins);
        istr5 >> WC2[i];
        istringstream istr6(zwei);
        istr6 >> IC2[i];
    }

    input2.close();

    //combine template B with sequence
    if(ui->checkBox_12->isChecked()){
       int nmin = ui->spinBox_6->value();
       int nmax = ui->spinBox_7->value();

       QString qexts = ui->lineEdit_11->text();
       string exts = qexts.toUtf8().constData();

       if((nmax-nmin+1)!=t.size()){
           qDebug()<<"Error 5: Number of spectra does not match number of phases.";
           QMessageBox::information(this, "Error", " Error 5: Number of spectra does not match the number of phases spedified in "+checkfile.fileName()+".");
           return;
       }

       for(int i =0; i<(nmax-nmin+1); i++){

           QString comp1 = ui->lineEdit_4->text();
           string input11 = comp1.toUtf8().constData();
           ostringstream input1NameStream(input11);
           input1NameStream<<BPath<<"/"<<input11<<nmin+i<<exts;
           string input1Name = input1NameStream.str();

           QFile checkfile1(input1Name.c_str());

           if(!checkfile1.exists()){
              qDebug()<<"Error 3: The file "<<checkfile1.fileName()<<" does not exist.";
              QMessageBox::information(this, "Error", "Error 3: Spectrum "+checkfile1.fileName()+" of primary does not exist!");
              this->setCursor(QCursor(Qt::ArrowCursor));
              return;
           }
           ifstream input1(input1Name.c_str());
           number=0;

           while(std::getline(input1, line))
                ++ number;

           input1.clear();
           input1.seekg(0, ios::beg);

           QVector<double> WC1(number), IC1(number);

           for (int i =0; i < number; i++){
               input1 >> eins >> zwei;
               istringstream istr3(eins);
               istr3 >> WC1[i];
               istringstream istr4(zwei);
               istr4 >> IC1[i];
            }

           std::ostringstream timeNameStream("time.txt");
           timeNameStream<<BPath<<"/"<<"time.txt";
           std::string timeName = timeNameStream.str();
           ofstream tim(timeName.c_str());

           int aa=0;

           QVector<double> WCs1(number), WCs2(number2), CI(number), ICs1(number), ICs2(number);

           tim<<setprecision(14)<<t[i]<<endl;

           QString binar = ui->lineEdit_7->text();
           string bina = binar.toUtf8().constData();
           ostringstream out2NameStream(bina);
           out2NameStream<<BPath<<"/"<<bina<<i<<".txt";
           string out2Name = out2NameStream.str();
           ofstream file1(out2Name.c_str());

           for(int n = 0; n<WC1.size(); n++){
               WCs1[n]=WC1[n]*(1+V1[i]/c);
               ICs1[n]=IC1[n]*ratio1[i];
           }

           for(int n = 0; n<WC2.size(); n++){
               WCs2[n]=WC2[n]*(1+V2[i]/c);
               ICs2[n]=IC2[n]*ratio2[i];
           }

           aa = 0;

           for(int e=0; e<number; e++){
               for(int u=aa; (u<aa+150) & (u<number); u++){

                    if((WCs1[u]==WC1[e])){
                        CI[e]=ICs1[u];
                        aa=u;
                    }
                    if((WCs1[u]<WC1[e]) & (WCs1[u+1]>WC1[e])){
                        CI[e]=(ICs1[u]+(WC1[e]-WCs1[u])/(WCs1[u+1]-WCs1[u])*(ICs1[u+1]-ICs1[u]));
                        aa=u;
                    }
                }
           }


           aa=0;

           for(int e=0; e<number; e++){
               for(int u=aa; (u<aa+150) & (u<number); u++){

                    if((WCs2[u]==WC1[e])){
                        CI[e]+=ICs2[u];
                        aa=u;
                    }
                    if((WCs2[u]<WC1[e]) & (WCs2[u+1]>WC1[e])){
                        CI[e]+=(ICs2[u]+(WC1[e]-WCs2[u])/(WCs2[u+1]-WCs2[u])*(ICs2[u+1]-ICs2[u]));
                        aa=u;
                    }
                }
           }

            for(int e=0; e<number; e++){
                file1<<WC1[e]<<" "<<CI[e]<<endl;
            }

       }
    }

    // combine template A and B
    else{

        QString comp1 = ui->lineEdit_4->text();
        string input11 = comp1.toUtf8().constData();
        ostringstream input1NameStream(input11);
        input1NameStream<<BPath<<"/"<<input11;
        string input1Name = input1NameStream.str();

        QFile checkfile1(input1Name.c_str());

        if(!checkfile1.exists()){
           qDebug()<<"Error 3: The file "<<checkfile1.fileName()<<" does not exist.";
           QMessageBox::information(this, "Error", "Error 3: Spectrum "+qBPath+"/" +comp1+" of primary does not exist!");
           this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }
        ifstream input1(input1Name.c_str());
        number=0;

        while(std::getline(input1, line))
             ++ number;

        input1.clear();
        input1.seekg(0, ios::beg);

        QVector<double> WC1(number), IC1(number);

        for (int i =0; i < number; i++){
            input1 >> eins >> zwei;
            istringstream istr3(eins);
            istr3 >> WC1[i];
            istringstream istr4(zwei);
            istr4 >> IC1[i];
         }

         input1.close();

         if((WC1[1]-WC1[0])!=(WC2[1]-WC2[0])){
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

           int aa=0;
           //double diff=WC1[1]-WC1[0];
           QVector<double> WCs1(number), WCs2(number2), CI(number), ICs1(number), ICs2(number);

           for(int i=0; i<phas.size(); i++){

               tim<<setprecision(14)<<t[i]<<endl;

               QString binar = ui->lineEdit_7->text();
               string bina = binar.toUtf8().constData();
               ostringstream out2NameStream(bina);
               out2NameStream<<BPath<<"/"<<bina<<i<<".txt";
               string out2Name = out2NameStream.str();
               ofstream file1(out2Name.c_str());

               for(int n = 0; n<WC1.size(); n++){
                   WCs1[n]=WC1[n]*(1+V1[i]/c);
                   ICs1[n]=IC1[n]*ratio1[i];
               }

               for(int n = 0; n<WC2.size(); n++){
                   WCs2[n]=WC2[n]*(1+V2[i]/c);
                   ICs2[n]=IC2[n]*ratio2[i];
               }

               aa = 0;

               for(int e=0; e<number; e++){
                   for(int u=0; u<WC1.size(); u++){

                    if((WCs1[u]==WC1[e])){
                        CI[e]=ICs1[u];
                        u=WC1.size();
                        //aa=u;
                    }
                    else{
                        if((WCs1[u]<=WC1[e]) & (WCs1[u+1]>WC1[e])){
                            CI[e]=(ICs1[u]+(WC1[e]-WCs1[u])/(WCs1[u+1]-WCs1[u])*(ICs1[u+1]-ICs1[u]));
                            u=WC1.size();
                            //aa=u;
                        }
                        else{
                            CI[e]=0;
                        }
                    }
                  }
               }


               aa=0;

               for(int e=0; e<number; e++){
                   for(int u=0; u<WC1.size(); u++){

                    if((WCs2[u]==WC1[e])){
                        CI[e]+=ICs2[u];
                        u=WC1.size();
                        //aa=u;
                    }
                    else{
                        if((WCs2[u]<=WC1[e]) & (WCs2[u+1]>WC1[e])){
                            CI[e]+=(ICs2[u]+(WC1[e]-WCs2[u])/(WCs2[u+1]-WCs2[u])*(ICs2[u+1]-ICs2[u]));
                            u=WC1.size();
                            //aa=u;
                        }
                        else{
                            CI[e]+=0;
                        }
                    }
                  }
               }

                for(int e=0; e<number; e++){
                    file1<<WC1[e]<<" "<<CI[e]<<endl;
                }

           }

           tim.close();
                    }

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
    cout<<"test"<<endl;

    QFile checkfile1(input1Name.c_str());

            if(!checkfile1.exists()){
                qDebug()<<"Error 1: The file "<<checkfile1.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error", "Error 1: Line list "+checkfile1.fileName()+" for primary does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }

            ifstream input1(input1Name.c_str());

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
                         istringstream istr(eins);
                         istr >> linesw01[i];
                         istringstream istr2(zwei);
                         istr2 >> linesi1[i];
                         istringstream istr3(drei);
                         istr3 >> spoti1[i];;
                    }
                    cout<<"test"<<endl;


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
                    cout<<"test"<<endl;


                    QFile checkfile3(input3Name.c_str());

                          if(!checkfile3.exists()){
                            qDebug()<<"Error: The file "<<checkfile3.fileName()<<" does not exist.";
                            QMessageBox::information(this, "Error", "Error: Line list "+checkfile3.fileName()+" features does not exist!");
                            this->setCursor(QCursor(Qt::ArrowCursor));
                            return;
                                   }

                          ifstream input3(input3Name.c_str());

                          while(std::getline(input3, line))
                               ++ num_lines3;

                               input3.clear();
                               input3.seekg(0, ios::beg);

                          lineswt.resize(num_lines3);
                          linesit.resize(num_lines3);
                          intenst.resize(num_lines3);
                          FWHMt.resize(num_lines3);
                          FWHMn.resize(num_lines3);
                          cout<<"test"<<endl;


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
                    cout<<"test"<<endl;

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

                  t[m]=BTT0+(m+1)*dphi*BTP;

                  if(BTe!=0){

                      BTt=t[m];
                      BinaryTool::BTfindroot();
                      E=BTE;

                  }
                  else{
                      E=M_PI*(t[m]-BTT0)/BTP;
                  }

                  theta=2*(atan(tan(E/2)*sqrt((1+BTe)/(1-BTe))));

                  V1[m] = V + K1*(cos(theta+w1)+BTe*cos(w1));

                  rv<<V1[m]<<endl;

                  if(ui->checkBox_3->isChecked()){
                    vsi11=vsi1+pulA*sin(2*M_PI/pulP*(t[m]-BTT0));
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
    BTP = ui->doubleSpinBox_17->value();
}

//**************************************
// root finding
//**************************************
void BinaryTool::BTfindroot(){

    int n=1, Ph, Pl, Psh, zaehler=40, eval=0;
    double yh, ysh, yl, ym, yi, ys, yt;
    double sigma = 1e-5;
    double step=0.1;
    double gamma=2.0;	//expansion coeff.
    double alpha =1.0;	//reflection coeff.
    double beta=0.5;	//contraction coeff.
    double btot=0.5;	//total contraction coeff.
    double y[n+1], Pm[n+1][n], Z[n], C[n], S[n], Em[n], X[n], e[n][n];

        //initial points
        Pm[0][0]=2*M_PI*(BTt-BTT0)/BTP-2*BTe;
        for (int i=0; i<n+1; i++){
            for (int j=0; j<n; j++){
                if(i>0 & i==j+1){
                    e[i][j]=1;
                }
                else{
                    e[i][j]=0;
                }
                if(i==0){
                    X[j]=Pm[i][j];
                    //cout <<X[j]<<"\t";
                }
                if(i!=0){
                    Pm[i][j]=Pm[0][j]+step*e[i][j];
                    X[j]=Pm[i][j];
                    //cout <<X[j]<<"\t";
                }
            }
            y[i]=BTfunction(X, BTt, BTT0, BTP, BTe);
            eval++;
            //cout <<y[i]<<endl;
        }

        //start main loop
        for (int tc=0; tc<zaehler; tc++){

            //initialize next step
            ym=0;
            ys=0;
            for (int i=0; i<n; i++){
                Z[i]=0;
            }

            //looking for highest value
            yh=y[0];
            for (int j=0; j<n+1; j++){
                if(y[j]>=yh){
                    yh = y[j];
                    Ph = j;
                }
            }

            //looking for smallest value
            yl=yh;
            for (int j=0; j<n+1; j++){
                if(y[j]<yl){
                    yl=y[j];
                    Pl = j;
                }
            }

            // second highest value
            ysh=yl;
            yh=y[Ph];
            yl=y[Pl];
            ysh=y[Psh];

            //computing mean and sigma
            for (int i=0; i<n+1; i++){
                ym+=y[i]/(n+1);
            }
            for (int i=0; i<n+1; i++){
                ys+=sqrt(pow((y[i]-ym),2));
            }
            ys=ys/(n);

            //compute centroid
            for (int j=0; j<n; j++){
                for (int i=0; i<n+1; i++){
                    if (i!=Ph){
                        Z[j]+=Pm[i][j]/n;
                    }
                }
            }

            //reflect highest value at centroid
            for (int i=0; i<n; i++){
                C[i]=Z[i]+alpha*(Z[i]-Pm[Ph][i]);
            }
            yi=BTfunction(C, BTt, BTT0, BTP, BTe);
            eval++;

            if(yi<yl){
                for (int i=0; i<n; i++){
                    Em[i]=Z[i]+gamma*(C[i]-Z[i]);
                }
                yt=BTfunction(Em, BTt, BTT0, BTP, BTe);
                eval++;
                if(yt<yl){
                    for (int i=0; i<n; i++){
                        Pm[Ph][i]=Em[i];
                    }
                    y[Ph]=yt;//BTfunction(E);
                    //eval++;
                }
                if (yt>=yl){
                    for (int i=0; i<n; i++){
                        Pm[Ph][i]=C[i];
                    }
                    eval++;
                    y[Ph]=BTfunction(C, BTt, BTT0, BTP, BTe);
                }
            }

            if(yi>=yl){
                if(yi<=ysh){
                    for(int i=0; i<n; i++){
                        Pm[Ph][i]=C[i];
                    }
                    eval++;
                    y[Ph]=BTfunction(C, BTt, BTT0, BTP, BTe);
                }
                if(yi>ysh){
                    if(yi<=yh){
                        for(int i=0; i<n; i++){
                            Pm[Ph][i]=C[i];
                        }
                        eval++;
                        y[Ph]=BTfunction(C, BTt, BTT0, BTP, BTe);
                        yh=y[Ph];
                    }
                    for(int i=0; i<n; i++){
                        S[i]=Z[i]+beta*(Pm[Ph][i]-Z[i]);
                    }
                    yt=BTfunction(S, BTt, BTT0, BTP, BTe);
                    eval++;
                    if(yt>yh){
                        for (int j=0; j<n+1; j++){
                            for (int i=0; i<n; i++){
                                Pm[j][i]=Pm[Pl][i]+btot*(Pm[j][i]-Pm[Pl][i]); //total contraction
                                X[i]=Pm[j][i];
                            }
                            y[j]=BTfunction(X, BTt, BTT0, BTP, BTe);
                            eval++;
                        }
                    }

                    if(yt<=yh){
                        for(int i=0; i<n; i++){
                            Pm[Ph][i]=S[i];
                        }
                        eval++;
                        y[Ph]=BTfunction(S, BTt, BTT0, BTP, BTe);
                    }
                }
            }

        }//end main loop

        //looking for highest value
        yh=y[0];
        for (int j=0; j<n+1; j++){
            if(y[j]>=yh){
                yh = y[j];
                Ph = j;
            }
        }

        //looking for smallest value
        yl=yh;
        for (int j=0; j<n+1; j++){
            if(y[j]<yl){
                yl=y[j];
                Pl = j;
            }
        }

        //looking for second highest value
        ysh=yl;
        for (int j=0; j<n+1; j++){
            if(y[j]>ysh & (y[j]<yh)){
                ysh=y[j];
                Psh=j;
            }
        }

        BTE=Pm[Pl][0];

}

// load orbital parameters
void BinaryTool::on_pushButton_7_clicked()
{
    int dey=ui->comboBox_2->currentIndex();
    ui->doubleSpinBox_17->setValue(PERa[dey]);
    ui->doubleSpinBox_3->setValue(ECCa[dey]);
    ui->doubleSpinBox_6->setValue(AMPAa[dey]);
    ui->doubleSpinBox_7->setValue(AMPBa[dey]);
    ui->doubleSpinBox_8->setValue(GAMa[dey]);
    ui->doubleSpinBox_5->setValue(PERIa[dey]);
    ui->doubleSpinBox_4->setValue(LPERIa[dey]);
}


void BinaryTool::on_checkBox_12_clicked()
{
    if(ui->checkBox_12->isChecked()){
        ui->spinBox_6->setEnabled(true);
        ui->spinBox_7->setEnabled(true);
        ui->lineEdit_11->setEnabled(true);
    }
    else{
        ui->spinBox_6->setEnabled(false);
        ui->spinBox_7->setEnabled(false);
        ui->lineEdit_11->setEnabled(false);
    }
}
