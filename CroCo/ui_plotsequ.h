/********************************************************************************
** Form generated from reading UI file 'plotsequ.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTSEQU_H
#define UI_PLOTSEQU_H

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
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_PlotSequ
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QCustomPlot *customPlot;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_4;
    QCheckBox *checkBox_13;
    QDoubleSpinBox *doubleSpinBox_12;
    QLabel *label_8;
    QLineEdit *lineEdit_2;
    QLabel *label_9;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLabel *label_6;
    QSpinBox *spinBox;
    QLabel *label_7;
    QSpinBox *spinBox_2;
    QLabel *label_17;
    QLineEdit *lineEdit_9;
    QLabel *label_13;
    QDoubleSpinBox *doubleSpinBox_5;
    QComboBox *comboBox;
    QLabel *label_14;
    QLineEdit *lineEdit_6;
    QLabel *label_15;
    QLineEdit *lineEdit_7;
    QLabel *label_16;
    QLineEdit *lineEdit_8;
    QCheckBox *checkBox_15;
    QCheckBox *checkBox_16;
    QLabel *label_26;
    QComboBox *comboBox_2;
    QSpinBox *spinBox_4;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_4;
    QLineEdit *lineEdit_11;
    QLabel *label_20;
    QDoubleSpinBox *doubleSpinBox_6;
    QCheckBox *checkBox_17;
    QCheckBox *checkBox_19;
    QCheckBox *checkBox_6;
    QDoubleSpinBox *doubleSpinBox_8;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *checkBox_11;
    QCheckBox *checkBox_5;
    QLineEdit *lineEdit_12;
    QLabel *label_21;
    QDoubleSpinBox *doubleSpinBox_7;
    QCheckBox *checkBox_18;
    QCheckBox *checkBox_20;
    QCheckBox *checkBox_7;
    QDoubleSpinBox *doubleSpinBox_9;
    QLabel *label_19;
    QFrame *line;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QCheckBox *checkBox_14;
    QLineEdit *lineEdit_16;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_10;
    QCheckBox *checkBox_12;
    QLineEdit *lineEdit_15;
    QLabel *label_23;
    QLineEdit *lineEdit_14;
    QLabel *label_24;
    QDoubleSpinBox *doubleSpinBox_13;
    QLabel *label_25;
    QDoubleSpinBox *doubleSpinBox_14;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox_8;
    QLineEdit *lineEdit_13;
    QLabel *label_22;
    QDoubleSpinBox *doubleSpinBox_10;
    QCheckBox *checkBox_9;
    QDoubleSpinBox *doubleSpinBox_11;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_11;
    QLineEdit *lineEdit_5;
    QLabel *label_10;
    QCheckBox *checkBox;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_2;
    QLineEdit *lineEdit_4;
    QLabel *label_12;
    QSpinBox *spinBox_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton;

    void setupUi(QDialog *PlotSequ)
    {
        if (PlotSequ->objectName().isEmpty())
            PlotSequ->setObjectName(QStringLiteral("PlotSequ"));
        PlotSequ->resize(1778, 681);
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
        PlotSequ->setPalette(palette);
        QFont font;
        font.setPointSize(9);
        PlotSequ->setFont(font);
        gridLayout = new QGridLayout(PlotSequ);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scrollArea = new QScrollArea(PlotSequ);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1750, 653));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        customPlot = new QCustomPlot(scrollAreaWidgetContents);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(customPlot);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        doubleSpinBox = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setDecimals(4);
        doubleSpinBox->setMinimum(-9999);
        doubleSpinBox->setMaximum(9999);

        horizontalLayout->addWidget(doubleSpinBox);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        doubleSpinBox_2 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setDecimals(4);
        doubleSpinBox_2->setMinimum(-9999);
        doubleSpinBox_2->setMaximum(9999);
        doubleSpinBox_2->setValue(0);

        horizontalLayout->addWidget(doubleSpinBox_2);

        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        doubleSpinBox_3 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setDecimals(11);
        doubleSpinBox_3->setMinimum(-999);
        doubleSpinBox_3->setMaximum(9999.99);

        horizontalLayout->addWidget(doubleSpinBox_3);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        doubleSpinBox_4 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setDecimals(11);
        doubleSpinBox_4->setMinimum(-999);
        doubleSpinBox_4->setMaximum(9999);

        horizontalLayout->addWidget(doubleSpinBox_4);

        checkBox_13 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_13->setObjectName(QStringLiteral("checkBox_13"));

        horizontalLayout->addWidget(checkBox_13);

        doubleSpinBox_12 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_12->setObjectName(QStringLiteral("doubleSpinBox_12"));
        doubleSpinBox_12->setDecimals(3);
        doubleSpinBox_12->setMaximum(9999.99);

        horizontalLayout->addWidget(doubleSpinBox_12);

        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout->addWidget(label_8);

        lineEdit_2 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(lineEdit_2);

        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout->addWidget(label_9);

        lineEdit_3 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        sizePolicy1.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(lineEdit_3);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        lineEdit = new QLineEdit(scrollAreaWidgetContents);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(lineEdit);

        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_2->addWidget(label_6);

        spinBox = new QSpinBox(scrollAreaWidgetContents);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(9999);
        spinBox->setValue(0);

        horizontalLayout_2->addWidget(spinBox);

        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_2->addWidget(label_7);

        spinBox_2 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximum(9999);
        spinBox_2->setValue(1);

        horizontalLayout_2->addWidget(spinBox_2);

        label_17 = new QLabel(scrollAreaWidgetContents);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_2->addWidget(label_17);

        lineEdit_9 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        sizePolicy1.setHeightForWidth(lineEdit_9->sizePolicy().hasHeightForWidth());
        lineEdit_9->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(lineEdit_9);

        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_2->addWidget(label_13);

        doubleSpinBox_5 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        doubleSpinBox_5->setDecimals(13);
        doubleSpinBox_5->setMinimum(-99);
        doubleSpinBox_5->setMaximum(100000);
        doubleSpinBox_5->setSingleStep(0.1);

        horizontalLayout_2->addWidget(doubleSpinBox_5);

        comboBox = new QComboBox(scrollAreaWidgetContents);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        label_14 = new QLabel(scrollAreaWidgetContents);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_2->addWidget(label_14);

        lineEdit_6 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        sizePolicy1.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy1);
        lineEdit_6->setCursor(QCursor(Qt::IBeamCursor));

        horizontalLayout_2->addWidget(lineEdit_6);

        label_15 = new QLabel(scrollAreaWidgetContents);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_2->addWidget(label_15);

        lineEdit_7 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        sizePolicy1.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(lineEdit_7);

        label_16 = new QLabel(scrollAreaWidgetContents);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_2->addWidget(label_16);

        lineEdit_8 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        sizePolicy1.setHeightForWidth(lineEdit_8->sizePolicy().hasHeightForWidth());
        lineEdit_8->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(lineEdit_8);

        checkBox_15 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_15->setObjectName(QStringLiteral("checkBox_15"));

        horizontalLayout_2->addWidget(checkBox_15);

        checkBox_16 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_16->setObjectName(QStringLiteral("checkBox_16"));

        horizontalLayout_2->addWidget(checkBox_16);

        label_26 = new QLabel(scrollAreaWidgetContents);
        label_26->setObjectName(QStringLiteral("label_26"));

        horizontalLayout_2->addWidget(label_26);

        comboBox_2 = new QComboBox(scrollAreaWidgetContents);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        sizePolicy1.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(comboBox_2);

        spinBox_4 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setMinimum(1);

        horizontalLayout_2->addWidget(spinBox_4);


        verticalLayout_3->addLayout(horizontalLayout_2);

        line_2 = new QFrame(scrollAreaWidgetContents);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        checkBox_10 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_10->setObjectName(QStringLiteral("checkBox_10"));

        horizontalLayout_5->addWidget(checkBox_10);

        checkBox_4 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        horizontalLayout_5->addWidget(checkBox_4);

        lineEdit_11 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        sizePolicy1.setHeightForWidth(lineEdit_11->sizePolicy().hasHeightForWidth());
        lineEdit_11->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(lineEdit_11);

        label_20 = new QLabel(scrollAreaWidgetContents);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_5->addWidget(label_20);

        doubleSpinBox_6 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        doubleSpinBox_6->setDecimals(3);
        doubleSpinBox_6->setMinimum(-99.99);
        doubleSpinBox_6->setSingleStep(0.1);

        horizontalLayout_5->addWidget(doubleSpinBox_6);

        checkBox_17 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_17->setObjectName(QStringLiteral("checkBox_17"));

        horizontalLayout_5->addWidget(checkBox_17);

        checkBox_19 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_19->setObjectName(QStringLiteral("checkBox_19"));

        horizontalLayout_5->addWidget(checkBox_19);

        checkBox_6 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));

        horizontalLayout_5->addWidget(checkBox_6);

        doubleSpinBox_8 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_8->setObjectName(QStringLiteral("doubleSpinBox_8"));
        doubleSpinBox_8->setDecimals(4);
        doubleSpinBox_8->setMinimum(-9999.99);
        doubleSpinBox_8->setMaximum(9999.99);

        horizontalLayout_5->addWidget(doubleSpinBox_8);

        label_18 = new QLabel(scrollAreaWidgetContents);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_5->addWidget(label_18);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        checkBox_11 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_11->setObjectName(QStringLiteral("checkBox_11"));

        horizontalLayout_6->addWidget(checkBox_11);

        checkBox_5 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));

        horizontalLayout_6->addWidget(checkBox_5);

        lineEdit_12 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        sizePolicy1.setHeightForWidth(lineEdit_12->sizePolicy().hasHeightForWidth());
        lineEdit_12->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(lineEdit_12);

        label_21 = new QLabel(scrollAreaWidgetContents);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_6->addWidget(label_21);

        doubleSpinBox_7 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));
        doubleSpinBox_7->setDecimals(3);
        doubleSpinBox_7->setMinimum(-99.99);
        doubleSpinBox_7->setSingleStep(0.1);

        horizontalLayout_6->addWidget(doubleSpinBox_7);

        checkBox_18 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_18->setObjectName(QStringLiteral("checkBox_18"));

        horizontalLayout_6->addWidget(checkBox_18);

        checkBox_20 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_20->setObjectName(QStringLiteral("checkBox_20"));

        horizontalLayout_6->addWidget(checkBox_20);

        checkBox_7 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_7->setObjectName(QStringLiteral("checkBox_7"));

        horizontalLayout_6->addWidget(checkBox_7);

        doubleSpinBox_9 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_9->setObjectName(QStringLiteral("doubleSpinBox_9"));
        doubleSpinBox_9->setDecimals(4);
        doubleSpinBox_9->setMinimum(-9999.99);
        doubleSpinBox_9->setMaximum(9999.99);

        horizontalLayout_6->addWidget(doubleSpinBox_9);

        label_19 = new QLabel(scrollAreaWidgetContents);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_6->addWidget(label_19);


        verticalLayout_2->addLayout(horizontalLayout_6);


        horizontalLayout_8->addLayout(verticalLayout_2);

        line = new QFrame(scrollAreaWidgetContents);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_8->addWidget(line);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButton_5 = new QPushButton(scrollAreaWidgetContents);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(scrollAreaWidgetContents);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(scrollAreaWidgetContents);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setEnabled(false);
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(scrollAreaWidgetContents);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy1.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(scrollAreaWidgetContents);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        sizePolicy1.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(scrollAreaWidgetContents);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        sizePolicy1.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(pushButton_10);

        checkBox_14 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_14->setObjectName(QStringLiteral("checkBox_14"));
        sizePolicy1.setHeightForWidth(checkBox_14->sizePolicy().hasHeightForWidth());
        checkBox_14->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(checkBox_14);

        lineEdit_16 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_16->setObjectName(QStringLiteral("lineEdit_16"));
        sizePolicy1.setHeightForWidth(lineEdit_16->sizePolicy().hasHeightForWidth());
        lineEdit_16->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(lineEdit_16);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lineEdit_10 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        sizePolicy1.setHeightForWidth(lineEdit_10->sizePolicy().hasHeightForWidth());
        lineEdit_10->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(lineEdit_10);

        checkBox_12 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_12->setObjectName(QStringLiteral("checkBox_12"));
        sizePolicy1.setHeightForWidth(checkBox_12->sizePolicy().hasHeightForWidth());
        checkBox_12->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(checkBox_12);

        lineEdit_15 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_15->setObjectName(QStringLiteral("lineEdit_15"));
        sizePolicy1.setHeightForWidth(lineEdit_15->sizePolicy().hasHeightForWidth());
        lineEdit_15->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(lineEdit_15);

        label_23 = new QLabel(scrollAreaWidgetContents);
        label_23->setObjectName(QStringLiteral("label_23"));

        horizontalLayout_4->addWidget(label_23);

        lineEdit_14 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));
        sizePolicy1.setHeightForWidth(lineEdit_14->sizePolicy().hasHeightForWidth());
        lineEdit_14->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(lineEdit_14);

        label_24 = new QLabel(scrollAreaWidgetContents);
        label_24->setObjectName(QStringLiteral("label_24"));

        horizontalLayout_4->addWidget(label_24);

        doubleSpinBox_13 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_13->setObjectName(QStringLiteral("doubleSpinBox_13"));
        doubleSpinBox_13->setSingleStep(0.1);
        doubleSpinBox_13->setValue(0.5);

        horizontalLayout_4->addWidget(doubleSpinBox_13);

        label_25 = new QLabel(scrollAreaWidgetContents);
        label_25->setObjectName(QStringLiteral("label_25"));

        horizontalLayout_4->addWidget(label_25);

        doubleSpinBox_14 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_14->setObjectName(QStringLiteral("doubleSpinBox_14"));
        doubleSpinBox_14->setSingleStep(0.1);
        doubleSpinBox_14->setValue(0.5);

        horizontalLayout_4->addWidget(doubleSpinBox_14);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_8->addLayout(verticalLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        checkBox_8 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_8->setObjectName(QStringLiteral("checkBox_8"));

        horizontalLayout_3->addWidget(checkBox_8);

        lineEdit_13 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_13->sizePolicy().hasHeightForWidth());
        lineEdit_13->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(lineEdit_13);

        label_22 = new QLabel(scrollAreaWidgetContents);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_3->addWidget(label_22);

        doubleSpinBox_10 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_10->setObjectName(QStringLiteral("doubleSpinBox_10"));
        doubleSpinBox_10->setDecimals(3);
        doubleSpinBox_10->setMinimum(-99.99);

        horizontalLayout_3->addWidget(doubleSpinBox_10);

        checkBox_9 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_9->setObjectName(QStringLiteral("checkBox_9"));

        horizontalLayout_3->addWidget(checkBox_9);

        doubleSpinBox_11 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_11->setObjectName(QStringLiteral("doubleSpinBox_11"));
        doubleSpinBox_11->setDecimals(4);
        doubleSpinBox_11->setMinimum(-9999.99);
        doubleSpinBox_11->setMaximum(9999.99);

        horizontalLayout_3->addWidget(doubleSpinBox_11);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_3->addWidget(label_11);

        lineEdit_5 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        sizePolicy1.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(lineEdit_5);

        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_3->addWidget(label_10);

        checkBox = new QCheckBox(scrollAreaWidgetContents);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_3->addWidget(checkBox);

        checkBox_3 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        horizontalLayout_3->addWidget(checkBox_3);

        checkBox_2 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        horizontalLayout_3->addWidget(checkBox_2);

        lineEdit_4 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        sizePolicy1.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(lineEdit_4);

        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_3->addWidget(label_12);

        spinBox_3 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        sizePolicy1.setHeightForWidth(spinBox_3->sizePolicy().hasHeightForWidth());
        spinBox_3->setSizePolicy(sizePolicy1);
        spinBox_3->setValue(9);

        horizontalLayout_3->addWidget(spinBox_3);

        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_3->addWidget(pushButton_4);

        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout_3);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(PlotSequ);
        QObject::connect(pushButton, SIGNAL(clicked()), PlotSequ, SLOT(close()));

        QMetaObject::connectSlotsByName(PlotSequ);
    } // setupUi

    void retranslateUi(QDialog *PlotSequ)
    {
        PlotSequ->setWindowTitle(QApplication::translate("PlotSequ", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("PlotSequ", "x1:", Q_NULLPTR));
        label_2->setText(QApplication::translate("PlotSequ", "X2:", Q_NULLPTR));
        label_3->setText(QApplication::translate("PlotSequ", "y1:", Q_NULLPTR));
        label_4->setText(QApplication::translate("PlotSequ", "y2:", Q_NULLPTR));
        checkBox_13->setText(QApplication::translate("PlotSequ", "Velocity to:", Q_NULLPTR));
        label_8->setText(QApplication::translate("PlotSequ", "x Label", Q_NULLPTR));
        label_9->setText(QApplication::translate("PlotSequ", "y Label", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("PlotSequ", "find values", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("PlotSequ", "Plot", Q_NULLPTR));
        label_5->setText(QApplication::translate("PlotSequ", "Files:", Q_NULLPTR));
        label_6->setText(QApplication::translate("PlotSequ", "from", Q_NULLPTR));
        label_7->setText(QApplication::translate("PlotSequ", "to", Q_NULLPTR));
        label_17->setText(QApplication::translate("PlotSequ", "*", Q_NULLPTR));
        label_13->setText(QApplication::translate("PlotSequ", "Offset", Q_NULLPTR));
        label_14->setText(QApplication::translate("PlotSequ", "Ext.", Q_NULLPTR));
        label_15->setText(QApplication::translate("PlotSequ", "W.Col.", Q_NULLPTR));
        label_16->setText(QApplication::translate("PlotSequ", "I.Col.", Q_NULLPTR));
        checkBox_15->setText(QApplication::translate("PlotSequ", "log(x)", Q_NULLPTR));
        checkBox_16->setText(QApplication::translate("PlotSequ", "10^x", Q_NULLPTR));
        label_26->setText(QString());
        checkBox_10->setText(QApplication::translate("PlotSequ", "Plot above", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("PlotSequ", "Overplot 1:", Q_NULLPTR));
        label_20->setText(QApplication::translate("PlotSequ", "<html><head/><body><p><span style=\" color:#e215da;\">Add</span></p></body></html>", Q_NULLPTR));
        checkBox_17->setText(QApplication::translate("PlotSequ", "log(x)", Q_NULLPTR));
        checkBox_19->setText(QApplication::translate("PlotSequ", "10^x", Q_NULLPTR));
        checkBox_6->setText(QApplication::translate("PlotSequ", "Shift", Q_NULLPTR));
        label_18->setText(QApplication::translate("PlotSequ", "km/s", Q_NULLPTR));
        checkBox_11->setText(QApplication::translate("PlotSequ", "Plot above", Q_NULLPTR));
        checkBox_5->setText(QApplication::translate("PlotSequ", "Overplot 2:", Q_NULLPTR));
        label_21->setText(QApplication::translate("PlotSequ", "<html><head/><body><p><span style=\" color:#204a87;\">Add</span></p></body></html>", Q_NULLPTR));
        checkBox_18->setText(QApplication::translate("PlotSequ", "log(x)", Q_NULLPTR));
        checkBox_20->setText(QApplication::translate("PlotSequ", "10^x", Q_NULLPTR));
        checkBox_7->setText(QApplication::translate("PlotSequ", "Shift", Q_NULLPTR));
        label_19->setText(QApplication::translate("PlotSequ", "km/s", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("PlotSequ", "Co-Add", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("PlotSequ", "Co-Average", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("PlotSequ", "Median", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("PlotSequ", "Moments RV", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("PlotSequ", "Bisec", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("PlotSequ", "Moments", Q_NULLPTR));
        checkBox_14->setText(QApplication::translate("PlotSequ", "times", Q_NULLPTR));
        checkBox_12->setText(QApplication::translate("PlotSequ", "/w RV List", Q_NULLPTR));
        label_23->setText(QApplication::translate("PlotSequ", "Wavelength", Q_NULLPTR));
        label_24->setText(QApplication::translate("PlotSequ", "+", Q_NULLPTR));
        label_25->setText(QApplication::translate("PlotSequ", "-", Q_NULLPTR));
        checkBox_8->setText(QApplication::translate("PlotSequ", "DIfferences:", Q_NULLPTR));
        label_22->setText(QApplication::translate("PlotSequ", "<html><head/><body><p><span style=\" color:#4e9a06;\">Add</span></p></body></html>", Q_NULLPTR));
        checkBox_9->setText(QApplication::translate("PlotSequ", "Shift", Q_NULLPTR));
        label_11->setText(QApplication::translate("PlotSequ", "work path", Q_NULLPTR));
        label_10->setText(QApplication::translate("PlotSequ", "Save as", Q_NULLPTR));
        checkBox->setText(QApplication::translate("PlotSequ", "pdf", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("PlotSequ", "jpg", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("PlotSequ", "png", Q_NULLPTR));
        label_12->setText(QApplication::translate("PlotSequ", "Font Size:", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("PlotSequ", "Save", Q_NULLPTR));
        pushButton->setText(QApplication::translate("PlotSequ", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PlotSequ: public Ui_PlotSequ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTSEQU_H
