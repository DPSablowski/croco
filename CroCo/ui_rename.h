/********************************************************************************
** Form generated from reading UI file 'rename.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENAME_H
#define UI_RENAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
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
    QCheckBox *checkBox_2;
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
    QVBoxLayout *verticalLayout_3;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *lineEdit_9;
    QLabel *label_17;
    QLineEdit *lineEdit_10;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_18;
    QSpinBox *spinBox_6;
    QLabel *label_19;
    QSpinBox *spinBox_7;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_20;
    QSpinBox *spinBox_8;
    QPushButton *pushButton_4;
    QFrame *line;
    QLabel *label_21;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_22;
    QLineEdit *lineEdit_11;
    QLabel *label_24;
    QLineEdit *lineEdit_13;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_23;
    QLineEdit *lineEdit_12;
    QLabel *label_25;
    QLineEdit *lineEdit_14;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_26;
    QLineEdit *lineEdit_15;
    QLabel *label_27;
    QLineEdit *lineEdit_16;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_28;
    QSpinBox *spinBox_9;
    QLabel *label_29;
    QSpinBox *spinBox_10;
    QHBoxLayout *horizontalLayout_15;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QPushButton *pushButton_5;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Rename)
    {
        if (Rename->objectName().isEmpty())
            Rename->setObjectName(QString::fromUtf8("Rename"));
        Rename->resize(1841, 556);
        gridLayout = new QGridLayout(Rename);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(Rename);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(Rename);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit);

        checkBox_2 = new QCheckBox(Rename);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        horizontalLayout_2->addWidget(checkBox_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(Rename);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        spinBox = new QSpinBox(Rename);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(9999);

        horizontalLayout_4->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        checkBox = new QCheckBox(Rename);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout_5->addWidget(checkBox);

        spinBox_2 = new QSpinBox(Rename);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        horizontalLayout_5->addWidget(spinBox_2);

        label_5 = new QLabel(Rename);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(label_5);

        spinBox_3 = new QSpinBox(Rename);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));

        horizontalLayout_5->addWidget(spinBox_3);

        label_6 = new QLabel(Rename);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(label_6);

        spinBox_4 = new QSpinBox(Rename);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));

        horizontalLayout_5->addWidget(spinBox_4);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(Rename);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(Rename);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_2);

        label_3 = new QLabel(Rename);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit_3 = new QLineEdit(Rename);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(Rename);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        lineEdit_4 = new QLineEdit(Rename);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        sizePolicy.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout_6);

        tableWidget = new QTableWidget(Rename);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
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
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton = new QPushButton(Rename);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(Rename);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_3 = new QPushButton(Rename);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        customPlot = new QCustomPlot(Rename);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy4);

        verticalLayout_2->addWidget(customPlot);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_8 = new QLabel(Rename);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_7->addWidget(label_8);

        doubleSpinBox = new QDoubleSpinBox(Rename);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setDecimals(4);
        doubleSpinBox->setMaximum(9999.989999999999782);

        horizontalLayout_7->addWidget(doubleSpinBox);

        label_9 = new QLabel(Rename);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_7->addWidget(label_9);

        doubleSpinBox_2 = new QDoubleSpinBox(Rename);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setDecimals(4);
        doubleSpinBox_2->setMaximum(9999.989999999999782);

        horizontalLayout_7->addWidget(doubleSpinBox_2);

        label_10 = new QLabel(Rename);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_7->addWidget(label_10);

        doubleSpinBox_3 = new QDoubleSpinBox(Rename);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setDecimals(4);
        doubleSpinBox_3->setMaximum(9999.989999999999782);

        horizontalLayout_7->addWidget(doubleSpinBox_3);

        label_11 = new QLabel(Rename);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_7->addWidget(label_11);

        doubleSpinBox_4 = new QDoubleSpinBox(Rename);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setDecimals(4);
        doubleSpinBox_4->setMaximum(9999.989999999999782);

        horizontalLayout_7->addWidget(doubleSpinBox_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_12 = new QLabel(Rename);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_8->addWidget(label_12);

        spinBox_5 = new QSpinBox(Rename);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setMinimum(1);
        spinBox_5->setMaximum(999);

        horizontalLayout_8->addWidget(spinBox_5);

        lineEdit_8 = new QLineEdit(Rename);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
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
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        comboBox = new QComboBox(Rename);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(comboBox);

        label_13 = new QLabel(Rename);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_9->addWidget(label_13);

        lineEdit_5 = new QLineEdit(Rename);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        sizePolicy2.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(lineEdit_5);

        label_14 = new QLabel(Rename);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_9->addWidget(label_14);

        lineEdit_6 = new QLineEdit(Rename);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        sizePolicy2.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(lineEdit_6);

        label_15 = new QLabel(Rename);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_9->addWidget(label_15);

        lineEdit_7 = new QLineEdit(Rename);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        sizePolicy2.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(lineEdit_7);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_9);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_16 = new QLabel(Rename);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout_3->addWidget(label_16);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        lineEdit_9 = new QLineEdit(Rename);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        sizePolicy.setHeightForWidth(lineEdit_9->sizePolicy().hasHeightForWidth());
        lineEdit_9->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(lineEdit_9);

        label_17 = new QLabel(Rename);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        sizePolicy1.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy1);

        horizontalLayout_10->addWidget(label_17);

        lineEdit_10 = new QLineEdit(Rename);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        sizePolicy.setHeightForWidth(lineEdit_10->sizePolicy().hasHeightForWidth());
        lineEdit_10->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(lineEdit_10);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_18 = new QLabel(Rename);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_11->addWidget(label_18);

        spinBox_6 = new QSpinBox(Rename);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));
        sizePolicy.setHeightForWidth(spinBox_6->sizePolicy().hasHeightForWidth());
        spinBox_6->setSizePolicy(sizePolicy);
        spinBox_6->setMaximum(9999);

        horizontalLayout_11->addWidget(spinBox_6);

        label_19 = new QLabel(Rename);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        sizePolicy1.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy1);

        horizontalLayout_11->addWidget(label_19);

        spinBox_7 = new QSpinBox(Rename);
        spinBox_7->setObjectName(QString::fromUtf8("spinBox_7"));
        sizePolicy.setHeightForWidth(spinBox_7->sizePolicy().hasHeightForWidth());
        spinBox_7->setSizePolicy(sizePolicy);
        spinBox_7->setMaximum(9999);

        horizontalLayout_11->addWidget(spinBox_7);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_20 = new QLabel(Rename);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_12->addWidget(label_20);

        spinBox_8 = new QSpinBox(Rename);
        spinBox_8->setObjectName(QString::fromUtf8("spinBox_8"));
        sizePolicy5.setHeightForWidth(spinBox_8->sizePolicy().hasHeightForWidth());
        spinBox_8->setSizePolicy(sizePolicy5);
        spinBox_8->setMaximum(9999);

        horizontalLayout_12->addWidget(spinBox_8);

        pushButton_4 = new QPushButton(Rename);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        horizontalLayout_12->addWidget(pushButton_4);


        verticalLayout_3->addLayout(horizontalLayout_12);

        line = new QFrame(Rename);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        label_21 = new QLabel(Rename);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        verticalLayout_3->addWidget(label_21);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_22 = new QLabel(Rename);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_13->addWidget(label_22);

        lineEdit_11 = new QLineEdit(Rename);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));
        sizePolicy.setHeightForWidth(lineEdit_11->sizePolicy().hasHeightForWidth());
        lineEdit_11->setSizePolicy(sizePolicy);

        horizontalLayout_13->addWidget(lineEdit_11);

        label_24 = new QLabel(Rename);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_13->addWidget(label_24);

        lineEdit_13 = new QLineEdit(Rename);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));
        sizePolicy.setHeightForWidth(lineEdit_13->sizePolicy().hasHeightForWidth());
        lineEdit_13->setSizePolicy(sizePolicy);
        lineEdit_13->setMinimumSize(QSize(50, 0));
        lineEdit_13->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_13->addWidget(lineEdit_13);


        verticalLayout_3->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_23 = new QLabel(Rename);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_14->addWidget(label_23);

        lineEdit_12 = new QLineEdit(Rename);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));
        sizePolicy.setHeightForWidth(lineEdit_12->sizePolicy().hasHeightForWidth());
        lineEdit_12->setSizePolicy(sizePolicy);

        horizontalLayout_14->addWidget(lineEdit_12);

        label_25 = new QLabel(Rename);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout_14->addWidget(label_25);

        lineEdit_14 = new QLineEdit(Rename);
        lineEdit_14->setObjectName(QString::fromUtf8("lineEdit_14"));
        sizePolicy.setHeightForWidth(lineEdit_14->sizePolicy().hasHeightForWidth());
        lineEdit_14->setSizePolicy(sizePolicy);
        lineEdit_14->setMinimumSize(QSize(50, 0));
        lineEdit_14->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_14->addWidget(lineEdit_14);


        verticalLayout_3->addLayout(horizontalLayout_14);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_26 = new QLabel(Rename);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        horizontalLayout_16->addWidget(label_26);

        lineEdit_15 = new QLineEdit(Rename);
        lineEdit_15->setObjectName(QString::fromUtf8("lineEdit_15"));
        sizePolicy.setHeightForWidth(lineEdit_15->sizePolicy().hasHeightForWidth());
        lineEdit_15->setSizePolicy(sizePolicy);

        horizontalLayout_16->addWidget(lineEdit_15);

        label_27 = new QLabel(Rename);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        horizontalLayout_16->addWidget(label_27);

        lineEdit_16 = new QLineEdit(Rename);
        lineEdit_16->setObjectName(QString::fromUtf8("lineEdit_16"));
        sizePolicy.setHeightForWidth(lineEdit_16->sizePolicy().hasHeightForWidth());
        lineEdit_16->setSizePolicy(sizePolicy);
        lineEdit_16->setMinimumSize(QSize(50, 0));
        lineEdit_16->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_16->addWidget(lineEdit_16);


        verticalLayout_3->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_28 = new QLabel(Rename);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        horizontalLayout_17->addWidget(label_28);

        spinBox_9 = new QSpinBox(Rename);
        spinBox_9->setObjectName(QString::fromUtf8("spinBox_9"));
        spinBox_9->setMaximum(9999);

        horizontalLayout_17->addWidget(spinBox_9);

        label_29 = new QLabel(Rename);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        horizontalLayout_17->addWidget(label_29);

        spinBox_10 = new QSpinBox(Rename);
        spinBox_10->setObjectName(QString::fromUtf8("spinBox_10"));
        spinBox_10->setMaximum(9999);

        horizontalLayout_17->addWidget(spinBox_10);


        verticalLayout_3->addLayout(horizontalLayout_17);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        checkBox_3 = new QCheckBox(Rename);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        horizontalLayout_15->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(Rename);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        horizontalLayout_15->addWidget(checkBox_4);


        verticalLayout_3->addLayout(horizontalLayout_15);

        pushButton_5 = new QPushButton(Rename);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButton_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_3, 0, 2, 1, 1);


        retranslateUi(Rename);
        QObject::connect(pushButton_3, SIGNAL(clicked()), Rename, SLOT(close()));

        QMetaObject::connectSlotsByName(Rename);
    } // setupUi

    void retranslateUi(QDialog *Rename)
    {
        Rename->setWindowTitle(QApplication::translate("Rename", "Dialog", nullptr));
        label->setText(QApplication::translate("Rename", "Path to files:", nullptr));
        checkBox_2->setText(QApplication::translate("Rename", "keep all files", nullptr));
        label_4->setText(QApplication::translate("Rename", "Number of Files:", nullptr));
        checkBox->setText(QApplication::translate("Rename", "Reject file", nullptr));
        label_5->setText(QApplication::translate("Rename", ",", nullptr));
        label_6->setText(QApplication::translate("Rename", "and", nullptr));
        label_2->setText(QApplication::translate("Rename", "New Name:", nullptr));
        label_3->setText(QApplication::translate("Rename", "*", nullptr));
        label_7->setText(QApplication::translate("Rename", "Save Table As:", nullptr));
        pushButton->setText(QApplication::translate("Rename", "List Files", nullptr));
        pushButton_2->setText(QApplication::translate("Rename", "Rename", nullptr));
        pushButton_3->setText(QApplication::translate("Rename", "Close", nullptr));
        label_8->setText(QApplication::translate("Rename", "x1:", nullptr));
        label_9->setText(QApplication::translate("Rename", "x2:", nullptr));
        label_10->setText(QApplication::translate("Rename", "y1:", nullptr));
        label_11->setText(QApplication::translate("Rename", "y2:", nullptr));
        label_12->setText(QApplication::translate("Rename", "Plot #:", nullptr));
        label_13->setText(QApplication::translate("Rename", "Extension:", nullptr));
        label_14->setText(QApplication::translate("Rename", "W-Col:", nullptr));
        label_15->setText(QApplication::translate("Rename", "I.Col", nullptr));
        label_16->setText(QApplication::translate("Rename", "<html><head/><body><p><span style=\" font-weight:600;\">Renumerate</span></p></body></html>", nullptr));
        label_17->setText(QApplication::translate("Rename", "*", nullptr));
        label_18->setText(QApplication::translate("Rename", "from", nullptr));
        label_19->setText(QApplication::translate("Rename", "to", nullptr));
        label_20->setText(QApplication::translate("Rename", "New start from", nullptr));
        pushButton_4->setText(QApplication::translate("Rename", "Do", nullptr));
        label_21->setText(QApplication::translate("Rename", "<html><head/><body><p><span style=\" font-weight:600;\">Combine Sequences</span></p></body></html>", nullptr));
        label_22->setText(QApplication::translate("Rename", "Sequence 1:", nullptr));
        label_24->setText(QApplication::translate("Rename", "*.", nullptr));
        label_23->setText(QApplication::translate("Rename", "Sequence 2:", nullptr));
        label_25->setText(QApplication::translate("Rename", "*.", nullptr));
        label_26->setText(QApplication::translate("Rename", "Out 1 & 2:", nullptr));
        label_27->setText(QApplication::translate("Rename", "*.", nullptr));
        label_28->setText(QApplication::translate("Rename", "From", nullptr));
        label_29->setText(QApplication::translate("Rename", "to", nullptr));
        checkBox_3->setText(QApplication::translate("Rename", "2-column", nullptr));
        checkBox_4->setText(QApplication::translate("Rename", "3-column", nullptr));
        pushButton_5->setText(QApplication::translate("Rename", "Combine", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Rename: public Ui_Rename {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENAME_H
