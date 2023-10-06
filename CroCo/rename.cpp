#include "rename.h"
#include "ui_rename.h"
#include <dirent.h>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <CCfits/CCfits>

using namespace std;

int tabRC;

Rename::Rename(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rename)
{
    ui->setupUi(this);

    this->setWindowTitle("Renumerate & Rename Files");

    ui->lineEdit->setText("/home/daniels/Observations/Capella/Set_13/spectra");
    ui->lineEdit_3->setText("dat");
    ui->lineEdit_4->setText("table.dat");

    ui->lineEdit_5->setText("DataVector");
    ui->lineEdit_6->setText("Arg");
    ui->lineEdit_7->setText("Fun");

    ui->comboBox->addItem("ASCII");
    ui->comboBox->addItem("fits");

    ui->doubleSpinBox->setValue(3900);
    ui->doubleSpinBox_2->setValue(8500);
    ui->doubleSpinBox_3->setValue(0);
    ui->doubleSpinBox_4->setValue(1.5);

    ui->checkBox_2->setChecked(true);
    ui->checkBox_3->setChecked(true);

    ui->customPlot->axisRect()->setupFullAxesBox(true);
}

Rename::~Rename()
{
    delete ui;
}

void Rename::seData(QString str, QString str2, QString str3, QString str4, QString str5)
{
    ui->lineEdit->setText(str);
    ui->lineEdit_9->setText(str2);
    ui->lineEdit_5->setText(str3);
    ui->lineEdit_6->setText(str4);
    ui->lineEdit_7->setText(str5);
}

//**************************************
//List files
//**************************************
void Rename::on_pushButton_clicked()
{   
    QString direc=ui->lineEdit->text();
    string directory = direc.toUtf8().constData();

    QString qRExt = ui->lineEdit_3->text();
    string rExt = qRExt.toUtf8().constData();

    DIR *pdir = NULL;
    struct dirent *pent = NULL;
    const char * DIRECTORY;

    // convert directory string to const char
    DIRECTORY = directory.c_str();

    pdir = opendir (DIRECTORY);

    int i = 0, e=0;
    QString name=ui->lineEdit_2->text();

    std::string oldname, newname, nename;
    nename = name.toUtf8().constData();

    const char * OLDNAME, * NEWNAME;

    while(pent=readdir(pdir))
    {
        if(ui->checkBox->isChecked()){

            if((i!=ui->spinBox_2->value()-1) & (i!=ui->spinBox_3->value()-1) & (i!=ui->spinBox_4->value()-1)){

                // convert int i to str s
                string s = to_string(e);

                oldname = (std::string(DIRECTORY)+pent->d_name).c_str();

                OLDNAME = oldname.c_str();
                QString qold = QString::fromStdString(pent->d_name);

                ui->tableWidget->setItem(e, 0, new QTableWidgetItem(qold));
                e+=1;
            }
        }

        else{

            // convert int i to str s
            string s = to_string(e);

            oldname = (std::string(DIRECTORY)+pent->d_name).c_str();

            OLDNAME = oldname.c_str();
            QString qold = QString::fromStdString(pent->d_name);

            ui->tableWidget->setItem(e, 0, new QTableWidgetItem(qold));
            e+=1;

        }
        i+=1;
    }

    ui->tableWidget->sortItems(0, Qt::AscendingOrder);
    int start=ui->spinBox_11->value();
    int counter=0;

    for(int l =start; l<e; l++){
        QString qi = QString::number(counter);
        QString qNew = ui->lineEdit_2->text()+qi+"."+qRExt;
        ui->tableWidget->setItem(l, 1, new QTableWidgetItem(qNew));
        ++counter;
    }
}

void Rename::on_spinBox_valueChanged()
{
    tabRC=ui->spinBox->value();
    ui->tableWidget->setRowCount(tabRC);
}

//**********************************
// Rename files
//**********************************
void Rename::on_pushButton_2_clicked()
{
    int nfiles = ui->spinBox->value();

    QString qRPath=ui->lineEdit->text();
    QString qOld, qNew;
    QString qTab=ui->lineEdit_4->text();
    string Tab = qTab.toUtf8().constData();
    string rPath = qRPath.toUtf8().constData();
    QTableWidgetItem *qTOld, *qTNew;
    string Old, New;
    const char *OLD, *NEW;

    ostringstream dat3NameStream(Tab);
    dat3NameStream<<rPath<<"/"<<Tab;
    std::string dat3Name = dat3NameStream.str();
    ofstream outp(dat3Name.c_str());
    outp<<"Old \t New"<<endl;

    for(int i=0; i<nfiles; i++){
        qTOld = ui->tableWidget->item(i,0);
        qOld = qTOld->text();
        qTNew = ui->tableWidget->item(i,1);
        qNew = qTNew->text();

        string Oldstr = qOld.toUtf8().constData();
        ostringstream datNameStream(Oldstr);
        datNameStream<<rPath<<"/"<<Oldstr;
        Old = datNameStream.str();
        OLD = Old.c_str();

        string Newstr = qNew.toUtf8().constData();
        ostringstream dat2NameStream(Newstr);
        dat2NameStream<<rPath<<"/"<<Newstr;
        New = dat2NameStream.str();
        NEW = New.c_str();

        outp<<Old<<"\t"<<New<<endl;

        if(ui->checkBox_2->isChecked()){
            const QString qfi1 = ui->lineEdit->text()+"/"+qOld;
            const QString qfi2 = ui->lineEdit->text()+"/"+qNew;
            QFile::copy(qfi1,qfi2);
        }
        else{
            rename(OLD,NEW);
        }
    }

}



void Rename::on_spinBox_5_valueChanged()
{
    this->setCursor(QCursor(Qt::WaitCursor));

    ui->customPlot->clearGraphs();
    int i = ui->spinBox_5->value()-1;

    if(i>ui->spinBox->value()-1){
        return;
    }

    QString qRPath=ui->lineEdit->text();
    string rPath = qRPath.toUtf8().constData();

    QVector<double> a(2), b(2);


    QTableWidgetItem *qtoplot;
    qtoplot= ui->tableWidget->item(i, 0);
    QString qplot = qtoplot->text();
    ui->lineEdit_8->setText(qplot);

    string toplot = qplot.toUtf8().constData();
    ostringstream dat4NameStream(toplot);
    dat4NameStream<<rPath<<"/"<<toplot;
    std::string dat4Name = dat4NameStream.str();

    QFile checkfile(dat4Name.c_str());

    if(!checkfile.exists()){
        qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+qRPath+"/"+qplot+" does not exist!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    ifstream plot(dat4Name.c_str());

    if(ui->comboBox->currentIndex()==0){

        string one, two, zeile;

        int number_of_lines =0;

        while(std::getline(plot, zeile))
           ++ number_of_lines;

        plot.clear();
        plot.seekg(0, ios::beg);

        a.resize(number_of_lines);
        b.resize(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
            plot >> one >>two;
            istringstream ist(one);
            ist >> a[i];
            istringstream ist2(two);
            ist2 >> b[i];
        }
        plot.close();
    }

    else if(ui->comboBox->currentIndex()==1){

        QString qspExtension, qspWavecol, qspIntenscol;
        string spExtension, spWavecol, spIntenscol;
        std::valarray<double> spwave;
        std::valarray<double> spintens;

        CCfits::FITS::setVerboseMode(true);

        try
        {
            qspExtension=ui->lineEdit_5->text();
            spExtension = qspExtension.toUtf8().constData();
            qspWavecol=ui->lineEdit_6->text();
            spWavecol = qspWavecol.toUtf8().constData();
            qspIntenscol=ui->lineEdit_7->text();
            spIntenscol = qspIntenscol.toUtf8().constData();

            //open file for reading
            shared_ptr<CCfits::FITS> input_file(new CCfits::FITS(dat4Name.c_str(),CCfits::Read,true));

            // Create pointer to extension
                CCfits::ExtHDU& datavector = input_file->extension(spExtension);

              // Read rows
              CCfits::Column& column = datavector.column(spWavecol);
              column.read(spwave, 1, column.rows());

              // Read rows
              CCfits::Column& column2 = datavector.column(spIntenscol);
              column2.read(spintens, 1, column2.rows());

              int bini=spwave.size();

              a.resize(bini);
              b.resize(bini);

              for(int i=0; i<bini; i++){
                b[i]=spintens[i];
                a[i]=spwave[i];
              }
        }
            catch (CCfits::FitsException&)

             {
              std::cerr << " Fits Exception Thrown by test function \n";
              }
           // return;

    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(a, b);
    ui->customPlot->xAxis->setRange(ui->doubleSpinBox->value(), ui->doubleSpinBox_2->value());
    ui->customPlot->yAxis->setRange(ui->doubleSpinBox_3->value(), ui->doubleSpinBox_4->value());
    ui->customPlot->replot();

    this->setCursor(QCursor(Qt::ArrowCursor));
}

//***********************************
// Renumerate
//***********************************
void Rename::on_pushButton_4_clicked()
{
    QString direc=ui->lineEdit->text();
    string directory = direc.toUtf8().constData();

    QString qRExt = ui->lineEdit_10->text();
    string rExt = qRExt.toUtf8().constData();

    QString qRFil = ui->lineEdit_9->text();
    string rFil = qRFil.toUtf8().constData();

    const char *OLD, *NEW;

    int minf = ui->spinBox_6->value();
    int maxf = ui->spinBox_7->value();
    int nstart = ui->spinBox_8->value();
    int qf;

    if(nstart>minf){
        for(int i = 0; i<maxf-minf+1; i++){

                 qf = maxf-i;
                 QString ila = QString::number(qf);
                 const QString qfi1 = direc+"/"+qRFil+ila+"."+qRExt;
                 qf = nstart+maxf-i-minf;
                 ila = QString::number(qf);
                 const QString qfi2 = direc+"/"+qRFil+ila+"."+qRExt;
                 QFile::rename(qfi1,qfi2);


        }
    }
    else{
        for(int i =0; i<maxf-minf+1; i++){

            qf = minf+i;
            QString ila = QString::number(qf);

                const QString qfi1 = direc+"/"+qRFil+ila+"."+qRExt;
                qf = nstart+i;
                ila = QString::number(qf);
                const QString qfi2 = direc+"/"+qRFil+ila+"."+qRExt;
                QFile::rename(qfi1,qfi2);

        }
    }
}

void Rename::on_checkBox_3_clicked()
{
    if(ui->checkBox_3->isChecked()){
        ui->checkBox_4->setChecked(false);
    }
    else{
        ui->checkBox_4->setChecked(true);
    }
}

void Rename::on_checkBox_4_clicked()
{
    if(ui->checkBox_4->isChecked()){
        ui->checkBox_3->setChecked(false);
    }
    else{
        ui->checkBox_3->setChecked(true);
    }
}

//*************************************
// combine sequence
//*************************************
void Rename::on_pushButton_5_clicked()
{
    QString direc=ui->lineEdit->text();

    QString qs1 = ui->lineEdit_11->text();
    QString qe1 = ui->lineEdit_13->text();

    QString qs2 = ui->lineEdit_12->text();
    QString qe2 = ui->lineEdit_14->text();

    QString qs = ui->lineEdit_15->text();
    QString qe = ui->lineEdit_16->text();

    QString snum, qiA, qiB, qo;

    int smin = ui->spinBox_9->value();
    int smax = ui->spinBox_10->value();

        for(int i =smin; i<smax+1; i++){

            snum = QString::number(i);
            qiA = direc+"/"+qs1+snum+"."+qe1;
            string iA = qiA.toUtf8().constData();
            ostringstream dat1NameStream(iA);
            dat1NameStream<<iA;
            std::string dat1Name = dat1NameStream.str();

            QFile checkfile(dat1Name.c_str());

            if(!checkfile.exists()){
                qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error", "File "+checkfile.fileName()+" does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }
            ifstream inA(dat1Name.c_str());

            qiB = direc+"/"+qs2+snum+"."+qe2;
            string iB = qiB.toUtf8().constData();
            ostringstream dat2NameStream(iB);
            dat2NameStream<<iB;
            std::string dat2Name = dat2NameStream.str();

            QFile checkfile2(dat2Name.c_str());

            if(!checkfile.exists()){
                qDebug()<<"The file "<<checkfile2.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error", "File "+checkfile2.fileName()+" does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }
            ifstream inB(dat2Name.c_str());

            string one, two, three, zeile;

            int nlinesA=0;
            int nlinesB=0;

            while(std::getline(inA, zeile))
               ++ nlinesA;

            inA.clear();
            inA.seekg(0, ios::beg);

            while(std::getline(inB, zeile))
               ++ nlinesB;

            inB.clear();
            inB.seekg(0, ios::beg);

            QVector<double> Aa(nlinesA), Ab(nlinesA), Ac(nlinesA);
            QVector<double> Ba(nlinesB), Bb(nlinesB), Bc(nlinesB);


            // two colmns
            if(ui->checkBox_3->isChecked()){

                for (int e=0; e<nlinesA; e++){
                    inA >> one >>two;
                    istringstream ist(one);
                    ist >> Aa[e];
                    istringstream ist2(two);
                    ist2 >> Ab[e];
                }
                inA.close();

                for (int e=0; e<nlinesB; e++){
                    inB >> one >>two;
                    istringstream ist3(one);
                    ist3 >> Ba[e];
                    istringstream ist4(two);
                    ist4 >> Bb[e];
                }
                inB.close();

                qo = direc+"/"+qs+snum+"."+qe;
                string out = qo.toUtf8().constData();
                ostringstream dat3NameStream(out);
                dat3NameStream<<out;
                std::string dat3Name = dat3NameStream.str();
                ofstream file(dat3Name.c_str());

                for(int e=0; e<nlinesA+nlinesB; e++){
                    if(e<nlinesA){
                        file<<Aa[e]<<"\t"<<Ab[e]<<endl;
                    }
                    else{
                        file<<Ba[e-nlinesA]<<"\t"<<Bb[e-nlinesA]<<endl;
                    }
                }
                file.close();
            }
            // three columns
            else{
                for (int e=0; e<nlinesA; e++){
                    inA >> one >>two>>three;
                    istringstream ist(one);
                    ist >> Aa[e];
                    istringstream ist2(two);
                    ist2 >> Ab[e];
                    istringstream ist3(three);
                    ist3 >> Ac[e];
                }
                inA.close();

                for (int e=0; e<nlinesB; e++){
                    inB >> one >>two>>three;
                    istringstream ist4(one);
                    ist4 >> Ba[e];
                    istringstream ist5(two);
                    ist5 >> Bb[e];
                    istringstream ist6(three);
                    ist6 >> Bc[e];
                }
                inB.close();

                qo = direc+"/"+qs+snum+"."+qe;
                string out = qo.toUtf8().constData();
                ostringstream dat3NameStream(out);
                dat3NameStream<<out;
                std::string dat3Name = dat3NameStream.str();
                ofstream file(dat3Name.c_str());

                for(int e=0; e<nlinesA+nlinesB; e++){
                    if(e<nlinesA){
                        file<<Aa[e]<<"\t"<<Ab[e]<<"\t"<<Ac[e]<<endl;
                    }
                    else{
                        file<<Ba[e-nlinesA]<<"\t"<<Bb[e-nlinesA]<<"\t"<<Bc[e-nlinesA]<<endl;
                    }
                }
                file.close();
            }
        }
}
