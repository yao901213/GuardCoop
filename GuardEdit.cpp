#include "GuardEdit.h"
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
	
	ui->pushButtonOk->setShortcut(Qt::Key_Enter);
	ui->pushButtonOk->setShortcut(Qt::Key_Return);
	ui->lineEditIDCardNum->installEventFilter(this);

	this->setModal(true);
	this->show();
}

void GuardEditDiag::InitAddFunc()
{
	QObject::connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(ClickSubmitButtonAddFunc()));
	QObject::connect(ui->pushButtonDelPic, SIGNAL(clicked()), this, SLOT(ClearPhoto()));

	ui->comboBox->setCurrentIndex(0);
	InitDateEdit();
}

void GuardEditDiag::InitModFunc()
{
	QSqlRecord record;

	QObject::connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(ClickSubmitButtonModFunc()));
	QObject::connect(ui->pushButtonDelPic, SIGNAL(clicked()), this, SLOT(ClickDelPicButton()));

	model->select();
	record = model->record(CurRowIndex);

	ui->comboBox->setCurrentText(record.value("WorkPosition").toString());
	ui->lineEditID->setText(record.value("EmployeeID").toString());
	ui->lineEditID->setEnabled(false);
	ui->lineEditName->setText(record.value("Name").toString());
	ui->lineEditIDCardNum->setText(record.value("IDCardNum").toString());
	ui->comboBoxGender->setCurrentText(record.value("Gender").toString());
	ui->dateEdit_Employ->setDate(record.value("DateofEmploy").toDate());
	ui->dateEdit->setDate(record.value("DateofBirth").toDate());

	QPixmap photo; 
	photo.loadFromData(record.value("Photo").toByteArray(), "JPG");
	ui->labelPic->setPixmap(photo);
	ui->labelPic->setScaledContents(true);
}

void GuardEditDiag::InitDateEdit()
{
	ui->dateEdit_Employ->setDate(QDate::currentDate());
	//ui->dateEdit_Employ->setEnabled(false);
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
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("输入姓名不是纯中文"), 2);
		ui->lineEditName->setText(record.value("Name").toString());
		return;
	}

	record.setValue("EmployeeID", ui->lineEditID->text());

	//varbinary在读取之后重新通过model存入库中，出现数据格式不一致的问题，使用query单独插入数据，规避问题
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

	queryStr = tr("UPDATE HumanResource.Guard SET DateofEmploy = '%1'"
		"WHERE EmployeeID = %2").arg(ui->dateEdit_Employ->text()).arg(ID);
	query.prepare(queryStr);
	query.exec();

	if (!ui->lineEditPhoto->text().isEmpty())
	{
		if (!InfoCheck::IsPicPathValid(ui->lineEditPhoto->text()))
			return;
		QFile file(ui->lineEditPhoto->text());
		file.open(QIODevice::ReadOnly);
		QByteArray data = file.readAll();
		QVariant var(data);
		record.setValue("Photo", var);
		model->setRecord(CurRowIndex, record);
		model->submitAll();
	}

	this->accept();
}

void GuardEditDiag::ClickSubmitButtonAddFunc()
{
	int totalnum = 0;
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
	totalnum = model->rowCount();
	QSqlRecord record = model->record();

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
	record.setValue("Gender", ui->comboBoxGender->currentText());
	record.setValue("DateofEmploy", ui->dateEdit_Employ->text());
	record.setValue("DateofBirth", ui->dateEdit->text());

	if (!ui->lineEditPhoto->text().isEmpty())
	{
		if (!InfoCheck::IsPicPathValid(ui->lineEditPhoto->text()))
			return;
		QFile file(ui->lineEditPhoto->text());
		file.open(QIODevice::ReadOnly);
		QByteArray data = file.readAll();
		QVariant var(data);
		record.setValue("Photo", var);
	}

	model->insertRecord(totalnum, record);
	qDebug() << model->lastError().text();
	model->submitAll();
	qDebug() << model->lastError().text();

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
	QString GenderStr;
	InfoCheck::GetBirthAndGenderFromID(ID, *ui->dateEdit, GenderStr);

	ui->comboBoxGender->setCurrentText(GenderStr);
}

void GuardEditDiag::ClickDelPicButton()
{
	QMessageBox box;
	box.setWindowTitle(QString::fromLocal8Bit("提醒"));
	box.setText(QString::fromLocal8Bit("确定删除图片?"));
	box.setIcon(QMessageBox::Information);
	box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	box.setButtonText(QMessageBox::Ok, QString::fromLocal8Bit("确定"));
	box.setButtonText(QMessageBox::Cancel, QString::fromLocal8Bit("取消"));
	if (QMessageBox::Cancel == box.exec())
	{
		return;
	}

	ClearPhoto();

	QString querystr = tr("UPDATE HumanResource.Guard SET Photo = NULL WHERE EmployeeID = %1").
		arg(ui->lineEditID->text().toInt());
	QSqlQuery query;
	query.prepare(querystr);
	if (!query.exec())
	{
		qDebug() << query.lastError().text();
	}

}

void GuardEditDiag::ClearPhoto()
{
	ui->labelPic->clear();
	ui->lineEditPhoto->clear();
}


