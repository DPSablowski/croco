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

private:
    Ui::RvCurve *ui;
};

#endif // RVCURVE_H
