#include "GuardPositionEditDiag.h"
#include "ErrorProc.h"
#include <QSqlRecord>
#include <QSqlError>

GuardPositionEditDiag::GuardPositionEditDiag(QSqlTableModel *parentModel)
{
	ui = new Ui_DialogGuardPosition;
	ui->setupUi(this);
	model = parentModel;
	InitDiag();
}

GuardPositionEditDiag::~GuardPositionEditDiag()
{
	delete ui;
}

void GuardPositionEditDiag::InitDiag()
{
	QObject::connect(ui->pushButtonOk, SIGNAL(clicked()),
		this, SLOT(ClickOkButton()));
	QObject::connect(ui->pushButtonCancel, SIGNAL(clicked()),
		this, SLOT(reject()));

	this->setModal(true);
	this->show();
}

void GuardPositionEditDiag::ClickOkButton()
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
	record = model->record(index);
	record.setValue("PositionName", ui->lineEditName->text());
	record.setValue("Address", ui->lineEditAddress->text());
	record.setValue("Longitude", ui->lineEditLongtitude->text().toDouble());
	record.setValue("Latitude", ui->lineEditLatitude->text().toDouble());

	model->insertRecord(index, record);
	if (model->submitAll())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("添加成功"), 0);
		this->accept();
	}
	else
	{
		QString str = QString::fromLocal8Bit("添加数据库错误") + model->lastError().text();
		ErrorProc::PopMessageBox(&str, 2);
	}
}

bool GuardPositionEditDiag::IsInputValid()
{
	double axis;

	axis = ui->lineEditLongtitude->text().toDouble();
	if ( axis < 115 ||axis > 117)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("输入的经度不在聊城市范围内"), 2);
		return false;
	}
	axis = ui->lineEditLatitude->text().toDouble();
	if (axis > 37 || axis < 36)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("输入的维度不在聊城市范围内"), 2);
		return false;
	}
	return true;
}
