#include "ErrorProc.h"
#include "CarEdit.h"
#include <QSqlQuery>
#include <QSqlError>
#include "InfoCheck.h"
#include <QSqlRecord>

CarEdit::CarEdit(QString &filter, int index)
{
	ui = new Ui_CarEdit;
	ui->setupUi(this);
	Index = index;
	model = new QSqlTableModel;
	model->setTable("HumanResource.Car");
	model->setFilter(filter);
	model->select();
	InitDiag();
}

CarEdit::~CarEdit()
{
	delete ui;
	delete model;
}

void CarEdit::InitDiag()
{
	QObject::connect(ui->pushButtonCancel, SIGNAL(clicked()), this, SLOT(reject()));

	ui->comboBoxPerform->addItem(QString::fromLocal8Bit("良好"));
	ui->comboBoxPerform->addItem(QString::fromLocal8Bit("一般"));
	ui->comboBoxPerform->addItem(QString::fromLocal8Bit("维修"));

	ui->comboBoxCondition->addItem(QString::fromLocal8Bit("使用"));
	ui->comboBoxCondition->addItem(QString::fromLocal8Bit("保管"));
	
	ui->comboBoxType->addItem(QString::fromLocal8Bit("轿车"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("SUV"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("MPV"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("中巴"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("大巴"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("其他"));

	this->setModal(true);
	this->show();
}

void CarEdit::InitDiagAddFunc()
{
	QObject::connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(ClickOkButtonAddFunc()));
	ui->lineEditID->setText(QString::fromLocal8Bit("鲁P"));
}

void CarEdit::InitDiagModFunc()
{
	QObject::connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(ClickOkButtonModFunc()));

	model->select();
	QSqlRecord record = model->record(Index);
	ui->lineEditID->setText(record.value("ID").toString());
	ui->lineEditBrand->setText(record.value("Brand").toString());
	ui->lineEditKeeper->setText(record.value("Keeper").toString());
	ui->comboBoxType->setCurrentText(record.value("Type").toString());
	ui->comboBoxPerform->setCurrentText(record.value("Perform").toString());
	ui->comboBoxCondition->setCurrentText(record.value("Condition").toString());
	ui->dateEdit->setDate(record.value("DateofBuy").toDate());
	ui->textEdit->setText(record.value("Remark").toString());

	ui->lineEditID->setDisabled(true);
	ui->lineEditBrand->setDisabled(true);
	ui->comboBoxType->setDisabled(true);
	ui->dateEdit->setDisabled(true);
}

void CarEdit::ClickOkButtonAddFunc()
{
	if (!IsInputValid())
	{
		return;
	}

	if (IsCarIDExist())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("当前车牌号已经存在"), 2);
		return;
	}

	if (!InfoCheck::IsCarIDValid(ui->lineEditID->text()))
	{
		return;
	}

	QSqlQuery query;
	QString prepare = "INSERT INTO HumanResource.Car(ID, Type, Brand, Keeper, DateofBuy, Condition, Perform, Remark)"
		"VALUES(:ID, :Type, :Brand, :Keeper, :DateofBuy, :Condition, :Perform, :Remark)";
	query.prepare(prepare);
	query.bindValue(":ID", ui->lineEditID->text());
	query.bindValue(":Type", ui->comboBoxType->currentText());
	query.bindValue(":Brand", ui->lineEditBrand->text());
	query.bindValue(":Keeper", ui->lineEditKeeper->text());
	query.bindValue(":DateofBuy", ui->dateEdit->text());
	query.bindValue(":Condition", ui->comboBoxCondition->currentText());
	query.bindValue(":Perform", ui->comboBoxPerform->currentText());
	query.bindValue(":Remark", ui->textEdit->toPlainText());

	if (!query.exec())
	{
		QString str = QString::fromLocal8Bit("添加数据库错误") + query.lastError().text();
		ErrorProc::PopMessageBox(&str, 2);
	}
	else
	{
		this->accept();
	}
}

void CarEdit::ClickOkButtonModFunc()
{
	model->select();
	QSqlRecord record = model->record(Index);

	record.setValue("Keeper", ui->lineEditKeeper->text());
	record.setValue("Condition", ui->comboBoxCondition->currentText());
	record.setValue("Perform", ui->comboBoxPerform->currentText());
	record.setValue("Remark", ui->textEdit->toPlainText());

	model->setRecord(Index, record);
	if (!model->submitAll())
	{
		QString str = QString::fromLocal8Bit("修改数据库错误") + model->lastError().text();
		ErrorProc::PopMessageBox(&str, 2);
		return;
	}
	else
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("修改数据库成功"), 0);
		this->accept();
	}
}

bool CarEdit::IsCarIDExist()
{
	model->setFilter(tr("ID = '%1'").arg(ui->lineEditID->text()));
	model->select();
	if (0 == model->rowCount())
	{
		return false;
	}

	return true;
}

bool CarEdit::IsInputValid()
{
	if (ui->lineEditID->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请输入车牌号"), 2);
		return false;
	}

	if (ui->lineEditBrand->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请输入车辆型号"), 2);
		return false;
	}

	if (ui->lineEditKeeper->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请输入持有者姓名"), 2);
		return false;
	}

	return true;
}

