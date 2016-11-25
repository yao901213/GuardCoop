#include "PropertyEmployeeLoanDetail.h"

PropertyEmployeeLoanDetail::PropertyEmployeeLoanDetail(QString &filter)
{
	ui = new Ui_SmallTable;
	ui->setupUi(this);

	model = new QSqlTableModel;
	model->setTable("HumanResource.PropertyLoan");
	model->setFilter(filter);

	InitDiag();
}

PropertyEmployeeLoanDetail::~PropertyEmployeeLoanDetail()
{
	delete ui;
	delete model;
}

void PropertyEmployeeLoanDetail::InitDiag()
{
	ui->pushButtonOK->setText(QString::fromLocal8Bit("�ر�"));

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

	QObject::connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(DoubleClickRow()));
	QObject::connect(ui->pushButtonOK, SIGNAL(clicked()), this, SLOT(reject()));

	this->setWindowTitle(QString::fromLocal8Bit("��ϸ���"));
	this->setModal(true);
	this->show();
}

void PropertyEmployeeLoanDetail::DoubleClickRow()
{
	detail = new PropertyLoanEdit(model->filter(), ui->tableView->currentIndex().row());
	detail->InitDiagDetailFunc();
}