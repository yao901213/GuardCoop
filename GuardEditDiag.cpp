#include "GuardEditDiag.h"
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include "InfoCheck.h"
#include "ErrorProc.h"
#include <QFileDialog>
#include "GlobalVar.h"
#include <QSqlQuery>

GuardEditDiag::GuardEditDiag(QDialog *parent) :
	QDialog(parent)
{
	ui = new Ui_GuardEditDialog;
	model = new QSqlTableModel;
	ui->setupUi(this);
}

GuardEditDiag::GuardEditDiag(int index, QSqlTableModel *parentmodel)
{
	ui = new Ui_GuardEditDialog;
	model = new QSqlTableModel;
	modelCompany = new QSqlTableModel;

	modelCompany->setTable("HumanResource.GuardCompany");
	modelCompany->setFilter("");
	model->setTable("HumanResource.Guard");
	model->setFilter(parentmodel->filter());
	CurRowIndex = index;
	ui->setupUi(this);
	QObject::connect(ui->pushButtonBrowse, SIGNAL(clicked()), this, SLOT(ClickBrowseButton()));
	QObject::connect(ui->pushButtonPreview, SIGNAL(clicked()), this, SLOT(ClickPreviewButton()));

	InitDiag();
}

GuardEditDiag::~GuardEditDiag()
{
	delete ui;
	delete model;
}

void GuardEditDiag::InitComboBox()
{
	int i = 0;
	int RowCount = 0;
	QString CurrentName;
	modelCompany->select();

	ui->comboBox->setEditable(false);
	ui->comboBox->addItem("");
	RowCount = modelCompany->rowCount();
	for (; i < RowCount; i++)
	{
		CurrentName = modelCompany->record(i).value("Name").toString();
		if (CurrentName == QString::fromLocal8Bit("��ʱ"))
		{
			continue;
		}
		ui->comboBox->addItem(CurrentName);
	}

	ui->comboBoxGender->addItem(QString::fromLocal8Bit(""));
	ui->comboBoxGender->addItem(QString::fromLocal8Bit("��"));
	ui->comboBoxGender->addItem(QString::fromLocal8Bit("Ů"));

	return;
}

void GuardEditDiag::InitDiag()
{
	InitComboBox();
	ui->lineEditIDCardNum->installEventFilter(this);

	this->setModal(true);
	this->show();
}

void GuardEditDiag::InitAddFunc()
{
	QObject::connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(ClickSubmitButtonAddFunc()));
	ui->comboBox->setCurrentIndex(0);
}

void GuardEditDiag::InitModFunc()
{
	QSqlRecord record;
	QObject::connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(ClickSubmitButtonModFunc()));

	model->select();
	record = model->record(CurRowIndex);

	ui->comboBox->setCurrentText(record.value("WorkPosition").toString());
	ui->lineEditID->setText(record.value("EmployeeID").toString());
	ui->lineEditID->setEnabled(false);
	ui->lineEditName->setText(record.value("Name").toString());
	ui->lineEditIDCardNum->setText(record.value("IDCardNum").toString());
	ui->comboBoxGender->setCurrentText(record.value("Gender").toString());
	ui->dateEdit->setDate(record.value("DateofBirth").toDate());

	QPixmap photo;
	photo.loadFromData(record.value("Photo").toByteArray(), "JPG");
	ui->labelPic->setPixmap(photo);
	ui->labelPic->setScaledContents(true);
}

void GuardEditDiag::ClickSubmitButtonModFunc()
{
	model->select();
	QSqlRecord record = model->record(CurRowIndex);
	int ID = record.value("EmployeeID").toInt();

	if (!InfoCheck::IsEmployeeIdCardNumValid(&ui->lineEditIDCardNum->text()))
	{
		ui->lineEditIDCardNum->setText(record.value("IDCardNum").toString());
		return;
	}

	if (!InfoCheck::IsChineseStr(&ui->lineEditName->text()))
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�����������Ǵ�����"), 2);
		ui->lineEditName->setText(record.value("Name").toString());
		return;
	}

	record.setValue("EmployeeID", ui->lineEditID->text());

	QSqlQuery query;
	QString queryStr = tr("UPDATE HumanResource.Guard SET Name = '%1'"
	"WHERE EmployeeID = %2").arg(ui->lineEditName->text()).arg(ID);
	query.prepare(queryStr);
	query.exec();

	queryStr = tr("UPDATE HumanResource.Guard SET WorkPosition = '%1'"
		"WHERE EmployeeID = %2").arg(ui->comboBox->currentText()).arg(ID);
	query.prepare(queryStr);
	query.exec();

	queryStr = tr("UPDATE HumanResource.Guard SET IDCardNum = '%1'"
		"WHERE EmployeeID = %2").arg(ui->lineEditIDCardNum->text()).arg(ID);
	query.prepare(queryStr);
	query.exec();

	queryStr = tr("UPDATE HumanResource.Guard SET DateofBirth = '%1'"
		"WHERE EmployeeID = %2").arg(ui->dateEdit->text()).arg(ID);
	query.prepare(queryStr);
	query.exec();

	queryStr = tr("UPDATE HumanResource.Guard SET Gender = '%1'"
		"WHERE EmployeeID = %2").arg(ui->comboBoxGender->currentText()).arg(ID);
	query.prepare(queryStr);
	query.exec();

	if (!ui->lineEditPhoto->text().isEmpty())
	{
		QFile file(ui->lineEditPhoto->text());
		file.open(QIODevice::ReadOnly);
		QByteArray data = file.readAll();
		QVariant var(data);
		//record.setValue("Photo", var);
		//model->setRecord(CurRowIndex, record);
		//model->submitAll();
	}

	this->accept();
}

void GuardEditDiag::ClickSubmitButtonAddFunc()
{
	if (!IsEmplyeeIdValid())
	{
		return;
	}
	if (!InfoCheck::IsEmployeeIdCardNumValid(&ui->lineEditIDCardNum->text()))
	{
		ui->lineEditIDCardNum->clear();
		return;
	}

	if (!InfoCheck::IsChineseStr(&ui->lineEditName->text()))
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�����������Ǵ�����"), 2);
		ui->lineEditName->clear();
		return;
	}

	model->setFilter("");
	model->select();
	QSqlRecord record = model->record(CurRowIndex);

	record.setValue("EmployeeID", ui->lineEditID->text().toInt());
	record.setValue("Name", ui->lineEditName->text());
	if ("" != ui->comboBox->currentText())
	{
		record.setValue("WorkPosition", ui->comboBox->currentText());
	}
	else
	{
		record.setValue("WorkPosition", QString::fromLocal8Bit("����"));
	}
	record.setValue("IDCardNum", ui->lineEditIDCardNum->text());

	if (!ui->lineEditPhoto->text().isEmpty())
	{
		QFile file(ui->lineEditPhoto->text());
		file.open(QIODevice::ReadOnly);
		QByteArray data = file.readAll();
		QVariant var(data);
		record.setValue("Photo", var);
	}

	model->insertRecord(CurRowIndex, record);
	qDebug() << model->lastError().text();
	model->submitAll();

	this->accept();
}


bool GuardEditDiag::IsEmplyeeIdValid()
{
	model->setFilter(QObject::tr("EmployeeID = %1").arg(ui->lineEditID->text()));
	model->select();

	if (1 == model->rowCount())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�Ѿ����ڹ���:%1�������ظ����")
					.arg(ui->lineEditID->text()), 2);
		return false;
	}

	if (0 == model->rowCount())
	{
		return true;
	}
	ErrorProc::PopMessageBox(&QString::fromLocal8Bit("���ݿ��й���:%1����")
		.arg(ui->lineEditID->text()), 2);

	return false;
}

void GuardEditDiag::ClickBrowseButton()
{
	QString filename = QFileDialog::getOpenFileName(this,
		QString::fromLocal8Bit("���"),
		"D:/", tr("Images(*.jpg)"));
	ui->lineEditPhoto->setText(filename);
}

void GuardEditDiag::ClickPreviewButton()
{
	if (ui->lineEditPhoto->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��ѡ���ϴ�����Ƭ"), 2);
		return;
	}

	QFile file(ui->lineEditPhoto->text());
	QByteArray data;
	file.open(QIODevice::ReadOnly);
	data = file.readAll();
	file.close();
	//QVariant var(data);
	QPixmap photo;
	photo.loadFromData(data, "JPG");
	ui->labelPic->setPixmap(photo);
	ui->labelPic->setScaledContents(true);
}

bool GuardEditDiag::eventFilter(QObject *obj, QEvent *ev)
{
	if (obj == ui->lineEditIDCardNum)
	{
		if (ev->type() == QEvent::FocusOut)
		{
			StaticCheck = false;
			if (InfoCheck::IsEmployeeIdCardNumValid(&ui->lineEditIDCardNum->text()))
			{
				ui->label_IDCardNotition->setStyleSheet(QStringLiteral("color: rgb(144, 238, 144);"));
				ui->label_IDCardNotition->setText(QString::fromLocal8Bit("У��ɹ�"));
				GetBirthAndGenderFromID();
			}
			else
			{
				ui->label_IDCardNotition->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
				ui->label_IDCardNotition->setText(QString::fromLocal8Bit("���֤�������"));
			}
			StaticCheck = true;
		}
		if (ev->type() == QEvent::FocusIn)
		{
			ui->label_IDCardNotition->clear();
		}
	}

	return QDialog::eventFilter(obj, ev);
}

void GuardEditDiag::GetBirthAndGenderFromID()
{
	QString ID = ui->lineEditIDCardNum->text();

	int year, month, date, gender;
	int offset = 6;

	if (ID.length() == FIX_NEW_ID_CARD_NUM_LEN)
	{
		year = ID.mid(offset, 4).toInt();
		offset += 4;
	}
	else
	{
		year = ID.mid(offset, 2).toInt();
		offset += 2;
	}
	month = ID.mid(offset, 2).toInt();
	offset += 2;
	date = ID.mid(offset, 2).toInt();
	offset += 4;
	gender = ID.mid(offset, 1).toInt() % 2;

	ui->dateEdit->setDate(QDate(year, month, date));
	if (gender)
	{
		ui->comboBoxGender->setCurrentText(QString::fromLocal8Bit("��"));
	}
	else
	{
		ui->comboBoxGender->setCurrentText(QString::fromLocal8Bit("Ů"));
	}
}
