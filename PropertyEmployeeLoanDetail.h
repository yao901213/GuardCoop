#pragma once
#ifndef PROPERTY_EMPLOYEE_LOAN_DETAIL_H
#define PROPERTY_EMPLOYEE_LOAN_DETAIL_H
#include "ui_SmallTable.h"
#include <QSqlTableModel>
#include "PropertyLoanEdit.h"

class PropertyEmployeeLoanDetail : public QDialog
{
	Q_OBJECT
public:
	PropertyEmployeeLoanDetail(QString &filter);
	~PropertyEmployeeLoanDetail();
private:
	Ui_SmallTable *ui;
	QSqlTableModel *model; 
	PropertyLoanEdit *detail;
	void InitDiag();
	private slots:
	void DoubleClickRow();
};


#endif