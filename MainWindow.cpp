#include "MainWindow.h"
#include "GlobalVar.h"
#include <QObject>
#include <QFile>

bool g_IsAdminAccount = false;
#define TOP_PIC_PATH "Resource/TopPic.jpg"

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
	CompanyInfo = new CompanyWidget();
	phonebook = new PhoneBook();
	GuardInfo = new GuardWidget();
	GuardCompanyInfo = new GuardCompany();
	GuardPosition = new MapWidget();

	CompanyInfoIndex = ui->stackedWidget->addWidget(CompanyInfo);
	PhoneBookIndex = ui->stackedWidget->addWidget(phonebook);
	GuardInfoIndex = ui->stackedWidget->addWidget(GuardInfo);
	GuardCompanyIndex = ui->stackedWidget->addWidget(GuardCompanyInfo);
	GuardPositionIndex = ui->stackedWidget->addWidget(GuardPosition);

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

	//对几个文本页面的初始化
	QObject::connect(ui->pushButtonCompany, SIGNAL(clicked()), CompanyInfo, SLOT(InitCompanyInfo()));
	QObject::connect(ui->pushButtonInstitution, SIGNAL(clicked()), CompanyInfo, SLOT(InitInstitutionInfo()));
	QObject::connect(ui->pushButtonLaw, SIGNAL(clicked()), CompanyInfo, SLOT(InitLawInfo()));
	QObject::connect(ui->pushButtonRules, SIGNAL(clicked()), CompanyInfo, SLOT(InitRulesInfo()));

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
	GuardCompanyInfo->ShowDbData();
	GuardCompanyInfo->ResetComboBox();
}

void MainWindow::StackWidgetSwitch2PhoneBook()
{
	ui->stackedWidget->setCurrentIndex(PhoneBookIndex);
	phonebook->ShowPhoneBook();
}

void MainWindow::StackWidgetSwitch2GuardInfo()
{
	ui->stackedWidget->setCurrentIndex(GuardInfoIndex);
	GuardInfo->ShowDbData();
	GuardInfo->ClearLineEdit();
}

void MainWindow::StackWidgetSwitch2GuardCompany()
{
	ui->stackedWidget->setCurrentIndex(GuardCompanyIndex);
	GuardCompanyInfo->ShowDbData();
	GuardCompanyInfo->ResetComboBox();
}

void MainWindow::StackWidgetSwitch2GuardPosition()
{
	ui->stackedWidget->setCurrentIndex(GuardPositionIndex);
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