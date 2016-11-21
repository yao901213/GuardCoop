#include "PropertyTool.h"

PropertyTool::PropertyTool(QWidget *parent) :
	QWidget(parent)
{
	ui = new Ui_PhoneBookWidget;
	model = new QSqlTableModel;

	model->setTable("HumanResource.PropertyTool");
	model->setFilter("");
}

PropertyTool::~PropertyTool()
{
	delete ui;
	delete model;
}

void PropertyTool::InitWidget()
{

}
