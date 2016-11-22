#include "MainWindow.h"
#include "GlobalVar.h"
#include <QObject>
#include <QFile>

bool g_IsAdminAccount = false;
#define TOP_PIC_PATH "Resource/TopPic.jpg"
const QString strPos = QString::fromLocal8Bit("当前位置：");


MainWindow::MainWindow(QWidget *parent):
	QWidget(parent)
{
	ui = new Ui_Form;

	ui->setupUi(this);
	InitForm();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::InitForm()
{
	if (!connectDB.Connect2DB())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("连接数据库失败"), 2);
		return;
	}
	InitTopPic();
	InitStackedWidget();
	InitConnection();
}

void MainWindow::InitStackedWidget()
{
	CompanyInfo = new TextWidget();
	phonebook = new PhoneBook();
	GuardInfo = new GuardWidget();
	GuardCompanyInfo = new GuardCompany();
	GuardPosition = new GuardPosWidget();
	propertyEmployee = new PropertyEmployee();
	propertyTool = new PropertyTool();

	CompanyInfoIndex = ui->stackedWidget->addWidget(CompanyInfo);
	PhoneBookIndex = ui->stackedWidget->addWidget(phonebook);
	GuardInfoIndex = ui->stackedWidget->addWidget(GuardInfo);
	GuardCompanyIndex = ui->stackedWidget->addWidget(GuardCompanyInfo);
	GuardPositionIndex = ui->stackedWidget->addWidget(GuardPosition);
	PropertyEmployeeIndex = ui->stackedWidget->addWidget(propertyEmployee);
	PropertyToolIndex = ui->stackedWidget->addWidget(propertyTool);
}

//should be called after InitStackedWidget
void MainWindow::InitConnection()
{
	//stacked widget切换之后清空通讯录中的内容
	QObject::connect(ui->stackedWidget, SIGNAL(currentChanged(int)), phonebook, SLOT(ClearLineEdit()));

	//切换页面
	QObject::connect(ui->pushButtonCompany, SIGNAL(clicked()), this, SLOT(StackWidgetSwitch2CompanyInfo()));
	QObject::connect(ui->pushButtonInstitution, SIGNAL(clicked()), this, SLOT(StackWidgetSwitch2CompanyInfo()));
	QObject::connect(ui->pushButtonLaw, SIGNAL(clicked()), this, SLOT(StackWidgetSwitch2CompanyInfo()));
	QObject::connect(ui->pushButtonRules, SIGNAL(clicked()), this, SLOT(StackWidgetSwitch2CompanyInfo()));
	QObject::connect(ui->pushButtonPhoneBook, SIGNAL(clicked()), this, SLOT(StackWidgetSwitch2PhoneBook()));
	QObject::connect(ui->pushButtonGuardInfo, SIGNAL(clicked()), this, SLOT(StackWidgetSwitch2GuardInfo()));
	QObject::connect(ui->pushButtonGuardCompanyInfo, SIGNAL(clicked()), this, SLOT(StackWidgetSwitch2GuardCompany()));
	QObject::connect(ui->pushButtonGuardPosition, SIGNAL(clicked()), this, SLOT(StackWidgetSwitch2GuardPosition()));
	QObject::connect(ui->pushButtonPropertyEmployee, SIGNAL(clicked()), this, SLOT(StackWidgetSwitch2PropertyEmployee()));
	QObject::connect(ui->pushButtonPropertyTool, SIGNAL(clicked()), this, SLOT(StackWidgetSwitch2PropertyTool()));

	//对几个文本页面的初始化
	QObject::connect(ui->pushButtonCompany, SIGNAL(clicked()), CompanyInfo, SLOT(InitCompanyInfo()));
	QObject::connect(ui->pushButtonInstitution, SIGNAL(clicked()), CompanyInfo, SLOT(InitInstitutionInfo()));
	QObject::connect(ui->pushButtonLaw, SIGNAL(clicked()), CompanyInfo, SLOT(InitLawInfo()));
	QObject::connect(ui->pushButtonRules, SIGNAL(clicked()), CompanyInfo, SLOT(InitRulesInfo()));

	//文本页面的当前位置Label的文本设置
	QObject::connect(ui->pushButtonCompany, SIGNAL(clicked()), this, SLOT(SetLabelPosCompanyInfo()));
	QObject::connect(ui->pushButtonInstitution, SIGNAL(clicked()), this, SLOT(SetLabelPosInstitution()));
	QObject::connect(ui->pushButtonLaw, SIGNAL(clicked()), this, SLOT(SetLabelPosLaw()));
	QObject::connect(ui->pushButtonRules, SIGNAL(clicked()), this, SLOT(SetLabelPosRule()));

}

void MainWindow::InitTopPic()
{
	QFile file(TOP_PIC_PATH);
	QByteArray data;
	file.open(QIODevice::ReadOnly);
	data = file.readAll();
	file.close();
	//QVariant var(data);
	QPixmap photo;
	photo.loadFromData(data, "JPG");
	ui->labelTopPic->setPixmap(photo);
	ui->labelTopPic->setScaledContents(true);
}


void MainWindow::StackWidgetSwitch2CompanyInfo()
{
	ui->stackedWidget->setCurrentIndex(CompanyInfoIndex);
}

void MainWindow::StackWidgetSwitch2PhoneBook()
{
	QString str = QString::fromLocal8Bit("公司相关->通讯录");
	ui->labelPosition->setText(strPos + str);

	ui->stackedWidget->setCurrentIndex(PhoneBookIndex);
	phonebook->ShowPhoneBook();
}

void MainWindow::StackWidgetSwitch2GuardInfo()
{
	QString str = QString::fromLocal8Bit("保安服务->人员信息");
	ui->labelPosition->setText(strPos + str);

	ui->stackedWidget->setCurrentIndex(GuardInfoIndex);
	GuardInfo->ShowDbData();
	GuardInfo->ClearLineEdit();
}

void MainWindow::StackWidgetSwitch2GuardCompany()
{
	QString str = QString::fromLocal8Bit("保安服务->客户单位");
	ui->labelPosition->setText(strPos + str);

	ui->stackedWidget->setCurrentIndex(GuardCompanyIndex);
	GuardCompanyInfo->ShowDbData();
	GuardCompanyInfo->ResetComboBox();
}

void MainWindow::StackWidgetSwitch2GuardPosition()
{
	QString str = QString::fromLocal8Bit("保安服务->岗点分布");
    ui->labelPosition->setText(strPos + str);

	ui->stackedWidget->setCurrentIndex(GuardPositionIndex);
}

void MainWindow::StackWidgetSwitch2PropertyTool()
{
	QString str = QString::fromLocal8Bit("保安服务->工具统计");
	ui->labelPosition->setText(strPos + str);
	ui->stackedWidget->setCurrentIndex(PropertyToolIndex);
}

void MainWindow::ConstrainGuestAccount()
{
	if (g_IsAdminAccount)
	{
		return;
	}
	CompanyInfo->ConstrainGuestAccount();
	phonebook->ConstrainGuestAccount();
	GuardInfo->ConstrainGuestAccount();
	GuardCompanyInfo->ConstrainGuestAccount();
}

void MainWindow::SetLabelPosCompanyInfo()
{
	QString str = QString::fromLocal8Bit("公司相关->公司简介");
	ui->labelPosition->setText(strPos + str);
}

void MainWindow::SetLabelPosInstitution()
{
	QString str = QString::fromLocal8Bit("公司相关->机构设置");
	ui->labelPosition->setText(strPos + str);
}

void MainWindow::SetLabelPosLaw()
{
	QString str = QString::fromLocal8Bit("公司相关->法律法规");
	ui->labelPosition->setText(strPos + str);
}

void MainWindow::SetLabelPosRule()
{
	QString str = QString::fromLocal8Bit("公司相关->规章制度");
	ui->labelPosition->setText(strPos + str);
}

void MainWindow::StackWidgetSwitch2PropertyEmployee()
{
	QString str = QString::fromLocal8Bit("物业服务->人员信息");
	ui->labelPosition->setText(strPos + str);

	ui->stackedWidget->setCurrentIndex(PropertyEmployeeIndex);
}
