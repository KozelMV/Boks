/* 
x	1. Напишите программу, объединяющую в себе классы bMoney из упражнения 8 и sterling из упражнения 11. 
x	2. Напишите операцию преобразования для преобразования между классами bMoney и sterling, предполагая, что
	один фунт (£1.0.0) равен пятидесяти долларам ($50.00). Это приблизительный курс обмена для XIX века, когда Британская империя еще ис-
	пользовала меру фунты-шиллинги-пенсы. 
x	3. Напишите программу main(),которая позволит пользователю вводить суммы в каждой из валют и преобразовывать их в другую валюту с выводом результата. 
->	4. Минимизируйте количество изменений в существующих классах bMoney и sterling.
*/

#include "stdafx.h"
#include "newMoney.h"
#include "oldMoney.h"
#include <iostream>
#include <conio.h>


void main()
{
	
	bMoney bm;
	sterling st;
	long double temp;

	std::cout << "\t\t________________________________________________________________________________________" << std::endl;
	std::cout << "\t\t| Enter the newMoney >> oldMoney (q) | Enter the oldMoney << newMoney (w) | Exit (Esc) |" << std::endl;
	std::cout << "\t\t****************************************************************************************" << std::endl;
	char esc;
	do
	{
		esc = _getch();
		switch (esc)
		{
		case 'q': {
			std::cout << "\nEnter the newMoney: $";
			bm.getmoney(); bm.showResult();
			std::cout << " = ";
			temp = bm.res();
			sterling st(temp);
			st.putSterling();
		} break;
		case 'w': {
			//std::cout << "Enter the oldMoney: J"; 
			st.getSterling();
			temp = double(st);
			if (temp < 0.12)
				bMoney bbm(temp*100);
			else
				bMoney bbm(temp * 12);
		}break;
		//default:
		//	break;
		}
		
	} while (esc != '\x01b');
	system("pause");
	return;
}