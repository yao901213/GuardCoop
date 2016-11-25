#include "PropertyLoanEdit.h"
#include "GlobalVar.h"
#include <QDate>
#include <QSqlRecord>
#include "ErrorProc.h"
#include "PubFunc.h"
#include <QSqlQuery>
#include <QSqlError>

PropertyLoanEdit::PropertyLoanEdit(QString &filter, int index)
{
	model = new QSqlTableModel;
	modelEmployee = new QSqlTableModel;
	modelTool = new QSqlTableModel;


	ui = new Ui_PropertyLoanEdit;

	model->setTable("HumanResource.PropertyLoan");
	model->setFilter(filter);

	modelEmployee->setTable("HumanResource.Property");
	modelEmployee->setFilter("");

	modelTool->setTable("HumanResource.PropertyTool");
	modelTool->setFilter("");
	Index = index;
	ui->setupUi(this);
	InitDiag();
}

PropertyLoanEdit::~PropertyLoanEdit()
{
	delete model;
	delete ui;
	delete modelEmployee;
	delete modelTool;
}

void PropertyLoanEdit::InitDiagAddfunc()
{
	QObject::connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(ClickOkButtonAddFunc()));
	ui->dateEditBorrow->setDate(QDate::currentDate());
	ui->dateEditBorrow->setDisabled(true);
	ui->lineEditAdmin->setText(AdminAccount);
	ui->lineEditAdmin->setDisabled(true);
	ui->comboBoxIntact->setDisabled(true);
	ui->dateEditReturn->clear();
	ui->dateEditReturn->setDisabled(true);
	ui->labelLeft->setText(0);
	
	ui->lineEditLoanStaff->installEventFilter(this);
}

void PropertyLoanEdit::InitDiagModFunc()
{
	QObject::connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(ClickOkButtonModFunc()));
	model->select();
	QSqlRecord record = model->record(Index);
	ui->lineEditID->setText(record.value("ID").toString());
	ui->lineEditBorrower->setText(record.value("Borrower").toString());
	ui->lineEditBorrowerID->setText(record.value("BorrowerID").toString());
	ui->lineEditLoanStaff->setText(record.value("LoanStaff").toString());
	ui->dateEditBorrow->setDate(record.value("DateofBorrow").toDate());
	ui->spinBoxNumber->setValue(record.value("StaffNumber").toInt());
	ui->textEditRemark->setPlainText(record.value("Remark").toString());
	ui->lineEditAdmin->setText(record.value("Admin").toString());
	ui->lineEditID->setDisabled(true);
	ui->lineEditLoanStaff->setDisabled(true);
	ui->spinBoxNumber->setDisabled(true);
	ui->dateEditBorrow->setDisabled(true);
	ui->dateEditReturn->setDisabled(true);
	ui->lineEditAdmin->setDisabled(true);
	ui->comboBoxIntact->setDisabled(true);
	
	this->setWindowTitle(QString::fromLocal8Bit("ת��"));
}

void PropertyLoanEdit::InitDiagDelFunc()
{
	QObject::connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(ClickOkButtonDelFunc()));
	model->select();
	QSqlRecord record = model->record(Index);
	ui->lineEditID->setText(record.value("ID").toString());
	ui->lineEditBorrower->setText(record.value("Borrower").toString());
	ui->lineEditBorrowerID->setText(record.value("BorrowerID").toString());
	ui->lineEditLoanStaff->setText(record.value("LoanStaff").toString());
	ui->dateEditBorrow->setDate(record.value("DateofBorrow").toDate());
	ui->spinBoxNumber->setValue(record.value("StaffNumber").toInt());
	ui->textEditRemark->setPlainText(record.value("Remark").toString());
	ui->lineEditAdmin->setText(record.value("Admin").toString());
	ui->lineEditID->setDisabled(true);
	ui->lineEditLoanStaff->setDisabled(true);
	ui->spinBoxNumber->setDisabled(true);
	ui->dateEditBorrow->setDisabled(true);
	ui->lineEditAdmin->setDisabled(true);
	ui->lineEditBorrower->setDisabled(true);
	ui->lineEditBorrowerID->setDisabled(true);
	ui->dateEditReturn->setDate(QDate::currentDate());

	this->setWindowTitle(QString::fromLocal8Bit("�黹"));
}

void PropertyLoanEdit::InitDiag()
{
	this->show();
	ui->lineEditID->setDisabled(true);
	ui->comboBoxIntact->addItem(QString::fromLocal8Bit("��"));
	ui->comboBoxIntact->addItem(QString::fromLocal8Bit("��"));

	QObject::connect(ui->pushButtonCancel, SIGNAL(clicked()), this, SLOT(reject()));
	QObject::connect(ui->pushButtonCheckBorrower, SIGNAL(clicked()), this, SLOT(ClickCheckButton()));

	ui->lineEditBorrowerID->installEventFilter(this);
}

void PropertyLoanEdit::ClickOkButtonAddFunc()
{
	if (!IsInputValid())
	{
		return;
	}

	QSqlQuery query;
	query.prepare("INSERT INTO HumanResource.PropertyLoan(ID, Borrower, BorrowerID, LoanStaff, StaffNumber, Admin, DateofBorrow, ReturnFlag, Remark)"
		"VALUES(NEXT VALUE FOR HumanResource.PropertyLoanSeq, :Borrower, :BorrowerID, :LoanStaff, :StaffNumber, :Admin, :DateofBorrow, :ReturnFlag, :Remark)");
	query.bindValue(":Borrower", ui->lineEditBorrower->text());
	query.bindValue(":BorrowerID", ui->lineEditBorrowerID->text());
	query.bindValue(":LoanStaff", ui->lineEditLoanStaff->text());
	query.bindValue(":StaffNumber", ui->spinBoxNumber->value());
	query.bindValue(":Admin", ui->lineEditAdmin->text());
	query.bindValue(":DateofBorrow", ui->dateEditBorrow->text());
	query.bindValue(":ReturnFlag", QString::fromLocal8Bit("��"));
	query.bindValue(":Remark", ui->textEditRemark->toPlainText());

	if (!query.exec())
	{
		QString str = QString::fromLocal8Bit("������ݿ����") + query.lastError().text();
		ErrorProc::PopMessageBox(&str, 2);
	}
	else
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("������ݿ�ɹ�"), 0);
		ChangeToolTable();
		ChangeEmployeeTable();
		this->accept();
	}
}

void PropertyLoanEdit::ClickOkButtonModFunc()
{
	int OriginalBorrowerID;

	model->setFilter(tr("ID = %1").arg(ui->lineEditID->text()));
	model->select();
	QSqlRecord record = model->record(0);
	OriginalBorrowerID = record.value("BorrowerID").toInt();

	if (!IsInputEmpty())
	{
		return;
	}

	modelEmployee->setFilter(tr("Name = '%1'").arg(ui->lineEditBorrower->text()));
	modelEmployee->select();
	if (0 == modelEmployee->rowCount())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("����Ľ���������������"), 2);
		return;
	}

	modelEmployee->setFilter(tr("ID = %1").arg(ui->lineEditBorrowerID->text()));
	modelEmployee->select();
	if (0 == modelEmployee->rowCount())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("����Ľ����˹��Ų�����"), 2);
		return;
	}

	record.setValue("Borrower", ui->lineEditBorrower->text());
	record.setValue("BorrowerID", ui->lineEditBorrowerID->text());
	model->setRecord(0, record);
	model->submitAll();

	modelEmployee->setFilter(tr("ID = %1").arg(ui->lineEditBorrowerID->text()));
	record = modelEmployee->record(0);
	record.setValue("Loan", QString::fromLocal8Bit("��"));
	modelEmployee->setRecord(0, record);
	modelEmployee->submitAll();

	model->setFilter(tr("BorrowerID = %1").arg(OriginalBorrowerID));
	model->select();
	if (0 != model->rowCount())
	{
		this->accept();
		return;
	}

	modelEmployee->setFilter(tr("ID = %1").arg(OriginalBorrowerID));
	modelEmployee->select();
	record = modelEmployee->record(0);
	record.setValue("Loan", QString::fromLocal8Bit("��"));
	modelEmployee->setRecord(0, record);
	modelEmployee->submitAll();

	this->accept();
}

void PropertyLoanEdit::ChangeEmployeeTable()
{
	QSqlQuery query;
	QString prepare = tr("UPDATE HumanResource.Property SET Loan = '%1' WHERE ID = %2").
		arg(QString::fromLocal8Bit("��")).arg(ui->lineEditBorrowerID->text());
	query.prepare(prepare);
	if (!query.exec())
	{
		QString str = QString::fromLocal8Bit("�޸�Ա����Ϣ�����") + query.lastError().text();
		ErrorProc::PopMessageBox(&str, 2);
	}
}

void PropertyLoanEdit::ChangeToolTable()
{
	modelTool->setFilter(tr("Name = '%1'").arg(ui->lineEditLoanStaff->text()));
	modelTool->select();
	QSqlRecord record = modelTool->record(0);
	QSqlQuery query;
	QString prepare = tr("UPDATE HumanResource.PropertyTool SET NumberLeft = %1 WHERE Name = '%2'").
		arg(record.value("NumberLeft").toInt() - ui->spinBoxNumber->value()).arg(ui->lineEditLoanStaff->text());
	query.prepare(prepare);
	if (!query.exec())
	{
		QString str = QString::fromLocal8Bit("�޸Ĺ��߱����") + query.lastError().text();
		ErrorProc::PopMessageBox(&str, 2);
	}
}

void PropertyLoanEdit::ClickCheckButton()
{
	if (ui->lineEditBorrower->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("������Ա����"), 2);
		return;
	}
	choice = new PropertyEmployeeSelect(tr("Name = '%1'").arg(ui->lineEditBorrower->text()));
	QObject::connect(choice, SIGNAL(ChoiceID(int)), this, SLOT(SetBorrowerLineEdit(int)));
}

bool PropertyLoanEdit::eventFilter(QObject *obj, QEvent *ev)
{
	if (obj == ui->lineEditBorrowerID)
	{
		LineEditBorrowerIDFilter(ev);
	}

	if (ui->lineEditLoanStaff == obj)
	{
		LineEditLoanStaffFilter(ev);
	}

	return QDialog::eventFilter(obj, ev);
}

void PropertyLoanEdit::LineEditBorrowerIDFilter(QEvent *ev)
{
	if (ev->type() == QEvent::FocusOut)
	{
		modelEmployee->setFilter(tr("ID = %1").arg(ui->lineEditBorrowerID->text()));
		modelEmployee->select();
		if (1 != modelEmployee->rowCount())
		{
			UiEmbellish::RedText(ui->labelBorrowerIDNote);
			ui->labelBorrowerIDNote->setText(QString::fromLocal8Bit("û�иù���"));
		}
		else
		{
			QString str = modelEmployee->record(0).value("Name").toString();
			ui->lineEditBorrower->setText(str);
			UiEmbellish::GreenText(ui->labelBorrowerIDNote);
			ui->labelBorrowerIDNote->setText(QString::fromLocal8Bit("���ҳɹ�"));
		}
	}
	if (ev->type() == QEvent::FocusIn)
	{
		ui->labelBorrowerIDNote->clear();
	}
}

void PropertyLoanEdit::LineEditLoanStaffFilter(QEvent *ev)
{
	if (ev->type() == QEvent::FocusOut)
	{
		modelTool->setFilter(tr("Name = '%1'").arg(ui->lineEditLoanStaff->text()));
		modelTool->select();
		if (1 != modelTool->rowCount())
		{
			UiEmbellish::RedText(ui->labelLoanStaffNote);
			ui->labelLoanStaffNote->setText(QString::fromLocal8Bit("û�иù�������"));
		}
		else
		{
			QString str = modelTool->record(0).value("NumberLeft").toString();
			UiEmbellish::GreenText(ui->labelLoanStaffNote);
			ui->labelLoanStaffNote->setText(QString::fromLocal8Bit("���ҳɹ�"));
			ui->labelLeft->setText(str);
		}
	}
	if (ev->type() == QEvent::FocusIn)
	{
		ui->labelLoanStaffNote->clear();
		ui->labelLeft->setText(0);
	}
}

void PropertyLoanEdit::SetBorrowerLineEdit(int value)
{
	modelEmployee->setFilter(tr("Name = '%1'").arg(ui->lineEditBorrower->text()));
	modelEmployee->select();
	QSqlRecord record = modelEmployee->record(value);
	QString str = record.value("ID").toString();
	ui->lineEditBorrowerID->setText(str);
	ui->labelBorrowerIDNote->setText(QString::fromLocal8Bit("���ҳɹ�"));
	UiEmbellish::GreenText(ui->labelBorrowerIDNote);
}

bool PropertyLoanEdit::IsInputEmpty()
{
	if (ui->lineEditBorrowerID->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("����������˹���"), 2);
		return false;
	}

	if (ui->lineEditBorrower->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("���������������"), 2);
		return false;
	}

	if (0 == ui->spinBoxNumber->value())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("������Ʒ��������Ϊ0"), 2);
		return false;
	}

	if (ui->lineEditLoanStaff->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�����������Ʒ����"), 2);
		return false;
	}

	if (ui->lineEditAdmin->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("���������Ա�˺�"), 2);
		return false;
	}
	return true;
}


bool PropertyLoanEdit::IsInputValid()
{
	if (!IsInputEmpty())
	{
		return false;
	}
	modelEmployee->setFilter(tr("ID = %1").arg(ui->lineEditBorrowerID->text()));
	modelEmployee->select();
	if (0 == modelEmployee->rowCount())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�����˹����������"), 2);
		return false;
	}

	modelEmployee->setFilter(tr("Name = '%1'").arg(ui->lineEditBorrower->text()));
	modelEmployee->select();
	if (0 == modelEmployee->rowCount())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�����������������"), 2);
		return false;
	}

	modelTool->setFilter(tr("Name = '%1'").arg(ui->lineEditLoanStaff->text()));
	modelTool->select();
	if (0 == modelTool->rowCount())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�����������������"), 2);
		return false;
	}
	QSqlRecord record = modelTool->record(0);
	if (ui->spinBoxNumber->value() > record.value("NumberLeft").toInt())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("������Ʒ��������"), 2);
		return false;
	}

	return true;
}

void PropertyLoanEdit::ClickOkButtonDelFunc()
{
	if (!IsInputValidDelFunc())
	{
		return;
	}
	model->setFilter(tr("ID = %1").arg(ui->lineEditID->text()));
	model->select();

	QSqlRecord record = model->record(0);
	record.setValue("DateofReturn", ui->dateEditReturn->text());
	record.setValue("Remark", ui->textEditRemark->toPlainText());
	record.setValue("Intact", ui->comboBoxIntact->currentText());
	record.setValue("ReturnFlag", QString::fromLocal8Bit("��"));
	model->setRecord(0, record);
	model->submitAll();

	modelTool->setFilter(tr("Name = '%1'").arg(ui->lineEditLoanStaff->text()));
	modelTool->select();
	record = modelTool->record(0);
	int oldNumberLeft = record.value("NumberLeft").toInt();
	record.setValue("NumberLeft", oldNumberLeft + ui->spinBoxNumber->value());
	modelTool->setRecord(0, record);
	modelTool->submitAll();

	model->setFilter(tr("BorrowerID = %1 AND ReturnFlag = '%2'").arg(ui->lineEditBorrowerID->text())
	.arg(QString::fromLocal8Bit("��")));
	model->select();
	if (0 != model->rowCount())
	{
		this->accept();
		return;
	}
	modelEmployee->setFilter(tr("ID = %1").arg(ui->lineEditBorrowerID->text()));
	modelEmployee->select();
	record = modelEmployee->record(0);
	record.setValue("Loan", QString::fromLocal8Bit("��"));
	modelEmployee->setRecord(0, record);
	modelEmployee->submitAll();
	this->accept();
}

bool PropertyLoanEdit::IsInputValidDelFunc()
{
	if (ui->dateEditBorrow->date().daysTo(ui->dateEditReturn->date()) < 0)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�黹�����ڽ�������֮ǰ"), 2);
		return false;
	}

	return true;
}