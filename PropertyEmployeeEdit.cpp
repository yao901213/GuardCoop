#include "PropertyEmployeeEdit.h"
#include "InfoCheck.h"
#include "ErrorProc.h"
#include "GlobalVar.h"
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlError>
#include <QFileDialog>
#include <QDebug>

PropertyEmployeeEdit::PropertyEmployeeEdit(QSqlTableModel *parentmodel, int CurRow)
{
	model = new QSqlTableModel;
	ui = new Ui_PropertyEdit;
	ui->setupUi(this);
	index = CurRow;
	model->setTable("HumanResource.Property");
	model->setFilter(parentmodel->filter());

	InitDiag();
}

PropertyEmployeeEdit::~PropertyEmployeeEdit()
{
	delete ui;
	delete model;
}

void PropertyEmployeeEdit::InitDiag()
{
	ui->comboBoxType->addItem(" ");
	ui->comboBoxType->addItem(strCleaner);
	ui->comboBoxType->addItem(strPlumElec);
	ui->comboBoxType->addItem(strGarden);

	ui->comboBoxGender->addItem(" ");
	ui->comboBoxGender->addItem(QString::fromLocal8Bit("男"));
	ui->comboBoxGender->addItem(QString::fromLocal8Bit("女"));

	ui->comboBox->addItem(QString::fromLocal8Bit("否"));
	ui->comboBox->addItem(QString::fromLocal8Bit("是"));

	ui->comboBox->setCurrentText(QString::fromLocal8Bit("否"));

	ui->lineEditIDCardNum->installEventFilter(this);
	this->setModal(true);
	ui->pushButtonOk->setShortcut(Qt::Key_Enter);
	ui->pushButtonOk->setShortcut(Qt::Key_Return);
	
	QObject::connect(ui->pushButtonBrowse, SIGNAL(clicked()), this, SLOT(ClickBrowseButton()));
	QObject::connect(ui->pushButtonPreview, SIGNAL(clicked()), this, SLOT(ClickPreviewButton()));

	this->show();
}

void PropertyEmployeeEdit::InitAddFunc()
{
	ui->pushButtonLoanDetail->setHidden(true);
	QObject::connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(ClickSubmitButtonAdd()));
	ui->dateEdit_Employ->setDate(QDate::currentDate());
}

void PropertyEmployeeEdit::InitModFunc()
{
	model->select();
	QSqlRecord record;

	record = model->record(index);

	ui->lineEditID->setText(record.value("ID").toString());
	ui->lineEditIDCardNum->setText(record.value("IDCard").toString());
	ui->lineEditName->setText(record.value("Name").toString());
	ui->comboBoxGender->setCurrentText(record.value("Gender").toString());
	ui->comboBoxType->setCurrentText(record.value("Type").toString());
	ui->comboBox->setCurrentText(record.value("Loan").toString());
	ui->dateEdit->setDate(record.value("DateofBirth").toDate());
	ui->dateEdit_Employ->setDate(record.value("DateofEmploy").toDate());

	ui->lineEditID->setEnabled(false);

	QObject::connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(ClickSubmitButtonMod()));
}

void PropertyEmployeeEdit::ClickSubmitButtonMod()
{
	if (!IsInputValid())
	{
		return;
	}


}

void PropertyEmployeeEdit::ClickSubmitButtonAdd()
{
	if (!IsInputValid())
	{
		return;
	}

	if (!IsIDValid())
	{
		ui->lineEditID->clear();
		return;
	}

	model->setFilter("");
	model->select();
	QSqlRecord  record = model->record();
	record.setValue("ID", ui->lineEditID->text());
	record.setValue("Name", ui->lineEditName->text());
	record.setValue("IDCard", ui->lineEditIDCardNum->text());
	record.setValue("Gender", ui->comboBoxGender->currentText());
	record.setValue("DateofBirth", ui->dateEdit->text());
	record.setValue("DateofEmploy", ui->dateEdit_Employ->text());
	record.setValue("Type", ui->comboBoxType->currentText());
	record.setValue("Loan", ui->comboBox->currentText());

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
	model->insertRecord(model->rowCount(), record);
	qDebug() << model->lastError().text();
	if (!model->submitAll())
	{
		QString errormsg = QString::fromLocal8Bit("添加数据库错误") + model->lastError().text();
		ErrorProc::PopMessageBox(&errormsg, 2);

		return;
	}
	this->accept();
}

bool PropertyEmployeeEdit::eventFilter(QObject *obj, QEvent *ev)
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

void PropertyEmployeeEdit::GetBirthAndGenderFromID()
{
	QString gender;
	InfoCheck::GetBirthAndGenderFromID(ui->lineEditIDCardNum->text(), *ui->dateEdit, gender);
	ui->comboBoxGender->setCurrentText(gender);
}

bool PropertyEmployeeEdit::IsIDValid()
{
	model->setFilter(tr("Name = '%1'").arg(ui->lineEditID->text()));
	model->select();
	if (0 != model->rowCount())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("ID已经存在"), 2);  
		return false;
	}
	return true;
}

bool PropertyEmployeeEdit::IsInputValid()
{
	if (!InfoCheck::IsEmployeeIdCardNumValid(&ui->lineEditIDCardNum->text()))
	{
		ui->lineEditIDCardNum->clear();
		return false;
	}

	if (!InfoCheck::IsChineseStr(&ui->lineEditName->text()))
	{
		ui->lineEditName->clear();
		return false;
	}

	return true;
}

void PropertyEmployeeEdit::ClickBrowseButton()
{
	QString filename = QFileDialog::getOpenFileName(this,
		QString::fromLocal8Bit("浏览"),
		"D:/", tr("Images(*.jpg)"));
	ui->lineEditPhoto->setText(filename);
}

void PropertyEmployeeEdit::ClickPreviewButton()
{
	if (ui->lineEditPhoto->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请选择上传的照片"), 2);
		return;
	}

	if (!InfoCheck::IsPicPathValid(ui->lineEditPhoto->text()))
	{
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
