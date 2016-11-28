#pragma once
#ifndef GUARD_EDIT_DIAG_H
#define GUARD_EDIT_DIAG_H
#include "ui_GuardEditDiag.h"
#include <QObject>
#include <QSqlTableModel>

class GuardEditDiag :public QDialog
{
	Q_OBJECT
public:
	explicit GuardEditDiag(QDialog *parent = 0);
	GuardEditDiag(int index, QSqlTableModel *parentmodel, int sort);
	~GuardEditDiag();
	void InitAddFunc();
	void InitModFunc();
private:
	Ui_GuardEditDialog *ui;
	int CurRowIndex;
	QSqlTableModel *model;
	QSqlTableModel *modelCompany;
	bool IsEmplyeeIdValid();
	void InitComboBox();
	void InitDiag();
	void InitDateEdit();
	void GetBirthAndGenderFromID();
	bool IsPicPathValid();
protected:
	bool eventFilter(QObject *obj, QEvent *ev);
private slots:
void ClickSubmitButtonAddFunc();
void ClickSubmitButtonModFunc();
void ClickBrowseButton();
void ClickPreviewButton();
void ClickDelPicButton();
void ClearPhoto();
};


#endif