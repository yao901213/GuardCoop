#include "ContractService.h"
#include "ErrorProc.h"

ContractService::ContractService(QWidget *parent):
	QWidget(parent)
{
	ui = new Ui_PhoneBookWidget;
	ui->setupUi(this);
	model = new QSqlTableModel;
	model->setTable("HumanResource.ContractService");
	model->setFilter("");
	ftp = new Ftp();

	InitWidget();
}

ContractService::~ContractService()
{
	delete ftp;
	delete ui;
	delete model;
}

void ContractService::InitWidget()
{
	ui->lineEdit->setPlaceholderText(QString::fromLocal8Bit("�����ͬ���Ʋ�ѯ"));
	model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("�ҷ�����"));
	model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("��ͬ����"));
	model->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("��Чʱ��"));
	model->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("��ֹʱ��"));

	model->select();
	ui->tableView->setModel(model);
	ui->tableView->setColumnHidden(0, true);
	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableView->horizontalHeader()->setHighlightSections(false);
	ui->tableView->show();

	QObject::connect(ui->pushButtonShowAll, SIGNAL(clicked()), this, SLOT(UpdateTable()));
	QObject::connect(ui->pushButtonAdd, SIGNAL(clicked()), this, SLOT(ClickAddButton()));
	QObject::connect(ui->pushButtonMod, SIGNAL(clicked()), this, SLOT(ClickModButton()));
	QObject::connect(ui->pushButtonSearch, SIGNAL(clicked()), this, SLOT(ClickSearchButton()));
	QObject::connect(ui->pushButtonDelete, SIGNAL(clicked()), this, SLOT(ClickDelButton()));
	QObject::connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(DoubleClickRow()));
	QObject::connect(ui->tableView->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(ClickTableHeader(int)));
}


void ContractService::ClickAddButton()
{
	edit = new ContractServiceEdit(model->filter(), -1, -1);
	edit->InitAddFunc();

	QObject::connect(edit, SIGNAL(accepted()), this, SLOT(UpdateTable()));
}

void ContractService::ClickModButton()
{
	if (-1 == ui->tableView->currentIndex().row())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��ѡ��Ҫ�޸ĵ�����"), 2);
		return;
	}
	edit = new ContractServiceEdit(model->filter(), ui->tableView->currentIndex().row(), Sort);
	edit->InitModFunc();

	QObject::connect(edit, SIGNAL(accepted()), this, SLOT(UpdateTable()));
}

void ContractService::ClickSearchButton()
{
	model->setFilter(tr("Name = '%1'").arg(ui->lineEdit->text()));
	model->select();
}

void ContractService::ClickDelButton()
{
	if (-1 == ui->tableView->currentIndex().row())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��ѡ��Ҫɾ��������"), 2);
		return;
	}


}

void ContractService::UpdateTable()
{
	model->setFilter("");
	model->select();

}

void ContractService::DoubleClickRow()
{
	edit = new ContractServiceEdit(model->filter(), ui->tableView->currentIndex().row(), Sort);
	edit->InitDetailFunc();

}

void ContractService::ClickTableHeader(int num)
{
	Sort = num;
	model->setSort(Sort, Qt::AscendingOrder);
	model->select();
}