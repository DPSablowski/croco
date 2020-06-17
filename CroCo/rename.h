#ifndef RENAME_H
#define RENAME_H

#include <QDialog>

namespace Ui {
class Rename;
}

class Rename : public QDialog
{
    Q_OBJECT

public:
    explicit Rename(QWidget *parent = 0);
    ~Rename();

public slots:
    void seData(QString str, QString str2, QString str3, QString str4, QString str5);

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged();

    void on_pushButton_2_clicked();

    void on_spinBox_5_valueChanged();

    void on_pushButton_4_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Rename *ui;
};

#endif // RENAME_H
