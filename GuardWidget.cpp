#include "GuardWidget.h"
#include "ErrorProc.h"
#include "InfoCheck.h"
#include <QSqlRecord>
#include "GlobalVar.h"

GuardWidget::GuardWidget(QWidget *parent) :
	QWidget(parent)
{
	ui = new Ui_GuardWidget;
	model = new QSqlTableModel;

	lineEdit = new QLineEdit(this);
	lineEdit->setObjectName(QStringLiteral("lineEdit"));
	lineEdit->setGeometry(QRect(240, 30, 171, 20));

	ui->setupUi(this);
	InitWidget();
}

GuardWidget::~GuardWidget()
{
	delete ui;
	delete model;
	delete lineEdit;
}

void GuardWidget::ConstrainGuestAccount()
{
	ui->groupBox->setEnabled(false);
}

void GuardWidget::InitWidget()
{
	model->setTable("HumanResource.Guard");
	model->setFilter("");
	model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("����"), Qt::DisplayRole);
	model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("����"), Qt::DisplayRole);
	model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("�����ص�"), Qt::DisplayRole);
	model->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("���֤��"), Qt::DisplayRole);
	model->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("��ְ����"), Qt::DisplayRole);
	model->select();

	ui->tableView->setModel(model);
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableView->setColumnHidden(4, true);
	ui->tableView->setColumnHidden(5, true);
	ui->tableView->setColumnHidden(7, true);

	ui->tableView->resizeColumnToContents(3);

	QObject::connect(ui->pushButtonAdd, SIGNAL(clicked()), this, SLOT(ClickAddButton()));
	QObject::connect(ui->pushButtonMod, SIGNAL(clicked()), this, SLOT(ClickModButton()));
	QObject::connect(ui->pushButtonDel, SIGNAL(clicked()), this, SLOT(ClickDelButton()));
	QObject::connect(ui->pushButtonSearch, SIGNAL(clicked()), this, SLOT(ClickSearchButton()));
	QObject::connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(DouleClickRow()));

	ui->pushButtonSearch->setFocus();
	ui->pushButtonSearch->setShortcut(Qt::Key_Enter);
	ui->pushButtonSearch->setShortcut(Qt::Key_Return);
	lineEdit->setMouseTracking(true);

	ShowDbData();
}

void GuardWidget::ShowDbData()
{
	model->setFilter("");
	model->select();

	ui->tableView->show();
	InitStatusLabel();
}

void GuardWidget::ClickAddButton()
{
	int CurRowIndex = -1;

	CurRowIndex = ui->tableView->currentIndex().row();
	if (-1 == CurRowIndex)
	{
		CurRowIndex = model->rowCount();
	}
	GuardEdit = new GuardEditDiag(CurRowIndex, model);
	QObject::connect(GuardEdit, SIGNAL(rejected()), this, SLOT(ShowDbData()));
	QObject::connect(GuardEdit, SIGNAL(accepted()), this, SLOT(UpdateCompanyTable()));
	QObject::connect(GuardEdit, SIGNAL(accepted()), this, SLOT(ShowDbData()));

	GuardEdit->InitAddFunc();
}

void GuardWidget::ClickModButton()
{
	int CurRowIndex = -1;

	CurRowIndex = ui->tableView->currentIndex().row();
	if (-1 == CurRowIndex)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��ѡ����Ҫ�޸ĵ�����"), 2);
		return;
	}
	GuardEdit = new GuardEditDiag(CurRowIndex, model);
	QObject::connect(GuardEdit, SIGNAL(accepted()), this, SLOT(UpdateCompanyTable()));
	QObject::connect(GuardEdit, SIGNAL(accepted()), this, SLOT(ShowDbData()));
	QObject::connect(GuardEdit, SIGNAL(rejected()), this, SLOT(ShowDbData()));
	GuardEdit->InitModFunc();
}

void GuardWidget::ClickDelButton()
{
	int CurRow = ui->tableView->currentIndex().row();
	if (-1 == CurRow)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��ѡ��Ҫɾ��������"), 2);
		return;
	}
	QMessageBox MessageBox;
	QString MessString = QString::fromLocal8Bit("ȷ��ɾ��ѡ�е����ݣ�������%1 ���ţ�%2")
		.arg(model->record(CurRow).value("Name").toString(), model->record(CurRow).value("EmployeeID").toString());
	MessageBox.setIcon(QMessageBox::Warning);
	MessageBox.setWindowTitle(QString::fromLocal8Bit("����"));
	MessageBox.setFocus();
	MessageBox.setText(MessString);
	MessageBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	MessageBox.setButtonText(QMessageBox::Ok, QString::fromLocal8Bit("ȷ��"));
	MessageBox.setButtonText(QMessageBox::Cancel, QString::fromLocal8Bit("ȡ��"));

	if (QMessageBox::Ok == MessageBox.exec())
	{
		model->removeRow(CurRow);
	}
	else
	{
	}
	UpdateCompanyTable();
	ShowDbData();

	return;
}

void GuardWidget::ClickSearchButton()
{
	QString str = lineEdit->text();

	if (str.isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("������Ҫ��ѯ������"), 2);
		return;
	}

	QChar cha = str.at(0);
	if (str.at(0).isDigit())
	{
		if (!InfoCheck::IsDigitStr(&str))
		{
			ErrorProc::PopMessageBox(&QString::fromLocal8Bit("����Ĺ����в��ܰ�������֮����ַ�"), 2);
			return;
		}
			model->setFilter(QObject::tr("EmployeeID = %1").arg(str));
	}
	else if (InfoCheck::IsChineseChar(&cha))
	{
		if (!InfoCheck::IsChineseStr(&str))
		{
			ErrorProc::PopMessageBox(&QString::fromLocal8Bit("����������в��ܰ�������֮����ַ�"), 2);
			return;
		}
		model->setFilter(QObject::tr("Name = '%1'").arg(str));
	}
	else
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�����������Ч"), 2);
		return;
	}
	model->select();
	ui->tableView->show();
}

void GuardWidget::InitStatusLabel()
{
	model->setFilter("");
	model->select();

	ui->label->setText(QString::fromLocal8Bit("��%1λԱ����Ϣ").arg(model->rowCount()));

}

void GuardWidget::DouleClickRow()
{
	guarddetail = new GuardDetail(ui->tableView->currentIndex().row(), model);
}

void GuardWidget::UpdateCompanyTable()
{
	QSqlTableModel modelCompany;
	int CompanyNum = 0;
	int i = 0;
	QString CompanyName;
	int GuardNum = 0;
	QSqlRecord CompanyRecord;

	modelCompany.setTable("HumanResource.GuardCompany");
	modelCompany.setFilter("");
	modelCompany.select();
	CompanyNum = modelCompany.rowCount();

	for (i = 0; i < CompanyNum; i++)
	{
		CompanyRecord = modelCompany.record(i);
		CompanyName = CompanyRecord.value("Name").toString();
		model->setFilter(QObject::tr("WorkPosition = '%1'").arg(CompanyName));
		model->select();
		GuardNum = model->rowCount();
		CompanyRecord.setValue("GuardNum", GuardNum);
		modelCompany.setRecord(i, CompanyRecord);
	}
	modelCompany.submitAll();
}
