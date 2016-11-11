#pragma once
#ifndef INFO_CHECK_H
#define INFO_CHECK_H

#include <QString>

#define ACCOUNT_MAX_LEN 20
#define PWD_MAX_LEN 20
#define FIX_NEW_ID_CARD_NUM_LEN 18
#define FIX_OLD_ID_CARD_NUM_LEN 15

class InfoCheck
{
public:
	static bool IsDigitStr(QString *str);
	static bool IsAccountValid(QString *AccountString);
	static bool IsPasswordValid(QString *PwdString);
	static bool IsStringNumAndAlpha(QString *InputString);
	static bool IsChineseStr(QString *str);
	static bool IsPhoneNumValid(QString *str);
	static bool IsChineseChar(QChar *word);
	static bool IsEmployeeIdCardNumValid(QString *IDCardNum);
};


#endif