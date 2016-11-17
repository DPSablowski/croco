/********************************************************************************
** Form generated from reading UI file 'rename.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENAME_H
#define UI_RENAME_H

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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Rename
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkBox;
    QSpinBox *spinBox_2;
    QLabel *label_5;
    QSpinBox *spinBox_3;
    QLabel *label_6;
    QSpinBox *spinBox_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Rename)
    {
        if (Rename->objectName().isEmpty())
            Rename->setObjectName(QStringLiteral("Rename"));
        Rename->resize(430, 556);
        gridLayout = new QGridLayout(Rename);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(Rename);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(Rename);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(Rename);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        spinBox = new QSpinBox(Rename);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(9999);

        horizontalLayout_4->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        checkBox = new QCheckBox(Rename);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_5->addWidget(checkBox);

        spinBox_2 = new QSpinBox(Rename);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));

        horizontalLayout_5->addWidget(spinBox_2);

        label_5 = new QLabel(Rename);
        label_5->setObjectName(QStringLiteral("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(label_5);

        spinBox_3 = new QSpinBox(Rename);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));

        horizontalLayout_5->addWidget(spinBox_3);

        label_6 = new QLabel(Rename);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(label_6);

        spinBox_4 = new QSpinBox(Rename);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));

        horizontalLayout_5->addWidget(spinBox_4);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(Rename);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(Rename);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);

        label_3 = new QLabel(Rename);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit_3 = new QLineEdit(Rename);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(Rename);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setColumnCount(2);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setDefaultSectionSize(200);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton = new QPushButton(Rename);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(Rename);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_3 = new QPushButton(Rename);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_3->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Rename);
        QObject::connect(pushButton_3, SIGNAL(clicked()), Rename, SLOT(close()));

        QMetaObject::connectSlotsByName(Rename);
    } // setupUi

    void retranslateUi(QDialog *Rename)
    {
        Rename->setWindowTitle(QApplication::translate("Rename", "Dialog", 0));
        label->setText(QApplication::translate("Rename", "Path to files:", 0));
        label_4->setText(QApplication::translate("Rename", "Number of Files:", 0));
        checkBox->setText(QApplication::translate("Rename", "Reject file", 0));
        label_5->setText(QApplication::translate("Rename", ",", 0));
        label_6->setText(QApplication::translate("Rename", "and", 0));
        label_2->setText(QApplication::translate("Rename", "New Name:", 0));
        label_3->setText(QApplication::translate("Rename", "*", 0));
        pushButton->setText(QApplication::translate("Rename", "List Files", 0));
        pushButton_2->setText(QApplication::translate("Rename", "Rename", 0));
        pushButton_3->setText(QApplication::translate("Rename", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class Rename: public Ui_Rename {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENAME_H
