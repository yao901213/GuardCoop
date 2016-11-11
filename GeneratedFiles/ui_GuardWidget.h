/********************************************************************************
** Form generated from reading UI file 'GuardWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUARDWIDGET_H
#define UI_GUARDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuardWidget
{
public:
    QTableView *tableView;
    QPushButton *pushButtonSearch;
    QGroupBox *groupBox;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonMod;
    QPushButton *pushButtonDel;
    QLabel *label;

    void setupUi(QWidget *GuardWidget)
    {
        if (GuardWidget->objectName().isEmpty())
            GuardWidget->setObjectName(QStringLiteral("GuardWidget"));
        GuardWidget->resize(693, 477);
        tableView = new QTableView(GuardWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 70, 651, 341));
        pushButtonSearch = new QPushButton(GuardWidget);
        pushButtonSearch->setObjectName(QStringLiteral("pushButtonSearch"));
        pushButtonSearch->setGeometry(QRect(410, 30, 75, 23));
        groupBox = new QGroupBox(GuardWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(300, 420, 361, 41));
        pushButtonAdd = new QPushButton(groupBox);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));
        pushButtonAdd->setGeometry(QRect(10, 10, 75, 23));
        pushButtonMod = new QPushButton(groupBox);
        pushButtonMod->setObjectName(QStringLiteral("pushButtonMod"));
        pushButtonMod->setGeometry(QRect(140, 10, 75, 23));
        pushButtonDel = new QPushButton(groupBox);
        pushButtonDel->setObjectName(QStringLiteral("pushButtonDel"));
        pushButtonDel->setGeometry(QRect(260, 10, 75, 23));
        label = new QLabel(GuardWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 440, 151, 16));
        QWidget::setTabOrder(pushButtonSearch, pushButtonAdd);
        QWidget::setTabOrder(pushButtonAdd, pushButtonMod);
        QWidget::setTabOrder(pushButtonMod, pushButtonDel);
        QWidget::setTabOrder(pushButtonDel, tableView);

        retranslateUi(GuardWidget);

        QMetaObject::connectSlotsByName(GuardWidget);
    } // setupUi

    void retranslateUi(QWidget *GuardWidget)
    {
        GuardWidget->setWindowTitle(QApplication::translate("GuardWidget", "Form", 0));
        pushButtonSearch->setText(QApplication::translate("GuardWidget", "\346\237\245\350\257\242", 0));
        groupBox->setTitle(QString());
        pushButtonAdd->setText(QApplication::translate("GuardWidget", "\346\267\273\345\212\240", 0));
        pushButtonMod->setText(QApplication::translate("GuardWidget", "\344\277\256\346\224\271", 0));
        pushButtonDel->setText(QApplication::translate("GuardWidget", "\345\210\240\351\231\244", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GuardWidget: public Ui_GuardWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUARDWIDGET_H
