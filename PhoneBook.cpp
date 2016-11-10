#include "PhoneBook.h"
#include "GlobalVar.h"
#include "ErrorProc.h"
#include <QSqlRecord>
#include "InfoCheck.h"

PhoneBook::PhoneBook(QWidget *parent):
	QWidget(parent),
	ui(new Ui::PhoneBookWidget)
{
	ui->setupUi(this);
	InitWidget();
}

PhoneBook::~PhoneBook()
{
	delete ui;
}

void PhoneBook::ShowPhoneBook()
{
	model->select();
	model->setFilter("");
	ui->tableView->show();
	SetStatusLabel();
}

void PhoneBook::SetStatusLabel()
{
	QString message = QString::fromLocal8Bit("����%1����ϵ��").arg(model->rowCount());
	model->setFilter("");
	model->select();

	ui->label->setText(message);
}

void PhoneBook::UpdatePhoneBook()
{
	model->setFilter("");
	model->select();
	ui->tableView->show();
	SetStatusLabel();
	ui->lineEdit->clear();
}

void PhoneBook::ConstrainGuestAccount()
{
	ui->groupBoxAdmin->setEnabled(false);
}


void PhoneBook::InitWidget()
{
	model = new  QSqlTableModel;
	model->setTable("HumanResource.PhoneBook");

	model->setHeaderData(0, Qt::Horizontal,QString::fromLocal8Bit("����"), Qt::DisplayRole);
	model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("��ϵ��ʽ"), Qt::DisplayRole);
	model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("Email"), Qt::DisplayRole);
	model->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("סַ"), Qt::DisplayRole);

	model->select();
	
	ui->tableView->setModel(model);
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableView->resizeColumnToContents(2);

	QObject::connect(ui->pushButtonSearch, SIGNAL(clicked()), this, SLOT(ClickSearchButton()));
	QObject::connect(ui->pushButtonMod, SIGNAL(clicked()), this, SLOT(ClickModButton()));
	QObject::connect(ui->pushButtonAdd, SIGNAL(clicked()), this, SLOT(ClickAddButton()));
	QObject::connect(ui->pushButtonDelete, SIGNAL(clicked()), this, SLOT(ClickDelButton()));
	QObject::connect(ui->pushButtonShowAll, SIGNAL(clicked()), this, SLOT(UpdatePhoneBook()));

	ui->pushButtonSearch->setFocus();
	ui->pushButtonSearch->setShortcut(Qt::Key_Enter);
	ui->pushButtonSearch->setShortcut(Qt::Key_Return);

	return;
}

void PhoneBook::ClickAddButton()
{
	AddPhoneDiag = new AddPhoneBook;
	QObject::connect(AddPhoneDiag, SIGNAL(accepted()), this, SLOT(UpdatePhoneBook()));
	AddPhoneDiag->InitAddFunc();
}

void PhoneBook::ClickSearchButton()
{
	if (ui->lineEdit->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("������Ҫ��ѯ������"), 2);

		return;
	}
	QChar cha = ui->lineEdit->text().at(0);

	if (cha.isDigit())
	{
		if (!InfoCheck::IsPhoneNumValid(&ui->lineEdit->text()))
		{
			ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��Ҫ��ѯ�ĺ����������"), 2);
			return;
		}
		model->setFilter(QObject::tr("PhoneNum = '%1'").arg(ui->lineEdit->text()));
	}
	else if (InfoCheck::IsChineseChar(&cha))
	{
		if (!InfoCheck::IsChineseStr(&ui->lineEdit->text()))
		{
			ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��Ҫ��ѯ�������������"), 2);

			return;
		}
		model->setFilter(QObject::tr("Name = '%1'").arg(ui->lineEdit->text()));
	}
	else
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��ѯ����ֻ��Ϊ�����Ļ�����"), 2);

		return;
	}

	model->select();
	ui->tableView->show();

	return;
}

void PhoneBook::ClickModButton()
{
	if (-1 == ui->tableView->currentIndex().row())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��ѡ����Ҫ�޸ĵ���"), 2);
		return;
	}
	QString sss = model->filter();
	AddPhoneDiag = new AddPhoneBook(ui->tableView->currentIndex().row(), model);
	AddPhoneDiag->InitModFunc();

	QObject::connect(AddPhoneDiag, SIGNAL(accepted()), this, SLOT(UpdatePhoneBook()));
}

void PhoneBook::ClickDelButton()
{
	int CurRow = 0;

	CurRow = ui->tableView->currentIndex().row();
	if (-1 == CurRow)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��ѡ��Ҫɾ��������"), 2);
		return;
	}
	QMessageBox MessageBox;
	QString MessString = QString::fromLocal8Bit("ȷ��ɾ��ѡ�е����ݣ�������");
	MessString += model->record(CurRow).value("Name").toString();
	MessageBox.setIcon(QMessageBox::Warning);
	MessageBox.setWindowTitle(QString::fromLocal8Bit("����"));
	MessageBox.setFocus();
	MessageBox.setText(MessString);
	MessageBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	MessageBox.setButtonText(QMessageBox::Ok, QString::fromLocal8Bit("ȷ��"));
	MessageBox.setButtonText(QMessageBox::Cancel, QString::fromLocal8Bit("ȡ��"));

	if (QMessageBox::Ok == MessageBox.exec())
	{
		model->removeRow(CurRow);
		UpdatePhoneBook();
	}
	else
	{
	}

	return;
}

void PhoneBook::ClearLineEdit()
{
	ui->lineEdit->clear();
}