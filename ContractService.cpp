#include "ContractService.h"

ContractService::ContractService(QWidget *parent):
	QWidget(parent)
{
	ui = new Ui_TableWidget;
	ui->setupUi(this);
	model = new QSqlTableModel;
	model->setTable("HumanResource.ContractService");
	model->setFilter("");
	ftp = new Ftp();

	lineEdit = new QLineEdit(this);
	lineEdit->setObjectName(QStringLiteral("lineEdit"));
	lineEdit->setGeometry(QRect(240, 30, 171, 20));

	InitWidget();
}

ContractService::~ContractService()
{
	delete ftp;
	delete ui;
	delete model;
	delete lineEdit;
}

void ContractService::InitWidget()
{
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
}
