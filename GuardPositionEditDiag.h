#pragma once
#ifndef GUARD_POSITION_EDIT_H
#define GUARD_POSITION_EDIT_H
#include "ui_GuardPositionDiag.h"
#include <QSqlTableModel>

class GuardPositionEditDiag :public QDialog
{
	Q_OBJECT
public:
	GuardPositionEditDiag();
	~GuardPositionEditDiag();
	void InitDiagAddFunc();
	void InitDiagModFunc();
	void InitDiagDelFunc();
private:
	Ui_DialogGuardPosition *ui;
	bool IsInputValid();
	QSqlTableModel *model;
private slots:
	void ClickOkButtonAddFunc();
	void ClickOkButtonDelFunc();
	void ClickOkButtonModFunc();
	void ClickCheckButton();
	void InitDiag();
};

#endif