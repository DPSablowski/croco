#ifndef MAPPLOT_H
#define MAPPLOT_H

#include <QDialog>

namespace Ui {
class MapPlot;
}

class MapPlot : public QDialog
{
    Q_OBJECT

public:
    explicit MapPlot(QWidget *parent = 0);
    ~MapPlot();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_2_textChanged();

    void on_spinBox_3_valueChanged();

public slots:
    void seData(QString str);

private:
    Ui::MapPlot *ui;
};

#endif // MAPPLOT_H
