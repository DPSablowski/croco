/********************************************************************************
** Form generated from reading UI file 'mapplot.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPPLOT_H
#define UI_MAPPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
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

class Ui_MapPlot
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QCustomPlot *customPlot;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QSpinBox *spinBox;
    QLabel *label_3;
    QSpinBox *spinBox_2;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLabel *label_5;
    QSpinBox *spinBox_3;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *MapPlot)
    {
        if (MapPlot->objectName().isEmpty())
            MapPlot->setObjectName(QStringLiteral("MapPlot"));
        MapPlot->resize(673, 516);
        QFont font;
        font.setPointSize(9);
        MapPlot->setFont(font);
        gridLayout = new QGridLayout(MapPlot);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        customPlot = new QCustomPlot(MapPlot);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(customPlot);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(MapPlot);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(MapPlot);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(lineEdit);

        label_2 = new QLabel(MapPlot);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        spinBox = new QSpinBox(MapPlot);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        sizePolicy1.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(spinBox);

        label_3 = new QLabel(MapPlot);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        spinBox_2 = new QSpinBox(MapPlot);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        sizePolicy1.setHeightForWidth(spinBox_2->sizePolicy().hasHeightForWidth());
        spinBox_2->setSizePolicy(sizePolicy1);
        spinBox_2->setMaximum(999);

        horizontalLayout->addWidget(spinBox_2);

        pushButton_2 = new QPushButton(MapPlot);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_2);

        label_4 = new QLabel(MapPlot);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        lineEdit_2 = new QLineEdit(MapPlot);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(lineEdit_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_3 = new QPushButton(MapPlot);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(pushButton_3);

        lineEdit_3 = new QLineEdit(MapPlot);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        sizePolicy1.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(lineEdit_3);

        checkBox = new QCheckBox(MapPlot);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_3->addWidget(checkBox);

        checkBox_2 = new QCheckBox(MapPlot);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        horizontalLayout_3->addWidget(checkBox_2);

        label_5 = new QLabel(MapPlot);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        spinBox_3 = new QSpinBox(MapPlot);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        sizePolicy1.setHeightForWidth(spinBox_3->sizePolicy().hasHeightForWidth());
        spinBox_3->setSizePolicy(sizePolicy1);
        spinBox_3->setValue(9);

        horizontalLayout_3->addWidget(spinBox_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton = new QPushButton(MapPlot);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(MapPlot);
        QObject::connect(pushButton, SIGNAL(clicked()), MapPlot, SLOT(close()));

        QMetaObject::connectSlotsByName(MapPlot);
    } // setupUi

    void retranslateUi(QDialog *MapPlot)
    {
        MapPlot->setWindowTitle(QApplication::translate("MapPlot", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("MapPlot", "File", Q_NULLPTR));
        label_2->setText(QApplication::translate("MapPlot", "from", Q_NULLPTR));
        label_3->setText(QApplication::translate("MapPlot", "to", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MapPlot", "Show", Q_NULLPTR));
        label_4->setText(QApplication::translate("MapPlot", "Work Path:", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MapPlot", "Save As", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MapPlot", "pdf", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("MapPlot", "png", Q_NULLPTR));
        label_5->setText(QApplication::translate("MapPlot", "Font Size:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MapPlot", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MapPlot: public Ui_MapPlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPPLOT_H
