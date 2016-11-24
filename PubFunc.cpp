#include "pubfunc.h"

void UiEmbellish::GreenText(QLineEdit &lineedit)
{
	lineedit.setStyleSheet(QStringLiteral("color: rgb(144, 238, 144);"));
}

void UiEmbellish::RedText(QLineEdit &lineedit)
{
	lineedit.setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
}