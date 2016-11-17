#include "GuardPosition.h"
#include <QSqlRecord>

GuardPosWidget::GuardPosWidget(QWidget* parent) :
	QWidget(parent)
{
	ui = new Ui_MapWidget;
	ui->setupUi(this);
	model = new QSqlTableModel;

	LoadTime = 0;
	Index = 0;
	Longitude = 0;
	Latitude = 0;
	InitWidget();
	UpdateSymbol = false;
}

GuardPosWidget::~GuardPosWidget()
{
	delete ui;
	delete model;
}

void GuardPosWidget::InitWidget()
{
	QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
	QString urlStr = "file:///";
    urlStr += QCoreApplication::applicationDirPath();
	urlStr += "/map.html";
	Url = QUrl(urlStr);
	ui->webEngineView->load(Url);
	ui->webEngineView->show();
	QObject::connect(ui->webEngineView->page(), SIGNAL(loadFinished(bool)),
		this, SLOT(ShowAllPoints(bool)));
	QObject::connect(ui->pushButtonAdd, SIGNAL(clicked()),
		this, SLOT(ClickAddButton()));
	QObject::connect(ui->pushButtonMod, SIGNAL(clicked()), this, SLOT(ClickModButton()));
	QObject::connect(ui->pushButtonDel, SIGNAL(clicked()), this, SLOT(ClickDelButton()));

	model->setTable("HumanResource.GuardPosition");
	model->setFilter("");

}

//function setLabel(logitude, latitude, label, title)

void GuardPosWidget::AddPoint()
{
	QString cmd = QString("setLabel(%1, %2, %3, \"%4\")").
		arg(Longitude, 0,'g').arg(Latitude, 0, 'g').arg(Index).arg(title);

	ui->webEngineView->page()->runJavaScript(cmd, [](const QVariant &v) {qDebug() << v.toString(); });
}

void GuardPosWidget::ShowAllPoints(bool Finished)
{
	int i, RowCount;
	QSqlRecord record;
	double x, y;

	if (!Finished)
	{
		return;
	}
	if (!UpdateSymbol && ++LoadTime != 2)
	{
		return;
	}

	model->setFilter("");
	model->select();
	RowCount = model->rowCount();

	for (i = 0; i < RowCount; i++)
	{
		record = model->record(i);
		x = record.value("Longitude").toDouble();
		y = record.value("Latitude").toDouble();
		SetAxis(x, y);
		title = record.value("PositionName").toString();
		Index++;
		AddPoint();
	}

	ResetPointIndex();
}

void GuardPosWidget::ClickAddButton()
{
	edit = new GuardPositionEditDiag();
	edit->InitDiagAddFunc();
	QObject::connect(edit, SIGNAL(accepted()), this, SLOT(ReloadUrl()));
}

void GuardPosWidget::ReloadUrl()
{
	ui->webEngineView->load(Url);
	ui->webEngineView->show();
	UpdateSymbol = true;
}

void GuardPosWidget::ResetPointIndex()
{
	LoadTime = 0;
	UpdateSymbol = false;
	Index = 0;
}


void GuardPosWidget::ClickModButton()
{
	edit = new GuardPositionEditDiag();
	edit->InitDiagModFunc();
	QObject::connect(edit, SIGNAL(accepted()), this, SLOT(ReloadUrl()));

}
void GuardPosWidget::ClickDelButton()
{
	edit = new GuardPositionEditDiag();
	edit->InitDiagDelFunc();
	QObject::connect(edit, SIGNAL(accepted()), this, SLOT(ReloadUrl()));

}


