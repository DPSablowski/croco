#include "vald3.h"
#include "ui_vald3.h"
#include <string>
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include "QDir"
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <QLineEdit>
#include <QString>
#include <QVector>
#include <QFile>
#include <QMessageBox>
#define ARMA_64BIT_WORD
#include <armadillo>
#include <QFileDialog>
#include <QDebug>

using namespace  std;
using namespace arma;

QVector<double> valdw(1), excite(1), vmic(1), loggf(1), rad(1), stark(1), waals(1), factor(1), strength(1);
QVector<string> ion(1), rline(1);
double ageAt=0.0, ageBt =0.0, LAt=0.0, LBt = 0.0, TAt=0.0, TBt=0.0, resAB=0.0, resA=0.0, resB=0.0;
int nmesavar=1, eval=0, stopopt=0;

VALD3::VALD3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VALD3)
{
    ui->setupUi(this);
    this->setWindowTitle("VALD3 & MESA Tool");

    ui->lineEdit->setText("vald3.lin");
    ui->lineEdit_5->setText("newlist.lin");
    ui->lineEdit_12->setText("Sneden_2014_13C15N.l");

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"Line No."<<"Change");
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setRowCount(nmesavar);
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem("0.01"));

    ui->checkBox_7->setChecked(true);

    ui->checkBox_6->setEnabled(false);
    ui->checkBox_9->setEnabled(false);
    ui->lineEdit_17->setEnabled(false);
    ui->lineEdit_18->setEnabled(false);
    ui->lineEdit_19->setEnabled(false);
    ui->lineEdit_20->setEnabled(false);
    ui->lineEdit_22->setEnabled(false);
    ui->lineEdit_24->setEnabled(false);
    ui->lineEdit_26->setEnabled(false);

    ui->lineEdit_13->setText("/home/daniel/MESA/mesa-r11532/star/CapellaA");
    ui->lineEdit_23->setText("inlist_capella");
    ui->lineEdit_14->setText("/home/daniel/MESA/mesa-r11532/star/CapellaA/LOGS");

    ui->lineEdit_17->setText("/home/daniel/MESA/mesa-r11532/star/CapellaB");
    ui->lineEdit_18->setText("/home/daniel/MESA/mesa-r11532/star/CapellaB/LOGS");

    ui->lineEdit_24->setText("inlist_capella");

    ui->lineEdit_15->setText("1.89597");        //log L/Ls A
    ui->lineEdit_16->setText("3.69636");        //Log Teff A

    ui->lineEdit_19->setText("1.8615344");      // log L/Ls B
    ui->lineEdit_20->setText("3.75816");        // log Teff A

    ui->lineEdit_21->setText("0.019957212");    // + log L/Ls A
    ui->lineEdit_29->setText("0.019957212");    // - log L/Ls A

    ui->lineEdit_25->setText("0.0043437");      // + log Teff A
    ui->lineEdit_31->setText("0.0043437");      // - log Teff A

    ui->lineEdit_22->setText("0.020990138");    // + log L/Ls B
    ui->lineEdit_30->setText("0.020990138");    // - log L/Ls B

    ui->lineEdit_26->setText("0.00451856");     // + log Teff B
    ui->lineEdit_32->setText("0.00451856");     // + log Teff B

    ui->lineEdit_27->setText("/home/daniel/MESA/mesa-r11532/star/CapellaA/initialvalues.dat");
    ui->lineEdit_28->setText("/home/daniel/MESA/mesa-r11532/star/CapellaA/initialmat.dat");

}

VALD3::~VALD3()
{
    delete ui;
}

//********************************
// set work path from main window
//********************************
void VALD3::seData(QString str1)
{
    ui->lineEdit_2->setText(str1);
}

//***********************************
// create new list
//***********************************
void VALD3::on_pushButton_3_clicked()
{
    double lstrength = ui->lineEdit_3->text().toDouble();
    double ustrength = ui->lineEdit_4->text().toDouble();
    double lwave = ui->lineEdit_6->text().toDouble();
    double uwave = ui->lineEdit_7->text().toDouble();

        string repla, lines, line, weins, wzwei;

    // load comparison wavelengths
    double mgf = 0.0;     // log gf multiplicator
    string mele;  // element
    QVector<double> cowave(1), wpm(1);
    int wlines=0;
    if(ui->checkBox_3->isChecked()){

        mgf = ui->lineEdit_9->text().toDouble();     // log gf multiplicator
        mele = ui->lineEdit_8->text().toUtf8().constData();  // element

        string wfile = (ui->lineEdit_2->text()+"/"+ui->lineEdit_10->text()).toUtf8().constData();
        std::ostringstream datNameStream(wfile);
        datNameStream<<wfile;
        std::string datName = datNameStream.str();

        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            QMessageBox::information(this, "Error", "Error 1: File"+checkfile.fileName()+" does not exist!");
            //this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }
        ifstream wf(datName.c_str());

        while(std::getline(wf, lines))
           ++wlines;

        wf.clear();
        wf.seekg(0, ios::beg);

        cowave.resize(wlines);
        wpm.resize(wlines);

        for(int i =0; i<wlines; i++){
            wf >> weins >> wzwei;
            istringstream strw(weins);
            strw >> cowave[i];
            istringstream strr(wzwei);
            if(ui->checkBox_3->isChecked()){
                wpm[i]=ui->lineEdit_11->text().toDouble();
            }
            else{
                strr >> wpm[i];
            }
        }
        wf.close();
    }

    QString qfile = ui->lineEdit_2->text()+"/"+ui->lineEdit->text();
    string fvald3 = qfile.toUtf8().constData();

    std::ostringstream dat1NameStream(fvald3);
    dat1NameStream<<fvald3;
    std::string dat1Name = dat1NameStream.str();

    QFile checkfile1(dat1Name.c_str());

    if(!checkfile1.exists()){
        QMessageBox::information(this, "Error", "Error 1: File"+qfile+" does not exist!");
        //this->setCursor(QCursor(Qt::ArrowCursor));
        return;
    }
    ifstream vald3(dat1Name.c_str());

    int nlines=0;

    while(std::getline(vald3, lines))
       ++nlines;

    vald3.clear();
    vald3.seekg(0, ios::beg);

    QString qfile2 = ui->lineEdit_2->text()+"/linelist.temp";
    string file2 = qfile2.toUtf8().constData();

    std::ostringstream dat2NameStream(file2);
    dat2NameStream<<file2;
    std::string dat2Name = dat2NameStream.str();
    ofstream otemp(dat2Name.c_str());

    QString qfile3 = ui->lineEdit_2->text()+"/"+ui->lineEdit_5->text();
    string file3 = qfile3.toUtf8().constData();

    std::ostringstream dat3NameStream(file3);
    dat2NameStream<<file3;
    std::string dat3Name = dat3NameStream.str();
    ofstream olist(dat3Name.c_str());

    int count=0;

    while( std::getline( vald3, line ) ) {
        if(count<3){
            olist<<line<<endl;
            ++count;
        }
        else{
            //
        }
        replace(line.begin(), line.end(), ',', ' ');
        otemp<<line<<endl;
    }
    otemp.close();
    vald3.clear();
    vald3.seekg(0, ios::beg);
    count=0;


    string eins, zwei, drei, vier, fuenf, sechs, sieben, acht, neun, zehn, elf;

    ifstream temp(dat2Name.c_str());

    valdw.resize(nlines);
    ion.resize(nlines);
    excite.resize(nlines);
    vmic.resize(nlines);
    loggf.resize(nlines);
    rad.resize(nlines);
    stark.resize(nlines);
    waals.resize(nlines);
    factor.resize(nlines);
    strength.resize(nlines);
    rline.resize(nlines);
    string test;
    int llines=0;
    int nloggf=0;

    temp>> eins >> zwei >> drei;
    istringstream strl(drei);
    strl >> llines;
    cout<<"Number of spectral lines: "<<llines<<endl;

    for(int i=0; i < 3; ++i){
        temp.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        vald3.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }

    for(int i =0; i<nlines; i++){
        if(i<llines){
            temp >> eins >> elf >> zwei >> drei >> vier >> fuenf >> sechs >> sieben >> acht >> neun >> zehn;
            istringstream str1(eins);
            str1 >> ion[i];
            istringstream str(elf);
            str >> test;
            ion[i] = ion[i]+" "+test;
            istringstream str2(zwei);
            str2 >> valdw[i];
            istringstream str3(drei);
            str3 >> excite[i];
            istringstream str4(vier);
            str4 >> vmic[i];
            istringstream str5(fuenf);
            str5 >> loggf[i];
            if((ui->checkBox_3->isChecked()) & (ion[i] == mele)){
                for(int e=0; e<wlines; e++){
                    if((valdw[i]>=cowave[e]-wpm[e]) & (valdw[i]<=cowave[e]+wpm[e])){
                        loggf[i]=loggf[i]*mgf;
                        ++nloggf;
                        e=wlines;
                    }
                }
            }
            istringstream str6(sechs);
            str6 >> rad[i];
            istringstream str7(sieben);
            str7 >> stark[i];
            istringstream str8(acht);
            str8 >> waals[i];
            istringstream str9(neun);
            str9 >> factor[i];
            istringstream str10(zehn);
            str10 >> strength[i];
            //cout<<ion[i]<<"\t"<<valdw[i]<<"\t"<<excite[i]<<"\t"<<vmic[i]<<"\t"<<loggf[i]<<"\t"<<rad[i]<<"\t"<<stark[i]<<"\t"<<waals[i]<<"\t"<<factor[i]<<"\t"<<strength[i]<<endl;
            std::getline( temp, line );
            rline[i]=line;
            cout<<i<<"\t"<<rline[i]<<endl;
            //temp.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::getline( vald3, line );
            if(ui->checkBox->isChecked()){
                if((strength[i]>=lstrength) & (strength[i]<=ustrength)){
                    if(ui->checkBox_2->isChecked()){
                        if((valdw[i]>=lwave) & (valdw[i]<=uwave)){
                            //olist<<line<<endl;
                            olist<<ion[i]<<"\t"<<valdw[i]<<"\t"<<excite[i]<<"\t"<<vmic[i]<<"\t"<<loggf[i]<<"\t"<<rad[i]<<"\t"<<stark[i]<<"\t"<<waals[i]<<"\t"<<factor[i]<<"\t"<<strength[i]<<"\t"<<rline[i]<<endl;
                            ++count;
                        }
                        else{

                        }
                    }
                    else{
                        //olist<<line<<endl;
                        olist<<ion[i]<<"\t"<<valdw[i]<<"\t"<<excite[i]<<"\t"<<vmic[i]<<"\t"<<loggf[i]<<"\t"<<rad[i]<<"\t"<<stark[i]<<"\t"<<waals[i]<<"\t"<<factor[i]<<"\t"<<strength[i]<<"\t"<<rline[i]<<endl;
                        ++count;
                    }
                }
                else{

                }
            }
            else{
                if(ui->checkBox_2->isChecked()){
                    if((valdw[i]>=lwave) & (valdw[i]<=uwave)){
                        //olist<<line<<endl;
                        olist<<ion[i]<<"\t"<<valdw[i]<<"\t"<<excite[i]<<"\t"<<vmic[i]<<"\t"<<loggf[i]<<"\t"<<rad[i]<<"\t"<<stark[i]<<"\t"<<waals[i]<<"\t"<<factor[i]<<"\t"<<strength[i]<<"\t"<<rline[i]<<endl;
                        ++count;
                    }
                    else{

                    }
                }
                else{
                    //olist<<line<<endl;
                    olist<<ion[i]<<"\t"<<valdw[i]<<"\t"<<excite[i]<<"\t"<<vmic[i]<<"\t"<<loggf[i]<<"\t"<<rad[i]<<"\t"<<stark[i]<<"\t"<<waals[i]<<"\t"<<factor[i]<<"\t"<<strength[i]<<"\t"<<rline[i]<<endl;
                    ++count;
                }
            }
        }
        else{
            std::getline( vald3, line );
            olist<<line<<endl;
        }

    }

    QMessageBox::information(this, "Note", QString::number(count)+" lines written to new file. You might need to exchange third number in first line (number of spectral lines in list) by this number.\n"
                                                                  +QString::number(nloggf)+" log(gf) values have been multiplied.");

}

//************************************
// qick help
//************************************
void VALD3::on_pushButton_2_clicked()
{
    QMessageBox::information(this, "Help", "This helps you to create shorter line lists as obtained by VALD3.\n"
                                           "You can spedify the depth of lines and the overall wavelength range.\n"
                                           "Lines which fullfil these criteria are written into a new file.");
}

//*****************************************
// Sneden list wavenumbers to wavelength
//*****************************************
void VALD3::on_pushButton_4_clicked()
{
    string slist = (ui->lineEdit_2->text()+"/"+ui->lineEdit_12->text()).toUtf8().constData();
    std::ostringstream datNameStream(slist);
    datNameStream<<slist;
    std::string datName = datNameStream.str();

    QFile checkfile(datName.c_str());

    if(!checkfile.exists()){
        QMessageBox::information(this, "Error", "Error 1: File"+checkfile.fileName()+" does not exist!");
        //this->setCursor(QCursor(Qt::ArrowCursor));
        return;
    }
    ifstream waven(datName.c_str());

    int nwaves=0;
    string lines, one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen;
    double output;

    while(std::getline(waven, lines))
       ++nwaves;

    waven.clear();
    waven.seekg(0, ios::beg);

    string wlist = (ui->lineEdit_2->text()+"/wavelengths.dat").toUtf8().constData();
    std::ostringstream dat2NameStream(wlist);
    dat2NameStream<<wlist;
    std::string dat2Name = dat2NameStream.str();
    ofstream out(dat2Name.c_str());

    for(int i =0; i<nwaves; i++){
       waven >> one >> two >> three >> four >> five >> six >> seven >> eight >> nine >> ten >> eleven >> twelve >> thirteen;
       istringstream str(twelve);
       istringstream str1(thirteen);
       str >> output;
       //output = 10000000/output;
       out << output<<endl;
       waven.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    out.close();
    waven.close();
}

//**********************************
// Go MESA
//**********************************
void VALD3::on_pushButton_5_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));
    int Ph=0, Pl=0, Psh=0;
    eval=0;

    int zaehler=ui->spinBox_2->value(), subta=0;
    double yh, ysh, yl, ym, yi, ys, yt;
    QVector<int> zeile(ui->spinBox->value());

    int nu=0, nA=0, nB=0;
    int nzeilen = ui->spinBox->value();
    QVector<string> keywordA(nzeilen), keywordB(nzeilen);

    if(ui->checkBox_5->isChecked()){
        cout<<"binary ";
        if(ui->checkBox_6->isChecked()){
            nu=ui->spinBox->value();
            cout<<" coupled ";
        }
        else{
            nu=2*ui->spinBox->value();
            cout<<" not coupled ";
            subta=nzeilen;
        }
    }
    else{
        nu=ui->spinBox->value();
    }
    cout<<"number of variables: "<<nu<<endl;
    QVector<double> vari(nu), change(nu);

    QTableWidgetItem *item;

    for(int i=0; i<nzeilen; i++){
        item = ui->tableWidget->item(i, 0);
        if (!item || item->text().isEmpty())
        {
           QMessageBox::information(this, "Error", "Error: No line no. defined at "+QString::number(i+1)+".");
           return;
        }
        else{
            zeile[i]=item->text().toInt();
        }
        item = ui->tableWidget->item(i, 1);
        if (!item || item->text().isEmpty())
        {
           QMessageBox::information(this, "Error", "Error: No line no. defined at "+QString::number(i+1)+".");
           return;
        }
        else{
            change[i]=item->text().toDouble();
        }
    }

    string inlA = (ui->lineEdit_13->text()+"/"+ui->lineEdit_23->text()).toUtf8().constData();
    std::ostringstream datNameStream(inlA);
    datNameStream<<inlA;
    std::string datName = datNameStream.str();

    QFile checkfile(datName.c_str());

    if(!checkfile.exists()){
        QMessageBox::information(this, "Error", "Error 1: File"+checkfile.fileName()+" does not exist!");
        //this->setCursor(QCursor(Qt::ArrowCursor));
        return;
    }

    string inlA2 = (ui->lineEdit_13->text()+"/"+ui->lineEdit_23->text()+"_initial").toUtf8().constData();
    std::ostringstream dat2NameStream(inlA2);
    dat2NameStream<<inlA2;
    std::string dat2Name = dat2NameStream.str();

    std::ifstream  srcA(datName.c_str());
    std::ofstream  dstA(dat2Name.c_str());

    dstA << srcA.rdbuf();

        dstA.close();
        srcA.clear();
        srcA.seekg(0, ios::beg);

        string eins, zwei, line;

        while(std::getline(srcA, line))
           ++nA;

        srcA.clear();
        srcA.seekg(0, ios::beg);

    for(int i=0; i<nzeilen; i++){
        for(int e =0; e<zeile[i]-1; e++){
            srcA.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        srcA >> eins >> zwei;
        istringstream str(eins);
        str >> keywordA[i];
        keywordB[i]=keywordA[i];
        istringstream str2(zwei);
        str2 >> vari[i];
        cout<<vari[i]<<endl;
        srcA.clear();
        srcA.seekg(0, ios::beg);
    }
    srcA.close();

    string inlB = (ui->lineEdit_17->text()+"/"+ui->lineEdit_24->text()).toUtf8().constData();
    std::ostringstream datNameBStream(inlB);
    datNameBStream<<inlB;
    std::string datBName = datNameBStream.str();

    string inlB2 = (ui->lineEdit_17->text()+"/"+ui->lineEdit_24->text()+"_initial").toUtf8().constData();
    std::ostringstream dat2NameBStream(inlB2);
    dat2NameBStream<<inlB2;
    std::string datB2Name = dat2NameBStream.str();

    if(ui->checkBox_5->isChecked()){

        QFile checkfile2(datBName.c_str());

        if(!checkfile2.exists()){
            QMessageBox::information(this, "Error", "Error 1: File"+checkfile2.fileName()+" does not exist!");
            //this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }

        std::ifstream  srcB(datBName.c_str());
        std::ofstream  dstB(datB2Name.c_str());

        dstB << srcB.rdbuf();
        dstB.close();

        // coupled
        if(ui->checkBox_6->isChecked()){
            srcB.clear();
            srcB.seekg(0, ios::beg);

            while(std::getline(srcB, line))
               ++nB;

            srcB.clear();
            srcB.seekg(0, ios::beg);
            srcB.close();
        }
        // not coupled
        else{
            srcB.clear();
            srcB.seekg(0, ios::beg);

            while(std::getline(srcB, line))
               ++nB;

            srcB.clear();
            srcB.seekg(0, ios::beg);

            for(int i=0; i<nzeilen; i++){
                for(int e =0; e<zeile[i]-1; e++){
                    srcB.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                }
                srcB >> eins >> zwei;
                istringstream str(eins);
                str >> keywordB[i];
                istringstream str2(zwei);
                str2 >> vari[i+nzeilen];
                change[i+nzeilen]=change[i];
                cout<<vari[i+nzeilen]<<endl;
                srcB.clear();
                srcB.seekg(0, ios::beg);
            }
            srcB.close();
        }
    }
    else{
        //
    }


    string outVal= (ui->lineEdit_13->text()+"/best_values.dat").toUtf8().constData();
    std::ostringstream dat3NameStream(outVal);
    dat3NameStream<<outVal;
    std::string dat3Name = dat3NameStream.str();
    ofstream out(outVal.c_str());

    // transformation coeff.
    double Gamma=2.0;
    double alpha=1.0;
    double beta=0.5;
    double btot=0.5;

    double y[nu+1], Z[nu], Co[nu], So[nu], Eo[nu];
    mat P(nu+1,nu), e(nu+1,nu);

    int count=0;

    out<<"Start optimisation on:"<<endl;

    // start from optimisation data
    if(ui->checkBox_10->isChecked()){
        out<<"initial data, load"<<endl;

        QString qOptval = ui->lineEdit_27->text();
        string file1opt = qOptval.toUtf8().constData();
        std::ostringstream file1NameStream(file1opt);
        file1NameStream<<file1opt;
        std::string file1Name = file1NameStream.str();

        QString qOptmat = ui->lineEdit_28->text();
        string file2opt = qOptmat.toUtf8().constData();
        std::ostringstream file2NameStream(file2opt);
        file2NameStream<<file2opt;
        std::string file2Name = file2NameStream.str();

        QFile checkfile1(file1Name.c_str());

        if(!checkfile1.exists()){
            QMessageBox::information(this, "Error", "File with optimsation data does not exist.");
            return;
        }

        QFile checkfile2(file2Name.c_str());

        if(!checkfile2.exists()){
            QMessageBox::information(this, "Error", "File with optimsation data does not exist.");
            return;
        }

        ifstream initiate1(file1Name.c_str());
        ifstream initiate2(file2Name.c_str());

        int number_of_lines =0;

        while(std::getline(initiate1, line))
           ++ number_of_lines;

        initiate1.clear();
        initiate1.seekg(0, ios::beg);

        if(number_of_lines!=nu+1){
            QMessageBox::information(this, "Error", "Optimisation file "+checkfile1.fileName()+" does not match to the number of specified variables.");
            return;
        }

        for (int i=0; i<number_of_lines; i++){
            initiate1 >> eins;
            istringstream ist(eins);
            ist >> y[i];
            if(i==0) resAB=y[0];
                if(y[i]<resAB){
                    resAB=y[i];
                }
            }
        initiate1.close();

        number_of_lines =0;

        while(std::getline(initiate2, line))
           ++number_of_lines;

        initiate2.clear();
        initiate2.seekg(0, ios::beg);
        int bin=1;

        if(number_of_lines!=(nu+1)*nu){
            QMessageBox::information(this, "Error", "Optimisation file "+checkfile2.fileName()+" does not match to the number of specified variables.");
            return;
        }

        int coun=0;

        for (int i=0; i<number_of_lines; i++){
            initiate2 >> eins;
            istringstream ist(eins);
            ist >> P(coun,i-coun*nu);
            cout<<"P["<<coun<<"]["<<i-coun*nu<<"]: "<<P(coun,i-coun*nu)<<" ";
            if(i==coun*nu+nu-1){
                cout<<endl;
                ++coun;
            }
        }
        initiate2.close();
        out<<"data loaded, continue with optimisation..."<<endl;

    }
    else{   // create initial data
    for(int i=0; i<nu; i++){
        P(0,i)=vari[i];
        if(i<nzeilen){
            out<<keywordA[i]<<"\t"<<P(0,i);
            if(ui->checkBox_6->isChecked()){
                out<<" of Comp. A and B."<<endl;
            }
            else{
                out<<" of Comp. A."<<endl;
            }
        }
        else{
            out<<keywordB[i-nzeilen]<<"\t"<<P(0,i)<<" of Comp. B."<<endl;
        }
    }

    for(int i=0; i<nu+1; i++){
        for(int j=0; j<nu; j++){
            if((i>0)&(i==j+1)){
                e(i,j)=change[i-1];
            }
            else{
                e(i,j)=0;
            }
        }
    }
    double resA1=0.0, resB1=0.0;

    for (int i=0; i<nu+1; i++){
        out<<"Simplex point "<<i<<": ";
        for (int j=0; j<nu; j++){
            P(i,j)=P(0,j)+P(0,j)*e(i,j);
            //init2<<setprecision(14)<<P(i,j)<<endl;
            out<<P(i,j)<<": ";
        }

        //--------------------------------------------------------
        // create new inlist and run MESA
        if(i<nzeilen+1){
            ifstream dstA(dat2Name.c_str());
            ofstream srcA(datName.c_str());
            for(int e=0; e<nA; e++){
                if(e==zeile[count]-1){
                    srcA<<keywordA[count]<<"\t"<<P(i,count)<<endl;
                    cout<<"file A: "<<i<<"\t"<<P(i,count)<<endl;
                    ++count;
                    dstA.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                }
                else{
                    std::getline(dstA, line);
                    srcA<<line<<endl;
                }
            }
            count=0;

            dstA.clear();
            dstA.seekg(0, ios::beg);
            dstA.close();
            srcA.close();

            QDir::setCurrent(ui->lineEdit_13->text());
            system("./rn");
            VALD3::computeMESAResiduumA();
        }
        else{
            resA=resA1;
        }
        // binary
        if(ui->checkBox_5->isChecked()){
            // coupled
            if(ui->checkBox_6->isChecked()){

                ofstream srcB(datBName.c_str());
                ifstream dstB(datB2Name.c_str());

                for(int e=0; e<nB; e++){
                    if(e==zeile[count]-1){
                        srcB<<keywordA[count]<<"\t"<<P(i,count)<<endl;
                        cout<<"file B: "<<i<<"\t"<<P(i,count)<<endl;
                        ++count;
                        dstB.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    }
                    else{
                        std::getline(dstB, line);
                        srcB<<line<<endl;
                    }
                }
                count=0;

                dstB.clear();
                dstB.seekg(0, ios::beg);
                dstB.close();
                srcB.close();

                if(resA<10e10){
                    QDir::setCurrent(ui->lineEdit_17->text());
                    system("./rn");
                    VALD3::computeMESAResiduumB();
                }
                else{
                    resB=10e10;
                }
            }
            // not coupled
            else{
                if((i==0) or (i>nzeilen)){
                    ifstream dstB(datB2Name.c_str());
                    ofstream srcB(datBName.c_str());
                    for(int e=0; e<nB; e++){
                        if(e==zeile[count]-1){
                            srcB<<keywordB[count]<<"\t"<<P(i,count+nzeilen)<<endl;
                            cout<<"file B: "<<i<<"\t"<<P(i,count+nzeilen)<<endl;
                            ++count;
                            dstB.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        }
                        else{
                            std::getline(dstB, line);
                            srcB<<line<<endl;
                        }
                    }
                    count=0;

                    dstB.clear();
                    dstB.seekg(0, ios::beg);

                    if(resA<10e10){
                        QDir::setCurrent(ui->lineEdit_17->text());
                        system("./rn");
                        VALD3::computeMESAResiduumB();
                    }
                    else{
                        resB=10e10;
                    }
                }
                else{
                    resB=resB1;
                }
            }
        }
        //--------------------------------------------------------
        y[i]=VALD3::MESAResiduum();
        out<<"resA: "<<resA<<"; resB: "<<resB<<"; ageA: "<<ageAt<<"; ageB: "<<ageBt<<"; RMS: "<<y[i]<<endl;
        qApp->processEvents(QEventLoop::AllEvents);
        if(i==0){
            resAB=y[i];
            resA1=resA;
            resB1=resB;
            out<<"resA1: "<<resA1<<"; resB1: "<<resB1<<endl;
        }
        else{
            if(y[i]<resAB){
                cout<<"Better parameters found: "<<endl;
                out<<"Better parameters found: "<<endl;
                for(int e=0; e<nu; e++){
                    resAB=y[i];
                    cout<<P(i,e)<<endl;
                    out<<P(i,e)<<endl;
                }
                out<<"Residuum: "<<resAB<<endl;
                out<<endl;
                if(ui->checkBox_5->isChecked()){
                    out<<"Component A: Age: "<<ageAt<<"; log(L/L): "<<LAt<<"; log(Teff): "<<TAt<<endl;
                    out<<"Component B: Age: "<<ageBt<<"; log(L/L): "<<LBt<<"; log(Teff): "<<TBt<<endl;
                }
                else{
                    out<<"Age: "<<ageAt<<"; log(L/L): "<<LAt<<"; log(Teff): "<<TAt<<endl;
                }
                if(ui->checkBox_7->isChecked()){
                    VALD3::saveTracks();
                    out<<"Tracks saved with index "<<eval<<endl;
                }
                else{
                    //
                }
            }
            else{

            }
        }
        ++eval;
        if(stopopt==1){
            stopopt=0;
            out<<endl;
            out<<"Simplex points:"<<endl;
            for(int j=0; j<nu+1; j++){
                for(int i=0; i<nu;i++){
                    cout<<P(j,i)<<"\t";
                    out<<setprecision(12)<<P(j,i)<<"\t";
                }
                out<<setprecision(12)<<"r: "<<y[j]<<endl;
            }
            out.close();
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }
        cout<<"Residuum: "<<y[i]<<endl;
    }
}

    // start optimization loop
    for (int t=0; t<zaehler; t++){
        ui->spinBox_3->setValue(t);
        //initialize next step
        ym=0;
        ys=0;
        for (int i=0; i<nu; i++){
            Z[i]=0;
        }

        //looking for highest value
        yh=y[0];
        Ph = 0;
        for (int j=0; j<nu+1; j++){
            if(y[j]>yh){
                yh = y[j];
                Ph = j;
            }
        }

        //looking for smallest value
        yl=yh;
        for (int j=0; j<nu+1; j++){
            if(y[j]<yl){
                yl=y[j];
                Pl = j;
            }
        }

        //looking for second highest value
        ysh=yl;
        for (int j=0; j<nu+1; j++){
            if((y[j]>ysh) & (y[j]<yh) & (y[j]>yl) & (j !=Pl)){
                ysh=y[j];
                Psh=j;
            }
        }

        yh=y[Ph];
        yl=y[Pl];
        ysh=y[Psh];

        //computing mean and sigma
        for (int i=0; i<nu+1; i++){
            ym+=y[i]/(nu+1);
        }
        for (int i=0; i<nu+1; i++){
            ys+=sqrt(pow((y[i]-ym),2));
        }
        ys=ys/(nu);

        cout<<"Iteration: "<<t<<"; Simplex Mean: "<<ym<<"; Simplex STD: "<<ys<<endl;
        out<<"Iteration: "<<t<<"; Simplex Mean: "<<ym<<"; Simplex STD: "<<ys<<endl;

        //compute centroid
        for (int j=0; j<nu; j++){
            for (int i=0; i<nu+1; i++){
                if (i!=Ph){
                    Z[j]+=P(i,j)/nu;
                }
            }
        }

        //reflect highest value at centroid
        cout<<"reflection at centroid..."<<endl;
        for (int i=0; i<nu; i++){
            Co[i]=Z[i]+alpha*(Z[i]-P(Ph,i));
        }
        //-----------------------------------------------------
        eval++;
        ifstream dstA(dat2Name.c_str());
        ofstream srcA(datName.c_str());
        for(int e=0; e<nA; e++){
            if(e==zeile[count]-1){
                srcA<<keywordA[count]<<"\t"<<Co[count]<<endl;
                cout<<"file A: "<<e<<"\t"<<Co[count]<<endl;
                ++count;
                dstA.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }
            else{
                std::getline(dstA, line);
                srcA<<line<<endl;
            }
        }
        count=0;

        dstA.clear();
        dstA.seekg(0, ios::beg);
        dstA.close();
        srcA.close();

        QDir::setCurrent(ui->lineEdit_13->text());
        system("./rn");
        VALD3::computeMESAResiduumA();
        // binary
        if(ui->checkBox_5->isChecked()){
            // coupled
            if(ui->checkBox_6->isChecked()){
                ifstream dstB(datB2Name.c_str());
                ofstream srcB(datBName.c_str());
                for(int e=0; e<nB; e++){
                    if(e==zeile[count]-1){
                        srcB<<keywordA[count]<<"\t"<<Co[count]<<endl;
                        cout<<"file B: "<<e<<"\t"<<Co[count]<<endl;
                        ++count;
                        dstB.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    }
                    else{
                        std::getline(dstB, line);
                        srcB<<line<<endl;
                    }
                }
                count=0;

                dstB.clear();
                dstB.seekg(0, ios::beg);
                dstB.close();
                srcB.close();

                if(resA<10e10){
                    QDir::setCurrent(ui->lineEdit_17->text());
                    system("./rn");
                    VALD3::computeMESAResiduumB();
                }
                else{
                    resB=10e10;
                }
            }
            // not coupled
            else{
                ifstream dstB(datB2Name.c_str());
                ofstream srcB(datBName.c_str());
                for(int e=0; e<nB; e++){
                    if(e==zeile[count]-1){
                        srcB<<keywordB[count]<<"\t"<<Co[count+nzeilen]<<endl;
                        cout<<"file B: "<<e<<"\t"<<Co[count+nzeilen]<<endl;
                        ++count;
                        dstB.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    }
                    else{
                        std::getline(dstB, line);
                        srcB<<line<<endl;
                    }
                }
                count=0;

                dstB.clear();
                dstB.seekg(0, ios::beg);

                if(resA<10e10){
                    QDir::setCurrent(ui->lineEdit_17->text());
                    system("./rn");
                    VALD3::computeMESAResiduumB();
                }
                else{
                    resB=10e10;
                }
            }
        }
        //--------------------------------------------------------
        yi=VALD3::MESAResiduum();
        if(yi<resAB){
            out<<"Better parameters found:"<<endl;
            resAB=yi;
            for(int i = 0; i<nu;i++){
                out<<Co[i]<<endl;
            }
            out<<"Residuum: "<<resAB<<"; resA: "<<resA<<"; resB: "<<resB<<endl;
            out<<endl;
            if(ui->checkBox_5->isChecked()){
                out<<"Component A: Age: "<<ageAt<<"; log(L/L): "<<LAt<<"; log(Teff): "<<TAt<<endl;
                out<<"Component B: Age: "<<ageBt<<"; log(L/L): "<<LBt<<"; log(Teff): "<<TBt<<endl;
            }
            else{
                out<<"Age: "<<ageAt<<"; log(L/L): "<<LAt<<"; log(Teff): "<<TAt<<endl;
            }
            if(ui->checkBox_7->isChecked()){
                VALD3::saveTracks();
                out<<"Tracks saved with index "<<eval<<endl;
            }
            else{
                //
            }
        }
        qApp->processEvents(QEventLoop::AllEvents);
        if(stopopt==1){
            stopopt=0;
            //output results
            out<<"Optimisation stopped. Current best values:"<<endl;
            for(int i = 0; i<nu;i++){
                out<<P(Pl,i)<<endl;
            }
            out<<"Residuum: "<<resAB<<endl;
            out<<endl;
            out<<"Simplex points:"<<endl;
            for(int j=0; j<nu+1; j++){
                for(int i=0; i<nu;i++){
                    cout<<P(j,i)<<"\t";
                    out<<setprecision(12)<<P(j,i)<<"\t";
                }
                out<<setprecision(12)<<"r: "<<y[j]<<endl;
            }
            out.close();
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
         }

        //Alpha Branch, better than best point
        if(yi<yl){
           cout<<"expansion 1 ";
            out<<"expansion 1"<<endl;
            for (int i=0; i<nu; i++){
                Eo[i]=Z[i]+Gamma*(Z[i]-P(Ph,i));  //Expansion over worst point
            }
            //-----------------------------------------------------
            eval++;
            ifstream dstA(dat2Name.c_str());
            ofstream srcA(datName.c_str());
            for(int e=0; e<nA; e++){
                if(e==zeile[count]-1){
                    srcA<<keywordA[count]<<"\t"<<Eo[count]<<endl;
                    cout<<"file A: "<<e<<"\t"<<Eo[count]<<endl;
                    ++count;
                    dstA.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                }
                else{
                    std::getline(dstA, line);
                    srcA<<line<<endl;
                }
            }
            count=0;

            dstA.clear();
            dstA.seekg(0, ios::beg);
            dstA.close();
            srcA.close();

            QDir::setCurrent(ui->lineEdit_13->text());
            system("./rn");
            VALD3::computeMESAResiduumA();
            // binary
            if(ui->checkBox_5->isChecked()){
                // coupled
                if(ui->checkBox_6->isChecked()){
                    ifstream dstB(datB2Name.c_str());
                    ofstream srcB(datBName.c_str());
                    for(int e=0; e<nB; e++){
                        if(e==zeile[count]-1){
                            srcB<<keywordA[count]<<"\t"<<Eo[count]<<endl;
                            cout<<"file B: "<<e<<"\t"<<Eo[count]<<endl;
                            ++count;
                            dstB.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        }
                        else{
                            std::getline(dstB, line);
                            srcB<<line<<endl;
                        }
                    }
                    count=0;

                    dstB.clear();
                    dstB.seekg(0, ios::beg);
                    dstB.close();
                    srcB.close();

                    if(resA<10e10){
                        QDir::setCurrent(ui->lineEdit_17->text());
                        system("./rn");
                        VALD3::computeMESAResiduumB();
                    }
                    else{
                        resB=10e10;
                    }
                }
                // not coupled
                else{
                    ifstream dstB(datB2Name.c_str());
                    ofstream srcB(datBName.c_str());
                    for(int e=0; e<nB; e++){
                        if(e==zeile[count]-1){
                            srcB<<keywordB[count]<<"\t"<<Eo[count+nzeilen]<<endl;
                            cout<<"file B: "<<e<<"\t"<<Eo[count+nzeilen]<<endl;
                            ++count;
                            dstB.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        }
                        else{
                            std::getline(dstB, line);
                            srcB<<line<<endl;
                        }
                    }
                    count=0;

                    dstB.clear();
                    dstB.seekg(0, ios::beg);

                    if(resA<10e10){
                        QDir::setCurrent(ui->lineEdit_17->text());
                        system("./rn");
                        VALD3::computeMESAResiduumB();
                    }
                    else{
                        resB=10e10;
                    }
                }
            }
            //--------------------------------------------------------
            yt=VALD3::MESAResiduum();
            qApp->processEvents(QEventLoop::AllEvents);
            if(yt<resAB){
                out<<"Better parameters found:"<<endl;
                resAB=yt;
                for(int i = 0; i<nu;i++){
                    out<<Co[i]<<endl;
                }
                out<<"Residuum: "<<resAB<<"; resA: "<<resA<<"; resB: "<<resB<<endl;
                out<<endl;
                if(ui->checkBox_5->isChecked()){
                    out<<"Component A: Age: "<<ageAt<<"; log(L/L): "<<LAt<<"; log(Teff): "<<TAt<<endl;
                    out<<"Component B: Age: "<<ageBt<<"; log(L/L): "<<LBt<<"; log(Teff): "<<TBt<<endl;
                }
                else{
                    out<<"Age: "<<ageAt<<"; log(L/L): "<<LAt<<"; log(Teff): "<<TAt<<endl;
                }
                if(ui->checkBox_7->isChecked()){
                    VALD3::saveTracks();
                    out<<"Tracks saved with index "<<eval<<endl;
                }
                else{
                    //
                }
            }

            if(stopopt==1){
                stopopt=0;
                //output results
                out<<"Optimisation stopped. Current best values:"<<endl;
                    for(int i = 0; i<nu;i++){
                        out<<P(Pl,i)<<endl;
                    }
                    out<<"Residuum: "<<resAB<<endl;
                    out<<endl;
                    out<<"Simplex points:"<<endl;
                    for(int j=0; j<nu+1; j++){
                        for(int i=0; i<nu;i++){
                            cout<<P(j,i)<<"\t";
                            out<<setprecision(12)<<P(j,i)<<"\t";
                        }
                        out<<setprecision(12)<<"r: "<<y[j]<<endl;
                    }
                    out.close();
                this->setCursor(QCursor(Qt::ArrowCursor));
                return;
            }
            if(yt<yl){
                cout<<"exp ";
                out<<"Worst point replaced by expansion."<<endl;
                for (int i=0; i<nu; i++){
                    P(Ph,i)=Eo[i];
                }
            y[Ph]=yt;
        }
        if(yt>=yl){
            cout<<"ref1 ";
            out<<"ref1: Worst point replaced by reflected."<<endl;
            for (int i=0; i<nu; i++){
                P(Ph,i)=Co[i];
            }
            y[Ph]=yi;
          }
        }//Alpha Branch end

        if(yi>=yl){
            cout<<"yi>=yl ";
            //Beta_2 Branch
            if(yi<=ysh){
                cout<<"ref2 ";
                for(int i=0; i<nu; i++){
                    P(Ph,i)=Co[i];
                }
                y[Ph]=yi;
                out<<"Ref2: Worst point replaced by reflected."<<endl;
                }//Beta_2 Branch End

                //Beta_1 Branch
                if(yi>ysh){
                    cout<<"yi>ysh ";
                    if(yi<=yh){
                        cout<<"yi<=yh ref3 ";
                        for(int i=0; i<nu; i++){
                            P(Ph,i)=Co[i];
                        }
                        y[Ph]=yi;
                        out<<"Ref3: Worst point replaced by reflected."<<endl;
                    }

                for(int i=0; i<nu; i++){
                    So[i]=Z[i]+beta*(P(Ph,i)-Z[i]); //single contraction
                }
                out<<"Single point contraction."<<endl;
                //-----------------------------------------------------
                eval++;
                ifstream dstA(dat2Name.c_str());
                ofstream srcA(datName.c_str());
                for(int e=0; e<nA; e++){
                    if(e==zeile[count]-1){
                        srcA<<keywordA[count]<<"\t"<<So[count]<<endl;
                        cout<<"file A: "<<e<<"\t"<<So[count]<<endl;
                        ++count;
                        dstA.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    }
                    else{
                        std::getline(dstA, line);
                        srcA<<line<<endl;
                    }
                }
                count=0;

                dstA.clear();
                dstA.seekg(0, ios::beg);
                dstA.close();
                srcA.close();

                QDir::setCurrent(ui->lineEdit_13->text());
                system("./rn");
                VALD3::computeMESAResiduumA();
                // binary
                if(ui->checkBox_5->isChecked()){
                    // coupled
                    if(ui->checkBox_6->isChecked()){
                        ifstream dstB(datB2Name.c_str());
                        ofstream srcB(datBName.c_str());
                        for(int e=0; e<nB; e++){
                            if(e==zeile[count]-1){
                                srcB<<keywordA[count]<<"\t"<<So[count]<<endl;
                                cout<<"file B: "<<e<<"\t"<<So[count]<<endl;
                                ++count;
                                dstB.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                            }
                            else{
                                std::getline(dstB, line);
                                srcB<<line<<endl;
                            }
                        }
                        count=0;

                        dstB.clear();
                        dstB.seekg(0, ios::beg);
                        dstB.close();
                        srcB.close();

                        if(resA<10e10){
                            QDir::setCurrent(ui->lineEdit_17->text());
                            system("./rn");
                            VALD3::computeMESAResiduumB();
                        }
                        else{
                            resB=10e10;
                        }
                    }
                    // not coupled
                    else{
                        ifstream dstB(datB2Name.c_str());
                        ofstream srcB(datBName.c_str());
                        for(int e=0; e<nB; e++){
                            if(e==zeile[count]-1){
                                srcB<<keywordB[count]<<"\t"<<So[count+nzeilen]<<endl;
                                cout<<"file B: "<<e<<"\t"<<So[count+nzeilen]<<endl;
                                ++count;
                                dstB.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                            }
                            else{
                                std::getline(dstB, line);
                                srcB<<line<<endl;
                            }
                        }
                        count=0;

                        dstB.clear();
                        dstB.seekg(0, ios::beg);

                        if(resA<10e10){
                            QDir::setCurrent(ui->lineEdit_17->text());
                            system("./rn");
                            VALD3::computeMESAResiduumB();
                        }
                        else{
                            resB=10e10;
                        }
                    }
                }
                //--------------------------------------------------------
                yt=VALD3::MESAResiduum();
                if(yt<resAB){
                    out<<"better parameters found:"<<endl;
                    resAB=yt;
                    for(int i = 0; i<nu;i++){
                        out<<So[i]<<endl;
                    }
                    out<<"Residuum: "<<resAB<<"; resA: "<<resA<<"; resB: "<<resB<<endl;
                    out<<endl;
                    if(ui->checkBox_5->isChecked()){
                        out<<"Component A: Age: "<<ageAt<<"; log(L/L): "<<LAt<<"; log(Teff): "<<TAt<<endl;
                        out<<"Component B: Age: "<<ageBt<<"; log(L/L): "<<LBt<<"; log(Teff): "<<TBt<<endl;
                    }
                    else{
                        out<<"Age: "<<ageAt<<"; log(L/L): "<<LAt<<"; log(Teff): "<<TAt<<endl;
                    }
                    if(ui->checkBox_7->isChecked()){
                        VALD3::saveTracks();
                        out<<"Tracks saved with index "<<eval<<endl;
                    }
                    else{
                        //
                    }
                }
                qApp->processEvents(QEventLoop::AllEvents);

                if(stopopt==1){
                    stopopt=0;
                    //output results
                    out<<"Optimisation stopped. Current best values:"<<endl;
                        for(int i = 0; i<nu;i++){
                            out<<P(Pl,i)<<endl;
                        }
                        out<<"Residuum: "<<resAB<<endl;
                        out<<endl;
                        out<<"Simplex points:"<<endl;
                        for(int j=0; j<nu+1; j++){
                            for(int i=0; i<nu;i++){
                                cout<<P(j,i)<<"\t";
                                out<<setprecision(12)<<P(j,i)<<"\t";
                            }
                            out<<setprecision(12)<<"r: "<<y[j]<<endl;
                        }
                        out.close();
                        this->setCursor(QCursor(Qt::ArrowCursor));
                        return;
                    }

                //Beta_1_1 Branch
                if(yt>yh){
                    cout<<"yt>yh tot ";
                    out<<"Total contraction of simplex."<<endl;
                    for (int j=0; j<nu+1; j++){
                        out<<"Contraction of point "<<j+1<<" of "<<nu+1<<" points."<<endl;
                        for (int i=0; i<nu; i++){
                            P(j,i)=P(Pl,i)+btot*(P(j,i)-P(Pl,i)); //total contraction
                        }
                        //-----------------------------------------------------
                        eval++;
                        ifstream dstA(dat2Name.c_str());
                        ofstream srcA(datName.c_str());
                        for(int e=0; e<nA; e++){
                            if(e==zeile[count]-1){
                                srcA<<keywordA[count]<<"\t"<<P(j,count)<<endl;
                                cout<<"file A: "<<e<<"\t"<<P(j,count)<<endl;
                                ++count;
                                dstA.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                            }
                            else{
                                std::getline(dstA, line);
                                srcA<<line<<endl;
                            }
                        }
                        count=0;

                        dstA.clear();
                        dstA.seekg(0, ios::beg);
                        dstA.close();
                        srcA.close();

                        QDir::setCurrent(ui->lineEdit_13->text());
                        system("./rn");
                        VALD3::computeMESAResiduumA();
                        // binary
                        if(ui->checkBox_5->isChecked()){
                            // coupled
                            if(ui->checkBox_6->isChecked()){
                                ifstream dstB(datB2Name.c_str());
                                ofstream srcB(datBName.c_str());
                                for(int e=0; e<nB; e++){
                                    if(e==zeile[count]-1){
                                        srcB<<keywordA[count]<<"\t"<<P(j,count)<<endl;
                                        cout<<"file B: "<<e<<"\t"<<P(j,count)<<endl;
                                        ++count;
                                        dstB.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                                    }
                                    else{
                                        std::getline(dstB, line);
                                        srcB<<line<<endl;
                                    }
                                }
                                count=0;

                                dstB.clear();
                                dstB.seekg(0, ios::beg);
                                dstB.close();
                                srcB.close();

                                if(resA<10e10){
                                    QDir::setCurrent(ui->lineEdit_17->text());
                                    system("./rn");
                                    VALD3::computeMESAResiduumB();
                                }
                                else{
                                    resB=10e10;
                                }
                            }
                            // not coupled
                            else{
                                ifstream dstB(datB2Name.c_str());
                                ofstream srcB(datBName.c_str());
                                for(int e=0; e<nB; e++){
                                    if(e==zeile[count]-1){
                                        srcB<<keywordB[count]<<"\t"<<P(j,count+nzeilen)<<endl;
                                        cout<<"file B: "<<e<<"\t"<<P(j,count+nzeilen)<<endl;
                                        ++count;
                                        dstB.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                                    }
                                    else{
                                        std::getline(dstB, line);
                                        srcB<<line<<endl;
                                    }
                                }
                                count=0;

                                dstB.clear();
                                dstB.seekg(0, ios::beg);

                                if(resA<10e10){
                                    QDir::setCurrent(ui->lineEdit_17->text());
                                    system("./rn");
                                    VALD3::computeMESAResiduumB();
                                }
                                else{
                                    resB=10e10;
                                }
                            }
                        }
                        //--------------------------------------------------------
                        y[j]=VALD3::MESAResiduum();
                        if(y[j]<resAB){
                            out<<"Better parameters found:"<<endl;
                            resAB=y[j];
                            for(int i = 0; i<nu;i++){
                                out<<P(j,i)<<endl;
                            }
                            out<<"Residuum: "<<resAB<<"; resA: "<<resA<<"; resB: "<<resB<<endl;
                            out<<endl;
                            if(ui->checkBox_5->isChecked()){
                                out<<"Component A: Age: "<<ageAt<<"; log(L/L): "<<LAt<<"; log(Teff): "<<TAt<<endl;
                                out<<"Component B: Age: "<<ageBt<<"; log(L/L): "<<LBt<<"; log(Teff): "<<TBt<<endl;
                            }
                            else{
                                out<<"Age: "<<ageAt<<"; log(L/L): "<<LAt<<"; log(Teff): "<<TAt<<endl;
                            }
                            if(ui->checkBox_7->isChecked()){
                                VALD3::saveTracks();
                                out<<"Tracks saved with index "<<eval<<endl;
                            }
                            else{
                                //
                            }
                        }
                cout<<j+1<<" of "<<nu+1<<" points contracted."<<endl;
                 qApp->processEvents(QEventLoop::AllEvents);

                if(stopopt==1){
                    stopopt=0;
                    //output results
                    out<<"Optimisation stopped. Current best values:"<<endl;
                    for(int i = 0; i<nu;i++){
                        out<<P(Pl,i)<<endl;
                    }
                    out<<"Residuum: "<<resAB<<endl;
                    out<<endl;
                    out<<"Simplex points:"<<endl;
                    for(int j=0; j<nu+1; j++){
                        for(int i=0; i<nu;i++){
                            cout<<P(j,i)<<"\t";
                            out<<setprecision(12)<<P(j,i)<<"\t";
                        }
                        out<<setprecision(12)<<"r: "<<y[j]<<endl;
                    }
                    out.close();
                    this->setCursor(QCursor(Qt::ArrowCursor));
                    return;
                 }
                }

                }//Beta_1_1 Branch End

                //Beta_1_2 Branch
                if(yt<=yh){
                    cout<<"yt<=yh, sco ";
                    out<<"Sco: Worst point repleced by single contracted point."<<endl;
                    for(int i=0; i<nu; i++){
                        P(Ph,i)=So[i];
                    }
                y[Ph]=yt;
                }
            }
        }

    }// end main loop, index t

    //looking for highest value
    yh=y[0];
    for (int j=0; j<nu+1; j++){
        if(y[j]>yh){
        yh = y[j];
        Ph = j;
        }
    }

    //looking for smallest value
    yl=yh;
    for (int j=0; j<nu+1; j++){
        if(y[j]<yl){
            yl=y[j];
            Pl = j;
        }
    }

    //looking for second highest value
    ysh=yl;
    for (int j=0; j<nu+1; j++){
        if((y[j]>ysh)&(y[j]<yh)){
            ysh=y[j];
            Psh=j;
        }
    }

    //computing mean and sigma
    for (int i=0; i<nu+1; i++){
        ym+=y[i]/(nu+1);
    }
    for (int i=0; i<nu+1; i++){
        ys+=sqrt(pow((y[i]-ym),2));
    }
    ys=ys/(nu);

    cout<<"Best parameters after "<<zaehler<<" Iterations and "<<eval<<" Evaluations:"<<endl;
    out<<"Best parameters after "<<zaehler<<" Iterations and "<<eval<<" Evaluations:"<<endl;
    for(int i=0; i<nu;i++){
        cout<<P(Pl,i)<<endl;
        out<<P(Pl,i)<<endl;
    }
    out<<endl;
    out<<"Simplex Mean: "<<ym<<"; Simplex STD: "<<ys<<endl;
    out<<endl;
    cout<<"Simplex after "<<zaehler<<" iterations:"<<endl;
    out<<"Simplex after "<<zaehler<<" iterations:"<<endl;
    for(int j=0; j<nu+1; j++){
        for(int i=0; i<nu;i++){
            cout<<P(j,i)<<"\t";
            out<<P(j,i)<<"\t";
        }
        out<<"r: "<<y[j]<<endl;
        cout<<endl;
    }
    out.close();

    this->setCursor(QCursor(Qt::ArrowCursor));

}


//**************************
// table for variables
//**************************
void VALD3::on_spinBox_valueChanged()
{
    nmesavar = ui->spinBox->value();
    int nmesavar2=ui->tableWidget->rowCount();
    if(nmesavar>nmesavar2){
        for(int i=0; i<nmesavar-nmesavar2; i++){
            ui->tableWidget->insertRow(nmesavar2+i);
            ui->tableWidget->setItem(nmesavar2+i, 1, new QTableWidgetItem("0.01"));

        }
    }
    if(nmesavar<nmesavar2){
        for(int i=0; i<nmesavar2-nmesavar; i++){
            ui->tableWidget->removeRow(nmesavar2-i-1);
        }
    }
    ui->tableWidget->setRowCount(nmesavar);
}

//*****************************
// binary check box
//*****************************
void VALD3::on_checkBox_5_clicked()
{
    if(ui->checkBox_5->isChecked()){
        ui->checkBox_6->setEnabled(true);
        ui->checkBox_9->setEnabled(true);
        ui->lineEdit_17->setEnabled(true);
        ui->lineEdit_18->setEnabled(true);
        ui->lineEdit_19->setEnabled(true);
        ui->lineEdit_20->setEnabled(true);
        ui->lineEdit_22->setEnabled(true);
        ui->lineEdit_24->setEnabled(true);
        ui->lineEdit_26->setEnabled(true);
    }
    else{
        ui->checkBox_6->setEnabled(false);
        ui->checkBox_9->setEnabled(false);
        ui->lineEdit_17->setEnabled(false);
        ui->lineEdit_18->setEnabled(false);
        ui->lineEdit_19->setEnabled(false);
        ui->lineEdit_20->setEnabled(false);
        ui->lineEdit_22->setEnabled(false);
        ui->lineEdit_24->setEnabled(false);
        ui->lineEdit_26->setEnabled(false);
    }
}

//********************************
// compute residuum
//********************************
void VALD3::computeMESAResiduumA()
{
        string historyA = (ui->lineEdit_14->text()+"/history.data").toUtf8().constData();
        std::ostringstream datNameStream(historyA);
        datNameStream<<historyA;
        std::string datName = datNameStream.str();

        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            QMessageBox::information(this, "Error", "Error 1: File"+checkfile.fileName()+" does not exist!");
            //this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }
        ifstream histA(datName.c_str());

        int nhistA=0;
        string lines;
        while(std::getline(histA, lines))
           ++nhistA;

        histA.clear();
        histA.seekg(0, ios::beg);

        QVector<double> LA(nhistA), TA(nhistA), ageA(nhistA);
        string a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39;

        for(int i =0; i<6; i++){
            histA.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }

        for(int i =0; i<nhistA; i++){
            histA >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 >> a9 >> a10 >> a11 >> a12 >> a13 >> a14 >> a15 >> a16 >> a17 >> a18 >> a19 >> a20 >> a21 >> a22 >> a23 >> a24 >> a25 >> a26 >> a27 >> a28 >> a29 >> a30 >> a31 >> a32 >> a33 >> a34 >> a35 >> a36 >> a37 >> a38 >> a39;
            istringstream str(a3);
            str >> ageA[i];
            istringstream str1(a38);
            str1 >> TA[i];
            istringstream str2(a39);
            str2 >> LA[i];
            histA.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }

        double LAm = ui->lineEdit_15->text().toDouble();
        double TAm = ui->lineEdit_16->text().toDouble();
        double pthreshLA = ui->lineEdit_21->text().toDouble();
        double pthreshTA = ui->lineEdit_25->text().toDouble();
        double mthreshLA = ui->lineEdit_29->text().toDouble();
        double mthreshTA = ui->lineEdit_31->text().toDouble();
        int ec=0, ec2=0;

        LAt=LA[nhistA-1];
        TAt=TA[nhistA-1];
        ageAt=ageA[nhistA-1];

        resA = abs(LAm-LA[nhistA-1])/LAm+abs(TAm-TA[nhistA-1])/TAm;

        for(int i=0; i<nhistA; i++){

            if(ui->checkBox_11->isChecked()){
                if( (abs(LAm-LA[nhistA-1-i])/LAm+abs(TAm-TA[nhistA-1-i])/TAm) < resA ){
                    ++ec;
                    resA = abs(LAm-LA[nhistA-1-i])/LAm+abs(TAm-TA[nhistA-1-i])/TAm;
                    ageAt = ageA[nhistA-1-i];
                    LAt=LA[nhistA-1-i];
                    TAt=TA[nhistA-1-i];
                }
                else{
                }
            }
            else{
                if((LA[nhistA-1-i]<=LAm+pthreshLA) & (LA[nhistA-1-i]>=LAm-mthreshLA) & (TA[nhistA-1-i]<=TAm+pthreshTA) & (TA[nhistA-1-i]>=TAm-mthreshTA)){
                    if( (abs(LAm-LA[nhistA-1-i])/LAm+abs(TAm-TA[nhistA-1-i])/TAm) < resA ){
                        ++ec;
                        resA = abs(LAm-LA[nhistA-1-i])/LAm+abs(TAm-TA[nhistA-1-i])/TAm;
                        ageAt = ageA[nhistA-1-i];
                        LAt=LA[nhistA-1-i];
                        TAt=TA[nhistA-1-i];
                    }
                    else{
                    }
                }
            }
            if((ec==ec2) & (ec>0) & (ec2 > 0)){
                i=nhistA;
            }
            else{
                ec2=ec;
            }
        }
        if(ec==0){
            cout<<"Track through HRD box of star A not present."<<endl;
            if(ui->checkBox_8->isChecked()){
                stopopt=1;
            }
            else{
                resA = 10e10;
            }
        }
}

//*****************************
// residuum for star B
//*****************************
void VALD3::computeMESAResiduumB()
{
    string historyB = (ui->lineEdit_18->text()+"/history.data").toUtf8().constData();
    std::ostringstream datNameStream(historyB);
    datNameStream<<historyB;
    std::string datName = datNameStream.str();

    QFile checkfile(datName.c_str());

    if(!checkfile.exists()){
        QMessageBox::information(this, "Error", "Error 1: File"+checkfile.fileName()+" does not exist!");
        //this->setCursor(QCursor(Qt::ArrowCursor));
        return;
    }
    ifstream histB(datName.c_str());

    int nhistB=0;
    string lines;
    while(std::getline(histB, lines))
       ++nhistB;

    histB.clear();
    histB.seekg(0, ios::beg);

    QVector<double> LB(nhistB), TB(nhistB), ageB(nhistB);
    string a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39;

    for(int i =0; i<6; i++){
        histB.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }

    for(int i =0; i<nhistB; i++){
        histB >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 >> a9 >> a10 >> a11 >> a12 >> a13 >> a14 >> a15 >> a16 >> a17 >> a18 >> a19 >> a20 >> a21 >> a22 >> a23 >> a24 >> a25 >> a26 >> a27 >> a28 >> a29 >> a30 >> a31 >> a32 >> a33 >> a34 >> a35 >> a36 >> a37 >> a38 >> a39;
        istringstream str(a3);
        str >> ageB[i];
        istringstream str1(a38);
        str1 >> TB[i];
        istringstream str2(a39);
        str2 >> LB[i];
        histB.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }

    double LBm = ui->lineEdit_19->text().toDouble();
    double TBm = ui->lineEdit_20->text().toDouble();
    double pthreshLB = ui->lineEdit_22->text().toDouble();
    double pthreshTB = ui->lineEdit_26->text().toDouble();
    double mthreshLB = ui->lineEdit_30->text().toDouble();
    double mthreshTB = ui->lineEdit_32->text().toDouble();
    int ec=0, ec2=0;

    LBt=LB[nhistB-1];
    TBt=TB[nhistB-1];
    ageBt=ageB[nhistB-1];

    resB = abs(LBm-LB[nhistB-1])/LBm+abs(TBm-TB[nhistB-1])/TBm;

    for(int i=0; i<nhistB; i++){

        if(ui->checkBox_11->isChecked()){
            if( (abs(LBm-LB[nhistB-1-i])/LBm+abs(TBm-TB[nhistB-1-i])/TBm) < resB ){
                ++ec;
                resB = abs(LBm-LB[nhistB-1-i])/LBm+abs(TBm-TB[nhistB-1-i])/TBm;
                ageBt = ageB[nhistB-1-i];
                LBt=LB[nhistB-1-i];
                TBt=TB[nhistB-1-i];
            }
            else{
                //
            }
        }
        else{
            if((LB[nhistB-1-i]<=LBm+pthreshLB) & (LB[nhistB-1-i]>=LBm-mthreshLB) & (TB[nhistB-1-i]<=TBm+pthreshTB) & (TB[nhistB-1-i]>=TBm-mthreshTB)){
                if( (abs(LBm-LB[nhistB-1-i])/LBm+abs(TBm-TB[nhistB-1-i])/TBm) < resB ){
                    ++ec;
                    resB = abs(LBm-LB[nhistB-1-i])/LBm+abs(TBm-TB[nhistB-1-i])/TBm;
                    ageBt = ageB[nhistB-1-i];
                    LBt=LB[nhistB-1-i];
                    TBt=TB[nhistB-1-i];
                }
                else{
                    //
                }
            }
            else{
                //
            }
        }
        if((ec==ec2) & (ec>0) & (ec2 > 0)){
            i=nhistB;
        }
        else{
            ec2=ec;
        }
    }
    if(ec==0){
        cout<<"Track through HRD box of star B not present."<<endl;
        if(ui->checkBox_9->isChecked()){
            stopopt=1;
            cout<<"Abort optimisation."<<endl;
        }
        else{
            resB = 10e10;
        }
    }
}

//**********************************************
// combine residuum
//**********************************************
double VALD3::MESAResiduum()
{
    double retAB=0.0;
    double weightA=ui->doubleSpinBox->value();
    double weightB=ui->doubleSpinBox_2->value();

    if(ui->checkBox_5->isChecked()){
        retAB = (weightA*resA+weightB*resB)/2+abs(ageAt-ageBt)/(ageAt+ageBt)*2;
    }
    else{
        retAB = resA;
    }

    return retAB;
}

//************************************
// rename and save better tracks
//************************************
void VALD3::saveTracks(){

    string oldA = (ui->lineEdit_14->text()+"/history.data").toUtf8().constData();
    string newA = (ui->lineEdit_14->text()+"/history_A_"+QString::number(eval)+".data").toUtf8().constData();

    const char *OLDA, *NEWA;

    OLDA = oldA.c_str();
    NEWA = newA.c_str();

    rename(OLDA, NEWA);

    string oldB = (ui->lineEdit_18->text()+"/history.data").toUtf8().constData();
    string newB = (ui->lineEdit_18->text()+"/history_B_"+QString::number(eval)+".data").toUtf8().constData();

    const char *OLDB, *NEWB;

    OLDB = oldB.c_str();
    NEWB = newB.c_str();

    rename(OLDB, NEWB);
}
//************************************
// stop optimisation
//************************************
void VALD3::on_pushButton_7_clicked()
{
    stopopt=1;
}
