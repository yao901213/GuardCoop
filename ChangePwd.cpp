#include "ChangePwd.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include "ErrorProc.h"
#include <QSqlRecord>

ChangePwd::ChangePwd(QDialog *parent) :
	QDialog(parent)
{
	ui = new Ui_DialogChangePwd;
	ui->setupUi(this);
	InitDiag();
}

ChangePwd::~ChangePwd()
{
	delete ui;
}

void ChangePwd::InitDiag()
{
	QObject::connect(ui->CancelButton, SIGNAL(clicked()), this, SLOT(reject()));
	QObject::connect(ui->OKButtton, SIGNAL(clicked()), this, SLOT(ClickOkButton()));
	ui->radioButtonUser->setChecked(true);
	ui->OKButtton->setShortcut(Qt::Key_Enter);
	ui->OKButtton->setShortcut(Qt::Key_Return);

	show();
}
bool ChangePwd::IsInputEmpty()
{
	if (ui->LineEditAccount->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("账号名为空"), 2);
		return true;
	}

	if (ui->lineEditOldPwd->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("密码不能为空"), 2);
		return true;
	}

	if (ui->LineEditNewPwd->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("新密码不能为空"), 2);
		return true;
	}

	if (ui->LineEditNewPwd2->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请再次输入密码"), 2);
		return true;
	}

	return false;
}

void ChangePwd::ClickOkButton()
{
	QSqlTableModel model;
	QString prepare;

	if (IsInputEmpty())
	{
		return;
	}

	if (ui->radioButtonUser->isChecked())
	{
		model.setTable("HumanResource.GuestAccount");
		prepare = tr("UPDATE HumanResource.GuestAccount SET Password = '%1' WHERE Account = '%2'").
			arg(ui->LineEditNewPwd->text()).arg(ui->LineEditAccount->text());
	}
	else
	{
		model.setTable("HumanResource.AdminAccount");
		prepare = tr("UPDATE HumanResource.AdminAccount SET Password = '%1' WHERE Account = '%2'").
			arg(ui->LineEditNewPwd->text()).arg(ui->LineEditAccount->text());
	}

	model.setFilter(tr("Account = '%1' AND Password = '%2'").
		arg(ui->LineEditAccount->text()).arg(ui->lineEditOldPwd->text()));
	model.select();

	if (0 == model.rowCount())
	{
		model.setFilter(tr("Account = '%1'").arg(ui->LineEditAccount->text()));
		model.select();
		if (0 == model.rowCount())
		{
			ErrorProc::PopMessageBox(&QString::fromLocal8Bit("账号名输入不正确"), 2);
			return;
		}
		else
		{
			ErrorProc::PopMessageBox(&QString::fromLocal8Bit("原密码输入不正确"), 2);
			return;
		}
	}

	if (ui->LineEditNewPwd->text() != ui->LineEditNewPwd2->text())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("两次密码输入不一致"), 2);
		return;
	}
	QSqlQuery query;
	query.prepare(prepare);

	if (!query.exec())
	{
		ErrorProc::PopMessageBox(&query.lastError().text(), 2);
		return;
	}

	this->accept();
}