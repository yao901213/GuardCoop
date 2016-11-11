/********************************************************************************
** Form generated from reading UI file 'GuardPositionDiag.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUARDPOSITIONDIAG_H
#define UI_GUARDPOSITIONDIAG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogGuardPosition
{
public:
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;
    QLabel *label_5;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditName;
    QLabel *label_2;
    QLineEdit *lineEditAddress;
    QLabel *label_3;
    QLineEdit *lineEditLongtitude;
    QLabel *label_4;
    QLineEdit *lineEditLatitude;

    void setupUi(QDialog *DialogGuardPosition)
    {
        if (DialogGuardPosition->objectName().isEmpty())
            DialogGuardPosition->setObjectName(QStringLiteral("DialogGuardPosition"));
        DialogGuardPosition->resize(315, 358);
        pushButtonOk = new QPushButton(DialogGuardPosition);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(70, 290, 75, 23));
        pushButtonCancel = new QPushButton(DialogGuardPosition);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(170, 290, 75, 23));
        label_5 = new QLabel(DialogGuardPosition);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 250, 251, 16));
        label_5->setStyleSheet(QLatin1String("\n"
"color: rgb(80,80, 80,);"));
        widget = new QWidget(DialogGuardPosition);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 40, 211, 201));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(20);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditName = new QLineEdit(widget);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));

        gridLayout->addWidget(lineEditName, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEditAddress = new QLineEdit(widget);
        lineEditAddress->setObjectName(QStringLiteral("lineEditAddress"));

        gridLayout->addWidget(lineEditAddress, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEditLongtitude = new QLineEdit(widget);
        lineEditLongtitude->setObjectName(QStringLiteral("lineEditLongtitude"));

        gridLayout->addWidget(lineEditLongtitude, 2, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEditLatitude = new QLineEdit(widget);
        lineEditLatitude->setObjectName(QStringLiteral("lineEditLatitude"));

        gridLayout->addWidget(lineEditLatitude, 3, 1, 1, 1);


        retranslateUi(DialogGuardPosition);
        QObject::connect(pushButtonOk, SIGNAL(clicked()), DialogGuardPosition, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogGuardPosition);
    } // setupUi

    void retranslateUi(QDialog *DialogGuardPosition)
    {
        DialogGuardPosition->setWindowTitle(QApplication::translate("DialogGuardPosition", "\350\257\267\350\276\223\345\205\245\345\262\227\347\202\271\344\277\241\346\201\257", 0));
        pushButtonOk->setText(QApplication::translate("DialogGuardPosition", "\347\241\256\345\256\232", 0));
        pushButtonCancel->setText(QApplication::translate("DialogGuardPosition", "\345\217\226\346\266\210", 0));
        label_5->setText(QApplication::translate("DialogGuardPosition", "\344\270\272\344\277\235\350\257\201\347\262\276\347\241\256\346\230\276\347\244\272\357\274\214\347\273\217\347\272\254\345\272\246\350\257\267\344\277\235\347\225\231\345\260\217\346\225\260\347\202\271\345\220\2166\344\275\215", 0));
        label->setText(QApplication::translate("DialogGuardPosition", "\345\220\215\347\247\260", 0));
        label_2->setText(QApplication::translate("DialogGuardPosition", "\345\234\260\345\235\200", 0));
        label_3->setText(QApplication::translate("DialogGuardPosition", "\347\273\217\345\272\246", 0));
        label_4->setText(QApplication::translate("DialogGuardPosition", "\347\273\264\345\272\246", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogGuardPosition: public Ui_DialogGuardPosition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUARDPOSITIONDIAG_H
