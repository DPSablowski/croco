#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QString>
#include <QGraphicsView>
#include <QtCore>
#include <QtGui>
#include <QCheckBox>
#include <plotspec.h>
#include <plotsequ.h>
#include <rvcurve.h>
#include <template.h>
#include <binarytool.h>
#include <telluric.h>
#include <mapplot.h>
#include <rvcalc.h>
#include <rename.h>
#include <cpd.h>
#include <arithmetic.h>
#include <crop.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged();

    void on_spinBox_2_valueChanged();

    void on_spinBox_3_valueChanged();

    void on_pushButton_3_clicked();

   void on_doubleSpinBox_valueChanged();

    void on_doubleSpinBox_2_valueChanged();

    void on_doubleSpinBox_3_valueChanged();

    void on_doubleSpinBox_4_valueChanged();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_doubleSpinBox_5_valueChanged();

    void on_doubleSpinBox_6_valueChanged();

    void on_doubleSpinBox_7_valueChanged();

    void on_doubleSpinBox_8_valueChanged();

    void on_actionAbout_triggered();

    void on_actionBug_Report_triggered();

    void on_actionPlot_triggered();

    void on_actionSequence_Plotter_triggered();

    void on_actionSave_As_triggered();

    void on_lineEdit_15_textEdited();

    void on_actionRV_Curve_triggered();

    void on_checkBox_8_pressed();

    void on_doubleSpinBox_12_valueChanged();

    void on_doubleSpinBox_13_valueChanged();

    void on_doubleSpinBox_14_valueChanged();

    void on_actionTemplate_Generator_triggered();

    void on_doubleSpinBox_15_valueChanged();

    void ReadHeader(int argc, char *argv[]);

    void on_pushButton_10_clicked();

    void on_lineEdit_18_textChanged();

    void on_lineEdit_19_textChanged();

    void on_lineEdit_20_textChanged();

    void ReadMeasured(int gg);

    void on_actionBinary_Tool_triggered();

    void on_checkBox_10_clicked();

    void on_checkBox_11_clicked();

    void on_actionTelluric_triggered();

    void on_action2D_Map_Plot_triggered();

    void on_actionRV_Calculator_triggered();

    void on_actionRaname_Files_triggered();

    void on_comboBox_currentIndexChanged();

    void on_actionCPD_triggered();

    void on_actionArithmetic_triggered();

    void on_actionCrop_triggered();

private:
    Ui::MainWindow *ui;
    PlotSpec *pSpec;
    PlotSequ *pSequ;
    RvCurve *qCurve;
    Template *qTemplate;
    BinaryTool *qBinary;
    void saveFile();
    QString curFile;
    Telluric *qTell;
    MapPlot *qMPlot;
    RVCalc *qRVCalc;
    Rename *qRename;
    CPD *qCPD;
    Arithmetic *qArith;
    Crop *qCrop;
};

#endif // MAINWINDOW_H
