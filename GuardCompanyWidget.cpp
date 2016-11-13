#include "GuardCompanyWidget.h"
#include "ErrorProc.h"
#include <QSqlRecord>

GuardCompany::GuardCompany(QWidget *parent) :
	QWidget(parent)
{
	ui = new Ui_GuardWidget;
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
}

void GuardCompany::ShowDbData()
{
	int i = 0;
	int rowcount = 0;
	QString strtemp = QString::fromLocal8Bit("��ʱ");
	QString strnull = QString::fromLocal8Bit("����");
	QString strcurrent;

	model->setFilter("");
	model->select();
	
	ui->tableView->setModel(model);
	model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("��˾��"));
	model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("��ַ"));
	model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("��ϵ��"));
	model->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("��ϵ��ʽ"));
	model->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("Ա������"));

	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

	rowcount = model->rowCount();
	for (i = 0; i < rowcount; i++)
	{
		strcurrent = model->record(i).value("Name").toString();
		if ((strcurrent == strtemp) || (strcurrent == strnull))
		{
			ui->tableView->setRowHidden(i, true);
		}
	}

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
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��ѡ��Ҫ��ѯ�Ĺ�˾����"), 2);
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
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��ѡ��Ҫɾ��������"), 2);
		return;
	}
	if (IsCompanyHasGuard())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�ù�˾���й�Ա��Ϣ�������޸Ĺ�Ա��Ϣ��ɾ����˾��Ϣ"), 2);
		return;
	}
	QMessageBox MessageBox;
	QString MessString = QString::fromLocal8Bit("ȷ��ɾ��ѡ�е����ݣ���˾����%1")
		.arg(model->record(CurRow).value("Name").toString());
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
	model->setFilter("");
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
	model->select();
	rowCount = model->rowCount();
	comboBox->setEditable(false);

	comboBox->addItem("");
	for (i = 0; i < rowCount; i++)
	{
		CurrentName = model->record(i).value("Name").toString();
		if (CurrentName == QString::fromLocal8Bit("��ʱ")
			|| CurrentName == QString::fromLocal8Bit("����"))
		{
			continue;
		}
		comboBox->addItem(CurrentName);
	}
	comboBox->setCurrentIndex(0);
}

