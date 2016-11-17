#pragma once
#ifndef GUARD_COMPANY_H
#define GUARD_COMPANY_H

#include "ui_TableWidget.h"
#include <QSqlTableModel>
#include <QComboBox>
#include "GuardCompanyEdit.h"

class GuardCompany : public QWidget
{
	Q_OBJECT
public:
	explicit GuardCompany(QWidget *parent = 0);
	~GuardCompany();
	void ShowDbData();
	void ResetComboBox();
	void ConstrainGuestAccount();
private:
	QComboBox *comboBox;
	Ui_TableWidget *ui;
	QSqlTableModel *model;
	GuardCompanyEditDiag *edit;
	void InitGuardCompanyInfo();
	bool IsCompanyHasGuard();
	void InitComboBox();

private slots:
	void ClickAddButton();
	void ClickSearchButton();
	void ClickModButton();
	void ClickDelButton();
	void UpdateTable();
};


#endif