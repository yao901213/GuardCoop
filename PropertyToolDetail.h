#pragma once
#ifndef PROPERTY_TOOL_DETAIL_H
#define PROPERTY_TOOL_DETAIL_H

#include "ui_PropertyToolDetail.h"
#include <QSqlTableModel>

class PropertyToolDetail : public QDialog 
{
	Q_OBJECT
public:
	PropertyToolDetail(QString &filter, int index);
	~PropertyToolDetail();
private:
	void InitDiag();
	QSqlTableModel *model;
	int Index;
	Ui_PropertyToolDetail *ui;
};


#endif