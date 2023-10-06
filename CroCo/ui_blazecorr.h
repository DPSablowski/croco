/********************************************************************************
** Form generated from reading UI file 'blazecorr.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLAZECORR_H
#define UI_BLAZECORR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_BlazeCorr
{
public:
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_20;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_16;
    QLineEdit *lineEdit_5;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_13;
    QSpinBox *spinBox_2;
    QCheckBox *checkBox_4;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_14;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_17;
    QLineEdit *lineEdit_6;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_15;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QCheckBox *checkBox_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBox_4;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_18;
    QSpinBox *spinBox_4;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_5;
    QPushButton *pushButton_6;
    QProgressBar *progressBar;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QLineEdit *lineEdit_10;
    QLabel *label_10;
    QLineEdit *lineEdit_11;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QLineEdit *lineEdit_8;
    QLabel *label_3;
    QLineEdit *lineEdit_9;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QSpinBox *spinBox;
    QLabel *label_7;
    QSpinBox *spinBox_3;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *checkBox;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_22;
    QLineEdit *lineEdit_15;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;
    QCustomPlot *customPlot;

    void setupUi(QDialog *BlazeCorr)
    {
        if (BlazeCorr->objectName().isEmpty())
            BlazeCorr->setObjectName(QString::fromUtf8("BlazeCorr"));
        BlazeCorr->resize(1434, 716);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BlazeCorr->sizePolicy().hasHeightForWidth());
        BlazeCorr->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(BlazeCorr);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        scrollArea = new QScrollArea(BlazeCorr);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -11, 1400, 707));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMaximumSize(QSize(330, 16777215));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(95, 0));
        label_5->setMaximumSize(QSize(95, 16777215));

        horizontalLayout_4->addWidget(label_5);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy2);
        lineEdit_2->setMinimumSize(QSize(200, 0));
        lineEdit_2->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_4->addWidget(lineEdit_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(95, 0));
        label_4->setMaximumSize(QSize(95, 16777215));

        horizontalLayout_5->addWidget(label_4);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);
        lineEdit->setMinimumSize(QSize(200, 0));
        lineEdit->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_5->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy1.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy1);
        label_16->setMinimumSize(QSize(95, 0));
        label_16->setMaximumSize(QSize(95, 16777215));

        horizontalLayout_18->addWidget(label_16);

        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        sizePolicy2.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy2);
        lineEdit_5->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_18->addWidget(lineEdit_5);


        verticalLayout_2->addLayout(horizontalLayout_18);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);
        label_13->setMaximumSize(QSize(95, 16777215));

        horizontalLayout_14->addWidget(label_13);

        spinBox_2 = new QSpinBox(groupBox);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        sizePolicy2.setHeightForWidth(spinBox_2->sizePolicy().hasHeightForWidth());
        spinBox_2->setSizePolicy(sizePolicy2);
        spinBox_2->setMaximum(99999);
        spinBox_2->setValue(300);

        horizontalLayout_14->addWidget(spinBox_2);

        checkBox_4 = new QCheckBox(groupBox);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        sizePolicy2.setHeightForWidth(checkBox_4->sizePolicy().hasHeightForWidth());
        checkBox_4->setSizePolicy(sizePolicy2);

        horizontalLayout_14->addWidget(checkBox_4);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy3);
        pushButton_3->setMinimumSize(QSize(75, 0));
        pushButton_3->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_14->addWidget(pushButton_3);


        verticalLayout_2->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);
        label_14->setMinimumSize(QSize(95, 0));
        label_14->setMaximumSize(QSize(95, 16777215));

        horizontalLayout_15->addWidget(label_14);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        sizePolicy2.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy2);
        lineEdit_3->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_15->addWidget(lineEdit_3);


        verticalLayout_2->addLayout(horizontalLayout_15);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        sizePolicy1.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy1);
        label_17->setMinimumSize(QSize(95, 0));
        label_17->setMaximumSize(QSize(95, 16777215));

        horizontalLayout_19->addWidget(label_17);

        lineEdit_6 = new QLineEdit(groupBox);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        sizePolicy2.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy2);
        lineEdit_6->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_19->addWidget(lineEdit_6);


        verticalLayout_2->addLayout(horizontalLayout_19);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy1.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy1);
        label_15->setMinimumSize(QSize(95, 0));
        label_15->setMaximumSize(QSize(95, 16777215));

        horizontalLayout_17->addWidget(label_15);

        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        sizePolicy2.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy2);
        lineEdit_4->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_17->addWidget(lineEdit_4);


        verticalLayout_2->addLayout(horizontalLayout_17);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy2.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy2);
        pushButton_5->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_16->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy2.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy2);

        horizontalLayout_16->addWidget(pushButton_4);

        checkBox_6 = new QCheckBox(groupBox);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setEnabled(false);
        sizePolicy2.setHeightForWidth(checkBox_6->sizePolicy().hasHeightForWidth());
        checkBox_6->setSizePolicy(sizePolicy2);

        horizontalLayout_16->addWidget(checkBox_6);


        verticalLayout_2->addLayout(horizontalLayout_16);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);

        horizontalLayout_10->addWidget(label_11);

        doubleSpinBox_3 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setEnabled(false);
        sizePolicy2.setHeightForWidth(doubleSpinBox_3->sizePolicy().hasHeightForWidth());
        doubleSpinBox_3->setSizePolicy(sizePolicy2);
        doubleSpinBox_3->setValue(1.000000000000000);

        horizontalLayout_10->addWidget(doubleSpinBox_3);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);

        horizontalLayout_10->addWidget(label_12);

        doubleSpinBox_4 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setEnabled(false);
        sizePolicy2.setHeightForWidth(doubleSpinBox_4->sizePolicy().hasHeightForWidth());
        doubleSpinBox_4->setSizePolicy(sizePolicy2);
        doubleSpinBox_4->setValue(1.000000000000000);

        horizontalLayout_10->addWidget(doubleSpinBox_4);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        sizePolicy1.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy1);

        horizontalLayout_13->addWidget(label_18);

        spinBox_4 = new QSpinBox(groupBox);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setEnabled(false);
        sizePolicy2.setHeightForWidth(spinBox_4->sizePolicy().hasHeightForWidth());
        spinBox_4->setSizePolicy(sizePolicy2);
        spinBox_4->setMaximum(999);

        horizontalLayout_13->addWidget(spinBox_4);


        verticalLayout_2->addLayout(horizontalLayout_13);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        sizePolicy2.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy2);

        horizontalLayout_12->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(groupBox);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        sizePolicy2.setHeightForWidth(checkBox_3->sizePolicy().hasHeightForWidth());
        checkBox_3->setSizePolicy(sizePolicy2);

        horizontalLayout_12->addWidget(checkBox_3);

        checkBox_5 = new QCheckBox(groupBox);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        sizePolicy2.setHeightForWidth(checkBox_5->sizePolicy().hasHeightForWidth());
        checkBox_5->setSizePolicy(sizePolicy2);

        horizontalLayout_12->addWidget(checkBox_5);

        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy2.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy2);

        horizontalLayout_12->addWidget(pushButton_6);


        verticalLayout_2->addLayout(horizontalLayout_12);

        progressBar = new QProgressBar(groupBox);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy4);
        progressBar->setMinimumSize(QSize(150, 0));
        progressBar->setMaximumSize(QSize(16777215, 16777215));
        progressBar->setValue(24);

        verticalLayout_2->addWidget(progressBar);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(90, 0));
        label->setMaximumSize(QSize(90, 16777215));

        horizontalLayout->addWidget(label);

        lineEdit_7 = new QLineEdit(groupBox_2);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        sizePolicy2.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy2);
        lineEdit_7->setMinimumSize(QSize(125, 0));
        lineEdit_7->setMaximumSize(QSize(125, 16777215));

        horizontalLayout->addWidget(lineEdit_7);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setMaximumSize(QSize(70, 16777215));

        horizontalLayout->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setMinimumSize(QSize(90, 0));
        label_9->setMaximumSize(QSize(90, 16777215));

        horizontalLayout_8->addWidget(label_9);

        lineEdit_10 = new QLineEdit(groupBox_2);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        sizePolicy2.setHeightForWidth(lineEdit_10->sizePolicy().hasHeightForWidth());
        lineEdit_10->setSizePolicy(sizePolicy2);
        lineEdit_10->setMinimumSize(QSize(125, 0));
        lineEdit_10->setMaximumSize(QSize(125, 16777215));

        horizontalLayout_8->addWidget(lineEdit_10);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(label_10);

        lineEdit_11 = new QLineEdit(groupBox_2);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));
        sizePolicy3.setHeightForWidth(lineEdit_11->sizePolicy().hasHeightForWidth());
        lineEdit_11->setSizePolicy(sizePolicy3);
        lineEdit_11->setMinimumSize(QSize(50, 0));
        lineEdit_11->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_8->addWidget(lineEdit_11);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(90, 0));
        label_2->setMaximumSize(QSize(90, 16777215));

        horizontalLayout_6->addWidget(label_2);

        lineEdit_8 = new QLineEdit(groupBox_2);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        sizePolicy2.setHeightForWidth(lineEdit_8->sizePolicy().hasHeightForWidth());
        lineEdit_8->setSizePolicy(sizePolicy2);
        lineEdit_8->setMinimumSize(QSize(125, 0));
        lineEdit_8->setMaximumSize(QSize(125, 16777215));

        horizontalLayout_6->addWidget(lineEdit_8);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(label_3);

        lineEdit_9 = new QLineEdit(groupBox_2);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        sizePolicy3.setHeightForWidth(lineEdit_9->sizePolicy().hasHeightForWidth());
        lineEdit_9->setSizePolicy(sizePolicy3);
        lineEdit_9->setMinimumSize(QSize(50, 0));
        lineEdit_9->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_6->addWidget(lineEdit_9);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_6);

        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        sizePolicy2.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy2);
        spinBox->setMaximum(999);

        horizontalLayout_2->addWidget(spinBox);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_7);

        spinBox_3 = new QSpinBox(groupBox_2);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        sizePolicy2.setHeightForWidth(spinBox_3->sizePolicy().hasHeightForWidth());
        spinBox_3->setSizePolicy(sizePolicy2);
        spinBox_3->setMaximum(999);

        horizontalLayout_2->addWidget(spinBox_3);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        sizePolicy2.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(checkBox);

        doubleSpinBox = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        sizePolicy2.setHeightForWidth(doubleSpinBox->sizePolicy().hasHeightForWidth());
        doubleSpinBox->setSizePolicy(sizePolicy2);
        doubleSpinBox->setMaximum(9999.989999999999782);

        horizontalLayout_7->addWidget(doubleSpinBox);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(label_8);

        doubleSpinBox_2 = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        sizePolicy2.setHeightForWidth(doubleSpinBox_2->sizePolicy().hasHeightForWidth());
        doubleSpinBox_2->setSizePolicy(sizePolicy2);
        doubleSpinBox_2->setMaximum(9999.989999999999782);

        horizontalLayout_7->addWidget(doubleSpinBox_2);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_22 = new QLabel(groupBox_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        sizePolicy1.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(label_22);

        lineEdit_15 = new QLineEdit(groupBox_2);
        lineEdit_15->setObjectName(QString::fromUtf8("lineEdit_15"));
        sizePolicy2.setHeightForWidth(lineEdit_15->sizePolicy().hasHeightForWidth());
        lineEdit_15->setSizePolicy(sizePolicy2);
        lineEdit_15->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_9->addWidget(lineEdit_15);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(pushButton_2);


        verticalLayout_3->addLayout(horizontalLayout_9);


        verticalLayout->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_20->addLayout(verticalLayout);

        customPlot = new QCustomPlot(scrollAreaWidgetContents);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy5);

        horizontalLayout_20->addWidget(customPlot);


        gridLayout->addLayout(horizontalLayout_20, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(BlazeCorr);

        QMetaObject::connectSlotsByName(BlazeCorr);
    } // setupUi

    void retranslateUi(QDialog *BlazeCorr)
    {
        BlazeCorr->setWindowTitle(QCoreApplication::translate("BlazeCorr", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("BlazeCorr", "Spline-Fit", nullptr));
        label_5->setText(QCoreApplication::translate("BlazeCorr", "Work Path:", nullptr));
        label_4->setText(QCoreApplication::translate("BlazeCorr", "<html><head/><body><p><span style=\" color:#204a87;\">Flat:</span></p></body></html>", nullptr));
        label_16->setText(QCoreApplication::translate("BlazeCorr", "Spectrum:", nullptr));
        label_13->setText(QCoreApplication::translate("BlazeCorr", "# Points:", nullptr));
        checkBox_4->setText(QCoreApplication::translate("BlazeCorr", "Auto", nullptr));
        pushButton_3->setText(QCoreApplication::translate("BlazeCorr", "Distribute", nullptr));
        label_14->setText(QCoreApplication::translate("BlazeCorr", "<html><head/><body><p><span style=\" color:#a40000;\">Spline Points:</span></p></body></html>", nullptr));
        label_17->setText(QCoreApplication::translate("BlazeCorr", "<html><head/><body><p><span style=\" color:#4e9a06;\">Splinefit:</span></p></body></html>", nullptr));
        label_15->setText(QCoreApplication::translate("BlazeCorr", "Out Div", nullptr));
        pushButton_5->setText(QCoreApplication::translate("BlazeCorr", "Plot", nullptr));
        pushButton_4->setText(QCoreApplication::translate("BlazeCorr", "Fit", nullptr));
        checkBox_6->setText(QCoreApplication::translate("BlazeCorr", "Sigma Clipping", nullptr));
        label_11->setText(QCoreApplication::translate("BlazeCorr", "Sigma above:", nullptr));
        label_12->setText(QCoreApplication::translate("BlazeCorr", "below:", nullptr));
        label_18->setText(QCoreApplication::translate("BlazeCorr", "Spacing:", nullptr));
        checkBox_2->setText(QCoreApplication::translate("BlazeCorr", "Divide", nullptr));
        checkBox_3->setText(QCoreApplication::translate("BlazeCorr", "Subtract", nullptr));
        checkBox_5->setText(QCoreApplication::translate("BlazeCorr", "Add", nullptr));
        pushButton_6->setText(QCoreApplication::translate("BlazeCorr", "Do", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("BlazeCorr", "Differences and Sequence", nullptr));
        label->setText(QCoreApplication::translate("BlazeCorr", "Differences:", nullptr));
        pushButton->setText(QCoreApplication::translate("BlazeCorr", "Separate", nullptr));
        label_9->setText(QCoreApplication::translate("BlazeCorr", "O/I Diff:", nullptr));
        label_10->setText(QCoreApplication::translate("BlazeCorr", "*.", nullptr));
        label_2->setText(QCoreApplication::translate("BlazeCorr", "Spectra:", nullptr));
        label_3->setText(QCoreApplication::translate("BlazeCorr", "*.", nullptr));
        label_6->setText(QCoreApplication::translate("BlazeCorr", "from", nullptr));
        label_7->setText(QCoreApplication::translate("BlazeCorr", "to", nullptr));
        checkBox->setText(QCoreApplication::translate("BlazeCorr", "Region from", nullptr));
        label_8->setText(QCoreApplication::translate("BlazeCorr", "to", nullptr));
        label_22->setText(QCoreApplication::translate("BlazeCorr", "Ext. Corr. Spectra:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("BlazeCorr", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BlazeCorr: public Ui_BlazeCorr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLAZECORR_H
