#include "PropertyLoanEdit.h"
#include "GlobalVar.h"
#include <QDate>
#include <QSqlRecord>

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

	ui->lineEditBorrowerID->installEventFilter(this);
	ui->lineEditLoanStaff->installEventFilter(this);
}

void PropertyLoanEdit::ClickOkButtonAddFunc()
{


}


bool PropertyLoanEdit::eventFilter(QObject *obj, QEvent *ev)
{
	if (obj == ui->lineEditBorrowerID)
	{
		if (ev->type() == QEvent::FocusOut)
		{
			modelEmployee->setFilter(tr("ID = %1").arg(ui->lineEditBorrowerID->text()));
			modelEmployee->select();
			if (1 != modelEmployee->rowCount())
			{
				ui->labelBorrowerNote->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
				ui->labelBorrowerNote->setText(QString::fromLocal8Bit("没有该工号"));
			}
			else
			{
				QString str = modelEmployee->record(0).value("Name").toString();
				ui->lineEditBorrower->setText(str);
				ui->labelBorrowerNote->setStyleSheet(QStringLiteral("color: rgb(144, 238, 144);"));
				ui->labelBorrowerNote->setText(QString::fromLocal8Bit("查找成功"));
			}
		}
		if (ev->type() == QEvent::FocusIn)
		{
			ui->labelBorrowerNote->clear();
		}
	}

	if (ui->lineEditLoanStaff == obj)
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

	return QDialog::eventFilter(obj, ev);
}
