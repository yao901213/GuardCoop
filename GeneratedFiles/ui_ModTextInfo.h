/********************************************************************************
** Form generated from reading UI file 'ModTextInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODTEXTINFO_H
#define UI_MODTEXTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogModText
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *DialogModText)
    {
        if (DialogModText->objectName().isEmpty())
            DialogModText->setObjectName(QStringLiteral("DialogModText"));
        DialogModText->resize(549, 459);
        widget = new QWidget(DialogModText);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 31, 481, 401));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        verticalSpacer = new QSpacerItem(400, 50, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(100);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonOk = new QPushButton(widget);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));

        horizontalLayout->addWidget(pushButtonOk, 0, Qt::AlignRight|Qt::AlignVCenter);

        pushButtonCancel = new QPushButton(widget);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout->addWidget(pushButtonCancel, 0, Qt::AlignLeft);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);

        retranslateUi(DialogModText);
        QObject::connect(pushButtonCancel, SIGNAL(clicked()), DialogModText, SLOT(close()));

        QMetaObject::connectSlotsByName(DialogModText);
    } // setupUi

    void retranslateUi(QDialog *DialogModText)
    {
        DialogModText->setWindowTitle(QApplication::translate("DialogModText", "\344\277\256\346\224\271\346\226\207\346\234\254\344\277\241\346\201\257", 0));
        pushButtonOk->setText(QApplication::translate("DialogModText", "\347\241\256\345\256\232", 0));
        pushButtonCancel->setText(QApplication::translate("DialogModText", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogModText: public Ui_DialogModText {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODTEXTINFO_H
