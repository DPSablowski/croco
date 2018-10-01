/********************************************************************************
** Form generated from reading UI file 'moments.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOMENTS_H
#define UI_MOMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
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

class Ui_Moments
{
public:
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpinBox *spinBox;
    QPushButton *pushButton_2;
    QFrame *line;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_5;
    QCheckBox *checkBox;
    QSpinBox *spinBox_4;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_6;
    QLabel *label_6;
    QSpinBox *spinBox_2;
    QLabel *label_7;
    QSpinBox *spinBox_3;
    QLabel *label_8;
    QLineEdit *lineEdit_7;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QTableWidget *tableWidget;

    void setupUi(QDialog *Moments)
    {
        if (Moments->objectName().isEmpty())
            Moments->setObjectName(QStringLiteral("Moments"));
        Moments->resize(917, 516);
        horizontalLayout_9 = new QHBoxLayout(Moments);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Moments);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(Moments);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(Moments);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(Moments);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(Moments);
        label_5->setObjectName(QStringLiteral("label_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(label_5);

        lineEdit_4 = new QLineEdit(Moments);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        sizePolicy.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(Moments);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_3 = new QLineEdit(Moments);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(Moments);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        spinBox = new QSpinBox(Moments);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout_4->addWidget(spinBox);

        pushButton_2 = new QPushButton(Moments);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_4);

        line = new QFrame(Moments);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButton_3 = new QPushButton(Moments);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(pushButton_3);

        lineEdit_5 = new QLineEdit(Moments);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        sizePolicy.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(lineEdit_5);

        checkBox = new QCheckBox(Moments);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_7->addWidget(checkBox);

        spinBox_4 = new QSpinBox(Moments);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));

        horizontalLayout_7->addWidget(spinBox_4);

        label_9 = new QLabel(Moments);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_7->addWidget(label_9);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        pushButton_4 = new QPushButton(Moments);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_8->addWidget(pushButton_4);

        lineEdit_6 = new QLineEdit(Moments);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        sizePolicy.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(lineEdit_6);

        label_6 = new QLabel(Moments);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_8->addWidget(label_6);

        spinBox_2 = new QSpinBox(Moments);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));

        horizontalLayout_8->addWidget(spinBox_2);

        label_7 = new QLabel(Moments);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_8->addWidget(label_7);

        spinBox_3 = new QSpinBox(Moments);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));

        horizontalLayout_8->addWidget(spinBox_3);

        label_8 = new QLabel(Moments);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_8->addWidget(label_8);

        lineEdit_7 = new QLineEdit(Moments);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        sizePolicy.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy);
        lineEdit_7->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_8->addWidget(lineEdit_7);


        verticalLayout->addLayout(horizontalLayout_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        pushButton = new QPushButton(Moments);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout_9->addLayout(verticalLayout);

        tableWidget = new QTableWidget(Moments);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        horizontalLayout_9->addWidget(tableWidget);


        retranslateUi(Moments);
        QObject::connect(pushButton, SIGNAL(clicked()), Moments, SLOT(close()));

        QMetaObject::connectSlotsByName(Moments);
    } // setupUi

    void retranslateUi(QDialog *Moments)
    {
        Moments->setWindowTitle(QApplication::translate("Moments", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Moments", "Work Path:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Moments", "Moments In:", Q_NULLPTR));
        label_5->setText(QApplication::translate("Moments", "Moments 2 In:", Q_NULLPTR));
        label_3->setText(QApplication::translate("Moments", "Moments Out:", Q_NULLPTR));
        label_4->setText(QApplication::translate("Moments", "# Sets:", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Moments", "Correct", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Moments", "Merge to", Q_NULLPTR));
        checkBox->setText(QApplication::translate("Moments", "ignore first", Q_NULLPTR));
        label_9->setText(QApplication::translate("Moments", "lines", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Moments", "Combine", Q_NULLPTR));
        label_6->setText(QApplication::translate("Moments", "from", Q_NULLPTR));
        label_7->setText(QApplication::translate("Moments", "to", Q_NULLPTR));
        label_8->setText(QApplication::translate("Moments", "*", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Moments", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Moments: public Ui_Moments {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOMENTS_H
