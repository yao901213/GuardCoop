#pragma once
#ifndef GUARD_COMPANY_EDIT_H
#define GUARD_COMPANY_EDIT_H

#include "ui_GuardCompanyEditDiag.h"
#include <QSqlTableModel>

class GuardCompanyEditDiag : public QDialog
{
	Q_OBJECT
public:
	GuardCompanyEditDiag(int index, QSqlTableModel *model);
	~GuardCompanyEditDiag();
	void InitDiagAddFunc();
	void InitDiagModFunc();
private:
	Ui_DialogEditGuardCompany *ui;
	QSqlTableModel* model;
	QSqlTableModel* modelGuard;
	int CurIndex;
	bool IsOldCompanyNameHaveGuard();
	void ChangeOldCompanyNameInGuardTable();
	void ReplaceNewCompanyNameInGuardTable();
	QString OldName;
	bool IsTempSymbolExitInGuardTable();
private slots:
	void ClickOkButtonAdd();
	void ClickOkButtonMod();
	bool IsInputValid();
	bool IsCompanyNameExist();
	int GetCompanyNameNum();
};

#endif