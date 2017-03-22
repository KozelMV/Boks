// new(page_357)exercise_8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>  //_getch
#include <cstdlib>  //exit()
#include <cstdio>  //sprintf()
#include <string>  //length()
#include <iomanip> //setw() setwill('_')

class bMoney
{
private:
	enum { SZ = 33 };
	char userEnter[SZ]; //содержит: 1. Ввод пользователя. 2. Результат сложения двух строк.
	char parsUserEnter[SZ];
	std::string result;
	long double namberParsUserEnter;
public:
	// 1. ---> Ввод данных
	void getmoney()
	{
		char temp;
		int i = 0;
		do
		{
			temp = _getch();
			if (temp != 13)
			{
				userEnter[i] = temp;
				std::cout << userEnter[i];
				i++;
			}
			if (i >= SZ) //если превышен размер массива завершить программу
			{
				std::cout << "\nERROR ARR_SZ 1" << std::endl;
				system("pause");
				exit(1);
			}

		} while (temp != 13);
		userEnter[i] = '\0'; //последний символ, конец страки
		std::cout << std::endl;

		// 2. ---> Выборка чисел и точки из введенной страки
		for (int i = 0, z = 0; i < SZ; i++)
		{
			switch (userEnter[i])
			{
			case '0': {parsUserEnter[z] = userEnter[i]; z++; }; break;
			case '1': {parsUserEnter[z] = userEnter[i]; z++; }; break;
			case '2': {parsUserEnter[z] = userEnter[i]; z++; }; break;
			case '3': {parsUserEnter[z] = userEnter[i]; z++; }; break;
			case '4': {parsUserEnter[z] = userEnter[i]; z++; }; break;
			case '5': {parsUserEnter[z] = userEnter[i]; z++; }; break;
			case '6': {parsUserEnter[z] = userEnter[i]; z++; }; break;
			case '7': {parsUserEnter[z] = userEnter[i]; z++; }; break;
			case '8': {parsUserEnter[z] = userEnter[i]; z++; }; break;
			case '9': {parsUserEnter[z] = userEnter[i]; z++; }; break;
			case '.': {parsUserEnter[z] = userEnter[i]; z++; }; break;
			default:
				break;
			}
			if (userEnter[i] == '\0')
				parsUserEnter[z] = '\0';
		}
		
		//std::cout << "!test(char[])parsUserEnter ---> " << parsUserEnter << std::endl; //!test
		// 3. ---> Перевод страки в long double
			namberParsUserEnter = strtold(parsUserEnter, '\0');
			//std::cout << "!test(long double)namberParsUserEnter ---> " << std::fixed << namberParsUserEnter << std::endl; //!test
		
	}

	// 9. --> Вывод результатов на экран
	void showResult()
	{
		// 5. ---> Перевод результата суммы в страку
			sprintf_s(userEnter, "%f", namberParsUserEnter);
			//std::cout << "!test(char[])userEnter ---> " << userEnter << std::endl;
			
			// 6. ---> Форматирование переведенной строки в формат $9'999'999'999'999'990.000000 //29
				char temp[SZ];
				temp[0] = '$';
				temp[1] = '0';
				temp[2] = '\'';
				for (int i = 3, q = 6; i < SZ; i++)
				{
					if (i == 22)
					{
						temp[i] = '.';
						i++;
						for (; i < SZ; i++)
						{
							temp[i] = '0';
						}
						break;
					}
					if (i >= 6 && i % q == 0)
					{

						temp[i] = '\'';
						q += 4;
					}
					else
						temp[i] = '0';
				}
				temp[SZ - 4] = '\0';

				//std::cout << "!test(temp) ---> " << temp << std::endl; //!test

				//Количество символов после точки
				int strLen = 0;

				for (int i = 0; i < SZ; i++) //получаем длинну массива
				{
					if (userEnter[i] != '\0')
						strLen++;
					else
					{
						strLen -= 7;
						//std::cout << "!test(length) ---> " <<  strLen << std::endl; //!test
						break;
					}
				}
				//количество 0 перед введеной сумой	
				int itemp = ((SZ - strLen) - 7) - 4;
				if (strLen > 3)
					itemp -= strLen / 3;
				//std::cout << "!test(itemp) ---> " << itemp << std::endl; //!test
				//Капируем массив данных в шаблон

				strLen += strLen / 3;//длинна + символы '\''

				for (int i = 0, q = 0; i < strLen + 7; i++)
				{
					if (temp[(((SZ - 4) - 7) - strLen) + i] == '\'')
					{
					}
					else
					{
						temp[(((SZ - 4) - 7) - strLen) + i] = userEnter[q];
						q++;
					}
				}
				//std::cout << "!test(temp) ---> " << temp << std::endl; //!test

				// 7. ---> Убираем лишние символы с переди $9'990.000000
				result = temp;
				if (temp[itemp] == '\'')
					result.erase(1, itemp);
				else
					result.erase(1, itemp - 1);
				//std::cout << "!test(result) ---> " << result << std::endl; //!test
				// 8. ---> Убираем лишние символы в конце массива $9'999'999'999'999'990.00 
				for (int i = 0; i < 4; i++)
					result.pop_back();
				//std::cout << "!test(result) ---> " << result << std::endl; //!test
			
		
		std::cout << result << std::endl;
	}

/*========================== Прототипы перегруженных операций =====================*/

	bMoney operator+(bMoney bm1);  //1
	bMoney operator-(bMoney bm1);  //2
	bMoney operator*(long double); //3
	bMoney operator/(bMoney bm1);  //4
	bMoney operator/(long double); //5
};



bMoney bMoney::operator+(bMoney bm1)
{
	bMoney temp;
	temp.namberParsUserEnter = namberParsUserEnter + bm1.namberParsUserEnter;
	return temp;
}

bMoney bMoney::operator-(bMoney bm1)
{
	bMoney temp;
	temp.namberParsUserEnter = namberParsUserEnter - bm1.namberParsUserEnter;
	return temp;
}

bMoney bMoney::operator*(long double t)
{
	bMoney temp;
	temp.namberParsUserEnter = namberParsUserEnter * t;
	return temp;
}

bMoney bMoney::operator/(bMoney bm1)
{
	bMoney temp;
	temp.namberParsUserEnter = namberParsUserEnter / bm1.namberParsUserEnter;
	return temp;
}

bMoney bMoney::operator/(long double t)
{
	bMoney temp;
	temp.namberParsUserEnter = namberParsUserEnter / t;
	return temp;
}
/*=================================================================================*/

int main()
{
	//setlocale(LC_ALL, ""); недопустимо! '.' в данной лакалии считает за конец строки

	long double userEnter;
	bMoney m1, m2, res;
	char esc;
	do
	{
	std::cout << "Enter the cost of the products 1: "; m1.getmoney();
	std::cout << "Enter the cost of the products 2: "; m2.getmoney();/*std::cin >> userEnter*/;
	std::cout << "Enter the number of products: "; std::cin >> userEnter;

	//Выводим результаты
	std::cout << std::setw(70) << std::setfill('=') << '\n';
/*1*/  res = m1 + m2; std::cout << "Sum: " << std::setw(49) << std::setfill('_'); res.showResult();
/*2*/  res = m1 - m2; std::cout << "Difference: " << std::setw(42) << std::setfill('_'); res.showResult();
/*3.1*/res = m1 * userEnter; std::cout << "Total cost of products 1: " << std::setw(28) << std::setfill('_'); res.showResult();
/*3.2*/res = m2 * userEnter; std::cout << "Total cost of products 2: " << std::setw(28) << std::setfill('_'); res.showResult();
/*4*/  res = m1 / m2; std::cout << "Total price divided by the price of the product: " << std::setw(5) << std::setfill('_'); res.showResult();
/*5*/  res = m1 / userEnter; std::cout << "Total price divided by the number of parts: " << std::setw(10) << std::setfill('_'); res.showResult();
/*Неверные операции*/
/*1*/ res = m1 * m2; std::cout << "FAILL bMoney * bMoney: " << std::setw(10) << std::setfill('_'); res.showResult(); //не имеет смысла
/*2*/ res = m1 + userEnter;  std::cout << "FAILL bMoney + Long double: " << std::setw(10) << std::setfill('_'); res.showResult();//не имеет смысла
	std::cout << std::setw(70) << std::setfill('=') << '\n';
	
	

	std::cout << "You exit program? Yes / No : " ; 
	std::cin >> esc;

	
	} while (esc != 'y');
	std::cout << "Good by :)" << std::endl;
	system("pause");
    return 0;
}

