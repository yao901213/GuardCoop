#pragma once
#ifndef MAP_WIDGET_H
#define MAP_WIDGET_H
#include "ui_MapWidget.h"
#include <QSqlTableModel>
#include "GuardPositionEditDiag.h"


class MapWidget :public QWidget
{
	Q_OBJECT
public:
	MapWidget(QWidget *pare = 0);
	~MapWidget();
private:
	Ui_MapWidget *ui;
	GuardPositionEditDiag *edit;
	void InitWidget();
	QUrl Url;
	double Longitude;
	double Latitude;
	QSqlTableModel *model;
	void SetAxis(double x, double y) { Longitude = x; Latitude = y; };
	QString title;
	int Index;
	int LoadTime;
	bool UpdateSymbol;
	void ResetPointIndex();
private slots:
	void ShowAllPoints(bool Finished);
	void AddPoint();
	void ClickAddButton();
	void ReloadUrl();
};
#endif