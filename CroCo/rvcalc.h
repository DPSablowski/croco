#ifndef RVCALC_H
#define RVCALC_H

#include <QDialog>

namespace Ui {
class RVCalc;
}

class RVCalc : public QDialog
{
    Q_OBJECT

public:
    explicit RVCalc(QWidget *parent = 0);
    ~RVCalc();

private slots:
    void on_doubleSpinBox_9_valueChanged();

    void on_pushButton_2_clicked();

    void on_lineEdit_2_textChanged();

    void on_spinBox_valueChanged();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_4_textEdited();

    void on_lineEdit_5_textEdited();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void findroot();

    void on_pushButton_7_clicked();

    void on_checkBox_6_clicked();

    void on_checkBox_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::RVCalc *ui;
};

#endif // RVCALC_H
