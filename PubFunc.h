#pragma once
#ifndef PUB_FUNC_H
#define PUB_FUNC_H

#include <QLabel>

class UiEmbellish
{
public:
	static void GreenText(QLabel *label);
	static void RedText(QLabel *label);
};

class StringMod
{
public:
	static void ChangeSlash2ReSlash(QString &str);
};

#endif