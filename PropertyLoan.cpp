#include "PropertyLoan.h"
#include "ErrorProc.h"

PropertyLoan::PropertyLoan(QWidget *parent):
	QWidget(parent)
{
	ui = new Ui_TableWidget;
	ui->setupUi(this);

	model = new QSqlTableModel;
	model->setTable("HumanResource.PropertyLoan");
	model->setFilter("");

	InitWidget();
}

PropertyLoan::~PropertyLoan()
{
	delete ui;
	delete model;
}

void PropertyLoan::InitWidget()
{
	lineEdit = new QLineEdit(this);
	lineEdit->setObjectName(QStringLiteral("lineEdit"));
	lineEdit->setGeometry(QRect(240, 30, 171, 23));

	InitButtons();
	InitTable();
	InitConnect();
}

void PropertyLoan::InitTable()
{
	model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("序列号"), Qt::DisplayRole);
	model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("借用人"), Qt::DisplayRole);
	model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("借用人工号"), Qt::DisplayRole);
	model->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("借用物品"), Qt::DisplayRole);
	model->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("借用数量"), Qt::DisplayRole);
	model->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("经办人"), Qt::DisplayRole);
	model->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("借出日期"), Qt::DisplayRole);
	model->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("归还日期"), Qt::DisplayRole);
	model->setHeaderData(8, Qt::Horizontal, QString::fromLocal8Bit("是否归还"), Qt::DisplayRole);
	model->setHeaderData(9, Qt::Horizontal, QString::fromLocal8Bit("是否完好"), Qt::DisplayRole);
	model->select();

	ui->tableView->setModel(model);
	ui->tableView->setColumnHidden(10, true);
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableView->show();
}

void PropertyLoan::InitButtons()
{
	ui->pushButtonAdd->setText(QString::fromLocal8Bit("新的借用"));
	ui->pushButtonDel->setText(QString::fromLocal8Bit("归还"));
	ui->pushButtonMod->setText(QString::fromLocal8Bit("转让"));
}

void PropertyLoan::InitConnect()
{
	QObject::connect(ui->pushButtonAdd, SIGNAL(clicked()), this, SLOT(ClickAddButton()));
	QObject::connect(ui->pushButtonDel, SIGNAL(clicked()), this, SLOT(ClickDelButton()));
	QObject::connect(ui->pushButtonMod, SIGNAL(clicked()), this, SLOT(ClickModButton()));
	QObject::connect(ui->pushButtonSearch, SIGNAL(clicked()), this, SLOT(ClickSearckButton()));
	QObject::connect(ui->pushButtonShowAll, SIGNAL(clicked()), this, SLOT(UpdateTable()));

}

void PropertyLoan::ClickAddButton()
{
	edit = new PropertyLoanEdit(QString(""), 0);
	edit->InitDiagAddfunc();
	QObject::connect(edit, SIGNAL(accepted()), this, SLOT(UpdateTable()));
}

void PropertyLoan::ClickModButton()
{
	if (-1 == ui->tableView->currentIndex().row())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请选择要修改的数据"), 2);
		return;
	}
	edit = new PropertyLoanEdit(model->filter(), ui->tableView->currentIndex().row());
	edit->InitDiagModFunc();
	QObject::connect(edit, SIGNAL(accepted()), this, SLOT(UpdateTable()));
}

void PropertyLoan::ClickDelButton()
{

}
void PropertyLoan::ClickSearckButton()
{

}

void PropertyLoan::UpdateTable()
{
	model->setFilter("");
	model->select();
}