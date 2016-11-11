#pragma once
#ifndef ADD_PHONE_BOOK_H
#define ADD_PHONE_BOOK_H
#include "ui_AddPhoneBookDiag.h"
#include <QSqlTableModel>

class AddPhoneBook :public QDialog
{
	Q_OBJECT
public:
	explicit AddPhoneBook(QDialog *parent = 0);
	~AddPhoneBook();
	AddPhoneBook(int index, QSqlTableModel *model);
	void InitAddFunc();
	void InitModFunc();
	int ModRowIndex;
private:
	Ui_DialogAddPhoneBook *ui;
	QSqlTableModel *model;
private slots:
	void ClickSubmitButtonAddFunc();
	void ClickSubmitButtonModFunc();
	bool IsInputValid();
};

#endif