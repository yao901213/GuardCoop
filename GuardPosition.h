#pragma once
#ifndef GUARD_POSITION_H
#define GUARD_POSITION_H
#include "ui_MapWidget.h"
#include <QSqlTableModel>
#include "GuardPositionEdit.h"


class GuardPosWidget :public QWidget
{
	Q_OBJECT
public:
	GuardPosWidget(QWidget *pare = 0);
	~GuardPosWidget();
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
	void ClickModButton();
	void ClickDelButton();
};
#endif