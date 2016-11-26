#include "CarInsure.h"

CarInsure::CarInsure(QString &filter, int index)
{
	ui = new Ui_CarInsure;
	ui->setupUi(this);

	model = new QSqlTableModel;
	model->setTable("HumanResource.CarInsure");
	model->setFilter(filter);
	Index = index;
	InitDiag();
}

CarInsure::~CarInsure()
{
	delete ui;
	delete model;
}

void CarInsure::InitDiag()
{

	this->setModal(true);
	this->show();
}