#include "Connect2DB.h"

bool DB::Connect2DB()
{
	db = QSqlDatabase::addDatabase("QODBC");
	if (!db.isValid())
	{
		QMessageBox::critical(0,
			QString::fromLocal8Bit("错误"),
			QString::fromLocal8Bit("当前驱动不可用"),
			QMessageBox::Ok);
		qDebug() << "the sql driver validity is " << db.isValid();
		return false;
	}
	QString dsn = QString::fromLocal8Bit("DRIVER={SQL SERVER};SERVER=localhost;DATABASE=PSBData");
	db.setDatabaseName(dsn);
	db.setHostName("localhost");
	db.setDatabaseName("PSBData");
	db.setUserName("sa");
	db.setPassword("1");

	return true;
};