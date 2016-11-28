#pragma once
#ifndef TOOL_EDIT_H
#define TOOL_EDIT_H
#include "ui_ToolEdit.h"
#include <QSqlTableModel>

class ToolEdit : public QDialog
{
	Q_OBJECT
public:
	ToolEdit(QString &filter, int index, int sort);
	~ToolEdit();
	void InitAddFunc();
	void InitModFunc();
private:
	void InitDiag();
	QSqlTableModel *model;
	Ui_DialogToolEdit *ui;
	int Index;
	bool IsInputValid();
private slots:
	void ClickOkButtonAddFunc();
	void ClickOkButtonModFunc();
};


#endif