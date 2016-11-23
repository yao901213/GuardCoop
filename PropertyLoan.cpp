#include "PropertyLoan.h"

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
	model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("���к�"), Qt::DisplayRole);
	model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("������"), Qt::DisplayRole);
	model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("�����˹���"), Qt::DisplayRole);
	model->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("������Ʒ"), Qt::DisplayRole);
	model->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("��������"), Qt::DisplayRole);
	model->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("������"), Qt::DisplayRole);
	model->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("�������"), Qt::DisplayRole);
	model->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("�黹����"), Qt::DisplayRole);
	model->setHeaderData(8, Qt::Horizontal, QString::fromLocal8Bit("�Ƿ�黹"), Qt::DisplayRole);
	model->setHeaderData(9, Qt::Horizontal, QString::fromLocal8Bit("�Ƿ����"), Qt::DisplayRole);
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
	ui->pushButtonAdd->setText(QString::fromLocal8Bit("�µĽ���"));
	ui->pushButtonDel->setText(QString::fromLocal8Bit("�黹"));
	ui->pushButtonMod->setText(QString::fromLocal8Bit("ת��"));
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
}

void PropertyLoan::ClickModButton()
{


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