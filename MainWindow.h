#pragma once
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "ui_Main.h"
#include "TextWidget.h"
#include "PhoneBook.h"
#include "GlobalVar.h"
#include "Guard.h"
#include "GuardCompany.h"
#include "GuardPosition.h"
#include "Connect2DB.h"
#include "PropertyEmployee.h"
#include "PropertyTool.h"
#include "PropertyLoan.h"

class MainWindow : public QWidget
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	void InitForm();

private:
	Ui_Form *ui;
	TextWidget *CompanyInfo;
	PhoneBook *phonebook;
	GuardWidget *GuardInfo;
	GuardCompany *GuardCompanyInfo;
	GuardPosWidget *GuardPosition;
	PropertyEmployee *propertyEmployee;
	PropertyTool *propertyTool;
	PropertyLoan *propertyLoan;
	int CompanyInfoIndex;
	int PhoneBookIndex;
	int GuardInfoIndex;
	int GuardCompanyIndex;
	int GuardPositionIndex;
	int PropertyEmployeeIndex;
	int PropertyToolIndex;
	int PropertyLoanIndex;
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
	void StackWidgetSwitch2PropertyEmployee();
	void StackWidgetSwitch2PropertyTool();
	void StackWidgetSwitch2PropertyLoan();	
	void SetLabelPosCompanyInfo();
	void SetLabelPosInstitution();
	void SetLabelPosLaw();
	void SetLabelPosRule();
public slots:
	void ConstrainGuestAccount();
};



#endif