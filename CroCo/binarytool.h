#ifndef BINARYTOOL_H
#define BINARYTOOL_H

#include <QDialog>

namespace Ui {
class BinaryTool;
}

class BinaryTool : public QDialog
{
    Q_OBJECT

public:
    explicit BinaryTool(QWidget *parent = 0);
    ~BinaryTool();

private slots:

    void on_doubleSpinBox_4_valueChanged();

    void on_doubleSpinBox_3_valueChanged();

    void on_doubleSpinBox_5_valueChanged();

    void on_doubleSpinBox_6_valueChanged();

    void on_doubleSpinBox_7_valueChanged();

    void on_doubleSpinBox_8_valueChanged();

    void on_doubleSpinBox_10_valueChanged();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    double std_rand();

    double gauss();

    void on_lineEdit_3_textChanged();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_doubleSpinBox_2_valueChanged();

    void on_pushButton_6_clicked();

    void on_spinBox_4_valueChanged();

    void on_doubleSpinBox_17_valueChanged();

    void showPointToolTip(QMouseEvent *event);


private:
    Ui::BinaryTool *ui;
};

#endif // BINARYTOOL_H
