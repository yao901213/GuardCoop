#include <QSqlRecord>
#include <QSqlError>
#include "PropertyTool.h"
#include "ErrorProc.h"

PropertyTool::PropertyTool(QWidget *parent) :
	QWidget(parent)
{
	ui = new Ui_PhoneBookWidget;
	ui->setupUi(this);

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
	ui->lineEdit->setPlaceholderText(QString::fromLocal8Bit("���������Ʋ�ѯ"));

	this->show();
}


void PropertyTool::InitTable()
{
	model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("����"), Qt::DisplayRole);
	model->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("����"), Qt::DisplayRole);
	model->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("ʣ��"), Qt::DisplayRole);
	model->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("����"), Qt::DisplayRole);

	model->select();	
	ui->tableView->setSortingEnabled(true);
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
}

void PropertyTool::ClickAddButton()
{
	edit = new ToolEdit(model->filter(), 0);
	edit->InitAddFunc();
	QObject::connect(edit, SIGNAL(accepted()), this, SLOT(UpdateTable()));
}

void PropertyTool::ClickModButton()
{
	if (-1 == ui->tableView->currentIndex().row())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��ѡ��Ҫ�޸ĵ�����"), 2);
		return;
	}
	edit = new ToolEdit(model->filter(), ui->tableView->currentIndex().row());
	edit->InitModFunc();
	QObject::connect(edit, SIGNAL(accepted()), this, SLOT(UpdateTable()));
}

void PropertyTool::ClickDelButton()
{
	if (-1 == ui->tableView->currentIndex().row())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��ѡ����Ҫɾ��������"), 2);
		return;
	}

	QSqlRecord record = model->record(ui->tableView->currentIndex().row());
	if (0 != record.value("Number").toInt() - record.value("NumberLeft").toInt())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��ǰ�����н����¼��������ɾ�������ȴ�������¼"), 2);
		return;
	}
	QMessageBox box;
	QString ssss = record.value("Name").toString();
	box.setIcon(QMessageBox::Warning);
	box.setWindowTitle(QString::fromLocal8Bit("����"));
	box.setText(QString::fromLocal8Bit("ȷ����Ҫɾ�������ݣ�\n���ƣ�%1").arg(record.value("Name").toString()));
	box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	box.setButtonText(QMessageBox::Ok, QString::fromLocal8Bit("ȷ��"));
	box.setButtonText(QMessageBox::Cancel, QString::fromLocal8Bit("ȡ��"));
	if (QMessageBox::Ok != box.exec())
	{
		return;
	}
	model->removeRow(ui->tableView->currentIndex().row());
	if (!model->submitAll())
	{
		QString str = QString::fromLocal8Bit("���ݿ⴦�����") + model->lastError().text();
		ErrorProc::PopMessageBox(&str, 2);
		return;
	}
	else
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("ɾ���ɹ�"), 0);
		UpdateTable();
	}
}

void PropertyTool::ClickSearchButton()
{
	if (ui->lineEdit->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�������ѯ������"), 2);
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
	detail = new PropertyToolDetail(model->filter(), ui->tableView->currentIndex().row());
}
