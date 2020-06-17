#ifndef VALD3_H
#define VALD3_H

#include <QDialog>

namespace Ui {
class VALD3;
}

class VALD3 : public QDialog
{
    Q_OBJECT

public:
    explicit VALD3(QWidget *parent = nullptr);
    ~VALD3();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_spinBox_valueChanged();

    void on_checkBox_5_clicked();

    void computeMESAResiduumA();

    void computeMESAResiduumB();

    double MESAResiduum();

    void on_pushButton_7_clicked();

    void saveTracks();

public slots:
    void seData(QString str);

private:
    Ui::VALD3 *ui;
};

#endif // VALD3_H
