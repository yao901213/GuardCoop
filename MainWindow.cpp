#include "MainWindow.h"
#include "GlobalVar.h"
#include <QObject>
#include <QFile>

bool g_IsAdminAccount = false;
#define TOP_PIC_PATH "Resource/TopPic.jpg"
const QString strPos = QString::fromLocal8Bit("��ǰλ�ã�");


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
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�������ݿ�ʧ��"), 2);
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
	propertyLoan = new PropertyLoan();
	car = new Car();
	contractService = new ContractService();

	ContractServiceIndex = ui->stackedWidget->addWidget(contractService);
	CompanyInfoIndex = ui->stackedWidget->addWidget(CompanyInfo);
	PhoneBookIndex = ui->stackedWidget->addWidget(phonebook);
	GuardInfoIndex = ui->stackedWidget->addWidget(GuardInfo);
	GuardCompanyIndex = ui->stackedWidget->addWidget(GuardCompanyInfo);
	GuardPositionIndex = ui->stackedWidget->addWidget(GuardPosition);
	PropertyEmployeeIndex = ui->stackedWidget->addWidget(propertyEmployee);
	PropertyToolIndex = ui->stackedWidget->addWidget(propertyTool);
	PropertyLoanIndex = ui->stackedWidget->addWidget(propertyLoan);
	CarIndex = ui->stackedWidget->addWidget(car);
}

//should be called after InitStackedWidget
void MainWindow::InitConnection()
{
	//stacked widget�л�֮�����ͨѶ¼�е�����
	QObject::connect(ui->stackedWidget, SIGNAL(currentChanged(int)), phonebook, SLOT(ClearLineEdit()));

	//�л�ҳ��
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
	QObject::connect(ui->pushButtonPropertyUse, SIGNAL(clicked()), this, SLOT(StackWidgetSwitch2PropertyLoan()));
	QObject::connect(ui->pushButtonCar, SIGNAL(clicked()), this, SLOT(StackWidgetSwitch2Car()));
	QObject::connect(ui->pushButtonContractService, SIGNAL(clicked()), this, SLOT(StackWidgetSwitch2ContractService()));

	//�Լ����ı�ҳ��ĳ�ʼ��
	QObject::connect(ui->pushButtonCompany, SIGNAL(clicked()), CompanyInfo, SLOT(InitCompanyInfo()));
	QObject::connect(ui->pushButtonInstitution, SIGNAL(clicked()), CompanyInfo, SLOT(InitInstitutionInfo()));
	QObject::connect(ui->pushButtonLaw, SIGNAL(clicked()), CompanyInfo, SLOT(InitLawInfo()));
	QObject::connect(ui->pushButtonRules, SIGNAL(clicked()), CompanyInfo, SLOT(InitRulesInfo()));

	//�ı�ҳ��ĵ�ǰλ��Label���ı�����
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
	QString str = QString::fromLocal8Bit("��˾���->ͨѶ¼");
	ui->labelPosition->setText(strPos + str);

	ui->stackedWidget->setCurrentIndex(PhoneBookIndex);
	phonebook->ShowPhoneBook();
}

void MainWindow::StackWidgetSwitch2GuardInfo()
{
	QString str = QString::fromLocal8Bit("��������->��Ա��Ϣ");
	ui->labelPosition->setText(strPos + str);

	ui->stackedWidget->setCurrentIndex(GuardInfoIndex);
	GuardInfo->ShowDbData();
	GuardInfo->ClearLineEdit();
}

void MainWindow::StackWidgetSwitch2GuardCompany()
{
	QString str = QString::fromLocal8Bit("��������->�ͻ���λ");
	ui->labelPosition->setText(strPos + str);

	ui->stackedWidget->setCurrentIndex(GuardCompanyIndex);
	GuardCompanyInfo->ShowDbData();
	GuardCompanyInfo->ResetComboBox();
}

void MainWindow::StackWidgetSwitch2GuardPosition()
{
	QString str = QString::fromLocal8Bit("��������->�ڵ�ֲ�");
    ui->labelPosition->setText(strPos + str);

	ui->stackedWidget->setCurrentIndex(GuardPositionIndex);
}

void MainWindow::StackWidgetSwitch2PropertyTool()
{
	QString str = QString::fromLocal8Bit("��������->���ʹ���");
	ui->labelPosition->setText(strPos + str);
	ui->stackedWidget->setCurrentIndex(PropertyToolIndex);
	propertyTool->UpdateTable();
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
	QString str = QString::fromLocal8Bit("��˾���->��˾���");
	ui->labelPosition->setText(strPos + str);
}

void MainWindow::SetLabelPosInstitution()
{
	QString str = QString::fromLocal8Bit("��˾���->��������");
	ui->labelPosition->setText(strPos + str);
}

void MainWindow::SetLabelPosLaw()
{
	QString str = QString::fromLocal8Bit("��˾���->���ɷ���");
	ui->labelPosition->setText(strPos + str);
}

void MainWindow::SetLabelPosRule()
{
	QString str = QString::fromLocal8Bit("��˾���->�����ƶ�");
	ui->labelPosition->setText(strPos + str);
}

void MainWindow::StackWidgetSwitch2PropertyEmployee()
{
	QString str = QString::fromLocal8Bit("��ҵ����->��Ա��Ϣ");
	ui->labelPosition->setText(strPos + str);

	ui->stackedWidget->setCurrentIndex(PropertyEmployeeIndex);
	propertyEmployee->UpdateTable();
}

void MainWindow::StackWidgetSwitch2PropertyLoan()
{
	QString str = QString::fromLocal8Bit("��ҵ����->��������");
	ui->labelPosition->setText(strPos + str);

	ui->stackedWidget->setCurrentIndex(PropertyLoanIndex);
	propertyLoan->UpdateTable();
}

void MainWindow::StackWidgetSwitch2Car()
{
	QString str = QString::fromLocal8Bit("�������->������Ϣ");
	ui->labelPosition->setText(strPos + str);

	ui->stackedWidget->setCurrentIndex(CarIndex);
	car->UpdateTable();
}

void MainWindow::StackWidgetSwitch2ContractService()
{
	QString str = QString::fromLocal8Bit("��������->�����ͬ");
	ui->labelPosition->setText(strPos + str);

	ui->stackedWidget->setCurrentIndex(ContractServiceIndex);

	//ftp = new Ftp();
	//ftp->SetUrl(QString("ftp://localhost/111.txt"));
	//ftp->SetLocalFile(QString("E:\\1.txt"));
	//ftp->Upload();
}