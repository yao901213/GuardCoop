#include "LogInDialog.h"
#include "ErrorProc.h"
#include "Connect2DB.h"
#include <QSqlQuery>
#include <QSqlTableModel>


LogInDialog::LogInDialog(QWidget *parent):
	QDialog(parent)
{
	ui = new Ui_Dialog;
	ui->setupUi(this);
	InitForm();

}

LogInDialog::~LogInDialog()
{
	delete ui;
}

bool LogInDialog::IsRadioButtonSelected()
{
	if (!ui->radioButton->isChecked()
		&& !ui->radioButton_2->isChecked())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��ѡ���û�����"), 2);
		return false;
	}

	return true;
}


void LogInDialog:: InitForm()
{
	if (!connectDb.Connect2DB())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�������ݿ�ʧ��"), 2);
		return;
	}
	QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(ClickLoginButton()));
	QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(ClickRegisterButton()));
	QObject::connect(ui->pushButtonChangePwd, SIGNAL(clicked()), this, SLOT(ClickChangeButton()));
	ui->pushButton->setShortcut(Qt::Key_Enter);
	ui->pushButton->setShortcut(Qt::Key_Return);

	ui->radioButton->setChecked(true);

	return;
}

void LogInDialog::TestTemp()
{
	ui->lineEdit->setText(QString("admin"));
	ui->lineEdit_3->setText(QString("admin"));
	ui->radioButton_2->setChecked(true);
}

void LogInDialog::ClickLoginButton()
{
	///////////////////////
	TestTemp();
	//////////////////////
	
	if (ui->lineEdit->text().trimmed().isEmpty()  
		|| ui->lineEdit_3->text().trimmed().isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�������û���������"), 2);
		return;
	}

	//�û�
	QSqlTableModel model;
	if (ui->radioButton->isChecked())
	{
		model.setTable("HumanResource.GuestAccount");
	}
	else if (ui->radioButton_2->isChecked())
	{
		//�������Ա�˺�
		model.setTable("HumanResource.AdminAccount");
		g_IsAdminAccount = true;
	}
	else
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��ѡ���¼���"), 2);

		return;
	}

	model.setFilter(QObject::tr("Account = '%1' AND Password = '%2'")
		.arg(ui->lineEdit->text().trimmed()).arg(ui->lineEdit_3->text().trimmed()));
	model.select();

	if (1 == model.rowCount())
	{
		//��¼�ɹ�
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("��¼�ɹ�"), 0);

		this->accept();
	}
	else
	{
		model.setFilter(QObject::tr("Account = '%1'")
			.arg(ui->lineEdit->text().trimmed()));
		model.select();
		if (1 == model.rowCount())
		{
			ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�������"), 2);

			ui->lineEdit_3->clear();
			ui->lineEdit_3->setFocus();
			return;
		}
		else
		{
			ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�����ڸ��û���"), 2);

			ui->lineEdit->clear();
			ui->lineEdit_3->clear();
			return;
		}
	}

	return;
}

void LogInDialog::ClickRegisterButton()
{
	RegisterDiag = new RegisterDialog();
	RegisterDiag->exec();

}

class InitUi
{
public:
	explicit InitUi();
	~InitUi();
	LogInDialog *login;
	MainWindow *window;
};

InitUi::InitUi()
{
	login = new LogInDialog();
	window = new MainWindow();
}

InitUi::~InitUi()
{
	delete login;
	delete window;
}

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	InitUi ui;

	ui.login->show();
	ui.window->hide();
	QObject::connect(ui.login, SIGNAL(accepted()), ui.window, SLOT(show()));
	QObject::connect(ui.login, SIGNAL(rejected()), ui.window, SLOT(close()));
	QObject::connect(ui.login, SIGNAL(accepted()), ui.window, SLOT(ConstrainGuestAccount()));
	
	return app.exec();
}

void LogInDialog::ClickChangeButton()
{
	change = new ChangePwd;
}
