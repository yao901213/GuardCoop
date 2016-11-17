#include "InfoCheck.h"
#include "ErrorProc.h"
#include "GlobalVar.h"
#include <QDebug>

bool StaticCheck = true;
char IDCardCoef[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char IDCardCheckSum[] = { 1, 0, 'x', 9, 8, 7 , 6, 5, 4, 3 ,2 };

bool InfoCheck::IsDigitStr(QString *str)
{
	int iCount = 0;

	for (iCount = 0; iCount < str->length(); iCount++)
	{
		if (str->at(iCount) < '0' || str->at(iCount) > '9')
		{
			return false;
		}
	}

	return true;
}

bool InfoCheck::IsChineseChar(QChar *word)
{
	ushort uni = word->unicode();
	if (uni >= 0x4E00 && uni <= 0x9FA5)
	{
		return true;
	}
	return false;
}


bool InfoCheck::IsAccountValid(QString *AccountString)
{
	if (AccountString->length() > ACCOUNT_MAX_LEN)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("�û������Ȳ��ܳ���20"), 2);
		return false;
	}

	if (!IsStringNumAndAlpha(AccountString))
	{
		QString ErrorMessage(QString::fromLocal8Bit("�û�����ֻ�ܳ�����ĸ�����֣��쳣�ķ��ţ�"));
		ErrorMessage += *AccountString;
		ErrorProc::PopMessageBox(&ErrorMessage, 2);

		return false;
	}

	return true;
}

bool InfoCheck::IsChineseStr(QString *str)
{
	int Count = str->count();

	for (int i = 0; i < Count; i++)
	{
		QChar cha = str->at(i);
		if (IsChineseChar(&cha))
		{
			//����ַ�������  
		}
		else
		{
			return false;
		}
	}

	return true;
}

bool InfoCheck::IsStringNumAndAlpha(QString *InputString)
{
	int i = 0;
	QChar CurrentChar;
	while (i < InputString->length())
	{
		CurrentChar = InputString->at(i);
		if ((CurrentChar > '9' || CurrentChar < '0')
			&& (CurrentChar > 'z' || CurrentChar < 'a')
			&& (CurrentChar > 'Z' || CurrentChar < 'A'))
		{
			return false;
		}
		i++;
	}

	return true;
}

bool InfoCheck::IsPasswordValid(QString *PwdString)
{
	if (PwdString->length() > ACCOUNT_MAX_LEN)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("���볤�Ȳ��ܳ���20"), 2);
		return false;
	}

	if (!IsStringNumAndAlpha(PwdString))
	{
		QString ErrorMessage(QString::fromLocal8Bit("������ֻ�ܳ�����ĸ�����֣��쳣�ķ��ţ�"));
		ErrorMessage += *PwdString;
		ErrorProc::PopMessageBox(&ErrorMessage, 2);

		return false;
	}
	return true;
}

bool InfoCheck::IsPhoneNumValid(QString *str)
{
	int i = 0;

	while (i < str->length())
	{
		if (str->at(i) >= '0' && str->at(i) <= '9' || str->at(i) == '-')
		{
			i++;
			continue;
		}
		else
		{
			return false;
		}
	}

	return true;
}



//У�飺1.����Ϊ�գ�2.18λ����15λ��3.ֻ�������ֺ�"x"
bool InfoCheck::IsEmployeeIdCardNumValid(QString *IDCardNum)
{
	if (IDCardNum->isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("���֤�Ų���Ϊ��"), 2);

		return false;
	}
	
	switch (IDCardNum->length())
	{
	case FIX_OLD_ID_CARD_NUM_LEN:
		return (IsOldIDCardNumValid(IDCardNum));
	case FIX_NEW_ID_CARD_NUM_LEN:
		return (IsNewIDCardNumValid(IDCardNum));
	default:
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("���֤�ų��Ȳ���ȷ"), 2);
		return false;
	}
}

bool InfoCheck::IsOldIDCardNumValid(QString *OldIdCardNum)
{
	int i = 0;

	while (i < FIX_OLD_ID_CARD_NUM_LEN)
	{
		if (OldIdCardNum->at(i) > '9' || OldIdCardNum->at(i) < '0')
		{
			ErrorProc::PopMessageBox(&QString::fromLocal8Bit("���֤����ֻ�������ֻ���\"x\""), 2);
			return false;
		}

		i++;
	}

	return IsOldIDCardBirthCodeValid(OldIdCardNum);
}

bool InfoCheck::IsNewIDCardNumValid(QString *NewIdCardNum)
{
	int i = 0;

	while (i < FIX_NEW_ID_CARD_NUM_LEN)
	{
		if (NewIdCardNum->at(i) <= '9' && NewIdCardNum->at(i) >= '0')
		{
			i++;
			continue;
		}

		//18λ���֤���һλ����Ϊx
		if ((i == FIX_NEW_ID_CARD_NUM_LEN - 1) && (NewIdCardNum->at(i) == 'x'))
		{
			break;
		}

		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("���֤����ֻ�������ֻ���\"x\""), 2);
		return false;
	}
	 
	if (!IsNewIDCardBirthCodeValid(NewIdCardNum))
	{
		return false;
	}

	return IsNewIDCardCheckSumValid(NewIdCardNum);
}


bool InfoCheck::IsNewIDCardBirthCodeValid(QString *IdCardNum)
{
	QString Year = IdCardNum->mid(6,4);
	QString Month;
	QString Date;

	if (Year.toInt() > LAST_BIRTH_YEAR ||
		Year.toInt() < EARLIEST_BIRTH_YEAR)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("���֤��7~10λ�������:%1").arg(Year.toInt()), 2);
		return false;
	}

	Month = IdCardNum->mid(10, 2);
	if (Month.toInt() > DECEMBER ||
		Month.toInt() < JANUARY)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("���֤��10~11λ�������:%1").arg(Month.toInt()), 2);
		return false;
	}

	Date = IdCardNum->mid(12, 2);
	if (Date.toInt() > 31 ||
		Date.toInt() < 1)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("���֤��12~13λ�������:%1").arg(Date.toInt()), 2);
		return false;
	}

	return true;
}

bool InfoCheck::IsOldIDCardBirthCodeValid(QString *IdCardNum)
{
	QString Month;
	QString Date;

	Month = IdCardNum->mid(8, 2);
	if (Month.toInt() > DECEMBER ||
		Month.toInt() < JANUARY)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("���֤��8~9λ�������:%1").arg(Month.toInt()), 2);
		return false;
	}

	Date = IdCardNum->mid(10, 2);
	if (Date.toInt() > 31 ||
		Date.toInt() < 1)
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("���֤��10~11λ�������:%1").arg(Date.toInt()), 2);
		return false;
	}

	return true;
}


bool InfoCheck::IsNewIDCardCheckSumValid(QString *IdCardNum)
{
	int i = 0;
	int sum = 0;
	int residue = 0;
	
	for (i = 0; i < FIX_NEW_ID_CARD_NUM_LEN - 1; i++)
	{
		sum += IdCardNum->mid(i, 1).toInt() * IDCardCoef[i];
	}

	residue = sum % 11;
	if (IdCardNum->right(1) == QString("x"))
	{
		if ('x' == IDCardCheckSum[residue])
		{
			return true;
		}
		else
		{
			ErrorProc::PopMessageBox(&QString::fromLocal8Bit("���֤�����һλ�������:%1").arg(IdCardNum->right(1).toInt()), 2);
			return false;
		}
	}

	if (IdCardNum->right(1).toInt() == (int)IDCardCheckSum[residue])
	{
		return true;
	}
	else
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("���֤�����һλ�������:%1").arg(IdCardNum->right(1).toInt()), 2);
		return false;
	}
}

void InfoCheck::GetBirthAndGenderFromID(QString &ID, QDateEdit &dateedit, QString &gender)
{
	int year, month, date, iGender;
	int offset = 6;

	if (ID.length() == FIX_NEW_ID_CARD_NUM_LEN)
	{
		year = ID.mid(offset, 4).toInt();
		offset += 4;
	}
	else
	{
		year = ID.mid(offset, 2).toInt() + 1900;
		offset += 2;
	}
	month = ID.mid(offset, 2).toInt();
	offset += 2;
	date = ID.mid(offset, 2).toInt();
	offset += 4;
	iGender = ID.mid(offset, 1).toInt() % 2;

	dateedit.setDate(QDate(year, month, date));
	if (iGender)
	{
		gender = QString::fromLocal8Bit("��");
	}
	else
	{
		gender = QString::fromLocal8Bit("Ů");
	}
}