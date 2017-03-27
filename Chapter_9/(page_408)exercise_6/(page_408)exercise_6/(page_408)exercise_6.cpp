// (page_408)exercise_6.cpp : Defines the entry point for the console application.
/*
¬спомним программу ARROVER3 из главы 8. —охраним класс safearay таким же и, использу€ наследование, добавим к нему возможность дл€ пользо -
вател€ определ€ть верхнюю и нижнюю границы массива в конструкторе.
Ёто похоже на упражнение 9 из главы 8, за исключением того, что применено наследование дл€ создани€ нового класса(можно назвать его
safehilo) взамен модификации исходного класса.
*/

#include "stdafx.h"
#include <iostream>
#include <process.h>      // дл€ функции exit
const int LIMIT = 100;    // размер массива
///////////////////////////////////////////////////////////
class safearray
{
private:
	int arr[LIMIT];
public:

	// обратите внимание, что функци€ возвращает ссылку!
	int& operator[](int n)
	{
		if (n < 0 || n >= LIMIT)
		{
			std::cout << "\nќшибочный индекс!"; exit(1);
		}
		return arr[n];
	}
};
class safehilo : public safearray {
private:
	int str, fin;
public:
	//конструктор с двум§ аргументами
	safehilo() : str(0), fin(100){
		void check();
	}
	safehilo(short int s, short int f) : str(s), fin(f){
		void check();
	}
	void check() {
		if (str >= LIMIT)
			str = str % LIMIT;
		if (fin > LIMIT)
			fin = fin % LIMIT;
	}
	int down() { return str; };
	int top() { return fin; };
};
///////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "");
	safehilo sa1(5,10);

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

