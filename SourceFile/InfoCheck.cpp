#include "InfoCheck.h"
#include "ErrorProc.h"

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
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("用户名长度不能超过20"), 2);
		return false;
	}

	if (!IsStringNumAndAlpha(AccountString))
	{
		QString ErrorMessage(QString::fromLocal8Bit("用户名中只能出现字母和数字，异常的符号："));
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
			//这个字符是中文  
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
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("密码长度不能超过20"), 2);
		return false;
	}

	if (!IsStringNumAndAlpha(PwdString))
	{
		QString ErrorMessage(QString::fromLocal8Bit("密码中只能出现字母和数字，异常的符号："));
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



//校验：1.不能为空；2.18位或者15位；3.只能有数字和"x"
bool InfoCheck::IsEmployeeIdCardNumValid(QString *IDCardNum)
{
	QMessageBox MessageBox;
	int i = 0;

	if (IDCardNum->isEmpty())
	{
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("身份证号不能为空"), 2);

		return false;
	}
	switch (IDCardNum->length())
	{
	case FIX_OLD_ID_CARD_NUM_LEN:
		while (i < FIX_OLD_ID_CARD_NUM_LEN)
		{
			if (IDCardNum->at(i) > '9' || IDCardNum->at(i) < '0')
			{
				ErrorProc::PopMessageBox(&QString::fromLocal8Bit("身份证号中只能是数字或者\"x\""), 2);
				return false;
			}

			i++;
		}
		break;
	case FIX_NEW_ID_CARD_NUM_LEN:
		while (i < FIX_NEW_ID_CARD_NUM_LEN)
		{
			if (IDCardNum->at(i) <= '9' && IDCardNum->at(i) >= '0')
			{
				i++;
				continue;
			}

			//18位身份证最后一位可能为x
			if ((i == FIX_NEW_ID_CARD_NUM_LEN - 1) && (IDCardNum->at(i) == 'x'))
			{
				break;
			}

			ErrorProc::PopMessageBox(&QString::fromLocal8Bit("身份证号中只能是数字或者\"x\""), 2);
			return false;
		}
		break;

	default:
		ErrorProc::PopMessageBox(&QString::fromLocal8Bit("身份证号长度不正确"), 2);

		return false;
	}

	return true;

}