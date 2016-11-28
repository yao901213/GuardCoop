#pragma once
#ifndef GUARD_DETAIL_INFO_H
#define GUARD_DETAIL_INFO_H

#include "ui_GuardDetailInfoDiag.h"
#include <QSqlTableModel>
#include <QObject>

class GuardDetail :QDialog
{
	Q_OBJECT
public:
	explicit GuardDetail(int SelectIndex, QSqlTableModel *parentModel, int sort);
	~GuardDetail();
private:
	QSqlTableModel *model;
	Ui_GuardDetailInfoDialog *ui;
	int index;
	void InitDiag();
};

#endif