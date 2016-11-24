#pragma once
#ifndef PROPERTY_EMPLOYEE_SELECT_H
#define PROPERTY_EMPLOYEE_SELECT_H
#include "ui_SmallTable.h"
#include <QSqlTableModel>

class PropertyEmployeeSelect :public QDialog
{
	Q_OBJECT
public:
	PropertyEmployeeSelect(QString &filter);
	~PropertyEmployeeSelect();
private:
	Ui_SmallTable *ui;
	QSqlTableModel *model;
	void InitDiag();
signals:
void ChoiceID(int);
private slots:
void ClickOkButton();
};


#endif