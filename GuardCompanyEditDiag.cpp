#include "GuardCompanyEditDiag.h"
#include "ErrorProc.h"
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>

GuardCompanyEditDiag::GuardCompanyEditDiag(int index, QSqlTableModel *parentmodel)
{
	model = new QSqlTableModel;
	modelGuard = new QSqlTableModel;

	OldName = "";
	CurIndex = index;
	modelGuard->setTable("HumanResource.Guard");
	model->setTable("HumanResource.GuardCompany");
	model->setFilter(parentmodel->filter());

	ui = new  Ui_DialogEditGuardCompany;
	ui->setupUi(this);
}

GuardCompanyEditDiag::~GuardCompanyEditDiag()
{
	delete model;
	delete ui;
}

void GuardCompanyEditDiag::InitDiagModFunc()
{
	model->select();
	QSqlRecord record = model->record(CurIndex);

	ui->lineEditName->setText(record.value("Name").toString());
	ui->lineEditAddress->setText(record.value("Address").toString());
	ui->lineEditContacts->setText(record.value("Contacts").toString());
	ui->lineEditPhone->setText(record.value("Phone").toString());

	QObject::connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(ClickOkButtonMod()));
	this->show();
}

bool GuardCompanyEditDiag::IsOldCompanyNameHaveGuard()
{
	modelGuard->setFilter(QObject::tr("WorkPosition = '%1'").arg(OldName));
	modelGuard->select();

	if (0 != modelGuard->rowCount())
	{
		return true;
	}

	return false;
}


void GuardCompanyEditDiag::InitDiagAddFunc()
{
	QObject::connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(ClickOkButtonAdd()));
	this->show();
}

void GuardCompanyEditDiag::ClickOkButtonAdd()
{
	if (!IsInputValid())
	{
		return;
	}

	if (IsCompanyNameExist())
	{
		return;
	}

	model->setFilter("");
	model->select();
	QSqlRecord record = model->record(CurIndex);
	record.setValue("Name", ui->lineEditName->text());
	record.setValue("Address", ui->lineEditAddress->text());
	record.setValue("Contacts", ui->lineEditContacts->text());
	record.setValue("Phone", ui->lineEditPhone->text());
	record.setValue("GuardNum", 0);

	model->insertRecord(CurIndex, record);
	model->submitAll();

	this->accept();
}

void GuardCompanyEditDiag::ClickOkButtonMod()
{
	model->select();
	QSqlRecord record = model->record(CurIndex);
	OldName = record.value("Name").toString();
	
	if (!IsInputValid())
	{
		return;
	}

	if (OldName != ui->lineEditName->text())
	{
		if (IsCompanyNameExist())
		{
			return;
		}
		if (IsOldCompanyNameHaveGuard())
		{
			ChangeOldCompanyNameInGuardTable();
		}
		record.setValue("Name", ui->lineEditName->text());
	}
	record.setValue("Address", ui->lineEditAddress->text());
	record.setValue("Contacts", ui->lineEditContacts->text());
	record.setValue("Phone", ui->lineEditPhone->text());
	//record.setValue("GuardNum", record.value("GuardNum").toInt());
	model->setRecord(CurIndex, record);
	qDebug() << model->lastError().text();

	model->submitAll();


	if (IsTempSymbolExitInGuardTable())
	{
		ReplaceNewCompanyNameInGuardTable();
	}

	this->accept();
}

bool GuardCompanyEditDiag::IsInputValid()
{
	if (ui->lineEditName->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请填写公司名称"), 2);
		return false;
	}

	return true;
}

bool GuardCompanyEditDiag::IsCompanyNameExist()
{
	if (0 != GetCompanyNameNum())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("该公司名已经存在"), 2);
		return true;
	}

	return false;
}

int GuardCompanyEditDiag::GetCompanyNameNum()
{
	QSqlTableModel modeltemp;

	modeltemp.setTable("HumanResource.GuardCompany");
	modeltemp.setFilter(QObject::tr("Name = '%1'").arg(ui->lineEditName->text()));
	modeltemp.select();

	return modeltemp.rowCount();
}


void GuardCompanyEditDiag::ReplaceNewCompanyNameInGuardTable()
{
	int i = 0;
	int RowCount = 0;
	QString NewName = ui->lineEditName->text();
	QSqlRecord record;
	QString oldname = QString::fromLocal8Bit("临时");

	modelGuard->setFilter(QObject::tr("WorkPosition = '%1'").arg(oldname));
	modelGuard->select();

	RowCount = modelGuard->rowCount();
	for (; i < RowCount; i++)
	{
		record = modelGuard->record(i);
		record.setValue("WorkPosition", NewName);
		modelGuard->setRecord(i, record);
	}

	modelGuard->submitAll();
	qDebug() << modelGuard->lastError().text();
}

void GuardCompanyEditDiag::ChangeOldCompanyNameInGuardTable()
{
	int i = 0;
	int RowCount = 0;
	QString NewName = QString::fromLocal8Bit("临时");
	QSqlRecord record;

	modelGuard->setFilter(QObject::tr("WorkPosition = '%1'").arg(OldName));
	modelGuard->select();

	RowCount = modelGuard->rowCount();
	for (; i < RowCount; i++)
	{
		record = modelGuard->record(i);
		record.setValue("WorkPosition", NewName);
		modelGuard->setRecord(i, record);
	}

	if (!modelGuard->submitAll())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("添加数据库错误"), 2);
		return;
	}
	qDebug() << modelGuard->lastError().text();
}

bool GuardCompanyEditDiag::IsTempSymbolExitInGuardTable()
{
	QString str = QString::fromLocal8Bit("临时");
	modelGuard->setFilter(QObject::tr("WorkPosition = '%1'").arg(str));
	modelGuard->select();
	if (0 != modelGuard->rowCount())
	{
		return true;
	}

	return false;
}

