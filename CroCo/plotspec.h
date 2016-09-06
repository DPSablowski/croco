#ifndef PLOTSPEC_H
#define PLOTSPEC_H

#include <QDialog>
#include <QLineEdit>
#include <QString>
#include <QGraphicsView>
#include <QtCore>
#include <QtGui>
#include <QCheckBox>

namespace Ui {
class PlotSpec;
}

class PlotSpec : public QDialog
{
    Q_OBJECT

public:
    explicit PlotSpec(QWidget *parent = 0);
    ~PlotSpec();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_doubleSpinBox_valueChanged();

    void on_doubleSpinBox_2_valueChanged();

    void on_doubleSpinBox_3_valueChanged();

    void on_doubleSpinBox_4_valueChanged();

    void on_lineEdit_2_editingFinished();

    void on_lineEdit_3_editingFinished();

    void on_pushButton_4_clicked();

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_lineEdit_5_textEdited();

    void on_spinBox_valueChanged();

    void on_lineEdit_7_textChanged();

    void on_lineEdit_8_textChanged();

    void on_lineEdit_9_textChanged();

private:
    Ui::PlotSpec *ui;
};

#endif // PLOTSPEC_H
