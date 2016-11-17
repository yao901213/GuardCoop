#pragma once
#ifndef PROPERTY_EMPLOYEE_H
#define PROPERTY_EMPLOYEE_H

#include <QSqlTableModel>
#include <QLineEdit>
#include <QComboBox>
#include "ui_TableWidget.h"

class PropertyEmployee : public QWidget
{
	Q_OBJECT
public:
	PropertyEmployee(QWidget *parent = 0);
	~PropertyEmployee();
private:
	Ui_TableWidget *ui;
	QSqlTableModel *model;
	QLineEdit *lineEdit;
	QComboBox *ComboBox;
	void InitWidget();
	void UpdateTable();
	void InitCombobox();
private slots:
	void ClickSearchButton();
	void ClickAddButton();
	void ClickModButton();
	void ClickDelButton();
};


#endif