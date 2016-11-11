#include "GuardDetailInfoDiag.h"
#include <QSqlRecord>

GuardDetail::GuardDetail(int SelectIndex, QSqlTableModel *parentmodel)
{
	ui = new Ui_GuardDetailInfoDialog; 
	model = new QSqlTableModel;
	model->setTable("HumanResource.Guard");
	model->setFilter(parentmodel->filter());
	ui->setupUi(this);
	index = SelectIndex;

	InitDiag();
}

GuardDetail::~GuardDetail()
{
	delete ui;
	delete model;
}

void GuardDetail::InitDiag()
{
	model->select();
	QSqlRecord record = model->record(index);

	ui->labelID->setText(record.value("EmployeeID").toString());
	ui->labelName->setText(record.value("Name").toString());
	ui->labelWorkPosition->setText(record.value("WorkPosition").toString());
	ui->labelIDCardNum->setText(record.value("IDCardNum").toString());

	QPixmap photo;
	photo.loadFromData(record.value("Photo").toByteArray(), "JPG");
	ui->labelPic->setPixmap(photo);
	ui->labelPic->setScaledContents(true);

	this->show();
}
