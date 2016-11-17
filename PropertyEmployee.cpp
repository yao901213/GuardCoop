#include "PropertyEmployee.h"
#include "InfoCheck.h"

const QString strCleaner = QString::fromLocal8Bit("保洁");
const QString strPlumElec = QString::fromLocal8Bit("水电");
const QString strGarden = QString::fromLocal8Bit("保洁");

PropertyEmployee::PropertyEmployee(QWidget *parent):
	QWidget(parent)
{
	ui = new Ui_TableWidget;
	ui->setupUi(this);
	model = new QSqlTableModel;
	model->setTable("HumanResource.Property");
	model->setFilter("");

	InitWidget();
}

PropertyEmployee::~PropertyEmployee()
{
	delete ui;
	delete model;
}

void PropertyEmployee::InitWidget()
{
	lineEdit = new QLineEdit(this);
	lineEdit->setObjectName(QStringLiteral("lineEdit"));
	lineEdit->setGeometry(QRect(240, 30, 171, 23));

	ComboBox = new QComboBox(this);
	ComboBox->setObjectName(QStringLiteral("ComboBox"));
	ComboBox->setGeometry(QRect(170, 30, 61, 23));

	SetModelHeader();
	TableViewInit();

	InitConnect();
	InitCombobox();
}

void PropertyEmployee::SetModelHeader()
{
	model->select();

	model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("工号"), Qt::DisplayRole);
	model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("姓名"), Qt::DisplayRole);
	model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("身份证号"), Qt::DisplayRole);
	model->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("入职时间"), Qt::DisplayRole);
	model->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("借用物品"), Qt::DisplayRole);
	model->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("雇员类型"), Qt::DisplayRole);
}

void PropertyEmployee::TableViewInit()
{
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableView->setModel(model);
	ui->tableView->setColumnHidden(3, true);
	ui->tableView->setColumnHidden(4, true);
	ui->tableView->resizeColumnToContents(2);
	
	ui->tableView->show();
}

void PropertyEmployee::InitConnect()
{
	QObject::connect(ui->pushButtonAdd, SIGNAL(clicked()), this, SLOT(ClickAddButton()));
	QObject::connect(ui->pushButtonDel, SIGNAL(clicked()), this, SLOT(ClickDelButton()));
	QObject::connect(ui->pushButtonMod, SIGNAL(clicked()), this, SLOT(ClickModButton()));
	QObject::connect(ui->pushButtonSearch, SIGNAL(clicked()), this, SLOT(ClickSearchButton()));
	QObject::connect(ui->pushButtonShowAll, SIGNAL(clicked()), this, SLOT(UpdateTable()));
}


void PropertyEmployee::UpdateTable()
{
	model->setFilter("");
	model->select();
}

void PropertyEmployee::InitCombobox()
{
	ComboBox->setEditable(false);
	ComboBox->addItem(QString::fromLocal8Bit("全部"));
	ComboBox->addItem(strCleaner);
	ComboBox->addItem(strPlumElec);
	ComboBox->addItem(strGarden);
}

void PropertyEmployee::ClickSearchButton()
{
	
}

void PropertyEmployee::ClickAddButton()
{
	edit = new PropertyEmployeeEdit(model, 0);
	edit->InitAddFunc();

}

void PropertyEmployee::ClickModButton()
{
	edit = new PropertyEmployeeEdit(model, ui->tableView->currentIndex().row());
	edit->InitModFunc();
}

void PropertyEmployee::ClickDelButton()
{

}