#include "PropertyEmployeeSelect.h"
#include "ErrorProc.h"

PropertyEmployeeSelect::PropertyEmployeeSelect(QString &filter)
{
	ui = new Ui_SmallTable;
	ui->setupUi(this);
	model = new QSqlTableModel;
	model->setTable("HumanResource.Property");
	model->setFilter(filter);
	model->select();
	InitDiag();
}

PropertyEmployeeSelect::~PropertyEmployeeSelect()
{
	delete ui;
	delete model;
}

void PropertyEmployeeSelect::InitDiag()
{
	model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("工号"), Qt::DisplayRole);
	model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("姓名"), Qt::DisplayRole);
	model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("身份证号"), Qt::DisplayRole);
	model->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("员工类型"), Qt::DisplayRole);
	model->select();

	ui->tableView->setModel(model);
	ui->tableView->setColumnHidden(3, true);
	ui->tableView->setColumnHidden(4, true);
	ui->tableView->setColumnHidden(5, true);
	ui->tableView->setColumnHidden(6, true);
	ui->tableView->setColumnHidden(8, true);
	ui->tableView->show();
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

	this->setModal(true);
	QObject::connect(ui->pushButtonOK, SIGNAL(clicked()), this, SLOT(ClickOkButton()));
	show();
}


void PropertyEmployeeSelect::ClickOkButton()
{
	int index = ui->tableView->currentIndex().row();
	if (-1 == index)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请选中要选择的员工"), 2);
		return;
	}

	emit ChoiceID(index);
	this->accept();
}
