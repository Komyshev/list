#include "io.h"

int scanInt(int &a)
{
	cout << "Введите значение: ";
	while (scanIntVal(a))
	{
		cout << endl << "Ошибка!! Повторите ввод: ";
	}

	return a;
}

bool scanIntVal(int &a)
{
	if (!(cin >> a))
	{
		cin.clear();
		
		while (cin.get() != '\n')
		{

		}
		
		return 1;
	}

	return 0;
}

bool scanYesNo()
{
	char c;
	while (1)
	{
		c = _getch();
		if ( (c == 'Y') || (c == 'y') || (c == -83) || (c == -115) )
		{
			cout << 'Y' << endl << endl;
			return 1;
		}
		else if ( (c == 'N') || (c == 'n') || (c == -30) || (c == -110) )
		{
			cout << 'N' << endl << endl;
			return 0;
		}
	}	
}
