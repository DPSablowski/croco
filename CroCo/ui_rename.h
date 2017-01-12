/********************************************************************************
** Form generated from reading UI file 'rename.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENAME_H
#define UI_RENAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Rename
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkBox;
    QSpinBox *spinBox_2;
    QLabel *label_5;
    QSpinBox *spinBox_3;
    QLabel *label_6;
    QSpinBox *spinBox_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *lineEdit_4;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_3;
    QVBoxLayout *verticalLayout_2;
    QCustomPlot *customPlot;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_12;
    QSpinBox *spinBox_5;
    QLineEdit *lineEdit_8;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_9;
    QComboBox *comboBox;
    QLabel *label_13;
    QLineEdit *lineEdit_5;
    QLabel *label_14;
    QLineEdit *lineEdit_6;
    QLabel *label_15;
    QLineEdit *lineEdit_7;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *Rename)
    {
        if (Rename->objectName().isEmpty())
            Rename->setObjectName(QStringLiteral("Rename"));
        Rename->resize(1236, 556);
        gridLayout = new QGridLayout(Rename);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(Rename);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(Rename);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(Rename);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        spinBox = new QSpinBox(Rename);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(9999);

        horizontalLayout_4->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        checkBox = new QCheckBox(Rename);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_5->addWidget(checkBox);

        spinBox_2 = new QSpinBox(Rename);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));

        horizontalLayout_5->addWidget(spinBox_2);

        label_5 = new QLabel(Rename);
        label_5->setObjectName(QStringLiteral("label_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(label_5);

        spinBox_3 = new QSpinBox(Rename);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));

        horizontalLayout_5->addWidget(spinBox_3);

        label_6 = new QLabel(Rename);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(label_6);

        spinBox_4 = new QSpinBox(Rename);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));

        horizontalLayout_5->addWidget(spinBox_4);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(Rename);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(Rename);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_2);

        label_3 = new QLabel(Rename);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit_3 = new QLineEdit(Rename);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_7 = new QLabel(Rename);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_6->addWidget(label_7);

        lineEdit_4 = new QLineEdit(Rename);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        sizePolicy.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout_6);

        tableWidget = new QTableWidget(Rename);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy3);
        tableWidget->setColumnCount(2);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setDefaultSectionSize(200);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton = new QPushButton(Rename);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(Rename);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_3 = new QPushButton(Rename);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        customPlot = new QCustomPlot(Rename);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy4);

        verticalLayout_2->addWidget(customPlot);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_8 = new QLabel(Rename);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_7->addWidget(label_8);

        doubleSpinBox = new QDoubleSpinBox(Rename);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setDecimals(4);
        doubleSpinBox->setMaximum(9999.99);

        horizontalLayout_7->addWidget(doubleSpinBox);

        label_9 = new QLabel(Rename);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_7->addWidget(label_9);

        doubleSpinBox_2 = new QDoubleSpinBox(Rename);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setDecimals(4);
        doubleSpinBox_2->setMaximum(9999.99);

        horizontalLayout_7->addWidget(doubleSpinBox_2);

        label_10 = new QLabel(Rename);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_7->addWidget(label_10);

        doubleSpinBox_3 = new QDoubleSpinBox(Rename);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setDecimals(4);
        doubleSpinBox_3->setMaximum(9999.99);

        horizontalLayout_7->addWidget(doubleSpinBox_3);

        label_11 = new QLabel(Rename);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_7->addWidget(label_11);

        doubleSpinBox_4 = new QDoubleSpinBox(Rename);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setDecimals(4);
        doubleSpinBox_4->setMaximum(9999.99);

        horizontalLayout_7->addWidget(doubleSpinBox_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_12 = new QLabel(Rename);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_8->addWidget(label_12);

        spinBox_5 = new QSpinBox(Rename);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));
        spinBox_5->setMinimum(1);
        spinBox_5->setMaximum(999);

        horizontalLayout_8->addWidget(spinBox_5);

        lineEdit_8 = new QLineEdit(Rename);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setEnabled(false);
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(lineEdit_8->sizePolicy().hasHeightForWidth());
        lineEdit_8->setSizePolicy(sizePolicy5);

        horizontalLayout_8->addWidget(lineEdit_8);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);


        horizontalLayout_7->addLayout(horizontalLayout_8);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        comboBox = new QComboBox(Rename);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(comboBox);

        label_13 = new QLabel(Rename);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_9->addWidget(label_13);

        lineEdit_5 = new QLineEdit(Rename);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        sizePolicy2.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(lineEdit_5);

        label_14 = new QLabel(Rename);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_9->addWidget(label_14);

        lineEdit_6 = new QLineEdit(Rename);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        sizePolicy2.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(lineEdit_6);

        label_15 = new QLabel(Rename);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_9->addWidget(label_15);

        lineEdit_7 = new QLineEdit(Rename);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        sizePolicy2.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(lineEdit_7);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_9);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);


        retranslateUi(Rename);
        QObject::connect(pushButton_3, SIGNAL(clicked()), Rename, SLOT(close()));

        QMetaObject::connectSlotsByName(Rename);
    } // setupUi

    void retranslateUi(QDialog *Rename)
    {
        Rename->setWindowTitle(QApplication::translate("Rename", "Dialog", 0));
        label->setText(QApplication::translate("Rename", "Path to files:", 0));
        label_4->setText(QApplication::translate("Rename", "Number of Files:", 0));
        checkBox->setText(QApplication::translate("Rename", "Reject file", 0));
        label_5->setText(QApplication::translate("Rename", ",", 0));
        label_6->setText(QApplication::translate("Rename", "and", 0));
        label_2->setText(QApplication::translate("Rename", "New Name:", 0));
        label_3->setText(QApplication::translate("Rename", "*", 0));
        label_7->setText(QApplication::translate("Rename", "Save Table As:", 0));
        pushButton->setText(QApplication::translate("Rename", "List Files", 0));
        pushButton_2->setText(QApplication::translate("Rename", "Rename", 0));
        pushButton_3->setText(QApplication::translate("Rename", "Close", 0));
        label_8->setText(QApplication::translate("Rename", "x1:", 0));
        label_9->setText(QApplication::translate("Rename", "x2:", 0));
        label_10->setText(QApplication::translate("Rename", "y1:", 0));
        label_11->setText(QApplication::translate("Rename", "y2:", 0));
        label_12->setText(QApplication::translate("Rename", "Plot #:", 0));
        label_13->setText(QApplication::translate("Rename", "Extension:", 0));
        label_14->setText(QApplication::translate("Rename", "W-Col:", 0));
        label_15->setText(QApplication::translate("Rename", "I.Col", 0));
    } // retranslateUi

};

namespace Ui {
    class Rename: public Ui_Rename {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENAME_H
