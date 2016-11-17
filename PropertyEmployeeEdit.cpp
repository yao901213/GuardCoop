#include "PropertyEmployeeEdit.h"

PropertyEmployeeEdit::PropertyEmployeeEdit(QSqlTableModel *parentmodel, int CurRow)
{
	model = new QSqlTableModel;
	ui = new Ui_PropertyEdit;
	ui->setupUi(this);
	index = CurRow;
	model->setTable("HumanResource.Property");
	model->setFilter(parentmodel->filter());

	InitDiag();
}

PropertyEmployeeEdit::~PropertyEmployeeEdit()
{
	delete ui;
	delete model;
}

void PropertyEmployeeEdit::InitDiag()
{

	this->show();
}

void PropertyEmployeeEdit::InitAddFunc()
{

}

void PropertyEmployeeEdit::InitModFunc()
{
	model->select();

	
}