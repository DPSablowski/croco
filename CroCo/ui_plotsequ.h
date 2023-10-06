/********************************************************************************
** Form generated from reading UI file 'plotsequ.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTSEQU_H
#define UI_PLOTSEQU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
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
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
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
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *checkBox_8;
    QLineEdit *lineEdit_13;
    QLabel *label_22;
    QDoubleSpinBox *doubleSpinBox_10;
    QCheckBox *checkBox_9;
    QDoubleSpinBox *doubleSpinBox_11;
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
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox_21;
    QLineEdit *lineEdit_19;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QCheckBox *checkBox;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_2;
    QLineEdit *lineEdit_4;
    QLabel *label_29;
    QLineEdit *lineEdit_17;
    QLabel *label_30;
    QLineEdit *lineEdit_18;
    QPushButton *pushButton_4;
    QLabel *label_11;
    QLineEdit *lineEdit_5;
    QLabel *label_12;
    QSpinBox *spinBox_3;
    QLabel *label_27;
    QDoubleSpinBox *doubleSpinBox_15;
    QLabel *label_28;
    QDoubleSpinBox *doubleSpinBox_16;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *PlotSequ)
    {
        if (PlotSequ->objectName().isEmpty())
            PlotSequ->setObjectName(QString::fromUtf8("PlotSequ"));
        PlotSequ->resize(1316, 591);
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
        QBrush brush9(QColor(0, 0, 0, 128));
        brush9.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
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
        QBrush brush10(QColor(0, 0, 0, 128));
        brush10.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
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
        QBrush brush11(QColor(0, 0, 0, 128));
        brush11.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        PlotSequ->setPalette(palette);
        QFont font;
        font.setPointSize(9);
        PlotSequ->setFont(font);
        gridLayout = new QGridLayout(PlotSequ);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(PlotSequ);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(-2, 0, 1298, 557));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        customPlot = new QCustomPlot(scrollAreaWidgetContents);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(customPlot);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton_11 = new QPushButton(scrollAreaWidgetContents);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy1);
        pushButton_11->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(pushButton_11);

        pushButton_12 = new QPushButton(scrollAreaWidgetContents);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        sizePolicy1.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy1);
        pushButton_12->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(pushButton_12);

        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        doubleSpinBox = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setDecimals(4);
        doubleSpinBox->setMinimum(-9999.000000000000000);
        doubleSpinBox->setMaximum(9999.000000000000000);

        horizontalLayout->addWidget(doubleSpinBox);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        doubleSpinBox_2 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setDecimals(4);
        doubleSpinBox_2->setMinimum(-9999.000000000000000);
        doubleSpinBox_2->setMaximum(9999.000000000000000);
        doubleSpinBox_2->setValue(0.000000000000000);

        horizontalLayout->addWidget(doubleSpinBox_2);

        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        doubleSpinBox_3 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setDecimals(11);
        doubleSpinBox_3->setMinimum(-999.000000000000000);
        doubleSpinBox_3->setMaximum(9999.989999999999782);

        horizontalLayout->addWidget(doubleSpinBox_3);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        doubleSpinBox_4 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setDecimals(11);
        doubleSpinBox_4->setMinimum(-999.000000000000000);
        doubleSpinBox_4->setMaximum(9999.000000000000000);

        horizontalLayout->addWidget(doubleSpinBox_4);

        checkBox_13 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_13->setObjectName(QString::fromUtf8("checkBox_13"));

        horizontalLayout->addWidget(checkBox_13);

        doubleSpinBox_12 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_12->setObjectName(QString::fromUtf8("doubleSpinBox_12"));
        doubleSpinBox_12->setDecimals(3);
        doubleSpinBox_12->setMaximum(9999.989999999999782);

        horizontalLayout->addWidget(doubleSpinBox_12);

        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout->addWidget(label_8);

        lineEdit_2 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(lineEdit_2);

        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout->addWidget(label_9);

        lineEdit_3 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        sizePolicy1.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(lineEdit_3);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        lineEdit = new QLineEdit(scrollAreaWidgetContents);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(lineEdit);

        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        spinBox = new QSpinBox(scrollAreaWidgetContents);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(9999);
        spinBox->setValue(0);

        horizontalLayout_2->addWidget(spinBox);

        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_2->addWidget(label_7);

        spinBox_2 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMaximum(9999);
        spinBox_2->setValue(1);

        horizontalLayout_2->addWidget(spinBox_2);

        label_17 = new QLabel(scrollAreaWidgetContents);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_2->addWidget(label_17);

        lineEdit_9 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        sizePolicy1.setHeightForWidth(lineEdit_9->sizePolicy().hasHeightForWidth());
        lineEdit_9->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(lineEdit_9);

        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_2->addWidget(label_13);

        doubleSpinBox_5 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));
        doubleSpinBox_5->setDecimals(13);
        doubleSpinBox_5->setMinimum(-99.000000000000000);
        doubleSpinBox_5->setMaximum(99999.990000000005239);
        doubleSpinBox_5->setSingleStep(0.100000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox_5);

        comboBox = new QComboBox(scrollAreaWidgetContents);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        label_14 = new QLabel(scrollAreaWidgetContents);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_2->addWidget(label_14);

        lineEdit_6 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        sizePolicy1.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy1);
        lineEdit_6->setCursor(QCursor(Qt::IBeamCursor));

        horizontalLayout_2->addWidget(lineEdit_6);

        label_15 = new QLabel(scrollAreaWidgetContents);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_2->addWidget(label_15);

        lineEdit_7 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        sizePolicy1.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(lineEdit_7);

        label_16 = new QLabel(scrollAreaWidgetContents);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_2->addWidget(label_16);

        lineEdit_8 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        sizePolicy1.setHeightForWidth(lineEdit_8->sizePolicy().hasHeightForWidth());
        lineEdit_8->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(lineEdit_8);

        checkBox_15 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_15->setObjectName(QString::fromUtf8("checkBox_15"));

        horizontalLayout_2->addWidget(checkBox_15);

        checkBox_16 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_16->setObjectName(QString::fromUtf8("checkBox_16"));

        horizontalLayout_2->addWidget(checkBox_16);

        label_26 = new QLabel(scrollAreaWidgetContents);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        horizontalLayout_2->addWidget(label_26);

        comboBox_2 = new QComboBox(scrollAreaWidgetContents);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        sizePolicy1.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(comboBox_2);

        spinBox_4 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setMinimum(1);

        horizontalLayout_2->addWidget(spinBox_4);


        verticalLayout_3->addLayout(horizontalLayout_2);

        line_2 = new QFrame(scrollAreaWidgetContents);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        checkBox_10 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));

        horizontalLayout_5->addWidget(checkBox_10);

        checkBox_4 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        horizontalLayout_5->addWidget(checkBox_4);

        lineEdit_11 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));
        sizePolicy1.setHeightForWidth(lineEdit_11->sizePolicy().hasHeightForWidth());
        lineEdit_11->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(lineEdit_11);

        label_20 = new QLabel(scrollAreaWidgetContents);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_5->addWidget(label_20);

        doubleSpinBox_6 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_6->setObjectName(QString::fromUtf8("doubleSpinBox_6"));
        doubleSpinBox_6->setDecimals(3);
        doubleSpinBox_6->setMinimum(-99.989999999999995);
        doubleSpinBox_6->setSingleStep(0.100000000000000);

        horizontalLayout_5->addWidget(doubleSpinBox_6);

        checkBox_17 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_17->setObjectName(QString::fromUtf8("checkBox_17"));

        horizontalLayout_5->addWidget(checkBox_17);

        checkBox_19 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_19->setObjectName(QString::fromUtf8("checkBox_19"));

        horizontalLayout_5->addWidget(checkBox_19);

        checkBox_6 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));

        horizontalLayout_5->addWidget(checkBox_6);

        doubleSpinBox_8 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_8->setObjectName(QString::fromUtf8("doubleSpinBox_8"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_8->sizePolicy().hasHeightForWidth());
        doubleSpinBox_8->setSizePolicy(sizePolicy1);
        doubleSpinBox_8->setDecimals(4);
        doubleSpinBox_8->setMinimum(-9999.989999999999782);
        doubleSpinBox_8->setMaximum(9999.989999999999782);

        horizontalLayout_5->addWidget(doubleSpinBox_8);

        label_18 = new QLabel(scrollAreaWidgetContents);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_5->addWidget(label_18);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        checkBox_11 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_11->setObjectName(QString::fromUtf8("checkBox_11"));

        horizontalLayout_6->addWidget(checkBox_11);

        checkBox_5 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));

        horizontalLayout_6->addWidget(checkBox_5);

        lineEdit_12 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));
        sizePolicy1.setHeightForWidth(lineEdit_12->sizePolicy().hasHeightForWidth());
        lineEdit_12->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(lineEdit_12);

        label_21 = new QLabel(scrollAreaWidgetContents);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_6->addWidget(label_21);

        doubleSpinBox_7 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_7->setObjectName(QString::fromUtf8("doubleSpinBox_7"));
        doubleSpinBox_7->setDecimals(3);
        doubleSpinBox_7->setMinimum(-99.989999999999995);
        doubleSpinBox_7->setSingleStep(0.100000000000000);

        horizontalLayout_6->addWidget(doubleSpinBox_7);

        checkBox_18 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_18->setObjectName(QString::fromUtf8("checkBox_18"));

        horizontalLayout_6->addWidget(checkBox_18);

        checkBox_20 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_20->setObjectName(QString::fromUtf8("checkBox_20"));

        horizontalLayout_6->addWidget(checkBox_20);

        checkBox_7 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));

        horizontalLayout_6->addWidget(checkBox_7);

        doubleSpinBox_9 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_9->setObjectName(QString::fromUtf8("doubleSpinBox_9"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_9->sizePolicy().hasHeightForWidth());
        doubleSpinBox_9->setSizePolicy(sizePolicy1);
        doubleSpinBox_9->setDecimals(4);
        doubleSpinBox_9->setMinimum(-9999.989999999999782);
        doubleSpinBox_9->setMaximum(9999.989999999999782);

        horizontalLayout_6->addWidget(doubleSpinBox_9);

        label_19 = new QLabel(scrollAreaWidgetContents);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_6->addWidget(label_19);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        checkBox_8 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));

        horizontalLayout_10->addWidget(checkBox_8);

        lineEdit_13 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_13->sizePolicy().hasHeightForWidth());
        lineEdit_13->setSizePolicy(sizePolicy2);
        lineEdit_13->setMinimumSize(QSize(100, 0));
        lineEdit_13->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_10->addWidget(lineEdit_13);

        label_22 = new QLabel(scrollAreaWidgetContents);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_10->addWidget(label_22);

        doubleSpinBox_10 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_10->setObjectName(QString::fromUtf8("doubleSpinBox_10"));
        doubleSpinBox_10->setDecimals(3);
        doubleSpinBox_10->setMinimum(-99.989999999999995);

        horizontalLayout_10->addWidget(doubleSpinBox_10);

        checkBox_9 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));

        horizontalLayout_10->addWidget(checkBox_9);

        doubleSpinBox_11 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_11->setObjectName(QString::fromUtf8("doubleSpinBox_11"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_11->sizePolicy().hasHeightForWidth());
        doubleSpinBox_11->setSizePolicy(sizePolicy1);
        doubleSpinBox_11->setDecimals(4);
        doubleSpinBox_11->setMinimum(-9999.989999999999782);
        doubleSpinBox_11->setMaximum(9999.989999999999782);

        horizontalLayout_10->addWidget(doubleSpinBox_11);


        verticalLayout_2->addLayout(horizontalLayout_10);


        horizontalLayout_8->addLayout(verticalLayout_2);

        line = new QFrame(scrollAreaWidgetContents);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_8->addWidget(line);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        pushButton_5 = new QPushButton(scrollAreaWidgetContents);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(scrollAreaWidgetContents);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(scrollAreaWidgetContents);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(scrollAreaWidgetContents);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        sizePolicy1.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(scrollAreaWidgetContents);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        sizePolicy1.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(scrollAreaWidgetContents);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        sizePolicy1.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(pushButton_10);

        checkBox_14 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_14->setObjectName(QString::fromUtf8("checkBox_14"));
        sizePolicy1.setHeightForWidth(checkBox_14->sizePolicy().hasHeightForWidth());
        checkBox_14->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(checkBox_14);

        lineEdit_16 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_16->setObjectName(QString::fromUtf8("lineEdit_16"));
        sizePolicy1.setHeightForWidth(lineEdit_16->sizePolicy().hasHeightForWidth());
        lineEdit_16->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(lineEdit_16);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lineEdit_10 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        sizePolicy1.setHeightForWidth(lineEdit_10->sizePolicy().hasHeightForWidth());
        lineEdit_10->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(lineEdit_10);

        checkBox_12 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_12->setObjectName(QString::fromUtf8("checkBox_12"));
        sizePolicy1.setHeightForWidth(checkBox_12->sizePolicy().hasHeightForWidth());
        checkBox_12->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(checkBox_12);

        lineEdit_15 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_15->setObjectName(QString::fromUtf8("lineEdit_15"));
        sizePolicy1.setHeightForWidth(lineEdit_15->sizePolicy().hasHeightForWidth());
        lineEdit_15->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(lineEdit_15);

        label_23 = new QLabel(scrollAreaWidgetContents);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_4->addWidget(label_23);

        lineEdit_14 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_14->setObjectName(QString::fromUtf8("lineEdit_14"));
        sizePolicy1.setHeightForWidth(lineEdit_14->sizePolicy().hasHeightForWidth());
        lineEdit_14->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(lineEdit_14);

        label_24 = new QLabel(scrollAreaWidgetContents);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_4->addWidget(label_24);

        doubleSpinBox_13 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_13->setObjectName(QString::fromUtf8("doubleSpinBox_13"));
        doubleSpinBox_13->setSingleStep(0.100000000000000);
        doubleSpinBox_13->setValue(0.500000000000000);

        horizontalLayout_4->addWidget(doubleSpinBox_13);

        label_25 = new QLabel(scrollAreaWidgetContents);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout_4->addWidget(label_25);

        doubleSpinBox_14 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_14->setObjectName(QString::fromUtf8("doubleSpinBox_14"));
        doubleSpinBox_14->setSingleStep(0.100000000000000);
        doubleSpinBox_14->setValue(0.500000000000000);

        horizontalLayout_4->addWidget(doubleSpinBox_14);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        checkBox_21 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_21->setObjectName(QString::fromUtf8("checkBox_21"));
        sizePolicy1.setHeightForWidth(checkBox_21->sizePolicy().hasHeightForWidth());
        checkBox_21->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(checkBox_21);

        lineEdit_19 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_19->setObjectName(QString::fromUtf8("lineEdit_19"));
        sizePolicy1.setHeightForWidth(lineEdit_19->sizePolicy().hasHeightForWidth());
        lineEdit_19->setSizePolicy(sizePolicy1);
        lineEdit_19->setMinimumSize(QSize(125, 0));
        lineEdit_19->setMaximumSize(QSize(125, 16777215));

        horizontalLayout_3->addWidget(lineEdit_19);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_8->addLayout(verticalLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_9->addWidget(label_10);

        checkBox = new QCheckBox(scrollAreaWidgetContents);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout_9->addWidget(checkBox);

        checkBox_3 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        horizontalLayout_9->addWidget(checkBox_3);

        checkBox_2 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        horizontalLayout_9->addWidget(checkBox_2);

        lineEdit_4 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        sizePolicy1.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(lineEdit_4);

        label_29 = new QLabel(scrollAreaWidgetContents);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        horizontalLayout_9->addWidget(label_29);

        lineEdit_17 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_17->setObjectName(QString::fromUtf8("lineEdit_17"));
        sizePolicy1.setHeightForWidth(lineEdit_17->sizePolicy().hasHeightForWidth());
        lineEdit_17->setSizePolicy(sizePolicy1);
        lineEdit_17->setMinimumSize(QSize(100, 0));
        lineEdit_17->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_9->addWidget(lineEdit_17);

        label_30 = new QLabel(scrollAreaWidgetContents);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        horizontalLayout_9->addWidget(label_30);

        lineEdit_18 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_18->setObjectName(QString::fromUtf8("lineEdit_18"));
        sizePolicy1.setHeightForWidth(lineEdit_18->sizePolicy().hasHeightForWidth());
        lineEdit_18->setSizePolicy(sizePolicy1);
        lineEdit_18->setMinimumSize(QSize(100, 0));
        lineEdit_18->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_9->addWidget(lineEdit_18);

        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_9->addWidget(pushButton_4);

        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_9->addWidget(label_11);

        lineEdit_5 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        sizePolicy1.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy1);
        lineEdit_5->setMinimumSize(QSize(125, 0));
        lineEdit_5->setMaximumSize(QSize(125, 16777215));

        horizontalLayout_9->addWidget(lineEdit_5);

        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_9->addWidget(label_12);

        spinBox_3 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        sizePolicy1.setHeightForWidth(spinBox_3->sizePolicy().hasHeightForWidth());
        spinBox_3->setSizePolicy(sizePolicy1);
        spinBox_3->setValue(9);

        horizontalLayout_9->addWidget(spinBox_3);

        label_27 = new QLabel(scrollAreaWidgetContents);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        horizontalLayout_9->addWidget(label_27);

        doubleSpinBox_15 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_15->setObjectName(QString::fromUtf8("doubleSpinBox_15"));
        doubleSpinBox_15->setDecimals(3);
        doubleSpinBox_15->setMinimum(0.000000000000000);
        doubleSpinBox_15->setMaximum(999.990000000000009);
        doubleSpinBox_15->setSingleStep(0.100000000000000);
        doubleSpinBox_15->setValue(0.500000000000000);

        horizontalLayout_9->addWidget(doubleSpinBox_15);

        label_28 = new QLabel(scrollAreaWidgetContents);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        horizontalLayout_9->addWidget(label_28);

        doubleSpinBox_16 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_16->setObjectName(QString::fromUtf8("doubleSpinBox_16"));
        doubleSpinBox_16->setDecimals(3);
        doubleSpinBox_16->setMaximum(999.990000000000009);
        doubleSpinBox_16->setSingleStep(0.020000000000000);
        doubleSpinBox_16->setValue(0.500000000000000);

        horizontalLayout_9->addWidget(doubleSpinBox_16);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_9->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout_9);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(PlotSequ);
        QObject::connect(pushButton, SIGNAL(clicked()), PlotSequ, SLOT(close()));

        QMetaObject::connectSlotsByName(PlotSequ);
    } // setupUi

    void retranslateUi(QDialog *PlotSequ)
    {
        PlotSequ->setWindowTitle(QCoreApplication::translate("PlotSequ", "Dialog", nullptr));
        pushButton_11->setText(QCoreApplication::translate("PlotSequ", "<<", nullptr));
        pushButton_12->setText(QCoreApplication::translate("PlotSequ", ">>", nullptr));
        label->setText(QCoreApplication::translate("PlotSequ", "x1:", nullptr));
        label_2->setText(QCoreApplication::translate("PlotSequ", "X2:", nullptr));
        label_3->setText(QCoreApplication::translate("PlotSequ", "y1:", nullptr));
        label_4->setText(QCoreApplication::translate("PlotSequ", "y2:", nullptr));
        checkBox_13->setText(QCoreApplication::translate("PlotSequ", "Velocity to:", nullptr));
        label_8->setText(QCoreApplication::translate("PlotSequ", "x Label", nullptr));
        label_9->setText(QCoreApplication::translate("PlotSequ", "y Label", nullptr));
        pushButton_3->setText(QCoreApplication::translate("PlotSequ", "find values", nullptr));
        pushButton_2->setText(QCoreApplication::translate("PlotSequ", "Plot", nullptr));
        label_5->setText(QCoreApplication::translate("PlotSequ", "Files:", nullptr));
        label_6->setText(QCoreApplication::translate("PlotSequ", "from", nullptr));
        label_7->setText(QCoreApplication::translate("PlotSequ", "to", nullptr));
        label_17->setText(QCoreApplication::translate("PlotSequ", "*", nullptr));
        label_13->setText(QCoreApplication::translate("PlotSequ", "Offset", nullptr));
        label_14->setText(QCoreApplication::translate("PlotSequ", "Ext.", nullptr));
        label_15->setText(QCoreApplication::translate("PlotSequ", "W.Col.", nullptr));
        label_16->setText(QCoreApplication::translate("PlotSequ", "I.Col.", nullptr));
        checkBox_15->setText(QCoreApplication::translate("PlotSequ", "log(x)", nullptr));
        checkBox_16->setText(QCoreApplication::translate("PlotSequ", "10^x", nullptr));
        label_26->setText(QString());
        checkBox_10->setText(QCoreApplication::translate("PlotSequ", "Plot above", nullptr));
        checkBox_4->setText(QCoreApplication::translate("PlotSequ", "Overplot 1:", nullptr));
        label_20->setText(QCoreApplication::translate("PlotSequ", "<html><head/><body><p><span style=\" color:#e215da;\">Add</span></p></body></html>", nullptr));
        checkBox_17->setText(QCoreApplication::translate("PlotSequ", "log(x)", nullptr));
        checkBox_19->setText(QCoreApplication::translate("PlotSequ", "10^x", nullptr));
        checkBox_6->setText(QCoreApplication::translate("PlotSequ", "Shift", nullptr));
        label_18->setText(QCoreApplication::translate("PlotSequ", "km/s", nullptr));
        checkBox_11->setText(QCoreApplication::translate("PlotSequ", "Plot above", nullptr));
        checkBox_5->setText(QCoreApplication::translate("PlotSequ", "Overplot 2:", nullptr));
        label_21->setText(QCoreApplication::translate("PlotSequ", "<html><head/><body><p><span style=\" color:#204a87;\">Add</span></p></body></html>", nullptr));
        checkBox_18->setText(QCoreApplication::translate("PlotSequ", "log(x)", nullptr));
        checkBox_20->setText(QCoreApplication::translate("PlotSequ", "10^x", nullptr));
        checkBox_7->setText(QCoreApplication::translate("PlotSequ", "Shift", nullptr));
        label_19->setText(QCoreApplication::translate("PlotSequ", "km/s", nullptr));
        checkBox_8->setText(QCoreApplication::translate("PlotSequ", "DIfferences:", nullptr));
        label_22->setText(QCoreApplication::translate("PlotSequ", "<html><head/><body><p><span style=\" color:#4e9a06;\">Add</span></p></body></html>", nullptr));
        checkBox_9->setText(QCoreApplication::translate("PlotSequ", "Shift", nullptr));
        pushButton_5->setText(QCoreApplication::translate("PlotSequ", "Co-Add", nullptr));
        pushButton_6->setText(QCoreApplication::translate("PlotSequ", "Co-Average", nullptr));
        pushButton_7->setText(QCoreApplication::translate("PlotSequ", "Median", nullptr));
        pushButton_8->setText(QCoreApplication::translate("PlotSequ", "Moments RV", nullptr));
        pushButton_9->setText(QCoreApplication::translate("PlotSequ", "Bisec", nullptr));
        pushButton_10->setText(QCoreApplication::translate("PlotSequ", "Moments", nullptr));
        checkBox_14->setText(QCoreApplication::translate("PlotSequ", "times", nullptr));
        checkBox_12->setText(QCoreApplication::translate("PlotSequ", "/w RV List", nullptr));
        label_23->setText(QCoreApplication::translate("PlotSequ", "Wavelength", nullptr));
        label_24->setText(QCoreApplication::translate("PlotSequ", "+", nullptr));
        label_25->setText(QCoreApplication::translate("PlotSequ", "-", nullptr));
        checkBox_21->setText(QCoreApplication::translate("PlotSequ", "List of Files to be processed:", nullptr));
        label_10->setText(QCoreApplication::translate("PlotSequ", "Save as", nullptr));
        checkBox->setText(QCoreApplication::translate("PlotSequ", "pdf", nullptr));
        checkBox_3->setText(QCoreApplication::translate("PlotSequ", "jpg", nullptr));
        checkBox_2->setText(QCoreApplication::translate("PlotSequ", "png", nullptr));
        label_29->setText(QCoreApplication::translate("PlotSequ", "Size", nullptr));
        label_30->setText(QCoreApplication::translate("PlotSequ", "x", nullptr));
        pushButton_4->setText(QCoreApplication::translate("PlotSequ", "Save", nullptr));
        label_11->setText(QCoreApplication::translate("PlotSequ", "work path", nullptr));
        label_12->setText(QCoreApplication::translate("PlotSequ", "Font Size:", nullptr));
        label_27->setText(QCoreApplication::translate("PlotSequ", "Tick Step x", nullptr));
        label_28->setText(QCoreApplication::translate("PlotSequ", "y", nullptr));
        pushButton->setText(QCoreApplication::translate("PlotSequ", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlotSequ: public Ui_PlotSequ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTSEQU_H
