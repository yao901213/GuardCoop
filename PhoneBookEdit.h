#pragma once
#ifndef ADD_PHONE_BOOK_H
#define ADD_PHONE_BOOK_H
#include "ui_PhoneBookEditDiag.h"
#include <QSqlTableModel>

class PhoneBookEdit :public QDialog
{
	Q_OBJECT
public:
	explicit PhoneBookEdit(QDialog *parent = 0);
	~PhoneBookEdit();
	PhoneBookEdit(int index, QSqlTableModel *model);
	void InitAddFunc();
	void InitModFunc();
	int ModRowIndex;
private:
	Ui_PhoneBookEdit *ui;
	QSqlTableModel *model;
	void InitDiag();
private slots:
	void ClickSubmitButtonAddFunc();
	void ClickSubmitButtonModFunc();
	bool IsInputValid();
};

#endif