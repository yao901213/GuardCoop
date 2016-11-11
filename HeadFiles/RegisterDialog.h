#pragma once
#ifndef REGISTER_DIALOG_H
#define REGISTER_DIALOG_H

#include <QObject>
#include <QDialog>
#include "ui_RegisterDialog.h"

class RegisterDialog : public QDialog
{
	Q_OBJECT
public:
	explicit RegisterDialog(QWidget *parent = 0);
	~RegisterDialog();
	void InitDialog();

	private slots:
	void ClickOkButton();

private:
	Ui_RegisterDialog *ui;

	bool IsPasswordSame();
	bool IsInputValid();

	bool IsInputNull();
	bool IsAccountExist();

	void InsertAccountInfo2Db();
};



#endif