#pragma once
#ifndef PROPERTY_EMPLOYEE_H
#define PROPERTY_EMPLOYEE_H

#include <QSqlTableModel>
#include <QLineEdit>
#include <QComboBox>
#include "ui_TableWidget.h"
#include "PropertyEmployeeEdit.h"
#include "PropertyDetail.h"

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
	PropertyDetail *detail;
	void InitWidget();
	void InitCombobox();
	PropertyEmployeeEdit *edit;
	void InitConnect();
	void SetModelHeader();
	void TableViewInit();
	QString strSearchFilter;
	void SetFilterByType();
	int ColumnIndex;
public slots:
	void UpdateTable();
private slots:
	void ClickSearchButton();
	void ClickAddButton();
	void ClickModButton();
	void ClickDelButton();
	void DoubleClickTable();
	void ClickTableHeader(int);
};


#endif