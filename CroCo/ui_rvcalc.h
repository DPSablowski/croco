/********************************************************************************
** Form generated from reading UI file 'rvcalc.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RVCALC_H
#define UI_RVCALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
#include <QtWidgets/QVBoxLayout>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_RVCalc
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_8;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_4;
    QHBoxLayout *horizontalLayout_5;
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
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_9;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_10;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_11;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_14;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_18;
    QLineEdit *lineEdit_6;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_19;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_4;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_6;
    QLineEdit *lineEdit_8;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_20;
    QDoubleSpinBox *doubleSpinBox_15;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_21;
    QSpinBox *spinBox_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QCustomPlot *customPlot;
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
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_3;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QLabel *label_16;
    QLineEdit *lineEdit_4;
    QLabel *label_17;
    QLineEdit *lineEdit_5;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *RVCalc)
    {
        if (RVCalc->objectName().isEmpty())
            RVCalc->setObjectName(QStringLiteral("RVCalc"));
        RVCalc->resize(1136, 645);
        QFont font;
        font.setPointSize(9);
        RVCalc->setFont(font);
        gridLayout = new QGridLayout(RVCalc);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(RVCalc);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        doubleSpinBox = new QDoubleSpinBox(RVCalc);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(doubleSpinBox->sizePolicy().hasHeightForWidth());
        doubleSpinBox->setSizePolicy(sizePolicy);
        doubleSpinBox->setDecimals(4);
        doubleSpinBox->setMaximum(999);

        horizontalLayout->addWidget(doubleSpinBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(RVCalc);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_8->addWidget(label_8);

        doubleSpinBox_8 = new QDoubleSpinBox(RVCalc);
        doubleSpinBox_8->setObjectName(QStringLiteral("doubleSpinBox_8"));
        sizePolicy.setHeightForWidth(doubleSpinBox_8->sizePolicy().hasHeightForWidth());
        doubleSpinBox_8->setSizePolicy(sizePolicy);
        doubleSpinBox_8->setDecimals(6);
        doubleSpinBox_8->setMaximum(1);
        doubleSpinBox_8->setSingleStep(0.01);

        horizontalLayout_8->addWidget(doubleSpinBox_8);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(RVCalc);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        doubleSpinBox_3 = new QDoubleSpinBox(RVCalc);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        sizePolicy.setHeightForWidth(doubleSpinBox_3->sizePolicy().hasHeightForWidth());
        doubleSpinBox_3->setSizePolicy(sizePolicy);
        doubleSpinBox_3->setDecimals(4);
        doubleSpinBox_3->setMinimum(-999);
        doubleSpinBox_3->setMaximum(999);

        horizontalLayout_3->addWidget(doubleSpinBox_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(RVCalc);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        doubleSpinBox_4 = new QDoubleSpinBox(RVCalc);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        sizePolicy.setHeightForWidth(doubleSpinBox_4->sizePolicy().hasHeightForWidth());
        doubleSpinBox_4->setSizePolicy(sizePolicy);
        doubleSpinBox_4->setDecimals(4);
        doubleSpinBox_4->setMinimum(-999);
        doubleSpinBox_4->setMaximum(999);

        horizontalLayout_4->addWidget(doubleSpinBox_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(RVCalc);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        doubleSpinBox_5 = new QDoubleSpinBox(RVCalc);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        sizePolicy.setHeightForWidth(doubleSpinBox_5->sizePolicy().hasHeightForWidth());
        doubleSpinBox_5->setSizePolicy(sizePolicy);
        doubleSpinBox_5->setDecimals(4);
        doubleSpinBox_5->setMinimum(-999);
        doubleSpinBox_5->setMaximum(999.99);

        horizontalLayout_5->addWidget(doubleSpinBox_5);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(RVCalc);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        doubleSpinBox_2 = new QDoubleSpinBox(RVCalc);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        sizePolicy.setHeightForWidth(doubleSpinBox_2->sizePolicy().hasHeightForWidth());
        doubleSpinBox_2->setSizePolicy(sizePolicy);
        doubleSpinBox_2->setDecimals(4);
        doubleSpinBox_2->setMaximum(1e+07);

        horizontalLayout_2->addWidget(doubleSpinBox_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(RVCalc);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        doubleSpinBox_6 = new QDoubleSpinBox(RVCalc);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        sizePolicy.setHeightForWidth(doubleSpinBox_6->sizePolicy().hasHeightForWidth());
        doubleSpinBox_6->setSizePolicy(sizePolicy);
        doubleSpinBox_6->setDecimals(5);
        doubleSpinBox_6->setMinimum(-360);
        doubleSpinBox_6->setMaximum(360);

        horizontalLayout_6->addWidget(doubleSpinBox_6);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        comboBox = new QComboBox(RVCalc);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);

        horizontalLayout_20->addWidget(comboBox);

        pushButton_5 = new QPushButton(RVCalc);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);

        horizontalLayout_20->addWidget(pushButton_5);


        verticalLayout->addLayout(horizontalLayout_20);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_9 = new QLabel(RVCalc);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_9->addWidget(label_9);

        doubleSpinBox_9 = new QDoubleSpinBox(RVCalc);
        doubleSpinBox_9->setObjectName(QStringLiteral("doubleSpinBox_9"));
        sizePolicy.setHeightForWidth(doubleSpinBox_9->sizePolicy().hasHeightForWidth());
        doubleSpinBox_9->setSizePolicy(sizePolicy);
        doubleSpinBox_9->setDecimals(4);
        doubleSpinBox_9->setMaximum(1e+07);

        horizontalLayout_9->addWidget(doubleSpinBox_9);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_10 = new QLabel(RVCalc);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_10->addWidget(label_10);

        doubleSpinBox_10 = new QDoubleSpinBox(RVCalc);
        doubleSpinBox_10->setObjectName(QStringLiteral("doubleSpinBox_10"));
        doubleSpinBox_10->setEnabled(false);
        sizePolicy.setHeightForWidth(doubleSpinBox_10->sizePolicy().hasHeightForWidth());
        doubleSpinBox_10->setSizePolicy(sizePolicy);
        doubleSpinBox_10->setDecimals(4);
        doubleSpinBox_10->setMinimum(-999);
        doubleSpinBox_10->setMaximum(999);

        horizontalLayout_10->addWidget(doubleSpinBox_10);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_11 = new QLabel(RVCalc);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_11->addWidget(label_11);

        doubleSpinBox_11 = new QDoubleSpinBox(RVCalc);
        doubleSpinBox_11->setObjectName(QStringLiteral("doubleSpinBox_11"));
        doubleSpinBox_11->setEnabled(false);
        sizePolicy.setHeightForWidth(doubleSpinBox_11->sizePolicy().hasHeightForWidth());
        doubleSpinBox_11->setSizePolicy(sizePolicy);
        doubleSpinBox_11->setDecimals(4);
        doubleSpinBox_11->setMinimum(-999);
        doubleSpinBox_11->setMaximum(999);

        horizontalLayout_11->addWidget(doubleSpinBox_11);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_14 = new QLabel(RVCalc);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_14->addWidget(label_14);

        lineEdit_2 = new QLineEdit(RVCalc);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);

        horizontalLayout_14->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_18 = new QLabel(RVCalc);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_16->addWidget(label_18);

        lineEdit_6 = new QLineEdit(RVCalc);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        sizePolicy.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy);

        horizontalLayout_16->addWidget(lineEdit_6);


        verticalLayout->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_19 = new QLabel(RVCalc);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_17->addWidget(label_19);

        lineEdit_7 = new QLineEdit(RVCalc);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        sizePolicy.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy);

        horizontalLayout_17->addWidget(lineEdit_7);

        pushButton_4 = new QPushButton(RVCalc);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        horizontalLayout_17->addWidget(pushButton_4);


        verticalLayout->addLayout(horizontalLayout_17);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButton_6 = new QPushButton(RVCalc);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(pushButton_6);

        lineEdit_8 = new QLineEdit(RVCalc);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        sizePolicy1.setHeightForWidth(lineEdit_8->sizePolicy().hasHeightForWidth());
        lineEdit_8->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(lineEdit_8);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_20 = new QLabel(RVCalc);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_18->addWidget(label_20);

        doubleSpinBox_15 = new QDoubleSpinBox(RVCalc);
        doubleSpinBox_15->setObjectName(QStringLiteral("doubleSpinBox_15"));
        sizePolicy.setHeightForWidth(doubleSpinBox_15->sizePolicy().hasHeightForWidth());
        doubleSpinBox_15->setSizePolicy(sizePolicy);

        horizontalLayout_18->addWidget(doubleSpinBox_15);


        verticalLayout->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        label_21 = new QLabel(RVCalc);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_19->addWidget(label_21);

        spinBox_2 = new QSpinBox(RVCalc);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setEnabled(false);
        sizePolicy.setHeightForWidth(spinBox_2->sizePolicy().hasHeightForWidth());
        spinBox_2->setSizePolicy(sizePolicy);
        spinBox_2->setMaximum(999);

        horizontalLayout_19->addWidget(spinBox_2);


        verticalLayout->addLayout(horizontalLayout_19);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        pushButton = new QPushButton(RVCalc);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout_12->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_12);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        line = new QFrame(RVCalc);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        customPlot = new QCustomPlot(RVCalc);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(customPlot);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_12 = new QLabel(RVCalc);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_13->addWidget(label_12);

        doubleSpinBox_12 = new QDoubleSpinBox(RVCalc);
        doubleSpinBox_12->setObjectName(QStringLiteral("doubleSpinBox_12"));
        doubleSpinBox_12->setDecimals(4);
        doubleSpinBox_12->setMaximum(1e+07);

        horizontalLayout_13->addWidget(doubleSpinBox_12);

        doubleSpinBox_13 = new QDoubleSpinBox(RVCalc);
        doubleSpinBox_13->setObjectName(QStringLiteral("doubleSpinBox_13"));
        doubleSpinBox_13->setDecimals(4);
        doubleSpinBox_13->setMaximum(1e+07);

        horizontalLayout_13->addWidget(doubleSpinBox_13);

        pushButton_2 = new QPushButton(RVCalc);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        horizontalLayout_13->addWidget(pushButton_2);

        label_13 = new QLabel(RVCalc);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_13->addWidget(label_13);

        doubleSpinBox_14 = new QDoubleSpinBox(RVCalc);
        doubleSpinBox_14->setObjectName(QStringLiteral("doubleSpinBox_14"));
        sizePolicy.setHeightForWidth(doubleSpinBox_14->sizePolicy().hasHeightForWidth());
        doubleSpinBox_14->setSizePolicy(sizePolicy);
        doubleSpinBox_14->setMaximum(1e+07);

        horizontalLayout_13->addWidget(doubleSpinBox_14);

        checkBox = new QCheckBox(RVCalc);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_13->addWidget(checkBox);

        lineEdit = new QLineEdit(RVCalc);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_13->addWidget(lineEdit);

        checkBox_2 = new QCheckBox(RVCalc);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        horizontalLayout_13->addWidget(checkBox_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_13);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_15 = new QLabel(RVCalc);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_15->addWidget(label_15);

        spinBox = new QSpinBox(RVCalc);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);
        spinBox->setValue(9);

        horizontalLayout_15->addWidget(spinBox);

        pushButton_3 = new QPushButton(RVCalc);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        horizontalLayout_15->addWidget(pushButton_3);

        lineEdit_3 = new QLineEdit(RVCalc);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);

        horizontalLayout_15->addWidget(lineEdit_3);

        checkBox_3 = new QCheckBox(RVCalc);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        horizontalLayout_15->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(RVCalc);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        horizontalLayout_15->addWidget(checkBox_4);

        label_16 = new QLabel(RVCalc);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_15->addWidget(label_16);

        lineEdit_4 = new QLineEdit(RVCalc);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        sizePolicy.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy);

        horizontalLayout_15->addWidget(lineEdit_4);

        label_17 = new QLabel(RVCalc);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_15->addWidget(label_17);

        lineEdit_5 = new QLineEdit(RVCalc);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        sizePolicy.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy);

        horizontalLayout_15->addWidget(lineEdit_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_15);


        gridLayout->addLayout(verticalLayout_2, 0, 2, 1, 1);


        retranslateUi(RVCalc);
        QObject::connect(pushButton, SIGNAL(clicked()), RVCalc, SLOT(close()));

        QMetaObject::connectSlotsByName(RVCalc);
    } // setupUi

    void retranslateUi(QDialog *RVCalc)
    {
        RVCalc->setWindowTitle(QApplication::translate("RVCalc", "Dialog", 0));
        label->setText(QApplication::translate("RVCalc", "Period:", 0));
        label_8->setText(QApplication::translate("RVCalc", "Eccentricity:", 0));
        label_3->setText(QApplication::translate("RVCalc", "Systemic Velocity:", 0));
        label_4->setText(QApplication::translate("RVCalc", "Amplitude A:", 0));
        label_5->setText(QApplication::translate("RVCalc", "Amplitude B:", 0));
        label_2->setText(QApplication::translate("RVCalc", "Periastron Passage:", 0));
        label_6->setText(QApplication::translate("RVCalc", "Longitude of Periastron A:", 0));
        pushButton_5->setText(QApplication::translate("RVCalc", "Load", 0));
        label_9->setText(QApplication::translate("RVCalc", "Time:", 0));
        label_10->setText(QApplication::translate("RVCalc", "RV A:", 0));
        label_11->setText(QApplication::translate("RVCalc", "RV B:", 0));
        label_14->setText(QApplication::translate("RVCalc", "Work Path:", 0));
        label_18->setText(QApplication::translate("RVCalc", "Times:", 0));
        label_19->setText(QApplication::translate("RVCalc", "Output:", 0));
        pushButton_4->setText(QApplication::translate("RVCalc", "Calculate", 0));
        pushButton_6->setText(QApplication::translate("RVCalc", "Res", 0));
        label_20->setText(QApplication::translate("RVCalc", "Resolution [km/s]:", 0));
        label_21->setText(QApplication::translate("RVCalc", "# Independent", 0));
        pushButton->setText(QApplication::translate("RVCalc", "Close", 0));
        label_12->setText(QApplication::translate("RVCalc", "Range:", 0));
        pushButton_2->setText(QApplication::translate("RVCalc", "Show", 0));
        label_13->setText(QApplication::translate("RVCalc", "Subtract", 0));
        checkBox->setText(QApplication::translate("RVCalc", "data from file:", 0));
        checkBox_2->setText(QApplication::translate("RVCalc", "mod(P)", 0));
        label_15->setText(QApplication::translate("RVCalc", "Font Size", 0));
        pushButton_3->setText(QApplication::translate("RVCalc", "Save As", 0));
        checkBox_3->setText(QApplication::translate("RVCalc", "pdf", 0));
        checkBox_4->setText(QApplication::translate("RVCalc", "png", 0));
        label_16->setText(QApplication::translate("RVCalc", "x Label:", 0));
        label_17->setText(QApplication::translate("RVCalc", "y Label:", 0));
    } // retranslateUi

};

namespace Ui {
    class RVCalc: public Ui_RVCalc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RVCALC_H
