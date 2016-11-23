#pragma once
#ifndef PROPERTY_LOAN_EDIT_H
#define PROPERTY_LOAN_EDIT_H

#include "ui_PropertyLoanEdit.h"
#include <QSqlTableModel>

class PropertyLoanEdit : public QDialog
{
	Q_OBJECT
public:
	PropertyLoanEdit(QString &filter, int index);
	~PropertyLoanEdit();
	void InitDiagAddfunc();

protected:
	bool eventFilter(QObject *ob, QEvent *ev);
private:
	Ui_PropertyLoanEdit *ui;
	QSqlTableModel *model;
	QSqlTableModel *modelEmployee;
	QSqlTableModel *modelTool;
	int Index;
	void InitDiag();
	private slots:
	void ClickOkButtonAddFunc();
};


#endif