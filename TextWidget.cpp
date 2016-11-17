#include "TextWidget.h"
#include "ErrorProc.h"
#include "GlobalVar.h"
#include <QSqlRecord>
#include <QRect>
#include <QObject>

TextWidget::TextWidget(QWidget *parent):
	QWidget(parent),
	ui(new Ui_TextWidget)
{
	model = new QSqlTableModel;
	model->setTable("HumanResource.Text");
	CurrentPageType = PAGE_BUT;
	ui->setupUi(this);
	InitTextWidget();
}

TextWidget::~TextWidget()
{
	delete ui;
	delete model;
}

void TextWidget::SetLabelTextInfo(QString *TextType)
{
	QVariant companyInfo;

	model->select();

	if (model->rowCount() == 0)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("û�������ݿ����ҵ���Ӧ������"), 2);
		return;
	}

	companyInfo = model->record(0).value(*TextType);

	ui->label_2->setText(QString("    ") + companyInfo.toString());
	ui->label_2->adjustSize();
	ui->label_2->setWordWrap(true);
	ui->label_2->setAlignment(Qt::AlignTop);
}

void TextWidget::GetCurrentPageType(QString *textType)
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

void TextWidget::GetTextInfoFromDb()
{
	QString textType;
	GetCurrentPageType(&textType);
	SetLabelTextInfo(&textType);
}

void TextWidget::InitCompanyInfo()
{
	SetCurrentPage(PAGE_COMPANY);
	GetTextInfoFromDb();
	ui->label->setText(QString::fromLocal8Bit("��˾���"));
}

void TextWidget::InitInstitutionInfo()
{
	SetCurrentPage(PAGE_INSTITUTION);
	GetTextInfoFromDb();
	ui->label->setText(QString::fromLocal8Bit("��������"));
}

void TextWidget::InitRulesInfo()
{
	SetCurrentPage(PAGE_RULE);
	GetTextInfoFromDb();
	ui->label->setText(QString::fromLocal8Bit("�����ƶ�"));
}

void TextWidget::InitLawInfo()
{
	SetCurrentPage(PAGE_LAW);
	GetTextInfoFromDb();
	ui->label->setText(QString::fromLocal8Bit("���ɷ���"));
}

void TextWidget::ConstrainGuestAccount()
{
	ui->pushButton->setEnabled(false);
	ui->pushButton->setToolTip(QString::fromLocal8Bit("��ǰ���ǹ���Ա�˺ŵ�¼�����ܶ����ݽ����޸�"));
}

void TextWidget::InitTextWidget()
{
	QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(ModifyText()));
	ui->pushButton->setShortcut(Qt::Key_Enter);
	ui->pushButton->setShortcut(Qt::Key_Return);

	return;
}

void TextWidget::ModifyText()
{
	if (!g_IsAdminAccount)
	{
		return;
	}

	ModDialog = new ModTextInfoDiag();
	QObject::connect(ModDialog, SIGNAL(accepted()), this, SLOT(GetTextInfoFromDb()));
	ModDialog->PageType = CurrentPageType;
	ModDialog->InitModTextInfoDiag();

	return;
}
