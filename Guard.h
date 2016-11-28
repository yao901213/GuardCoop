#pragma once
#ifndef GUARD_WIDGET_H
#define GUARD_WIDGET_H
#include "ui_TableWidget.h"
#include <QWidget>
#include <QSqlTableModel>
#include "GuardEdit.h"
#include "GuardDetailInfo.h"

class GuardWidget :public QWidget
{
	Q_OBJECT
public:
	explicit GuardWidget(QWidget* parent = 0);
	~GuardWidget();
	void ClearLineEdit() { lineEdit->clear(); };
	void ConstrainGuestAccount();
private:
	QLineEdit *lineEdit;
	Ui_TableWidget *ui;
	QSqlTableModel *model;
	GuardEditDiag *GuardEdit;
	GuardDetail *guarddetail;
	void InitWidget();
	void InitStatusLabel();
	int ColumnIndex;
private slots:
	void ClickAddButton();
	void ClickModButton();
	void ClickDelButton();
	void ClickSearchButton();
	void DouleClickRow();
	void UpdateCompanyTable();
	void ClickTableHeader(int);
public slots:
	void ShowDbData();

};

#endif