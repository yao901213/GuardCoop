/********************************************************************************
** Form generated from reading UI file 'LogInDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_3;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(505, 281);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 30, 431, 181));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(31, 41, 66, 74));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(40);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(12);
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(label_2);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(110, 40, 191, 79));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(25);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(12, 0, 0, 0);
        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(12);
        lineEdit->setFont(font1);

        verticalLayout_2->addWidget(lineEdit);

        lineEdit_3 = new QLineEdit(layoutWidget1);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        QFont font2;
        font2.setFamily(QStringLiteral("Agency FB"));
        font2.setPointSize(12);
        lineEdit_3->setFont(font2);
        lineEdit_3->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(lineEdit_3);

        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(330, 40, 77, 78));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(20);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font);

        verticalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setFont(font);

        verticalLayout_3->addWidget(pushButton_2);

        layoutWidget3 = new QWidget(groupBox);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(80, 150, 252, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setSpacing(60);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(layoutWidget3);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setFont(font);

        horizontalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(layoutWidget3);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setFont(font);

        horizontalLayout->addWidget(radioButton_2);

        QWidget::setTabOrder(lineEdit, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, radioButton);
        QWidget::setTabOrder(radioButton, radioButton_2);
        QWidget::setTabOrder(radioButton_2, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_2);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\350\201\212\345\237\216\345\270\202\351\262\201\346\230\214\344\277\235\345\256\211\346\234\215\345\212\241\346\234\211\351\231\220\345\205\254\345\217\270\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237", 0));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Dialog", "\350\264\246  \345\217\267", 0));
        label_2->setText(QApplication::translate("Dialog", "\345\257\206  \347\240\201", 0));
        lineEdit->setPlaceholderText(QApplication::translate("Dialog", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", 0));
#ifndef QT_NO_TOOLTIP
        lineEdit_3->setToolTip(QApplication::translate("Dialog", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0));
#endif // QT_NO_TOOLTIP
        lineEdit_3->setPlaceholderText(QApplication::translate("Dialog", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0));
        pushButton->setText(QApplication::translate("Dialog", "\347\231\273\345\275\225", 0));
        pushButton_2->setText(QApplication::translate("Dialog", "\346\263\250\345\206\214", 0));
        radioButton->setText(QApplication::translate("Dialog", "\347\224\250\346\210\267\347\231\273\345\275\225", 0));
        radioButton_2->setText(QApplication::translate("Dialog", "\347\256\241\347\220\206\345\221\230\347\231\273\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
