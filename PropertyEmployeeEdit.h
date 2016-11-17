#pragma once
#ifndef PROPERTY_EMPLOYEE_EDIT
#define PROPERTY_EMPLOYEE_EDIT
#include "ui_PropertyEdit.h"
#include <QSqlTableModel>

class PropertyEmployeeEdit : public QDialog
{
	Q_OBJECT
public:
	PropertyEmployeeEdit(QSqlTableModel *parentmodel, int CurRow);
	~PropertyEmployeeEdit();
	void InitModFunc();
	void InitAddFunc();

private:
	void InitDiag();
	QSqlTableModel *model;
	Ui_PropertyEdit *ui;
	int index;
};

#endif
