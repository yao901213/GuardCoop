#pragma once
#ifndef CAR_EDIT_H
#define CAR_EDIT_H
#include "ui_CarEdit.h"
#include <QSqlTableModel>

class CarEdit : public QDialog
{
	Q_OBJECT
public:
	CarEdit(QString &filter, int index);
	~CarEdit();
	void InitDiagAddFunc();
	void InitDiagModFunc();
private:
	Ui_CarEdit *ui;
	QSqlTableModel *model;
	void InitDiag();
	int Index;
	bool IsCarIDExist();
	bool IsInputValid();
private slots:
	void ClickOkButtonAddFunc();

};




#endif