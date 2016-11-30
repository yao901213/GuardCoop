#pragma once
#ifndef CONTRACT_SERVICE
#define CONTRACT_SERVICE
#include "ui_phonebook.h"
#include "Ftp.h"
#include <QSqlTableModel>
#include <QLineEdit>
#include "ContractServiceEdit.h"

class ContractService : public QWidget
{
	Q_OBJECT
public:
	explicit ContractService(QWidget *parent = 0);
	~ContractService();
private:
	Ftp *ftp;
	QLineEdit *lineEdit;
	QSqlTableModel *model;
	Ui_PhoneBookWidget *ui;
	void InitWidget();
	ContractServiceEdit *edit;
	private slots:
	void ClickAddButton();
	void ClickModButton();
	void ClickSearchButton();
	void ClickDelButton();
	void UpdateTable();
	void DoubleClickRow();
};


#endif