#include "CarDetail.h"
#include <QSqlRecord>
#include <QSqlError>
#include "ErrorProc.h"
#include <QMessageBox>

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

	QObject::connect(ui->pushButtonAddInsure, SIGNAL(clicked()), this, SLOT(ClickInsureAddButton()));
	QObject::connect(ui->pushButtonDelInsure, SIGNAL(clicked()), this, SLOT(ClickInsureDelButton()));
	QObject::connect(ui->pushButtonAddMaintain, SIGNAL(clicked()), this, SLOT(ClickMaintainAddButton()));
	QObject::connect(ui->pushButtonDelMaintain, SIGNAL(clicked()), this, SLOT(ClickMaintainDelButton()));

	InitInsureTable();
	InitMaintainTable();

	this->setModal(true);
	this->show();
}

void CarDetail::InitInsureTable()
{
	modelInsure->setFilter(tr("CarID = '%1'").arg(ui->labelID->text()));
	modelInsure->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("���ƺ�"), Qt::DisplayRole);
	modelInsure->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("��������"), Qt::DisplayRole);
	modelInsure->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("�۸�"), Qt::DisplayRole);
	modelInsure->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("���չ�˾"), Qt::DisplayRole);
	modelInsure->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("��Чʱ��"), Qt::DisplayRole);
	modelInsure->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("��ֹʱ��"), Qt::DisplayRole);
	modelInsure->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("������"), Qt::DisplayRole);
	modelInsure->setHeaderData(8, Qt::Horizontal, QString::fromLocal8Bit("��ע"), Qt::DisplayRole);
	
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
	modelMaintain->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("���ƺ�"), Qt::DisplayRole);
	modelMaintain->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("����"), Qt::DisplayRole);
	modelMaintain->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("�ص�"), Qt::DisplayRole);
	modelMaintain->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("�۸�"), Qt::DisplayRole);
	modelMaintain->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("����"), Qt::DisplayRole);
	modelMaintain->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("������"), Qt::DisplayRole);
	modelMaintain->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("������"), Qt::DisplayRole);
	modelMaintain->setHeaderData(8, Qt::Horizontal, QString::fromLocal8Bit("��ע"), Qt::DisplayRole);
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
	insure->InitDetailFunc(ui->labelID->text());
}

void CarDetail::DoubleClickMaintainTable()
{
	maintain = new CarMaintain(modelCar->filter(), ui->tableViewMaintain->currentIndex().row(), - 1);
	maintain->InitDetailFunc(ui->labelID->text());
}

void CarDetail::ClickInsureAddButton()
{
	insure = new CarInsure(modelInsure->filter(), 0, -1);
	insure->InitAddFromDetail(ui->labelID->text());

	QObject::connect(insure, SIGNAL(accepted()), this, SLOT(UpdateInsureTable()));
}

void CarDetail::ClickInsureDelButton()
{
	int CurRow = ui->tableViewInsure->currentIndex().row();
	if (-1 == CurRow)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��ѡ��Ҫɾ��������"), 2);
		return;
	}
	modelInsure->setFilter(tr("CarID = '%1'").arg(ui->labelID->text()));
	modelInsure->select();
	
	QMessageBox box;
	box.setWindowTitle(QString::fromLocal8Bit("����"));
	box.setIcon(QMessageBox::Warning);
	box.setText(QString::fromLocal8Bit("��ȷ���Ƿ�ɾ�����ݣ�"));
	box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	box.setButtonText(QMessageBox::Ok, QString::fromLocal8Bit("ȷ��"));
	box.setButtonText(QMessageBox::Cancel, QString::fromLocal8Bit("ȡ��"));
	
	if (QMessageBox::Ok == box.exec())
	{
		if (!modelInsure->removeRow(CurRow))
		{
			QString str = QString::fromLocal8Bit("ɾ�����ݿ����") + modelInsure->lastError().text();
			ErrorProc::PopMessageBox(&str, 2);
		}
		else
		{
			ErrorProc::PopMessageBox(&QString::fromLocal8Bit("ɾ���ɹ�"), 0);
			UpdateInsureTable();
		}
	}
}

void CarDetail::ClickMaintainAddButton()
{
	maintain = new CarMaintain(modelMaintain->filter(), 0, -1);
	maintain->InitAddFromDetail(ui->labelID->text());

	QObject::connect(maintain, SIGNAL(accepted()), this, SLOT(UpdateMaintainTable()));
}

void CarDetail::ClickMaintainDelButton()
{
	int CurRow = ui->tableViewMaintain->currentIndex().row();
	if (-1 == CurRow)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��ѡ��Ҫɾ��������"), 2);
		return;
	}

	modelMaintain->setFilter(tr("CarID = '%1'").arg(ui->labelID->text()));
	modelMaintain->select();

	QMessageBox box;
	box.setWindowTitle(QString::fromLocal8Bit("����"));
	box.setIcon(QMessageBox::Warning);
	box.setText(QString::fromLocal8Bit("��ȷ���Ƿ�ɾ�����ݣ�"));
	box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	box.setButtonText(QMessageBox::Ok, QString::fromLocal8Bit("ȷ��"));
	box.setButtonText(QMessageBox::Cancel, QString::fromLocal8Bit("ȡ��"));

	if (QMessageBox::Ok == box.exec())
	{
		if (!modelMaintain->removeRow(CurRow))
		{
			QString str = QString::fromLocal8Bit("ɾ�����ݿ����") + modelMaintain->lastError().text();
			ErrorProc::PopMessageBox(&str, 2);
		}
		else
		{
			ErrorProc::PopMessageBox(&QString::fromLocal8Bit("ɾ���ɹ�"), 0);
			UpdateMaintainTable();
		}
	}

}

void CarDetail::UpdateInsureTable()
{
	modelInsure->setFilter(tr("CarID = '%1'").arg(ui->labelID->text()));
	modelInsure->select();
}

void CarDetail::UpdateMaintainTable()
{
	modelMaintain->setFilter(tr("CarID = '%1'").arg(ui->labelID->text()));
	modelMaintain->select();
}