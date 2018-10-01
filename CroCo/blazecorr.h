#ifndef BLAZECORR_H
#define BLAZECORR_H

#include <QDialog>

namespace Ui {
class BlazeCorr;
}

class BlazeCorr : public QDialog
{
    Q_OBJECT

public:
    explicit BlazeCorr(QWidget *parent = 0);
    ~BlazeCorr();

public slots:
    void seData(QString str);

private slots:

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

private:
    Ui::BlazeCorr *ui;
};

#endif // BLAZECORR_H
