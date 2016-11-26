#include "Car.h"

Car::Car(QWidget *parent):
	QWidget(parent)
{
	ui = new Ui_CarTable;
	ui->setupUi(this);

	model = new QSqlTableModel;
	model->setTable("HumanResource.Car");
	model->setFilter("");
	model->select();
	InitWidget();
}

Car::~Car()
{
	delete ui;
	delete model;
}

void Car::InitWidget()
{
	model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("���ƺ�"), Qt::DisplayRole);
	model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("����"), Qt::DisplayRole);
	model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("�ͺ�"), Qt::DisplayRole);
	model->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("������"), Qt::DisplayRole);
	model->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("��������"), Qt::DisplayRole);
	model->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("ʹ��״̬"), Qt::DisplayRole);
	model->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("����"), Qt::DisplayRole);
	//model->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("��ע"), Qt::DisplayRole);

	ui->tableView->setModel(model);
	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableView->setSortingEnabled(true);
	ui->tableView->horizontalHeader()->setHighlightSections(false);
	ui->tableView->setColumnHidden(7, true);
	ui->tableView->show();

	QObject::connect(ui->pushButtonAdd, SIGNAL(clicked()), this, SLOT(ClickAddButton()));
	QObject::connect(ui->pushButtonMod, SIGNAL(clicked()), this, SLOT(ClickModButton()));
	QObject::connect(ui->pushButtonMaintain, SIGNAL(clicked()), this, SLOT(ClickMaintainButton()));
	QObject::connect(ui->pushButtonInsure, SIGNAL(clicked()), this, SLOT(ClickInsureButton()));
	QObject::connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(DoubleClickRow()));
}

void Car::UpdateTable()
{
	model->setFilter("");
	model->select();
}

void Car::ClickAddButton()
{
	edit = new CarEdit(QString(""), 0);
	edit->InitDiagAddFunc();

	QObject::connect(edit, SIGNAL(accepted()), this, SLOT(UpdateTable()));
}

void Car::ClickModButton()
{


}

void Car::ClickInsureButton()
{

}

void Car::ClickMaintainButton()
{

}

void Car::DoubleClickRow()
{


}