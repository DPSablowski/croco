/********************************************************************************
** Form generated from reading UI file 'rvcalc.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RVCALC_H
#define UI_RVCALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_RVCalc
{
public:
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QCustomPlot *customPlot;
    QHBoxLayout *horizontalLayout_26;
    QCheckBox *checkBox_10;
    QDoubleSpinBox *doubleSpinBox_7;
    QLabel *label_26;
    QDoubleSpinBox *doubleSpinBox_16;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBox_12;
    QDoubleSpinBox *doubleSpinBox_13;
    QPushButton *pushButton_2;
    QLabel *label_13;
    QDoubleSpinBox *doubleSpinBox_14;
    QCheckBox *checkBox;
    QLineEdit *lineEdit;
    QCheckBox *checkBox_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_15;
    QSpinBox *spinBox;
    QSpinBox *spinBox_5;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_3;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QLabel *label_16;
    QLineEdit *lineEdit_4;
    QLabel *label_17;
    QLineEdit *lineEdit_5;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_14;
    QLineEdit *lineEdit_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_8;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_6;
    QHBoxLayout *horizontalLayout_20;
    QComboBox *comboBox;
    QPushButton *pushButton_5;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_9;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_10;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_11;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_18;
    QLineEdit *lineEdit_6;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_7;
    QLineEdit *lineEdit_9;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_19;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_4;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_6;
    QLineEdit *lineEdit_8;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_20;
    QDoubleSpinBox *doubleSpinBox_15;
    QSpinBox *spinBox_2;
    QHBoxLayout *horizontalLayout_19;
    QPushButton *pushButton_7;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_9;
    QHBoxLayout *horizontalLayout_22;
    QCheckBox *checkBox_5;
    QLineEdit *lineEdit_10;
    QLabel *label_21;
    QLineEdit *lineEdit_11;
    QHBoxLayout *horizontalLayout_23;
    QPushButton *pushButton_8;
    QSpinBox *spinBox_3;
    QLabel *label_22;
    QSpinBox *spinBox_4;
    QCheckBox *checkBox_8;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_23;
    QLineEdit *lineEdit_12;
    QPushButton *pushButton_10;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_25;
    QPushButton *pushButton_11;
    QLineEdit *lineEdit_13;
    QLabel *label_24;
    QSpinBox *spinBox_6;
    QLabel *label_25;
    QSpinBox *spinBox_7;
    QLineEdit *lineEdit_14;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *pushButton;
    QPushButton *pushButton_9;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *RVCalc)
    {
        if (RVCalc->objectName().isEmpty())
            RVCalc->setObjectName(QString::fromUtf8("RVCalc"));
        RVCalc->resize(1158, 700);
        QFont font;
        font.setPointSize(9);
        RVCalc->setFont(font);
        gridLayout_2 = new QGridLayout(RVCalc);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        scrollArea = new QScrollArea(RVCalc);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -105, 1124, 785));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        customPlot = new QCustomPlot(scrollAreaWidgetContents);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(customPlot);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        checkBox_10 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(checkBox_10->sizePolicy().hasHeightForWidth());
        checkBox_10->setSizePolicy(sizePolicy1);

        horizontalLayout_26->addWidget(checkBox_10);

        doubleSpinBox_7 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_7->setObjectName(QString::fromUtf8("doubleSpinBox_7"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_7->sizePolicy().hasHeightForWidth());
        doubleSpinBox_7->setSizePolicy(sizePolicy1);
        doubleSpinBox_7->setMaximum(9999.989999999999782);

        horizontalLayout_26->addWidget(doubleSpinBox_7);

        label_26 = new QLabel(scrollAreaWidgetContents);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy2);

        horizontalLayout_26->addWidget(label_26);

        doubleSpinBox_16 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_16->setObjectName(QString::fromUtf8("doubleSpinBox_16"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_16->sizePolicy().hasHeightForWidth());
        doubleSpinBox_16->setSizePolicy(sizePolicy1);
        doubleSpinBox_16->setMaximum(9999.989999999999782);

        horizontalLayout_26->addWidget(doubleSpinBox_16);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_26->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_26);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_13->addWidget(label_12);

        doubleSpinBox_12 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_12->setObjectName(QString::fromUtf8("doubleSpinBox_12"));
        doubleSpinBox_12->setDecimals(4);
        doubleSpinBox_12->setMaximum(9999999.990000000223517);

        horizontalLayout_13->addWidget(doubleSpinBox_12);

        doubleSpinBox_13 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_13->setObjectName(QString::fromUtf8("doubleSpinBox_13"));
        doubleSpinBox_13->setDecimals(4);
        doubleSpinBox_13->setMaximum(9999999.990000000223517);

        horizontalLayout_13->addWidget(doubleSpinBox_13);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);

        horizontalLayout_13->addWidget(pushButton_2);

        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_13->addWidget(label_13);

        doubleSpinBox_14 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_14->setObjectName(QString::fromUtf8("doubleSpinBox_14"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_14->sizePolicy().hasHeightForWidth());
        doubleSpinBox_14->setSizePolicy(sizePolicy1);
        doubleSpinBox_14->setMaximum(9999999.990000000223517);

        horizontalLayout_13->addWidget(doubleSpinBox_14);

        checkBox = new QCheckBox(scrollAreaWidgetContents);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout_13->addWidget(checkBox);

        lineEdit = new QLineEdit(scrollAreaWidgetContents);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy3);

        horizontalLayout_13->addWidget(lineEdit);

        checkBox_2 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        horizontalLayout_13->addWidget(checkBox_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_13);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_15 = new QLabel(scrollAreaWidgetContents);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_15->addWidget(label_15);

        spinBox = new QSpinBox(scrollAreaWidgetContents);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        sizePolicy1.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy1);
        spinBox->setValue(9);

        horizontalLayout_15->addWidget(spinBox);

        spinBox_5 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setMinimum(1);
        spinBox_5->setValue(2);

        horizontalLayout_15->addWidget(spinBox_5);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);

        horizontalLayout_15->addWidget(pushButton_3);

        lineEdit_3 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        sizePolicy1.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy1);

        horizontalLayout_15->addWidget(lineEdit_3);

        checkBox_3 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        horizontalLayout_15->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        horizontalLayout_15->addWidget(checkBox_4);

        label_16 = new QLabel(scrollAreaWidgetContents);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_15->addWidget(label_16);

        lineEdit_4 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        sizePolicy1.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy1);

        horizontalLayout_15->addWidget(lineEdit_4);

        label_17 = new QLabel(scrollAreaWidgetContents);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_15->addWidget(label_17);

        lineEdit_5 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        sizePolicy1.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy1);

        horizontalLayout_15->addWidget(lineEdit_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_15);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_14 = new QLabel(scrollAreaWidgetContents);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_14->addWidget(label_14);

        lineEdit_2 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);
        lineEdit_2->setMinimumSize(QSize(150, 0));

        horizontalLayout_14->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_14);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        doubleSpinBox = new QDoubleSpinBox(groupBox);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        sizePolicy1.setHeightForWidth(doubleSpinBox->sizePolicy().hasHeightForWidth());
        doubleSpinBox->setSizePolicy(sizePolicy1);
        doubleSpinBox->setDecimals(6);
        doubleSpinBox->setMaximum(999.000000000000000);

        horizontalLayout->addWidget(doubleSpinBox);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout->addWidget(label_8);

        doubleSpinBox_8 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_8->setObjectName(QString::fromUtf8("doubleSpinBox_8"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_8->sizePolicy().hasHeightForWidth());
        doubleSpinBox_8->setSizePolicy(sizePolicy1);
        doubleSpinBox_8->setDecimals(6);
        doubleSpinBox_8->setMaximum(1.000000000000000);
        doubleSpinBox_8->setSingleStep(0.010000000000000);

        horizontalLayout->addWidget(doubleSpinBox_8);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        doubleSpinBox_3 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_3->sizePolicy().hasHeightForWidth());
        doubleSpinBox_3->setSizePolicy(sizePolicy1);
        doubleSpinBox_3->setDecimals(4);
        doubleSpinBox_3->setMinimum(-999.000000000000000);
        doubleSpinBox_3->setMaximum(999.000000000000000);

        horizontalLayout_3->addWidget(doubleSpinBox_3);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        doubleSpinBox_4 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_4->sizePolicy().hasHeightForWidth());
        doubleSpinBox_4->setSizePolicy(sizePolicy1);
        doubleSpinBox_4->setDecimals(4);
        doubleSpinBox_4->setMinimum(-999.000000000000000);
        doubleSpinBox_4->setMaximum(999.000000000000000);

        horizontalLayout_4->addWidget(doubleSpinBox_4);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        doubleSpinBox_5 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_5->sizePolicy().hasHeightForWidth());
        doubleSpinBox_5->setSizePolicy(sizePolicy1);
        doubleSpinBox_5->setDecimals(4);
        doubleSpinBox_5->setMinimum(-999.000000000000000);
        doubleSpinBox_5->setMaximum(999.990000000000009);

        horizontalLayout_4->addWidget(doubleSpinBox_5);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        doubleSpinBox_2 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_2->sizePolicy().hasHeightForWidth());
        doubleSpinBox_2->setSizePolicy(sizePolicy1);
        doubleSpinBox_2->setDecimals(6);
        doubleSpinBox_2->setMaximum(9999999.000000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        doubleSpinBox_6 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_6->setObjectName(QString::fromUtf8("doubleSpinBox_6"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_6->sizePolicy().hasHeightForWidth());
        doubleSpinBox_6->setSizePolicy(sizePolicy1);
        doubleSpinBox_6->setDecimals(5);
        doubleSpinBox_6->setMinimum(-360.000000000000000);
        doubleSpinBox_6->setMaximum(360.000000000000000);

        horizontalLayout_6->addWidget(doubleSpinBox_6);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);

        horizontalLayout_20->addWidget(comboBox);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);

        horizontalLayout_20->addWidget(pushButton_5);


        verticalLayout_3->addLayout(horizontalLayout_20);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_9->addWidget(label_9);

        doubleSpinBox_9 = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_9->setObjectName(QString::fromUtf8("doubleSpinBox_9"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_9->sizePolicy().hasHeightForWidth());
        doubleSpinBox_9->setSizePolicy(sizePolicy1);
        doubleSpinBox_9->setDecimals(4);
        doubleSpinBox_9->setMaximum(9999999.000000000000000);

        horizontalLayout_9->addWidget(doubleSpinBox_9);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_10->addWidget(label_10);

        doubleSpinBox_10 = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_10->setObjectName(QString::fromUtf8("doubleSpinBox_10"));
        doubleSpinBox_10->setEnabled(false);
        sizePolicy1.setHeightForWidth(doubleSpinBox_10->sizePolicy().hasHeightForWidth());
        doubleSpinBox_10->setSizePolicy(sizePolicy1);
        doubleSpinBox_10->setDecimals(4);
        doubleSpinBox_10->setMinimum(-999.000000000000000);
        doubleSpinBox_10->setMaximum(999.000000000000000);

        horizontalLayout_10->addWidget(doubleSpinBox_10);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_10->addWidget(label_11);

        doubleSpinBox_11 = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_11->setObjectName(QString::fromUtf8("doubleSpinBox_11"));
        doubleSpinBox_11->setEnabled(false);
        sizePolicy1.setHeightForWidth(doubleSpinBox_11->sizePolicy().hasHeightForWidth());
        doubleSpinBox_11->setSizePolicy(sizePolicy1);
        doubleSpinBox_11->setDecimals(4);
        doubleSpinBox_11->setMinimum(-999.000000000000000);
        doubleSpinBox_11->setMaximum(999.000000000000000);

        horizontalLayout_10->addWidget(doubleSpinBox_11);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_16->addWidget(label_18);

        lineEdit_6 = new QLineEdit(groupBox_2);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        sizePolicy1.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy1);

        horizontalLayout_16->addWidget(lineEdit_6);


        verticalLayout_4->addLayout(horizontalLayout_16);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_21->addWidget(label_7);

        lineEdit_9 = new QLineEdit(groupBox_2);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        sizePolicy1.setHeightForWidth(lineEdit_9->sizePolicy().hasHeightForWidth());
        lineEdit_9->setSizePolicy(sizePolicy1);

        horizontalLayout_21->addWidget(lineEdit_9);


        verticalLayout_4->addLayout(horizontalLayout_21);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_17->addWidget(label_19);

        lineEdit_7 = new QLineEdit(groupBox_2);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        sizePolicy1.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy1);

        horizontalLayout_17->addWidget(lineEdit_7);

        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);

        horizontalLayout_17->addWidget(pushButton_4);


        verticalLayout_4->addLayout(horizontalLayout_17);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        pushButton_6 = new QPushButton(groupBox_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(pushButton_6);

        lineEdit_8 = new QLineEdit(groupBox_2);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        sizePolicy1.setHeightForWidth(lineEdit_8->sizePolicy().hasHeightForWidth());
        lineEdit_8->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(lineEdit_8);


        verticalLayout_4->addLayout(horizontalLayout_7);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_18->addWidget(label_20);

        doubleSpinBox_15 = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_15->setObjectName(QString::fromUtf8("doubleSpinBox_15"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_15->sizePolicy().hasHeightForWidth());
        doubleSpinBox_15->setSizePolicy(sizePolicy1);

        horizontalLayout_18->addWidget(doubleSpinBox_15);

        spinBox_2 = new QSpinBox(groupBox_3);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setEnabled(false);
        sizePolicy1.setHeightForWidth(spinBox_2->sizePolicy().hasHeightForWidth());
        spinBox_2->setSizePolicy(sizePolicy1);
        spinBox_2->setMaximum(999);

        horizontalLayout_18->addWidget(spinBox_2);


        verticalLayout_5->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        pushButton_7 = new QPushButton(groupBox_3);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);
        pushButton_7->setMinimumSize(QSize(90, 0));
        pushButton_7->setMaximumSize(QSize(90, 16777215));

        horizontalLayout_19->addWidget(pushButton_7);

        checkBox_6 = new QCheckBox(groupBox_3);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));

        horizontalLayout_19->addWidget(checkBox_6);

        checkBox_7 = new QCheckBox(groupBox_3);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));

        horizontalLayout_19->addWidget(checkBox_7);

        checkBox_9 = new QCheckBox(groupBox_3);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));

        horizontalLayout_19->addWidget(checkBox_9);


        verticalLayout_5->addLayout(horizontalLayout_19);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        checkBox_5 = new QCheckBox(groupBox_3);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        sizePolicy3.setHeightForWidth(checkBox_5->sizePolicy().hasHeightForWidth());
        checkBox_5->setSizePolicy(sizePolicy3);
        checkBox_5->setMinimumSize(QSize(85, 0));
        checkBox_5->setMaximumSize(QSize(85, 16777215));

        horizontalLayout_22->addWidget(checkBox_5);

        lineEdit_10 = new QLineEdit(groupBox_3);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        sizePolicy1.setHeightForWidth(lineEdit_10->sizePolicy().hasHeightForWidth());
        lineEdit_10->setSizePolicy(sizePolicy1);

        horizontalLayout_22->addWidget(lineEdit_10);

        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy4);

        horizontalLayout_22->addWidget(label_21);

        lineEdit_11 = new QLineEdit(groupBox_3);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));
        sizePolicy1.setHeightForWidth(lineEdit_11->sizePolicy().hasHeightForWidth());
        lineEdit_11->setSizePolicy(sizePolicy1);
        lineEdit_11->setMinimumSize(QSize(75, 0));
        lineEdit_11->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_22->addWidget(lineEdit_11);


        verticalLayout_5->addLayout(horizontalLayout_22);


        verticalLayout->addWidget(groupBox_3);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        pushButton_8 = new QPushButton(scrollAreaWidgetContents);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        sizePolicy1.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy1);

        horizontalLayout_23->addWidget(pushButton_8);

        spinBox_3 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        sizePolicy1.setHeightForWidth(spinBox_3->sizePolicy().hasHeightForWidth());
        spinBox_3->setSizePolicy(sizePolicy1);
        spinBox_3->setMaximum(9999);

        horizontalLayout_23->addWidget(spinBox_3);

        label_22 = new QLabel(scrollAreaWidgetContents);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        sizePolicy2.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy2);

        horizontalLayout_23->addWidget(label_22);

        spinBox_4 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        sizePolicy1.setHeightForWidth(spinBox_4->sizePolicy().hasHeightForWidth());
        spinBox_4->setSizePolicy(sizePolicy1);
        spinBox_4->setMaximum(9999);

        horizontalLayout_23->addWidget(spinBox_4);

        checkBox_8 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));

        horizontalLayout_23->addWidget(checkBox_8);


        verticalLayout->addLayout(horizontalLayout_23);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        label_23 = new QLabel(scrollAreaWidgetContents);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_24->addWidget(label_23);

        lineEdit_12 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));
        sizePolicy1.setHeightForWidth(lineEdit_12->sizePolicy().hasHeightForWidth());
        lineEdit_12->setSizePolicy(sizePolicy1);

        horizontalLayout_24->addWidget(lineEdit_12);

        pushButton_10 = new QPushButton(scrollAreaWidgetContents);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        sizePolicy1.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy1);

        horizontalLayout_24->addWidget(pushButton_10);


        verticalLayout->addLayout(horizontalLayout_24);

        line_4 = new QFrame(scrollAreaWidgetContents);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_4);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        pushButton_11 = new QPushButton(scrollAreaWidgetContents);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        horizontalLayout_25->addWidget(pushButton_11);

        lineEdit_13 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));

        horizontalLayout_25->addWidget(lineEdit_13);

        label_24 = new QLabel(scrollAreaWidgetContents);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_25->addWidget(label_24);

        spinBox_6 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));
        spinBox_6->setMaximum(999);

        horizontalLayout_25->addWidget(spinBox_6);

        label_25 = new QLabel(scrollAreaWidgetContents);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout_25->addWidget(label_25);

        spinBox_7 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_7->setObjectName(QString::fromUtf8("spinBox_7"));
        spinBox_7->setMaximum(999);

        horizontalLayout_25->addWidget(spinBox_7);

        lineEdit_14 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_14->setObjectName(QString::fromUtf8("lineEdit_14"));
        sizePolicy1.setHeightForWidth(lineEdit_14->sizePolicy().hasHeightForWidth());
        lineEdit_14->setSizePolicy(sizePolicy1);
        lineEdit_14->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_25->addWidget(lineEdit_14);


        verticalLayout->addLayout(horizontalLayout_25);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        horizontalLayout_12->addWidget(pushButton);

        pushButton_9 = new QPushButton(scrollAreaWidgetContents);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        sizePolicy1.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy1);

        horizontalLayout_12->addWidget(pushButton_9);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_12);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(RVCalc);
        QObject::connect(pushButton, SIGNAL(clicked()), RVCalc, SLOT(close()));

        QMetaObject::connectSlotsByName(RVCalc);
    } // setupUi

    void retranslateUi(QDialog *RVCalc)
    {
        RVCalc->setWindowTitle(QCoreApplication::translate("RVCalc", "Dialog", nullptr));
        checkBox_10->setText(QCoreApplication::translate("RVCalc", "y1:", nullptr));
        label_26->setText(QCoreApplication::translate("RVCalc", "y2:", nullptr));
        label_12->setText(QCoreApplication::translate("RVCalc", "Range:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("RVCalc", "Show", nullptr));
        label_13->setText(QCoreApplication::translate("RVCalc", "Subtract", nullptr));
        checkBox->setText(QCoreApplication::translate("RVCalc", "data from file:", nullptr));
        checkBox_2->setText(QCoreApplication::translate("RVCalc", "mod(P)", nullptr));
        label_15->setText(QCoreApplication::translate("RVCalc", "Font Size", nullptr));
        pushButton_3->setText(QCoreApplication::translate("RVCalc", "Save As", nullptr));
        checkBox_3->setText(QCoreApplication::translate("RVCalc", "pdf", nullptr));
        checkBox_4->setText(QCoreApplication::translate("RVCalc", "png", nullptr));
        label_16->setText(QCoreApplication::translate("RVCalc", "x Label:", nullptr));
        label_17->setText(QCoreApplication::translate("RVCalc", "y Label:", nullptr));
        label_14->setText(QCoreApplication::translate("RVCalc", "Work Path:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("RVCalc", "Orbit", nullptr));
        label->setText(QCoreApplication::translate("RVCalc", "Period:", nullptr));
        label_8->setText(QCoreApplication::translate("RVCalc", "Eccentricity:", nullptr));
        label_3->setText(QCoreApplication::translate("RVCalc", "Systemic Velocity:", nullptr));
        label_4->setText(QCoreApplication::translate("RVCalc", "Amplitude A:", nullptr));
        label_5->setText(QCoreApplication::translate("RVCalc", "Amplitude B:", nullptr));
        label_2->setText(QCoreApplication::translate("RVCalc", "Periastron Passage:", nullptr));
        label_6->setText(QCoreApplication::translate("RVCalc", "Longitude of Periastron A:", nullptr));
        pushButton_5->setText(QCoreApplication::translate("RVCalc", "Load", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("RVCalc", "Calculate RVs", nullptr));
        label_9->setText(QCoreApplication::translate("RVCalc", "Time:", nullptr));
        label_10->setText(QCoreApplication::translate("RVCalc", "RV A:", nullptr));
        label_11->setText(QCoreApplication::translate("RVCalc", "RV B:", nullptr));
        label_18->setText(QCoreApplication::translate("RVCalc", "Input File with Times:", nullptr));
        label_7->setText(QCoreApplication::translate("RVCalc", "Out RVs & Times:", nullptr));
        label_19->setText(QCoreApplication::translate("RVCalc", "Out RVs:", nullptr));
        pushButton_4->setText(QCoreApplication::translate("RVCalc", "Calculate", nullptr));
        pushButton_6->setText(QCoreApplication::translate("RVCalc", "Residuum", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("RVCalc", "Data-Set preparation for Disentanging", nullptr));
        label_20->setText(QCoreApplication::translate("RVCalc", "Resolution [km/s]:", nullptr));
        pushButton_7->setText(QCoreApplication::translate("RVCalc", "# Independent", nullptr));
        checkBox_6->setText(QCoreApplication::translate("RVCalc", "Iterative", nullptr));
        checkBox_7->setText(QCoreApplication::translate("RVCalc", "All @ Once", nullptr));
        checkBox_9->setText(QCoreApplication::translate("RVCalc", "single", nullptr));
        checkBox_5->setText(QCoreApplication::translate("RVCalc", "Files", nullptr));
        label_21->setText(QCoreApplication::translate("RVCalc", "*", nullptr));
        pushButton_8->setText(QCoreApplication::translate("RVCalc", "Reject File", nullptr));
        label_22->setText(QCoreApplication::translate("RVCalc", "of", nullptr));
        checkBox_8->setText(QCoreApplication::translate("RVCalc", "w/ RV", nullptr));
        label_23->setText(QCoreApplication::translate("RVCalc", "Reject from List", nullptr));
        pushButton_10->setText(QCoreApplication::translate("RVCalc", "Do", nullptr));
        pushButton_11->setText(QCoreApplication::translate("RVCalc", "Merge RVs", nullptr));
        label_24->setText(QCoreApplication::translate("RVCalc", "from", nullptr));
        label_25->setText(QCoreApplication::translate("RVCalc", "to", nullptr));
        pushButton->setText(QCoreApplication::translate("RVCalc", "Close", nullptr));
        pushButton_9->setText(QCoreApplication::translate("RVCalc", "Test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RVCalc: public Ui_RVCalc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RVCALC_H
