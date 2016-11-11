/********************************************************************************
** Form generated from reading UI file 'MapWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPWIDGET_H
#define UI_MAPWIDGET_H

#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapWidget
{
public:
    QWebEngineView *webEngineView;
    QGroupBox *groupBox;
    QPushButton *pushButtonAdd;

    void setupUi(QWidget *MapWidget)
    {
        if (MapWidget->objectName().isEmpty())
            MapWidget->setObjectName(QStringLiteral("MapWidget"));
        MapWidget->resize(680, 507);
        webEngineView = new QWebEngineView(MapWidget);
        webEngineView->setObjectName(QStringLiteral("webEngineView"));
        webEngineView->setGeometry(QRect(20, 30, 501, 431));
        webEngineView->setUrl(QUrl(QStringLiteral("about:blank")));
        groupBox = new QGroupBox(MapWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(530, 30, 131, 431));
        pushButtonAdd = new QPushButton(groupBox);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));
        pushButtonAdd->setGeometry(QRect(30, 70, 75, 23));

        retranslateUi(MapWidget);

        QMetaObject::connectSlotsByName(MapWidget);
    } // setupUi

    void retranslateUi(QWidget *MapWidget)
    {
        MapWidget->setWindowTitle(QApplication::translate("MapWidget", "Form", 0));
        groupBox->setTitle(QString());
        pushButtonAdd->setText(QApplication::translate("MapWidget", "\346\267\273\345\212\240", 0));
    } // retranslateUi

};

namespace Ui {
    class MapWidget: public Ui_MapWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPWIDGET_H
