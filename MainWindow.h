#pragma once
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "ui_Main.h"
#include "CompanyWidget.h"
#include "PhoneBook.h"
#include "GlobalVar.h"
#include "GuardWidget.h"
#include "GuardCompanyWidget.h"
#include "MapWidget.h"
#include "Connect2DB.h"

class MainWindow : public QWidget
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	void InitForm();

private:
	Ui_Form *ui;
	CompanyWidget *CompanyInfo;
	PhoneBook *phonebook;
	GuardWidget *GuardInfo;
	GuardCompany *GuardCompanyInfo;
	MapWidget *GuardPosition;
	int CompanyInfoIndex;
	int PhoneBookIndex;
	int GuardInfoIndex;
	int GuardCompanyIndex;
	int GuardPositionIndex;
	DB connectDB;
	void InitTopPic();
	void InitStackedWidget();
	void InitConnection();
private slots:
	void StackWidgetSwitch2CompanyInfo();
	void StackWidgetSwitch2PhoneBook();
	void StackWidgetSwitch2GuardInfo();
	void StackWidgetSwitch2GuardCompany();
	void StackWidgetSwitch2GuardPosition();
public slots:
	void ConstrainGuestAccount();
};



#endif