#include "plotsequ.h"
#include "ui_plotsequ.h"
#include <sstream>
#include <fstream>
#include <CCfits/CCfits>

using namespace std;

int pcolor=1;
double xse1, yse2, xse2, yse1, offset;
QString qSeqPath, qseExtension, qseWavecol, qseIntenscol;
string seqPath, seExtension, seWavecol, seIntenscol;
std::valarray<double> sewave;
std::valarray<double> seintens;


PlotSequ::PlotSequ(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlotSequ)
{
    ui->setupUi(this);
    this->setWindowTitle("Sequence Plotter");

    ui->lineEdit->setText("cab_");
    ui->customPlot->xAxis->setLabel("Wavelength [A]");
    ui->customPlot->yAxis->setLabel("normalized Intensity");
    ui->checkBox->setChecked(true);
    ui->lineEdit_5->setText("/home/daniels/Observations/Capella/Set_13/Ca_UV/prepared");
    qSeqPath=ui->lineEdit_5->text();
    seqPath = qSeqPath.toUtf8().constData();
    offset=ui->doubleSpinBox_5->value();

    ui->lineEdit_6->setText("DataVector");
    ui->lineEdit_7->setText("Arg");
    ui->lineEdit_8->setText("Fun");
    ui->lineEdit_9->setText(".dat");
    ui->lineEdit_10->setText("added.dat");
    qseExtension=ui->lineEdit_6->text();
    seExtension = qseExtension.toUtf8().constData();
    qseWavecol=ui->lineEdit_7->text();
    seWavecol = qseWavecol.toUtf8().constData();
    qseIntenscol=ui->lineEdit_8->text();
    seIntenscol = qseIntenscol.toUtf8().constData();

    ui->comboBox->addItem("ASCII");
    ui->comboBox->addItem("fits");

    QFont legendFont = font();
    legendFont.setPointSize(16);
    ui->customPlot->axisRect()->setupFullAxesBox(true);
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);

    ui->comboBox_2->addItem("Black");
    ui->comboBox_2->addItem("Blue");
    ui->comboBox_2->addItem("Red");
    ui->comboBox_2->addItem("Green");

    ui->lineEdit_11->setText("103_1_cor_1.txt");
    ui->lineEdit_12->setText("103_1_cor_2.txt");

    connect(ui->customPlot, SIGNAL(mouseMove(QMouseEvent*)), this ,SLOT(showPointToolTip(QMouseEvent*)));


}

PlotSequ::~PlotSequ()
{
    delete ui;
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
                QMessageBox::information(this, "Error1 ", "Error 1: File does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
                //check=1;
               return;
            }

            CCfits::FITS::setVerboseMode(true);

            try
            {

                //open file for reading
                auto_ptr<CCfits::FITS> input_file(new CCfits::FITS(datName.c_str(),CCfits::Read,true));

                // Create pointer to extension
                    CCfits::ExtHDU& datavector = input_file->extension(seExtension);

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

    QPen pen1, pen2, pen3, pen4;

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
            QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input+fError+".txt does not exist!");
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
                QMessageBox::information(this, "Error1 ", "Error 1: File does not exist!");
                this->setCursor(QCursor(Qt::ArrowCursor));
                //check=1;
               return;
            }

            CCfits::FITS::setVerboseMode(true);

            try
            {

                //open file for reading
                auto_ptr<CCfits::FITS> input_file(new CCfits::FITS(datName.c_str(),CCfits::Read,true));

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
        ui->customPlot->graph()->setData(a, b);

        if(ui->checkBox_4->isChecked()){
            QString input1=ui->lineEdit_11->text();
            string data1 = input1.toUtf8().constData();
            std::ostringstream dat1NameStream(data1);
            dat1NameStream<<seqPath<<"/"<<data1;
            std::string dat1Name = dat1NameStream.str();
            ifstream dat1(dat1Name.c_str());


            QFile checkfile(dat1Name.c_str());

            if(!checkfile.exists()){
                qDebug()<<"The file "<<checkfile.fileName()<<" does not exist.";
                QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input1+".txt does not exist!");
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
            if(ui->checkBox_6->isChecked()){
            a1[i]=a1[i]*(1+ui->doubleSpinBox_8->value()/299792.458);
            }
            istringstream ist2(zwei);
            ist2 >> b1[i];
            b1[i]=b1[i]+ui->doubleSpinBox_6->value()+offset*(u-min);
            }
            dat1.close();

            ui->customPlot->addGraph();
            ui->customPlot->graph()->setPen(QPen(Qt::red));
            ui->customPlot->graph()->setData(a1, b1);
        }

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
                QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input2+".txt does not exist!");
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
            if(ui->checkBox_7->isChecked()){
            a2[i]=a2[i]*(1+ui->doubleSpinBox_9->value()/299792.458);
            }
            istringstream ist2(zwei);
            ist2 >> b2[i];
            b2[i]=b2[i]+ui->doubleSpinBox_7->value()+offset*(u-min);
            }
            dat2.close();

            ui->customPlot->addGraph();
            ui->customPlot->graph()->setPen(QPen(Qt::blue));
            ui->customPlot->graph()->setData(a2, b2);
        }}

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
            QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input1+".txt does not exist!");
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
        if(ui->checkBox_6->isChecked()){
        a1[i]=a1[i]*(1+ui->doubleSpinBox_8->value()/299792.458);
        }
        istringstream ist2(zwei);
        ist2 >> b1[i];
        b1[i]=b1[i]+ui->doubleSpinBox_6->value()+offset*(max-min+1);
        }
        dat1.close();

        ui->customPlot->addGraph();
        pen2.setColor(Qt::red);
        pen2.setWidth(ui->spinBox_4->value());
        ui->customPlot->graph()->setPen(pen2);
        ui->customPlot->graph()->setData(a1, b1);
    }

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
            QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input2+".txt does not exist!");
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
        if(ui->checkBox_7->isChecked()){
        a2[i]=a2[i]*(1+ui->doubleSpinBox_9->value()/299792.458);
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
                QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input3+".txt does not exist!");
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
            if(ui->checkBox_9->isChecked()){
            a3[i]=a3[i]*(1+ui->doubleSpinBox_11->value()/299792.458);
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
    if(ui->checkBox->isChecked()){
        QString sav=ui->lineEdit_4->text();
        QString save=qSeqPath+"/"+sav+".pdf";
        ui->customPlot->savePdf(save);
    }
    if(ui->checkBox_2->isChecked()){
        QString sav=ui->lineEdit_4->text();
        QString save=qSeqPath+"/"+sav+".png";
        ui->customPlot->savePng(save);
    }
    if(ui->checkBox_3->isChecked()){
        QString sav=ui->lineEdit_4->text();
        QString save=qSeqPath+"/"+sav+".jpg";
        ui->customPlot->saveJpg(save);
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
            QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input+fError+".txt does not exist!");
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

        QString input=ui->lineEdit->text();
        string data = input.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<seqPath<<"/"<<data;
        std::string datName = datNameStream.str();
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
    this->setCursor(QCursor(Qt::WaitCursor));

    string line, eins, zwei;
    int min=ui->spinBox->value();
    int max=ui->spinBox_2->value();
    int number_of_lines =0;

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
            QMessageBox::information(this, "Error", "File "+qSeqPath+"/"+input+fError+".txt does not exist!");
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
}
