#pragma once
#ifndef CONTRACT_SERVICE
#define CONTRACT_SERVICE
#include "ui_TableWidget.h"
#include "Ftp.h"
#include <QSqlTableModel>
#include <QLineEdit>

class ContractService : public QWidget
{
public:
	explicit ContractService(QWidget *parent = 0);
	~ContractService();
private:
	Ftp *ftp;
	QLineEdit *lineEdit;
	QSqlTableModel *model;
	Ui_TableWidget *ui;
	void InitWidget();
};


#endif