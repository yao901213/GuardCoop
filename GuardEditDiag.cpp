#include "GuardEditDiag.h"
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include "InfoCheck.h"
#include "ErrorProc.h"
#include <QFileDialog>
#include "GlobalVar.h"

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
		if (CurrentName == QString::fromLocal8Bit("临时"))
		{
			continue;
		}
		ui->comboBox->addItem(CurrentName);
	}

	ui->comboBoxGender->addItem(QString::fromLocal8Bit(""));
	ui->comboBoxGender->addItem(QString::fromLocal8Bit("男"));
	ui->comboBoxGender->addItem(QString::fromLocal8Bit("女"));

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

	QPixmap photo;
	photo.loadFromData(record.value("Photo").toByteArray(), "JPG");
	ui->labelPic->setPixmap(photo);
	ui->labelPic->setScaledContents(true);
}

void GuardEditDiag::ClickSubmitButtonModFunc()
{
	model->select();
	QSqlRecord record = model->record(CurRowIndex);

	if (!InfoCheck::IsEmployeeIdCardNumValid(&ui->lineEditIDCardNum->text()))
	{
		ui->lineEditIDCardNum->setText(record.value("IDCardNum").toString());
		return;
	}

	if (!InfoCheck::IsChineseStr(&ui->lineEditName->text()))
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("输入姓名不是纯中文"), 2);
		ui->lineEditName->setText(record.value("Name").toString());
		return;
	}

	record.setValue("EmployeeID", ui->lineEditID->text());
	record.setValue("Name", ui->lineEditName->text());
	record.setValue("WorkPosition", ui->comboBox->currentText());
	record.setValue("IDCardNum", ui->lineEditIDCardNum->text());

	if (!ui->lineEditPhoto->text().isEmpty())
	{
		QFile file(ui->lineEditPhoto->text());
		file.open(QIODevice::ReadOnly);
		QByteArray data = file.readAll();
		QVariant var(data);
		record.setValue("Photo", var);
	}
	else
	{
		//record.setValue("Photo", 0);
	}
	model->setRecord(CurRowIndex, record);
	model->submitAll();

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
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("输入姓名不是纯中文"), 2);
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
		record.setValue("WorkPosition", QString::fromLocal8Bit("暂无"));
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
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("已经存在工号:%1，不能重复添加")
					.arg(ui->lineEditID->text()), 2);
		return false;
	}

	if (0 == model->rowCount())
	{
		return true;
	}
	ErrorProc::PopMessageBox(&QString::fromLocal8Bit("数据库中工号:%1错误")
		.arg(ui->lineEditID->text()), 2);

	return false;
}

void GuardEditDiag::ClickBrowseButton()
{
	QString filename = QFileDialog::getOpenFileName(this,
		QString::fromLocal8Bit("浏览"),
		"D:/", tr("Images(*.jpg)"));
	ui->lineEditPhoto->setText(filename);
}

void GuardEditDiag::ClickPreviewButton()
{
	if (ui->lineEditPhoto->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请选择上传的照片"), 2);
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
				ui->label_IDCardNotition->setText(QString::fromLocal8Bit("校验成功"));
				GetBirthAndGenderFromID();
			}
			else
			{
				ui->label_IDCardNotition->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
				ui->label_IDCardNotition->setText(QString::fromLocal8Bit("身份证号码错误"));
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
	offset += 2;
	gender = ID.mid(offset, 1).toInt() % 2;

	ui->dateEdit->setDate(QDate(year, month, date));
	if (gender)
	{
		ui->comboBoxGender->setCurrentIndex(1);
	}
	else
	{
		ui->comboBoxGender->setCurrentIndex(2);
	}
}
