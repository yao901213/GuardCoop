#pragma once
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

#include "ErrorProc.h"

#ifndef CONNECT_TO_DB
#define CONNECT_TO_DB

class DB
{
public:
	QSqlDatabase db;
	bool Connect2DB();
};


#endif
