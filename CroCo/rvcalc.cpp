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
QVector<double> PER(1), ECC(1), AMPA(1), AMPB(1), GAM(1), PERI(1), LPERI(1);

QString qRvPath;
string rvPath;

RVCalc::RVCalc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RVCalc)
{
    ui->setupUi(this);
    this->setWindowTitle("RV Calculator");


    ui->checkBox_7->setChecked(true);

    ui->lineEdit_2->setText(QDir::currentPath());
    qRvPath=ui->lineEdit_2->text();
    rvPath = qRvPath.toUtf8().constData();
    ui->lineEdit->setText("times_rv15.dat");

    ui->lineEdit_7->setText("rv13.dat");
    ui->lineEdit_10->setText("cab_");
    ui->lineEdit_11->setText(".dat");
    ui->lineEdit_6->setText("Ham_sin_rv_t.txt");
    ui->lineEdit_9->setText("times_rv13.dat");

    QFont legendFont = font();
    legendFont.setPointSize(16);
    ui->customPlot->axisRect()->setupFullAxesBox(true);
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setLabel("Velocity [km/s]");
    ui->customPlot->xAxis->setLabel("HJD");

    string sbin = "BinaryData.dat";
    ifstream binaries(sbin.c_str());

    QFile qBin(sbin.c_str());

    if(!qBin.exists()){
        qDebug()<<"No data base file for orbits of binaries present.";
        QMessageBox::information(this, "Error", "Data base of orbital elements not present.");
    }


    else{
        int lines=0;
        string zeile1, eins1, zwei1, drei1, vier1, fuenf1, sechs1, sieben1, acht1;

        while(std::getline(binaries, zeile1))
        ++ lines;

        binaries.clear();
        binaries.seekg(0, ios::beg);

        QVector<string> names(lines);

        PER.resize(lines);
        ECC.resize(lines);
        AMPA.resize(lines);
        AMPB.resize(lines);
        GAM.resize(lines);
        PERI.resize(lines);
        LPERI.resize(lines);

        for(int i=0; i < lines; i++){
            binaries >> eins1 >> zwei1 >> drei1 >> vier1 >> fuenf1 >> sechs1 >> sieben1 >> acht1;
            istringstream str1(eins1);
            str1 >> names[i];
            QString qstr = QString::fromStdString(str1.str());
            ui->comboBox->addItem(qstr);
            istringstream str2(zwei1);
            str2 >> PER[i];
            istringstream str3(drei1);
            str3 >> ECC[i];
            istringstream str4(vier1);
            str4 >> AMPA[i];
            istringstream str5(fuenf1);
            str5 >> AMPB[i];
            istringstream str6(sechs1);
            str6 >> GAM[i];
            istringstream str7(sieben1);
            str7 >> PERI[i];
            istringstream str8(acht1);
            str8 >> LPERI[i];
        }

        ui->doubleSpinBox->setValue(PER[0]);
        ui->doubleSpinBox_8->setValue(ECC[0]);
        ui->doubleSpinBox_4->setValue(AMPA[0]);
        ui->doubleSpinBox_5->setValue(AMPB[0]);
        ui->doubleSpinBox_3->setValue(GAM[0]);
        ui->doubleSpinBox_2->setValue(PERI[0]);
        ui->doubleSpinBox_6->setValue(LPERI[0]);

        connect(ui->customPlot, SIGNAL(mouseMove(QMouseEvent*)), this ,SLOT(showPointToolTip(QMouseEvent*)));
    }
}

RVCalc::~RVCalc()
{
    delete ui;
}

void RVCalc::seData(QString str1, QString str2)
{
    ui->lineEdit_2->setText(str1);
    qRvPath=ui->lineEdit_2->text();
    rvPath = qRvPath.toUtf8().constData();

    ui->lineEdit_11->setText(str2);

}

//********************************************************
//show mouse coordinates
//********************************************************
void RVCalc::showPointToolTip(QMouseEvent *event)
{

    double xc = ui->customPlot->xAxis->pixelToCoord(event->pos().x());
    double yc = ui->customPlot->yAxis->pixelToCoord(event->pos().y());

    setToolTip(QString("%1 , %2").arg(xc).arg(yc));
}

double ofunction (double X[], double RVCt, double RVCT0, double RVCP, double RVCe){
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


//******************************************
// "Show" button to plot orbit and data
//******************************************
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
    int steps, help;
    if(ui->checkBox_2->isChecked()){
        steps = 100;
    }
    else{
        steps=(t2-t1)/dt;
    }
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
        if(ui->checkBox_2->isChecked()){
            cout<<t[m]<<"\t";
            t[m]=t[m]-RVCT0;
            cout<<t[m]<<"\t";
            help = t[m]/RVCP;
            cout<<help<<"\t";
            t[m] = (t[m]-help*RVCP)/RVCP;
            cout<<t[m]<<endl;
        }
        else{
            t[m]=t[m]-ui->doubleSpinBox_14->value();
        }
    }

    QPen pen;
    pen.setWidth(ui->spinBox_5->value());
    pen.setColor(Qt::red);
    QPen pen4;
    pen4.setWidth(ui->spinBox_5->value());
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

        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File "+qRvPath+"/"+plot1+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }
        ifstream toplot1(datName.c_str());

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
            if(ui->checkBox_2->isChecked()){
                at[i] = at[i]-RVCT0;
                help = at[i]/RVCP;
                at[i] = (at[i]-help*RVCP)/RVCP;
            }
            else{
                at[i]=at[i]-ui->doubleSpinBox_14->value();
            }
            cout<<"at: "<<at[i]<<endl;

            if(i==0){
                at1=at[0];
            }
       /*   if(ui->checkBox_2->isChecked()){

                if(at[i]-at1>=RVCP){
                    for(int e=0; e<a; e++){
                        at[i]=at[i]-RVCP;
                        if(at[i]<at1){
                            at[i]=at[i]+RVCP;
                            e=a;
                        }
                    }
                }

            }*/

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
        pen2.setWidth(ui->spinBox_5->value()+1);
        pen2.setColor(Qt::green);
        QPen pen3;
        pen3.setWidth(ui->spinBox_5->value()+1);
        pen3.setColor(Qt::black);
        double yr1 = ui->doubleSpinBox_7->value();
        double yr2 = ui->doubleSpinBox_16->value();
        int thc = 2*ui->spinBox_5->value();

        ui->customPlot->addGraph();
        ui->customPlot->graph(2)->setData(at, bt);
        ui->customPlot->graph(2)->setPen(pen2);
        ui->customPlot->graph(2)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, thc));
        ui->customPlot->graph(2)->rescaleAxes(true);
        ui->customPlot->addGraph();
        ui->customPlot->graph(3)->setData(at, ct);
        ui->customPlot->graph(3)->setPen(pen3);
        ui->customPlot->graph(3)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(3)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, thc));
        ui->customPlot->graph(3)->rescaleAxes(true);
        if(ui->checkBox_10->isChecked()){
            ui->customPlot->yAxis->setRange(yr1, yr2);
        }
        if(ui->checkBox_2->isChecked()){
            ui->customPlot->xAxis->setRange(-0.1, 1.1);
        }

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
    int dey=ui->comboBox->currentIndex();
    ui->doubleSpinBox->setValue(PER[dey]);
    ui->doubleSpinBox_8->setValue(ECC[dey]);
    ui->doubleSpinBox_4->setValue(AMPA[dey]);
    ui->doubleSpinBox_5->setValue(AMPB[dey]);
    ui->doubleSpinBox_3->setValue(GAM[dey]);
    ui->doubleSpinBox_2->setValue(PERI[dey]);
    ui->doubleSpinBox_6->setValue(LPERI[dey]);

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

    QFile checkfile(datName.c_str());

    if(!checkfile.exists()){
        qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+qRvPath+"/"+plot1+" does not exist!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    ifstream toplot1(datName.c_str());

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

    double RVA, RVB, residuumA=0, residuumB=0;

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

    double Estart=2*M_PI*(RVCt-RVCT0)/RVCP-2*RVCe;
    double RE=2*M_PI*(RVCt-RVCT0)/RVCP+RVCe*sin(Estart);
    double diff=abs(Estart-RE);
    int fcount=0;

    while(diff>10e-12){
        Estart=(Estart+RE)/2;
        RE=2*M_PI*(RVCt-RVCT0)/RVCP+RVCe*sin(Estart);
        diff=abs(Estart-RE);
        ++fcount;
        if(fcount>200){
            diff=0.0;
        }
    }

    RVCE=RE;

}

//************************************
//average of independent spectra
//************************************
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

    QFile checkfile(datName.c_str());

    if(!checkfile.exists()){
        qDebug()<<"Error1: The file "<<checkfile.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+qRvPath+"/"+plot1+" does not exist!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    ifstream toplot1(datName.c_str());

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

                QFile checkfile2(datName.c_str());

                if(!checkfile2.exists()){
                    qDebug()<<"Error1: The file "<<checkfile2.fileName()<<" does not exist.";
                    QMessageBox::information(this, "Error", "File "+checkfile2.fileName()+" does not exist!");
                    this->setCursor(QCursor(Qt::ArrowCursor));
                    return;
                }
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
                if(abs(bt[i]-bt[n])<=reso or (abs(at[i]-at[n])<=reso)){
                    if(count==0){
                        count=1;
                        nind = n;
                        if(abs(bt[i]-bt[n])<=reso){
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

                QFile checkfile1(dat1Name.c_str());

                if(!checkfile1.exists()){
                    qDebug()<<"Error2: The file "<<checkfile1.fileName()<<" does not exist.";
                    QMessageBox::information(this, "Error", "File "+qRvPath+"/"+aver+" does not exist!");
                    this->setCursor(QCursor(Qt::ArrowCursor));
                    return;
                }
                ifstream out1(dat1Name.c_str());

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

                QFile checkfile2(dat2Name.c_str());

                if(!checkfile2.exists()){
                    qDebug()<<"Error3: The file "<<checkfile2.fileName()<<" does not exist.";
                    QMessageBox::information(this, "Error", "File "+qRvPath+"/"+aver+" does not exist!");
                    this->setCursor(QCursor(Qt::ArrowCursor));
                    return;
                }
                ifstream out2(dat2Name.c_str());

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
                else {
                    //
                }


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
                        out3<<setprecision(14)<<W1[q]<<"\t"<<I1[q]<<endl;
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

            QFile checkfile(datName.c_str());

            if(!checkfile.exists()){
                QMessageBox::information(this, "Error", "The file "+checkfile.fileName()+" does not exist.");
                return;
            }

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
                out<<setprecision(14)<<WW[i]<<"\t"<<II[i]<<endl;
            }
            cout<<bt[e]<<"\t"<<at[e]<<endl;
        }
    }

    }

    // all at once
    if(ui->checkBox_7->isChecked()){

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
                }
            }
            //cout<<count<<"\t"<<count2<<"\t";

            for(int n=0; n<bt.size(); n++){
                count = 0;
                if((abs(current1-bt[n])<=reso) & (abs(current2-at[n])<=reso) & (count3==0)){

                    for(int e =0; e<count2; e++){
                        if((n!=rese[e]) & (i!=n)){
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
                    QFile checkfile1(datName.c_str());

                    if(!checkfile1.exists()){
                        qDebug()<<"Error2: The file "<<checkfile1.fileName()<<" does not exist.";
                        QMessageBox::information(this, "Error", "File "+qRvPath+"/"+aver+" does not exist!");
                        this->setCursor(QCursor(Qt::ArrowCursor));
                        return;
                    }
                    ifstream in(datName.c_str());

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

                    QFile checkfile1(datName.c_str());

                    if(!checkfile1.exists()){
                        qDebug()<<"Error2: The file "<<checkfile1.fileName()<<" does not exist.";
                        QMessageBox::information(this, "Error", "File "+qRvPath+"/"+aver+" does not exist!");
                        this->setCursor(QCursor(Qt::ArrowCursor));
                       return;
                    }
                    ifstream in(datName.c_str());

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
                out<<setprecision(14)<<W1[l]<<"\t"<<I1[l]/ndiv<<endl;
            }
        }
        }
    }

    // single files
    if(ui->checkBox_9->isChecked()){

        std::ostringstream datNameStream(aver1);
        datNameStream<<rvPath<<"/"<<aver1<<"rv"<<fExten;
        std::string datName = datNameStream.str();
        ofstream rvout(datName.c_str());

        for(int i =0; i<lines; i++){

            if(abs(at[count]-at[i])>=reso or (i ==0)){

                rvout<<setprecision(16)<<otim[i]<<"\t"<<bt[i]<<" \t"<<at[i]<<endl;

                if(ui->checkBox_5->isChecked()){

                    std::ostringstream datNameStream(aver1);
                    datNameStream<<rvPath<<"/"<<aver1<<i<<fExten;
                    std::string datName = datNameStream.str();

                    QFile checkfile1(datName.c_str());

                    if(!checkfile1.exists()){
                        qDebug()<<"Error2: The file "<<checkfile1.fileName()<<" does not exist.";
                        QMessageBox::information(this, "Error", "File "+qRvPath+"/"+aver+" does not exist!");
                        this->setCursor(QCursor(Qt::ArrowCursor));
                       return;
                    }
                    ifstream in(datName.c_str());

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

                    std::ostringstream dat2NameStream(aver1);
                    dat2NameStream<<rvPath<<"/"<<aver1<<"sin_"<<count2<<fExten;
                    std::string dat2Name = dat2NameStream.str();
                    ofstream out(dat2Name.c_str());

                    for(int l = 0; l<lines1; l++){
                        out<<setprecision(14)<<W1[l]<<"\t"<<I1[l]<<endl;
                    }
                    lines1=0;

                }
                ++count2;
                count=i;
                cout<<"spectra "<<i<<endl;
            }
            else {

            }
        }

        ui->spinBox_2->setValue(count2+1);

    }

    this->setCursor(QCursor(Qt::ArrowCursor));

}

void RVCalc::on_checkBox_6_clicked()
{
    if(ui->checkBox_6->isChecked()){
        ui->checkBox_7->setChecked(false);
        ui->checkBox_9->setChecked(false);
    }
    else{
        ui->checkBox_7->setChecked(true);
        ui->checkBox_9->setChecked(false);
    }
}

void RVCalc::on_checkBox_7_clicked()
{
    if(ui->checkBox_7->isChecked()){
        ui->checkBox_6->setChecked(false);
        ui->checkBox_9->setChecked(false);
    }
    else{
        ui->checkBox_6->setChecked(true);
        ui->checkBox_9->setChecked(false);
    }
}

void RVCalc::on_checkBox_9_clicked()
{
    if(ui->checkBox_9->isChecked()){
        ui->checkBox_7->setChecked(false);
        ui->checkBox_6->setChecked(false);
    }
    else{
        ui->checkBox_6->setChecked(true);
        ui->checkBox_7->setChecked(false);
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

        QFile checkfile2(dat2Name.c_str());

        if(!checkfile2.exists()){
            qDebug()<<"Error3: The file "<<checkfile2.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File "+qRvPath+"/"+qrvf+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        ifstream inf(dat2Name.c_str());

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

    string logf = "log_removed.dat";
    std::ostringstream dat4NameStream(logf);
    dat4NameStream<<rvPath<<"/"<<logf;
    std::string dat4Name = dat4NameStream.str();

    QString qlogf = qRvPath+"/log_removed.dat";
    QFileInfo QLFile(qlogf);
    ofstream LogFile;

    if(QLFile.exists()){
        LogFile.open(dat4Name.c_str(), std::ios_base::app);
        LogFile<<rn<<endl;
    }
    else{
        LogFile.open(dat4Name.c_str());
        LogFile<<rn<<endl;
    }

    this->setCursor(QCursor(Qt::ArrowCursor));


}


//******************************
// Test button
//******************************
void RVCalc::on_pushButton_9_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));

    int linesA=0, linesB=0;
    string one, two, three, zeile;

    string inA = ui->lineEdit_6->text().toUtf8().constData();
    string inB = ui->lineEdit_9->text().toUtf8().constData();

    string outA = ui->lineEdit_7->text().toUtf8().constData();
    ostringstream dat3NameStream(outA);
    dat3NameStream<<rvPath<<"/"<<outA;
    std::string dat3Name = dat3NameStream.str();
    ofstream ouA(dat3Name.c_str());

    std::ostringstream dat1NameStream(inA);
    dat1NameStream<<rvPath<<"/"<<inA;
    std::string dat1Name = dat1NameStream.str();

    QFile checkfile1(dat1Name.c_str());

    if(!checkfile1.exists()){
        qDebug()<<"Error3: The file "<<checkfile1.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+qRvPath+"/"+ui->lineEdit_6->text()+" does not exist!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    ifstream in1(dat1Name.c_str());

    while(std::getline(in1, zeile))
       ++ linesA;

    in1.clear();
    in1.seekg(0, ios::beg);

    QVector<double> timA(linesA), rvA(linesA), rvB(linesA);

    std::ostringstream dat2NameStream(inB);
    dat2NameStream<<rvPath<<"/"<<inB;
    std::string dat2Name = dat2NameStream.str();

    QFile checkfile2(dat2Name.c_str());

    if(!checkfile2.exists()){
        qDebug()<<"Error3: The file "<<checkfile2.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+qRvPath+"/"+ui->lineEdit_9->text()+" does not exist!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    ifstream in2(dat2Name.c_str());

    while(std::getline(in2, zeile))
       ++ linesB;

    in2.clear();
    in2.seekg(0, ios::beg);

    QVector<double> timB(linesB);


    for(int i = 1; i<linesA; i++){
        in1 >> one >> two >> three;
        istringstream ist1(one);
        ist1 >> timA[i];
        istringstream ist2(two);
        ist2 >>rvA[i];
        istringstream ist3(three);
        ist3 >>rvB[i];
    }
    in1.close();

    for(int i=0; i<linesB; i++){
        in2 >> one >> two >> three;
        istringstream str(one);
        str >> timB[i];
    }
    in2.close();

    int pos=0;
    double diff=0.0;
    RVCP=ui->doubleSpinBox->value();
    RVCT0=ui->doubleSpinBox_2->value();
    double gamma=ui->doubleSpinBox_3->value();
    double KA=ui->doubleSpinBox_4->value();
    double KB=ui->doubleSpinBox_5->value();
    double WA=ui->doubleSpinBox_6->value()/180*M_PI;
    double WB=WA+M_PI;
    RVCe=ui->doubleSpinBox_8->value();
    double RVA1=0.0, RVB1=0.0, theta=0.0, E=0.0, RVA2=0.0, RVB2=0.0;

    for(int i=0; i<linesB; i++){
        for(int e=0; e<linesA; e++){
            if(e==0){
                diff=abs(timB[i]-timA[e]);
            }
            else{
                    if(abs(timB[i]-timA[e])<diff){
                        diff=abs(timB[i]-timA[e]);
                        pos=e;
                    }
                    else{

                    }
            }

        }
        if(timB[i]!=timA[pos]){

            RVCt=timA[pos];
            RVCalc::findroot();
            E=RVCE;
            theta=2*(atan(tan(E/2)*sqrt((1+RVCe)/(1-RVCe))));

            RVA2 = gamma + KA*(cos(theta+WA)+RVCe*cos(WA));
            RVB2 = gamma + KB*(cos(theta+WB)+RVCe*cos(WB));

            RVCt=timB[i];
            RVCalc::findroot();
            E=RVCE;
            theta=2*(atan(tan(E/2)*sqrt((1+RVCe)/(1-RVCe))));

            RVA1 = gamma + KA*(cos(theta+WA)+RVCe*cos(WA));
            RVB1 = gamma + KB*(cos(theta+WB)+RVCe*cos(WB));
        }
        else{
            RVA1=0.0;
            RVB1=0.0;
            RVA2=0.0;
            RVB2=0.0;
        }

        ouA<<setprecision(14)<<timB[i]<<"\t"<<rvA[pos]-(RVA2-RVA1)<<"\t"<<rvB[pos]-(RVB2-RVB1)<<endl;

    }
    ouA.close();


    this->setCursor(QCursor(Qt::ArrowCursor));

}

//*********************************
// reject files from a list
//*********************************
void RVCalc::on_pushButton_10_clicked()
{
    QString qinA = ui->lineEdit_12->text();
    string inA = qinA.toUtf8().constData();
    std::ostringstream dat1NameStream(inA);
    dat1NameStream<<rvPath<<"/"<<inA;
    std::string dat1Name = dat1NameStream.str();

    QFile checkfile(dat1Name.c_str());

    if(!checkfile.exists()){
        qDebug()<<"Error3: The file "<<checkfile.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+qRvPath+"/"+qinA+" does not exist!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    ifstream in1(dat1Name.c_str());

    int linesn=0, numb=0;
    string eins, zeile;

    while(std::getline(in1, zeile))
       ++ linesn;

    in1.clear();
    in1.seekg(0, ios::beg);

    for(int i =0; i<linesn; i++){
        in1 >> eins;
        istringstream istr1(eins);
        istr1 >> numb;
        ui->spinBox_3->setValue(numb);
        RVCalc::on_pushButton_8_clicked();
    }
}

//******************************
// merge RV files from croco
//******************************
void RVCalc::on_pushButton_11_clicked()
{
    int fmin=ui->spinBox_6->value();
    int fmax=ui->spinBox_7->value();
    QString qinA = ui->lineEdit_13->text();
    string inA = qinA.toUtf8().constData();
    QString qExt = ui->lineEdit_14->text();
    string ext = qExt.toUtf8().constData();
    std::ostringstream dat1NameStream(inA);
    QString fnum;
    string eins, zwei, zeile;

    QVector<double> vela(fmax-fmin+1), velb(fmax-fmin+1);

    for(int i=fmin; i<=fmax;i++){

        fnum = QString::number(i);
        dat1NameStream<<rvPath<<"/"<<inA<<i<<ext;
        std::string dat1Name = dat1NameStream.str();

        QFile checkfile(dat1Name.c_str());

        if(!checkfile.exists()){
            qDebug()<<"Error3: The file "<<checkfile.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File "+qRvPath+"/"+qinA+fnum+qExt+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }

        ifstream in1(dat1Name.c_str());

        for(int e =0; e<1; e++){
            in1 >> eins >> zwei;
            istringstream istr1(eins);
            istr1 >> vela[i];
            istringstream istr2(zwei);
            istr2>> velb[i];
        }
        in1.close();
    }

    string outA = "mergedRVs.dat";
    ostringstream dat3NameStream(outA);
    dat3NameStream<<rvPath<<"/"<<outA;
    std::string dat3Name = dat3NameStream.str();
    ofstream ouA(dat3Name.c_str());

    for(int i =0; i<vela.size(); i++){
        ouA<<setprecision(10)<<vela[i]<<"\t"<<velb[i]<<endl;
    }
}
