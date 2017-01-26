#include "rvcalc.h"
#include "ui_rvcalc.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>

using namespace std;

double RVCP, RVCe, RVCt, RVCT0, RVCE;

QString qRvPath;
string rvPath;

RVCalc::RVCalc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RVCalc)
{
    ui->setupUi(this);
    this->setWindowTitle("RV Calculator");

    ui->doubleSpinBox->setValue(104.0217);
    ui->doubleSpinBox_8->setValue(0.00089);
    ui->doubleSpinBox_4->setValue(25.9611);
    ui->doubleSpinBox_5->setValue(26.8400);
    ui->doubleSpinBox_3->setValue(29.9378);
    ui->doubleSpinBox_2->setValue(54389);
    ui->doubleSpinBox_6->setValue(327.40);
    ui->doubleSpinBox_12->setValue(36997.00);
    ui->doubleSpinBox_13->setValue(37018.00);
    ui->doubleSpinBox_14->setValue(0.00);

    ui->checkBox_7->setChecked(true);

    ui->lineEdit_2->setText("/home/daniels/Observations/Capella/Set_15/Ca_UV/subset1");
    qRvPath=ui->lineEdit_2->text();
    rvPath = qRvPath.toUtf8().constData();
    ui->lineEdit->setText("times_rv15.dat");

    ui->lineEdit_7->setText("rv13.dat");
    ui->lineEdit_10->setText("cab_");
    ui->lineEdit_11->setText(".dat");

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
    ui->comboBox->addItem("HR5110");
}

RVCalc::~RVCalc()
{
    delete ui;
}

double function (double X[], double RVCt, double RVCT0, double RVCP, double RVCe){
    double func;

    func= abs(RVCe*sin(X[0])+2*M_PI*(RVCt-RVCT0)/RVCP-X[0]);

    return func;

    }

//calculate RVs
void RVCalc::on_doubleSpinBox_9_valueChanged()
{
    RVCP=ui->doubleSpinBox->value();
    RVCT0=ui->doubleSpinBox_2->value();
    double gamma=ui->doubleSpinBox_3->value();
    double KA=ui->doubleSpinBox_4->value();
    double KB=ui->doubleSpinBox_5->value();
    double WA=ui->doubleSpinBox_6->value()/180*M_PI;
    double WB=WA+M_PI;
    RVCe=ui->doubleSpinBox_8->value();
    RVCt=ui->doubleSpinBox_9->value();
    double RVA, RVB, theta, E;

    //if(RVCe!=0){

        RVCalc::findroot();
        E=RVCE;
        theta=2*(atan(tan(E/2)*sqrt((1+RVCe)/(1-RVCe))));

    /*}
    else{
        E = M_PI*(RVCt-RVCT0)/RVCP;
        theta=2*(atan(tan(E/2)));
    }*/

    cout<<E<<endl;


    RVA = gamma + KA*(cos(theta+WA)+RVCe*cos(WA));
    RVB = gamma + KB*(cos(theta+WB)+RVCe*cos(WB));

    ui->doubleSpinBox_10->setValue(RVA);
    ui->doubleSpinBox_11->setValue(RVB);

}


//
void RVCalc::on_pushButton_2_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));

    ui->customPlot->clearGraphs();

    RVCP=ui->doubleSpinBox->value();
    RVCT0=ui->doubleSpinBox_2->value();
    double gamma=ui->doubleSpinBox_3->value();
    double KA=ui->doubleSpinBox_4->value();
    double KB=ui->doubleSpinBox_5->value();
    double WA=ui->doubleSpinBox_6->value()/180*M_PI;
    double WB=WA+M_PI;
    RVCe=ui->doubleSpinBox_8->value();

    double t1=ui->doubleSpinBox_12->value();
    double t2=ui->doubleSpinBox_13->value();
    double dt = RVCP/100;
    double theta, E;
    int steps =(t2-t1)/dt;
    QVector<double> RVA(steps), RVB(steps), t(steps);


    for(int m=0; m<steps; m++){
        t[m]=t1+m*dt;

        if(RVCe!=0){
            RVCt = t[m];
            RVCalc::findroot();
            E=RVCE;
            theta=2*(atan(tan(E/2)*sqrt((1+RVCe)/(1-RVCe))));
        }

        else{
            E = M_PI*(t[m]-RVCT0)/RVCP;
            theta=2*(atan(tan(E/2)));
        }

    RVA[m] = gamma + KA*(cos(theta+WA)+RVCe*cos(WA));
    RVB[m] = gamma + KB*(cos(theta+WB)+RVCe*cos(WB));
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
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int lines =0;

        while(std::getline(toplot1, zeile))
           ++ lines;

        toplot1.clear();
        toplot1.seekg(0, ios::beg);

        QVector<double> at(lines), bt(lines), ct(lines);

        double at1;
        int a=(t2-t1)/RVCP;

        for (int i=0; i<lines; i++){
        toplot1 >> one >>two>>three;
        istringstream ist(one);
        ist >> at[i];
        at[i]=at[i]-ui->doubleSpinBox_14->value();
        if(i==0){
            at1=at[0];
        }
        if(ui->checkBox_2->isChecked()){

            if(at[i]-at1>=RVCP){
            for(int e=0; e<a; e++){

                at[i]=at[i]-RVCP;
                if(at[i]<at1){
                    at[i]=at[i]+RVCP;
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
            ui->customPlot->xAxis->setRange(at1-5, at1+RVCP);
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
    this->setCursor(QCursor(Qt::WaitCursor));

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
        this->setCursor(QCursor(Qt::ArrowCursor));
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

    RVCP=ui->doubleSpinBox->value();
    RVCT0=ui->doubleSpinBox_2->value();
    double gamma=ui->doubleSpinBox_3->value();
    double KA=ui->doubleSpinBox_4->value();
    double KB=ui->doubleSpinBox_5->value();
    double WA=ui->doubleSpinBox_6->value()/180*M_PI;
    double WB=WA-M_PI;
    RVCe=ui->doubleSpinBox_8->value();
    double theta, E;

    QString qout=ui->lineEdit_7->text();
    string out = qout.toUtf8().constData();
    std::ostringstream outNameStream(out);
    outNameStream<<rvPath<<"/"<<out;
    std::string outName = outNameStream.str();
    ofstream oout(outName.c_str());

    QString qout2=ui->lineEdit_9->text();
    string out2 = qout2.toUtf8().constData();
    std::ostringstream out2NameStream(out2);
    out2NameStream<<rvPath<<"/"<<out2;
    std::string out2Name = out2NameStream.str();
    ofstream oout2(out2Name.c_str());

    for(int m=0; m<lines; m++){

        if(RVCe!=0){

            RVCt = tim[m];
            RVCalc::findroot();
            E=RVCE;
            theta=2*(atan(tan(E/2)*sqrt((1+RVCe)/(1-RVCe))));

        }
        else{
            E = M_PI*(tim[m]-RVCT0)/RVCP;
            theta=2*(atan(tan(E/2)));
        }

    oout<<setprecision(12)<<gamma + KA*(cos(theta+WA)+RVCe*cos(WA))<<"\t"<<gamma + KB*(cos(theta+WB)+RVCe*cos(WB))<<endl;
    oout2<<setprecision(14)<<tim[m]<<"\t"<<gamma + KA*(cos(theta+WA)+RVCe*cos(WA))<<"\t"<<gamma + KB*(cos(theta+WB)+RVCe*cos(WB))<<endl;

    }

    this->setCursor(QCursor(Qt::ArrowCursor));

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
        ui->doubleSpinBox_2->setValue(2454389);
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
        ui->doubleSpinBox_2->setValue(2452269.84);
        ui->doubleSpinBox_6->setValue(-29);
    }

    // BAT99_32
    if(ui->comboBox->currentIndex()==3){
        ui->doubleSpinBox->setValue(1.90756);
        ui->doubleSpinBox_8->setValue(0.06);
        ui->doubleSpinBox_4->setValue(120);
        ui->doubleSpinBox_5->setValue(120);
        ui->doubleSpinBox_3->setValue(288);
        ui->doubleSpinBox_2->setValue(2453011.57);
        ui->doubleSpinBox_6->setValue(250);
    }

    // BAT99_77
    if(ui->comboBox->currentIndex()==4){
        ui->doubleSpinBox->setValue(3.00303);
        ui->doubleSpinBox_8->setValue(0.32);
        ui->doubleSpinBox_4->setValue(144);
        ui->doubleSpinBox_5->setValue(144);
        ui->doubleSpinBox_3->setValue(339);
        ui->doubleSpinBox_2->setValue(2452631.87);
        ui->doubleSpinBox_6->setValue(7);
    }

    // BAT99_92
    if(ui->comboBox->currentIndex()==5){
        ui->doubleSpinBox->setValue(4.3125);
        ui->doubleSpinBox_8->setValue(0.02);
        ui->doubleSpinBox_4->setValue(204);
        ui->doubleSpinBox_5->setValue(204);
        ui->doubleSpinBox_3->setValue(332);
        ui->doubleSpinBox_2->setValue(2452998.03);
        ui->doubleSpinBox_6->setValue(109);
    }

    // BAT99_95
    if(ui->comboBox->currentIndex()==6){
        ui->doubleSpinBox->setValue(2.1110);
        ui->doubleSpinBox_8->setValue(0.07);
        ui->doubleSpinBox_4->setValue(107);
        ui->doubleSpinBox_5->setValue(107);
        ui->doubleSpinBox_3->setValue(274);
        ui->doubleSpinBox_2->setValue(2452999.87);
        ui->doubleSpinBox_6->setValue(285);
    }

    // BAT99_99
    if(ui->comboBox->currentIndex()==7){
        ui->doubleSpinBox->setValue(92.60);
        ui->doubleSpinBox_8->setValue(0);
        ui->doubleSpinBox_4->setValue(91);
        ui->doubleSpinBox_5->setValue(0);
        ui->doubleSpinBox_3->setValue(337);
        ui->doubleSpinBox_2->setValue(2453007.8);
        ui->doubleSpinBox_6->setValue(0);
    }


    // BAT99_103
    if(ui->comboBox->currentIndex()==8){
        ui->doubleSpinBox->setValue(2.75975);
        ui->doubleSpinBox_8->setValue(0.23);
        ui->doubleSpinBox_4->setValue(158);
        ui->doubleSpinBox_5->setValue(156);
        ui->doubleSpinBox_3->setValue(388);
        ui->doubleSpinBox_2->setValue(2453007.8);
        ui->doubleSpinBox_6->setValue(-41);
    }

    // BAT99_113
    if(ui->comboBox->currentIndex()==9){
        ui->doubleSpinBox->setValue(4.699);
        ui->doubleSpinBox_8->setValue(0.20);
        ui->doubleSpinBox_4->setValue(130);
        ui->doubleSpinBox_5->setValue(125);
        ui->doubleSpinBox_3->setValue(390);
        ui->doubleSpinBox_2->setValue(2452993.07);
        ui->doubleSpinBox_6->setValue(308);
    }

    // BAT99_119
    if(ui->comboBox->currentIndex()==10){
        ui->doubleSpinBox->setValue(159.0886);
        ui->doubleSpinBox_8->setValue(0.8191);
        ui->doubleSpinBox_4->setValue(101.2374);
        ui->doubleSpinBox_5->setValue(100);
        ui->doubleSpinBox_3->setValue(290);
        ui->doubleSpinBox_2->setValue(2456501.2889);
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

    // HR5110
    if(ui->comboBox->currentIndex()==14){
        ui->doubleSpinBox->setValue(2.613214);
        ui->doubleSpinBox_8->setValue(0.00);
        ui->doubleSpinBox_4->setValue(8.9);
        ui->doubleSpinBox_5->setValue(5.0);
        ui->doubleSpinBox_3->setValue(8.6);
        ui->doubleSpinBox_2->setValue(2445766.655);
        ui->doubleSpinBox_6->setValue(89);
    }
}

//*****************************************
// Residuum between calculated and data
//*****************************************
void RVCalc::on_pushButton_6_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));

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
        this->setCursor(QCursor(Qt::ArrowCursor));
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

    RVCP=ui->doubleSpinBox->value();
    RVCT0=ui->doubleSpinBox_2->value();
    double gamma=ui->doubleSpinBox_3->value();
    double KA=ui->doubleSpinBox_4->value();
    double KB=ui->doubleSpinBox_5->value();
    double WA=ui->doubleSpinBox_6->value()/180*M_PI;
    double WB=WA-M_PI;
    RVCe=ui->doubleSpinBox_8->value();
    double theta, E;;

    double RVA, RVB, residuumA, residuumB;

    for(int m=0; m<lines; m++){

        if(RVCe!=0){

            RVCt=at[m];
            RVCalc::findroot();
            E=RVCE;
            theta=2*(atan(tan(E/2)*sqrt((1+RVCe)/(1-RVCe))));
        }

        else{
            E = M_PI*(at[m]-RVCT0)/RVCP;
            theta=2*(atan(tan(E/2)));
        }

    RVA = gamma + KA*(cos(theta+WA)+RVCe*cos(WA));
    RVB = gamma + KB*(cos(theta+WB)+RVCe*cos(WB));

    residuumA += pow((RVA - bt[m]),2);
    residuumB += pow((RVB - ct[m]),2);

    }

    residuumA = sqrt(residuumA/(lines-1));
    residuumB = sqrt(residuumB/(lines-1));

    QString ResA = QString::number(residuumA);
    QString ResB = QString::number(residuumB);

    ui->lineEdit_8->setText(ResA+" / "+ResB);

    this->setCursor(QCursor(Qt::ArrowCursor));
}

//**************************************
// root finding
//**************************************
void RVCalc::findroot(){

    int n=1, Ph, Pl, Psh, zaehler=80, eval=0;
    double yh, ysh, yl, ym, yi, ys, yt;
    double sigma = 1e-5;
    double step=0.1;
    double gamma=2.0;	//expansion coeff.
    double alpha =1.0;	//reflection coeff.
    double beta=0.5;	//contraction coeff.
    double btot=0.5;	//total contraction coeff.
    double y[n+1], Pm[n+1][n], Z[n], C[n], S[n], Em[n], X[n], e[n][n];


        //initial points
        Pm[0][0]=2*M_PI*(RVCt-RVCT0)/RVCP-2*RVCe;
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
        }
        if(i!=0){
        Pm[i][j]=Pm[0][j]+step*e[i][j];
        X[j]=Pm[i][j];
        }
        }
        y[i]=function(X, RVCt, RVCT0, RVCP, RVCe);
        eval++;
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
        }}

        //looking for smallest value
        yl=yh;
        for (int j=0; j<n+1; j++){
        if(y[j]<yl){
        yl=y[j];
        Pl = j;
        }}
        cout<<"yl: "<<yl<<endl;

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
        }}}

        //reflect highest value at centroid
        for (int i=0; i<n; i++){
        C[i]=Z[i]+alpha*(Z[i]-Pm[Ph][i]);
        }
        yi=function(C, RVCt, RVCT0, RVCP, RVCe);
        eval++;

        if(yi<yl){
        for (int i=0; i<n; i++){
        Em[i]=Z[i]+gamma*(C[i]-Z[i]);
        }
        yt=function(Em, RVCt, RVCT0, RVCP, RVCe);
        eval++;
        if(yt<yl){
        for (int i=0; i<n; i++){
        Pm[Ph][i]=Em[i];
        }
        y[Ph]=yt;//function(E);
        //eval++;
        }
        if (yt>=yl){
        for (int i=0; i<n; i++){
        Pm[Ph][i]=C[i];
        }
        eval++;
        y[Ph]=function(C, RVCt, RVCT0, RVCP, RVCe);
        }}

        if(yi>=yl){
        if(yi<=ysh){
        for(int i=0; i<n; i++){
        Pm[Ph][i]=C[i];
        }
        eval++;
        y[Ph]=function(C, RVCt, RVCT0, RVCP, RVCe);
        }
        if(yi>ysh){
        if(yi<=yh){
        for(int i=0; i<n; i++){
        Pm[Ph][i]=C[i];
        }
        eval++;
        y[Ph]=function(C, RVCt, RVCT0, RVCP, RVCe);
        yh=y[Ph];
        }
        for(int i=0; i<n; i++){
        S[i]=Z[i]+beta*(Pm[Ph][i]-Z[i]);
        }
        yt=function(S, RVCt, RVCT0, RVCP, RVCe);
        eval++;
        if(yt>yh){
        for (int j=0; j<n+1; j++){
        for (int i=0; i<n; i++){
        Pm[j][i]=Pm[Pl][i]+btot*(Pm[j][i]-Pm[Pl][i]); //total contraction
        X[i]=Pm[j][i];
        }
        y[j]=function(X, RVCt, RVCT0, RVCP, RVCe);
        eval++;
        }}

        if(yt<=yh){
        for(int i=0; i<n; i++){
        Pm[Ph][i]=S[i];
        }
        eval++;
        y[Ph]=function(S, RVCt, RVCT0, RVCP, RVCe);
        }}

        }
        }//end main loop

        //looking for highest value
        yh=y[0];
        for (int j=0; j<n+1; j++){
        if(y[j]>=yh){
        yh = y[j];
        Ph = j;
        }}

        //looking for smallest value
        yl=yh;
        for (int j=0; j<n+1; j++){
        if(y[j]<yl){
        yl=y[j];
        Pl = j;
        }}

        //looking for second highest value
        ysh=yl;
        for (int j=0; j<n+1; j++){
        if(y[j]>ysh & y[j]<yh){
        ysh=y[j];
        Psh=j;
        }}

        RVCE=Pm[Pl][0];

}


//number of independent spectra
void RVCalc::on_pushButton_7_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));

    string one, two, three, zeile;

    double reso = ui->doubleSpinBox_15->value();

    if(reso==0){
        this->setCursor(QCursor(Qt::ArrowCursor));

        return;
    }

    QString aver=ui->lineEdit_10->text();
    string aver1 = aver.toUtf8().constData();

    QString qfExten = ui->lineEdit_11->text();
    string fExten = qfExten.toUtf8().constData();

    QString plot1=ui->lineEdit_9->text();
    string plot11 = plot1.toUtf8().constData();
    std::ostringstream datNameStream(plot11);
    datNameStream<<rvPath<<"/"<<plot11;
    std::string datName = datNameStream.str();
    ifstream toplot1(datName.c_str());

    QFile checkfile(datName.c_str());

    if(!checkfile.exists()){
        qDebug()<<"Error1: The file "<<checkfile.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+qRvPath+"/"+plot1+" does not exist!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    int lines =0, bb=0, cc=0;

    while(std::getline(toplot1, zeile))
       ++ lines;

    toplot1.clear();
    toplot1.seekg(0, ios::beg);

    QVector<double> bt(lines), at(lines), otim(lines);

    for (int i=0; i<lines; i++){
    toplot1 >> one>>two>>three;
    istringstream ist1(one);
    ist1 >> otim[i];
    istringstream ist2(two);
    ist2 >> bt[i];
    istringstream ist3(three);
    ist3 >> at[i];
    }
    toplot1.close();

    int count=0, count2=0, count3=0, nind=0, lines1=0, lines2=0;
    int indep=0;
    double dist=0;
    QVector<double> inrvsb(lines), inrvsa(lines);
    QVector<double> W1(lines), I1(lines);

    // iterative

    if(ui->checkBox_6->isChecked()){

        if(ui->checkBox_5->isChecked()){

            for(int e = 0; e<lines; e++){

                std::ostringstream datNameStream(aver1);
                datNameStream<<rvPath<<"/"<<aver1<<e<<fExten;
                std::string datName = datNameStream.str();
                ifstream in(datName.c_str());

                int pixe=0;

                while(std::getline(in, zeile))
                   ++ pixe;

                in.clear();
                in.seekg(0, ios::beg);

                QVector<double> Ww(pixe), Ii(pixe);

                for (int i=0; i<pixe; i++){
                in >> one>>two;
                istringstream ist2(one);
                ist2 >> Ww[i];
                istringstream ist(two);
                ist >> Ii[i];
                }
                in.close();

                ofstream out(datName.c_str());

                out <<"1\t1"<<endl;
                for(int i =0; i<pixe; i++){
                    out<<setprecision(12)<<Ww[i]<<"\t"<<Ii[i]<<endl;
                }
            }
        }

    while (count2<bt.size()){
        cout<<"Run # "<<count3<<endl;
        ++count3;
        count2=0;

    for(int i = 0; i<bt.size(); i++){
        for(int n =0; n<bt.size(); n++){
            if(n!=i){
                if(abs(bt[i]-bt[n])<=2*reso or (abs(at[i]-at[n])<=2*reso)){
                    if(count==0){
                    count=1;
                    nind = n;
                    if(abs(bt[i]-bt[n])<=2*reso){
                    dist=abs(bt[i]-bt[n]);
                    }
                    else{
                        dist=abs(at[i]-at[n]);
                    }
                    }
                    else if(abs(bt[i]-bt[n])<dist or (abs(at[i]-at[n])<dist)){
                        if(abs(bt[i]-bt[n])<dist){
                        dist=abs(bt[i]-bt[n]);
                        }
                        else{
                            dist=abs(at[i]-at[n]);
                        }

                        nind = n;
                    }
                }
            }
        }
        if(count==1){
            ++indep;
            bt[i]=(bt[i]+bt[nind])/2;
            at[i]=(at[i]+at[nind])/2;

            cout<<"Add "<<i<<" + "<<nind<<endl;

            lines1=0;
            lines2=0;
            int aa = 0;

            if(ui->checkBox_5->isChecked()){

            std::ostringstream dat1NameStream(aver1);
            dat1NameStream<<rvPath<<"/"<<aver1<<i<<fExten;
            std::string dat1Name = dat1NameStream.str();
            ifstream out1(dat1Name.c_str());

            QFile checkfile1(dat1Name.c_str());

            if(!checkfile1.exists()){
                qDebug()<<"Error2: The file "<<checkfile1.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error", "File "+qRvPath+"/"+aver+" does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }

            while(std::getline(out1, zeile))
               ++ lines1;

            out1.clear();
            out1.seekg(0, ios::beg);

            W1.resize(lines1-1), I1.resize(lines1-1);

            for (int q=0; q<lines1; q++){
            out1 >> one>>two;
            if(q==0){
                istringstream ist3(one);
                ist3 >> cc;
                istringstream ist4(two);
                ist4 >> cc;
            }
            else{
                istringstream ist3(one);
                ist3 >> W1[q-1];
                istringstream ist4(two);
                ist4 >> I1[q-1];
            }
            }
            out1.close();

            std::ostringstream dat2NameStream(aver1);
            dat2NameStream<<rvPath<<"/"<<aver1<<nind<<fExten;
            std::string dat2Name = dat2NameStream.str();
            ifstream out2(dat2Name.c_str());

            QFile checkfile2(dat2Name.c_str());

            if(!checkfile2.exists()){
                qDebug()<<"Error3: The file "<<checkfile2.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error", "File "+qRvPath+"/"+aver+" does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }

            while(std::getline(out2, zeile))
               ++ lines2;

            out2.clear();
            out2.seekg(0, ios::beg);

            QVector<double> W2(lines2-1), I2(lines2-1);

            for (int q=0; q<lines2; q++){
            out2 >> one>>two;
            if(q==0){
                istringstream ist5(one);
                ist5 >> bb;
                istringstream ist6(two);
                ist6 >> bb;
            }
            else{
            istringstream ist5(one);
            ist5 >> W2[q-1];
            istringstream ist6(two);
            ist6 >> I2[q-1];
            }
            }
            out2.close();

            if(lines2<lines1) lines1=lines2;
            else lines1 = lines1;


            for(int q =0; q<lines1-1; q++){

                for(int e=aa; e<aa+5; e++){

                    if(W2[e]==W1[q]){
                        I1[q]=(I1[q]+I2[e]);
                        aa=e;
                    }
                    else if ((W2[e]<W1[q])&(W2[e+1]>W1[q])){
                        I1[q]=(I1[q]+I2[e]+(W1[q]-W2[e])/(W2[e+1]-W2[e])*(I2[e+1]-I2[e]));
                        aa=e;
                    }
                }
            }

            ofstream out3(dat1Name.c_str());

            for(int q = 0; q<I1.size(); q++){
                if(q==0){
                    out3<<bb+cc<<"\t"<<bb+cc<<endl;
                }
                else{
                    out3<<setprecision(12)<<W1[q]<<"\t"<<I1[q]<<endl;
                }
            }
            out3.close();

            remove(dat2Name.c_str());

            for(int q = nind+1; q<bt.size(); q++){
                std::ostringstream dat3NameStream(aver1);
                dat3NameStream<<rvPath<<"/"<<aver1<<q-1<<fExten;
                std::string newname = dat3NameStream.str();

                std::ostringstream dat4NameStream(aver1);
                dat4NameStream<<rvPath<<"/"<<aver1<<q<<fExten;
                std::string oldname = dat4NameStream.str();

                const char *OLD, *NEW;

                OLD = oldname.c_str();
                NEW = newname.c_str();

                rename(OLD, NEW);

            }
            }

            inrvsb.resize(lines-indep);
            inrvsa.resize(lines-indep);
            for(int m =0; m<bt.size(); m++){
                if(m<nind){
                    inrvsb[m]=bt[m];
                    inrvsa[m]=at[m];
                }
                if(m>nind){
                    inrvsb[m-1]=bt[m];
                    inrvsa[m-1]=at[m];
                }
            }
            bt.resize(lines-indep);
            at.resize(lines-indep);
            for(int m =0; m<lines-indep; m++){
                bt[m]=inrvsb[m];
                at[m]=inrvsa[m];
            }
        }
        else {
            cout<<"For "<<i<<" all differences greater. ";
            ++count2;
        }
        count=0;
        cout<<bt[i]<<"\t"<<at[i]<<endl;
        cout<<endl;
    }
    }

    if(ui->checkBox_5->isChecked()){

        for(int e = 0; e<bt.size(); e++){

            std::ostringstream datNameStream(aver1);
            datNameStream<<rvPath<<"/"<<aver1<<e<<fExten;
            std::string datName = datNameStream.str();
            ifstream in(datName.c_str());

            int pixe=0;

            while(std::getline(in, zeile))
               ++ pixe;

            in.clear();
            in.seekg(0, ios::beg);

            QVector<double> WW(pixe-1), II(pixe-1);

            for (int i=0; i<pixe; i++){
            in >> one>>two;
            if(i==0){
                istringstream ist2(one);
                ist2 >> bb;
                istringstream ist(two);
                ist >> bb;
            }
            else{
                istringstream ist2(one);
                ist2 >> WW[i-1];
            istringstream ist(two);
            ist >> II[i-1];
            II[i-1]=II[i-1]/bb;
            }
            }
            in.close();

            ofstream out(datName.c_str());

            for(int i =1; i<pixe-1; i++){
                out<<setprecision(12)<<WW[i]<<"\t"<<II[i]<<endl;
            }
            cout<<bt[e]<<"\t"<<at[e]<<endl;
        }
    }

    }

    // all at once
    else if(ui->checkBox_7->isChecked()){

        int count=0, count2=1, count3=0, count4=0, count5=0;
        QVector<int> rese(count2), rese2(count2), nspec(count2);
        rese[0]=0;
        double current1=0, current2=0;

        std::ostringstream datNameStream(aver1);
        datNameStream<<rvPath<<"/"<<aver1<<"rv"<<fExten;
        std::string datName = datNameStream.str();
        ofstream rvout(datName.c_str());

        for(int i =0; i<bt.size(); i++){
            cout<<"Add "<<i<<"\t";
            current1=bt[i];
            current2=at[i];
            count=0;
            count3=0;

            if(i>0){
            for(int e =0; e<rese.size(); e++){
                if(i!=rese[e]){
                    ++count;
                }
                else ++count3;
            }
            if(count==rese.size()){
                for(int q = 0; q<rese.size(); q++){
                    rese2[q]=rese[q];
                }
                ++count2;
                rese.resize(count2);
                for(int q = 0; q<rese.size(); q++){
                    if(q==rese.size()-1){
                        rese[q]=i;
                    }
                    else{
                        rese[q]=rese2[q];
                    }
                }
                rese2.resize(count2);
            }}
            //cout<<count<<"\t"<<count2<<"\t";

            for(int n=0; n<bt.size(); n++){
                count = 0;
                if(abs(current1-bt[n])<=2*reso & (abs(current2-at[n])<=2*reso & count3==0) ){

                    for(int e =0; e<count2; e++){
                        if(n!=rese[e] & (i!=n)){
                            ++count;
                        }
                        else{

                        }
                    }
                    if(count==rese.size()){
                        bt[i]+=bt[n];
                        at[i]+=at[n];
                        otim[i]+=otim[n];
                        for(int q = 0; q<rese.size(); q++){
                            rese2[q]=rese[q];
                        }
                        ++count2;
                        rese.resize(count2);
                        for(int q = 0; q<rese.size(); q++){
                            if(q==rese.size()-1){
                                rese[q]=n;
                            }
                            else{
                                rese[q]=rese2[q];
                            }
                        }
                        rese2.resize(count2);
                        cout<<rese[count2-1]<<"\t";
                    }
                    count=0;
                }
            }
            if(count2==count4+1){
                cout<<"Single"<<endl;
            }
            if(count2!=count4){
                ++count5;
                nspec.resize(count5);
                nspec[count5-1]=count2;
            }

            cout<<count2<<"\t"<<count4<<"\t";
            if(count2-count4>0){
                bt[i]=bt[i]/((count2-count4));
                at[i]=at[i]/((count2-count4));
                otim[i]=otim[i]/((count2-count4));
                count4=count2;

                rvout<<setprecision(16)<<otim[i]<<"\t"<<bt[i]<<" \t"<<at[i]<<endl;
                cout<<endl;
                cout<<setprecision(16)<<otim[i]<<"\t"<<bt[i]<<" \t"<<at[i]<<endl;
                cout<<endl;
            }
        }

        cout<<count5<<endl;

        if(ui->checkBox_5->isChecked()){

        int spec=0, stsp=0, aa=0, ndiv=1;

        for(int q = 0; q<nspec.size(); q++){
            if(q==0){
                stsp=0;
                ndiv=nspec[0];
            }
            else{
                stsp=nspec[q-1];
                ndiv=nspec[q]-nspec[q-1];
            }
            for(int e = stsp; e<nspec[q]; e++){

                spec = rese[e];

                if(e==stsp){
                    lines1=0;
                std::ostringstream datNameStream(aver1);
                datNameStream<<rvPath<<"/"<<aver1<<spec<<fExten;
                std::string datName = datNameStream.str();
                ifstream in(datName.c_str());

                QFile checkfile1(datName.c_str());

                if(!checkfile1.exists()){
                    qDebug()<<"Error2: The file "<<checkfile1.fileName()<<" does not exist.";
                    QMessageBox::information(this, "Error", "File "+qRvPath+"/"+aver+" does not exist!");
                    this->setCursor(QCursor(Qt::ArrowCursor));
                   return;
                }

                while(std::getline(in, zeile))
                   ++ lines1;

                in.clear();
                in.seekg(0, ios::beg);

                W1.resize(lines1), I1.resize(lines1);

                for (int q=0; q<lines1; q++){
                in >> one>>two;
                istringstream ist3(one);
                ist3 >> W1[q];
                istringstream ist4(two);
                ist4 >> I1[q];
                }
                in.close();
                }

                else{
                    std::ostringstream datNameStream(aver1);
                    datNameStream<<rvPath<<"/"<<aver1<<spec<<fExten;
                    std::string datName = datNameStream.str();
                    ifstream in(datName.c_str());

                    QFile checkfile1(datName.c_str());

                    if(!checkfile1.exists()){
                        qDebug()<<"Error2: The file "<<checkfile1.fileName()<<" does not exist.";
                        QMessageBox::information(this, "Error", "File "+qRvPath+"/"+aver+" does not exist!");
                        this->setCursor(QCursor(Qt::ArrowCursor));
                       return;
                    }

                    while(std::getline(in, zeile))
                       ++ lines2;

                    in.clear();
                    in.seekg(0, ios::beg);

                    QVector<double> W2(lines2), I2(lines2);

                    for (int q=0; q<lines2; q++){
                    in >> one>>two;
                    istringstream ist3(one);
                    ist3 >> W2[q];
                    istringstream ist4(two);
                    ist4 >> I2[q];
                    }
                    in.close();

                    aa=0;

                    for(int l =0; l<lines1-1; l++){

                        for(int e=aa; e<aa+5; e++){

                            if(W2[e]==W1[l]){
                                I1[l]=I1[l]+I2[e];
                                aa=e;
                            }
                            else if ((W2[e]<W1[l])&(W2[e+1]>W1[l])){
                                I1[l]=I1[l]+I2[e]+(W1[l]-W2[e])/(W2[e+1]-W2[e])*(I2[e+1]-I2[e]);
                                aa=e;
                            }
                        }
                    }
                }

            }

            std::ostringstream datNameStream(aver1);
            datNameStream<<rvPath<<"/"<<aver1<<"av_"<<q<<fExten;
            std::string datName = datNameStream.str();
            ofstream out(datName.c_str());

            for(int l = 0; l<lines1; l++){
                out<<setprecision(12)<<W1[l]<<"\t"<<I1[l]/ndiv<<endl;
            }
        }
        }
    }

    ui->spinBox_2->setValue(bt.size());

    this->setCursor(QCursor(Qt::ArrowCursor));

}

void RVCalc::on_checkBox_6_clicked()
{
    if(ui->checkBox_6->isChecked()){
        ui->checkBox_7->setChecked(false);
    }
    else{
        ui->checkBox_7->setChecked(true);
    }
}

void RVCalc::on_checkBox_7_clicked()
{
    if(ui->checkBox_7->isChecked()){
        ui->checkBox_6->setChecked(false);
    }
    else{
        ui->checkBox_6->setChecked(true);
    }
}

//***********************************
// Reject a File
//***********************************
void RVCalc::on_pushButton_8_clicked()
{

    this->setCursor(QCursor(Qt::WaitCursor));


    int rn = ui->spinBox_3->value();
    int nf = rn+1;

    QString qfile=ui->lineEdit_10->text();
    string file1 = qfile.toUtf8().constData();

    QString qfExten = ui->lineEdit_11->text();
    string fExten = qfExten.toUtf8().constData();

    std::ostringstream dat1NameStream(file1);
    dat1NameStream<<rvPath<<"/"<<file1<<rn<<fExten;
    std::string dat1Name = dat1NameStream.str();

    remove(dat1Name.c_str());



    for(int i = rn; i<nf; i++){
        std::ostringstream dat3NameStream(file1);
        dat3NameStream<<rvPath<<"/"<<file1<<i<<fExten;
        std::string newname = dat3NameStream.str();

        std::ostringstream dat4NameStream(file1);
        dat4NameStream<<rvPath<<"/"<<file1<<i+1<<fExten;
        std::string oldname = dat4NameStream.str();

        QFile checkfile4(oldname.c_str());

        if(!checkfile4.exists()){
            this->setCursor(QCursor(Qt::ArrowCursor));
        }
        else ++nf;

        const char *OLD, *NEW;

        OLD = oldname.c_str();
        NEW = newname.c_str();

        rename(OLD, NEW);
    }

    if(ui->checkBox_8->isChecked()){

        int lines=0;
        string one, two, three, zeile;

        QString qrvf = ui->lineEdit_9->text();
        string rvf = qrvf.toUtf8().constData();
        std::ostringstream dat2NameStream(rvf);
        dat2NameStream<<rvPath<<"/"<<rvf;
        std::string dat2Name = dat2NameStream.str();
        ifstream inf(dat2Name.c_str());

        QFile checkfile2(dat2Name.c_str());

        if(!checkfile2.exists()){
            qDebug()<<"Error3: The file "<<checkfile2.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File "+qRvPath+"/"+qrvf+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        while(std::getline(inf, zeile))
           ++ lines;

        inf.clear();
        inf.seekg(0, ios::beg);

        QVector<double> times(lines), rv1(lines), rv2(lines);

        for (int q=0; q<lines; q++){
            inf >> one>>two>>three;
            istringstream ist1(one);
            ist1 >> times[q];
            istringstream ist2(two);
            ist2 >> rv1[q];
            istringstream ist3(three);
            ist3 >> rv2[q];
        }
        inf.close();

        remove(dat2Name.c_str());

        ofstream ouf(dat2Name.c_str());

        for(int i =0; i<lines; i++){
            if(i!=rn){
                ouf<<setprecision(16)<<times[i]<<"\t"<<rv1[i]<<"\t"<<rv2[i]<<endl;
            }
        }

        ouf.close();

    }

    this->setCursor(QCursor(Qt::ArrowCursor));


}

void RVCalc::on_pushButton_9_clicked()
{
    int linesn=0, lineso=0;
    string one, two, three, zeile;

    string oldf = "times_rv13.dat";
    string newf = "rv13.dat";
    string timf = "times13.dat";

    std::ostringstream dat1NameStream(oldf);
    dat1NameStream<<rvPath<<"/"<<oldf;
    std::string dat1Name = dat1NameStream.str();
    ifstream inold(dat1Name.c_str());

    std::ostringstream dat2NameStream(newf);
    dat2NameStream<<rvPath<<"/"<<newf;
    std::string dat2Name = dat2NameStream.str();
    ifstream innew(dat2Name.c_str());

    std::ostringstream dat3NameStream(timf);
    dat3NameStream<<rvPath<<"/"<<timf;
    std::string dat3Name = dat3NameStream.str();
    ofstream outt(dat3Name.c_str());

    ofstream tes("test.dat");

    while(std::getline(innew, zeile))
       ++ linesn;

    innew.clear();
    innew.seekg(0, ios::beg);

    QVector<double> nrv1(linesn), nrv2(linesn);

    for (int q=0; q<linesn; q++){
        innew >> one>>two;
        istringstream ist1(one);
        istringstream ist2(two);
        ist1 >>nrv1[q];
        ist2 >>nrv2[q];
        tes<<fixed<<setprecision(5)<<nrv1[q]<<"\t"<<nrv2[q]<<endl;
    }
    innew.close();
    tes.close();

    ifstream tes2("test.dat");

    for (int q=0; q<linesn; q++){
        tes2 >> one>>two;
        istringstream ist1(one);
        istringstream ist2(two);
        ist1 >>nrv1[q];
        ist2 >>nrv2[q];
        cout<<setprecision(14)<<nrv1[q]<<"\t"<<nrv2[q]<<endl;
    }
    tes2.close();

    while(std::getline(inold, zeile))
       ++ lineso;

    inold.clear();
    inold.seekg(0, ios::beg);

    QVector<double> otimes(lineso), orv1(lineso), orv2(lineso);

    ofstream tes3("test.dat");

    for (int q=0; q<lineso; q++){
        inold >> one>>two>>three;
        istringstream ist1(one);
        istringstream ist2(two);
        istringstream ist3(three);
        ist2 >> orv1[q];
        ist3 >> orv2[q];
        ist1 >> otimes[q];
        tes3<<fixed<<setprecision(5)<<orv1[q]<<"\t"<<orv2[q]<<endl;
    }
    inold.close();
    tes3.close();

    ifstream tes4("test.dat");

    for (int q=0; q<lineso; q++){
        tes4 >> one>>two;
        istringstream ist1(one);
        istringstream ist2(two);
        ist1 >>orv1[q];
        ist2 >>orv2[q];
        cout<<setprecision(14)<<orv1[q]<<"\t"<<orv2[q]<<endl;
    }
    tes4.close();

    for(int i = 0; i<linesn; i++){
        for(int q = 0; q<lineso; q++){
            if(nrv1[i]==orv1[q]){
                outt<<setprecision(14)<<otimes[q]<<endl;
                q=lineso;
            }
            else{
                q=q;
            }
        }
    }

    cout<<orv1[1]<<"\t"<<orv2[1]<<endl;

}
