#include "ErrorProc.h"
#include "InfoCheck.h"
#include "ContractServiceEdit.h"
#include <QSqlRecord>
#include <QSqlError>
#include <QFileInfo>
#include <QSqlQuery>
#include <QTextCodec>

const QString strurl = "ftp://localhost/";

ContractServiceEdit::ContractServiceEdit(QString &filter, int index, int sort)
{
	model = new QSqlTableModel;
	model->setTable("HumanResource.ContractService");
	model->setFilter(filter);
	if (-1 != sort)
	{
		model->setSort(sort, Qt::AscendingOrder);
	}
	Index = index;
	ui = new Ui_ContractServiceEdit;
	ui->setupUi(this);

	ftp = new Ftp;

	InitDiag();
}

ContractServiceEdit::~ContractServiceEdit()
{
	delete ui;
	delete model;
}

void ContractServiceEdit::InitDiag()
{
	ui->comboBoxType->addItem(QString::fromLocal8Bit(""));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("保安服务"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("物业管理"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("联网报警"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("金融网点巡查"));
	ui->comboBoxType->addItem(QString::fromLocal8Bit("科技工程"));

	QObject::connect(ui->pushButtonCancel, SIGNAL(clicked()), this, SLOT(reject()));

	this->setModal(true);
	this->show();
}

void ContractServiceEdit::InitAddFunc()
{
	QObject::connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(ClickOkButtonAddFunc()));

}

void ContractServiceEdit::ClickOkButtonAddFunc()
{
	if (!IsInputValid())
	{
		return;
	}
	QFileInfo fileinfo(ui->lineEditPath->text());
	
	SetFolderName();
	QString url = strurl + strFolder + "/" + QString("_%1").arg(ui->dateEditStart->date().year()) + "." + fileinfo.suffix();

	ftp->SetUrl(strFolder);
	ftp->SetLocalFile(ui->lineEditPath->text());
	ftp->Upload();

	QSqlQuery query;
	query.prepare("SELECT MAX(ID) FROM HumanResource.ContractService");
	query.exec();
	int maxid = query.record().value(0).toInt();

	query.prepare("INSERT INTO HumanResource.ContractService(ID, Name, Type, DateofStart, DateofEnd, Url)"
		"VALUES(NEXT VALUE FOR HumanResource.ContractServiceSeq, :Name, :Type, :DateofStart, :DateofEnd, :Url)");
	query.bindValue(":Name", ui->lineEditName->text());
	query.bindValue(":Type", ui->comboBoxType->currentText());
	query.bindValue(":DateofStart", ui->dateEditStart->text());
	query.bindValue(":DateofEnd", ui->dateEditEnd->text());
	query.bindValue(":Url", url);

	if (!query.exec())
	{
		QString str = QString::fromLocal8Bit("添加数据库错误") + query.lastError().text();
		ErrorProc::PopMessageBox(&str, 2);
	}
	else
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("添加数据库成功"), 0);
		this->accept();
	}
}

void ContractServiceEdit::ClickOkButtonModFunc()
{


}

bool ContractServiceEdit::IsInputValid()
{
	if (ui->lineEditName->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请输入乙方名称"), 2);
		return false;
	}

	if (ui->lineEditPath->text().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请输入文件的路径"), 2);
		return false;
	}

	if (ui->comboBoxType->currentIndex() == 0)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请选择合同类型"), 2);
		return false;
	}

	QFileInfo fileinfo(ui->lineEditPath->text());
	if (!fileinfo.exists())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("输入的路径错误"), 2);
		return false;
	}

	QDate datestart = ui->dateEditStart->date();
	QDate dateend = ui->dateEditEnd->date();
	if (datestart.daysTo(dateend) < 0)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("输入日期有误"), 2);
		return false;
	}

	return true;
}

void ContractServiceEdit::SetFolderName()
{
	switch (ui->comboBoxType->currentIndex())
	{
	case 0:
		return;
	case 1:
		strFolder = "baoan";
		break;
	case 2:
		strFolder = "wuye";
		break;
	case 3:
		strFolder = "baojing";
		break;
	case 4:
		strFolder = "jinrong";
		break;
	case 5:
		strFolder = "keji";
		break;
	default:
		strFolder = "other";
		break;
	}
	strFolder += "/";
}
