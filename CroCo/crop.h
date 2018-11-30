#ifndef CROP_H
#define CROP_H

#include <QDialog>

namespace Ui {
class Crop;
}

class Crop : public QDialog
{
    Q_OBJECT

public:
    explicit Crop(QWidget *parent = 0);
    ~Crop();

public slots:
    void seData(QString str, QString str2, QString str3, QString str4, QString str5);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void cropSpectra();

private:
    Ui::Crop *ui;
};

#endif // CROP_H
