#pragma once
#include <QMessageBox>
#include <QObject>

#ifndef ERROR_PROC_H
#define ERROR_PROC_H

class ErrorProc :public QObject
{
public:
	static void PopMessageBox(QString *MessString, int Type);


};


#endif