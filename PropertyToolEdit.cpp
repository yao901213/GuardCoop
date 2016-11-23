#include "PropertyToolEdit.h"
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include "ErrorProc.h"

ToolEdit::ToolEdit(QString &filter, int index)
{
	ui = new Ui_DialogToolEdit;
	ui->setupUi(this);

	model = new QSqlTableModel;
	model->setTable("HumanResource.PropertyTool");
	model->setFilter(filter);
	model->select();
	Index = index;
	InitDiag();
}

ToolEdit::~ToolEdit()
{
	delete ui;
	delete model;
}


void ToolEdit::ClickOkButtonAddFunc()
{
	if (!IsInputValid())
	{
		return;
	}
	
	model->setFilter(tr("Name = '%1'").arg(ui->lineEditName->text()));
	model->select();

	if (0 != model->rowCount())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�������Ѿ�����"), 2);
		return;
	}

	QSqlQuery query;
	QString prepare = "INSERT INTO HumanResource.PropertyTool(ID, Name, Discribe, Type, Number, NumberLeft)"
		"VALUES(NEXT VALUE FOR HumanResource.PropertyToolSeq, :Name, :Discribe, :Type, :Number, :NumberLeft)";
	query.prepare(prepare);
	query.bindValue(":Name", ui->lineEditName->text());
	query.bindValue(":Type", ui->comboBoxType->currentText());
	query.bindValue(":Discribe", ui->textEditDetail->toPlainText());
	query.bindValue(":Number", ui->spinBoxNum->text());
	query.bindValue(":NumberLeft", ui->spinBoxNum->text());

	if (!query.exec())
	{
		qDebug() << query.lastError().text();
		QString str = QString::fromLocal8Bit("������ݿ����") + query.lastError().text();
		ErrorProc::PopMessageBox(&str, 2);
	}
	else
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("������ݳɹ�"), 0);
		this->accept();
	}
}

void ToolEdit::ClickOkButtonModFunc()
{
	if (!IsInputValid())
	{
		return;
	}
	
	QSqlRecord record = model->record(Index);
	int totalold = record.value("Number").toInt();
	int leftold = record.value("NumberLeft").toInt();
	if (totalold != leftold)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("����Ʒ�н�����������޸�"), 2);
		return;
	}

	QSqlTableModel modeltemp;
	modeltemp.setTable("HumanResource.PropertyTool");
	modeltemp.setFilter(tr("Name = '%1'").arg(ui->lineEditName->text()));
	modeltemp.select();
	modeltemp.submitAll();
	int i = modeltemp.rowCount();
	if (0 != modeltemp.rowCount() && record.value("Name").toString() != ui->lineEditName->text())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�޸ĵ������Ѿ����ڣ��������޸�"), 2);
		return;
	}

	int totalnum = ui->spinBoxNum->value();
	if (totalnum < totalold - leftold)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�޸ĺ������С�ڵ�ǰ�����"), 2);
		return;
	}

	record.setValue("Name", ui->lineEditName->text());
	record.setValue("Discribe", ui->textEditDetail->toPlainText());
	record.setValue("Number", ui->spinBoxNum->value());
	record.setValue("Type", ui->comboBoxType->currentText());
	record.setValue("NumberLeft", leftold - totalold + totalnum);

	model->setRecord(Index, record);
	if (!model->submitAll())
	{
		QString str = QString::fromLocal8Bit("���ݿ����") + model->lastError().text();
		ErrorProc::PopMessageBox(&str, 2);
	}
	else
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�޸����ݳɹ�"), 0);
		this->accept();
	}
}

void ToolEdit::InitDiag()
{
	QObject::connect(ui->pushButtonCancel, SIGNAL(clicked()), this, SLOT(reject()));
	ui->comboBoxType->addItem(QString::fromLocal8Bit(""));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("�Ĳ�"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("����"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("����"));
	ui->spinBoxNum->setMinimum(0);
	ui->lineEditID->setDisabled(true);

	this->show();
}

void ToolEdit::InitModFunc()
{
	QObject::connect(ui->pushButtonOK, SIGNAL(clicked()), this, SLOT(ClickOkButtonModFunc()));
	QSqlRecord record = model->record(Index);

	ui->lineEditID->setText(record.value("ID").toString());
	ui->lineEditName->setText(record.value("Name").toString());
	ui->textEditDetail->setPlainText(record.value("Discribe").toString());
	ui->comboBoxType->setCurrentText(record.value("Type").toString());
	ui->spinBoxNum->setValue(record.value("Number").toInt());

}

void ToolEdit::InitAddFunc()
{
	QObject::connect(ui->pushButtonOK, SIGNAL(clicked()), this, SLOT(ClickOkButtonAddFunc()));
}

bool ToolEdit::IsInputValid()
{
	if (ui->lineEditName->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("���Ʋ���Ϊ��"), 2);
		return false;
	}

	if (ui->spinBoxNum->value() == 0)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��������Ϊ��"), 2);
		return false;
	}

	if(ui->comboBoxType->currentText() == "")
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��ѡ������"), 2);
		return false;
	}

	return true;
}