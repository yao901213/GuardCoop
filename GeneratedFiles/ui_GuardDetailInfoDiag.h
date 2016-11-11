/********************************************************************************
** Form generated from reading UI file 'GuardDetailInfoDiag.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUARDDETAILINFODIAG_H
#define UI_GUARDDETAILINFODIAG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuardDetailInfoDialog
{
public:
    QLabel *labelPic;
    QPushButton *pushButtonCancel;
    QLabel *labelWorkPosition;
    QLabel *labelIDCardNum;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelName;
    QLabel *labelID;

    void setupUi(QDialog *GuardDetailInfoDialog)
    {
        if (GuardDetailInfoDialog->objectName().isEmpty())
            GuardDetailInfoDialog->setObjectName(QStringLiteral("GuardDetailInfoDialog"));
        GuardDetailInfoDialog->resize(400, 499);
        labelPic = new QLabel(GuardDetailInfoDialog);
        labelPic->setObjectName(QStringLiteral("labelPic"));
        labelPic->setGeometry(QRect(270, 50, 80, 112));
        labelPic->setStyleSheet(QLatin1String("QLabel{\n"
"     border-width: 1px;\n"
"     border-style: dotted;\n"
"     border-color: rgb(0, 0, 0);\n"
"}"));
        labelPic->setAlignment(Qt::AlignCenter);
        pushButtonCancel = new QPushButton(GuardDetailInfoDialog);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(160, 400, 75, 23));
        labelWorkPosition = new QLabel(GuardDetailInfoDialog);
        labelWorkPosition->setObjectName(QStringLiteral("labelWorkPosition"));
        labelWorkPosition->setGeometry(QRect(150, 180, 201, 16));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        labelWorkPosition->setFont(font);
        labelIDCardNum = new QLabel(GuardDetailInfoDialog);
        labelIDCardNum->setObjectName(QStringLiteral("labelIDCardNum"));
        labelIDCardNum->setGeometry(QRect(150, 230, 161, 16));
        labelIDCardNum->setFont(font);
        layoutWidget = new QWidget(GuardDetailInfoDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 60, 114, 201));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(12);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        verticalLayout->addWidget(label_4);

        layoutWidget1 = new QWidget(GuardDetailInfoDialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(150, 61, 62, 91));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelName = new QLabel(layoutWidget1);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setFont(font);

        verticalLayout_2->addWidget(labelName);

        labelID = new QLabel(layoutWidget1);
        labelID->setObjectName(QStringLiteral("labelID"));
        labelID->setFont(font);

        verticalLayout_2->addWidget(labelID);


        retranslateUi(GuardDetailInfoDialog);
        QObject::connect(pushButtonCancel, SIGNAL(clicked()), GuardDetailInfoDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(GuardDetailInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *GuardDetailInfoDialog)
    {
        GuardDetailInfoDialog->setWindowTitle(QApplication::translate("GuardDetailInfoDialog", "\350\257\246\347\273\206\344\277\241\346\201\257", 0));
        labelPic->setText(QApplication::translate("GuardDetailInfoDialog", "\347\205\247\347\211\207", 0));
        pushButtonCancel->setText(QApplication::translate("GuardDetailInfoDialog", "\345\205\263\351\227\255", 0));
        labelWorkPosition->setText(QString());
        labelIDCardNum->setText(QString());
        label->setText(QApplication::translate("GuardDetailInfoDialog", "\345\247\223    \345\220\215", 0));
        label_2->setText(QApplication::translate("GuardDetailInfoDialog", "\345\267\245    \345\217\267", 0));
        label_3->setText(QApplication::translate("GuardDetailInfoDialog", "\345\267\245\344\275\234\345\234\260\347\202\271", 0));
        label_4->setText(QApplication::translate("GuardDetailInfoDialog", "\350\272\253\344\273\275\350\257\201\345\217\267", 0));
        labelName->setText(QString());
        labelID->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GuardDetailInfoDialog: public Ui_GuardDetailInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUARDDETAILINFODIAG_H
