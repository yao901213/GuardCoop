#pragma once
#ifndef COMPANY_WIDGET_H
#define COMPANY_WIDGET_H

#include "ui_TextWidget.h"
#include <QSqlTableModel>
#include "ModTextInfo.h"

namespace Ui {
	class TextWidget;
}


class TextWidget : public QWidget
{
	Q_OBJECT
public:
	explicit TextWidget(QWidget *parent = 0);
	~TextWidget();
	ModTextInfoDiag *ModDialog;
	void ConstrainGuestAccount();
private:
	Ui_TextWidget *ui;
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
	void InitTextWidget();
	void InitCompanyInfo();
	void ModifyText();
};


#endif