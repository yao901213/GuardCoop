#include "PropertyLoanEdit.h"
#include "GlobalVar.h"
#include <QDate>
#include <QSqlRecord>
#include "ErrorProc.h"
#include "PubFunc.h"

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
	InitDiagAddfunc();
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
}


void PropertyLoanEdit::InitDiag()
{
	this->show();
	ui->lineEditID->setDisabled(true);
	ui->comboBoxIntact->addItem(QString::fromLocal8Bit("是"));
	ui->comboBoxIntact->addItem(QString::fromLocal8Bit("否"));

	QObject::connect(ui->pushButtonCancel, SIGNAL(clicked()), this, SLOT(reject()));
	QObject::connect(ui->pushButtonCheckBorrower, SIGNAL(clicked()), this, SLOT(ClickCheckButton()));
	

	ui->lineEditBorrowerID->installEventFilter(this);
	ui->lineEditLoanStaff->installEventFilter(this);
}

void PropertyLoanEdit::ClickOkButtonAddFunc()
{


}

void PropertyLoanEdit::ClickCheckButton()
{
	if (ui->lineEditBorrower->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请输入员工名"), 2);
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
			ui->labelBorrowerIDNote->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
			ui->labelBorrowerIDNote->setText(QString::fromLocal8Bit("没有该工号"));
		}
		else
		{
			QString str = modelEmployee->record(0).value("Name").toString();
			ui->lineEditBorrower->setText(str);
			ui->labelBorrowerIDNote->setStyleSheet(QStringLiteral("color: rgb(144, 238, 144);"));
			ui->labelBorrowerIDNote->setText(QString::fromLocal8Bit("查找成功"));
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
			ui->labelLoanStaffNote->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
			ui->labelLoanStaffNote->setText(QString::fromLocal8Bit("没有该工具名称"));
		}
		else
		{
			QString str = modelTool->record(0).value("NumberLeft").toString();
			ui->labelLoanStaffNote->setStyleSheet(QStringLiteral("color: rgb(144, 238, 144);"));
			ui->labelLoanStaffNote->setText(QString::fromLocal8Bit("查找成功"));
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
	ui->lineEditBorrowerID->setText(QString::fromLocal8Bit("查找成功"));

}
