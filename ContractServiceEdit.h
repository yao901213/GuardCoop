#pragma once
#ifndef CONTRACT_SERVICE_EDIT_H
#define CONTRACT_SERVICE_EDIT_H
#include "ui_ContractServiceEdit.h"
#include <QSqlTableModel>

class ContractServiceEdit : public QDialog
{
	Q_OBJECT
public:
	explicit ContractServiceEdit(QString &filter, int index, int sort);
	~ContractServiceEdit();
	void InitAddFunc();
private:
	QSqlTableModel *model;
	Ui_ContractServiceEdit *ui;
	void InitDiag();
};


#endif