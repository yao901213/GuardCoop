#pragma once
#ifndef PROPERTY_LOAN_H
#define PROPERTY_LOAN_H
#include "ui_TableWidget.h"
#include "PropertyLoanEdit.h"
#include <QSqlTableModel>
#include <QLineEdit>

class PropertyLoan : public QWidget
{
	Q_OBJECT
public:
	PropertyLoan(QWidget *parent = 0);
	~PropertyLoan();
private:
	void InitWidget();
	QSqlTableModel *model;
	PropertyLoanEdit *edit;
	Ui_TableWidget *ui;
	QLineEdit *lineEdit;
	void InitTable();
	void InitButtons();
	void InitConnect();
public slots:
	void UpdateTable();
private slots:
	void ClickAddButton();
	void ClickModButton();
	void ClickDelButton();
	void ClickSearckButton();
};


#endif