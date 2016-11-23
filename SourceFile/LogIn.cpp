#include "LogIn.h"
#include "ErrorProc.h"
#include "Connect2DB.h"
#include <QSqlQuery>
#include <QSqlTableModel>

QString AdminAccount = "";

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
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请选择用户类型"), 2);
		return false;
	}

	return true;
}


void LogInDialog:: InitForm()
{
	if (!connectDb.Connect2DB())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("连接数据库失败"), 2);
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
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请输入用户名和密码"), 2);
		return;
	}

	//用户
	QSqlTableModel model;
	if (ui->radioButton->isChecked())
	{
		model.setTable("HumanResource.GuestAccount");
	}
	else if (ui->radioButton_2->isChecked())
	{
		//处理管理员账号
		model.setTable("HumanResource.AdminAccount");
		AdminAccount = ui->lineEdit->text();
		g_IsAdminAccount = true;
	}
	else
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("请选择登录身份"), 2);

		return;
	}

	model.setFilter(QObject::tr("Account = '%1' AND Password = '%2'")
		.arg(ui->lineEdit->text().trimmed()).arg(ui->lineEdit_3->text().trimmed()));
	model.select();

	if (1 == model.rowCount())
	{
		//登录成功
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("登录成功"), 0);

		this->accept();
	}
	else
	{
		model.setFilter(QObject::tr("Account = '%1'")
			.arg(ui->lineEdit->text().trimmed()));
		model.select();
		if (1 == model.rowCount())
		{
			ErrorProc::PopMessageBox(&QString::fromLocal8Bit("密码错误"), 2);

			ui->lineEdit_3->clear();
			ui->lineEdit_3->setFocus();
			return;
		}
		else
		{
			ErrorProc::PopMessageBox(&QString::fromLocal8Bit("不存在该用户名"), 2);

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
