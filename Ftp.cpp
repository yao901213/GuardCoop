#include "Ftp.h"
#include <QDebug>

Ftp::Ftp()
{
	manager = new QNetworkAccessManager;
}

Ftp::~Ftp()
{
	delete manager;
}

void Ftp::Upload()
{
	QUrl Url;
	Url.setUrl(UrlStr);
	Url.setUserName("administrator");
	Url.setPassword("1");
	Url.setPort(21);
	QFile file(file);
	file.open(QIODevice::ReadOnly);
	QByteArray data = file.readAll();
	QNetworkReply *reply = manager->put(QNetworkRequest(Url), data);
	qDebug() << reply->errorString();
}

void Ftp::Download()
{
	
}
