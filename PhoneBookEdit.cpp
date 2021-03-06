#include "PhoneBookEdit.h"
#include "ErrorProc.h"
#include "InfoCheck.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlTableModel>

PhoneBookEdit::PhoneBookEdit(QDialog *parent) :
	QDialog(parent)
{
	ui = new Ui_PhoneBookEdit;
	ModRowIndex = -1;
	ui->setupUi(this);	
	InitDiag();
}

PhoneBookEdit::PhoneBookEdit(int index, QSqlTableModel *parentmodel)
{
	ui = new Ui_PhoneBookEdit;
	ModRowIndex = index;
	model = new QSqlTableModel;
	model->setTable("HumanResource.PhoneBook");
	model->setFilter(parentmodel->filter());
	QString ss = model->filter();
	ui->setupUi(this);
	InitDiag();
}


PhoneBookEdit::~PhoneBookEdit()
{
	delete ui;
}

void PhoneBookEdit::InitDiag()
{
	setModal(true);
	show();
}


void PhoneBookEdit::InitModFunc()
{
	QObject::connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(ClickSubmitButtonModFunc()));

	setWindowTitle(QString::fromLocal8Bit("请输入要修改的信息"));
	model->select();
	ui->lineEditName->setText(model->record(ModRowIndex).value("Name").toString());
	ui->lineEditPhone->setText(model->record(ModRowIndex).value("PhoneNum").toString());
	ui->lineEditEmail->setText(model->record(ModRowIndex).value("Email").toString());
	ui->lineEditAddress->setText(model->record(ModRowIndex).value("Address").toString());
}

void PhoneBookEdit::InitAddFunc()
{
	QObject::connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(ClickSubmitButtonAddFunc()));
}

void PhoneBookEdit::ClickSubmitButtonAddFunc()
{
	QSqlQuery query;
	QString message = QString::fromLocal8Bit("添加数据错误");

	if (!IsInputValid())
	{
		return;
	}
	query.prepare("INSERT INTO HumanResource.PhoneBook(Name, PhoneNum, Email, Address)"
		"VALUES(:Name, :PhoneNum, :Email, :Address)");

	query.bindValue(":Name", ui->lineEditName->text());
	query.bindValue(":PhoneNum", ui->lineEditPhone->text());
	query.bindValue(":Email", ui->lineEditEmail->text());
	query.bindValue(":Address", ui->lineEditAddress->text());

	if (!query.exec())
	{
		message += query.lastError().text();
		ErrorProc::PopMessageBox(&message, 2);
		
		return;
	}
	else
	{ 
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("添加数据成功"), 0);
		this->accept();
	}
	return;
}

void PhoneBookEdit::ClickSubmitButtonModFunc()
{
	QSqlRecord record = model->record(ModRowIndex);

	record.setValue("Name", ui->lineEditName->text());
	record.setValue("PhoneNum", ui->lineEditPhone->text());
	record.setValue("Email", ui->lineEditEmail->text());
	record.setValue("Address", ui->lineEditAddress->text());

	model->setRecord(ModRowIndex, record);
	model->submitAll();

	this->accept();
}

bool PhoneBookEdit::IsInputValid()
{
	if (ui->lineEditName->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请输入用户名"), 2);
		return false;
	}

	if (ui->lineEditPhone->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请输入联系方式"), 2);
		return false;
	}

	if (!InfoCheck::IsChineseStr(&ui->lineEditName->text()))
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("用户名只能包含中文字符"), 2);
		return false;
	}

	if (!InfoCheck::IsPhoneNumValid(&ui->lineEditPhone->text()))
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("联系电话中只能包含数字和\"-\""), 2);
		return false;
	}

	return true;
}