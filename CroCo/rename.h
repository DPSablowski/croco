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

private slots:
    void on_pushButton_clicked();

private:
    Ui::Rename *ui;
};

#endif // RENAME_H
