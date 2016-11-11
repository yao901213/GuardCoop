#pragma once
#ifndef GUARD_POSITION_EDIT_H
#define GUARD_POSITION_EDIT_H
#include "ui_GuardPositionDiag.h"
#include <QSqlTableModel>

class GuardPositionEditDiag :public QDialog
{
	Q_OBJECT
public:
	GuardPositionEditDiag(QSqlTableModel *parentModel);
	~GuardPositionEditDiag();
private:
	void InitDiag();
	Ui_DialogGuardPosition *ui;
	bool IsInputValid();
	QSqlTableModel *model;
private slots:
	void ClickOkButton();
};

#endif