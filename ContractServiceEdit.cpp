#include "ContractServiceEdit.h"

ContractServiceEdit::ContractServiceEdit(QString &filter, int index, int sort)
{
	model = new QSqlTableModel;
	model->setTable("HumanResource.ContractService");
	model->setFilter(filter);
	if (-1 != sort)
	{
		model->setSort(sort, Qt::AscendingOrder);
	}

	ui = new Ui_ContractServiceEdit;
	ui->setupUi(this);

	InitDiag();
}

ContractServiceEdit::~ContractServiceEdit()
{
	delete ui;
	delete model;
}

void ContractServiceEdit::InitDiag()
{
	this->setModal(true);
	this->show();
}