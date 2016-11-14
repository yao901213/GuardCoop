#pragma once
#ifndef CHANGE_PWD
#define CHANGE_PWD
#include "ui_ChangePwdDiag.h"

class ChangePwd : public QDialog
{
	Q_OBJECT
public:
	explicit ChangePwd(QDialog *parent = 0);
	~ChangePwd();
private:
	void InitDiag();
	Ui_DialogChangePwd *ui;
	bool IsInputEmpty();
private slots:
	void ClickOkButton();
};

#endif