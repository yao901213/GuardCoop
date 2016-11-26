#pragma once
#include "ui_CarInsure.h"
#include <QSqlTableModel>

class CarInsure : public QDialog
{
public :
	CarInsure(QString &filter, int index);
	~CarInsure();
private:
	QSqlTableModel *model;
	int Index;
	Ui_CarInsure *ui;
	void InitDiag();
};