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

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Crop *ui;
};

#endif // CROP_H
