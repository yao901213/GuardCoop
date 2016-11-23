#pragma once
#ifndef PROPERTY_TOOL_H
#define PROPERTY_TOOL_H
#include "ui_PhoneBook.h"
#include <QSqlTableModel>
#include "PropertyToolEdit.h"
#include "PropertyToolDetail.h"

class PropertyTool : public QWidget
{
	Q_OBJECT
public:
	explicit PropertyTool(QWidget *parent = 0);
	~PropertyTool();
private:
	Ui_PhoneBookWidget *ui;
	ToolEdit *edit;
	PropertyToolDetail *detail;
	QSqlTableModel *model;
	void InitWidget();
	void InitTable();
	void InitConnect();
private slots:
void ClickAddButton();
void ClickModButton();
void ClickDelButton();
void ClickSearchButton();
void UpdateTable();
void DoubleClickRow();
};


#endif