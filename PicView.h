#pragma once
#ifndef PIC_VIEW_H
#define PIC_VIEW_H
#include "ui_PicView.h"
#include "Ftp.h"
#include <QtNetwork>

class PicView : public QDialog
{
	Q_OBJECT
public:
	explicit PicView(QString &path);
	~PicView();
private:
	void InitDiag();
	QUrl url;
	Ui_PicView *ui;
	Ftp *ftp;
	QString Path;
	void InitPicLabel();
	private slots:
	void ClickDownloadButton();
};



#endif