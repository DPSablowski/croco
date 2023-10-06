#ifndef PLOTSEQU_H
#define PLOTSEQU_H

#include <QDialog>

namespace Ui {
class PlotSequ;
}

class PlotSequ : public QDialog
{
    Q_OBJECT

public:
    explicit PlotSequ(QWidget *parent = 0);
    ~PlotSequ();

public slots:
    void seData(QString str, QString str2, QString str3, QString str4, QString str5);

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_doubleSpinBox_valueChanged();

    void on_doubleSpinBox_2_valueChanged();

    void on_doubleSpinBox_3_valueChanged();

    void on_doubleSpinBox_4_valueChanged();

    void on_lineEdit_2_editingFinished();

    void on_lineEdit_3_editingFinished();

    void on_pushButton_4_clicked();

    void on_checkBox_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_2_clicked();

    void on_lineEdit_5_textEdited();

    void on_doubleSpinBox_5_valueChanged();

    void on_spinBox_3_valueChanged();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void CoAverage();

    void on_pushButton_7_clicked();

    void on_comboBox_2_currentIndexChanged();

    void showPointToolTip(QMouseEvent *event);

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_checkBox_15_clicked();

    void on_checkBox_16_clicked();

    void on_doubleSpinBox_15_valueChanged();

    void on_doubleSpinBox_16_valueChanged();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void createMedian();

    void coAdd();

private:
    Ui::PlotSequ *ui;
};

#endif // PLOTSEQU_H
