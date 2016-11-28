#include "PropertyLoan.h"
#include "ErrorProc.h"

PropertyLoan::PropertyLoan(QWidget *parent) :
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
	lineEdit->setGeometry(QRect(280, 30, 131, 23));

	comboBox = new QComboBox(this);
	comboBox->setObjectName(QStringLiteral("comboBox"));
	comboBox->setGeometry(QRect(185, 30, 83, 22));
	
	ColumnIndex = -1;

	InitButtons();
	InitTable();
	InitConnect();
	InitComboBox();
}

void PropertyLoan::InitComboBox()
{
	comboBox->addItem(QString::fromLocal8Bit("���к�"));
	comboBox->addItem(QString::fromLocal8Bit("����������"));
	comboBox->addItem(QString::fromLocal8Bit("�����˹���"));
	comboBox->addItem(QString::fromLocal8Bit("��������"));
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
	ui->tableView->horizontalHeader()->setHighlightSections(false);
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
	QObject::connect(ui->pushButtonSearch, SIGNAL(clicked()), this, SLOT(ClickSearchButton()));
	QObject::connect(ui->pushButtonShowAll, SIGNAL(clicked()), this, SLOT(ShowAll()));
	QObject::connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(DoubleClickRow()));
	QObject::connect(ui->tableView->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(ClickTableHeader(int)));
}

void PropertyLoan::ClickAddButton()
{
	edit = new PropertyLoanEdit(QString(""), 0, -1);
	edit->InitDiagAddfunc();
	QObject::connect(edit, SIGNAL(accepted()), this, SLOT(UpdateTable()));
}

void PropertyLoan::ClickModButton()
{
	if (-1 == ui->tableView->currentIndex().row())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��ѡ��Ҫ�޸ĵ�����"), 2);
		return;
	}
	edit = new PropertyLoanEdit(model->filter(), ui->tableView->currentIndex().row(), ColumnIndex);
	edit->InitDiagModFunc();
	QObject::connect(edit, SIGNAL(accepted()), this, SLOT(UpdateTable()));
}

void PropertyLoan::ClickDelButton()
{
	if (-1 == ui->tableView->currentIndex().row())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��ѡ��Ҫ�޸ĵ�����"), 2);
		return;
	}
	edit = new PropertyLoanEdit(model->filter(), ui->tableView->currentIndex().row(), ColumnIndex);
	edit->InitDiagDelFunc();

	QObject::connect(edit, SIGNAL(accepted()), this, SLOT(UpdateTable()));
}

void PropertyLoan::ClickSearchButton()
{
	if (lineEdit->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("������Ҫ��ѯ������"), 2);
		return;
	}

	if (comboBox->currentText() == QString::fromLocal8Bit("���к�"))
	{
		model->setFilter(tr("ID = %1").arg(lineEdit->text()));
	}

	if (comboBox->currentText() == QString::fromLocal8Bit("����������"))
	{
		model->setFilter(tr("Borrower = '%1'").arg(lineEdit->text()));
	}

	if (comboBox->currentText() == QString::fromLocal8Bit("�����˹���"))
	{
		model->setFilter(tr("BorrowerID = %1").arg(lineEdit->text()));
	}

	if (comboBox->currentText() == QString::fromLocal8Bit("��������"))
	{
		model->setFilter(tr("LoanStaff = '%1'").arg(lineEdit->text()));
	}

	model->select();
}


void PropertyLoan::UpdateTable()
{
	model->setFilter(tr("ReturnFlag = '%1'").arg(QString::fromLocal8Bit("��")));
	model->select();
}

void PropertyLoan::ShowAll()
{
	model->setFilter("");
	model->select();
}

void PropertyLoan::DoubleClickRow()
{
	edit = new PropertyLoanEdit(model->filter(), ui->tableView->currentIndex().row(), ColumnIndex);
	edit->InitDiagDetailFunc();
}

void PropertyLoan::ClickTableHeader(int columnindex)
{
	ColumnIndex = columnindex;
	model->setSort(columnindex, Qt::AscendingOrder);
	model->select();
}