/********************************************************************************
** Form generated from reading UI file 'crop.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CROP_H
#define UI_CROP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Crop
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QSpinBox *spinBox;
    QLabel *label_3;
    QSpinBox *spinBox_2;
    QLabel *label_13;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QLineEdit *lineEdit_5;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_2;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_2;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_3;
    QSpinBox *spinBox_3;
    QLabel *label_11;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QLineEdit *lineEdit_6;
    QLabel *label_12;
    QLineEdit *lineEdit_8;
    QLabel *label_10;
    QLineEdit *lineEdit_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *Crop)
    {
        if (Crop->objectName().isEmpty())
            Crop->setObjectName(QStringLiteral("Crop"));
        Crop->resize(995, 346);
        verticalLayout = new QVBoxLayout(Crop);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Crop);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(Crop);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit);

        label_2 = new QLabel(Crop);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        spinBox = new QSpinBox(Crop);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(999);

        horizontalLayout->addWidget(spinBox);

        label_3 = new QLabel(Crop);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        spinBox_2 = new QSpinBox(Crop);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximum(9999);

        horizontalLayout->addWidget(spinBox_2);

        label_13 = new QLabel(Crop);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout->addWidget(label_13);

        lineEdit_2 = new QLineEdit(Crop);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        comboBox = new QComboBox(Crop);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        label_5 = new QLabel(Crop);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        lineEdit_4 = new QLineEdit(Crop);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        sizePolicy.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit_4);

        label_4 = new QLabel(Crop);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        lineEdit_3 = new QLineEdit(Crop);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit_3);

        label_6 = new QLabel(Crop);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_2->addWidget(label_6);

        lineEdit_5 = new QLineEdit(Crop);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        sizePolicy.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit_5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_2 = new QPushButton(Crop);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);

        label_7 = new QLabel(Crop);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_3->addWidget(label_7);

        doubleSpinBox = new QDoubleSpinBox(Crop);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setDecimals(5);
        doubleSpinBox->setMaximum(9999.99);

        horizontalLayout_3->addWidget(doubleSpinBox);

        label_8 = new QLabel(Crop);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_3->addWidget(label_8);

        doubleSpinBox_2 = new QDoubleSpinBox(Crop);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setDecimals(5);
        doubleSpinBox_2->setMaximum(9999.99);

        horizontalLayout_3->addWidget(doubleSpinBox_2);

        pushButton_4 = new QPushButton(Crop);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(pushButton_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_3 = new QPushButton(Crop);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_5->addWidget(pushButton_3);

        spinBox_3 = new QSpinBox(Crop);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setMinimum(2);

        horizontalLayout_5->addWidget(spinBox_3);

        label_11 = new QLabel(Crop);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_5->addWidget(label_11);

        checkBox = new QCheckBox(Crop);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_5->addWidget(checkBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_9 = new QLabel(Crop);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_4->addWidget(label_9);

        lineEdit_6 = new QLineEdit(Crop);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        sizePolicy.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(lineEdit_6);

        label_12 = new QLabel(Crop);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_4->addWidget(label_12);

        lineEdit_8 = new QLineEdit(Crop);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        sizePolicy1.setHeightForWidth(lineEdit_8->sizePolicy().hasHeightForWidth());
        lineEdit_8->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(lineEdit_8);

        label_10 = new QLabel(Crop);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_4->addWidget(label_10);

        lineEdit_7 = new QLineEdit(Crop);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        sizePolicy.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(lineEdit_7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_4);

        pushButton = new QPushButton(Crop);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pushButton);


        retranslateUi(Crop);
        QObject::connect(pushButton, SIGNAL(clicked()), Crop, SLOT(close()));

        QMetaObject::connectSlotsByName(Crop);
    } // setupUi

    void retranslateUi(QDialog *Crop)
    {
        Crop->setWindowTitle(QApplication::translate("Crop", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Crop", "Input Spectra", Q_NULLPTR));
        label_2->setText(QApplication::translate("Crop", "from", Q_NULLPTR));
        label_3->setText(QApplication::translate("Crop", "to", Q_NULLPTR));
        label_13->setText(QApplication::translate("Crop", ".", Q_NULLPTR));
        label_5->setText(QApplication::translate("Crop", "Extension", Q_NULLPTR));
        label_4->setText(QApplication::translate("Crop", "W.Col.", Q_NULLPTR));
        label_6->setText(QApplication::translate("Crop", "I.Col.", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Crop", "Crop", Q_NULLPTR));
        label_7->setText(QApplication::translate("Crop", "from", Q_NULLPTR));
        label_8->setText(QApplication::translate("Crop", "to", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Crop", "Abort", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Crop", "Bin", Q_NULLPTR));
        label_11->setText(QApplication::translate("Crop", "X", Q_NULLPTR));
        checkBox->setText(QApplication::translate("Crop", "and crop", Q_NULLPTR));
        label_9->setText(QApplication::translate("Crop", "Output", Q_NULLPTR));
        label_12->setText(QApplication::translate("Crop", "*.", Q_NULLPTR));
        label_10->setText(QApplication::translate("Crop", "Work Path:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Crop", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Crop: public Ui_Crop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CROP_H
