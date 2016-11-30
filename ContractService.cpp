#include "ContractService.h"

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
	ui->lineEdit->setPlaceholderText(QString::fromLocal8Bit(""));
	model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("乙方名称"));
	model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("合同类型"));
	model->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("生效时间"));
	model->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("截止时间"));

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
}


void ContractService::ClickAddButton()
{
	edit = new ContractServiceEdit(model->filter(), -1, -1);
	edit->InitAddFunc();

	QObject::connect(edit, SIGNAL(accepted()), this, SLOT(UpdateTable()));
}

void ContractService::ClickModButton()
{


}

void ContractService::ClickSearchButton()
{


}

void ContractService::ClickDelButton()
{


}

void ContractService::UpdateTable()
{
	model->setFilter("");
	model->select();

}

void ContractService::DoubleClickRow()
{


}