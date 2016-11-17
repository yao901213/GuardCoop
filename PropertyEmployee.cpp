#include "PropertyEmployee.h"
#include "InfoCheck.h"

const QString strCleaner = QString::fromLocal8Bit("����");
const QString strPlumElec = QString::fromLocal8Bit("ˮ��");
const QString strGarden = QString::fromLocal8Bit("����");

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

	model->select();
	model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("����"), Qt::DisplayRole);
	model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("����"), Qt::DisplayRole);
	model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("����֤��"), Qt::DisplayRole);
	model->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("��ְʱ��"), Qt::DisplayRole);
	model->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("������Ʒ"), Qt::DisplayRole);
	model->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("��Ա����"), Qt::DisplayRole);

	model->select();
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableView->setModel(model);
	ui->tableView->setColumnHidden(3, true);
	ui->tableView->setColumnHidden(4, true);
	ui->tableView->resizeColumnToContents(2);
	ui->tableView->show();

	InitCombobox();
}

void PropertyEmployee::UpdateTable()
{
	model->setFilter("");
	model->select();
}

void PropertyEmployee::InitCombobox()
{
	ComboBox->setEditable(false);
	ComboBox->addItem(QString::fromLocal8Bit("ȫ��"));
	ComboBox->addItem(strCleaner);
	ComboBox->addItem(strPlumElec);
	ComboBox->addItem(strGarden);
}

void PropertyEmployee::ClickSearchButton()
{

}
void PropertyEmployee::ClickAddButton()
{

}
void PropertyEmployee::ClickModButton()
{

}
void PropertyEmployee::ClickDelButton()
{

}