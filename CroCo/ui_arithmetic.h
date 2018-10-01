/********************************************************************************
** Form generated from reading UI file 'arithmetic.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARITHMETIC_H
#define UI_ARITHMETIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Arithmetic
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_10;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QLineEdit *lineEdit_5;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_11;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox_7;
    QSpinBox *spinBox;
    QLabel *label_7;
    QSpinBox *spinBox_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_6;
    QFrame *line;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QLineEdit *lineEdit_7;
    QLabel *label_10;
    QLineEdit *lineEdit_8;
    QLabel *label_11;
    QLineEdit *lineEdit_9;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_3;
    QCheckBox *checkBox_12;
    QCheckBox *checkBox_13;
    QCheckBox *checkBox_15;
    QCheckBox *checkBox_14;
    QLineEdit *lineEdit_10;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_13;
    QLineEdit *lineEdit_12;
    QLabel *label_14;
    QLineEdit *lineEdit_13;
    QLabel *label_12;
    QLineEdit *lineEdit_11;
    QSpacerItem *horizontalSpacer_9;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_4;
    QLabel *label_15;
    QLineEdit *lineEdit_14;
    QLabel *label_16;
    QLineEdit *lineEdit_15;
    QLabel *label_17;
    QSpinBox *spinBox_3;
    QSpacerItem *horizontalSpacer_10;
    QFrame *line_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QDialog *Arithmetic)
    {
        if (Arithmetic->objectName().isEmpty())
            Arithmetic->setObjectName(QStringLiteral("Arithmetic"));
        Arithmetic->resize(932, 540);
        verticalLayout = new QVBoxLayout(Arithmetic);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Arithmetic);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(Arithmetic);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit);

        label_6 = new QLabel(Arithmetic);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout->addWidget(label_6);

        lineEdit_6 = new QLineEdit(Arithmetic);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        horizontalLayout->addWidget(lineEdit_6);

        checkBox = new QCheckBox(Arithmetic);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout->addWidget(checkBox);

        checkBox_2 = new QCheckBox(Arithmetic);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        horizontalLayout->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(Arithmetic);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        horizontalLayout->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(Arithmetic);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        horizontalLayout->addWidget(checkBox_4);

        checkBox_10 = new QCheckBox(Arithmetic);
        checkBox_10->setObjectName(QStringLiteral("checkBox_10"));

        horizontalLayout->addWidget(checkBox_10);

        doubleSpinBox = new QDoubleSpinBox(Arithmetic);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setDecimals(4);
        doubleSpinBox->setMinimum(-999.99);
        doubleSpinBox->setMaximum(999.99);

        horizontalLayout->addWidget(doubleSpinBox);

        label_5 = new QLabel(Arithmetic);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(Arithmetic);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(Arithmetic);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit_2);

        checkBox_5 = new QCheckBox(Arithmetic);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));

        horizontalLayout_2->addWidget(checkBox_5);

        checkBox_6 = new QCheckBox(Arithmetic);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));

        horizontalLayout_2->addWidget(checkBox_6);

        lineEdit_5 = new QLineEdit(Arithmetic);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        sizePolicy.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit_5);

        checkBox_8 = new QCheckBox(Arithmetic);
        checkBox_8->setObjectName(QStringLiteral("checkBox_8"));

        horizontalLayout_2->addWidget(checkBox_8);

        checkBox_9 = new QCheckBox(Arithmetic);
        checkBox_9->setObjectName(QStringLiteral("checkBox_9"));

        horizontalLayout_2->addWidget(checkBox_9);

        checkBox_11 = new QCheckBox(Arithmetic);
        checkBox_11->setObjectName(QStringLiteral("checkBox_11"));

        horizontalLayout_2->addWidget(checkBox_11);

        doubleSpinBox_2 = new QDoubleSpinBox(Arithmetic);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setDecimals(4);
        doubleSpinBox_2->setMinimum(-999.99);
        doubleSpinBox_2->setMaximum(999.99);

        horizontalLayout_2->addWidget(doubleSpinBox_2);

        label_8 = new QLabel(Arithmetic);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_2->addWidget(label_8);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        checkBox_7 = new QCheckBox(Arithmetic);
        checkBox_7->setObjectName(QStringLiteral("checkBox_7"));

        horizontalLayout_4->addWidget(checkBox_7);

        spinBox = new QSpinBox(Arithmetic);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout_4->addWidget(spinBox);

        label_7 = new QLabel(Arithmetic);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_4->addWidget(label_7);

        spinBox_2 = new QSpinBox(Arithmetic);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));

        horizontalLayout_4->addWidget(spinBox_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(Arithmetic);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        lineEdit_3 = new QLineEdit(Arithmetic);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(lineEdit_3);

        label_3 = new QLabel(Arithmetic);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_4 = new QLineEdit(Arithmetic);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        sizePolicy.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(lineEdit_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pushButton_2 = new QPushButton(Arithmetic);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(pushButton_2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_6);

        line = new QFrame(Arithmetic);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_9 = new QLabel(Arithmetic);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_7->addWidget(label_9);

        lineEdit_7 = new QLineEdit(Arithmetic);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        sizePolicy.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(lineEdit_7);

        label_10 = new QLabel(Arithmetic);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_7->addWidget(label_10);

        lineEdit_8 = new QLineEdit(Arithmetic);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        sizePolicy.setHeightForWidth(lineEdit_8->sizePolicy().hasHeightForWidth());
        lineEdit_8->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(lineEdit_8);

        label_11 = new QLabel(Arithmetic);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_7->addWidget(label_11);

        lineEdit_9 = new QLineEdit(Arithmetic);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        sizePolicy.setHeightForWidth(lineEdit_9->sizePolicy().hasHeightForWidth());
        lineEdit_9->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(lineEdit_9);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        pushButton_3 = new QPushButton(Arithmetic);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(pushButton_3);

        checkBox_12 = new QCheckBox(Arithmetic);
        checkBox_12->setObjectName(QStringLiteral("checkBox_12"));

        horizontalLayout_8->addWidget(checkBox_12);

        checkBox_13 = new QCheckBox(Arithmetic);
        checkBox_13->setObjectName(QStringLiteral("checkBox_13"));

        horizontalLayout_8->addWidget(checkBox_13);

        checkBox_15 = new QCheckBox(Arithmetic);
        checkBox_15->setObjectName(QStringLiteral("checkBox_15"));

        horizontalLayout_8->addWidget(checkBox_15);

        checkBox_14 = new QCheckBox(Arithmetic);
        checkBox_14->setObjectName(QStringLiteral("checkBox_14"));

        horizontalLayout_8->addWidget(checkBox_14);

        lineEdit_10 = new QLineEdit(Arithmetic);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        sizePolicy.setHeightForWidth(lineEdit_10->sizePolicy().hasHeightForWidth());
        lineEdit_10->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(lineEdit_10);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_13 = new QLabel(Arithmetic);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_9->addWidget(label_13);

        lineEdit_12 = new QLineEdit(Arithmetic);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        sizePolicy.setHeightForWidth(lineEdit_12->sizePolicy().hasHeightForWidth());
        lineEdit_12->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(lineEdit_12);

        label_14 = new QLabel(Arithmetic);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_9->addWidget(label_14);

        lineEdit_13 = new QLineEdit(Arithmetic);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));
        sizePolicy.setHeightForWidth(lineEdit_13->sizePolicy().hasHeightForWidth());
        lineEdit_13->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(lineEdit_13);

        label_12 = new QLabel(Arithmetic);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_9->addWidget(label_12);

        lineEdit_11 = new QLineEdit(Arithmetic);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        sizePolicy.setHeightForWidth(lineEdit_11->sizePolicy().hasHeightForWidth());
        lineEdit_11->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(lineEdit_11);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);


        verticalLayout->addLayout(horizontalLayout_9);

        line_2 = new QFrame(Arithmetic);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        pushButton_4 = new QPushButton(Arithmetic);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(pushButton_4);

        label_15 = new QLabel(Arithmetic);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_10->addWidget(label_15);

        lineEdit_14 = new QLineEdit(Arithmetic);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));
        sizePolicy.setHeightForWidth(lineEdit_14->sizePolicy().hasHeightForWidth());
        lineEdit_14->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(lineEdit_14);

        label_16 = new QLabel(Arithmetic);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_10->addWidget(label_16);

        lineEdit_15 = new QLineEdit(Arithmetic);
        lineEdit_15->setObjectName(QStringLiteral("lineEdit_15"));
        sizePolicy.setHeightForWidth(lineEdit_15->sizePolicy().hasHeightForWidth());
        lineEdit_15->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(lineEdit_15);

        label_17 = new QLabel(Arithmetic);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_10->addWidget(label_17);

        spinBox_3 = new QSpinBox(Arithmetic);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));

        horizontalLayout_10->addWidget(spinBox_3);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_10);

        line_3 = new QFrame(Arithmetic);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton = new QPushButton(Arithmetic);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(pushButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(Arithmetic);
        QObject::connect(pushButton, SIGNAL(clicked()), Arithmetic, SLOT(close()));

        QMetaObject::connectSlotsByName(Arithmetic);
    } // setupUi

    void retranslateUi(QDialog *Arithmetic)
    {
        Arithmetic->setWindowTitle(QApplication::translate("Arithmetic", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Arithmetic", "A:", Q_NULLPTR));
        label_6->setText(QApplication::translate("Arithmetic", "*", Q_NULLPTR));
        checkBox->setText(QApplication::translate("Arithmetic", "A+B", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("Arithmetic", "A-B", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("Arithmetic", "A*B", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("Arithmetic", "A/B", Q_NULLPTR));
        checkBox_10->setText(QApplication::translate("Arithmetic", "Shift A by", Q_NULLPTR));
        label_5->setText(QApplication::translate("Arithmetic", "km/s", Q_NULLPTR));
        label_2->setText(QApplication::translate("Arithmetic", "B:", Q_NULLPTR));
        checkBox_5->setText(QApplication::translate("Arithmetic", "A+", Q_NULLPTR));
        checkBox_6->setText(QApplication::translate("Arithmetic", "A*", Q_NULLPTR));
        checkBox_8->setText(QApplication::translate("Arithmetic", "log10(x)", Q_NULLPTR));
        checkBox_9->setText(QApplication::translate("Arithmetic", "10^x", Q_NULLPTR));
        checkBox_11->setText(QApplication::translate("Arithmetic", "Shift B by", Q_NULLPTR));
        label_8->setText(QApplication::translate("Arithmetic", "km/s", Q_NULLPTR));
        checkBox_7->setText(QApplication::translate("Arithmetic", "Sequence from", Q_NULLPTR));
        label_7->setText(QApplication::translate("Arithmetic", "to", Q_NULLPTR));
        label_4->setText(QApplication::translate("Arithmetic", "Out:", Q_NULLPTR));
        label_3->setText(QApplication::translate("Arithmetic", "Work Path:", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Arithmetic", "Do", Q_NULLPTR));
        label_9->setText(QApplication::translate("Arithmetic", "L_0", Q_NULLPTR));
        label_10->setText(QApplication::translate("Arithmetic", "L_A", Q_NULLPTR));
        label_11->setText(QApplication::translate("Arithmetic", "L_B", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Arithmetic", "Shift", Q_NULLPTR));
        checkBox_12->setText(QApplication::translate("Arithmetic", "A", Q_NULLPTR));
        checkBox_13->setText(QApplication::translate("Arithmetic", "B", Q_NULLPTR));
        checkBox_15->setText(QApplication::translate("Arithmetic", "-1*Shift", Q_NULLPTR));
        checkBox_14->setText(QApplication::translate("Arithmetic", "Correct Velocities; In:", Q_NULLPTR));
        label_13->setText(QApplication::translate("Arithmetic", "Out A:", Q_NULLPTR));
        label_14->setText(QApplication::translate("Arithmetic", "Out B:", Q_NULLPTR));
        label_12->setText(QApplication::translate("Arithmetic", "Out Vel:", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Arithmetic", "Normalize", Q_NULLPTR));
        label_15->setText(QApplication::translate("Arithmetic", "x1:", Q_NULLPTR));
        label_16->setText(QApplication::translate("Arithmetic", "x2:", Q_NULLPTR));
        label_17->setText(QApplication::translate("Arithmetic", "Range +/- Pixel:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Arithmetic", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Arithmetic: public Ui_Arithmetic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARITHMETIC_H
