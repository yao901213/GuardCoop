#include "pubfunc.h"

void UiEmbellish::GreenText(QLabel *label)
{
	label->setStyleSheet(QStringLiteral("color: rgb(144, 238, 144);"));
}

void UiEmbellish::RedText(QLabel *label)
{
	label->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
}