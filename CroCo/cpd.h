#ifndef CPD_H
#define CPD_H

#include <QDialog>

namespace Ui {
class CPD;
}

class CPD : public QDialog
{
    Q_OBJECT

public:
    explicit CPD(QWidget *parent = 0);
    ~CPD();

private slots:
    void on_pushButton_2_clicked();

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_lineEdit_5_textChanged();

private:
    Ui::CPD *ui;
};

#endif // CPD_H
