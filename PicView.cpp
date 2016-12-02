#include "PicView.h"
#include <QtNetwork>
#include <QFileDialog>
#include <QFileInfo>

PicView::PicView(QString &path)
{
	Path = path;
	ui = new Ui_PicView;
	ui->setupUi(this);
	InitDiag();
}

PicView::~PicView()
{
	delete ui;
	delete reply;
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

	url.setUrl(Path);
	url.setUserName("Administrator");
	url.setPassword("1");
	QEventLoop loop;
	QNetworkAccessManager manager;

	reply = manager.get(QNetworkRequest(url));

	QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
	loop.exec();

	QByteArray data = reply->readAll();
	QPixmap photo;
	photo.loadFromData(data, fileinfo.suffix().toLatin1());
	ui->labelPic->setPixmap(photo);
	ui->labelPic->resize(ui->widget->size());
}

void PicView::ClickDownloadButton()
{
	QString filename = QFileDialog::getOpenFileName(this,
		QString::fromLocal8Bit("‰Ø¿¿"),
		"./", tr("Images(*.%1)").arg(QFileInfo(Path).suffix()));
	
	QFile file(filename);
	file.open(QIODevice::WriteOnly);
	QTextStream out(&file);

	out << reply->readAll();
	file.close();
}