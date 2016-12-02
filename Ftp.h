#pragma once
#ifndef FTP_H
#define FTP_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QFile>

class Ftp :public QObject
{
	Q_OBJECT
public:
	Ftp();
	~Ftp();
	void Upload();
	void Download(QByteArray &data);
	inline void SetUrl(QString &urlstr) { UrlStr = urlstr; };
	inline void SetLocalFile(QString &path) { file = path; };
private:
	QNetworkAccessManager *manager;
	QString UrlStr;
	QString file;
	QString Error;
	private slots:
	void replyFinished(QNetworkReply *);
	void slotError(QNetworkReply::NetworkError);
};



#endif