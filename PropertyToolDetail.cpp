#include "PropertyToolDetail.h"
#include <QSqlRecord>

PropertyToolDetail::PropertyToolDetail(QString &filter, int index, int sort)
{
	model = new QSqlTableModel;
	model->setTable("HumanResource.PropertyTool"); 
	model->setFilter(filter);
	if (-1 != sort)
	{
		model->setSort(sort, Qt::AscendingOrder);
	}

	ui = new Ui_PropertyToolDetail;
	ui->setupUi(this);
	Index = index;
	InitDiag();
}

PropertyToolDetail::~PropertyToolDetail()
{
	delete ui;
	delete model;
}

void PropertyToolDetail::InitDiag()
{
	model->select();
	QSqlRecord record = model->record(Index);

	ui->labelID->setText(record.value("ID").toString());
	ui->labelName->setText(record.value("Name").toString());
	ui->labelNumber->setText(record.value("Number").toString());
	ui->labelNumberLeft->setText(record.value("NumberLeft").toString());
	ui->textBrowserDiscribe->setText(record.value("Discribe").toString());
	ui->labelType->setText(record.value("Type").toString());
	this->show();
}
