#pragma once
#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include "ui_PhoneBook.h"
#include <QObject>
#include <QSqlTableModel>
#include "AddPhoneBook.h"


class PhoneBook :public QWidget
{
	Q_OBJECT
public:
	explicit PhoneBook(QWidget *parent = 0);
	~PhoneBook();
	void ShowPhoneBook();
	void ConstrainGuestAccount();
private:
	Ui_PhoneBookWidget *ui;
	void InitWidget();
	QSqlTableModel *model;
	AddPhoneBook *AddPhoneDiag;
	void SetStatusLabel();

private slots:
void ClickAddButton();
void ClickSearchButton();
void ClickModButton();
void ClickDelButton();
void UpdatePhoneBook();
public slots:
void ClearLineEdit();
};


#endif