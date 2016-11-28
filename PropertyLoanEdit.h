#pragma once
#ifndef PROPERTY_LOAN_EDIT_H
#define PROPERTY_LOAN_EDIT_H

#include "ui_PropertyLoanEdit.h"
#include "PropertyEmployeeSelect.h"
#include <QSqlTableModel>

class PropertyLoanEdit : public QDialog
{
	Q_OBJECT
public:
	PropertyLoanEdit(QString &filter, int index, int sort);
	~PropertyLoanEdit();
	void InitDiagAddfunc();
	void InitDiagModFunc();
	void InitDiagDelFunc();
	void InitDiagDetailFunc();
	int EmploeeID;

protected:
	bool eventFilter(QObject *ob, QEvent *ev);
private:
	Ui_PropertyLoanEdit *ui;
	QSqlTableModel *model;
	QSqlTableModel *modelEmployee;
	QSqlTableModel *modelTool;
	int Index;
	void InitDiag();
	void LineEditBorrowerIDFilter(QEvent *ev);
	void LineEditLoanStaffFilter(QEvent *ev);
	PropertyEmployeeSelect *choice;
	bool IsInputValid();
	bool IsInputEmpty();
	bool IsInputValidDelFunc();
	void ChangeEmployeeTable();
	void ChangeToolTable();
private slots:
	void ClickOkButtonAddFunc();
	void ClickOkButtonModFunc();
	void ClickOkButtonDelFunc();
	void ClickCheckButton();
	void SetBorrowerLineEdit(int);
};


#endif