#include "ErrorProc.h"
#include "GlobalVar.h"

void ErrorProc::PopMessageBox(QString *MessString, int Type)
{
	if (!StaticCheck)
	{
		return;
	}

	QMessageBox MessageBox;

	switch (Type)
	{
	case 0:
		MessageBox.setIcon(QMessageBox::Information);
		MessageBox.setWindowTitle(QString::fromLocal8Bit("提示"));
		break;
	case 1:
		MessageBox.setIcon(QMessageBox::Warning);
		MessageBox.setWindowTitle(QString::fromLocal8Bit("警告"));
		break;
	case 2:
		MessageBox.setWindowTitle(QString::fromLocal8Bit("错误"));
		MessageBox.setIcon(QMessageBox::Critical);
		break;
	default:
		MessageBox.setIcon(QMessageBox::Information);
	}

	MessageBox.setFocus();
	MessageBox.setText(*MessString);
	MessageBox.setStandardButtons(QMessageBox::Ok);
	MessageBox.setButtonText(QMessageBox::Ok, QString::fromLocal8Bit("确定"));
	MessageBox.exec();

	return;
}