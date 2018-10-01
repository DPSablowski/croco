#ifndef MOMENTS_H
#define MOMENTS_H

#include <QDialog>

namespace Ui {
class Moments;
}

class Moments : public QDialog
{
    Q_OBJECT

public:
    explicit Moments(QWidget *parent = 0);
    ~Moments();

public slots:
    void seData(QString str);

private slots:
    void on_spinBox_valueChanged();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Moments *ui;
};

#endif // MOMENTS_H
