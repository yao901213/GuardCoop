#include "ModTextInfo.h"
#include "ErrorProc.h"
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

ModTextInfoDiag::ModTextInfoDiag(QDialog *parent):
	QDialog(parent)
{
	ui = new Ui_DialogModText;
	model = new QSqlTableModel;
	PageType = PAGE_BUT;

	ui->setupUi(this);
}

ModTextInfoDiag::~ModTextInfoDiag()
{
	delete ui;
	delete model;
}

void ModTextInfoDiag::InitModTextInfoDiag()
{	
	QString *textType = new QString;

	GetPageType(textType);
	
	model->setTable("HumanResource.Text");
	model->select();
	
	if (1 != model->rowCount())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("没有找到对应的文本信息"), 2);
		return;
	}

	ui->textEdit->setText(model->record(0).value(*textType).toString());
	QObject::connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(SubmitModTextInfo()));
	
	this->setModal(true);
	this->show();

	delete textType;
}

void ModTextInfoDiag::GetPageType(QString *textType)
{
	switch (PageType)
	{
	case PAGE_COMPANY:
		*textType = "CompanyInfo";
		break;

	case PAGE_INSTITUTION:
		*textType = "InstitutionInfo";
		break;

	case PAGE_LAW:
		*textType = "LawInfo";
		break;

	case PAGE_RULE:
		*textType = "RuleInfo";
		break;

	default:
		break;
	}
}



void ModTextInfoDiag::SubmitModTextInfo()
{
	QSqlQuery query;
	QString textType;
	GetPageType(&textType);
	QString prepare("UPDATE HumanResource.Text SET "); 

	prepare += textType;
	prepare += QString(" = '");
	prepare += ui->textEdit->toPlainText();
	prepare += QString("'");
	query.prepare(prepare);
	if (!query.exec())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("修改文本内容失败"), 2);
		qDebug() << query.lastError().text();

		return;
	}
	ErrorProc::PopMessageBox(&QString::fromLocal8Bit("修改成功"), 0);
	this->accept();

	return;
}
