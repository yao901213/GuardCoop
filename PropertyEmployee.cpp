#include "PropertyEmployee.h"
#include "InfoCheck.h"
#include <QMessageBox>
#include "ErrorProc.h"
#include <QSqlRecord>

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

	model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("����"), Qt::DisplayRole);
	model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("����"), Qt::DisplayRole);
	model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("���֤��"), Qt::DisplayRole);
	model->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("��ְʱ��"), Qt::DisplayRole);
	model->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("������Ʒ"), Qt::DisplayRole);
	model->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("��Ա����"), Qt::DisplayRole);
}

void PropertyEmployee::TableViewInit()
{
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableView->setModel(model);
	ui->tableView->setColumnHidden(3, true);
	ui->tableView->setColumnHidden(4, true);
	ui->tableView->setColumnHidden(8, true);
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
	QObject::connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(DoubleClickTable()));

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
	if (lineEdit->text().isEmpty())
	{
		if (0 == ComboBox->currentIndex())
		{
			strSearchFilter = "";
		}
		else
		{
			strSearchFilter = tr("Type = '%1'").arg(ComboBox->currentText());
		}
	}
	else
	{
		strSearchFilter = tr("Name = '%1' ").arg(lineEdit->text());
		SetFilterByType();
	}
	model->setFilter(strSearchFilter);
	model->select();
}

void PropertyEmployee::ClickAddButton()
{
	edit = new PropertyEmployeeEdit(model, 0);
	edit->InitAddFunc();

	QObject::connect(edit, SIGNAL(accepted()), this, SLOT(UpdateTable()));
}

void PropertyEmployee::ClickModButton()
{
	int index = ui->tableView->currentIndex().row();
	if (-1 == index)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��ѡ����Ҫ�޸ĵ�����"), 2);
		return;
	}
	edit = new PropertyEmployeeEdit(model, index);
	edit->InitModFunc();

	QObject::connect(edit, SIGNAL(accepted()), this, SLOT(UpdateTable()));
}

void PropertyEmployee::ClickDelButton()
{
	int index = ui->tableView->currentIndex().row();
	if (-1 == index)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��ѡ����Ҫ�޸ĵ�����"), 2);
		return;
	}
	model->select();
	QSqlRecord record = model->record(index);
	QMessageBox	box;
	box.setWindowTitle(QString::fromLocal8Bit("����"));
	box.setIcon(QMessageBox::Warning);
	box.setText(QString::fromLocal8Bit("��Ҫɾ�����ݣ�������%1�����֤�ţ�%2").
		arg(record.value("Name").toString()).arg(record.value("IDCard").toString()));
	box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	box.setButtonText(QMessageBox::Ok, QString::fromLocal8Bit("ȷ��"));
	box.setButtonText(QMessageBox::Cancel, QString::fromLocal8Bit("ȡ��"));
	if (QMessageBox::Ok == box.exec())
	{
		model->removeRow(index);
		model->submitAll();
		UpdateTable();
	}
	
}

void PropertyEmployee::DoubleClickTable()
{
	detail = new PropertyDetail(model, ui->tableView->currentIndex().row());
}

void PropertyEmployee::SetFilterByType()
{
	if (ComboBox->currentIndex() == 0)
	{
		return;
	}

	strSearchFilter += tr("AND Type = '%1'").arg(ComboBox->currentText());
}
