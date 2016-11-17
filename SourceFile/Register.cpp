#include "Register.h"
#include "ErrorProc.h"
#include "InfoCheck.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QObject>


RegisterDialog::RegisterDialog(QWidget *parent):
	QDialog(parent)
{
	ui = new Ui_RegisterDialog;
	ui->setupUi(this);
	InitDialog();
}

RegisterDialog::~RegisterDialog()
{
	delete(ui);
}

bool RegisterDialog::IsPasswordSame()
{
	QString pwd = ui->PasswordLineEdit->text();
	QString repwd = ui->CommitPasswordLineEdit->text();

	if (pwd == repwd)
	{
		return true;
	}
	else
	{ 
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("������������벻һ�£�����������"), 2);
		return false;
	}
}

bool RegisterDialog::IsInputValid()
{
	if (IsInputNull())
	{
		return false;
	}

	if (!InfoCheck::IsAccountValid(&ui->AccountLineEdit->text()))
	{
		ui->AccountLineEdit->clear();
		return false;
	}

	if (!InfoCheck::IsPasswordValid(&ui->PasswordLineEdit->text()))
	{
		ui->PasswordLineEdit->clear();
		ui->CommitPasswordLineEdit->clear();
		return false;
	}

	return true;
}


bool RegisterDialog::IsInputNull()
{
	if (ui->AccountLineEdit->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�������û���"), 2);
		return true;
	}

	if (ui->PasswordLineEdit->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("����������"), 2);
		return true;
	}

	if (ui->CommitPasswordLineEdit->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("���ٴ���������"), 2);
		return true;
	}

	return false;
}



void RegisterDialog::ClickOkButton()
{
	if (!IsInputValid())
	{
		return;
	}

	if (!IsPasswordSame())
	{
		ui->CommitPasswordLineEdit->clear();
		return;
	}

	if (IsAccountExist())
	{
		QString ErrorMessage(QString::fromLocal8Bit("�û���\""));
		ErrorMessage += ui->AccountLineEdit->text();
		ErrorMessage += QString::fromLocal8Bit("\"�Ѵ���");
		ErrorProc::PopMessageBox(&ErrorMessage, 2);

		ui->AccountLineEdit->clear();

		return;
	}

	InsertAccountInfo2Db();

	return;
}


void RegisterDialog::InsertAccountInfo2Db()
{
	QSqlQuery query;

	query.prepare("INSERT INTO HumanResource.GuestAccount(Account, Password)"
		"VALUES(:Account, :Password)");
	query.bindValue(":Account", ui->AccountLineEdit->text());
	query.bindValue(":Password", ui->PasswordLineEdit->text());
	if (!query.exec())
	{
		QString ErrorMessage(QString::fromLocal8Bit("������ݿ�ʧ��"));
		ErrorMessage += query.lastError().text();
		ErrorProc::PopMessageBox(&ErrorMessage, 2);
	}
	else
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("ע��ɹ�"), 0);
		this->close();
	}

	return;
}

bool RegisterDialog::IsAccountExist()
{
	QSqlTableModel model;

	model.setTable("HumanResource.GuestAccount");
	model.setFilter(QObject::tr("Account =  '%1'").arg(ui->AccountLineEdit->text()));
	
	model.select();
	if (0 != model.rowCount())
	{
		//����һ����¼
		return true;
	}

	return false;
}

void RegisterDialog::InitDialog()
{
	QObject::connect(ui->OKButtton, SIGNAL(clicked()), this, SLOT(ClickOkButton()));

	return;
}