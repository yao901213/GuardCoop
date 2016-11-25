#include "ErrorProc.h"
#include "CarEdit.h"
#include <QSqlQuery>
#include <QSqlError>

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

	ui->comboBoxPerform->addItem(QString::fromLocal8Bit("����"));
	ui->comboBoxPerform->addItem(QString::fromLocal8Bit("һ��"));
	ui->comboBoxPerform->addItem(QString::fromLocal8Bit("ά��"));

	ui->comboBoxCondition->addItem(QString::fromLocal8Bit("ʹ��"));
	ui->comboBoxCondition->addItem(QString::fromLocal8Bit("����"));
	
	ui->comboBoxType->addItem(QString::fromLocal8Bit("�γ�"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("SUV"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("MPV"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("�а�"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("���"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("����"));

	this->setModal(true);
	this->show();
}

void CarEdit::InitDiagAddFunc()
{
	QObject::connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(ClickOkButtonAddFunc()));
	ui->lineEditID->setText(QString::fromLocal8Bit("³P"));
}

void CarEdit::InitDiagModFunc()
{


}

void CarEdit::ClickOkButtonAddFunc()
{
	if (!IsInputValid())
	{
		return;
	}

	if (IsCarIDExist())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��ǰ���ƺ��Ѿ�����"), 2);
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
		QString str = QString::fromLocal8Bit("������ݿ����") + query.lastError().text();
		ErrorProc::PopMessageBox(&str, 2);
	}
	else
	{
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
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�����복�ƺ�"), 2);
		return false;
	}

	if (ui->lineEditBrand->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�����복���ͺ�"), 2);
		return false;
	}

	if (ui->lineEditKeeper->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("���������������"), 2);
		return false;
	}

	return true;
}

