#include "CarDetail.h"
#include <QSqlRecord>
#include <QSqlError>

CarDetail::CarDetail(QString &filter, int index, int sort)
{
	ui = new Ui_CarDetail;
	ui->setupUi(this);

	modelCar = new QSqlTableModel;
	modelCar->setTable("HumanResource.Car");
	modelInsure = new QSqlTableModel;
	modelInsure->setTable("HumanResource.CarInsure");
	modelMaintain = new QSqlTableModel;
	modelMaintain->setTable("HumanResource.CarMaintain");
	modelCar->setFilter(filter);
	modelCar->setSort(sort, Qt::AscendingOrder);
	modelCar->select();
	Index = index;

	InitDiag();
}

CarDetail::~CarDetail()
{
	delete ui;
	delete modelCar;
	delete modelMaintain;
}

void CarDetail::InitDiag()
{
	QSqlRecord record = modelCar->record(Index);
	QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(reject()));
	QObject::connect(ui->tableViewInsure, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(DoubleClickInsureTable()));
	QObject::connect(ui->tableViewMaintain, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(DoubleClickMaintainTable()));

	ui->labelID->setText(record.value("ID").toString());
	ui->labelType->setText(record.value("Type").toString());
	ui->labelBrand->setText(record.value("Brand").toString());
	ui->labelKeeper->setText(record.value("Keeper").toString());
	ui->labelPerform->setText(record.value("Perform").toString());
	ui->labelDateofBuy->setText(record.value("DateofBuy").toString());
	ui->labelCondition->setText(record.value("Condition").toString());
	ui->textBrowser->setText(record.value("Remark").toString());

	InitInsureTable();
	InitMaintainTable();

	this->setModal(true);
	this->show();
}

void CarDetail::InitInsureTable()
{
	modelInsure->setFilter(tr("CarID = '%1'").arg(ui->labelID->text()));
	modelInsure->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("车牌号"), Qt::DisplayRole);
	modelInsure->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("保险类型"), Qt::DisplayRole);
	modelInsure->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("价格"), Qt::DisplayRole);
	modelInsure->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("保险公司"), Qt::DisplayRole);
	modelInsure->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("生效时间"), Qt::DisplayRole);
	modelInsure->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("截止时间"), Qt::DisplayRole);
	modelInsure->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("责任人"), Qt::DisplayRole);
	modelInsure->setHeaderData(8, Qt::Horizontal, QString::fromLocal8Bit("备注"), Qt::DisplayRole);
	
	ui->tableViewInsure->setModel(modelInsure);
	modelInsure->select();
	ui->tableViewInsure->setColumnHidden(0, true);
	ui->tableViewInsure->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableViewInsure->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->tableViewInsure->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableViewInsure->horizontalHeader()->setHighlightSections(false);
	ui->tableViewInsure->show();
}


void CarDetail::InitMaintainTable()
{
	modelMaintain->setFilter(tr("CarID = '%1'").arg(ui->labelID->text()));
	modelMaintain->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("车牌号"), Qt::DisplayRole);
	modelMaintain->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("类型"), Qt::DisplayRole);
	modelMaintain->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("地点"), Qt::DisplayRole);
	modelMaintain->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("价格"), Qt::DisplayRole);
	modelMaintain->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("日期"), Qt::DisplayRole);
	modelMaintain->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("公里数"), Qt::DisplayRole);
	modelMaintain->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("责任人"), Qt::DisplayRole);
	modelMaintain->setHeaderData(8, Qt::Horizontal, QString::fromLocal8Bit("备注"), Qt::DisplayRole);
	ui->tableViewMaintain->setModel(modelMaintain);
	modelMaintain->select();
	ui->tableViewMaintain->setColumnHidden(0, true);
	ui->tableViewMaintain->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableViewMaintain->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->tableViewMaintain->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableViewMaintain->horizontalHeader()->setHighlightSections(false);
	ui->tableViewMaintain->show();
}


void CarDetail::DoubleClickInsureTable()
{
	insure = new CarInsure(modelCar->filter(), ui->tableViewInsure->currentIndex().row(), -1);
	insure->InitDetailFunc();
}

void CarDetail::DoubleClickMaintainTable()
{
	maintain = new CarMaintain(modelCar->filter(), ui->tableViewMaintain->currentIndex().row(), - 1);
}
