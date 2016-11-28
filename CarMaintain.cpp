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
	modelCar->select();
	QSqlRecord record;
	if (-1 != Index)
	{
		record = modelCar->record(Index);
		ui->lineEditCarID->setText(record.value("ID").toString());
	}
	
	QObject::connect(ui->pushButtonCancel, SIGNAL(clicked()), this, SLOT(reject()));
	QObject::connect(ui->pushButtonOK, SIGNAL(clicked()), this, SLOT(ClickOkButton()));
	ui->lineEditID->setDisabled(true);
	this->setModal(true);
	this->show();
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