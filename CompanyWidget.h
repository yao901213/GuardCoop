#pragma once
#ifndef COMPANY_WIDGET_H
#define COMPANY_WIDGET_H

#include "ui_CompanyWidget.h"
#include <QSqlTableModel>
#include "ModTextInfo.h"

namespace Ui {
	class CompanyWidget;
}


class CompanyWidget : public QWidget
{
	Q_OBJECT
public:
	explicit CompanyWidget(QWidget *parent = 0);
	~CompanyWidget();
	ModTextInfoDiag *ModDialog;
	void ConstrainGuestAccount();
private:
	Ui::CompanyWidget *ui;
	QSqlTableModel *model;
	void SetLabelTextInfo(QString *TextType);
	PAGE_TYPE CurrentPageType;
	inline void SetCurrentPage(PAGE_TYPE type) { CurrentPageType = type; }
	void GetCurrentPageType(QString *type);
private slots:
	void GetTextInfoFromDb();
	void InitInstitutionInfo();
	void InitRulesInfo();
	void InitLawInfo();
	void InitCompanyWidget();
	void InitCompanyInfo();
	void ModifyText();
};


#endif