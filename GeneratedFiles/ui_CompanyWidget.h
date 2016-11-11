/********************************************************************************
** Form generated from reading UI file 'CompanyWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPANYWIDGET_H
#define UI_COMPANYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CompanyWidget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QWidget *CompanyWidget)
    {
        if (CompanyWidget->objectName().isEmpty())
            CompanyWidget->setObjectName(QStringLiteral("CompanyWidget"));
        CompanyWidget->resize(659, 446);
        layoutWidget = new QWidget(CompanyWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 30, 541, 341));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(18);
        label->setFont(font);

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 3);
        pushButton = new QPushButton(CompanyWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 390, 75, 23));

        retranslateUi(CompanyWidget);

        QMetaObject::connectSlotsByName(CompanyWidget);
    } // setupUi

    void retranslateUi(QWidget *CompanyWidget)
    {
        CompanyWidget->setWindowTitle(QApplication::translate("CompanyWidget", "\345\205\254\345\217\270\347\256\200\344\273\213", 0));
        label->setText(QApplication::translate("CompanyWidget", "\345\205\254\345\217\270\347\256\200\344\273\213", 0));
        label_2->setText(QApplication::translate("CompanyWidget", "TextLabel", 0));
        pushButton->setText(QApplication::translate("CompanyWidget", "\344\277\256\346\224\271", 0));
    } // retranslateUi

};

namespace Ui {
    class CompanyWidget: public Ui_CompanyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPANYWIDGET_H
