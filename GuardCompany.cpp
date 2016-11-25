#include "GuardCompany.h"
#include "ErrorProc.h"
#include <QSqlRecord>

GuardCompany::GuardCompany(QWidget *parent) :
	QWidget(parent)
{
	ui = new Ui_TableWidget;
	comboBox = new QComboBox(this);
	comboBox->setObjectName(QStringLiteral("comboBox"));
	comboBox->setGeometry(QRect(240, 30, 171, 20));

	ui->setupUi(this);
	model = new QSqlTableModel;
	model->setTable("HumanResource.GuardCompany");
	model->setFilter("");

	InitGuardCompanyInfo();
}

GuardCompany::~GuardCompany()
{
	delete ui;
	delete model;
	delete comboBox;
}

void GuardCompany::ConstrainGuestAccount()
{
	ui->groupBox->setEnabled(false);
}

void GuardCompany::InitGuardCompanyInfo()
{
	InitComboBox();

	QObject::connect(ui->pushButtonAdd, SIGNAL(clicked()), this, SLOT(ClickAddButton()));
	QObject::connect(ui->pushButtonDel, SIGNAL(clicked()), this, SLOT(ClickDelButton()));
	QObject::connect(ui->pushButtonMod, SIGNAL(clicked()), this, SLOT(ClickModButton()));
	QObject::connect(ui->pushButtonSearch, SIGNAL(clicked()), this, SLOT(ClickSearchButton()));
	QObject::connect(ui->pushButtonShowAll, SIGNAL(clicked()), this, SLOT(UpdateTable()));

}

void GuardCompany::ShowDbData()
{
	QString strtemp = QString::fromLocal8Bit("临时");

	model->setFilter(tr("Name != '%1'").arg(strtemp));
	model->select();
	
	ui->tableView->setModel(model);
	model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("公司名"));
	model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("地址"));
	model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("联系人"));
	model->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("联系方式"));
	model->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("员工人数"));

	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableView->setSortingEnabled(true);
	ui->tableView->horizontalHeader()->setHighlightSections(false);

	ui->tableView->show();
}

void GuardCompany::ClickAddButton()
{
	edit = new GuardCompanyEditDiag(ui->tableView->currentIndex().row(), model);
	edit->InitDiagAddFunc();
	QObject::connect(edit, SIGNAL(accepted()), this, SLOT(UpdateTable()));
}

void GuardCompany::ClickSearchButton()
{
	if (comboBox->currentText().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请选择要查询的公司名称"), 2);
		return;
	}

	model->setFilter(QObject::tr("Name = '%1'").arg(comboBox->currentText()));
	model->select();
	ui->tableView->show();
}

void GuardCompany::ClickModButton()
{
	edit = new GuardCompanyEditDiag(ui->tableView->currentIndex().row(), model);
	edit->InitDiagModFunc();
	QObject::connect(edit, SIGNAL(accepted()), this, SLOT(UpdateTable()));
}

void GuardCompany::ClickDelButton()
{
	int CurRow = ui->tableView->currentIndex().row();
	if (-1 == CurRow)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请选择要删除的数据"), 2);
		return;
	}
	if (IsCompanyHasGuard())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("该公司中有雇员信息，请先修改雇员信息再删除公司信息"), 2);
		return;
	}
	QMessageBox MessageBox;
	QString MessString = QString::fromLocal8Bit("确认删除选中的数据？公司名：%1")
		.arg(model->record(CurRow).value("Name").toString());
	MessageBox.setIcon(QMessageBox::Warning);
	MessageBox.setWindowTitle(QString::fromLocal8Bit("警告"));
	MessageBox.setFocus();
	MessageBox.setText(MessString);
	MessageBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	MessageBox.setButtonText(QMessageBox::Ok, QString::fromLocal8Bit("确定"));
	MessageBox.setButtonText(QMessageBox::Cancel, QString::fromLocal8Bit("取消"));

	if (QMessageBox::Ok == MessageBox.exec())
	{
		model->removeRow(CurRow);
		ShowDbData();
	}
	else
	{
	}

	return;
}

void GuardCompany::ResetComboBox()
{
	comboBox->setCurrentIndex(0);
}

void GuardCompany::UpdateTable()
{
	QString strtemp = QString::fromLocal8Bit("临时");
	model->setFilter(tr("Name != '%1'").arg(strtemp));
	model->select();

	ui->tableView->show();
	comboBox->clear();
	InitComboBox();
}

bool GuardCompany::IsCompanyHasGuard()
{
	QSqlTableModel modeltemp;
	int CurIndex = ui->tableView->currentIndex().row();
	QString Name = model->record(CurIndex).value("Name").toString();

	modeltemp.setTable("HumanResource.Guard");
	modeltemp.setFilter(QObject::tr("WorkPosition = '%1'").arg(Name));
	modeltemp.select();
	if (0 != modeltemp.rowCount())
	{
		return true;
	}

	return false;
}

void GuardCompany::InitComboBox()
{
	int i, rowCount;
	QString CurrentName;
	QSqlTableModel modeltemp;

	modeltemp.setTable("HumanResource.GuardCompany");
	modeltemp.setFilter("");
	modeltemp.select();
	rowCount = modeltemp.rowCount();
	comboBox->setEditable(true);

	comboBox->addItem("");
	for (i = 0; i < rowCount; i++)
	{
		CurrentName = modeltemp.record(i).value("Name").toString();
		if (CurrentName == QString::fromLocal8Bit("临时"))
		{
			continue;
		}
		comboBox->addItem(CurrentName);
	}
	comboBox->setCurrentIndex(0);
}

