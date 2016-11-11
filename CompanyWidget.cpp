#include "CompanyWidget.h"
#include "ErrorProc.h"
#include "GlobalVar.h"
#include <QSqlRecord>
#include <QRect>
#include <QObject>

CompanyWidget::CompanyWidget(QWidget *parent):
	QWidget(parent),
	ui(new Ui::CompanyWidget)
{
	model = new QSqlTableModel;
	model->setTable("HumanResource.Text");
	CurrentPageType = PAGE_BUT;
	ui->setupUi(this);
	InitCompanyWidget();
}

CompanyWidget::~CompanyWidget()
{
	delete ui;
	delete model;
}

void CompanyWidget::SetLabelTextInfo(QString *TextType)
{
	QVariant companyInfo;

	model->select();

	if (model->rowCount() == 0)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("没有在数据库中找到对应的数据"), 2);
		return;
	}

	companyInfo = model->record(0).value(*TextType);

	ui->label_2->setText(QString("    ") + companyInfo.toString());
	ui->label_2->adjustSize();
	ui->label_2->setWordWrap(true);
	ui->label_2->setAlignment(Qt::AlignTop);
}

void CompanyWidget::GetCurrentPageType(QString *textType)
{
	switch (CurrentPageType)
	{
	case PAGE_COMPANY:
		*textType = QString("CompanyInfo");
		break;

	case PAGE_INSTITUTION:
		*textType = QString("InstitutionInfo");
		break;

	case PAGE_LAW:
		*textType = QString("LawInfo");
		break;

	case PAGE_RULE:
		*textType = QString("RuleInfo");
		break;

	default:
		break;
	}
}

void CompanyWidget::GetTextInfoFromDb()
{
	QString textType;
	GetCurrentPageType(&textType);
	SetLabelTextInfo(&textType);
}

void CompanyWidget::InitCompanyInfo()
{
	SetCurrentPage(PAGE_COMPANY);
	GetTextInfoFromDb();
	ui->label->setText(QString::fromLocal8Bit("公司简介"));
}

void CompanyWidget::InitInstitutionInfo()
{
	SetCurrentPage(PAGE_INSTITUTION);
	GetTextInfoFromDb();
	ui->label->setText(QString::fromLocal8Bit("机构设置"));
}

void CompanyWidget::InitRulesInfo()
{
	SetCurrentPage(PAGE_RULE);
	GetTextInfoFromDb();
	ui->label->setText(QString::fromLocal8Bit("规章制度"));
}

void CompanyWidget::InitLawInfo()
{
	SetCurrentPage(PAGE_LAW);
	GetTextInfoFromDb();
	ui->label->setText(QString::fromLocal8Bit("法律法规"));
}

void CompanyWidget::ConstrainGuestAccount()
{
	ui->pushButton->setEnabled(false);
	ui->pushButton->setToolTip(QString::fromLocal8Bit("当前不是管理员账号登录，不能对内容进行修改"));
}

void CompanyWidget::InitCompanyWidget()
{
	QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(ModifyText()));
	ui->pushButton->setShortcut(Qt::Key_Enter);
	ui->pushButton->setShortcut(Qt::Key_Return);

	return;
}

void CompanyWidget::ModifyText()
{
	if (!g_IsAdminAccount)
	{
		return;
	}

	ModDialog = new ModTextInfoDiag();
	ModDialog->show();
	QObject::connect(ModDialog, SIGNAL(accepted()), this, SLOT(GetTextInfoFromDb()));
	ModDialog->PageType = CurrentPageType;
	ModDialog->InitModTextInfoDiag();

	return;
}
