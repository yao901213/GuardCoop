#pragma once
#ifndef INFO_CHECK_H
#define INFO_CHECK_H

#include <QString>
#include <QDateEdit>
#include <QDir>

#define ACCOUNT_MAX_LEN 20
#define PWD_MAX_LEN 20
#define FIX_NEW_ID_CARD_NUM_LEN 18
#define FIX_OLD_ID_CARD_NUM_LEN 15
#define EARLIEST_BIRTH_YEAR 1900
#define LAST_BIRTH_YEAR 2100
#define JANUARY 1
#define DECEMBER 12

extern char IDCardCoef[];
extern char IDCardCheckSum[];

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
	static bool IsOldIDCardNumValid(QString *OldIdCardNum);
	static bool IsNewIDCardNumValid(QString *NewIdCardNum);
	static bool IsNewIDCardBirthCodeValid(QString *IdCardNum);
	static bool IsOldIDCardBirthCodeValid(QString *IdCardNum);
	static bool IsNewIDCardCheckSumValid(QString *IdCardNum);
	static void GetBirthAndGenderFromID(QString &ID, QDateEdit &dateedit, QString &gender);
	static bool IsPicPathValid(QString &path);
};


#endif