#include <QSqlRecord>
#include <QSqlError>
#include "PropertyTool.h"
#include "ErrorProc.h"

PropertyTool::PropertyTool(QWidget *parent) :
	QWidget(parent)
{
	ui = new Ui_PhoneBookWidget;
	ui->setupUi(this);
	ColumnIndex = -1;
	model = new QSqlTableModel;
	model->setTable("HumanResource.PropertyTool");
	model->setFilter("");
	InitWidget();
}

PropertyTool::~PropertyTool()
{
	delete ui;
	delete model;
}

void PropertyTool::InitWidget()
{
	InitTable();
	InitConnect();
	ui->lineEdit->setPlaceholderText(QString::fromLocal8Bit("请输入名称查询"));

	this->show();
}


void PropertyTool::InitTable()
{
	model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("名称"), Qt::DisplayRole);
	model->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("总数"), Qt::DisplayRole);
	model->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("剩余"), Qt::DisplayRole);
	model->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("类型"), Qt::DisplayRole);

	model->select();	
	ui->tableView->setModel(model);
	ui->tableView->setColumnHidden(0, true);
	ui->tableView->setColumnHidden(2, true);
	ui->tableView->show();
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableView->horizontalHeader()->setHighlightSections(false);
}

void PropertyTool::InitConnect()
{
	QObject::connect(ui->pushButtonAdd, SIGNAL(clicked()), this, SLOT(ClickAddButton()));
	QObject::connect(ui->pushButtonMod, SIGNAL(clicked()), this, SLOT(ClickModButton()));
	QObject::connect(ui->pushButtonDelete, SIGNAL(clicked()), this, SLOT(ClickDelButton()));
	QObject::connect(ui->pushButtonSearch, SIGNAL(clicked()), this, SLOT(ClickSearchButton()));
	QObject::connect(ui->pushButtonShowAll, SIGNAL(clicked()), this, SLOT(UpdateTable()));
	QObject::connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(DoubleClickRow()));
	QObject::connect(ui->tableView->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(ClickTableHeader(int)));
}

void PropertyTool::ClickAddButton()
{
	edit = new ToolEdit(model->filter(), 0, -1);
	edit->InitAddFunc();
	QObject::connect(edit, SIGNAL(accepted()), this, SLOT(UpdateTable()));
}

void PropertyTool::ClickModButton()
{
	if (-1 == ui->tableView->currentIndex().row())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请选择要修改的数据"), 2);
		return;
	}
	edit = new ToolEdit(model->filter(), ui->tableView->currentIndex().row(), ColumnIndex);
	edit->InitModFunc();
	QObject::connect(edit, SIGNAL(accepted()), this, SLOT(UpdateTable()));
}

void PropertyTool::ClickDelButton()
{
	if (-1 == ui->tableView->currentIndex().row())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请选择需要删除的数据"), 2);
		return;
	}

	QSqlRecord record = model->record(ui->tableView->currentIndex().row());
	if (0 != record.value("Number").toInt() - record.value("NumberLeft").toInt())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("当前工具有借出记录，不允许删除，请先处理借出记录"), 2);
		return;
	}
	QMessageBox box;
	QString ssss = record.value("Name").toString();
	box.setIcon(QMessageBox::Warning);
	box.setWindowTitle(QString::fromLocal8Bit("警告"));
	box.setText(QString::fromLocal8Bit("确认需要删除的数据：\n名称：%1").arg(record.value("Name").toString()));
	box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	box.setButtonText(QMessageBox::Ok, QString::fromLocal8Bit("确认"));
	box.setButtonText(QMessageBox::Cancel, QString::fromLocal8Bit("取消"));
	if (QMessageBox::Ok != box.exec())
	{
		return;
	}
	model->removeRow(ui->tableView->currentIndex().row());
	if (!model->submitAll())
	{
		QString str = QString::fromLocal8Bit("数据库处理错误") + model->lastError().text();
		ErrorProc::PopMessageBox(&str, 2);
		return;
	}
	else
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("删除成功"), 0);
		UpdateTable();
	}
}

void PropertyTool::ClickSearchButton()
{
	if (ui->lineEdit->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请输入查询的内容"), 2);
		return;
	}

	model->setFilter(tr("Name = '%1'").arg(ui->lineEdit->text()));
	model->select();
}

void PropertyTool::UpdateTable()
{
	model->setFilter("");
	model->select();
}

void PropertyTool::DoubleClickRow()
{
	detail = new PropertyToolDetail(model->filter(), ui->tableView->currentIndex().row(), ColumnIndex);
}

void PropertyTool::ClickTableHeader(int num)
{
	ColumnIndex = num;
	model->setSort(num, Qt::AscendingOrder);
	model->select();
}