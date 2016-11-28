#pragma once
#ifndef CAR_DETAIL_H
#define CAR_DETAIL_H

#include "ui_CarDetail.h"
#include <QSqlTableModel>
#include "CarInsure.h"
#include "CarMaintain.h"

class CarDetail : public QDialog
{
	Q_OBJECT
public :
	CarDetail(QString &filter, int index, int sort);
	~CarDetail();
private:
	Ui_CarDetail *ui;
	QSqlTableModel *modelInsure;
	QSqlTableModel *modelCar;
	QSqlTableModel *modelMaintain;
	CarInsure *insure;
	CarMaintain *maintain;
	void InitDiag();
	int Index;
	void InitInsureTable();
	void InitMaintainTable();
	private slots:
	void DoubleClickInsureTable();
	void DoubleClickMaintainTable();
};


#endif