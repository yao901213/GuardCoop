/********************************************************************************
** Form generated from reading UI file 'GuardEditDiag.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUARDEDITDIAG_H
#define UI_GUARDEDITDIAG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuardEditDialog
{
public:
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButtonBrowse;
    QLabel *labelPic;
    QPushButton *pushButtonPreview;
    QLineEdit *lineEditIDCardNum;
    QLineEdit *lineEditPhoto;
    QLineEdit *lineEditName;
    QLineEdit *lineEditID;
    QComboBox *comboBox;

    void setupUi(QDialog *GuardEditDialog)
    {
        if (GuardEditDialog->objectName().isEmpty())
            GuardEditDialog->setObjectName(QStringLiteral("GuardEditDialog"));
        GuardEditDialog->resize(381, 500);
        pushButtonOk = new QPushButton(GuardEditDialog);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(80, 410, 75, 23));
        pushButtonCancel = new QPushButton(GuardEditDialog);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(210, 410, 75, 23));
        groupBox = new QGroupBox(GuardEditDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(50, 40, 301, 321));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 30, 122, 261));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(12);
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);

        pushButtonBrowse = new QPushButton(groupBox);
        pushButtonBrowse->setObjectName(QStringLiteral("pushButtonBrowse"));
        pushButtonBrowse->setGeometry(QRect(250, 150, 41, 23));
        labelPic = new QLabel(groupBox);
        labelPic->setObjectName(QStringLiteral("labelPic"));
        labelPic->setGeometry(QRect(200, 20, 80, 112));
        labelPic->setStyleSheet(QLatin1String("QLabel{\n"
"     border-width: 1px;\n"
"     border-style: dotted;\n"
"     border-color: rgb(0, 0, 0);\n"
"}"));
        labelPic->setAlignment(Qt::AlignCenter);
        pushButtonPreview = new QPushButton(groupBox);
        pushButtonPreview->setObjectName(QStringLiteral("pushButtonPreview"));
        pushButtonPreview->setGeometry(QRect(250, 180, 41, 23));
        lineEditIDCardNum = new QLineEdit(groupBox);
        lineEditIDCardNum->setObjectName(QStringLiteral("lineEditIDCardNum"));
        lineEditIDCardNum->setGeometry(QRect(110, 260, 133, 20));
        lineEditPhoto = new QLineEdit(groupBox);
        lineEditPhoto->setObjectName(QStringLiteral("lineEditPhoto"));
        lineEditPhoto->setGeometry(QRect(110, 150, 133, 20));
        lineEditName = new QLineEdit(groupBox);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setGeometry(QRect(110, 100, 71, 20));
        lineEditID = new QLineEdit(groupBox);
        lineEditID->setObjectName(QStringLiteral("lineEditID"));
        lineEditID->setGeometry(QRect(110, 40, 71, 20));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(110, 200, 131, 21));
        QWidget::setTabOrder(lineEditID, lineEditName);
        QWidget::setTabOrder(lineEditName, lineEditIDCardNum);
        QWidget::setTabOrder(lineEditIDCardNum, pushButtonOk);
        QWidget::setTabOrder(pushButtonOk, pushButtonCancel);

        retranslateUi(GuardEditDialog);
        QObject::connect(pushButtonCancel, SIGNAL(clicked()), GuardEditDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(GuardEditDialog);
    } // setupUi

    void retranslateUi(QDialog *GuardEditDialog)
    {
        GuardEditDialog->setWindowTitle(QApplication::translate("GuardEditDialog", "\350\257\267\350\276\223\345\205\245\344\272\272\345\221\230\344\277\241\346\201\257", 0));
        pushButtonOk->setText(QApplication::translate("GuardEditDialog", "\347\241\256\345\256\232", 0));
        pushButtonCancel->setText(QApplication::translate("GuardEditDialog", "\345\217\226\346\266\210", 0));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("GuardEditDialog", "\345\267\245    \345\217\267", 0));
        label_2->setText(QApplication::translate("GuardEditDialog", "\345\247\223    \345\220\215", 0));
        label_5->setText(QApplication::translate("GuardEditDialog", "\347\205\247    \347\211\207", 0));
        label_3->setText(QApplication::translate("GuardEditDialog", "\345\267\245\344\275\234\345\234\260\347\202\271", 0));
        label_4->setText(QApplication::translate("GuardEditDialog", "\350\272\253\344\273\275\350\257\201\345\217\267", 0));
        pushButtonBrowse->setText(QApplication::translate("GuardEditDialog", "...", 0));
        labelPic->setText(QApplication::translate("GuardEditDialog", "\347\205\247\347\211\207", 0));
        pushButtonPreview->setText(QApplication::translate("GuardEditDialog", "\351\242\204\350\247\210", 0));
    } // retranslateUi

};

namespace Ui {
    class GuardEditDialog: public Ui_GuardEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUARDEDITDIAG_H
