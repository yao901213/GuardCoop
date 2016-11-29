#pragma once
#ifndef CAR_MAINTAIN_H
#define CAR_MAINTAIN_H
#include "ui_CarMaintain.h"
#include <QSqlTableModel>
class CarMaintain :public QDialog
{
	Q_OBJECT
public:
	CarMaintain(QString &filter, int index, int sort);
	~CarMaintain();
	void InitAddFunc();
	void InitDetailFunc(QString &carid);
	void InitAddFromDetail(QString &carid);
private:
	void InitDiag();
	Ui_CarMaintain *ui;
	QSqlTableModel *model;
	QSqlTableModel *modelCar;
	int Index;
	bool IsInputValid();
	bool IsCarIDExist();
	private slots:
	void ClickOkButton();
};


#endif
