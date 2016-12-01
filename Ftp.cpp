#include "Ftp.h"
#include <QDebug>
#include "ErrorProc.h"

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
	connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
	connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(slotError(QNetworkReply::NetworkError))); //可返回错误报告

	if (reply->error() != QNetworkReply::NoError)
	{
		qDebug() << reply->readAll();
	}
}

void Ftp::Download()
{
	
}

void Ftp::replyFinished(QNetworkReply *reply)
{
	if (QNetworkReply::NoError != reply->error())
	{
		qDebug() << reply->errorString();
		QString str = QString::fromLocal8Bit("FTP上传失败,错误码（%1）").arg(Error) + reply->errorString();
		ErrorProc::PopMessageBox(&str, 2);
	}
}
void Ftp::slotError(QNetworkReply::NetworkError error)
{
	Error = error;
	qDebug() << error;
}
