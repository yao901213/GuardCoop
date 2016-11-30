#include "ErrorProc.h"
#include "InfoCheck.h"
#include "ContractServiceEdit.h"
#include <QSqlRecord>
#include <QSqlError>
#include <QFileInfo>
#include <QSqlQuery>

const QString strurl = "ftp://localhost";

ContractServiceEdit::ContractServiceEdit(QString &filter, int index, int sort)
{
	model = new QSqlTableModel;
	model->setTable("HumanResource.ContractService");
	model->setFilter(filter);
	if (-1 != sort)
	{
		model->setSort(sort, Qt::AscendingOrder);
	}
	Index = index;
	ui = new Ui_ContractServiceEdit;
	ui->setupUi(this);

	ftp = new Ftp;

	InitDiag();
}

ContractServiceEdit::~ContractServiceEdit()
{
	delete ui;
	delete model;
}

void ContractServiceEdit::InitDiag()
{
	ui->comboBoxType->addItem(QString::fromLocal8Bit(""));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("��������"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("��ҵ����"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("��������"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("��������Ѳ��"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("�Ƽ�����"));

	QObject::connect(ui->pushButtonCancel, SIGNAL(clicked()), this, SLOT(reject()));

	this->setModal(true);
	this->show();
}

void ContractServiceEdit::InitAddFunc()
{
	QObject::connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(ClickOkButtonAddFunc()));

}

void ContractServiceEdit::ClickOkButtonAddFunc()
{
	if (!IsInputValid())
	{
		return;
	}

	QFileInfo fileinfo(ui->lineEditPath->text());//
	QString url = strurl + "/" + ui->comboBoxType->currentText() + "/" + ui->lineEditName->text()
		+ QString("_%1").arg(ui->dateEditStart->date().year()) + "." + fileinfo.suffix();

	ftp->SetUrl(url);
	ftp->SetLocalFile(ui->lineEditPath->text());
	ftp->Upload();

	QSqlQuery query;
	query.prepare("INSERT INTO HumanResource.ContractService(ID, Name, Type, DateofStart, DateofEnd, Url)"
		"VALUES(NEXT VALUE FOR HumanResource.ContractServiceSeq, :Name, :Type, :DateofStart, :DateofEnd, :Url)");
	query.bindValue(":Name", ui->lineEditName->text());
	query.bindValue(":Type", ui->comboBoxType->currentText());
	query.bindValue(":DateofStart", ui->dateEditStart->text());
	query.bindValue(":DateofEnd", ui->dateEditEnd->text());
	query.bindValue(":Url", url);

	if (!query.exec())
	{
		QString str = QString::fromLocal8Bit("������ݿ����") + query.lastError().text();
		ErrorProc::PopMessageBox(&str, 2);
	}
	else
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("������ݿ�ɹ�"), 0);
		this->accept();
	}
}

void ContractServiceEdit::ClickOkButtonModFunc()
{


}

bool ContractServiceEdit::IsInputValid()
{
	if (ui->lineEditName->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�������ҷ�����"), 2);
		return false;
	}

	if (ui->lineEditPath->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�������ļ���·��"), 2);
		return false;
	}

	QFileInfo fileinfo(ui->lineEditPath->text());
	if (!fileinfo.exists())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�����·������"), 2);
		return false;
	}

	QDate datestart = ui->dateEditStart->date();
	QDate dateend = ui->dateEditEnd->date();
	if (datestart.daysTo(dateend) < 0)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("������������"), 2);
		return false;
	}

	return true;
}
