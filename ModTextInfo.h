#pragma once
#ifndef MOD_TEXT_INFO_H
#define MOD_TEXT_INFO_H
#include "ui_ModTextInfo.h"
#include <QObject>
#include <QSqlTableModel>

typedef enum
{
	PAGE_COMPANY,
	PAGE_INSTITUTION,
	PAGE_LAW,
	PAGE_RULE,
	PAGE_BUT
}PAGE_TYPE;

class ModTextInfoDiag :public QDialog
{
	Q_OBJECT
public:
	explicit ModTextInfoDiag(QDialog *parent = 0);
	~ModTextInfoDiag();
	void InitModTextInfoDiag();
	PAGE_TYPE PageType;
private:
	Ui_DialogModText *ui;
	void InitDialog();
	QSqlTableModel *model;
	void GetPageType(QString *type);
private slots:
	void SubmitModTextInfo();
};

#endif