// (page_358)exercise_9.cpp : Defines the entry point for the console application.
// демонстраци€ создани€ безопасного массива, провер€ющего
// свои индексы при использовании
// используетс€ перегрузка операции []

#include "stdafx.h"
#include <iostream>
#include <process.h>      // дл€ функции exit
const int LIMIT = 100;    // размер массива
						  ///////////////////////////////////////////////////////////
class safearray
{
private:
	int arr[LIMIT];
	int str, fin;
public:
	//конструктор с двум€ аргументами
	safearray() : str(100), fin(175) 
	{
		if (str >= LIMIT)
			str = str % LIMIT;
		if (fin > LIMIT)
			fin = fin % LIMIT;
	}
	// обратите внимание, что функци€ возвращает ссылку!
	int& operator[](int n)
	{
		if (n < 0 || n > LIMIT)
		{
			std::cout << "\nќшибочный индекс!\n"; 
			system("pause");  
			exit(1);
		}
		return arr[n];
	}
	int down() { return str; };
	int top() { return fin; };
};
///////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "");
	

	safearray sa1;
	// задаем значени€ элементов
	for (int j = sa1.down(); j <= sa1.top(); j++)
		sa1[j] = j * 10;    // используем функцию слева от знака =

							// показываем элементы
	for (int j = sa1.down(); j <= sa1.top(); j++)
	{
		int temp = sa1[j];  // используем функцию справа от знака =
		std::cout << "Ёлемент " << j << " равен " << temp << std::endl;
	}
	system("pause");

	return 0;
}
