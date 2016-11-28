#include <QSqlQuery>
#include "CarInsure.h"
#include "ErrorProc.h"
#include <QSqlError>
#include <QSqlRecord>

CarInsure::CarInsure(QString &filter, int index, int sort)
{
	ui = new Ui_CarInsure;
	ui->setupUi(this);
	Filter = filter;
	model = new QSqlTableModel;
	model->setTable("HumanResource.CarInsure");
	Index = index;
	Sort = sort;
	InitDiag();
}

CarInsure::~CarInsure()
{
	delete ui;
	delete model;
}

void CarInsure::InitDiag()
{
	if (-1 != Index)
	{
		QSqlTableModel modelCar;
		modelCar.setTable("HumanResource.Car");
		modelCar.setFilter(Filter);
		if (-1 != Sort)
		{
			modelCar.setSort(Sort, Qt::AscendingOrder);
		}
		modelCar.select();
		QSqlRecord record = modelCar.record(Index);
		ui->lineEditCarID->setText(record.value("ID").toString());
	}
	ui->comboBoxCompany->setEditable(true);
	ui->comboBoxType->setEditable(true);
	ui->lineEditID->setDisabled(true);

	QObject::connect(ui->pushButtonCancel, SIGNAL(clicked()), this, SLOT(reject()));
	InitComboBoxs();
	this->setModal(true);
	this->show();
}

void CarInsure::InitAddFunc()
{
	QObject::connect(ui->pushButtonOK, SIGNAL(clicked()), this, SLOT(ClickOkButton()));

}

void CarInsure::InitDetailFunc()
{
	model->setFilter(tr("CarID = '%1'").arg(ui->lineEditCarID->text()));
	model->select();
	QSqlRecord record = model->record(0);
	ui->lineEditID->setText(record.value("ID").toString());
	ui->lineEditID->setDisabled(true);
	ui->lineEditCarID->setDisabled(true);
	ui->lineEditInCharge->setText(record.value("InCharge").toString());
	ui->lineEditInCharge->setDisabled(true);
	ui->lineEditPrice->setText(record.value("Price").toString());
	ui->lineEditPrice->setDisabled(true);
	ui->comboBoxCompany->setCurrentText(record.value("InsureCompany").toString());
	ui->comboBoxCompany->setDisabled(true);
	ui->comboBoxType->setCurrentText(record.value("Type").toString());
	ui->comboBoxType->setDisabled(true);
	ui->dateEditEnd->setDate(record.value("DateofEnd").toDate());
	ui->dateEditEnd->setDisabled(true);
	ui->dateEditStart->setDate(record.value("DateofStart").toDate());
	ui->dateEditStart->setDisabled(true);
	ui->textEdit->setText(record.value("Remark").toString());
	ui->textEdit->setDisabled(true);
}


void CarInsure::InitComboBoxs()
{
	ui->comboBoxCompany->addItem("");
	ui->comboBoxCompany->addItem(QString::fromLocal8Bit("�й�����"));
	ui->comboBoxCompany->addItem(QString::fromLocal8Bit("̫ƽ��"));
	ui->comboBoxCompany->addItem(QString::fromLocal8Bit("ƽ������"));

	ui->comboBoxType->addItem("");
	ui->comboBoxType->addItem(QString::fromLocal8Bit("��ǿ��"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("������������"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("������"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("������"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("������"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("������"));
}

void CarInsure::ClickOkButton()
{
	QSqlQuery query;
	query.prepare("INSERT INTO HumanResource.CarInsure(ID, CarID, Type, Price, InsureCompany, DateofStart, DateofEnd, InCharge, Remark)"
		"VALUES(NEXT VALUE FOR HumanResource.CarInsureSeq, :CarID, :Type, :Price, :InsureCompany, :DateofStart, :DateofEnd, :InCharge, :Remark)");
	query.bindValue(":CarID", ui->lineEditCarID->text());
	query.bindValue(":Type", ui->comboBoxType->currentText());
	query.bindValue(":Price", ui->lineEditPrice->text());
	query.bindValue(":InsureCompany", ui->comboBoxCompany->currentText());
	query.bindValue(":DateofStart", ui->dateEditStart->text());
	query.bindValue(":DateofEnd", ui->dateEditEnd->text());
	query.bindValue(":InCharge", ui->lineEditInCharge->text());
	query.bindValue(":Remark", ui->textEdit->toPlainText());

	if (!query.exec())
	{
		QString str = QString::fromLocal8Bit("���ݿ����") + query.lastError().text();
		ErrorProc::PopMessageBox(&str, 2);
	}
	else
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("������ݿ�ɹ�"), 0);
		this->accept();
	}
}
