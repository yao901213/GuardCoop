/********************************************************************************
** Form generated from reading UI file 'RegisterDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QLabel *label;
    QGroupBox *groupBox;
    QLineEdit *AccountLineEdit;
    QLineEdit *PasswordLineEdit;
    QLineEdit *CommitPasswordLineEdit;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *OKButtton;
    QPushButton *CancelButton;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName(QStringLiteral("RegisterDialog"));
        RegisterDialog->resize(495, 504);
        label = new QLabel(RegisterDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 70, 323, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(20);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(RegisterDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(110, 110, 281, 241));
        AccountLineEdit = new QLineEdit(groupBox);
        AccountLineEdit->setObjectName(QStringLiteral("AccountLineEdit"));
        AccountLineEdit->setGeometry(QRect(110, 30, 151, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(12);
        AccountLineEdit->setFont(font1);
        PasswordLineEdit = new QLineEdit(groupBox);
        PasswordLineEdit->setObjectName(QStringLiteral("PasswordLineEdit"));
        PasswordLineEdit->setGeometry(QRect(110, 90, 151, 31));
        PasswordLineEdit->setFont(font1);
        PasswordLineEdit->setEchoMode(QLineEdit::Password);
        CommitPasswordLineEdit = new QLineEdit(groupBox);
        CommitPasswordLineEdit->setObjectName(QStringLiteral("CommitPasswordLineEdit"));
        CommitPasswordLineEdit->setGeometry(QRect(110, 150, 151, 31));
        CommitPasswordLineEdit->setFont(font1);
        CommitPasswordLineEdit->setEchoMode(QLineEdit::Password);
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 30, 66, 142));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(40);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        verticalLayout->addWidget(label_4);

        widget1 = new QWidget(RegisterDialog);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(150, 400, 212, 30));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setSpacing(60);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        OKButtton = new QPushButton(widget1);
        OKButtton->setObjectName(QStringLiteral("OKButtton"));
        OKButtton->setFont(font1);

        horizontalLayout->addWidget(OKButtton);

        CancelButton = new QPushButton(widget1);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));
        CancelButton->setFont(font1);

        horizontalLayout->addWidget(CancelButton);


        retranslateUi(RegisterDialog);
        QObject::connect(CancelButton, SIGNAL(clicked()), RegisterDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QApplication::translate("RegisterDialog", "\346\263\250\345\206\214", 0));
        label->setText(QApplication::translate("RegisterDialog", "\347\224\250\346\210\267\346\263\250\345\206\214", 0));
        groupBox->setTitle(QString());
        AccountLineEdit->setPlaceholderText(QApplication::translate("RegisterDialog", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", 0));
        PasswordLineEdit->setPlaceholderText(QApplication::translate("RegisterDialog", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0));
        CommitPasswordLineEdit->setPlaceholderText(QApplication::translate("RegisterDialog", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", 0));
        label_2->setText(QApplication::translate("RegisterDialog", "\347\224\250 \346\210\267 \345\220\215", 0));
        label_3->setText(QApplication::translate("RegisterDialog", "\345\257\206    \347\240\201", 0));
        label_4->setText(QApplication::translate("RegisterDialog", "\347\241\256\350\256\244\345\257\206\347\240\201", 0));
        OKButtton->setText(QApplication::translate("RegisterDialog", "\347\241\256\350\256\244", 0));
        CancelButton->setText(QApplication::translate("RegisterDialog", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
