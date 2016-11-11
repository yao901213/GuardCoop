/********************************************************************************
** Form generated from reading UI file 'Main.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_H
#define UI_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QToolBox *toolBox;
    QWidget *page_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButtonCompany;
    QPushButton *pushButtonInstitution;
    QPushButton *pushButtonRules;
    QPushButton *pushButtonLaw;
    QPushButton *pushButtonPhoneBook;
    QWidget *page_3;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonGuardInfo;
    QPushButton *pushButtonGuardCompanyInfo;
    QPushButton *pushButtonGuardPosition;
    QWidget *page;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButtonPropertyInfo;
    QPushButton *pushButtonPropertyCompany;
    QPushButton *pushButtonPropertyUse;
    QWidget *page_4;
    QWidget *page_5;
    QStackedWidget *stackedWidget;
    QWidget *page_6;
    QWidget *page_7;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(850, 591);
        layoutWidget = new QWidget(Form);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 801, 511));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, -1, -1);
        toolBox = new QToolBox(layoutWidget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(12);
        toolBox->setFont(font);
        toolBox->setCursor(QCursor(Qt::ArrowCursor));
        toolBox->setContextMenuPolicy(Qt::NoContextMenu);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 112, 357));
        layoutWidget1 = new QWidget(page_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 0, 77, 201));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonCompany = new QPushButton(layoutWidget1);
        pushButtonCompany->setObjectName(QStringLiteral("pushButtonCompany"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        pushButtonCompany->setFont(font1);
        pushButtonCompany->setAutoRepeatInterval(100);

        verticalLayout_2->addWidget(pushButtonCompany);

        pushButtonInstitution = new QPushButton(layoutWidget1);
        pushButtonInstitution->setObjectName(QStringLiteral("pushButtonInstitution"));
        pushButtonInstitution->setFont(font1);
        pushButtonInstitution->setAutoRepeatInterval(100);

        verticalLayout_2->addWidget(pushButtonInstitution);

        pushButtonRules = new QPushButton(layoutWidget1);
        pushButtonRules->setObjectName(QStringLiteral("pushButtonRules"));
        pushButtonRules->setFont(font1);
        pushButtonRules->setAutoRepeatInterval(100);

        verticalLayout_2->addWidget(pushButtonRules);

        pushButtonLaw = new QPushButton(layoutWidget1);
        pushButtonLaw->setObjectName(QStringLiteral("pushButtonLaw"));
        pushButtonLaw->setFont(font1);
        pushButtonLaw->setAutoRepeatInterval(100);

        verticalLayout_2->addWidget(pushButtonLaw);

        pushButtonPhoneBook = new QPushButton(layoutWidget1);
        pushButtonPhoneBook->setObjectName(QStringLiteral("pushButtonPhoneBook"));
        pushButtonPhoneBook->setFont(font1);
        pushButtonPhoneBook->setAutoRepeatInterval(100);

        verticalLayout_2->addWidget(pushButtonPhoneBook);

        toolBox->addItem(page_2, QString::fromUtf8("\345\205\254\345\217\270\347\233\270\345\205\263"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setGeometry(QRect(0, 0, 98, 28));
        layoutWidget2 = new QWidget(page_3);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(9, 0, 77, 141));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonGuardInfo = new QPushButton(layoutWidget2);
        pushButtonGuardInfo->setObjectName(QStringLiteral("pushButtonGuardInfo"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(12);
        pushButtonGuardInfo->setFont(font2);

        verticalLayout->addWidget(pushButtonGuardInfo);

        pushButtonGuardCompanyInfo = new QPushButton(layoutWidget2);
        pushButtonGuardCompanyInfo->setObjectName(QStringLiteral("pushButtonGuardCompanyInfo"));
        pushButtonGuardCompanyInfo->setFont(font2);

        verticalLayout->addWidget(pushButtonGuardCompanyInfo);

        pushButtonGuardPosition = new QPushButton(layoutWidget2);
        pushButtonGuardPosition->setObjectName(QStringLiteral("pushButtonGuardPosition"));
        pushButtonGuardPosition->setFont(font2);

        verticalLayout->addWidget(pushButtonGuardPosition);

        toolBox->addItem(page_3, QString::fromUtf8("\344\277\235\345\256\211\346\234\215\345\212\241"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 98, 28));
        layoutWidget3 = new QWidget(page);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 0, 77, 121));
        verticalLayout_4 = new QVBoxLayout(layoutWidget3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButtonPropertyInfo = new QPushButton(layoutWidget3);
        pushButtonPropertyInfo->setObjectName(QStringLiteral("pushButtonPropertyInfo"));
        pushButtonPropertyInfo->setFont(font1);

        verticalLayout_4->addWidget(pushButtonPropertyInfo);

        pushButtonPropertyCompany = new QPushButton(layoutWidget3);
        pushButtonPropertyCompany->setObjectName(QStringLiteral("pushButtonPropertyCompany"));
        pushButtonPropertyCompany->setFont(font1);

        verticalLayout_4->addWidget(pushButtonPropertyCompany);

        pushButtonPropertyUse = new QPushButton(layoutWidget3);
        pushButtonPropertyUse->setObjectName(QStringLiteral("pushButtonPropertyUse"));
        pushButtonPropertyUse->setFont(font1);

        verticalLayout_4->addWidget(pushButtonPropertyUse);

        toolBox->addItem(page, QString::fromUtf8("\347\211\251\344\270\232\346\234\215\345\212\241"));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        page_4->setGeometry(QRect(0, 0, 98, 28));
        toolBox->addItem(page_4, QString::fromUtf8("\350\264\242\345\212\241\347\256\241\347\220\206"));
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        page_5->setGeometry(QRect(0, 0, 98, 28));
        toolBox->addItem(page_5, QString::fromUtf8("\346\212\200\351\230\262\346\234\215\345\212\241"));

        horizontalLayout->addWidget(toolBox);

        stackedWidget = new QStackedWidget(layoutWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        stackedWidget->addWidget(page_7);

        horizontalLayout->addWidget(stackedWidget);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 6);

        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(Form);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "\350\201\212\345\237\216\345\270\202\351\262\201\346\230\214\344\277\235\345\256\211\346\234\215\345\212\241\346\234\211\351\231\220\345\205\254\345\217\270\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237", 0));
        pushButtonCompany->setText(QApplication::translate("Form", "\345\205\254\345\217\270\347\256\200\344\273\213", 0));
        pushButtonInstitution->setText(QApplication::translate("Form", "\346\234\272\346\236\204\350\256\276\347\275\256", 0));
        pushButtonRules->setText(QApplication::translate("Form", "\350\247\204\347\253\240\345\210\266\345\272\246", 0));
        pushButtonLaw->setText(QApplication::translate("Form", "\346\263\225\345\276\213\346\263\225\350\247\204", 0));
        pushButtonPhoneBook->setText(QApplication::translate("Form", "\351\200\232\350\256\257\345\275\225", 0));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("Form", "\345\205\254\345\217\270\347\233\270\345\205\263", 0));
        pushButtonGuardInfo->setText(QApplication::translate("Form", "\344\272\272\345\221\230\344\277\241\346\201\257", 0));
        pushButtonGuardCompanyInfo->setText(QApplication::translate("Form", "\345\256\242\346\210\267\345\215\225\344\275\215", 0));
        pushButtonGuardPosition->setText(QApplication::translate("Form", "\345\262\227\347\202\271\345\210\206\345\270\203", 0));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("Form", "\344\277\235\345\256\211\346\234\215\345\212\241", 0));
        pushButtonPropertyInfo->setText(QApplication::translate("Form", "\345\221\230\345\267\245\344\277\241\346\201\257", 0));
        pushButtonPropertyCompany->setText(QApplication::translate("Form", "\345\256\242\346\210\267\345\215\225\344\275\215", 0));
        pushButtonPropertyUse->setText(QApplication::translate("Form", "\347\211\251\350\265\204\351\242\206\347\224\250", 0));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("Form", "\347\211\251\344\270\232\346\234\215\345\212\241", 0));
        toolBox->setItemText(toolBox->indexOf(page_4), QApplication::translate("Form", "\350\264\242\345\212\241\347\256\241\347\220\206", 0));
        toolBox->setItemText(toolBox->indexOf(page_5), QApplication::translate("Form", "\346\212\200\351\230\262\346\234\215\345\212\241", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_H
