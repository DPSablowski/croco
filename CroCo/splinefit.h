#ifndef SPLINEFIT_H
#define SPLINEFIT_H

#include <QDialog>

namespace Ui {
class SplineFit;
}

class SplineFit : public QDialog
{
    Q_OBJECT

public:
    explicit SplineFit(QWidget *parent = 0);
    ~SplineFit();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_checkBox_clicked();

    void showPointToolTip(QMouseEvent *event);

    void writeCoords(QMouseEvent *event);

    void on_pushButton_3_clicked();

private:
    Ui::SplineFit *ui;
};

#endif // SPLINEFIT_H
