/********************************************************************************
** Form generated from reading UI file 'rvcurve.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RVCURVE_H
#define UI_RVCURVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_RvCurve
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QSpinBox *spinBox;
    QLabel *label_3;
    QSpinBox *spinBox_2;
    QCheckBox *checkBox_7;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLineEdit *lineEdit_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QVBoxLayout *verticalLayout_2;
    QCustomPlot *customPlot;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_13;
    QDoubleSpinBox *doubleSpinBox_5;
    QLabel *label_14;
    QDoubleSpinBox *doubleSpinBox_6;
    QLabel *label_15;
    QDoubleSpinBox *doubleSpinBox_7;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_6;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QLineEdit *lineEdit_4;
    QLabel *label_12;
    QSpinBox *spinBox_3;

    void setupUi(QDialog *RvCurve)
    {
        if (RvCurve->objectName().isEmpty())
            RvCurve->setObjectName(QStringLiteral("RvCurve"));
        RvCurve->resize(1179, 422);
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
        RvCurve->setPalette(palette);
        QFont font;
        font.setPointSize(9);
        RvCurve->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral("../../../../../../../home/daniels/work1/Disentangling/Template_Method/Log/Qt_LogCC/Data/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        RvCurve->setWindowIcon(icon);
        gridLayout = new QGridLayout(RvCurve);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scrollArea = new QScrollArea(RvCurve);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1159, 402));
        horizontalLayout_6 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QStringLiteral("label_6"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(label_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(label_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        plainTextEdit = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(plainTextEdit);

        plainTextEdit_2 = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(plainTextEdit_2->sizePolicy().hasHeightForWidth());
        plainTextEdit_2->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(plainTextEdit_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(scrollAreaWidgetContents);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy4);

        horizontalLayout->addWidget(lineEdit);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy5);

        horizontalLayout->addWidget(label_2);

        spinBox = new QSpinBox(scrollAreaWidgetContents);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy6);

        horizontalLayout->addWidget(spinBox);

        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy5.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy5);

        horizontalLayout->addWidget(label_3);

        spinBox_2 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        sizePolicy6.setHeightForWidth(spinBox_2->sizePolicy().hasHeightForWidth());
        spinBox_2->setSizePolicy(sizePolicy6);
        spinBox_2->setMaximum(999);

        horizontalLayout->addWidget(spinBox_2);

        checkBox_7 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_7->setObjectName(QStringLiteral("checkBox_7"));

        horizontalLayout->addWidget(checkBox_7);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy6.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy6);

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy5.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy5);

        horizontalLayout_5->addWidget(label_7);

        lineEdit_3 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        sizePolicy6.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy6);

        horizontalLayout_5->addWidget(lineEdit_3);

        radioButton = new QRadioButton(scrollAreaWidgetContents);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout_5->addWidget(radioButton);

        radioButton_2 = new QRadioButton(scrollAreaWidgetContents);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        sizePolicy6.setHeightForWidth(radioButton_2->sizePolicy().hasHeightForWidth());
        radioButton_2->setSizePolicy(sizePolicy6);

        horizontalLayout_5->addWidget(radioButton_2);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy6.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy6);

        horizontalLayout_5->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy6.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy6);

        horizontalLayout_2->addWidget(pushButton);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_4);

        lineEdit_2 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy6.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy6);

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_8->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_8);


        horizontalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        customPlot = new QCustomPlot(scrollAreaWidgetContents);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy7);

        verticalLayout_2->addWidget(customPlot);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);

        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_7->addWidget(label_8);

        doubleSpinBox = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));

        horizontalLayout_7->addWidget(doubleSpinBox);

        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_7->addWidget(label_9);

        doubleSpinBox_2 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));

        horizontalLayout_7->addWidget(doubleSpinBox_2);

        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_7->addWidget(label_10);

        doubleSpinBox_3 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setMinimum(-999);
        doubleSpinBox_3->setMaximum(999);

        horizontalLayout_7->addWidget(doubleSpinBox_3);

        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_7->addWidget(label_11);

        doubleSpinBox_4 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setMinimum(-999);
        doubleSpinBox_4->setMaximum(999);

        horizontalLayout_7->addWidget(doubleSpinBox_4);

        pushButton_5 = new QPushButton(scrollAreaWidgetContents);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout_7->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_7->addWidget(pushButton_4);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName(QStringLiteral("label_13"));
        sizePolicy5.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy5);

        horizontalLayout_9->addWidget(label_13);

        doubleSpinBox_5 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        doubleSpinBox_5->setDecimals(3);
        doubleSpinBox_5->setMinimum(-999);
        doubleSpinBox_5->setMaximum(999);
        doubleSpinBox_5->setValue(30);

        horizontalLayout_9->addWidget(doubleSpinBox_5);

        label_14 = new QLabel(scrollAreaWidgetContents);
        label_14->setObjectName(QStringLiteral("label_14"));
        sizePolicy5.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy5);

        horizontalLayout_9->addWidget(label_14);

        doubleSpinBox_6 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        doubleSpinBox_6->setDecimals(3);
        doubleSpinBox_6->setMinimum(-999);
        doubleSpinBox_6->setMaximum(999);
        doubleSpinBox_6->setValue(27);

        horizontalLayout_9->addWidget(doubleSpinBox_6);

        label_15 = new QLabel(scrollAreaWidgetContents);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_9->addWidget(label_15);

        doubleSpinBox_7 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));
        doubleSpinBox_7->setDecimals(3);
        doubleSpinBox_7->setMinimum(-999);
        doubleSpinBox_7->setMaximum(999);
        doubleSpinBox_7->setValue(1);

        horizontalLayout_9->addWidget(doubleSpinBox_7);

        checkBox_3 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        horizontalLayout_9->addWidget(checkBox_3);

        checkBox = new QCheckBox(scrollAreaWidgetContents);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_9->addWidget(checkBox);

        checkBox_2 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        horizontalLayout_9->addWidget(checkBox_2);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_6);

        pushButton_6 = new QPushButton(scrollAreaWidgetContents);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy4.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy4);

        horizontalLayout_10->addWidget(pushButton_6);

        checkBox_4 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        horizontalLayout_10->addWidget(checkBox_4);

        checkBox_5 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        sizePolicy6.setHeightForWidth(checkBox_5->sizePolicy().hasHeightForWidth());
        checkBox_5->setSizePolicy(sizePolicy6);

        horizontalLayout_10->addWidget(checkBox_5);

        checkBox_6 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));

        horizontalLayout_10->addWidget(checkBox_6);

        lineEdit_4 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        sizePolicy6.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy6);

        horizontalLayout_10->addWidget(lineEdit_4);

        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_10->addWidget(label_12);

        spinBox_3 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        sizePolicy6.setHeightForWidth(spinBox_3->sizePolicy().hasHeightForWidth());
        spinBox_3->setSizePolicy(sizePolicy6);
        spinBox_3->setValue(9);

        horizontalLayout_10->addWidget(spinBox_3);


        verticalLayout_2->addLayout(horizontalLayout_10);


        horizontalLayout_6->addLayout(verticalLayout_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(RvCurve);
        QObject::connect(pushButton, SIGNAL(clicked()), RvCurve, SLOT(close()));

        QMetaObject::connectSlotsByName(RvCurve);
    } // setupUi

    void retranslateUi(QDialog *RvCurve)
    {
        RvCurve->setWindowTitle(QApplication::translate("RvCurve", "Dialog", 0));
        label_6->setText(QApplication::translate("RvCurve", "<html><head/><body><p>File  <span style=\" font-weight:600; color:#0b54f9;\">RV1    </span><span style=\" font-weight:600; color:#f90e0e;\">RV2    </span><span style=\" font-weight:600; color:#39f90e;\">RV1+RV2</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("RvCurve", "file time", 0));
        label->setText(QApplication::translate("RvCurve", "RV files", 0));
        label_2->setText(QApplication::translate("RvCurve", ".txt from", 0));
        label_3->setText(QApplication::translate("RvCurve", "to", 0));
        checkBox_7->setText(QApplication::translate("RvCurve", "flip", 0));
        pushButton_2->setText(QApplication::translate("RvCurve", "get values", 0));
        label_7->setText(QApplication::translate("RvCurve", "Time data", 0));
        radioButton->setText(QApplication::translate("RvCurve", "phase", 0));
        radioButton_2->setText(QApplication::translate("RvCurve", "time", 0));
        pushButton_3->setText(QApplication::translate("RvCurve", "get values", 0));
        pushButton->setText(QApplication::translate("RvCurve", "Close", 0));
        label_4->setText(QApplication::translate("RvCurve", "Work path", 0));
        label_8->setText(QApplication::translate("RvCurve", "x1:", 0));
        label_9->setText(QApplication::translate("RvCurve", "x2:", 0));
        label_10->setText(QApplication::translate("RvCurve", "y1:", 0));
        label_11->setText(QApplication::translate("RvCurve", "y2:", 0));
        pushButton_5->setText(QApplication::translate("RvCurve", "find values", 0));
        pushButton_4->setText(QApplication::translate("RvCurve", "Plot", 0));
        label_13->setText(QApplication::translate("RvCurve", "<html><head/><body><p>f(x)=a+b*sin(6.28c*t),   a:</p></body></html>", 0));
        label_14->setText(QApplication::translate("RvCurve", "b:", 0));
        label_15->setText(QApplication::translate("RvCurve", "c:", 0));
        checkBox_3->setText(QApplication::translate("RvCurve", "plot", 0));
        checkBox->setText(QApplication::translate("RvCurve", "- RV1", 0));
        checkBox_2->setText(QApplication::translate("RvCurve", "- RV2", 0));
        pushButton_6->setText(QApplication::translate("RvCurve", "Save", 0));
        checkBox_4->setText(QApplication::translate("RvCurve", "pdf", 0));
        checkBox_5->setText(QApplication::translate("RvCurve", "png", 0));
        checkBox_6->setText(QApplication::translate("RvCurve", "jpg", 0));
        label_12->setText(QApplication::translate("RvCurve", "Font Size:", 0));
    } // retranslateUi

};

namespace Ui {
    class RvCurve: public Ui_RvCurve {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RVCURVE_H
