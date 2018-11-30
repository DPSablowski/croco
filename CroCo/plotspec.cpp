#include "plotspec.h"
#include "ui_plotspec.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <QLineEdit>
#include <QPixmap>
#include <QLabel>
#include <QVector>
#include <QFile>
#include <QObject>
#include <QtDebug>
#include <QCheckBox>
#include <CCfits/CCfits>

using namespace std;

QString qSpPath, qspExtension, qspWavecol, qspIntenscol;
string spPath, spExtension, spWavecol, spIntenscol;
std::valarray<double> spwave;
std::valarray<double> spintens;

PlotSpec::PlotSpec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlotSpec)
{
    ui->setupUi(this);
    this->setWindowTitle("Spectrum Plotter");

    ui->lineEdit->setText("spectra_0.txt");
    ui->customPlot_3->xAxis->setLabel("Wavelength");
    ui->customPlot_3->yAxis->setLabel("Normalized Intensity");
    ui->checkBox->setChecked(true);
    qSpPath=ui->lineEdit_5->text();
    spPath = qSpPath.toUtf8().constData();

    ui->lineEdit_2->setText("Wavelength");
    ui->lineEdit_3->setText("Normalized Intensity");

    ui->comboBox->addItem("ASCII");
    ui->comboBox->addItem("fits");

    QFont legendFont = font();
    legendFont.setPointSize(16);
    ui->customPlot_3->axisRect()->setupFullAxesBox(true);
    ui->customPlot_3->xAxis->setLabelFont(legendFont);
    ui->customPlot_3->yAxis->setLabelFont(legendFont);
    ui->customPlot_3->xAxis->setTickLabelFont(legendFont);
    ui->customPlot_3->yAxis->setTickLabelFont(legendFont);

    ui->comboBox_2->addItem("Black");
    ui->comboBox_2->addItem("Blue");
    ui->comboBox_2->addItem("Red");
    ui->comboBox_2->addItem("Green");
    ui->comboBox_2->addItem("Yellow");
    ui->comboBox_2->addItem("Magenta");

    connect(ui->customPlot_3, SIGNAL(mouseMove(QMouseEvent*)), this ,SLOT(showPointToolTip(QMouseEvent*)));

}


PlotSpec::~PlotSpec()
{
    delete ui;
}


//********************************************************
//show mouse coordinates
//********************************************************
void PlotSpec::showPointToolTip(QMouseEvent *event)
{

    double xc = ui->customPlot_3->xAxis->pixelToCoord(event->pos().x());
    double yc = ui->customPlot_3->yAxis->pixelToCoord(event->pos().y());

    setToolTip(QString("%1 , %2").arg(xc).arg(yc));
}


void PlotSpec::seData(QString str, QString str2, QString str3, QString str4, QString str5)
{
    ui->lineEdit_5->setText(str);
    ui->lineEdit->setText(str2);
    ui->lineEdit_7->setText(str3);
    ui->lineEdit_8->setText(str4);
    ui->lineEdit_9->setText(str5);
}

//****************************************************************
//plot spectrum
//****************************************************************
void PlotSpec::on_pushButton_2_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));
    string one, two, zeile;

    qSpPath=ui->lineEdit_5->text();
    spPath = qSpPath.toUtf8().constData();

    ui->customPlot_3->clearGraphs();

    int pcolor=ui->comboBox_2->currentIndex();

    QPen pen;

    if(pcolor==0){
        pen.setColor(Qt::black);
    }
    if(pcolor==1){
        pen.setColor(Qt::blue);;
    }
    if(pcolor==2){
        pen.setColor(Qt::red);
    }
    if(pcolor==3){
        pen.setColor(Qt::green);
    }
    if(pcolor==4){
        pen.setColor(Qt::yellow);
    }
    if(pcolor==5){
        pen.setColor(Qt::magenta);
    }

    pen.setWidth(ui->spinBox_2->value());

    QVector<double> a(1), b(1), fa(1), fb(1), fxe(1), fye(1);
    int number_of_lines=0;

    if(ui->comboBox->currentIndex()==0){
    QString plot1=ui->lineEdit->text();
    string plot11 = plot1.toUtf8().constData();
    std::ostringstream datNameStream(plot11);
    datNameStream<<spPath<<"/"<<plot11;
    std::string datName = datNameStream.str();
    ifstream toplot1(datName.c_str());

    QFile checkfile(datName.c_str());

    if(!checkfile.exists()){
        qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+qSpPath+"/"+plot1+" does not exist!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    while(std::getline(toplot1, zeile))
       ++ number_of_lines;

    toplot1.clear();
    toplot1.seekg(0, ios::beg);

    a.resize(number_of_lines);
    b.resize(number_of_lines);


    for (int i=0; i<number_of_lines; i++){
        toplot1 >> one >>two;
        istringstream ist(one);
        ist >> a[i];
        istringstream ist2(two);
        ist2 >> b[i];
        if(ui->checkBox_5->isChecked()){
            b[i]=b[i]/ui->doubleSpinBox_4->value();
        }
    }
    toplot1.close();
    }

    if(ui->comboBox->currentIndex()==1){
        QString input=ui->lineEdit->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<spPath<<"/"<<data;
        std::string datName = datNameStream.str();
        //ifstream dat(datName.c_str());


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
            qspExtension = ui->lineEdit_7->text();
            spExtension = qspExtension.toUtf8().constData();

            qspWavecol=ui->lineEdit_8->text();
            spWavecol = qspWavecol.toUtf8().constData();
            qspIntenscol=ui->lineEdit_9->text();
            spIntenscol = qspIntenscol.toUtf8().constData();

            //open file for reading
            shared_ptr<CCfits::FITS> input_file(new CCfits::FITS(datName.c_str(),CCfits::Read,true));

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

    if(ui->checkBox_6->isChecked()){
        QString flux1=ui->lineEdit_10->text();
        string flux11 = flux1.toUtf8().constData();
        std::ostringstream dat2NameStream(flux11);
        dat2NameStream<<spPath<<"/"<<flux11;
        std::string dat2Name = dat2NameStream.str();

        QFile checkfile2(dat2Name.c_str());

        if(!checkfile2.exists()){
            qDebug()<<"The file "<<checkfile2.fileName()<<" does not exist.";
            QMessageBox::information(this, "Error", "File "+qSpPath+"/"+flux1+" does not exist!");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        ifstream flux(dat2Name.c_str());

        number_of_lines =0;

        while(std::getline(flux, zeile))
           ++ number_of_lines;

        flux.clear();
        flux.seekg(0, ios::beg);

        fa.resize(number_of_lines);
        fb.resize(number_of_lines);
        fxe.resize(number_of_lines);
        fye.resize(number_of_lines);
        string drei, vier;

        for (int i=0; i<number_of_lines; i++){
            flux >> one >>two>>drei>>vier;
            istringstream ist(one);
            ist >> fa[i];
            istringstream ist2(two);
            ist2 >> fxe[i];
            istringstream ist3(drei);
            ist3 >> fb[i];
            istringstream ist4(vier);
            ist4 >> fye[i];
        }
    }

    ui->customPlot_3->addGraph();
    if(ui->checkBox_4->isChecked()){
    ui->customPlot_3->legend->setVisible(true);
    QFont legendFont = font();
    legendFont.setPointSize(ui->spinBox->value());
    ui->customPlot_3->legend->setFont(legendFont);
    ui->customPlot_3->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);
    QString label=ui->lineEdit_6->text();
    ui->customPlot_3->graph(0)->setName(label);
    }
    ui->customPlot_3->graph(0)->setData(a, b);
    ui->customPlot_3->graph()->setPen(pen);
    ui->customPlot_3->xAxis->setRange(ui->doubleSpinBox->value(), ui->doubleSpinBox_2->value());
    if(ui->checkBox_5->isChecked()){
        ui->customPlot_3->yAxis->setRange(ui->doubleSpinBox_3->value(), 1.10);
    }
    else{
        ui->customPlot_3->yAxis->setRange(ui->doubleSpinBox_3->value(), ui->doubleSpinBox_4->value());

    }
    /*
    if(ui->checkBox_6->isChecked()){
        ui->customPlot_3->addGraph();
        ui->customPlot_3->graph(1)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot_3->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));

        QCPErrorBars *errorBars = new QCPErrorBars(ui->customPlot_3->xAxis, ui->customPlot_3->yAxis);
        errorBars->removeFromLegend();
        errorBars->setDataPlottable(ui->customPlot_3->graph(1));
        ui->customPlot_3->graph(1)->setData(fa, fb);
    }*/
    ui->customPlot_3->replot();

    this->setCursor(QCursor(Qt::ArrowCursor));
}

//****************************************************************
//find values
//****************************************************************
void PlotSpec::on_pushButton_3_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));
    string one, two, zeile;
    double xs1, xs2, ys1, ys2;

    qSpPath=ui->lineEdit_5->text();
    spPath = qSpPath.toUtf8().constData();

    QVector<double> a(1), b(1);
    int number_of_lines=0;

    if(ui->comboBox->currentIndex()==0){
    QString plot1=ui->lineEdit->text();
    string plot11 = plot1.toUtf8().constData();
    std::ostringstream datNameStream(plot11);
    datNameStream<<spPath<<"/"<<plot11;
    std::string datName = datNameStream.str();
    ifstream toplot1(datName.c_str());

    QFile checkfile(datName.c_str());

    if(!checkfile.exists()){
        qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
        QMessageBox::information(this, "Error", "File "+qSpPath+"/"+plot1+" does not exist!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    while(std::getline(toplot1, zeile))
       ++ number_of_lines;

    toplot1.clear();
    toplot1.seekg(0, ios::beg);

    a.resize(number_of_lines);
    b.resize(number_of_lines);

    for (int i=0; i<number_of_lines; i++){
        toplot1 >> one >>two;
        istringstream ist(one);
        ist >> a[i];
        istringstream ist2(two);
        ist2 >> b[i];
    }
    toplot1.close();
    }

    if(ui->comboBox->currentIndex()==1){
        QString input=ui->lineEdit->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<spPath<<"/"<<data;
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
            qspExtension = ui->lineEdit_7->text();
            spExtension = qspExtension.toUtf8().constData();

            qspWavecol=ui->lineEdit_8->text();
            spWavecol = qspWavecol.toUtf8().constData();
            qspIntenscol=ui->lineEdit_9->text();
            spIntenscol = qspIntenscol.toUtf8().constData();

            //open file for reading
            shared_ptr<CCfits::FITS> input_file(new CCfits::FITS(datName.c_str(),CCfits::Read,true));

            // Create pointer to extension
                CCfits::ExtHDU& datavector = input_file->extension(spExtension);

              // Read rows
              CCfits::Column& column = datavector.column(spWavecol);
              column.read(spwave, 1, column.rows());

              // Read rows
              CCfits::Column& column2 = datavector.column(spIntenscol);
              column2.read(spintens, 1, column2.rows());

              number_of_lines=spwave.size();

              a.resize(number_of_lines);
              b.resize(number_of_lines);

              for(int i=0; i<number_of_lines; i++){
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


    xs1=a[0];
    xs2=a[number_of_lines-1];
    for(int i=0; i<number_of_lines; i++){
        if(a[i]<xs1){
            xs1=a[i];
        }
    }

    for(int i=0; i<number_of_lines; i++){
        if(a[i]>xs2){
            xs2=a[i];
        }
    }

    ui->doubleSpinBox->setValue(xs1);
    ui->doubleSpinBox_2->setValue(xs2);

    ys1=b[0];
    ys2=b[number_of_lines-1];
    for(int i=0; i<number_of_lines; i++){
        if(b[i]<ys1){
            ys1=b[i];
        }
    }
    for(int i=0; i<number_of_lines; i++){
        if(b[i]>ys2){
            ys2=b[i];
        }
    }


    ui->doubleSpinBox_3->setValue(ys1);
    ui->doubleSpinBox_4->setValue(ys2);

    this->setCursor(QCursor(Qt::ArrowCursor));
}

void PlotSpec::on_lineEdit_2_editingFinished()
{
    QString xlabel=ui->lineEdit_2->text();
    ui->customPlot_3->xAxis->setLabel(xlabel);
}

void PlotSpec::on_lineEdit_3_editingFinished()
{
    QString ylabel=ui->lineEdit_3->text();
    ui->customPlot_3->yAxis->setLabel(ylabel);
}

void PlotSpec::on_pushButton_4_clicked()
{
    if(ui->checkBox->isChecked()){
        QString sav=ui->lineEdit_4->text();
        QString save=qSpPath+"/"+sav +".pdf";
        ui->customPlot_3->savePdf(save);
    }
    if(ui->checkBox_2->isChecked()){
        QString sav=ui->lineEdit_4->text();
        QString save=qSpPath+"/"+sav+".png";
        ui->customPlot_3->savePng(save);
    }
    if(ui->checkBox_3->isChecked()){
        QString sav=ui->lineEdit_4->text();
        QString save=qSpPath+"/"+sav+".jpg";
        ui->customPlot_3->saveJpg(save);
    }
}

void PlotSpec::on_checkBox_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
}

void PlotSpec::on_checkBox_2_clicked()
{
    ui->checkBox_3->setChecked(false);
    ui->checkBox->setChecked(false);
}

void PlotSpec::on_checkBox_3_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox->setChecked(false);
}

void PlotSpec::on_lineEdit_5_textEdited()
{
    qSpPath=ui->lineEdit_5->text();
    spPath = qSpPath.toUtf8().constData();
}

void PlotSpec::on_spinBox_valueChanged()
{
    QFont legendFont = font();
    legendFont.setPointSize(ui->spinBox->value());
    ui->customPlot_3->xAxis->setLabelFont(legendFont);
    ui->customPlot_3->yAxis->setLabelFont(legendFont);
    ui->customPlot_3->xAxis->setTickLabelFont(legendFont);
    ui->customPlot_3->yAxis->setTickLabelFont(legendFont);
}
