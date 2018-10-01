#ifndef TELLURIC_H
#define TELLURIC_H

#include <QDialog>

namespace Ui {
class Telluric;
}

class Telluric : public QDialog
{
    Q_OBJECT

public:
    explicit Telluric(QWidget *parent = 0);
    ~Telluric();

private slots:
    void on_doubleSpinBox_valueChanged();

    void tellPlot();

    void tellRead();

    void on_lineEdit_6_textChanged();

    void on_doubleSpinBox_2_valueChanged();

    void on_doubleSpinBox_3_valueChanged();

    void on_pushButton_2_clicked();

    void on_doubleSpinBox_4_valueChanged();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_comboBox_3_currentIndexChanged();

    void on_pushButton_7_clicked();

public slots:
    void seData(QString str, QString str2, QString str3);

private:
    Ui::Telluric *ui;
};

#endif // TELLURIC_H
