#pragma once
#ifndef PROPERTY_EMPLOYEE_EDIT
#define PROPERTY_EMPLOYEE_EDIT
#include "ui_PropertyEdit.h"
#include <QSqlTableModel>
#include <QSqlQuery>
#include "propertyemployeeloandetail.h"

class PropertyEmployeeEdit : public QDialog
{
	Q_OBJECT
public:
	PropertyEmployeeEdit(QSqlTableModel *parentmodel, int CurRow, int sort);
	~PropertyEmployeeEdit();
	void InitModFunc();
	void InitAddFunc();

private:
	void InitDiag();
	QSqlTableModel *model;
	Ui_PropertyEdit *ui;
	int index;
	int CurID;
	void GetBirthAndGenderFromID();
	bool IsIDValid();
	bool IsInputValid();
	PropertyEmployeeLoanDetail *loandetail;
protected:
	bool eventFilter(QObject *obj, QEvent *ev);

private slots:
	void ClickSubmitButtonMod();
	void ClickSubmitButtonAdd();
	void ClickBrowseButton();
	void ClickPreviewButton();
	void ClickDelPicButton();
	void ClearPicLabel();
	void ClickLoanDetailButton();
};

const QString strCleaner = QString::fromLocal8Bit("保洁");
const QString strPlumElec = QString::fromLocal8Bit("水电");
const QString strGarden = QString::fromLocal8Bit("绿化");


#endif
