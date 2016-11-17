#include "GuardPositionEdit.h"
#include "ErrorProc.h"
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>

GuardPositionEditDiag::GuardPositionEditDiag()
{
	ui = new Ui_DialogGuardPosition;
	ui->setupUi(this);
	InitDiag();
}

GuardPositionEditDiag::~GuardPositionEditDiag()
{
	delete ui;
}

void GuardPositionEditDiag::InitDiag()
{
	model = new QSqlTableModel();
	model->setTable("HumanResource.GuardPosition");
	model->setFilter("");
	QObject::connect(ui->pushButtonCancel, SIGNAL(clicked()), this, SLOT(reject()));
}


void GuardPositionEditDiag::InitDiagAddFunc()
{
	QObject::connect(ui->pushButtonOk, SIGNAL(clicked()),
		this, SLOT(ClickOkButtonAddFunc()));
	QObject::connect(ui->pushButtonCancel, SIGNAL(clicked()),
		this, SLOT(reject()));
	ui->pushButtonCheck->setHidden(true);

	this->setModal(true);
	this->show();
}

void GuardPositionEditDiag::ClickOkButtonAddFunc()
{
	QSqlRecord record;
	int index = 0;
	if (!IsInputValid())
	{
		return;
	}

	model->setFilter("");
	model->select();
	index = model->rowCount();
	record = model->record();
	record.setValue("PositionName", ui->lineEditName->text());
	record.setValue("Address", ui->lineEditAddress->text());
	record.setValue("Longitude", ui->lineEditLongtitude->text().toDouble());
	record.setValue("Latitude", ui->lineEditLatitude->text().toDouble());

	model->insertRecord(index, record);
	qDebug() << model->lastError().text();
	if (model->submitAll())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("���ӳɹ�"), 0);
		this->accept();
	}
	else
	{
		QString str = QString::fromLocal8Bit("�������ݿ����") + model->lastError().text();
		ErrorProc::PopMessageBox(&str, 2);
	}
}

bool GuardPositionEditDiag::IsInputValid()
{
	double axis;

	axis = ui->lineEditLongtitude->text().toDouble();
	if ( axis < 115 ||axis > 117)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("����ľ��Ȳ����ĳ��з�Χ��"), 2);
		return false;
	}
	axis = ui->lineEditLatitude->text().toDouble();
	if (axis > 37 || axis < 36)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�����ά�Ȳ����ĳ��з�Χ��"), 2);
		return false;
	}
	return true;
}

void GuardPositionEditDiag::InitDiagModFunc()
{
	QObject::connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(ClickOkButtonModFunc()));
	QObject::connect(ui->pushButtonCheck, SIGNAL(clicked()), this, SLOT(ClickCheckButton()));
	this->setWindowTitle(QString::fromLocal8Bit("��������Ҫ�޸ĵĸڵ���"));
	SetDetailInfoDisable(true);

	DelFunc = false;

	this->show();
}

void GuardPositionEditDiag::InitDiagDelFunc()
{
	QObject::connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(ClickOkButtonDelFunc()));
	QObject::connect(ui->pushButtonCheck, SIGNAL(clicked()), this, SLOT(ClickCheckButton()));
	this->setWindowTitle(QString::fromLocal8Bit("��������Ҫɾ���ĸڵ���"));
	SetDetailInfoDisable(true);

	DelFunc = true;

	this->show();
}

void GuardPositionEditDiag::ClickOkButtonDelFunc()
{
	if (ui->lineEditName->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("����������"), 2);
		return;
	}
	model->setFilter(tr("PositionName = '%1'").arg(ui->lineEditName->text()));
	model->select();

	if (1 != model->rowCount())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��������ȷ������"), 2);
		return;
	}
	QSqlRecord record = model->record(0);
	record.setValue("Address", ui->lineEditAddress->text());
	record.setValue("Longitude", ui->lineEditLongtitude->text().toDouble());
	record.setValue("Latitude", ui->lineEditLatitude->text().toDouble());

	QMessageBox MessageBox;
	QString MessString = QString::fromLocal8Bit("ȷ��ɾ��ѡ�е����ݣ����ƣ�%1")
		.arg(model->record(0).value("PositionName").toString());
	MessageBox.setIcon(QMessageBox::Warning);
	MessageBox.setWindowTitle(QString::fromLocal8Bit("����"));
	MessageBox.setFocus();
	MessageBox.setText(MessString);
	MessageBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	MessageBox.setButtonText(QMessageBox::Ok, QString::fromLocal8Bit("ȷ��"));
	MessageBox.setButtonText(QMessageBox::Cancel, QString::fromLocal8Bit("ȡ��"));

	if (QMessageBox::Ok == MessageBox.exec())
	{
		model->removeRow(0);
	}

	this->accept();
}

void GuardPositionEditDiag::ClickOkButtonModFunc()
{
	if (ui->lineEditName->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("����������"), 2);
		return;
	}

	model->setFilter(tr("PositionName = '%1'").arg(ui->lineEditName->text()));
	model->select();

	if (1 != model->rowCount())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��������ȷ������"), 2);
		return;
	}

	QSqlRecord record = model->record(0);
	record.setValue("Address", ui->lineEditAddress->text());
	record.setValue("Longitude", ui->lineEditLongtitude->text().toDouble());
	record.setValue("Latitude", ui->lineEditLatitude->text().toDouble());

	model->setRecord(0, record);
	if (!model->submitAll())
	{
		QString str = QString::fromLocal8Bit("���ݿ�ִ��ʧ��") + model->lastError().text();
		ErrorProc::PopMessageBox(&str, 2);
		return;
	}
	else
	{ 
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�޸����ݿ�ɹ�"), 0);
	}
	this->accept();
	return;
}

void GuardPositionEditDiag::ClickCheckButton()
{
	QSqlRecord record;
	model->setFilter(tr("PositionName = '%1'").arg(ui->lineEditName->text()));
	QString str = model->filter();
	model->select();

	if (model->rowCount() == 0)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("���빫˾������������������"), 2);
		return;
	}

	record = model->record(0);
	ui->lineEditAddress->setText(record.value("Address").toString());
	ui->lineEditLatitude->setText(record.value("Latitude").toString());
	ui->lineEditLongtitude->setText(record.value("Longitude").toString());
	ui->lineEditName->setDisabled(true);

	if (DelFunc)
	{
		return;
	}

	SetDetailInfoDisable(false);
}

void GuardPositionEditDiag::SetDetailInfoDisable(bool disable)
{
	ui->lineEditAddress->setDisabled(disable);
	ui->lineEditLatitude->setDisabled(disable);
	ui->lineEditLongtitude->setDisabled(disable);
}