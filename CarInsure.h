#pragma once
#include "ui_CarInsure.h"
#include <QSqlTableModel>

class CarInsure : public QDialog
{
	Q_OBJECT
public :
	CarInsure(QString &filter, int index, int sort);
	~CarInsure();
	void InitAddFunc();
	void InitDetailFunc(QString &Carid);
	void InitAddFromDetail(QString &carid);
private:
	QSqlTableModel *model;
	QString Filter;
	int Index;
	int Sort;
	Ui_CarInsure *ui;
	void InitDiag();
	void InitComboBoxs();
	private slots:
	void ClickOkButton();
};