#include "PicView.h"
#include <QtNetwork>
#include <QFileDialog>
#include <QFileInfo>
#include "ErrorProc.h"
#include <QDesktopServices>
#include <windows.h>
#include <shellapi.h>
#include "PubFunc.h"

PicView::PicView(QString &path)
{
	Path = path;
	ui = new Ui_PicView;
	ui->setupUi(this);

	ftp = new Ftp;
	InitDiag();
}

PicView::~PicView()
{
	delete ui;
	delete ftp;
};

void PicView::InitDiag()
{
	QObject::connect(ui->pushButtonClose, SIGNAL(clicked()), this, SLOT(reject()));
	QObject::connect(ui->pushButtonDownload, SIGNAL(clicked()), this, SLOT(ClickDownloadButton()));
	this->setModal(true);
	this->show();
	InitPicLabel();
}

void PicView::InitPicLabel()
{
	QFileInfo fileinfo = QFileInfo(Path);

	ftp->SetUrl(Path);
	QByteArray data;
	ftp->Download(data);

	QPixmap photo;
	photo.loadFromData(data, fileinfo.suffix().toLatin1());
	ui->labelPic->setPixmap(photo);
	ui->labelPic->resize(ui->widget->size());
}

void PicView::ClickDownloadButton()
{
	QString dir = QFileDialog::getExistingDirectory(this,
		QString::fromLocal8Bit("浏览"),
		"./");
	QFileInfo fileinfo(Path);
	QByteArray data;

	dir += "/";
	QString name = fileinfo.fileName();
	
	ftp->SetUrl(Path);
	ftp->Download(data);

	QPixmap img;
	img.loadFromData(data, fileinfo.suffix().toLatin1());

	QString filepath = dir +name;
	if (img.save(filepath, fileinfo.suffix().toLatin1(), 100))
	{
		QString cmd = " /select,";
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("下载成功"), 0);
		StringMod::ChangeSlash2ReSlash(filepath);
		cmd += filepath;
		ShellExecuteA(0, "open", "explorer.exe", cmd.toLatin1(), NULL, true);
	}
	else
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("下载失败"), 2);
	}
}