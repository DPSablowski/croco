/********************************************************************************
** Form generated from reading UI file 'template.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPLATE_H
#define UI_TEMPLATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Template
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_16;
    QVBoxLayout *verticalLayout_4;
    QCustomPlot *qCustomPlot;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_7;
    QLineEdit *lineEdit_2;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_10;
    QCheckBox *checkBox;
    QCheckBox *checkBox_4;
    QDoubleSpinBox *doubleSpinBox_14;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_8;
    QLineEdit *lineEdit_3;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_11;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_5;
    QDoubleSpinBox *doubleSpinBox_15;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QLabel *label_12;
    QLineEdit *lineEdit_8;
    QLabel *label_22;
    QDoubleSpinBox *doubleSpinBox_13;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_6;
    QDoubleSpinBox *doubleSpinBox_16;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_13;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_14;
    QLineEdit *lineEdit_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_17;
    QDoubleSpinBox *doubleSpinBox_8;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_18;
    QDoubleSpinBox *doubleSpinBox_9;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_15;
    QDoubleSpinBox *doubleSpinBox_5;
    QLabel *label_21;
    QDoubleSpinBox *doubleSpinBox_6;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_16;
    QDoubleSpinBox *doubleSpinBox_7;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_12;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_19;
    QLineEdit *lineEdit_6;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_20;
    QLineEdit *lineEdit_7;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_4;
    QHBoxLayout *horizontalLayout_17;
    QCheckBox *checkBox_7;
    QDoubleSpinBox *doubleSpinBox_17;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Template)
    {
        if (Template->objectName().isEmpty())
            Template->setObjectName(QString::fromUtf8("Template"));
        Template->resize(1074, 499);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(177, 151, 176, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 228, 254, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(216, 189, 215, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(88, 75, 88, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(118, 101, 117, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(216, 203, 215, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        Template->setPalette(palette);
        QFont font;
        font.setPointSize(9);
        Template->setFont(font);
        gridLayout = new QGridLayout(Template);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(Template);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1054, 479));
        horizontalLayout_16 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        qCustomPlot = new QCustomPlot(scrollAreaWidgetContents);
        qCustomPlot->setObjectName(QString::fromUtf8("qCustomPlot"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(qCustomPlot->sizePolicy().hasHeightForWidth());
        qCustomPlot->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(qCustomPlot);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        doubleSpinBox = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setDecimals(4);
        doubleSpinBox->setMaximum(9999.989999999999782);

        horizontalLayout->addWidget(doubleSpinBox);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        doubleSpinBox_2 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setDecimals(4);
        doubleSpinBox_2->setMaximum(9999.989999999999782);

        horizontalLayout->addWidget(doubleSpinBox_2);

        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        doubleSpinBox_3 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setDecimals(4);
        doubleSpinBox_3->setMinimum(-99.000000000000000);
        doubleSpinBox_3->setMaximum(9999.989999999999782);

        horizontalLayout->addWidget(doubleSpinBox_3);

        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout->addWidget(label_6);

        doubleSpinBox_4 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setDecimals(4);
        doubleSpinBox_4->setMinimum(-99.000000000000000);
        doubleSpinBox_4->setMaximum(9999.989999999999782);

        horizontalLayout->addWidget(doubleSpinBox_4);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(scrollAreaWidgetContents);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(lineEdit);

        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_2->addWidget(label_7);

        lineEdit_2 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(lineEdit_2);

        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_2->addWidget(label_9);

        doubleSpinBox_10 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_10->setObjectName(QString::fromUtf8("doubleSpinBox_10"));
        doubleSpinBox_10->setDecimals(4);
        doubleSpinBox_10->setMinimum(-999.000000000000000);
        doubleSpinBox_10->setMaximum(999.990000000000009);

        horizontalLayout_2->addWidget(doubleSpinBox_10);

        checkBox = new QCheckBox(scrollAreaWidgetContents);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout_2->addWidget(checkBox);

        checkBox_4 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        horizontalLayout_2->addWidget(checkBox_4);

        doubleSpinBox_14 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_14->setObjectName(QString::fromUtf8("doubleSpinBox_14"));
        doubleSpinBox_14->setDecimals(4);
        doubleSpinBox_14->setMinimum(-999.000000000000000);
        doubleSpinBox_14->setMaximum(999.000000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox_14);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_3->addWidget(label_8);

        lineEdit_3 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        sizePolicy1.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(lineEdit_3);

        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_3->addWidget(label_10);

        doubleSpinBox_11 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_11->setObjectName(QString::fromUtf8("doubleSpinBox_11"));
        doubleSpinBox_11->setDecimals(4);
        doubleSpinBox_11->setMinimum(-999.000000000000000);
        doubleSpinBox_11->setMaximum(999.990000000000009);

        horizontalLayout_3->addWidget(doubleSpinBox_11);

        checkBox_2 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        horizontalLayout_3->addWidget(checkBox_2);

        checkBox_5 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));

        horizontalLayout_3->addWidget(checkBox_5);

        doubleSpinBox_15 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_15->setObjectName(QString::fromUtf8("doubleSpinBox_15"));
        doubleSpinBox_15->setDecimals(4);
        doubleSpinBox_15->setMinimum(-999.000000000000000);
        doubleSpinBox_15->setMaximum(999.000000000000000);

        horizontalLayout_3->addWidget(doubleSpinBox_15);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_4->addWidget(label_12);

        lineEdit_8 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        sizePolicy1.setHeightForWidth(lineEdit_8->sizePolicy().hasHeightForWidth());
        lineEdit_8->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(lineEdit_8);

        label_22 = new QLabel(scrollAreaWidgetContents);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_4->addWidget(label_22);

        doubleSpinBox_13 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_13->setObjectName(QString::fromUtf8("doubleSpinBox_13"));

        horizontalLayout_4->addWidget(doubleSpinBox_13);

        checkBox_3 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        horizontalLayout_4->addWidget(checkBox_3);

        checkBox_6 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));

        horizontalLayout_4->addWidget(checkBox_6);

        doubleSpinBox_16 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_16->setObjectName(QString::fromUtf8("doubleSpinBox_16"));
        doubleSpinBox_16->setDecimals(4);
        doubleSpinBox_16->setMinimum(-999.000000000000000);
        doubleSpinBox_16->setMaximum(999.000000000000000);

        horizontalLayout_4->addWidget(doubleSpinBox_16);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout_4->addLayout(verticalLayout_2);


        horizontalLayout_16->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(label_13);

        lineEdit_4 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        sizePolicy1.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(lineEdit_4);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_14 = new QLabel(scrollAreaWidgetContents);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy2.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(label_14);

        lineEdit_5 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        sizePolicy1.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(lineEdit_5);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_17 = new QLabel(scrollAreaWidgetContents);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        sizePolicy2.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy2);

        horizontalLayout_8->addWidget(label_17);

        doubleSpinBox_8 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_8->setObjectName(QString::fromUtf8("doubleSpinBox_8"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_8->sizePolicy().hasHeightForWidth());
        doubleSpinBox_8->setSizePolicy(sizePolicy1);
        doubleSpinBox_8->setDecimals(3);
        doubleSpinBox_8->setMaximum(999.990000000000009);

        horizontalLayout_8->addWidget(doubleSpinBox_8);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_18 = new QLabel(scrollAreaWidgetContents);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        sizePolicy2.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(label_18);

        doubleSpinBox_9 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_9->setObjectName(QString::fromUtf8("doubleSpinBox_9"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_9->sizePolicy().hasHeightForWidth());
        doubleSpinBox_9->setSizePolicy(sizePolicy1);
        doubleSpinBox_9->setDecimals(3);
        doubleSpinBox_9->setMaximum(999.990000000000009);

        horizontalLayout_9->addWidget(doubleSpinBox_9);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_15 = new QLabel(scrollAreaWidgetContents);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy2.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy2);

        horizontalLayout_10->addWidget(label_15);

        doubleSpinBox_5 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_5->sizePolicy().hasHeightForWidth());
        doubleSpinBox_5->setSizePolicy(sizePolicy1);
        doubleSpinBox_5->setDecimals(3);
        doubleSpinBox_5->setMaximum(9999.989999999999782);

        horizontalLayout_10->addWidget(doubleSpinBox_5);

        label_21 = new QLabel(scrollAreaWidgetContents);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        sizePolicy2.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy2);

        horizontalLayout_10->addWidget(label_21);

        doubleSpinBox_6 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_6->setObjectName(QString::fromUtf8("doubleSpinBox_6"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_6->sizePolicy().hasHeightForWidth());
        doubleSpinBox_6->setSizePolicy(sizePolicy1);
        doubleSpinBox_6->setDecimals(3);
        doubleSpinBox_6->setMaximum(9999.989999999999782);

        horizontalLayout_10->addWidget(doubleSpinBox_6);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_16 = new QLabel(scrollAreaWidgetContents);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy2.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy2);

        horizontalLayout_11->addWidget(label_16);

        doubleSpinBox_7 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_7->setObjectName(QString::fromUtf8("doubleSpinBox_7"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_7->sizePolicy().hasHeightForWidth());
        doubleSpinBox_7->setSizePolicy(sizePolicy1);
        doubleSpinBox_7->setDecimals(3);

        horizontalLayout_11->addWidget(doubleSpinBox_7);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy2.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy2);

        horizontalLayout_15->addWidget(label_11);

        doubleSpinBox_12 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_12->setObjectName(QString::fromUtf8("doubleSpinBox_12"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_12->sizePolicy().hasHeightForWidth());
        doubleSpinBox_12->setSizePolicy(sizePolicy1);
        doubleSpinBox_12->setDecimals(3);
        doubleSpinBox_12->setSingleStep(0.010000000000000);

        horizontalLayout_15->addWidget(doubleSpinBox_12);


        verticalLayout_3->addLayout(horizontalLayout_15);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_19 = new QLabel(scrollAreaWidgetContents);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        sizePolicy2.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy2);

        horizontalLayout_12->addWidget(label_19);

        lineEdit_6 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        sizePolicy1.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy1);

        horizontalLayout_12->addWidget(lineEdit_6);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_20 = new QLabel(scrollAreaWidgetContents);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        sizePolicy2.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy2);

        horizontalLayout_13->addWidget(label_20);

        lineEdit_7 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        sizePolicy1.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy1);

        horizontalLayout_13->addWidget(lineEdit_7);


        verticalLayout_3->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalSpacer_5 = new QSpacerItem(88, 17, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_5);

        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);

        horizontalLayout_14->addWidget(pushButton_4);


        verticalLayout_3->addLayout(horizontalLayout_14);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        checkBox_7 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        sizePolicy1.setHeightForWidth(checkBox_7->sizePolicy().hasHeightForWidth());
        checkBox_7->setSizePolicy(sizePolicy1);

        horizontalLayout_17->addWidget(checkBox_7);

        doubleSpinBox_17 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_17->setObjectName(QString::fromUtf8("doubleSpinBox_17"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_17->sizePolicy().hasHeightForWidth());
        doubleSpinBox_17->setSizePolicy(sizePolicy1);
        doubleSpinBox_17->setDecimals(3);

        horizontalLayout_17->addWidget(doubleSpinBox_17);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_17);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_16->addLayout(verticalLayout_3);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(Template);
        QObject::connect(pushButton, SIGNAL(clicked()), Template, SLOT(close()));

        QMetaObject::connectSlotsByName(Template);
    } // setupUi

    void retranslateUi(QDialog *Template)
    {
        Template->setWindowTitle(QApplication::translate("Template", "Dialog", nullptr));
        label_3->setText(QApplication::translate("Template", "x1:", nullptr));
        label_4->setText(QApplication::translate("Template", "x2:", nullptr));
        label_5->setText(QApplication::translate("Template", "y1:", nullptr));
        label_6->setText(QApplication::translate("Template", "y2:", nullptr));
        pushButton_2->setText(QApplication::translate("Template", "find values", nullptr));
        pushButton_3->setText(QApplication::translate("Template", "Plot", nullptr));
        label_2->setText(QApplication::translate("Template", "work path", nullptr));
        label_7->setText(QApplication::translate("Template", "<html><head/><body><p><span style=\" font-weight:600; color:#0f22e5;\">File 1:</span></p></body></html>", nullptr));
        label_9->setText(QApplication::translate("Template", "RV:", nullptr));
        checkBox->setText(QApplication::translate("Template", "log(x)", nullptr));
        checkBox_4->setText(QApplication::translate("Template", "y +", nullptr));
        label_8->setText(QApplication::translate("Template", "<html><head/><body><p><span style=\" font-weight:600; color:#ea1010;\">File 2:</span></p></body></html>", nullptr));
        label_10->setText(QApplication::translate("Template", "RV:", nullptr));
        checkBox_2->setText(QApplication::translate("Template", "log(x)", nullptr));
        checkBox_5->setText(QApplication::translate("Template", "y +", nullptr));
        pushButton->setText(QApplication::translate("Template", "Close", nullptr));
        label_12->setText(QApplication::translate("Template", "<html><head/><body><p><span style=\" font-weight:600;\">File 3:</span></p></body></html>", nullptr));
        label_22->setText(QApplication::translate("Template", "Offset", nullptr));
        checkBox_3->setText(QApplication::translate("Template", "log(x)", nullptr));
        checkBox_6->setText(QApplication::translate("Template", "y +", nullptr));
        label_13->setText(QApplication::translate("Template", "Line list comp A:", nullptr));
        label_14->setText(QApplication::translate("Template", "Line list comp B:", nullptr));
        label_17->setText(QApplication::translate("Template", "V*sin(i) [km/s] comp A:", nullptr));
        label_18->setText(QApplication::translate("Template", "V*sin(i)[km/s] comp B:", nullptr));
        label_15->setText(QApplication::translate("Template", "Wavelength range [A]:", nullptr));
        label_21->setText(QApplication::translate("Template", "to", nullptr));
        label_16->setText(QApplication::translate("Template", "Sampling [A/pix]:", nullptr));
        label_11->setText(QApplication::translate("Template", "Gaussian noise:", nullptr));
        label_19->setText(QApplication::translate("Template", "Template A:", nullptr));
        label_20->setText(QApplication::translate("Template", "Template B:", nullptr));
        pushButton_4->setText(QApplication::translate("Template", "Do It", nullptr));
        checkBox_7->setText(QApplication::translate("Template", "Sum *", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Template: public Ui_Template {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPLATE_H
