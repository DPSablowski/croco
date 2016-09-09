#include "rvcalc.h"
#include "ui_rvcalc.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

QString qRvPath;
string rvPath;

RVCalc::RVCalc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RVCalc)
{
    ui->setupUi(this);
    this->setWindowTitle("RV Calculator");

    ui->doubleSpinBox->setValue(159.0886);
    ui->doubleSpinBox_2->setValue(56582.3536);
    ui->doubleSpinBox_3->setValue(277);
    ui->doubleSpinBox_4->setValue(101);
    ui->doubleSpinBox_5->setValue(100);
    ui->doubleSpinBox_6->setValue(1.4835);
    ui->doubleSpinBox_8->setValue(0.82);
    ui->doubleSpinBox_12->setValue(36997.00);
    ui->doubleSpinBox_13->setValue(37018.00);
    ui->doubleSpinBox_14->setValue(0.00);

    ui->lineEdit_2->setText("/home/daniels/Disentangling/Artificial/ErrorTest/RVs_opt");
    qRvPath=ui->lineEdit_2->text();
    rvPath = qRvPath.toUtf8().constData();
    ui->lineEdit->setText("sn100_opt.dat");

    QFont legendFont = font();
    legendFont.setPointSize(16);
    ui->customPlot->axisRect()->setupFullAxesBox(true);
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setLabel("Velocity [km/s]");
    ui->customPlot->xAxis->setLabel("HJD");

    ui->comboBox->addItem("Capella");
    ui->comboBox->addItem("Mizar");
    ui->comboBox->addItem("BAT99_12");
    ui->comboBox->addItem("BAT99_32");
    ui->comboBox->addItem("BAT99_77");
    ui->comboBox->addItem("BAT99_92");
    ui->comboBox->addItem("BAT99_95");
    ui->comboBox->addItem("BAT99_99");
    ui->comboBox->addItem("BAT99_103");
    ui->comboBox->addItem("BAT99_113");
    ui->comboBox->addItem("BAT99_119");
    ui->comboBox->addItem("NGC 3603-A1");
    ui->comboBox->addItem("NN Del");
    ui->comboBox->addItem("PX Hya");
}

RVCalc::~RVCalc()
{
    delete ui;
}



//calculate RVs
void RVCalc::on_doubleSpinBox_9_valueChanged()
{
    double P=ui->doubleSpinBox->value();
    double T0=ui->doubleSpinBox_2->value();
    double gamma=ui->doubleSpinBox_3->value();
    double KA=ui->doubleSpinBox_4->value();
    double KB=ui->doubleSpinBox_5->value();
    double WA=ui->doubleSpinBox_6->value()/180*M_PI;
    double WB=WA+M_PI;
    double e=ui->doubleSpinBox_8->value();
    double t=ui->doubleSpinBox_9->value();
    double dE2, a1, a2, dE1, RVA, RVB, theta, xx, E1, E2, E;
    double dx=0.00001;

    if(e!=0){
    a1=2*M_PI*(t-T0)/P-2*e;
    a2=2*M_PI*(t-T0)/P+2*e;

    dE2=0;
    for(int i=0; i<(a2-a1)/dx; i++){
    xx=a1+i*dx;
    E1=xx;
    E2=e*sin(xx)+2*M_PI*(t-T0)/P;
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
    }
    theta=2*(atan(tan(E/2)*sqrt((1+e)/(1-e))));
    }
    else{
        E = M_PI*(t-T0)/P;
        theta=2*(atan(tan(E/2)));
    }


    RVA = gamma + KA*(cos(theta+WA)+e*cos(WA));
    RVB = gamma + KB*(cos(theta+WB)+e*cos(WB));

    ui->doubleSpinBox_10->setValue(RVA);
    ui->doubleSpinBox_11->setValue(RVB);

}


//
void RVCalc::on_pushButton_2_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));

    ui->customPlot->clearGraphs();

    double P=ui->doubleSpinBox->value();
    double T0=ui->doubleSpinBox_2->value();
    double gamma=ui->doubleSpinBox_3->value();
    double KA=ui->doubleSpinBox_4->value();
    double KB=ui->doubleSpinBox_5->value();
    double WA=ui->doubleSpinBox_6->value()/180*M_PI;
    double WB=WA-M_PI;
    double e=ui->doubleSpinBox_8->value();
    double t1=ui->doubleSpinBox_12->value();
    double t2=ui->doubleSpinBox_13->value();
    double dt = P/100;
    double dE2, a1, a2, dE1, theta, xx, E1, E2, E;
    double dx=0.00001;
    int steps =(t2-t1)/dt;
    QVector<double> RVA(steps), RVB(steps), t(steps);


    for(int m=0; m<steps; m++){
        t[m]=t1+m*dt;

        if(e!=0){
        a1=2*M_PI*(t[m]-T0)/P-4*e;
        a2=2*M_PI*(t[m]-T0)/P+4*e;
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
    }
        theta=2*(atan(tan(E/2)*sqrt((1+e)/(1-e))));
        }
        else{
            E = M_PI*(t[m]-T0)/P;
            theta=2*(atan(tan(E/2)));
        }

    RVA[m] = gamma + KA*(cos(theta+WA)+e*cos(WA));
    RVB[m] = gamma + KB*(cos(theta+WB)+e*cos(WB));
    t[m]=t[m]-ui->doubleSpinBox_14->value();
    }

    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::red);
    QPen pen4;
    pen4.setWidth(2);
    pen4.setColor(Qt::blue);

    ui->customPlot->addGraph();
    ui->customPlot->graph()->setData(t, RVA);
    ui->customPlot->graph()->setPen(pen4);
    ui->customPlot->graph()->rescaleAxes();
    ui->customPlot->addGraph();
    ui->customPlot->graph(1)->setData(t, RVB);
    ui->customPlot->graph(1)->setPen(pen);
    ui->customPlot->graph(1)->rescaleAxes(true);

    if(ui->checkBox->isChecked()){

        string one, two, three, zeile;

        double rvmin;

        QString plot1=ui->lineEdit->text();
        string plot11 = plot1.toUtf8().constData();
        std::ostringstream datNameStream(plot11);
        datNameStream<<rvPath<<"/"<<plot11;
        std::string datName = datNameStream.str();
        ifstream toplot1(datName.c_str());

        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File "+qRvPath+"/"+plot1+" does not exist!");
           return;
        }

        int lines =0;

        while(std::getline(toplot1, zeile))
           ++ lines;

        toplot1.clear();
        toplot1.seekg(0, ios::beg);

        QVector<double> at(lines), bt(lines), ct(lines);

        double at1;
        int a=(t2-t1)/P;

        for (int i=0; i<lines; i++){
        toplot1 >> one >>two>>three;
        istringstream ist(one);
        ist >> at[i];
        at[i]=at[i]-ui->doubleSpinBox_14->value();
        if(i==0){
            at1=at[0];
        }
        if(ui->checkBox_2->isChecked()){

            if(at[i]-at1>=P){
            for(int e=0; e<a; e++){

                at[i]=at[i]-P;
                if(at[i]<at1){
                    at[i]=at[i]+P;
                    e=a;
                }
            }
            }

        }

        istringstream ist2(two);
        ist2 >> bt[i];
        if(i==0){
            rvmin = bt[0];
        }
        if(bt[i]<rvmin){
            rvmin = bt[i];
        }
        istringstream ist3(three);
        ist3 >> ct[i];
        }
        toplot1.close();

        QPen pen2;
        pen2.setWidth(3);
        pen2.setColor(Qt::green);
        QPen pen3;
        pen3.setWidth(3);
        pen3.setColor(Qt::black);

        ui->customPlot->addGraph();
        ui->customPlot->graph(2)->setData(at, bt);
        ui->customPlot->graph(2)->setPen(pen2);
        ui->customPlot->graph(2)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
        ui->customPlot->graph(2)->rescaleAxes(true);
        ui->customPlot->addGraph();
        ui->customPlot->graph(3)->setData(at, ct);
        ui->customPlot->graph(3)->setPen(pen3);
        ui->customPlot->graph(3)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(3)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
        ui->customPlot->graph(3)->rescaleAxes(true);
        if(ui->checkBox_2->isChecked()){
            ui->customPlot->xAxis->setRange(at1-5, at1+P);
        }

        // looking for independent spectra
        if(rvmin<0){
        for(int i=0; i<lines; i++){
            bt[i]=bt[i]+abs(rvmin);
        }
        }
        double resolution = ui->doubleSpinBox_15->value();
        int testc=0;
        int NIS=0;
        /*
        for(int i =0; i<lines; i++){
            for(int m=0; m<lines; m++){
                if(abs(bt[i]-bt[m])>resolution){
                ++testc;
                }
            }
            if(testc==lines-1){
                ++NIS;
            }
            testc=0;
        }*/

        for(int e =0; e<lines; e++){
        for(int i = 1; i<lines; i++){
            if(abs(bt[i]-bt[0])>resolution){
                ++testc;
            }
        }
        QVector<double> ind1(testc+1);
        ind1[0]=bt[0];
        NIS = testc+1;
        testc=0;

        for(int i = 1; i<lines; i++){
            if(abs(bt[i]-bt[0])>resolution){
                ind1[testc]=bt[i];
                //cout<<ind1[testc+1]<<endl;
                ++testc;
            }
        }
        testc=0;
        }

        ui->spinBox_2->setValue(NIS);

    }
    ui->customPlot->replot();


    this->setCursor(QCursor(Qt::ArrowCursor));

}


void RVCalc::on_lineEdit_2_textChanged()
{
    qRvPath=ui->lineEdit_2->text();
    rvPath = qRvPath.toUtf8().constData();
}

void RVCalc::on_spinBox_valueChanged()
{
    QFont legendFont = font();
    legendFont.setPointSize(ui->spinBox->value());
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);
}

void RVCalc::on_checkBox_3_clicked()
{
    ui->checkBox_4->setChecked(false);
}

void RVCalc::on_checkBox_4_clicked()
{
    ui->checkBox_3->setChecked(false);
}

void RVCalc::on_pushButton_3_clicked()
{
    if(ui->checkBox_3->isChecked()){
        QString sav=ui->lineEdit_3->text();
        QString save=qRvPath+"/"+sav +".pdf";
        ui->customPlot->savePdf(save);
    }
    if(ui->checkBox_4->isChecked()){
        QString sav=ui->lineEdit_3->text();
        QString save=qRvPath+"/"+sav+".png";
        ui->customPlot->savePng(save);
    }
}

void RVCalc::on_lineEdit_4_textEdited()
{
    ui->customPlot->xAxis->setLabel(ui->lineEdit_4->text());
}

void RVCalc::on_lineEdit_5_textEdited()
{
    ui->customPlot->yAxis->setLabel(ui->lineEdit_5->text());
}

void RVCalc::on_pushButton_4_clicked()
{
    string zeile, one;

    QString qtimes=ui->lineEdit_6->text();
    string times = qtimes.toUtf8().constData();
    std::ostringstream datNameStream(times);
    datNameStream<<rvPath<<"/"<<times;
    std::string datName = datNameStream.str();
    ifstream otimes(datName.c_str());

    QFile checkfile(datName.c_str());

    if(!checkfile.exists()){
        qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+qRvPath+"/"+qtimes+" does not exist!");
       return;
    }

    int lines =0;

    while(std::getline(otimes, zeile))
       ++ lines;

    otimes.clear();
    otimes.seekg(0, ios::beg);

    QVector<double> tim(lines);

    for(int i=0; i<lines; i++){
        otimes >> one;
        istringstream ist(one);
        ist >> tim[i];
    }

    double P=ui->doubleSpinBox->value();
    double T0=ui->doubleSpinBox_2->value();
    double gamma=ui->doubleSpinBox_3->value();
    double KA=ui->doubleSpinBox_4->value();
    double KB=ui->doubleSpinBox_5->value();
    double WA=ui->doubleSpinBox_6->value()/180*M_PI;
    double WB=WA-M_PI;
    double e=ui->doubleSpinBox_8->value();
    double dE2, a1, a2, dE1, theta, xx, E1, E2, E;
    double dx=0.00001;

    QString qout=ui->lineEdit_7->text();
    string out = qout.toUtf8().constData();
    std::ostringstream outNameStream(out);
    outNameStream<<rvPath<<"/"<<out;
    std::string outName = outNameStream.str();
    ofstream oout(outName.c_str());

    for(int m=0; m<lines; m++){

        if(e!=0){
        a1=2*M_PI*(tim[m]-T0)/P-4*e;
        a2=2*M_PI*(tim[m]-T0)/P+4*e;
        dE2=0;

    for(int i=0; i<(a2-a1)/dx; i++){
    xx=a1+i*dx;
    E1=xx;
    E2=e*sin(xx)+2*M_PI*(tim[m]-T0)/P;
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
    }
        theta=2*(atan(tan(E/2)*sqrt((1+e)/(1-e))));
        }
        else{
            E = M_PI*(tim[m]-T0)/P;
            theta=2*(atan(tan(E/2)));
        }

    oout<<setprecision(12)<<tim[m]<<" "<<gamma + KA*(cos(theta+WA)+e*cos(WA))<<" "<<gamma + KB*(cos(theta+WB)+e*cos(WB))<<endl;

    }

}

// load orbit parameter
void RVCalc::on_pushButton_5_clicked()
{
    // Capella
    if(ui->comboBox->currentIndex()==0){
        ui->doubleSpinBox->setValue(104.0217);
        ui->doubleSpinBox_8->setValue(0.00089);
        ui->doubleSpinBox_4->setValue(25.9611);
        ui->doubleSpinBox_5->setValue(26.8400);
        ui->doubleSpinBox_3->setValue(29.9378);
        ui->doubleSpinBox_2->setValue(54389);
        ui->doubleSpinBox_6->setValue(327.40);
    }

    // Mizar
    if(ui->comboBox->currentIndex()==1){
        ui->doubleSpinBox->setValue(20.54);
        ui->doubleSpinBox_8->setValue(0.537);
        ui->doubleSpinBox_4->setValue(68.6);
        ui->doubleSpinBox_5->setValue(67.6);
        ui->doubleSpinBox_3->setValue(-5.6);
        ui->doubleSpinBox_2->setValue(36997);
        ui->doubleSpinBox_6->setValue(106.16);
    }

    // BAT99_12
    if(ui->comboBox->currentIndex()==2){
        ui->doubleSpinBox->setValue(3.2358);
        ui->doubleSpinBox_8->setValue(0.34);
        ui->doubleSpinBox_4->setValue(74);
        ui->doubleSpinBox_5->setValue(68);
        ui->doubleSpinBox_3->setValue(646);
        ui->doubleSpinBox_2->setValue(52269.84);
        ui->doubleSpinBox_6->setValue(-29);
    }

    // BAT99_32
    if(ui->comboBox->currentIndex()==3){
        ui->doubleSpinBox->setValue(1.90756);
        ui->doubleSpinBox_8->setValue(0.06);
        ui->doubleSpinBox_4->setValue(120);
        ui->doubleSpinBox_5->setValue(120);
        ui->doubleSpinBox_3->setValue(288);
        ui->doubleSpinBox_2->setValue(53011.57);
        ui->doubleSpinBox_6->setValue(250);
    }

    // BAT99_77
    if(ui->comboBox->currentIndex()==4){
        ui->doubleSpinBox->setValue(3.00303);
        ui->doubleSpinBox_8->setValue(0.32);
        ui->doubleSpinBox_4->setValue(144);
        ui->doubleSpinBox_5->setValue(144);
        ui->doubleSpinBox_3->setValue(339);
        ui->doubleSpinBox_2->setValue(52631.87);
        ui->doubleSpinBox_6->setValue(7);
    }

    // BAT99_92
    if(ui->comboBox->currentIndex()==5){
        ui->doubleSpinBox->setValue(4.3125);
        ui->doubleSpinBox_8->setValue(0.02);
        ui->doubleSpinBox_4->setValue(204);
        ui->doubleSpinBox_5->setValue(204);
        ui->doubleSpinBox_3->setValue(332);
        ui->doubleSpinBox_2->setValue(52998.03);
        ui->doubleSpinBox_6->setValue(109);
    }

    // BAT99_95
    if(ui->comboBox->currentIndex()==6){
        ui->doubleSpinBox->setValue(2.1110);
        ui->doubleSpinBox_8->setValue(0.07);
        ui->doubleSpinBox_4->setValue(107);
        ui->doubleSpinBox_5->setValue(107);
        ui->doubleSpinBox_3->setValue(274);
        ui->doubleSpinBox_2->setValue(52999.87);
        ui->doubleSpinBox_6->setValue(285);
    }

    // BAT99_99
    if(ui->comboBox->currentIndex()==7){
        ui->doubleSpinBox->setValue(92.60);
        ui->doubleSpinBox_8->setValue(0);
        ui->doubleSpinBox_4->setValue(91);
        ui->doubleSpinBox_5->setValue(0);
        ui->doubleSpinBox_3->setValue(337);
        ui->doubleSpinBox_2->setValue(53007.8);
        ui->doubleSpinBox_6->setValue(0);
    }


    // BAT99_103
    if(ui->comboBox->currentIndex()==8){
        ui->doubleSpinBox->setValue(2.75975);
        ui->doubleSpinBox_8->setValue(0.23);
        ui->doubleSpinBox_4->setValue(158);
        ui->doubleSpinBox_5->setValue(156);
        ui->doubleSpinBox_3->setValue(388);
        ui->doubleSpinBox_2->setValue(53007.8);
        ui->doubleSpinBox_6->setValue(-41);
    }

    // BAT99_113
    if(ui->comboBox->currentIndex()==9){
        ui->doubleSpinBox->setValue(4.699);
        ui->doubleSpinBox_8->setValue(0.20);
        ui->doubleSpinBox_4->setValue(130);
        ui->doubleSpinBox_5->setValue(125);
        ui->doubleSpinBox_3->setValue(390);
        ui->doubleSpinBox_2->setValue(52993.07);
        ui->doubleSpinBox_6->setValue(308);
    }

    // BAT99_119
    if(ui->comboBox->currentIndex()==10){
        ui->doubleSpinBox->setValue(159.0886);
        ui->doubleSpinBox_8->setValue(0.8191);
        ui->doubleSpinBox_4->setValue(101.2374);
        ui->doubleSpinBox_5->setValue(100);
        ui->doubleSpinBox_3->setValue(290);
        ui->doubleSpinBox_2->setValue(56501.2889);
        ui->doubleSpinBox_6->setValue(240.8657);
    }

    // NGC 3603-A1
    if(ui->comboBox->currentIndex()==11){
        ui->doubleSpinBox->setValue(3.77240);
        ui->doubleSpinBox_8->setValue(0.0000);
        ui->doubleSpinBox_4->setValue(330.000);
        ui->doubleSpinBox_5->setValue(433.000);
        ui->doubleSpinBox_3->setValue(153.000);
        ui->doubleSpinBox_2->setValue(3765.25);
        ui->doubleSpinBox_6->setValue(120.00);
    }

    // NN Del
    if(ui->comboBox->currentIndex()==12){
        ui->doubleSpinBox->setValue(99.1648477);
        ui->doubleSpinBox_8->setValue(0.5177);
        ui->doubleSpinBox_4->setValue(36.2432);
        ui->doubleSpinBox_5->setValue(39.4582);
        ui->doubleSpinBox_3->setValue(-9.4046);
        ui->doubleSpinBox_2->setValue(2456787.1095);
        ui->doubleSpinBox_6->setValue(350.5696);
    }

    // PX Hya
    if(ui->comboBox->currentIndex()==13){
        ui->doubleSpinBox->setValue(36.1828518);
        ui->doubleSpinBox_8->setValue(0.5652);
        ui->doubleSpinBox_4->setValue(57.6967);
        ui->doubleSpinBox_5->setValue(56.5568);
        ui->doubleSpinBox_3->setValue(-14.9896);
        ui->doubleSpinBox_2->setValue(2456743.2661);
        ui->doubleSpinBox_6->setValue(325.1146);
    }
}

// Residuum between calculated and data
void RVCalc::on_pushButton_6_clicked()
{
    string one, two, three, zeile;

    double rvmin;

    QString plot1=ui->lineEdit->text();
    string plot11 = plot1.toUtf8().constData();
    std::ostringstream datNameStream(plot11);
    datNameStream<<rvPath<<"/"<<plot11;
    std::string datName = datNameStream.str();
    ifstream toplot1(datName.c_str());

    QFile checkfile(datName.c_str());

    if(!checkfile.exists()){
        qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+qRvPath+"/"+plot1+" does not exist!");
       return;
    }

    int lines =0;

    while(std::getline(toplot1, zeile))
       ++ lines;

    toplot1.clear();
    toplot1.seekg(0, ios::beg);

    QVector<double> at(lines), bt(lines), ct(lines);

    for (int i=0; i<lines; i++){
    toplot1 >> one >>two>>three;
    istringstream ist(one);
    ist >> at[i];

    istringstream ist2(two);
    ist2 >> bt[i];

    istringstream ist3(three);
    ist3 >> ct[i];
    }
    toplot1.close();

    double P=ui->doubleSpinBox->value();
    double T0=ui->doubleSpinBox_2->value();
    double gamma=ui->doubleSpinBox_3->value();
    double KA=ui->doubleSpinBox_4->value();
    double KB=ui->doubleSpinBox_5->value();
    double WA=ui->doubleSpinBox_6->value()/180*M_PI;
    double WB=WA-M_PI;
    double e=ui->doubleSpinBox_8->value();
    double dE2, a1, a2, dE1, theta, xx, E1, E2, E;
    double dx=0.00001;

    double RVA, RVB, residuumA, residuumB;

    for(int m=0; m<lines; m++){

        if(e!=0){
        a1=2*M_PI*(at[m]-T0)/P-4*e;
        a2=2*M_PI*(at[m]-T0)/P+4*e;
        dE2=0;

    for(int i=0; i<(a2-a1)/dx; i++){
    xx=a1+i*dx;
    E1=xx;
    E2=e*sin(xx)+2*M_PI*(at[m]-T0)/P;
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
    }
        theta=2*(atan(tan(E/2)*sqrt((1+e)/(1-e))));
        }
        else{
            E = M_PI*(at[m]-T0)/P;
            theta=2*(atan(tan(E/2)));
        }

    RVA = gamma + KA*(cos(theta+WA)+e*cos(WA));
    RVB = gamma + KB*(cos(theta+WB)+e*cos(WB));

    residuumA += pow((RVA - bt[m]),2);
    residuumB += pow((RVB - ct[m]),2);

    }

    residuumA = sqrt(residuumA/(lines-1));
    residuumB = sqrt(residuumB/(lines-1));

    QString ResA = QString::number(residuumA);
    QString ResB = QString::number(residuumB);

    ui->lineEdit_8->setText(ResA+" / "+ResB);
}
