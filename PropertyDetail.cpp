#include "PropertyDetail.h"
#include <QSqlRecord>
#include <QPixmap>

PropertyDetail::PropertyDetail(QSqlTableModel *parentmodel, int parentindex, int sort)
{
	ui = new Ui_PropertyDetail;
	ui->setupUi(this);
	model = new QSqlTableModel;
	model->setTable("HumanResource.Property");
	model->setFilter(parentmodel->filter());
	if (-1 != sort)
	{
		model->setSort(sort, Qt::AscendingOrder);
	}
	index = parentindex;

	InitDiag();
}

PropertyDetail::~PropertyDetail()
{
	delete ui;
	delete model;
}

void PropertyDetail::InitDiag()
{
	model->select();
	QSqlRecord record = model->record(index);
	ui->labelID->setText(record.value("ID").toString());
	ui->labelName->setText(record.value("Name").toString());
	ui->labelIDCard->setText(record.value("IDCard").toString());
	ui->labelGender->setText(record.value("Gender").toString());
	ui->labelDateofBirth->setText(record.value("DateofBirth").toString());
	ui->labelDateofEmploy->setText(record.value("DateofEmploy").toString());
	ui->labelType->setText(record.value("Type").toString());
	ui->labelLoan->setText(record.value("Loan").toString());

	QPixmap photo;
	photo.loadFromData(record.value("Photo").toByteArray());
	ui->labelPic->setPixmap(photo);
	ui->labelPic->setScaledContents(true);

	QObject::connect(ui->pushButtonDetail, SIGNAL(clicked()), this, SLOT(ClickDetailButton()));

	if (QString::fromLocal8Bit("ÊÇ") != ui->labelLoan->text())
	{
		ui->pushButtonDetail->setDisabled(true);
	}

	this->setModal(true);
	this->show();
}

void PropertyDetail::ClickDetailButton()
{
	QString filter = tr("BorrowerID = %1").arg(ui->labelID->text());
	loandetail = new PropertyEmployeeLoanDetail(filter);
}