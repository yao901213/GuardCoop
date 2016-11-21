#pragma once
#ifndef PROPERTY_TOOL_H
#define PROPERTY_TOOL_H
#include "ui_PhoneBook.h"
#include <QSqlTableModel>

class PropertyTool : public QWidget
{
	Q_OBJECT
public:
	explicit PropertyTool(QWidget *parent = 0);
	~PropertyTool();
private:
	Ui_PhoneBookWidget *ui;
	QSqlTableModel *model;
	void InitWidget();
};


#endif