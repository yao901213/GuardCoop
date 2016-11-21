#pragma once
#ifndef PROPERTY_DETAIL_H
#define PROPERTY_DETAIL_H
#include "ui_PropertyDetailInfo.h"
#include <QSqlTableModel>

class PropertyDetail : public QDialog
{
	Q_OBJECT
public:
	explicit PropertyDetail(QSqlTableModel *parentmodel, int parentindex);
	~PropertyDetail();
private:
	QSqlTableModel *model;
	void InitDiag();

	int index;
	Ui_PropertyDetail *ui;
private slots:
	void ClickDetailButton();
};



#endif