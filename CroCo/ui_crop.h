/********************************************************************************
** Form generated from reading UI file 'crop.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CROP_H
#define UI_CROP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Crop
{
public:
    QPushButton *pushButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QSpinBox *spinBox;
    QLabel *label_3;
    QSpinBox *spinBox_2;
    QLineEdit *lineEdit_2;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QLineEdit *lineEdit_5;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_2;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_2;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QLineEdit *lineEdit_6;
    QLabel *label_10;
    QLineEdit *lineEdit_7;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *Crop)
    {
        if (Crop->objectName().isEmpty())
            Crop->setObjectName(QStringLiteral("Crop"));
        Crop->resize(742, 315);
        pushButton = new QPushButton(Crop);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 240, 85, 30));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        widget = new QWidget(Crop);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(9, 9, 531, 34));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout->addWidget(spinBox);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        spinBox_2 = new QSpinBox(widget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));

        horizontalLayout->addWidget(spinBox_2);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_2);

        widget1 = new QWidget(Crop);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(9, 85, 702, 34));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(widget1);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        label_5 = new QLabel(widget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        lineEdit_4 = new QLineEdit(widget1);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        sizePolicy.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit_4);

        label_4 = new QLabel(widget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        lineEdit_3 = new QLineEdit(widget1);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit_3);

        label_6 = new QLabel(widget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_2->addWidget(label_6);

        lineEdit_5 = new QLineEdit(widget1);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        sizePolicy.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit_5);

        widget2 = new QWidget(Crop);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(20, 150, 408, 32));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(widget2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);

        label_7 = new QLabel(widget2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_3->addWidget(label_7);

        doubleSpinBox = new QDoubleSpinBox(widget2);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setDecimals(5);
        doubleSpinBox->setMaximum(9999.99);

        horizontalLayout_3->addWidget(doubleSpinBox);

        label_8 = new QLabel(widget2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_3->addWidget(label_8);

        doubleSpinBox_2 = new QDoubleSpinBox(widget2);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setDecimals(5);
        doubleSpinBox_2->setMaximum(9999.99);

        horizontalLayout_3->addWidget(doubleSpinBox_2);

        widget3 = new QWidget(Crop);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(30, 200, 481, 34));
        horizontalLayout_4 = new QHBoxLayout(widget3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(widget3);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_4->addWidget(label_9);

        lineEdit_6 = new QLineEdit(widget3);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        horizontalLayout_4->addWidget(lineEdit_6);

        label_10 = new QLabel(widget3);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_4->addWidget(label_10);

        lineEdit_7 = new QLineEdit(widget3);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        horizontalLayout_4->addWidget(lineEdit_7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        retranslateUi(Crop);
        QObject::connect(pushButton, SIGNAL(clicked()), Crop, SLOT(close()));

        QMetaObject::connectSlotsByName(Crop);
    } // setupUi

    void retranslateUi(QDialog *Crop)
    {
        Crop->setWindowTitle(QApplication::translate("Crop", "Dialog", 0));
        pushButton->setText(QApplication::translate("Crop", "Close", 0));
        label->setText(QApplication::translate("Crop", "Input Spectra", 0));
        label_2->setText(QApplication::translate("Crop", "from", 0));
        label_3->setText(QApplication::translate("Crop", "to", 0));
        label_5->setText(QApplication::translate("Crop", "Extension", 0));
        label_4->setText(QApplication::translate("Crop", "W.Col.", 0));
        label_6->setText(QApplication::translate("Crop", "I.Col.", 0));
        pushButton_2->setText(QApplication::translate("Crop", "Crop", 0));
        label_7->setText(QApplication::translate("Crop", "from", 0));
        label_8->setText(QApplication::translate("Crop", "to", 0));
        label_9->setText(QApplication::translate("Crop", "Output", 0));
        label_10->setText(QApplication::translate("Crop", "Work Path:", 0));
    } // retranslateUi

};

namespace Ui {
    class Crop: public Ui_Crop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CROP_H
