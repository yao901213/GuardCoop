#pragma once
#ifndef CAR_H
#define CAR_H

#include "ui_CarTable.h"
#include <QSqlTableModel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include "CarEdit.h"

class Car : public QWidget
{
	Q_OBJECT
public:
	explicit Car(QWidget *parent = 0);
	~Car();
private:
	QPushButton *pushButtonInsure;
	QLineEdit *lineEdit;
	QComboBox *comboBox;
	Ui_CarTable *ui;
	QSqlTableModel *model;
	void InitWidget();
	CarEdit *edit;
public slots:
	void UpdateTable();
private slots:
	void ClickAddButton();
	void ClickModButton();
	void ClickInsureButton();
	void ClickMaintainButton();
	void DoubleClickRow();
};



#endif