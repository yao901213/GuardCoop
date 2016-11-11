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
		MessageBox.setWindowTitle(QString::fromLocal8Bit("��ʾ"));
		break;
	case 1:
		MessageBox.setIcon(QMessageBox::Warning);
		MessageBox.setWindowTitle(QString::fromLocal8Bit("����"));
		break;
	case 2:
		MessageBox.setWindowTitle(QString::fromLocal8Bit("����"));
		MessageBox.setIcon(QMessageBox::Critical);
		break;
	default:
		MessageBox.setIcon(QMessageBox::Information);
	}

	MessageBox.setFocus();
	MessageBox.setText(*MessString);
	MessageBox.setStandardButtons(QMessageBox::Ok);
	MessageBox.setButtonText(QMessageBox::Ok, QString::fromLocal8Bit("ȷ��"));
	MessageBox.exec();

	return;
}