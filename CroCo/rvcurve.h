#ifndef RVCURVE_H
#define RVCURVE_H

#include <QDialog>

namespace Ui {
class RvCurve;
}

class RvCurve : public QDialog
{
    Q_OBJECT

public:
    explicit RvCurve(QWidget *parent = 0);
    ~RvCurve();

private slots:
    void on_pushButton_2_clicked();

    void on_lineEdit_2_textEdited();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_doubleSpinBox_5_valueChanged();

    void on_doubleSpinBox_6_valueChanged();

    void on_doubleSpinBox_7_valueChanged();

    void on_pushButton_6_clicked();

    void on_checkBox_4_clicked();

    void on_checkBox_5_clicked();

    void on_checkBox_6_clicked();

    void on_spinBox_3_valueChanged();

    void on_pushButton_7_clicked();

    void on_doubleSpinBox_8_valueChanged(double arg1);

    void on_lineEdit_6_editingFinished();

    void on_lineEdit_7_editingFinished();

    void on_doubleSpinBox_9_valueChanged(double arg1);

    void on_doubleSpinBox_10_valueChanged(double arg1);

    void on_doubleSpinBox_11_valueChanged(double arg1);

    void on_doubleSpinBox_12_valueChanged(double arg1);

    void on_checkBox_10_clicked();

    void on_checkBox_11_clicked();

    void on_checkBox_12_clicked();

private:
    Ui::RvCurve *ui;
};

#endif // RVCURVE_H
