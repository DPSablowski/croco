/********************************************************************************
** Form generated from reading UI file 'cpd.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPD_H
#define UI_CPD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CPD
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QSpinBox *spinBox;
    QLabel *label_3;
    QSpinBox *spinBox_2;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label_27;
    QLineEdit *lineEdit_4;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_20;
    QDoubleSpinBox *doubleSpinBox_13;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_21;
    QDoubleSpinBox *doubleSpinBox_14;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox_3;
    QDoubleSpinBox *doubleSpinBox_5;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_6;
    QLabel *label_22;
    QDoubleSpinBox *doubleSpinBox_15;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_14;
    QDoubleSpinBox *doubleSpinBox_7;
    QLabel *label_17;
    QDoubleSpinBox *doubleSpinBox_8;
    QLabel *label_23;
    QDoubleSpinBox *doubleSpinBox_16;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_15;
    QDoubleSpinBox *doubleSpinBox_9;
    QLabel *label_18;
    QDoubleSpinBox *doubleSpinBox_10;
    QLabel *label_24;
    QDoubleSpinBox *doubleSpinBox_17;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_16;
    QDoubleSpinBox *doubleSpinBox_11;
    QLabel *label_19;
    QDoubleSpinBox *doubleSpinBox_12;
    QLabel *label_25;
    QDoubleSpinBox *doubleSpinBox_18;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_26;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;

    void setupUi(QDialog *CPD)
    {
        if (CPD->objectName().isEmpty())
            CPD->setObjectName(QString::fromUtf8("CPD"));
        CPD->resize(948, 280);
        verticalLayout_3 = new QVBoxLayout(CPD);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(CPD);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(CPD);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit);

        label_2 = new QLabel(CPD);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        spinBox = new QSpinBox(CPD);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(999);

        horizontalLayout->addWidget(spinBox);

        label_3 = new QLabel(CPD);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        spinBox_2 = new QSpinBox(CPD);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMaximum(999);

        horizontalLayout->addWidget(spinBox_2);

        label_4 = new QLabel(CPD);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        lineEdit_2 = new QLineEdit(CPD);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_2);

        label_27 = new QLabel(CPD);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        horizontalLayout->addWidget(label_27);

        lineEdit_4 = new QLineEdit(CPD);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        sizePolicy.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_12 = new QLabel(CPD);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout->addWidget(label_12);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        checkBox = new QCheckBox(CPD);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout_2->addWidget(checkBox);

        doubleSpinBox = new QDoubleSpinBox(CPD);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setDecimals(4);
        doubleSpinBox->setMaximum(9999.989999999999782);
        doubleSpinBox->setValue(4255.000000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox);

        label_6 = new QLabel(CPD);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        doubleSpinBox_2 = new QDoubleSpinBox(CPD);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setDecimals(4);
        doubleSpinBox_2->setMaximum(9999.989999999999782);
        doubleSpinBox_2->setValue(4260.000000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox_2);

        label_20 = new QLabel(CPD);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_2->addWidget(label_20);

        doubleSpinBox_13 = new QDoubleSpinBox(CPD);
        doubleSpinBox_13->setObjectName(QString::fromUtf8("doubleSpinBox_13"));
        doubleSpinBox_13->setDecimals(5);
        doubleSpinBox_13->setMaximum(9.990000000000000);
        doubleSpinBox_13->setValue(0.500000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox_13);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        checkBox_2 = new QCheckBox(CPD);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        horizontalLayout_3->addWidget(checkBox_2);

        doubleSpinBox_3 = new QDoubleSpinBox(CPD);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setDecimals(4);
        doubleSpinBox_3->setMaximum(9999.989999999999782);

        horizontalLayout_3->addWidget(doubleSpinBox_3);

        label_8 = new QLabel(CPD);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_3->addWidget(label_8);

        doubleSpinBox_4 = new QDoubleSpinBox(CPD);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setDecimals(4);
        doubleSpinBox_4->setMaximum(9999.989999999999782);

        horizontalLayout_3->addWidget(doubleSpinBox_4);

        label_21 = new QLabel(CPD);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_3->addWidget(label_21);

        doubleSpinBox_14 = new QDoubleSpinBox(CPD);
        doubleSpinBox_14->setObjectName(QString::fromUtf8("doubleSpinBox_14"));
        doubleSpinBox_14->setDecimals(5);
        doubleSpinBox_14->setMaximum(9.990000000000000);

        horizontalLayout_3->addWidget(doubleSpinBox_14);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        checkBox_3 = new QCheckBox(CPD);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        horizontalLayout_4->addWidget(checkBox_3);

        doubleSpinBox_5 = new QDoubleSpinBox(CPD);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));
        doubleSpinBox_5->setDecimals(4);
        doubleSpinBox_5->setMaximum(9999.989999999999782);

        horizontalLayout_4->addWidget(doubleSpinBox_5);

        label_10 = new QLabel(CPD);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_4->addWidget(label_10);

        doubleSpinBox_6 = new QDoubleSpinBox(CPD);
        doubleSpinBox_6->setObjectName(QString::fromUtf8("doubleSpinBox_6"));
        doubleSpinBox_6->setDecimals(4);
        doubleSpinBox_6->setMaximum(9999.989999999999782);

        horizontalLayout_4->addWidget(doubleSpinBox_6);

        label_22 = new QLabel(CPD);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_4->addWidget(label_22);

        doubleSpinBox_15 = new QDoubleSpinBox(CPD);
        doubleSpinBox_15->setObjectName(QString::fromUtf8("doubleSpinBox_15"));
        doubleSpinBox_15->setDecimals(5);
        doubleSpinBox_15->setMaximum(9.990000000000000);

        horizontalLayout_4->addWidget(doubleSpinBox_15);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_8->addLayout(verticalLayout);

        line = new QFrame(CPD);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_8->addWidget(line);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_13 = new QLabel(CPD);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_2->addWidget(label_13);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_14 = new QLabel(CPD);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_7->addWidget(label_14);

        doubleSpinBox_7 = new QDoubleSpinBox(CPD);
        doubleSpinBox_7->setObjectName(QString::fromUtf8("doubleSpinBox_7"));
        doubleSpinBox_7->setDecimals(4);
        doubleSpinBox_7->setMaximum(9999.989999999999782);
        doubleSpinBox_7->setValue(4300.000000000000000);

        horizontalLayout_7->addWidget(doubleSpinBox_7);

        label_17 = new QLabel(CPD);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_7->addWidget(label_17);

        doubleSpinBox_8 = new QDoubleSpinBox(CPD);
        doubleSpinBox_8->setObjectName(QString::fromUtf8("doubleSpinBox_8"));
        doubleSpinBox_8->setDecimals(4);
        doubleSpinBox_8->setMaximum(9999.989999999999782);
        doubleSpinBox_8->setValue(4305.000000000000000);

        horizontalLayout_7->addWidget(doubleSpinBox_8);

        label_23 = new QLabel(CPD);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_7->addWidget(label_23);

        doubleSpinBox_16 = new QDoubleSpinBox(CPD);
        doubleSpinBox_16->setObjectName(QString::fromUtf8("doubleSpinBox_16"));
        doubleSpinBox_16->setDecimals(5);
        doubleSpinBox_16->setMaximum(9999.989999999999782);
        doubleSpinBox_16->setValue(0.500000000000000);

        horizontalLayout_7->addWidget(doubleSpinBox_16);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_15 = new QLabel(CPD);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_6->addWidget(label_15);

        doubleSpinBox_9 = new QDoubleSpinBox(CPD);
        doubleSpinBox_9->setObjectName(QString::fromUtf8("doubleSpinBox_9"));
        doubleSpinBox_9->setDecimals(4);
        doubleSpinBox_9->setMaximum(9999.989999999999782);

        horizontalLayout_6->addWidget(doubleSpinBox_9);

        label_18 = new QLabel(CPD);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_6->addWidget(label_18);

        doubleSpinBox_10 = new QDoubleSpinBox(CPD);
        doubleSpinBox_10->setObjectName(QString::fromUtf8("doubleSpinBox_10"));
        doubleSpinBox_10->setDecimals(4);
        doubleSpinBox_10->setMaximum(9999.989999999999782);

        horizontalLayout_6->addWidget(doubleSpinBox_10);

        label_24 = new QLabel(CPD);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_6->addWidget(label_24);

        doubleSpinBox_17 = new QDoubleSpinBox(CPD);
        doubleSpinBox_17->setObjectName(QString::fromUtf8("doubleSpinBox_17"));
        doubleSpinBox_17->setDecimals(5);
        doubleSpinBox_17->setMaximum(9999.989999999999782);

        horizontalLayout_6->addWidget(doubleSpinBox_17);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_16 = new QLabel(CPD);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_5->addWidget(label_16);

        doubleSpinBox_11 = new QDoubleSpinBox(CPD);
        doubleSpinBox_11->setObjectName(QString::fromUtf8("doubleSpinBox_11"));
        doubleSpinBox_11->setDecimals(4);
        doubleSpinBox_11->setMaximum(9999.989999999999782);

        horizontalLayout_5->addWidget(doubleSpinBox_11);

        label_19 = new QLabel(CPD);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_5->addWidget(label_19);

        doubleSpinBox_12 = new QDoubleSpinBox(CPD);
        doubleSpinBox_12->setObjectName(QString::fromUtf8("doubleSpinBox_12"));
        doubleSpinBox_12->setDecimals(4);
        doubleSpinBox_12->setMaximum(9999.989999999999782);

        horizontalLayout_5->addWidget(doubleSpinBox_12);

        label_25 = new QLabel(CPD);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout_5->addWidget(label_25);

        doubleSpinBox_18 = new QDoubleSpinBox(CPD);
        doubleSpinBox_18->setObjectName(QString::fromUtf8("doubleSpinBox_18"));
        doubleSpinBox_18->setDecimals(5);
        doubleSpinBox_18->setMaximum(9999.989999999999782);

        horizontalLayout_5->addWidget(doubleSpinBox_18);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_8->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_26 = new QLabel(CPD);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        horizontalLayout_9->addWidget(label_26);

        lineEdit_3 = new QLineEdit(CPD);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_9->addWidget(lineEdit_3);

        label_5 = new QLabel(CPD);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_9->addWidget(label_5);

        lineEdit_5 = new QLineEdit(CPD);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        horizontalLayout_9->addWidget(lineEdit_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        pushButton_2 = new QPushButton(CPD);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_10->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(CPD);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_10->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout_10);


        retranslateUi(CPD);
        QObject::connect(pushButton, SIGNAL(clicked()), CPD, SLOT(close()));

        QMetaObject::connectSlotsByName(CPD);
    } // setupUi

    void retranslateUi(QDialog *CPD)
    {
        CPD->setWindowTitle(QCoreApplication::translate("CPD", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("CPD", "Files:", nullptr));
        label_2->setText(QCoreApplication::translate("CPD", "from", nullptr));
        label_3->setText(QCoreApplication::translate("CPD", "to", nullptr));
        label_4->setText(QCoreApplication::translate("CPD", "*", nullptr));
        label_27->setText(QCoreApplication::translate("CPD", "RV-File", nullptr));
        label_12->setText(QCoreApplication::translate("CPD", "Primary", nullptr));
        checkBox->setText(QCoreApplication::translate("CPD", "Window 1 from", nullptr));
        label_6->setText(QCoreApplication::translate("CPD", "to", nullptr));
        label_20->setText(QCoreApplication::translate("CPD", "Value", nullptr));
        checkBox_2->setText(QCoreApplication::translate("CPD", "Window 2 from", nullptr));
        label_8->setText(QCoreApplication::translate("CPD", "to", nullptr));
        label_21->setText(QCoreApplication::translate("CPD", "Value", nullptr));
        checkBox_3->setText(QCoreApplication::translate("CPD", "Window 3 from", nullptr));
        label_10->setText(QCoreApplication::translate("CPD", "to", nullptr));
        label_22->setText(QCoreApplication::translate("CPD", "Value", nullptr));
        label_13->setText(QCoreApplication::translate("CPD", "Secondary", nullptr));
        label_14->setText(QCoreApplication::translate("CPD", "from", nullptr));
        label_17->setText(QCoreApplication::translate("CPD", "to", nullptr));
        label_23->setText(QCoreApplication::translate("CPD", "Value", nullptr));
        label_15->setText(QCoreApplication::translate("CPD", "from", nullptr));
        label_18->setText(QCoreApplication::translate("CPD", "to", nullptr));
        label_24->setText(QCoreApplication::translate("CPD", "Value", nullptr));
        label_16->setText(QCoreApplication::translate("CPD", "from", nullptr));
        label_19->setText(QCoreApplication::translate("CPD", "to", nullptr));
        label_25->setText(QCoreApplication::translate("CPD", "Value", nullptr));
        label_26->setText(QCoreApplication::translate("CPD", "Output", nullptr));
        label_5->setText(QCoreApplication::translate("CPD", "Work Path", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CPD", "Go", nullptr));
        pushButton->setText(QCoreApplication::translate("CPD", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CPD: public Ui_CPD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPD_H
