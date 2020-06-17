#include "plotsequ.h"
#include "ui_plotsequ.h"
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <CCfits/CCfits>
#include <spline.h>

using namespace std;
namespace fit=CCfits;

int pcolor=1;
double xse1, yse2, xse2, yse1, offset;
QString qSeqPath, qseExtension, qseWavecol, qseIntenscol;
string seqPath;
string seExtension, seWavecol, seIntenscol;

std::valarray<double> sewave;
std::valarray<double> seintens;
const double c0=299792.458;


PlotSequ::PlotSequ(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlotSequ)
{
    ui->setupUi(this);
    this->setWindowTitle("Sequence Plotter");

    ui->customPlot->xAxis->setLabel("Wavelength [A]");
    ui->customPlot->yAxis->setLabel("Normalized Intensity");
    ui->checkBox->setChecked(true);
    qSeqPath=ui->lineEdit_5->text();
    seqPath = qSeqPath.toUtf8().constData();
    offset=ui->doubleSpinBox_5->value();


    ui->lineEdit_9->setText(".txt");
    ui->lineEdit_10->setText("Ha_lmB_1.dat");

    ui->comboBox->addItem("ASCII");
    ui->comboBox->addItem("fits");

    QFont legendFont = font();
    legendFont.setPointSize(16);
    ui->customPlot->axisRect()->setupFullAxesBox(true);
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);
    ui->customPlot->xAxis->setAutoTickStep(false);
    ui->customPlot->yAxis->setAutoTickStep(false);
    ui->customPlot->xAxis->setTickStep(0.5);
    ui->customPlot->yAxis->setTickStep(0.25);

    ui->comboBox_2->addItem("Black");
    ui->comboBox_2->addItem("Blue");
    ui->comboBox_2->addItem("Red");
    ui->comboBox_2->addItem("Green");
    ui->comboBox_2->addItem("Yellow");
    ui->comboBox_2->addItem("Magenta");

    ui->lineEdit_11->setText("103_1_cor_1.txt");
    ui->lineEdit_12->setText("103_1_cor_2.txt");

    ui->lineEdit_17->setText("250");
    ui->lineEdit_18->setText("500");

    connect(ui->customPlot, SIGNAL(mouseMove(QMouseEvent*)), this ,SLOT(showPointToolTip(QMouseEvent*)));


}

PlotSequ::~PlotSequ()
{
    delete ui;
}

void PlotSequ::seData(QString str1, QString str2, QString str3, QString str4, QString str5)
{
    ui->lineEdit_5->setText(str1);
    ui->lineEdit->setText(str2);
    ui->lineEdit_6->setText(str3);
    ui->lineEdit_7->setText(str4);
    ui->lineEdit_8->setText(str5);
}

//********************************************************
//show mouse coordinates
//********************************************************
void PlotSequ::showPointToolTip(QMouseEvent *event)
{

    double xc = ui->customPlot->xAxis->pixelToCoord(event->pos().x());
    double yc = ui->customPlot->yAxis->pixelToCoord(event->pos().y());

    setToolTip(QString("%1 , %2").arg(xc).arg(yc));
}

//****************************************************************
//set values
//****************************************************************
void PlotSequ::on_pushButton_3_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));

    qSeqPath=ui->lineEdit_5->text();
    seqPath=qSeqPath.toUtf8().constData();

    string line, eins, zwei;
    int min=ui->spinBox->value();
    int max=ui->spinBox_2->value();
    int number_of_lines =0;
    QVector<double> a(1), b(1);

    QString qext=ui->lineEdit_9->text();
    string sext = qext.toUtf8().constData();

    for (int u=min; u<=max; u++){

        if(ui->comboBox->currentIndex()==0){
    QString input=ui->lineEdit->text();
    string data = input.toUtf8().constData();
    std::ostringstream datNameStream(data);
    datNameStream<<seqPath<<"/"<<data<<u<<sext;
    std::string datName = datNameStream.str();

    QFile checkfile(datName.c_str());

    if(!checkfile.exists()){
        qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
        QString fError= QString::number(u);
        QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input+fError+qext+" does not exist!");
        this->setCursor(QCursor(Qt::ArrowCursor));
        return;
    }

    ifstream dat(datName.c_str());

    number_of_lines =0;


    while(std::getline(dat, line))
       ++ number_of_lines;

    dat.clear();
    dat.seekg(0, ios::beg);

    a.resize(number_of_lines);
    b.resize(number_of_lines);

    for (int i=0; i<number_of_lines; i++){
    dat >> eins >>zwei;
    istringstream ist(eins);
    ist >> a[i];
    if(ui->checkBox_15->isChecked()){
        a[i]=log10(a[i]);
    }
    else{
        if(ui->checkBox_16->isChecked()){
            a[i]=pow(10,a[i]);
        }
        else{

        }
    }
    if(ui->checkBox_13->isChecked()){
        a[i]=(a[i]-ui->doubleSpinBox_12->value())*c0/ui->doubleSpinBox_12->value();
    }
    istringstream ist2(zwei);
    ist2 >> b[i];
    b[i]=b[i]+offset*(u-min);
    }
    dat.close();
        }

        if(ui->comboBox->currentIndex()==1){
            QString input=ui->lineEdit->text();
            string data = input.toUtf8().constData();
            std::ostringstream datNameStream(data);
            datNameStream<<seqPath<<"/"<<data<<u<<sext;
            std::string datName = datNameStream.str();
            ifstream dat(datName.c_str());

            QFile checkfile1(datName.c_str());

            if(!checkfile1.exists()){
                qDebug()<<"Error 1: The file "<<checkfile1.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error1 ", "Error 1: File "+checkfile1.fileName()+" does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
                //check=1;
               return;
            }

            CCfits::FITS::setVerboseMode(true);

            try
            {
                qseExtension = ui->lineEdit_6->text();
                seExtension = qseExtension.toUtf8().constData();

                qseWavecol=ui->lineEdit_7->text();
                seWavecol = qseWavecol.toUtf8().constData();
                qseIntenscol=ui->lineEdit_8->text();
                seIntenscol = qseIntenscol.toUtf8().constData();


                //open file for reading
                shared_ptr<CCfits::FITS> input_file(new CCfits::FITS(datName.c_str(),CCfits::Read));
                cout<<"test"<<endl;


                // Create pointer to extension
                    CCfits::ExtHDU& datavector = input_file->extension(seExtension);

                    cout<<"test"<<endl;

                  // Read rows
                  CCfits::Column& column = datavector.column(seWavecol);
                  column.read(sewave, 1, column.rows());

                  // Read rows
                  CCfits::Column& column2 = datavector.column(seIntenscol);
                  column2.read(seintens, 1, column2.rows());

                  number_of_lines=sewave.size();

                  a.resize(number_of_lines);
                  b.resize(number_of_lines);

                  for(int i=0; i<number_of_lines; i++){
                  b[i]=seintens[i]+offset*(u-min);
                  a[i]=sewave[i];
                  if(ui->checkBox_15->isChecked()){
                      a[i]=log10(a[i]);
                  }
                  else{
                      if(ui->checkBox_16->isChecked()){
                          a[i]=pow(10,a[i]);
                      }
                      else{

                      }
                  }
                  if(ui->checkBox_13->isChecked()){
                      a[i]=(a[i]-ui->doubleSpinBox_12->value())*c0/ui->doubleSpinBox_12->value();
                  }
                  }


            }
                catch (CCfits::FitsException&)

                 {
                  std::cerr << " Fits Exception Thrown by test function \n";
                  }


               // return;

        }

    if(u==min){
        xse1=a[0];
        xse2=a[0];
    }
    for(int i=0; i<number_of_lines; i++){
        if(a[i]<xse1){
            xse1=a[i];
        }
        if(a[i]>xse2){
            xse2=a[i];
        }
    }

    ui->doubleSpinBox->setValue(xse1);
     ui->doubleSpinBox_2->setValue(xse2);

     if(u==min){
        yse1=b[0];
        yse2=b[0];
     }
    for(int i=0; i<number_of_lines; i++){
        if(b[i]<yse1){
            yse1=b[i];
        }
        if(b[i]>yse2){
            yse2=b[i];
        }
    }

     ui->doubleSpinBox_3->setValue(yse1);
     ui->doubleSpinBox_4->setValue(yse2);
}

    this->setCursor(QCursor(Qt::ArrowCursor));
}

//****************************************************************
//plot sequence
//****************************************************************
void PlotSequ::on_pushButton_2_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));

    qSeqPath=ui->lineEdit_5->text();
    seqPath=qSeqPath.toUtf8().constData();

    QPen pen1, pen2, pen3, pen4, pen5;

    ui->customPlot->clearGraphs();

    string line, eins, zwei;
    int min=ui->spinBox->value();
    int max=ui->spinBox_2->value();
    int number_of_lines =0;

    QString qext=ui->lineEdit_9->text();
    string sext = qext.toUtf8().constData();

    QVector<double> a(1), b(1);

    for (int u=min; u<=max; u++){

        if(ui->comboBox->currentIndex()==0){
            QString input=ui->lineEdit->text();
            string data = input.toUtf8().constData();
            std::ostringstream datNameStream(data);
            datNameStream<<seqPath<<"/"<<data<<u<<sext;
            std::string datName = datNameStream.str();
            ifstream dat(datName.c_str());


            QFile checkfile(datName.c_str());

            if(!checkfile.exists()){
                qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
                QString fError= QString::number(u);
                QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input+fError+qext+" does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
                return;
            }

            number_of_lines =0;

            while(std::getline(dat, line))
                ++ number_of_lines;

            dat.clear();
            dat.seekg(0, ios::beg);

            a.resize(number_of_lines);
            b.resize(number_of_lines);

            for (int i=0; i<number_of_lines; i++){
                dat >> eins >>zwei;
                istringstream ist(eins);
                ist >> a[i];
                if(ui->checkBox_15->isChecked()){
                    a[i]=log10(a[i]);
                }
                else{
                    if(ui->checkBox_16->isChecked()){
                        a[i]=pow(10,a[i]);
                    }
                    else{

                    }
                }
                if(ui->checkBox_13->isChecked()){
                    a[i]=(a[i]-ui->doubleSpinBox_12->value())*c0/ui->doubleSpinBox_12->value();
                }
                istringstream ist2(zwei);
                ist2 >> b[i];
                b[i]=b[i]+offset*(u-min);
            }
            dat.close();
        }

        if(ui->comboBox->currentIndex()==1){
            QString input=ui->lineEdit->text();
            string data = input.toUtf8().constData();
            std::ostringstream datNameStream(data);
            datNameStream<<seqPath<<"/"<<data<<u<<sext;
            std::string datName = datNameStream.str();
            ifstream dat(datName.c_str());

            QFile checkfile1(datName.c_str());

            if(!checkfile1.exists()){
                qDebug()<<"Error 1: The file "<<checkfile1.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error1 ", "Error 1: File "+checkfile1.fileName()+" does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
                //check=1;
               return;
            }

            CCfits::FITS::setVerboseMode(true);

            try
            {
                qseExtension = ui->lineEdit_6->text();
                seExtension = qseExtension.toUtf8().constData();

                qseWavecol=ui->lineEdit_7->text();
                seWavecol = qseWavecol.toUtf8().constData();
                qseIntenscol=ui->lineEdit_8->text();
                seIntenscol = qseIntenscol.toUtf8().constData();

                //open file for reading
                shared_ptr<CCfits::FITS> input_file(new CCfits::FITS(datName.c_str(),CCfits::Read,true));

                // Create pointer to extension
                    CCfits::ExtHDU& datavector = input_file->extension(seExtension);

                  // Read rows
                  CCfits::Column& column = datavector.column(seWavecol);
                  column.read(sewave, 1, column.rows());

                  // Read rows
                  CCfits::Column& column2 = datavector.column(seIntenscol);
                  column2.read(seintens, 1, column2.rows());

                  int bini=sewave.size();

                  a.resize(bini);
                  b.resize(bini);

                  for(int i=0; i<bini; i++){
                  b[i]=seintens[i]+offset*(u-min);
                  a[i]=sewave[i];
                  if(ui->checkBox_15->isChecked()){
                      a[i]=log10(a[i]);
                  }
                  else{
                      if(ui->checkBox_16->isChecked()){
                          a[i]=pow(10,a[i]);
                      }
                      else{

                      }
                  }
                  if(ui->checkBox_13->isChecked()){
                      a[i]=(a[i]-ui->doubleSpinBox_12->value())*c0/ui->doubleSpinBox_12->value();
                  }
                  }


            }
                catch (CCfits::FitsException&)

                 {
                  std::cerr << " Fits Exception Thrown by test function \n";
                  }


               // return;

        }

        ui->customPlot->addGraph();
        if(pcolor==1){
            pen1.setColor(Qt::black);
            pen1.setWidth(ui->spinBox_4->value());
        ui->customPlot->graph()->setPen(pen1);
        }
        if(pcolor==2){
            pen1.setColor(Qt::blue);
            pen1.setWidth(ui->spinBox_4->value());
        ui->customPlot->graph()->setPen(pen1);
        }
        if(pcolor==3){
            pen1.setColor(Qt::red);
            pen1.setWidth(ui->spinBox_4->value());
        ui->customPlot->graph()->setPen(pen1);
        }
        if(pcolor==4){
            pen1.setColor(Qt::green);
            pen1.setWidth(ui->spinBox_4->value());
        ui->customPlot->graph()->setPen(pen1);
        }
        if(pcolor==5){
            pen1.setColor(Qt::yellow);
            pen1.setWidth(ui->spinBox_4->value());
        ui->customPlot->graph()->setPen(pen1);
        }
        if(pcolor==6){
            pen1.setColor(Qt::magenta);
            pen1.setWidth(ui->spinBox_4->value());
        ui->customPlot->graph()->setPen(pen1);
        }
        ui->customPlot->graph()->setData(a, b);

        // overplot 1
        if(ui->checkBox_4->isChecked()){
            QString input1=ui->lineEdit_11->text();
            string data1 = input1.toUtf8().constData();
            std::ostringstream dat1NameStream(data1);
            dat1NameStream<<seqPath<<"/"<<data1;
            std::string dat1Name = dat1NameStream.str();

            QFile checkfile(dat1Name.c_str());

            if(!checkfile.exists()){
                qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input1+" does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
                return;
             }

             ifstream dat1(dat1Name.c_str());

            number_of_lines =0;


            while(std::getline(dat1, line))
               ++ number_of_lines;

            dat1.clear();
            dat1.seekg(0, ios::beg);

            QVector<double> a1(number_of_lines);
            QVector<double> b1(number_of_lines);

            for (int i=0; i<number_of_lines; i++){
                dat1 >> eins >>zwei;
                istringstream ist(eins);
                ist >> a1[i];
                if(ui->checkBox_17->isChecked()){
                    a1[i]=log10(a1[i]);
                }
                else{
                    if(ui->checkBox_19->isChecked()){
                        a1[i]=pow(10,a1[i]);
                    }
                    else{
                            //
                    }
                }

            if(ui->checkBox_13->isChecked()){
                a1[i]=(a1[i]-ui->doubleSpinBox_12->value())*c0/ui->doubleSpinBox_12->value();
                if(ui->checkBox_6->isChecked()){
                    a1[i]=a1[i]+ui->doubleSpinBox_8->value();
                }
                else{
                    //
                }
            }

                if(ui->checkBox_6->isChecked()){
                    a1[i]=a1[i]*(1+ui->doubleSpinBox_8->value()/c0);
                }
                else{
                    //
                }


            istringstream ist2(zwei);
            ist2 >> b1[i];
            b1[i]=b1[i]+ui->doubleSpinBox_6->value()+offset*(u-min);
            }
            dat1.close();

            ui->customPlot->addGraph();
            pen2.setColor(Qt::magenta);
            pen2.setWidth(ui->spinBox_4->value());
            ui->customPlot->graph()->setPen(pen2);
            ui->customPlot->graph()->setData(a1, b1);
        }

        // overplot 2
        if(ui->checkBox_5->isChecked()){
            QString input2=ui->lineEdit_12->text();
            string data2 = input2.toUtf8().constData();
            std::ostringstream dat2NameStream(data2);
            dat2NameStream<<seqPath<<"/"<<data2;
            std::string dat2Name = dat2NameStream.str();
            ifstream dat2(dat2Name.c_str());


            QFile checkfile(dat2Name.c_str());

            if(!checkfile.exists()){
                qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input2+" does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
                }

            number_of_lines =0;


            while(std::getline(dat2, line))
               ++ number_of_lines;

            dat2.clear();
            dat2.seekg(0, ios::beg);

            QVector<double> a2(number_of_lines);
            QVector<double> b2(number_of_lines);

            for (int i=0; i<number_of_lines; i++){
            dat2 >> eins >>zwei;
            istringstream ist(eins);
            ist >> a2[i];
            if(ui->checkBox_18->isChecked()){
                a2[i]=log10(a2[i]);
            }
            else{
                if(ui->checkBox_20->isChecked()){
                    a2[i]=pow(10,a2[i]);
                }
                else{

                }
            }

            if(ui->checkBox_13->isChecked()){
                a2[i]=(a2[i]-ui->doubleSpinBox_12->value())*c0/ui->doubleSpinBox_12->value();
                if(ui->checkBox_7->isChecked()){
                    a2[i]=a2[i]+ui->doubleSpinBox_9->value();
                }
                else{
                    //
                }
            }
            else{
                if(ui->checkBox_7->isChecked()){
                    a2[i]=a2[i]*(1+ui->doubleSpinBox_9->value()/c0);
                }
                else{
                    //
                }
            }

            istringstream ist2(zwei);
            ist2 >> b2[i];
            b2[i]=b2[i]+ui->doubleSpinBox_7->value()+offset*(u-min);
            }
            dat2.close();

            ui->customPlot->addGraph();
            pen2.setColor(Qt::blue);
            pen2.setWidth(ui->spinBox_4->value());
            ui->customPlot->graph()->setPen(pen2);
            ui->customPlot->graph()->setData(a2, b2);
        }}

    // plot 1 above
    if(ui->checkBox_10->isChecked()){
        QString input1=ui->lineEdit_11->text();
        string data1 = input1.toUtf8().constData();
        std::ostringstream dat1NameStream(data1);
        dat1NameStream<<seqPath<<"/"<<data1;
        std::string dat1Name = dat1NameStream.str();
        ifstream dat1(dat1Name.c_str());


        QFile checkfile(dat1Name.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input1+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
            }

        number_of_lines =0;


        while(std::getline(dat1, line))
           ++ number_of_lines;

        dat1.clear();
        dat1.seekg(0, ios::beg);

        QVector<double> a1(number_of_lines);
        QVector<double> b1(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        dat1 >> eins >>zwei;
        istringstream ist(eins);
        ist >> a1[i];
        if(ui->checkBox_17->isChecked()){
            a1[i]=log10(a1[i]);
        }
        else{
            if(ui->checkBox_19->isChecked()){
                a1[i]=pow(10,a1[i]);
            }
            else{

            }
        }
        if(ui->checkBox_13->isChecked()){
            a1[i]=(a1[i]-ui->doubleSpinBox_12->value())*c0/ui->doubleSpinBox_12->value();
            if(ui->checkBox_6->isChecked()){
                a1[i]=a1[i]+ui->doubleSpinBox_8->value();
            }
            else{
                //
            }
        }
        else{
            if(ui->checkBox_6->isChecked()){
                a1[i]=a1[i]*(1+ui->doubleSpinBox_8->value()/c0);
            }
            else{
                //
            }
        }

        istringstream ist2(zwei);
        ist2 >> b1[i];
        b1[i]=b1[i]+ui->doubleSpinBox_6->value()+offset*(max-min+1);
        }
        dat1.close();

        ui->customPlot->addGraph();
        pen2.setColor(Qt::magenta);
        pen2.setWidth(ui->spinBox_4->value());
        ui->customPlot->graph()->setPen(pen2);
        ui->customPlot->graph()->setData(a1, b1);
    }

    // plot 2 above
    if(ui->checkBox_11->isChecked()){
        QString input2=ui->lineEdit_12->text();
        string data2 = input2.toUtf8().constData();
        std::ostringstream dat2NameStream(data2);
        dat2NameStream<<seqPath<<"/"<<data2;
        std::string dat2Name = dat2NameStream.str();
        ifstream dat2(dat2Name.c_str());


        QFile checkfile(dat2Name.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input2+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
            }

        number_of_lines =0;


        while(std::getline(dat2, line))
           ++ number_of_lines;

        dat2.clear();
        dat2.seekg(0, ios::beg);

        QVector<double> a2(number_of_lines);
        QVector<double> b2(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        dat2 >> eins >>zwei;
        istringstream ist(eins);
        ist >> a2[i];
        if(ui->checkBox_18->isChecked()){
            a2[i]=log10(a2[i]);
        }
        else{
            if(ui->checkBox_20->isChecked()){
                a2[i]=pow(10,a2[i]);
            }
            else{

            }
        }

        if(ui->checkBox_13->isChecked()){
            a2[i]=(a2[i]-ui->doubleSpinBox_12->value())*c0/ui->doubleSpinBox_12->value();
            if(ui->checkBox_7->isChecked()){
                a2[i]=a2[i]+ui->doubleSpinBox_9->value();
            }
            else{
                //
            }
        }
        else{
            if(ui->checkBox_7->isChecked()){
                a2[i]=a2[i]*(1+ui->doubleSpinBox_9->value()/c0);
            }
            else{
                //
            }
        }

        istringstream ist2(zwei);
        ist2 >> b2[i];
        b2[i]=b2[i]+ui->doubleSpinBox_7->value()+offset*(max-min+1);
        }
        dat2.close();

        ui->customPlot->addGraph();
        pen3.setColor(Qt::blue);
        pen3.setWidth(ui->spinBox_4->value());
        ui->customPlot->graph()->setPen(pen3);
        ui->customPlot->graph()->setData(a2, b2);
    }

    // differences
        if(ui->checkBox_8->isChecked()){
            QString input3=ui->lineEdit_13->text();
            string data3 = input3.toUtf8().constData();
            std::ostringstream dat3NameStream(data3);
            dat3NameStream<<seqPath<<"/"<<data3;
            std::string dat3Name = dat3NameStream.str();
            ifstream dat3(dat3Name.c_str());


            QFile checkfile(dat3Name.c_str());

            if(!checkfile.exists()){
                qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input3+" does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
                }

            number_of_lines =0;
            int din=1;


            while(std::getline(dat3, line))
               ++ number_of_lines;

            dat3.clear();
            dat3.seekg(0, ios::beg);

            QVector<double> a3(number_of_lines);
            QVector<double> b3(number_of_lines);

            for (int i=0; i<number_of_lines; i++){
            dat3 >> eins >>zwei;
            istringstream ist(eins);
            ist >> a3[i];
            if(ui->checkBox_15->isChecked()){
                a3[i]=log10(a3[i]);
            }
            else{
                if(ui->checkBox_16->isChecked()){
                    a3[i]=pow(10,a3[i]);
                }
                else{

                }
            }

            if(ui->checkBox_13->isChecked()){
                a3[i]=(a3[i]-ui->doubleSpinBox_12->value())*c0/ui->doubleSpinBox_12->value();
                if(ui->checkBox_9->isChecked()){
                    a3[i]=a3[i]+ui->doubleSpinBox_11->value();
                }
                else{
                    //
                }
            }
            else{
                if(ui->checkBox_6->isChecked()){
                    a3[i]=a3[i]*(1+ui->doubleSpinBox_11->value()/c0);
                }
                else{
                    //
                }
            }

            if((i>0) & (a3[i]<a3[i-1])){
            ++din;
            }
            istringstream ist2(zwei);
            ist2 >> b3[i];
            b3[i]=b3[i]+ui->doubleSpinBox_10->value()+offset*din;
            }
            dat3.close();

            ui->customPlot->addGraph();
            pen4.setColor(Qt::green);
            pen4.setWidth(ui->spinBox_4->value());
            ui->customPlot->graph()->setPen(pen4);
            ui->customPlot->graph()->setLineStyle(QCPGraph::lsNone);
            ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
            ui->customPlot->graph()->setData(a3, b3);
        }


    ui->customPlot->xAxis->setRange(xse1, xse2);
    ui->customPlot->yAxis->setRange(yse1, yse2);
    ui->customPlot->replot();

    this->setCursor(QCursor(Qt::ArrowCursor));
}


void PlotSequ::on_doubleSpinBox_valueChanged()
{
    xse1=ui->doubleSpinBox->value();
}

void PlotSequ::on_doubleSpinBox_2_valueChanged()
{
    xse2=ui->doubleSpinBox_2->value();
}

void PlotSequ::on_doubleSpinBox_3_valueChanged()
{
    yse1=ui->doubleSpinBox_3->value();
}

void PlotSequ::on_doubleSpinBox_4_valueChanged()
{
    yse2=ui->doubleSpinBox_4->value();
}

void PlotSequ::on_lineEdit_2_editingFinished()
{
    QString xlabel=ui->lineEdit_2->text();
    ui->customPlot->xAxis->setLabel(xlabel);
}

void PlotSequ::on_lineEdit_3_editingFinished()
{
    QString ylabel=ui->lineEdit_3->text();
    ui->customPlot->yAxis->setLabel(ylabel);
}

void PlotSequ::on_pushButton_4_clicked()
{
    double iwidth = ui->lineEdit_17->text().toDouble();
    double iheight = ui->lineEdit_18->text().toDouble();

    if(ui->checkBox->isChecked()){
        QString sav=ui->lineEdit_4->text();
        QString save=qSeqPath+"/"+sav+".pdf";
        ui->customPlot->savePdf(save);
    }
    if(ui->checkBox_2->isChecked()){
        QString sav=ui->lineEdit_4->text();
        QString save=qSeqPath+"/"+sav+".png";
        ui->customPlot->savePng(save, iwidth, iheight);
    }
    if(ui->checkBox_3->isChecked()){
        QString sav=ui->lineEdit_4->text();
        QString save=qSeqPath+"/"+sav+".jpg";
        ui->customPlot->saveJpg(save, iwidth, iheight);
    }
}

void PlotSequ::on_checkBox_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
}

void PlotSequ::on_checkBox_3_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox->setChecked(false);
}

void PlotSequ::on_checkBox_2_clicked()
{
    ui->checkBox->setChecked(false);
    ui->checkBox_3->setChecked(false);
}

void PlotSequ::on_lineEdit_5_textEdited()
{
    qSeqPath=ui->lineEdit_5->text();
    seqPath=qSeqPath.toUtf8().constData();
}

void PlotSequ::on_doubleSpinBox_5_valueChanged()
{
    offset=ui->doubleSpinBox_5->value();
}

void PlotSequ::on_spinBox_3_valueChanged()
{
    QFont legendFont = font();
    legendFont.setPointSize(ui->spinBox_3->value());
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);
}

//***************************************************
// Co-Add spectra
//***************************************************
void PlotSequ::on_pushButton_5_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));

    string line, eins, zwei;
    int min=ui->spinBox->value();
    int max=ui->spinBox_2->value();
    int number_of_lines =0;

    qSeqPath=ui->lineEdit_5->text();
    seqPath=qSeqPath.toUtf8().constData();

    QString qext=ui->lineEdit_9->text();
    string sext = qext.toUtf8().constData();

    QVector<double> aad(1), bad(1), a2d(1), b2d(1);

    for (int u=min; u<=max; u++){

        if(ui->comboBox->currentIndex()==0){
        QString input=ui->lineEdit->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<seqPath<<"/"<<data<<u<<sext;
        std::string datName = datNameStream.str();
        ifstream dat(datName.c_str());


        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QString fError= QString::number(u);
            QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input+fError+qext+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
            }

        number_of_lines =0;


        while(std::getline(dat, line))
           ++ number_of_lines;

        dat.clear();
        dat.seekg(0, ios::beg);

        if(u==min){
            aad.resize(number_of_lines);
        }
        else a2d.resize(number_of_lines);
            bad.resize(number_of_lines);
            b2d.resize(number_of_lines);

        if(u==min){
            for (int i=0; i<number_of_lines; i++){
                dat >> eins >>zwei;
                istringstream ist(eins);
                ist >> aad[i];
                istringstream ist2(zwei);
                ist2 >> bad[i];
            }
        dat.close();
        }

        else {
            for (int i=0; i<number_of_lines; i++){
                dat >> eins >>zwei;
                istringstream ist(eins);
                ist >> a2d[i];
                istringstream ist2(zwei);
                ist2 >> b2d[i];
            }
            dat.close();
        }
        int aa=0;

        for(int i = 0; i<number_of_lines-1; i++){

            for(int e=aa; e<aa+5; e++){

                if(a2d[e]==aad[i]){
                    bad[i]+=b2d[e];
                    aa=e;
                }
                if((a2d[e]<aad[i])&(a2d[e+1]>aad[i])){
                    bad[i]+=b2d[e]+(aad[i]-a2d[e])/(a2d[e+1]-a2d[e])*(b2d[e+1]-b2d[e]);
                    aa=e;
                }
            }
        }


        }}

        QString input=ui->lineEdit_10->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<seqPath<<"/"<<data;
        std::string datName = datNameStream.str();

        QFile qOut(datName.c_str());

        if(qOut.exists()){
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Warning!", "The file already exists. \n\n Do you want to overwrite it?",
                                          QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::Yes) {
              qDebug() << "Yes was clicked";

            }

        else {
          qDebug() << "Yes was *not* clicked";
          this->setCursor(QCursor(Qt::ArrowCursor));
          return;
        }}

        ofstream out(datName.c_str());
        for(int i =0; i <b2d.size(); i++){
            out<<aad[i]<<" "<<bad[i]<<endl;
        }

        this->setCursor(QCursor(Qt::ArrowCursor));


}

//***************************************************
// Co-Average
//***************************************************
void PlotSequ::on_pushButton_6_clicked()
{
    // use file with file numbers to be averaged
    if(ui->checkBox_12->isChecked()){

        qSeqPath=ui->lineEdit_5->text();
        seqPath=qSeqPath.toUtf8().constData();

        QString input1=ui->lineEdit_15->text();
        string data1 = input1.toUtf8().constData();
        std::ostringstream dat1NameStream(data1);
        dat1NameStream<<seqPath<<"/"<<data1;
        std::string dat1Name = dat1NameStream.str();

        QFile checkfile(dat1Name.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File "+checkfile.fileName()+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }

        ifstream dat1(dat1Name.c_str());
        string lines, one, two;

        int number_of_ave=0;

        while(std::getline(dat1, lines))
           ++ number_of_ave;

        dat1.clear();
        dat1.seekg(0, ios::beg);
        QVector<double> otime(1);

        // use files with times to calculate mean times of averaged spectra
        if(ui->checkBox_14->isChecked()){
            QString input2=ui->lineEdit_16->text();
            string data2 = input2.toUtf8().constData();
            std::ostringstream dat2NameStream(data2);
            dat2NameStream<<seqPath<<"/"<<data2;
            std::string dat2Name = dat2NameStream.str();

            QFile checkfile2(dat2Name.c_str());

            if(!checkfile.exists()){
                qDebug()<<"The file "<<checkfile2.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error", "File "+checkfile2.fileName()+" does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
                return;
            }

            ifstream dat2(dat2Name.c_str());

            int number_of_t=0;

            while(std::getline(dat2, lines))
               ++ number_of_t;

            dat2.clear();
            dat2.seekg(0, ios::beg);
            otime.resize(number_of_t);

            for (int i=0; i<number_of_t; i++){
                dat2 >> one;
                istringstream ist(one);
                ist >> otime[i];
            }


        }
        int minave=0, maxave=0;
        double timave=0.0;

        for (int i=0; i<number_of_ave; i++){
            dat1 >> one >>two;
            istringstream ist(one);
            ist >> minave;
            istringstream ist2(two);
            ist2 >> maxave;

            ui->spinBox->setValue(minave);
            ui->spinBox_2->setValue(maxave);

            ui->lineEdit_10->setText("Average_"+QString::number(i)+".txt");

            PlotSequ::CoAverage();

            if(ui->checkBox_14->isChecked()){
                for(int e =minave; e<=maxave; e++){
                    timave+=otime[e];
                }
                cout<<setprecision(14)<<timave/(maxave-minave+1)<<endl;
                timave=0.0;
            }

        }
        dat1.close();

        QMessageBox::information(this, "Message", "Averaged spectra written to Average_*.txt.");


    }
    else{
        PlotSequ::CoAverage();
    }
}

//********************************************
// CoAverage Spectra
//********************************************
void PlotSequ::CoAverage()
{
    this->setCursor(QCursor(Qt::WaitCursor));

    string line, eins, zwei;
    int min=ui->spinBox->value();
    int max=ui->spinBox_2->value();
    int number_of_lines =0;

    QString qext=ui->lineEdit_9->text();
    string sext = qext.toUtf8().constData();

    qSeqPath=ui->lineEdit_5->text();
    seqPath=qSeqPath.toUtf8().constData();

    QVector<double> aad(1), bad(1), a2d(1), b2d(1);

    for (int u=min; u<=max; u++){

        if(ui->comboBox->currentIndex()==0){
        QString input=ui->lineEdit->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<seqPath<<"/"<<data<<u<<sext;
        std::string datName = datNameStream.str();

        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QString fError= QString::number(u);
            QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input+fError+qext+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }

        ifstream dat(datName.c_str());

        number_of_lines =0;

        while(std::getline(dat, line))
           ++ number_of_lines;

        dat.clear();
        dat.seekg(0, ios::beg);

        if(u==min){
        aad.resize(number_of_lines);
        }
        else a2d.resize(number_of_lines);
        bad.resize(number_of_lines);
        b2d.resize(number_of_lines);

        if(u==min){
            for (int i=0; i<number_of_lines; i++){
                dat >> eins >>zwei;
                istringstream ist(eins);
                ist >> aad[i];
                istringstream ist2(zwei);
                ist2 >> bad[i];
            }
        dat.close();
        }

        else {
            for (int i=0; i<number_of_lines; i++){
                dat >> eins >>zwei;
                istringstream ist(eins);
                ist >> a2d[i];
                istringstream ist2(zwei);
                ist2 >> b2d[i];
            }
            dat.close();

            int aa=0;

            for(int i = 0; i<number_of_lines-1; i++){

                for(int e=0; e<number_of_lines; e++){

                    if(a2d[e]==aad[i]){
                        bad[i]+=b2d[e];
                        e=number_of_lines;
                    }

                    if((a2d[e]<aad[i])&(a2d[e+1]>=aad[i])){
                        bad[i]+=b2d[e]+(aad[i]-a2d[e])/(a2d[e+1]-a2d[e])*(b2d[e+1]-b2d[e]);
                        e=number_of_lines;
                    }
                }
            }
         }

        }
        else{
            QMessageBox::information(this, "Error", "This function works on two-column ASCII files only.");
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }
    }

        QString input=ui->lineEdit_10->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<seqPath<<"/"<<data;
        std::string datName = datNameStream.str();

        QFile qOut(datName.c_str());

        if(ui->checkBox_12->isChecked()){
            //
        }
        else{
            if(qOut.exists()){
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Warning!", "The file already exists. \n\n Do you want to overwrite it?",
                                          QMessageBox::Yes|QMessageBox::No);
                if (reply == QMessageBox::Yes) {
                    qDebug() << "Yes was clicked";
                }

                else {
                    qDebug() << "Yes was *not* clicked";
                    this->setCursor(QCursor(Qt::ArrowCursor));
                    return;
                }
            }
        }

        ofstream out(datName.c_str());

        for(int i =0; i <b2d.size(); i++){
                out<<aad[i]<<" "<<bad[i]/(max-min+1)<<endl;
        }

        this->setCursor(QCursor(Qt::ArrowCursor));

}

//***************************************************
// median
//***************************************************
void PlotSequ::on_pushButton_7_clicked()
{
    qSeqPath=ui->lineEdit_5->text();
    seqPath=qSeqPath.toUtf8().constData();

}

void PlotSequ::on_comboBox_2_currentIndexChanged()
{
    if(ui->comboBox_2->currentIndex()==0){
        pcolor = 1;
    }
    if(ui->comboBox_2->currentIndex()==1){
        pcolor = 2;
    }
    if(ui->comboBox_2->currentIndex()==2){
        pcolor = 3;
    }
    if(ui->comboBox_2->currentIndex()==3){
        pcolor = 4;
    }
    if(ui->comboBox_2->currentIndex()==4){
        pcolor = 5;
    }
    if(ui->comboBox_2->currentIndex()==5){
        pcolor = 6;
    }
}

//***************************************************
// line moments shift window in composite spectra
//***************************************************
void PlotSequ::on_pushButton_8_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));

    QVector<double> otim(1);

    qSeqPath=ui->lineEdit_5->text();
    seqPath=qSeqPath.toUtf8().constData();

    QString input=ui->lineEdit_10->text();
    string data = input.toUtf8().constData();
    std::ostringstream datNameStream(data);
    datNameStream<<seqPath<<"/"<<data;
    std::string datName = datNameStream.str();

    QFile qOut(datName.c_str());

    if(qOut.exists()){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Warning!", "The file "+input+" already exists. \n\n Do you want to overwrite it?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
          qDebug() << "Yes was clicked";
        }

    else {
      qDebug() << "Yes was *not* clicked";
      this->setCursor(QCursor(Qt::ArrowCursor));
      return;
    }}

    ofstream out(datName.c_str());

    string line, eins, zwei;
    int min=ui->spinBox->value();
    int max=ui->spinBox_2->value();

    int number_of_lines =0;

    double loww = ui->doubleSpinBox->value();
    double hiw = ui->doubleSpinBox_2->value(), EW=0, sum=0, mom1=0, mom2=0, Cont=0;
    int numb=0;

    QString qext=ui->lineEdit_9->text();
    string sext = qext.toUtf8().constData();

    QVector<double> aad(1), bad(1), rv1(1), rv2(1);

    if(ui->checkBox_12->isChecked()){

        QString qrvel=ui->lineEdit_15->text();
        string rvel = qrvel.toUtf8().constData();
        std::ostringstream dat3NameStream(rvel);
        dat3NameStream<<seqPath<<"/"<<rvel;
        std::string dat3Name = dat3NameStream.str();
        ifstream RVel(dat3Name.c_str());


        QFile checkfile(dat3Name.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File "+qSeqPath+"\t"+qrvel+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
            }

        int nrvel=0;

        while(std::getline(RVel, line))
           ++ nrvel;

        RVel.clear();
        RVel.seekg(0, ios::beg);

        rv1.resize(nrvel);
        rv2.resize(nrvel);

        for (int i=0; i<nrvel; i++){
        RVel >> eins >>zwei;
        istringstream ist(eins);
        ist >> rv1[i];
        istringstream ist2(zwei);
        ist2 >> rv2[i];
        }
        RVel.close();

    }
    else{
        //
    }

    if(ui->checkBox_12->isChecked()){
        double ldw=ui->doubleSpinBox_14->value();
        double udw=ui->doubleSpinBox_13->value();

        out<<"Shift by given Rvs and integrate; -"<<ldw<<":+"<<udw<<endl;
    }
    else{
        double ldw=ui->doubleSpinBox_14->value();
        double udw=ui->doubleSpinBox_13->value();

        out<<"Looking for minimum in ["<<loww<<":"<<hiw<<"], compute line center, shift, and integrate -"<<ldw<<":+"<<udw<<endl;
    }

    for (int u=min; u<=max; u++){


        EW=0;
        sum=0;
        Cont=0;
        mom1=0;
        mom2=0;

        if(ui->comboBox->currentIndex()==0){


            QString input=ui->lineEdit->text();
            string data = input.toUtf8().constData();
            std::ostringstream datNameStream(data);
            datNameStream<<seqPath<<"/"<<data<<u<<sext;
            string datName = datNameStream.str();

            QFile checkfile(datName.c_str());

            if(!checkfile.exists()){
                qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input+" does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
                return;
            }
            ifstream dat(datName.c_str());

            number_of_lines =0;

            while(std::getline(dat, line))
                ++ number_of_lines;

            dat.clear();
            dat.seekg(0, ios::beg);

            aad.resize(number_of_lines);
            bad.resize(number_of_lines);

            for (int i=0; i<number_of_lines; i++){
                dat >> eins >>zwei;
                istringstream ist(eins);
                ist >> aad[i];
                istringstream ist2(zwei);
                ist2 >> bad[i];
            }
            dat.close();
        }

        if(ui->comboBox->currentIndex()==1){
            QString input=ui->lineEdit->text();
            string data = input.toUtf8().constData();
            std::ostringstream datNameStream(data);
            datNameStream<<seqPath<<"/"<<data<<u<<sext;
            std::string datName = datNameStream.str();

            QFile checkfile1(datName.c_str());

            if(!checkfile1.exists()){
                qDebug()<<"Error 1: The file "<<checkfile1.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error1 ", "Error 1: File "+checkfile1.fileName()+" does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
                //check=1;
               return;
            }

            CCfits::FITS::setVerboseMode(true);

            try
            {

                //open file for reading
                shared_ptr<CCfits::FITS> input_file(new CCfits::FITS(datName.c_str(),CCfits::Read,true));

                // Create pointer to extension
                    CCfits::ExtHDU& datavector = input_file->extension(seExtension);

                  // Read rows
                  CCfits::Column& column = datavector.column(seWavecol);
                  column.read(sewave, 1, column.rows());

                  // Read rows
                  CCfits::Column& column2 = datavector.column(seIntenscol);
                  column2.read(seintens, 1, column2.rows());

                  number_of_lines=sewave.size();

                  aad.resize(number_of_lines);
                  bad.resize(number_of_lines);

                  for(int i=0; i<number_of_lines; i++){
                  bad[i]=seintens[i];
                  aad[i]=sewave[i];
                  }


            }
                catch (CCfits::FitsException&)

                 {
                  std::cerr << " Fits Exception Thrown by test function \n";
                  }


               // return;

        }

        if(ui->checkBox_14->isChecked()){
            QString qTim=ui->lineEdit_16->text();
            string tim = qTim.toUtf8().constData();
            std::ostringstream timNameStream(tim);
            timNameStream<<seqPath<<"/"<<tim;
            std::string timName = timNameStream.str();

            QFile checkfile(timName.c_str());

            if(!checkfile.exists()){
                qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error", "File "+qSeqPath+"\t"+qTim+" does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
                return;
            }
            ifstream Tim(timName.c_str());

            int tlines=0;

            while(std::getline(Tim, line))
               ++ tlines;

            Tim.clear();
            Tim.seekg(0, ios::beg);

            otim.resize(tlines);

            for(int i =0; i<tlines; i++){
                Tim>>eins;
                istringstream ist(eins);
                ist >> otim[i];
            }
            Tim.close();

        }

        // use given wavelengths, shift by given RVs and integrate
        if(ui->checkBox_12->isChecked()){

            QString qlines=ui->lineEdit_14->text();
            string lines = qlines.toUtf8().constData();
            std::ostringstream dat2NameStream(lines);
            dat2NameStream<<seqPath<<"/"<<lines;
            std::string dat2Name = dat2NameStream.str();

            QFile checkfile(datName.c_str());

            if(!checkfile.exists()){
                qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error", "File "+qSeqPath+"\t"+qlines+" does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
                return;
            }

            ifstream Lines(dat2Name.c_str());

            int nlines=0;

            while(std::getline(Lines, line))
               ++ nlines;

            Lines.clear();
            Lines.seekg(0, ios::beg);

            QVector<double> lcw(nlines), lw(nlines);

            for (int i=0; i<nlines; i++){
            Lines >> eins >>zwei;
            istringstream ist(eins);
            ist >> lcw[i];      // central rest wavelengths
            istringstream ist2(zwei);
            ist2 >> lw[i];      // half width of integration intervall
            }
            Lines.close();

            double lc1, lc2, loww1, loww2, hiw1, hiw2;

            for (int i=0; i<nlines; i++){

                lc1=lcw[i]*(1+rv1[u]/c0);   // central wavelength shifted by RV
                lc2=lcw[i]*(1+rv2[u]/c0);
                loww1 = lc1-lw[i];          // lowwer wavelegth shifted by RV
                loww2 = lc2-lw[i];
                hiw1 = lc1+lw[i];           // upper wavelength shifted by RV
                hiw2 = lc2+lw[i];
                numb=0;

                for(int i =0; i<number_of_lines; i++){
                    if((aad[i]>loww1) & (aad[i]<hiw1)){
                        ++numb;
                    }
                    else{
                        //
                    }
                }

                QVector<double> aad2(numb), bad2(numb);
                numb = 0;

                for(int i =0; i<number_of_lines; i++){
                    if((aad[i]>loww1) & (aad[i]<hiw1)){

                        aad2[numb]=aad[i];
                        bad2[numb]=bad[i];
                        ++numb;
                    }
                }

                EW=0;
                sum=0;
                mom1=0;
                mom2=0;
                Cont=0;

                double ykl=0, ygr=0, xkl=0, xgr=0, ab=0;

                for(int i =0 ; i<10; i++){
                    ykl += bad2[i];
                    ygr += bad2[numb-i-1];
                    xkl += aad2[i];
                    xgr += aad2[numb-i-1];
                }
                ykl = ykl/10;
                ygr = ygr/10;
                xkl = xkl/10;
                xgr = xgr/10;

                double steig = (ygr-ykl)/(xgr-xkl);

                for(int i =1; i<aad2.size(); i++){
                    Cont = ykl+(aad2[i]-xkl)*steig;
                    sum+=bad2[i];
                    EW += (Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]);
                    mom1 += ((Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]))*aad2[i];
                    mom2 += ((Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]))*aad2[i]*aad2[i];
                }
                mom1 = mom1/EW;
                mom2 = mom2/EW;


                // add times to the output file
                if(ui->checkBox_14->isChecked()){
                    out<<setprecision(14)<<otim[i]<<"\t"<<lc1<<"\t"<<sum<<"\t"<<EW<<"\t"<<mom1<<"\t"<<mom2<<"\t";
                }
                else{
                    out<<lc1<<"\t"<<sum<<"\t"<<EW<<"\t"<<mom1<<"\t"<<mom2<<"\t";
                }
                numb=0;

                for(int i =0; i<number_of_lines; i++){
                    if((aad[i]>loww2) & (aad[i]<hiw2)){
                        ++numb;
                    }
                    else{
                        //
                    }
                }

                aad2.resize(numb);
                bad2.resize(numb);
                numb = 0;

                for(int i =0; i<number_of_lines; i++){
                    if((aad[i]>loww2) & (aad[i]<hiw2)){

                        aad2[numb]=aad[i];
                        bad2[numb]=bad[i];
                        ++numb;
                    }
                }

                EW=0;
                sum=0;
                mom1=0;
                mom2=0;
                Cont=0;

                ykl=0;
                ygr=0;
                xkl=0;
                xgr=0;

                for(int i =0 ; i<10; i++){
                    ykl += bad2[i];
                    ygr += bad2[numb-i-1];
                    xkl += aad2[i];
                    xgr += aad2[numb-i-1];
                }
                ykl = ykl/10;
                ygr = ygr/10;
                xkl = xkl/10;
                xgr = xgr/10;

                steig = (ygr-ykl)/(xgr-xkl);

                for(int i =1; i<aad2.size(); i++){
                    Cont = ykl+(aad2[i]-xkl)*steig;
                    sum+=bad2[i];
                    EW += (Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]);
                    mom1 += ((Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]))*aad2[i];
                    mom2 += ((Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]))*aad2[i]*aad2[i];
                }
                mom1 = mom1/EW;
                mom2 = mom2/EW;


                    out<<lc1<<"\t"<<sum<<"\t"<<EW<<"\t"<<mom1<<"\t"<<mom2<<"\t";


            }

            out<<endl;

        }

        // look for minimum, compute line center, shift and integrate
        else{

            double cmw=loww, imin=100, loww2, hiw2;
            for(int i =1; i<number_of_lines; i++){

            if((aad[i]>=loww) & (aad[i]<=hiw)){

                    if(bad[i]<imin){
                        imin=bad[i];
                        cmw = aad[i];
                    }
                    else{
                        //
                    }

            }
            else{
                //
                //
            }
        }

        loww2 = cmw-ui->doubleSpinBox_14->value();
        hiw2 = cmw + ui->doubleSpinBox_13->value();
        cout<<loww2<<"\t"<<cmw<<"\t"<<hiw2<<endl;
        numb=0;

        for(int i =0; i<number_of_lines; i++){
            if((aad[i]>loww2) & (aad[i]<hiw2)){
                ++numb;
            }
            else{
                //
            }
        }

        QVector<double> aad2(numb), bad2(numb);
        numb = 0;

        for(int i =0; i<number_of_lines; i++){
            if((aad[i]>loww2) & (aad[i]<hiw2)){

                aad2[numb]=aad[i];
                bad2[numb]=bad[i];
                ++numb;
            }
        }

        mom1 = 0;
        mom2 = 0;
        EW=0;
        Cont=0;
        sum=0;

        double ykl=0, ygr=0, xkl=0, xgr=0;

        for(int i =0 ; i<10; i++){
            ykl += bad2[i];
            ygr += bad2[numb-i-1];
            xkl += aad2[i];
            xgr += aad2[numb-i-1];
        }
        ykl = ykl/10;
        ygr = ygr/10;
        xkl = xkl/10;
        xgr = xgr/10;

        double steig = (ygr-ykl)/(xgr-xkl);

        for(int i =1; i<aad2.size(); i++){
            Cont = ykl+(aad2[i]-xkl)*steig;
            sum+=bad2[i];
            EW += (Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]);
            mom1 += ((Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]))*aad2[i];
            mom2 += ((Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]))*aad2[i]*aad2[i];
        }
        mom1 = mom1/EW;
        mom2 = mom2/EW;

        cmw=mom1;

        loww2 = cmw-ui->doubleSpinBox_14->value();
        hiw2 = cmw + ui->doubleSpinBox_13->value();
        cout<<loww2<<"\t"<<cmw<<"\t"<<hiw2<<endl;
        numb=0;

        for(int i =0; i<number_of_lines; i++){
            if((aad[i]>loww2) & (aad[i]<hiw2)){
                ++numb;
            }
            else{
                //
            }
        }

        aad2.resize(numb);
        bad2.resize(numb);
        numb = 0;

        for(int i =0; i<number_of_lines; i++){
            if((aad[i]>loww2) & (aad[i]<hiw2)){

                aad2[numb]=aad[i];
                bad2[numb]=bad[i];
                ++numb;
            }
        }

        mom1 = 0;
        mom2 = 0;
        EW=0;
        Cont=0;
        sum=0;

        ykl=0;
        ygr=0;
        xkl=0;
        xgr=0;

        for(int i =0 ; i<10; i++){
            ykl += bad2[i];
            ygr += bad2[numb-i-1];
            xkl += aad2[i];
            xgr += aad2[numb-i-1];
        }
        ykl = ykl/10;
        ygr = ygr/10;
        xkl = xkl/10;
        xgr = xgr/10;

        steig = (ygr-ykl)/(xgr-xkl);

        for(int i =1; i<aad2.size(); i++){
            Cont = ykl+(aad2[i]-xkl)*steig;
            sum+=bad2[i];
            EW += (Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]);
            mom1 += ((Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]))*aad2[i];
            mom2 += ((Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]))*aad2[i]*aad2[i];
        }
        mom1 = mom1/EW;
        mom2 = mom2/EW;

        if(ui->checkBox_14->isChecked()){
            out<<setprecision(14)<<otim[u]<<"\t"<<sum<<"\t"<<EW<<"\t"<<mom1<<"\t"<<mom2<<endl;
        }
        else{
            out<<sum<<"\t"<<EW<<"\t"<<mom1<<"\t"<<mom2<<endl;
        }
        }

    }

    if(ui->checkBox_4->isChecked() or ui->checkBox_10->isChecked()){

        EW=0;
        sum=0;
        mom1=0;
        mom2=0;
        Cont=0;

        QString input=ui->lineEdit_11->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<seqPath<<"/"<<data;
        string datName = datNameStream.str();

        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }
        ifstream dat(datName.c_str());

        number_of_lines =0;

        while(std::getline(dat, line))
            ++ number_of_lines;

        dat.clear();
        dat.seekg(0, ios::beg);

        aad.resize(number_of_lines);
        bad.resize(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
            dat >> eins >>zwei;
            istringstream ist(eins);
            ist >> aad[i];
            istringstream ist2(zwei);
            ist2 >> bad[i];
        }
        dat.close();

        if(ui->checkBox_6->isChecked()){
            double rvA = ui->doubleSpinBox_8->value();
            loww= loww*(1+rvA/c0);
            hiw = hiw*(1+rvA/c0);
        }

        double cmw=loww, imin=100, loww2, hiw2;


    for(int i =1; i<number_of_lines; i++){

        if((aad[i]>=loww) & (aad[i]<=hiw)){

                if(bad[i]<imin){
                    imin=bad[i];
                    cmw = aad[i];
                }
                else{
                    //
                }

        }
        else{
            //
            //
        }
    }

    loww2 = cmw-ui->doubleSpinBox_14->value();
    hiw2 = cmw + ui->doubleSpinBox_13->value();
    cout<<loww2<<"\t"<<cmw<<"\t"<<hiw2<<endl;
    numb=0;

    for(int i =0; i<number_of_lines; i++){
        if((aad[i]>loww2) & (aad[i]<hiw2)){
            ++numb;
        }
        else{
            //
        }
    }

    QVector<double> aad2(numb), bad2(numb);
    numb = 0;

    for(int i =0; i<number_of_lines; i++){
        if((aad[i]>loww2) & (aad[i]<hiw2)){

            aad2[numb]=aad[i];
            bad2[numb]=bad[i];
            ++numb;
        }
    }

    double ykl=0, ygr=0, xkl=0, xgr=0;

    for(int i =0 ; i<10; i++){
        ykl += bad2[i];
        ygr += bad2[numb-i-1];
        xkl += aad2[i];
        xgr += aad2[numb-i-1];
    }
    ykl = ykl/10;
    ygr = ygr/10;
    xkl = xkl/10;
    xgr = xgr/10;

    double steig = (ygr-ykl)/(xgr-xkl);

    for(int i =1; i<aad2.size(); i++){
        Cont = ykl+(aad2[i]-xkl)*steig;
        sum+=bad2[i];
        EW += (Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]);
        mom1 += ((Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]))*aad2[i];
        mom2 += ((Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]))*aad2[i]*aad[i];
    }
    mom1 = mom1/EW;
    mom2 = mom2/EW;

    cmw=mom1;

    loww2 = cmw-ui->doubleSpinBox_14->value();
    hiw2 = cmw + ui->doubleSpinBox_13->value();
    cout<<loww2<<"\t"<<cmw<<"\t"<<hiw2<<endl;
    numb=0;

    for(int i =0; i<number_of_lines; i++){
        if((aad[i]>loww2) & (aad[i]<hiw2)){
            ++numb;
        }
        else{
            //
        }
    }

    aad2.resize(numb);
    bad2.resize(numb);
    numb = 0;

    for(int i =0; i<number_of_lines; i++){
        if((aad[i]>loww2) & (aad[i]<hiw2)){

            aad2[numb]=aad[i];
            bad2[numb]=bad[i];
            ++numb;
        }
    }

    mom1 = 0;
    mom2 = 0;
    EW=0;
    Cont=0;
    sum=0;

    ykl=0;
    ygr=0;
    xkl=0;
    xgr=0;

    for(int i =0 ; i<10; i++){
        ykl += bad2[i];
        ygr += bad2[numb-i-1];
        xkl += aad2[i];
        xgr += aad2[numb-i-1];
    }
    ykl = ykl/10;
    ygr = ygr/10;
    xkl = xkl/10;
    xgr = xgr/10;

    steig = (ygr-ykl)/(xgr-xkl);

    for(int i =1; i<aad2.size(); i++){
        Cont = ykl+(aad2[i]-xkl)*steig;
        sum+=bad2[i];
        EW += (Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]);
        mom1 += ((Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]))*aad2[i];
        mom2 += ((Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]))*aad2[i]*aad2[i];
    }
    mom1 = mom1/EW;
    mom2 = mom2/EW;


    if(ui->checkBox_14->isChecked()){
        out<<"NaN"<<"\t"<<EW<<"\t"<<sum<<"\t"<<mom1<<"\t"<<mom2<<endl;
    }
    else{
        out<<EW<<"\t"<<sum<<"\t"<<mom1<<"\t"<<mom2<<endl;
    }

    }

    if(ui->checkBox_5->isChecked() or ui->checkBox_11->isChecked()){

        EW=0;
        sum=0;
        mom1=0;
        mom2=0;
        Cont=0;

        QString input=ui->lineEdit_12->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<seqPath<<"/"<<data;
        string datName = datNameStream.str();

        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }
        ifstream dat(datName.c_str());

        number_of_lines =0;

        while(std::getline(dat, line))
            ++ number_of_lines;

        dat.clear();
        dat.seekg(0, ios::beg);

        aad.resize(number_of_lines);
        bad.resize(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
            dat >> eins >>zwei;
            istringstream ist(eins);
            ist >> aad[i];
            istringstream ist2(zwei);
            ist2 >> bad[i];
        }
        dat.close();

        if(ui->checkBox_7->isChecked()){
            double rvB = ui->doubleSpinBox_9->value();
            loww= loww*(1+rvB/c0);
            hiw = hiw*(1+rvB/c0);
        }

        double cmw=loww, imin=100, loww2, hiw2;
    for(int i =1; i<number_of_lines; i++){

        if((aad[i]>=loww) & (aad[i]<=hiw)){

                if(bad[i]<imin){
                    imin=bad[i];
                    cmw = aad[i];
                }
                else{
                    //
                }

        }
        else{
            //
            //
        }
    }

    loww2 = cmw-ui->doubleSpinBox_14->value();
    hiw2 = cmw + ui->doubleSpinBox_13->value();
    cout<<loww2<<"\t"<<cmw<<"\t"<<hiw2<<endl;
    numb=0;

    for(int i =0; i<number_of_lines; i++){
        if((aad[i]>loww2) & (aad[i]<hiw2)){
            ++numb;
        }
        else{
            //
        }
    }

    QVector<double> aad2(numb), bad2(numb);
    numb = 0;

    for(int i =0; i<number_of_lines; i++){
        if((aad[i]>loww2) & (aad[i]<hiw2)){

            aad2[numb]=aad[i];
            bad2[numb]=bad[i];
            ++numb;
        }
    }

    double ykl=0, ygr=0, xkl=0, xgr=0;

    for(int i =0 ; i<10; i++){
        ykl += bad2[i];
        ygr += bad2[numb-i-1];
        xkl += aad2[i];
        xgr += aad2[numb-i-1];
    }
    ykl = ykl/10;
    ygr = ygr/10;
    xkl = xkl/10;
    xgr = xgr/10;

    double steig = (ygr-ykl)/(xgr-xkl);

    for(int i =1; i<aad2.size(); i++){
        Cont = ykl+(aad2[i]-xkl)*steig;
        sum+=bad2[i];
        EW += (Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]);
        mom1 += ((Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]))*aad2[i];
        mom2 += ((Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]))*aad2[i]*aad2[i];
    }
    mom1 = mom1/EW;
    mom2 = mom2/EW;

    cmw=mom1;

    loww2 = cmw-ui->doubleSpinBox_14->value();
    hiw2 = cmw + ui->doubleSpinBox_13->value();
    cout<<loww2<<"\t"<<cmw<<"\t"<<hiw2<<endl;
    numb=0;

    for(int i =0; i<number_of_lines; i++){
        if((aad[i]>loww2) & (aad[i]<hiw2)){
            ++numb;
        }
        else{
            //
        }
    }

    aad2.resize(numb);
    bad2.resize(numb);
    numb = 0;

    for(int i =0; i<number_of_lines; i++){
        if((aad[i]>loww2) & (aad[i]<hiw2)){

            aad2[numb]=aad[i];
            bad2[numb]=bad[i];
            ++numb;
        }
    }

    mom1 = 0;
    mom2 = 0;
    EW=0;
    Cont=0;
    sum=0;

    ykl=0;
    ygr=0;
    xkl=0;
    xgr=0;

    for(int i =0 ; i<10; i++){
        ykl += bad2[i];
        ygr += bad2[numb-i-1];
        xkl += aad2[i];
        xgr += aad2[numb-i-1];
    }
    ykl = ykl/10;
    ygr = ygr/10;
    xkl = xkl/10;
    xgr = xgr/10;

    steig = (ygr-ykl)/(xgr-xkl);

    for(int i =1; i<aad2.size(); i++){
        Cont = ykl+(aad2[i]-xkl)*steig;
        sum+=bad2[i];
        EW += (Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]);
        mom1 += ((Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]))*aad2[i];
        mom2 += ((Cont-(bad2[i-1]+bad2[i])/2)*(aad2[i]-aad2[i-1]))*aad2[i]*aad2[i];
    }
    mom1 = mom1/EW;
    mom2 = mom2/EW;

    if(ui->checkBox_14->isChecked()){
        out<<"NaN"<<"\t"<<sum<<"\t"<<EW<<"\t"<<sum<<"\t"<<mom1<<"\t"<<mom2<<endl;
    }
    else{
        out<<sum<<"\t"<<EW<<"\t"<<sum<<"\t"<<mom1<<"\t"<<mom2<<endl;
    }

    }

    out.close();

    this->setCursor(QCursor(Qt::ArrowCursor));

}

//*************************************************
// bisector
//*************************************************
void PlotSequ::on_pushButton_9_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));

    qSeqPath=ui->lineEdit_5->text();
    seqPath=qSeqPath.toUtf8().constData();

    QString input=ui->lineEdit_10->text();
    string data = input.toUtf8().constData();

    string line, eins, zwei;
    int min=ui->spinBox->value();
    int max=ui->spinBox_2->value();
    int number_of_lines =0;

    double loww = ui->doubleSpinBox->value();
    double hiw = ui->doubleSpinBox_2->value();
    double plus = ui->doubleSpinBox_13->value();

    QString qext=ui->lineEdit_9->text();
    string sext = qext.toUtf8().constData();

    QVector<double> aad(1), bad(1);
    vector<pair<double, double>> xy(4);
    vector<double> xs(4), ys(4);
    tk::spline s;
    int splinerror=0;

    for (int u=min; u<=max; u++){

        std::ostringstream datNameStream(data);
        datNameStream<<seqPath<<"/"<<data<<"_"<<u<<sext;
        std::string datName = datNameStream.str();

        QFile qOut(datName.c_str());

        if(qOut.exists()){
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Warning!", "The file "+input+" already exists. \n\n Do you want to overwrite it?",
                                          QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::Yes) {
              qDebug() << "Yes was clicked";
            }

        else {
          qDebug() << "Yes was *not* clicked";
          this->setCursor(QCursor(Qt::ArrowCursor));
          return;
        }
        }

        ofstream out(datName.c_str());

    if(ui->comboBox->currentIndex()==0){
        QString input=ui->lineEdit->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<seqPath<<"/"<<data<<u<<sext;
        std::string datName = datNameStream.str();
        ifstream dat(datName.c_str());


        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }

        number_of_lines =0;

        while(std::getline(dat, line))
            ++ number_of_lines;

        dat.clear();
        dat.seekg(0, ios::beg);

        aad.resize(number_of_lines);
        bad.resize(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
            dat >> eins >>zwei;
            istringstream ist(eins);
            ist >> aad[i];
            istringstream ist2(zwei);
            ist2 >> bad[i];
        }
        dat.close();
    }

    if(ui->comboBox->currentIndex()==1){
        QString input=ui->lineEdit->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<seqPath<<"/"<<data<<u<<sext;
        std::string datName = datNameStream.str();

        QFile checkfile1(datName.c_str());

        if(!checkfile1.exists()){
            qDebug()<<"Error 1: The file "<<checkfile1.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error1 ", "Error 1: File "+checkfile1.fileName()+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
            //check=1;
           return;
        }

        CCfits::FITS::setVerboseMode(true);

        try
        {

            //open file for reading
            shared_ptr<CCfits::FITS> input_file(new CCfits::FITS(datName.c_str(),CCfits::Read,true));

            // Create pointer to extension
                CCfits::ExtHDU& datavector = input_file->extension(seExtension);

              // Read rows
              CCfits::Column& column = datavector.column(seWavecol);
              column.read(sewave, 1, column.rows());

              // Read rows
              CCfits::Column& column2 = datavector.column(seIntenscol);
              column2.read(seintens, 1, column2.rows());

              number_of_lines=sewave.size();

              aad.resize(number_of_lines);
              bad.resize(number_of_lines);

              for(int i=0; i<number_of_lines; i++){
              bad[i]=seintens[i];
              aad[i]=sewave[i];
              }


        }
            catch (CCfits::FitsException&)

             {
              std::cerr << " Fits Exception Thrown by test function \n";
              }


           // return;

    }

        double cmw=loww, imin=100, loww2, hiw2;
        int minI, count=0;

        for(int i =1; i<number_of_lines; i++){
            if((aad[i]>=loww) & (aad[i]<=hiw)){

                if(bad[i]<imin){
                    imin = bad[i];
                    cmw = aad[i];
                    minI = i;
                }
                else{
                    imin = imin;
                }

                }
            else{
                cmw=cmw;
                imin = imin;
            }
        }
        loww2=cmw;

        double lowI2 = bad[minI];
        double higI2 = bad[minI];
        double m=0, b=0, xx;


        for(int i=0; i<number_of_lines; i++){
            if(aad[minI-i]>=cmw-plus){

                if(i==0){
                    out<<setprecision(8)<<cmw<<"\t"<<cmw-cmw<<"\t0\t"<<cmw<<"\t"<<cmw-cmw<<"\t0\t"<<lowI2<<endl;
                }
                else{
                    loww2=aad[minI-i];
                    lowI2=bad[minI-i];
                    for(int e=0; e<number_of_lines; e++){
                        if((bad[minI+e]<=lowI2) & (bad[minI+e+1]>lowI2)){
                            m=(bad[minI+e+1]-bad[minI+e])/(aad[minI+e+1]-aad[minI+e]);
                            b=bad[minI+e]-m*aad[minI+e];
                            xx=(lowI2-b)/m;
                            out<<(xx+aad[minI-i])/2<<"\t"<<(xx+aad[minI-i])/2-cmw<<"\t"<<((xx+aad[minI-i])/2-cmw)/cmw*c0<<"\t";
                            xy[0].first=bad[minI+e-1];
                            xy[1].first=bad[minI+e];
                            xy[2].first=bad[minI+e+1];
                            xy[3].first=bad[minI+e+2];

                            xy[0].second=aad[minI+e-1];
                            xy[1].second=aad[minI+e];
                            xy[2].second=aad[minI+e+1];
                            xy[3].second=aad[minI+e+2];

                            cout<<xy[0].first<<"\t"<<xy[0].second<<endl;
                            cout<<xy[1].first<<"\t"<<xy[1].second<<endl;
                            cout<<xy[2].first<<"\t"<<xy[2].second<<endl;
                            cout<<xy[3].first<<"\t"<<xy[3].second<<endl;

                            sort(xy.begin(), xy.end());
                            cout<<endl;

                            cout<<xy[0].first<<"\t"<<xy[0].second<<endl;
                            cout<<xy[1].first<<"\t"<<xy[1].second<<endl;
                            cout<<xy[2].first<<"\t"<<xy[2].second<<endl;
                            cout<<xy[3].first<<"\t"<<xy[3].second<<endl;

                            xs[0]=xy[0].first;
                            xs[1]=xy[1].first;
                            xs[2]=xy[2].first;
                            xs[3]=xy[3].first;

                            ys[0]=xy[0].second;
                            ys[1]=xy[1].second;
                            ys[2]=xy[2].second;
                            ys[3]=xy[3].second;

                            if((xs[0]==xs[1]) or (xs[0]==xs[2]) or (xs[0]==xs[3]) or (xs[1]==xs[2]) or (xs[1]==xs[3]) or (xs[3]==xs[2])){
                                out<<"Nan\tNan\tNan\t"<<lowI2<<endl;
                                splinerror=1;
                            }
                            else{
                                s.set_points(xs,ys);
                                xx=s(lowI2);
                                out<<(xx+aad[minI-i])/2<<"\t"<<(xx+aad[minI-i])/2-cmw<<"\t"<<((xx+aad[minI-i])/2-cmw)/cmw*c0<<"\t"<<lowI2<<endl;
                            }

                            e=number_of_lines;
                        }
                        else{
                            //
                        }
                    }
                }

            }
            else{
                if(aad[minI-i]<cmw-plus){
                    i=number_of_lines;
                }
                else{
                    //
                }
            }
        }

        out<<endl;

        loww2=cmw;
        lowI2=bad[minI];

        for(int i=0; i<number_of_lines; i++){
            if(aad[minI+i]<=cmw+plus){

                if(i==0){
                    out<<setprecision(8)<<cmw<<"\t"<<cmw-cmw<<"\t0\t"<<cmw<<"\t"<<cmw-cmw<<"\t0\t"<<lowI2<<endl;
                }
                else{
                    loww2=aad[minI+i];
                    lowI2=bad[minI+i];
                    for(int e=0; e<number_of_lines; e++){
                        if((bad[minI-e]>=lowI2) & (bad[minI-e+1]<lowI2)){
                            m=(bad[minI-e+1]-bad[minI-e])/(aad[minI-e+1]-aad[minI-e]);
                            b=bad[minI-e]-m*aad[minI-e];
                            xx=(lowI2-b)/m;
                            out<<(xx+aad[minI+i])/2<<"\t"<<(xx+aad[minI+i])/2-cmw<<"\t"<<((xx+aad[minI+i])/2-cmw)/cmw*c0<<"\t";
                            xy[0].first=bad[minI-e-1];
                            xy[1].first=bad[minI-e];
                            xy[2].first=bad[minI-e+1];
                            xy[3].first=bad[minI-e+2];

                            xy[0].second=aad[minI-e-1];
                            xy[1].second=aad[minI-e];
                            xy[2].second=aad[minI-e+1];
                            xy[3].second=aad[minI-e+2];

                            cout<<xy[0].first<<"\t"<<xy[0].second<<endl;
                            cout<<xy[1].first<<"\t"<<xy[1].second<<endl;
                            cout<<xy[2].first<<"\t"<<xy[2].second<<endl;
                            cout<<xy[3].first<<"\t"<<xy[3].second<<endl;

                            sort(xy.begin(), xy.end());
                            cout<<endl;

                            cout<<xy[0].first<<"\t"<<xy[0].second<<endl;
                            cout<<xy[1].first<<"\t"<<xy[1].second<<endl;
                            cout<<xy[2].first<<"\t"<<xy[2].second<<endl;
                            cout<<xy[3].first<<"\t"<<xy[3].second<<endl;

                            xs[0]=xy[0].first;
                            xs[1]=xy[1].first;
                            xs[2]=xy[2].first;
                            xs[3]=xy[3].first;

                            ys[0]=xy[0].second;
                            ys[1]=xy[1].second;
                            ys[2]=xy[2].second;
                            ys[3]=xy[3].second;

                            if((xs[0]==xs[1]) or (xs[0]==xs[2]) or (xs[0]==xs[3]) or (xs[1]==xs[2]) or (xs[1]==xs[3]) or (xs[3]==xs[2])){
                                out<<"Nan\tNan\tNan\t"<<lowI2<<endl;
                                splinerror=1;
                            }
                            else{
                                s.set_points(xs,ys);
                                xx=s(lowI2);
                                out<<(xx+aad[minI+i])/2<<"\t"<<(xx+aad[minI+i])/2-cmw<<"\t"<<((xx+aad[minI+i])/2-cmw)/cmw*c0<<"\t"<<lowI2<<endl;
                            }

                            e=number_of_lines;
                        }
                        else{
                            //
                        }
                    }
                }

            }
            else{
                if(aad[minI-i]<cmw-plus){
                    i=number_of_lines;
                }
                else{
                    //
                }
            }
        }

        out.close();
    }
    if(ui->checkBox_4->isChecked() or ui->checkBox_10->isChecked()){

        input=ui->lineEdit_10->text();
        data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<seqPath<<"/"<<data<<"_A_"<<sext;
        std::string datName = datNameStream.str();

        QFile qOut(datName.c_str());

        if(qOut.exists()){
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Warning!", "The file "+input+" already exists. \n\n Do you want to overwrite it?",
                                          QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::Yes) {
              qDebug() << "Yes was clicked";
            }

            else {
                qDebug() << "Yes was *not* clicked";
                this->setCursor(QCursor(Qt::ArrowCursor));
                return;
            }
        }

        ofstream out(datName.c_str());

        QString input=ui->lineEdit_11->text();
        string data = input.toUtf8().constData();
        std::ostringstream dat2NameStream(data);
        dat2NameStream<<seqPath<<"/"<<data;
        std::string dat2Name = dat2NameStream.str();
        ifstream dat(dat2Name.c_str());


        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }

        number_of_lines =0;

        while(std::getline(dat, line))
            ++ number_of_lines;

        dat.clear();
        dat.seekg(0, ios::beg);

        aad.resize(number_of_lines);
        bad.resize(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
            dat >> eins >>zwei;
            istringstream ist(eins);
            ist >> aad[i];
            istringstream ist2(zwei);
            ist2 >> bad[i];
        }
        dat.close();

        if(ui->checkBox_6->isChecked()){
            double rvA = ui->doubleSpinBox_8->value();
            loww= loww*(1+rvA/c0);
            hiw = hiw*(1+rvA/c0);
        }

        double cmw=loww, imin=100, loww2, hiw2;
        int minI=1, count=0;

        for(int i =1; i<number_of_lines; i++){
            if((aad[i]>=loww) & (aad[i]<=hiw)){

                if(bad[i]<imin){
                    imin = bad[i];
                    cmw = aad[i];
                    minI = i;
                }
                else{
                    imin = imin;
                }

                }
            else{
                cmw=cmw;
                imin = imin;
            }
        }

        double lowI2 = bad[minI];
        double higI2 = bad[minI];

        for(int i=0;i < number_of_lines-1; i++){
            if(lowI2<=0.45){
            lowI2 = bad[minI-i];
            loww2 = aad[minI-i];
            while (higI2<lowI2){
                ++count;
                higI2 = bad[minI+count];

            }
            hiw2=aad[minI+count]+((lowI2-higI2)/(bad[minI+count+1]-higI2))*(aad[minI+count+1]-aad[minI+count]);
            count = 0;
            cout<<cmw<<"\t"<<hiw2<<"\t"<<loww2<<endl;
            out<<(hiw2+loww2)/2-cmw<<"\t"<<lowI2<<endl;

            }
            else{
                i = number_of_lines;
            }
        }
        out.close();

    }

    if(ui->checkBox_5->isChecked() or ui->checkBox_11->isChecked()){

        input=ui->lineEdit_10->text();
        data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<seqPath<<"/"<<data<<"_B_"<<sext;
        std::string datName = datNameStream.str();

        QFile qOut(datName.c_str());

        if(qOut.exists()){
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Warning!", "The file "+input+" already exists. \n\n Do you want to overwrite it?",
                                          QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::Yes) {
              qDebug() << "Yes was clicked";
            }

            else {
                qDebug() << "Yes was *not* clicked";
                this->setCursor(QCursor(Qt::ArrowCursor));
                return;
            }
        }

        ofstream out(datName.c_str());

        QString input=ui->lineEdit_12->text();
        string data = input.toUtf8().constData();
        std::ostringstream dat2NameStream(data);
        dat2NameStream<<seqPath<<"/"<<data;
        std::string dat2Name = dat2NameStream.str();
        ifstream dat(dat2Name.c_str());


        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }

        number_of_lines =0;

        while(std::getline(dat, line))
            ++ number_of_lines;

        dat.clear();
        dat.seekg(0, ios::beg);

        aad.resize(number_of_lines);
        bad.resize(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
            dat >> eins >>zwei;
            istringstream ist(eins);
            ist >> aad[i];
            istringstream ist2(zwei);
            ist2 >> bad[i];
        }
        dat.close();

        if(ui->checkBox_7->isChecked()){
            double rvB = ui->doubleSpinBox_9->value();
            loww= loww*(1+rvB/c0);
            hiw = hiw*(1+rvB/c0);
        }

        double cmw=loww, imin=100, loww2, hiw2;
        int minI=1, count=0;

        for(int i =1; i<number_of_lines; i++){
            if((aad[i]>=loww) & (aad[i]<=hiw)){

                if(bad[i]<imin){
                    imin = bad[i];
                    cmw = aad[i];
                    minI = i;
                }
                else{
                    imin = imin;
                }

                }
            else{
                cmw=cmw;
                imin = imin;
            }
        }

        double lowI2 = bad[minI];
        double higI2 = bad[minI];
        loww2=cmw;

        for(int i=0;i < number_of_lines-1; i++){
            if(loww2>cmw-ui->doubleSpinBox_14->value()){    //lowI2<=0.45
            lowI2 = bad[minI-i];
            loww2 = aad[minI-i];
            while (higI2<lowI2){
                ++count;
                higI2 = bad[minI+count];

            }
            hiw2=aad[minI+count]+((lowI2-higI2)/(bad[minI+count+1]-higI2))*(aad[minI+count+1]-aad[minI+count]);
            count = 0;
            cout<<cmw<<"\t"<<hiw2<<"\t"<<loww2<<endl;
            out<<(hiw2+loww2)/2-cmw<<"\t"<<lowI2<<endl;

            }
            else{
                i = number_of_lines;
            }
        }
        out.close();
    }

    if(splinerror==1){
        QMessageBox::information(this, "Warnin", "Spline interpolation failed at least at one point. May use the linear interpolated points.");
    }

    this->setCursor(QCursor(Qt::ArrowCursor));

}

//**********************************
// line moments
//**********************************
void PlotSequ::on_pushButton_10_clicked()
{

    this->setCursor(QCursor(Qt::WaitCursor));

    qSeqPath=ui->lineEdit_5->text();
    seqPath=qSeqPath.toUtf8().constData();

    QVector<double> otim(1);

    QString input=ui->lineEdit_10->text();
    string data = input.toUtf8().constData();
    std::ostringstream datNameStream(data);
    datNameStream<<seqPath<<"/"<<data;
    std::string datName = datNameStream.str();

    QFile qOut(datName.c_str());

    if(qOut.exists()){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Warning!", "The file "+input+" already exists. \n\n Do you want to overwrite it?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
          qDebug() << "Yes was clicked";
        }

    else {
      qDebug() << "Yes was *not* clicked";
      this->setCursor(QCursor(Qt::ArrowCursor));
      return;
    }}

    ofstream out(datName.c_str());

    string line, eins, zwei;
    int min=ui->spinBox->value();
    int max=ui->spinBox_2->value();
    int number_of_lines =0, numb =0;

    double loww = ui->doubleSpinBox->value(), cwl=loww, Imin;
    double hiw = ui->doubleSpinBox_2->value(), mom1=0, mom2=0, mom3=0, EW=0, Cont=0, sum=0;
    double pdw = ui->doubleSpinBox_13->value();
    double mdw = ui->doubleSpinBox_14->value();

    if(ui->checkBox_14->isChecked()){
        QString qTim=ui->lineEdit_16->text();
        string tim = qTim.toUtf8().constData();
        std::ostringstream timNameStream(tim);
        timNameStream<<seqPath<<"/"<<tim;
        std::string timName = timNameStream.str();

        QFile checkfile(timName.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File "+qSeqPath+"\t"+qTim+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }

        ifstream Tim(timName.c_str());

        int tlines=0;

        while(std::getline(Tim, line))
           ++ tlines;

        Tim.clear();
        Tim.seekg(0, ios::beg);

        otim.resize(tlines);

        for(int i =0; i<tlines; i++){
            Tim>>eins;
            istringstream ist(eins);
            ist >> otim[i];
        }
        Tim.close();

    }

    out<<"Looking for minimum in ["<<loww<<":"<<hiw<<"] and integrate -"<<mdw<<":+"<<pdw<<endl;

    QString qext=ui->lineEdit_9->text();
    string sext = qext.toUtf8().constData();

    QVector<double> aad2(1), bad2(1);


    for (int u=min; u<=max; u++){
        cwl=loww;
        Imin=10;

        if(ui->comboBox->currentIndex()==0){
            QString input=ui->lineEdit->text();
            string data = input.toUtf8().constData();
            std::ostringstream datNameStream(data);
            datNameStream<<seqPath<<"/"<<data<<u<<sext;
            std::string datName = datNameStream.str();
            ifstream dat(datName.c_str());


            QFile checkfile(datName.c_str());

            if(!checkfile.exists()){
                qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input+" does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
                return;
            }

            number_of_lines =0;

            while(std::getline(dat, line))
                ++ number_of_lines;

            dat.clear();
            dat.seekg(0, ios::beg);
            numb=0;

            aad2.resize(number_of_lines);
            bad2.resize(number_of_lines);

            for (int i=0; i<number_of_lines; i++){
                dat >> eins >>zwei;
                istringstream ist(eins);
                ist >> aad2[i];
                istringstream ist2(zwei);
                ist2 >> bad2[i];

                if((aad2[i]>loww) & (aad2[i]<hiw)){
                    if(bad2[i]<Imin){
                        Imin = bad2[i];
                        cwl = aad2[i];
                    }
                }
            }
            dat.close();

        }

        if(ui->comboBox->currentIndex()==1){
            QString input=ui->lineEdit->text();
            string data = input.toUtf8().constData();
            std::ostringstream datNameStream(data);
            datNameStream<<seqPath<<"/"<<data<<u<<sext;
            std::string datName = datNameStream.str();

            QFile checkfile1(datName.c_str());

            if(!checkfile1.exists()){
                qDebug()<<"Error 1: The file "<<checkfile1.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error1 ", "Error 1: File "+checkfile1.fileName()+" does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
                //check=1;
               return;
            }

            CCfits::FITS::setVerboseMode(true);

            try
            {

                //open file for reading
                shared_ptr<CCfits::FITS> input_file(new CCfits::FITS(datName.c_str(),CCfits::Read,true));

                // Create pointer to extension
                    CCfits::ExtHDU& datavector = input_file->extension(seExtension);

                  // Read rows
                  CCfits::Column& column = datavector.column(seWavecol);
                  column.read(sewave, 1, column.rows());

                  // Read rows
                  CCfits::Column& column2 = datavector.column(seIntenscol);
                  column2.read(seintens, 1, column2.rows());

                  number_of_lines=sewave.size();

                  aad2.resize(number_of_lines);
                  bad2.resize(number_of_lines);

                  for(int i=0; i<number_of_lines; i++){
                  bad2[i]=seintens[i];
                  aad2[i]=sewave[i];
                  if((aad2[i]>loww) & (aad2[i]<hiw)){
                      if(bad2[i]<Imin){
                          Imin = bad2[i];
                          cwl = aad2[i];
                      }
                  }
                  }

            }
                catch (CCfits::FitsException&)

                 {
                  std::cerr << " Fits Exception Thrown by test function \n";
                  }
               // return;
        }

        loww = cwl - ui->doubleSpinBox_14->value();
        hiw = cwl + ui->doubleSpinBox_13->value();

        for(int i =0; i<number_of_lines; i++){
            if((aad2[i]>loww) & (aad2[i]<hiw)){
                ++numb;
            }
            else{
                numb=numb;
            }
        }

        QVector<double> aad(numb), bad(numb);
        numb = 0;

        for(int i =0; i<number_of_lines; i++){
            if((aad2[i]>loww) & (aad2[i]<hiw)){

                aad[numb]=aad2[i];
                bad[numb]=bad2[i];
                ++numb;
            }
        }

        mom1 = 0;
        mom2 = 0;
        mom3 = 0;
        EW=0;
        Cont=0;
        sum=0;
        double ykl=0, ygr=0, xkl=0, xgr=0;

        for(int i =0 ; i<10; i++){
            ykl += bad[i];
            ygr += bad[numb-i-1];
            xkl += aad[i];
            xgr += aad[numb-i-1];
        }
        ykl = ykl/10;
        ygr = ygr/10;
        xkl = xkl/10;
        xgr = xgr/10;

        double steig = (ygr-ykl)/(xgr-xkl);

        for(int i =1; i<aad.size(); i++){
            Cont = ykl+(aad[i]-xkl)*steig;
            sum+=bad[i];
            EW += (Cont-(bad[i-1]+bad[i])/2)*(aad[i]-aad[i-1]);
            mom1 += ((Cont-(bad[i-1]+bad[i])/2)*(aad[i]-aad[i-1]))*aad[i];
            mom2 += ((Cont-(bad[i-1]+bad[i])/2)*(aad[i]-aad[i-1]))*aad[i]*aad[i];
        }
        mom1 = mom1/EW;
        mom2 = mom2/EW;
        double rv;


        if(ui->checkBox_14->isChecked()){
            out<<setprecision(14)<<otim[u]<<"\t";
        }
        else{

        }

        out<<setprecision(14)<<sum<<"\t"<<EW<<"\t"<<mom1<<"\t"<<mom2;

        if(ui->checkBox_13->isChecked()){
            rv=c0*(mom1-ui->doubleSpinBox_12->value())/ui->doubleSpinBox_12->value();
            out<<"\t"<<rv<<endl;
        }
        else{
            out<<endl;
        }


    }
    if(ui->checkBox_4->isChecked() or ui->checkBox_10->isChecked()){
        QString input=ui->lineEdit_11->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<seqPath<<"/"<<data;
        std::string datName = datNameStream.str();
        ifstream dat(datName.c_str());


        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }

        number_of_lines =0;

        while(std::getline(dat, line))
            ++ number_of_lines;

        dat.clear();
        dat.seekg(0, ios::beg);
        numb=0;

        aad2.resize(number_of_lines);
        bad2.resize(number_of_lines);

        if(ui->checkBox_6->isChecked()){
            double rvA = ui->doubleSpinBox_8->value();
            loww= loww*(1+rvA/c0);
            hiw = hiw*(1+rvA/c0);
        }

        for (int i=0; i<number_of_lines; i++){
            dat >> eins >>zwei;
            istringstream ist(eins);
            ist >> aad2[i];
            istringstream ist2(zwei);
            ist2 >> bad2[i];
            if((aad2[i]>loww) & (aad2[i]<hiw)){
                if(bad2[i]<Imin){
                    Imin = bad2[i];
                    cwl = aad2[i];
                }
            }
        }
        dat.close();

        loww = cwl - ui->doubleSpinBox_14->value();
        hiw = cwl + ui->doubleSpinBox_13->value();

        for(int i =0; i<number_of_lines; i++){
            if((aad2[i]>loww) & (aad2[i]<hiw)){
                ++numb;
            }
            else{
                numb=numb;
            }
        }

        QVector<double> aad(numb), bad(numb);
        numb = 0;

        for(int i =0; i<number_of_lines; i++){
            if((aad2[i]>loww) & (aad2[i]<hiw)){

                aad[numb]=aad2[i];
                bad[numb]=bad2[i];
                ++numb;
            }
        }

        mom1 = 0;
        mom2 = 0;
        mom3 = 0;
        EW=0;
        Cont=0;
        sum=0;
        double ykl=0, ygr=0, xkl=0, xgr=0;

        for(int i =0 ; i<10; i++){
            ykl += bad[i];
            ygr += bad[numb-i-1];
            xkl += aad[i];
            xgr += aad[numb-i-1];
        }
        ykl = ykl/10;
        ygr = ygr/10;
        xkl = xkl/10;
        xgr = xgr/10;

        double steig = (ygr-ykl)/(xgr-xkl);

        for(int i =1; i<aad.size(); i++){
            Cont = ykl+(aad[i]-xkl)*steig;
            sum+=bad[i];
            EW += (Cont-(bad[i-1]+bad[i])/2)*(aad[i]-aad[i-1]);
            mom1 += ((Cont-(bad[i-1]+bad[i])/2)*(aad[i]-aad[i-1]))*aad[i];
            mom2 += ((Cont-(bad[i-1]+bad[i])/2)*(aad[i]-aad[i-1]))*aad[i]*aad[i];
        }
        mom1 = mom1/EW;
        mom2 = mom2/EW;
        double rv;

        if(ui->checkBox_14->isChecked()){
            out<<setprecision(14)<<"NaN\t"<<sum<<"\t"<<EW<<"\t"<<mom1<<"\t"<<mom2;
        }
        else{
            out<<setprecision(14)<<sum<<"\t"<<EW<<"\t"<<mom1<<"\t"<<mom2;
        }
        if(ui->checkBox_13->isChecked()){
            rv=c0*(mom1-ui->doubleSpinBox_12->value())/ui->doubleSpinBox_12->value();
            out<<"\t"<<rv<<endl;
        }
        else{
            out<<endl;
        }
    }

    if(ui->checkBox_5->isChecked() or ui->checkBox_11->isChecked()){
        QString input=ui->lineEdit_12->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<seqPath<<"/"<<data;
        std::string datName = datNameStream.str();
        ifstream dat(datName.c_str());


        QFile checkfile(datName.c_str());

        if(!checkfile.exists()){
            qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
            return;
        }

        number_of_lines =0;

        while(std::getline(dat, line))
            ++ number_of_lines;

        dat.clear();
        dat.seekg(0, ios::beg);
        numb=0;

        aad2.resize(number_of_lines);
        bad2.resize(number_of_lines);

        if(ui->checkBox_7->isChecked()){
            double rvB = ui->doubleSpinBox_9->value();
            loww= loww*(1+rvB/c0);
            hiw = hiw*(1+rvB/c0);
        }

        for (int i=0; i<number_of_lines; i++){
            dat >> eins >>zwei;
            istringstream ist(eins);
            ist >> aad2[i];
            istringstream ist2(zwei);
            ist2 >> bad2[i];
            if((aad2[i]>loww) & (aad2[i]<hiw)){
                if(bad2[i]<Imin){
                    Imin = bad2[i];
                    cwl = aad2[i];
                }
            }
        }
        dat.close();

        loww = cwl - ui->doubleSpinBox_14->value();
        hiw = cwl + ui->doubleSpinBox_13->value();

        for(int i =0; i<number_of_lines; i++){
            if((aad2[i]>loww) & (aad2[i]<hiw)){
                ++numb;
            }
            else{
                numb=numb;
            }
        }

        QVector<double> aad(numb), bad(numb);
        numb = 0;

        for(int i =0; i<number_of_lines; i++){
            if((aad2[i]>loww) & (aad2[i]<hiw)){

                aad[numb]=aad2[i];
                bad[numb]=bad2[i];
                ++numb;
            }
        }

        mom1 = 0;
        mom2 = 0;
        mom3 = 0;
        EW=0;
        Cont=0;
        sum=0;
        double ykl=0, ygr=0, xkl=0, xgr=0;

        for(int i =0 ; i<10; i++){
            ykl += bad[i];
            ygr += bad[numb-i-1];
            xkl += aad[i];
            xgr += aad[numb-i-1];
        }
        ykl = ykl/10;
        ygr = ygr/10;
        xkl = xkl/10;
        xgr = xgr/10;

        double steig = (ygr-ykl)/(xgr-xkl);

        for(int i =1; i<aad.size(); i++){
            Cont = ykl+(aad[i]-xkl)*steig;
            sum+=bad[i];
            EW += (Cont-(bad[i-1]+bad[i])/2)*(aad[i]-aad[i-1]);
            mom1 += ((Cont-(bad[i-1]+bad[i])/2)*(aad[i]-aad[i-1]))*aad[i];
            mom2 += ((Cont-(bad[i-1]+bad[i])/2)*(aad[i]-aad[i-1]))*aad[i]*aad[i];
        }
        mom1 = mom1/EW;
        mom2 = mom2/EW;
        double rv;

        if(ui->checkBox_14->isChecked()){
            out<<setprecision(14)<<"NaN\t"<<sum<<"\t"<<EW<<"\t"<<mom1<<"\t"<<mom2;
        }
        else{
            out<<setprecision(14)<<sum<<"\t"<<EW<<"\t"<<mom1<<"\t"<<mom2;
        }
        if(ui->checkBox_13->isChecked()){
            rv=c0*(mom1-ui->doubleSpinBox_12->value())/ui->doubleSpinBox_12->value();
            out<<"\t"<<rv<<endl;
        }
        else{
            out<<endl;
        }
    }
    out.close();

    this->setCursor(QCursor(Qt::ArrowCursor));


}

void PlotSequ::on_checkBox_15_clicked()
{
    if(ui->checkBox_15->isChecked()){
        ui->checkBox_16->setChecked(false);
    }
    else{

    }
}

void PlotSequ::on_checkBox_16_clicked()
{
    if(ui->checkBox_16->isChecked()){
        ui->checkBox_15->setChecked(false);
    }
    else{

    }
}

void PlotSequ::on_doubleSpinBox_15_valueChanged()
{
    ui->customPlot->xAxis->setTickStep(ui->doubleSpinBox_15->value());
    PlotSequ::on_pushButton_2_clicked();
}

void PlotSequ::on_doubleSpinBox_16_valueChanged()
{
    ui->customPlot->yAxis->setTickStep(ui->doubleSpinBox_16->value());
    PlotSequ::on_pushButton_2_clicked();
}

//******************************************
// move backward
//******************************************
void PlotSequ::on_pushButton_11_clicked()
{
    double ax1 = ui->doubleSpinBox->value();
    double ax2 = ui->doubleSpinBox_2->value();
    double interv=(ax2-ax1)/2;
    ui->doubleSpinBox->setValue(ax1-interv);
    ui->doubleSpinBox_2->setValue(ax2-interv);
    PlotSequ::on_pushButton_2_clicked();
}
//******************************************
// move forward
//******************************************
void PlotSequ::on_pushButton_12_clicked()
{
    double ax1 = ui->doubleSpinBox->value();
    double ax2 = ui->doubleSpinBox_2->value();
    double interv=(ax2-ax1)/2;
    ui->doubleSpinBox->setValue(ax1+interv);
    ui->doubleSpinBox_2->setValue(ax2+interv);
    PlotSequ::on_pushButton_2_clicked();
}
