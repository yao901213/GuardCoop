#include "CarMaintain.h"
#include <QSqlRecord>
#include <QSqlError>
#include <QSqlQuery>
#include "ErrorProc.h"

CarMaintain::CarMaintain(QString &filter, int index, int sort)
{
	ui = new Ui_CarMaintain;
	ui->setupUi(this);

	Index = index;
	model = new QSqlTableModel;
	model->setTable("HumanResource.CarMaintain");

	modelCar = new QSqlTableModel;
	modelCar->setTable("HumanResource.Car");
	modelCar->setFilter(filter);
	if (-1 != sort)
	{
		modelCar->setSort(sort, Qt::AscendingOrder);
	}
	InitDiag();
}

CarMaintain::~CarMaintain()
{
	delete model;
	delete modelCar;
	delete ui;
}

void CarMaintain::InitDiag()
{
	QObject::connect(ui->pushButtonCancel, SIGNAL(clicked()), this, SLOT(reject()));
	ui->lineEditID->setDisabled(true);
	this->setModal(true);
	this->show();
}

void CarMaintain::InitAddFunc()
{
	modelCar->select();
	QSqlRecord record;
	if (-1 != Index)
	{
		record = modelCar->record(Index);
		ui->lineEditCarID->setText(record.value("ID").toString());
	}
	QObject::connect(ui->pushButtonOK, SIGNAL(clicked()), this, SLOT(ClickOkButton()));

}

void CarMaintain::InitDetailFunc(QString &carid)
{
	QObject::connect(ui->pushButtonOK, SIGNAL(clicked()), this, SLOT(reject()));

	model->setFilter(tr("CarID = '%1'").arg(carid));
	model->select();
	QSqlRecord record = model->record(Index);
	ui->lineEditCarID->setText(carid);
	ui->lineEditCarID->setDisabled(true);
	ui->lineEditID->setText(record.value("ID").toString());
	ui->lineEditID->setDisabled(true);
	ui->lineEditType->setText(record.value("Type").toString());
	ui->lineEditType->setDisabled(true);
	ui->lineEditStation->setText(record.value("Station").toString());
	ui->lineEditStation->setDisabled(true);
	ui->lineEditPrice->setText(record.value("Price").toString());
	ui->lineEditPrice->setDisabled(true);
	ui->lineEditDistance->setText(record.value("Distance").toString());
	ui->lineEditDistance->setDisabled(true);
	ui->lineEditInCharge->setText(record.value("InCharge").toString());
	ui->lineEditInCharge->setDisabled(true);
	ui->dateEdit->setDate(record.value("Date").toDate());
	ui->dateEdit->setDisabled(true);
	ui->textEdit->setText(record.value("Remark").toString());
	ui->textEdit->setDisabled(true);
}

void CarMaintain::ClickOkButton()
{
	if (!IsInputValid())
	{
		return;
	}

	QSqlQuery query;
	query.prepare("INSERT INTO HumanResource.CarMaintain(ID, CarID, Type, Price, Station, Date, Distance, InCharge, Remark)"
		"VALUES(NEXT VALUE FOR HumanResource.CarMaintainSeq, :CarID, :Type, :Price, :Station, :Date, :Distance, :InCharge, :Remark)");
	query.bindValue(":CarID", ui->lineEditCarID->text());
	query.bindValue(":Type", ui->lineEditType->text());
	query.bindValue(":Price", ui->lineEditPrice->text());
	query.bindValue(":Station", ui->lineEditStation->text());
	query.bindValue(":Date", ui->dateEdit->text());
	query.bindValue(":Distance", ui->lineEditDistance->text());
	query.bindValue(":InCharge", ui->lineEditInCharge->text());
	query.bindValue(":Remark", ui->textEdit->toPlainText());

	if (!query.exec())
	{
		QString str = QString::fromLocal8Bit("数据库错误") + query.lastError().text();
		ErrorProc::PopMessageBox(&str, 2);
	}
	else
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("添加数据库成功"), 0);
		this->accept();
	}
}

bool CarMaintain::IsInputValid()
{
	if (!IsCarIDExist())
	{
		return false;
	}
	if (ui->lineEditInCharge->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请输入责任人"), 2);
		return false;
	}

	if (ui->lineEditPrice->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请输入价格"), 2);
		return false;
	}

	if (ui->lineEditStation->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请输入保养地点"), 2);
		return false;
	}

	if (ui->lineEditType->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请输入保养类型"), 2);
		return false;
	}

	return true;
}

bool CarMaintain::IsCarIDExist()
{
	if (ui->lineEditCarID->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请输入车牌号"), 2);
		return false;
	}

	modelCar->setFilter(tr("ID = '%1'").arg(ui->lineEditCarID->text()));
	modelCar->select();
	if (1 != modelCar->rowCount())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("没有该车牌号信息"), 2);
		return false;
	}

	return true;
}

void CarMaintain::InitAddFromDetail(QString &carid)
{
	ui->lineEditCarID->setText(carid);
	ui->lineEditCarID->setDisabled(true);
	QObject::connect(ui->pushButtonOK, SIGNAL(clicked()), this, SLOT(ClickOkButton()));
}