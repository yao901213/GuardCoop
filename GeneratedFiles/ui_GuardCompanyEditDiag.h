/********************************************************************************
** Form generated from reading UI file 'GuardCompanyEditDiag.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUARDCOMPANYEDITDIAG_H
#define UI_GUARDCOMPANYEDITDIAG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogEditGuardCompany
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;
    QLineEdit *lineEditName;
    QLineEdit *lineEditAddress;
    QLineEdit *lineEditContacts;
    QLineEdit *lineEditPhone;

    void setupUi(QDialog *DialogEditGuardCompany)
    {
        if (DialogEditGuardCompany->objectName().isEmpty())
            DialogEditGuardCompany->setObjectName(QStringLiteral("DialogEditGuardCompany"));
        DialogEditGuardCompany->resize(357, 387);
        label = new QLabel(DialogEditGuardCompany);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 70, 70, 16));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(DialogEditGuardCompany);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 120, 70, 16));
        label_2->setFont(font);
        label_3 = new QLabel(DialogEditGuardCompany);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 170, 70, 16));
        label_3->setFont(font);
        label_4 = new QLabel(DialogEditGuardCompany);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 230, 70, 16));
        label_4->setFont(font);
        pushButtonOk = new QPushButton(DialogEditGuardCompany);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(70, 300, 75, 23));
        pushButtonCancel = new QPushButton(DialogEditGuardCompany);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(190, 300, 75, 23));
        lineEditName = new QLineEdit(DialogEditGuardCompany);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setGeometry(QRect(130, 70, 151, 20));
        lineEditAddress = new QLineEdit(DialogEditGuardCompany);
        lineEditAddress->setObjectName(QStringLiteral("lineEditAddress"));
        lineEditAddress->setGeometry(QRect(130, 120, 151, 20));
        lineEditContacts = new QLineEdit(DialogEditGuardCompany);
        lineEditContacts->setObjectName(QStringLiteral("lineEditContacts"));
        lineEditContacts->setGeometry(QRect(130, 170, 151, 20));
        lineEditPhone = new QLineEdit(DialogEditGuardCompany);
        lineEditPhone->setObjectName(QStringLiteral("lineEditPhone"));
        lineEditPhone->setGeometry(QRect(130, 230, 151, 20));

        retranslateUi(DialogEditGuardCompany);
        QObject::connect(pushButtonCancel, SIGNAL(clicked()), DialogEditGuardCompany, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogEditGuardCompany);
    } // setupUi

    void retranslateUi(QDialog *DialogEditGuardCompany)
    {
        DialogEditGuardCompany->setWindowTitle(QApplication::translate("DialogEditGuardCompany", "\350\276\223\345\205\245\345\205\254\345\217\270\344\277\241\346\201\257", 0));
        label->setText(QApplication::translate("DialogEditGuardCompany", "\345\205\254\345\217\270\345\220\215\347\247\260", 0));
        label_2->setText(QApplication::translate("DialogEditGuardCompany", "\345\234\260    \345\235\200", 0));
        label_3->setText(QApplication::translate("DialogEditGuardCompany", "\350\201\224 \347\263\273 \344\272\272", 0));
        label_4->setText(QApplication::translate("DialogEditGuardCompany", "\350\201\224\347\263\273\347\224\265\350\257\235", 0));
        pushButtonOk->setText(QApplication::translate("DialogEditGuardCompany", "\347\241\256\345\256\232", 0));
        pushButtonCancel->setText(QApplication::translate("DialogEditGuardCompany", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogEditGuardCompany: public Ui_DialogEditGuardCompany {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUARDCOMPANYEDITDIAG_H
