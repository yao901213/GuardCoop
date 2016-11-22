#include "PropertyTool.h"

PropertyTool::PropertyTool(QWidget *parent) :
	QWidget(parent)
{
	ui = new Ui_PhoneBookWidget;
	ui->setupUi(this);

	model = new QSqlTableModel;
	model->setTable("HumanResource.PropertyTool");
	model->setFilter("");
	InitWidget();
}

PropertyTool::~PropertyTool()
{
	delete ui;
	delete model;
}

void PropertyTool::InitWidget()
{
	model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("����"), Qt::DisplayRole);
	model->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("����"), Qt::DisplayRole);
	model->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("ʣ��"), Qt::DisplayRole);
	model->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("����"), Qt::DisplayRole);

	model->select();
	ui->tableView->setModel(model);
	ui->tableView->setColumnHidden(0, true);
	ui->tableView->setColumnHidden(2, true);
	ui->tableView->show();
	
	this->show();
}
