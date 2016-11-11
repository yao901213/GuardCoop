/********************************************************************************
** Form generated from reading UI file 'AddPhoneBookDiag.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPHONEBOOKDIAG_H
#define UI_ADDPHONEBOOKDIAG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogAddPhoneBook
{
public:
    QPushButton *pushButtonOk;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEditName;
    QLineEdit *lineEditPhone;
    QLineEdit *lineEditEmail;
    QLineEdit *lineEditAddress;
    QWidget *widget2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *DialogAddPhoneBook)
    {
        if (DialogAddPhoneBook->objectName().isEmpty())
            DialogAddPhoneBook->setObjectName(QStringLiteral("DialogAddPhoneBook"));
        DialogAddPhoneBook->resize(316, 394);
        pushButtonOk = new QPushButton(DialogAddPhoneBook);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(110, 310, 75, 23));
        widget = new QWidget(DialogAddPhoneBook);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(270, 80, 8, 56));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(30);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_5->setPalette(palette);

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush2(QColor(255, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(255, 63, 63, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(127, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush5);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush6);
        QBrush brush7(QColor(255, 255, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush7);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        label_6->setPalette(palette1);

        verticalLayout_3->addWidget(label_6);

        widget1 = new QWidget(DialogAddPhoneBook);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(120, 70, 135, 171));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEditName = new QLineEdit(widget1);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));

        verticalLayout_2->addWidget(lineEditName);

        lineEditPhone = new QLineEdit(widget1);
        lineEditPhone->setObjectName(QStringLiteral("lineEditPhone"));

        verticalLayout_2->addWidget(lineEditPhone);

        lineEditEmail = new QLineEdit(widget1);
        lineEditEmail->setObjectName(QStringLiteral("lineEditEmail"));

        verticalLayout_2->addWidget(lineEditEmail);

        lineEditAddress = new QLineEdit(widget1);
        lineEditAddress->setObjectName(QStringLiteral("lineEditAddress"));

        verticalLayout_2->addWidget(lineEditAddress);

        widget2 = new QWidget(DialogAddPhoneBook);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(31, 71, 75, 168));
        verticalLayout = new QVBoxLayout(widget2);
        verticalLayout->setSpacing(30);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(10, 0, 0, 0);
        label = new QLabel(widget2);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(widget2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);


        retranslateUi(DialogAddPhoneBook);

        QMetaObject::connectSlotsByName(DialogAddPhoneBook);
    } // setupUi

    void retranslateUi(QDialog *DialogAddPhoneBook)
    {
        DialogAddPhoneBook->setWindowTitle(QApplication::translate("DialogAddPhoneBook", "\346\267\273\345\212\240\346\226\260\350\201\224\347\263\273\344\272\272", 0));
        pushButtonOk->setText(QApplication::translate("DialogAddPhoneBook", "\347\241\256\345\256\232", 0));
        label_5->setText(QApplication::translate("DialogAddPhoneBook", "*", 0));
        label_6->setText(QApplication::translate("DialogAddPhoneBook", "*", 0));
        label->setText(QApplication::translate("DialogAddPhoneBook", "\345\247\223\345\220\215", 0));
        label_2->setText(QApplication::translate("DialogAddPhoneBook", "\350\201\224\347\263\273\346\226\271\345\274\217", 0));
        label_3->setText(QApplication::translate("DialogAddPhoneBook", "Email", 0));
        label_4->setText(QApplication::translate("DialogAddPhoneBook", "\344\275\217\345\235\200", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogAddPhoneBook: public Ui_DialogAddPhoneBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPHONEBOOKDIAG_H
