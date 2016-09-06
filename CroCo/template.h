#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <QDialog>

namespace Ui {
class Template;
}

class Template : public QDialog
{
    Q_OBJECT

public:
    explicit Template(QWidget *parent = 0);
    ~Template();

private slots:
    void on_pushButton_4_clicked();

    void on_lineEdit_editingFinished();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_doubleSpinBox_valueChanged();

    void on_doubleSpinBox_2_valueChanged();

    void on_doubleSpinBox_3_valueChanged();

    void on_doubleSpinBox_4_valueChanged();

    void on_doubleSpinBox_10_valueChanged();

    void on_doubleSpinBox_11_valueChanged();

    void on_doubleSpinBox_5_valueChanged();

    void on_doubleSpinBox_6_valueChanged();

    void on_doubleSpinBox_13_valueChanged();

    void on_doubleSpinBox_14_valueChanged();

    void on_doubleSpinBox_15_valueChanged();

    void on_doubleSpinBox_16_valueChanged();

    void on_doubleSpinBox_7_valueChanged();

    void on_doubleSpinBox_17_valueChanged();

private:
    Ui::Template *ui;
};

#endif // TEMPLATE_H
