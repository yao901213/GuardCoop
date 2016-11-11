/********************************************************************************
** Form generated from reading UI file 'PhoneBook.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHONEBOOK_H
#define UI_PHONEBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PhoneBookWidget
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QGroupBox *groupBox;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButtonSearch;
    QPushButton *pushButtonShowAll;
    QGroupBox *groupBoxAdmin;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonMod;
    QPushButton *pushButton;

    void setupUi(QWidget *PhoneBookWidget)
    {
        if (PhoneBookWidget->objectName().isEmpty())
            PhoneBookWidget->setObjectName(QStringLiteral("PhoneBookWidget"));
        PhoneBookWidget->resize(699, 475);
        label = new QLabel(PhoneBookWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 450, 181, 16));
        layoutWidget = new QWidget(PhoneBookWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 30, 641, 411));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        horizontalLayout->addWidget(tableView);

        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 171, 361));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 20, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        pushButtonSearch = new QPushButton(layoutWidget1);
        pushButtonSearch->setObjectName(QStringLiteral("pushButtonSearch"));

        verticalLayout->addWidget(pushButtonSearch, 0, Qt::AlignHCenter);

        pushButtonShowAll = new QPushButton(layoutWidget1);
        pushButtonShowAll->setObjectName(QStringLiteral("pushButtonShowAll"));

        verticalLayout->addWidget(pushButtonShowAll, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout_3->addLayout(verticalLayout);

        groupBoxAdmin = new QGroupBox(layoutWidget1);
        groupBoxAdmin->setObjectName(QStringLiteral("groupBoxAdmin"));
        layoutWidget2 = new QWidget(groupBoxAdmin);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(50, 20, 77, 139));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setSpacing(15);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonAdd = new QPushButton(layoutWidget2);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));

        verticalLayout_2->addWidget(pushButtonAdd);

        pushButtonDelete = new QPushButton(layoutWidget2);
        pushButtonDelete->setObjectName(QStringLiteral("pushButtonDelete"));

        verticalLayout_2->addWidget(pushButtonDelete);

        pushButtonMod = new QPushButton(layoutWidget2);
        pushButtonMod->setObjectName(QStringLiteral("pushButtonMod"));

        verticalLayout_2->addWidget(pushButtonMod);

        pushButton = new QPushButton(layoutWidget2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);


        verticalLayout_3->addWidget(groupBoxAdmin);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 2);

        horizontalLayout->addWidget(groupBox);

        horizontalLayout->setStretch(0, 4);
        horizontalLayout->setStretch(1, 2);
        QWidget::setTabOrder(lineEdit, pushButtonSearch);
        QWidget::setTabOrder(pushButtonSearch, pushButtonShowAll);
        QWidget::setTabOrder(pushButtonShowAll, pushButtonAdd);
        QWidget::setTabOrder(pushButtonAdd, pushButtonDelete);
        QWidget::setTabOrder(pushButtonDelete, pushButtonMod);
        QWidget::setTabOrder(pushButtonMod, pushButton);
        QWidget::setTabOrder(pushButton, tableView);

        retranslateUi(PhoneBookWidget);

        QMetaObject::connectSlotsByName(PhoneBookWidget);
    } // setupUi

    void retranslateUi(QWidget *PhoneBookWidget)
    {
        PhoneBookWidget->setWindowTitle(QApplication::translate("PhoneBookWidget", "Form", 0));
        label->setText(QString());
        groupBox->setTitle(QString());
        lineEdit->setPlaceholderText(QApplication::translate("PhoneBookWidget", "\350\257\267\350\276\223\345\205\245\345\247\223\345\220\215\346\210\226\350\200\205\345\217\267\347\240\201\350\277\233\350\241\214\346\237\245\350\257\242", 0));
        pushButtonSearch->setText(QApplication::translate("PhoneBookWidget", "\346\237\245\350\257\242", 0));
        pushButtonShowAll->setText(QApplication::translate("PhoneBookWidget", "\346\230\276\347\244\272\345\205\250\351\203\250", 0));
        groupBoxAdmin->setTitle(QString());
        pushButtonAdd->setText(QApplication::translate("PhoneBookWidget", "\345\242\236\345\212\240", 0));
        pushButtonDelete->setText(QApplication::translate("PhoneBookWidget", "\345\210\240\351\231\244", 0));
        pushButtonMod->setText(QApplication::translate("PhoneBookWidget", "\344\277\256\346\224\271", 0));
        pushButton->setText(QApplication::translate("PhoneBookWidget", "\346\211\271\351\207\217\346\267\273\345\212\240", 0));
    } // retranslateUi

};

namespace Ui {
    class PhoneBookWidget: public Ui_PhoneBookWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHONEBOOK_H
