#pragma once
#ifndef CONTRACT_SERVICE_EDIT_H
#define CONTRACT_SERVICE_EDIT_H
#include "ui_ContractServiceEdit.h"
#include <QSqlTableModel>
#include "Ftp.h"
#include "PicView.h"

class ContractServiceEdit : public QDialog
{
	Q_OBJECT
public:
	explicit ContractServiceEdit(QString &filter, int index, int sort);
	~ContractServiceEdit();
	void InitAddFunc();
	void InitDetailFunc();
	void InitModFunc();
private:
	int Index;
	QSqlTableModel *model;
	Ui_ContractServiceEdit *ui;
	void InitDiag();
	bool IsInputValid();
	Ftp *ftp;
	QString strFolder;
	void SetFolderName();
	PicView *view;
	void InitLineedit();
private slots:
	void ClickOkButtonAddFunc();
	void ClickOkButtonModFunc();
	void ClickPicButton();
	void ClickBrowseButton();
};


#endif