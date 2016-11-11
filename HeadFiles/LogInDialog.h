#pragma once
#ifndef LOG_IN_DIALOG
#define LOG_IN_DIALOG

#include <QDialog>
#include <QObject>
#include "ui_LogInDialog.h"
#include "RegisterDialog.h"
#include "MainWindow.h"
#include "Connect2DB.h"

namespace Ui {
	class LogInDialog;
}

class LogInDialog : public QDialog
{
	Q_OBJECT

public:
	 explicit LogInDialog(QWidget *parent = 0);
	 ~LogInDialog();

	void InitForm();

	bool IsRadioButtonSelected();

	public slots:
	void ClickLoginButton();
	void ClickRegisterButton();
private:
	DB connectDb;
	MainWindow *MainWin;
	RegisterDialog *RegisterDiag;
	Ui_Dialog *ui;

	/////////////////

	void TestTemp();
};


#endif