// (page_473)exercise_11.cpp : Defines the entry point for the console application.
/*
Создайте класс, который позволит вам использовать 10 отдельных масси-
вов из упражнения 10 как один одномерный массив, 
допуская применение операций массива. 
То есть мы можем получить доступ к элементам
массива, записав в функции main() выражение типа a[j], 

а методы класса
могут получить доступ к полям класса, используя двухшаговый подход.
Перегрузим операцию [] (см. главу 9 «Наследование»), чтобы получить
нужный нам результат. Заполним массив данными и выведем их. Хотя
для интерфейса класса использованы операции индексации массива, вам
следует использовать указатели внутри методов класса.
*/
/*
X	1. Create class
X	2. coppy exercise_10 in class
X	3. Overload []
X	4. Fill the array
-->	5. test
*/

#include "stdafx.h"
#include <iostream>
#include <math.h> //abs()

//-----------------------------------------------------------
class MyArr {

private:
	enum MAX { ARR = 10 };
	int* ap[ARR];
public:
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	MyArr() { // constructor without parameters
		for (int j = 0; j < ARR; j++) // создаем массивы в цикле
			*(ap + j) = new int[ARR];
	}
	~MyArr() { //destructor
		for (int j = 0; j < ARR; j++)
			delete *(ap + j);
	}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	int forFillArray = 0;
	void fillArr() { // Наполняем массив данными от 0 до 99
		
		for (int q = 0; q < ARR; q++) { 
			for (int i = 0; i <  ARR; i++) {
				ap[q][i] = i + forFillArray;
			}
			forFillArray += 10;
		}
	}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	void arrShow(int q) { //Выводим данные на экран
		std::cout << "address " << ap[q] << " a" << q;
		if (q < 1) { 									//для красоты :) добавляем 0 к данным с нулевого массива
			for (int i = 0; i < ARR; i++)
				std::cout << " 0" << *(*(ap + q) + i) << ' ';
			std::cout << std::endl;
		}
		else {
			for (int i = 0; i < ARR; i++)
				std::cout << ' ' << ap[q][i] << ' ';		// Это похоже на двумерный массив, но в действительности 
			std::cout << std::endl;							//является группой одномерных массивов.
		}
	}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	int* access(int x) { //доступ к группе одномерных массивов как к одномерному
		if (x == 0 || x == (ARR*ARR))
			return &ap[0][0];

		if (x < 0) {
				std::cout << "Program crash. Array overloaded. Min value = " << 0 << std::endl;
				system("pause");
				exit(1);
		}
		if (x > 0) {
			if (x < (ARR*ARR))
				return &ap[(x / ARR)][x % ARR];
			if (x >(ARR*ARR)) { 
				std::cout << "Program crash. Array overloaded. Max value = " << ARR*ARR << std::endl;
				system("pause");
				exit(1);
			}
		}
		std::cout << "ERROR ZERO.(0)" << std::endl;
		system("pause");
		exit(1);
	}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	int& operator[] (int q) { //Возвращаем адрес ячейки
		return *access(q);
	}
}; //end class MyArr
//-----------------------------------------------------------
int main()
{
	MyArr arr1; //выделяем память
	
	arr1.fillArr(); //Наполняем массив от 0 до 99

	for (int i = 0; i < 10; i++) //выводим массив на экран
		arr1.arrShow(i);
	
	std::cout << arr1[14] << std::endl;
	std::cout << arr1[100] << std::endl;
	std::cout << arr1[88] << std::endl;

	arr1[14] = -14;

	for (int i = 0; i < 10; i++) //выводим массив на экран
		arr1.arrShow(i);

	if (arr1[2] == arr1[14])
		std::cout << true << std::endl;

	
	system("pause");
    return 0;
}

