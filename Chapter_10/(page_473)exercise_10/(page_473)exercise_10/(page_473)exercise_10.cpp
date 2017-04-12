// (page_473)exercise_10.cpp : Defines the entry point for the console application.
/*
10.	Описанный в упражнении 9 подход нерационален, так как каждый из
10 массивов объявляется отдельно, с использованием отдельного имени,
и каждый адрес получают отдельно. Вы можете упростить программу, ис-
пользуя операцию new, которая позволит вам выделить память для масси-
вов в цикле и одновременно связать с ними указатели:
for(j = 0; j < NUMARRAYS; j++) 	// создаем NUMARRAYS массивов
*(ар + j) = new int[MAXSIZE]; 	// no MAXSIZE целых чисел в каждом
Перепишите программу упражнения 9, используя этот подход. Доступ к
отдельному элементу массивов вы сможете получить, используя то же
выражение, что и в упражнении 9, или аналогичное выражение с указате-
лями: *(*(ap + j)+k).

*/

#include "stdafx.h"
#include <iostream>
const short MAXARR = 10;
int* ap[MAXARR];

int main()
{
	for (int j = 0; j < MAXARR; j++) // создаем массивы в цикле
		*(ap + j) = new int[MAXARR];

	void fillArray(int *arr[], int q); //прототип
	void arrShow(int *arr[], int q);  //прототип

	for (int q = 0; q < MAXARR; q++) // Наполняем массив данными от 0 до 99
		fillArray(ap, q);

	for (int i = 0; i < MAXARR; i++) // Выводим данные из массивов на экран
		arrShow(ap, i);

	system("pause");
	return 0;
}

int forFillArray = 0;
void fillArray(int *arr[], int q) { // Наполняем массив данными от 0 до 99
	for (int i = 0; i < MAXARR; i++) {
		arr[q][i] = i + forFillArray;
	}
	forFillArray += 10;
}

void arrShow(int *arr[], int q) { //Выводим данные на экран
	std::cout << "address " << arr[q] << " a" << q;
	if (q < 1) { 									//для красоты :) добавляем 0 к данным с нулевого массива
		for (int i = 0; i < MAXARR; i++)			
			std::cout << " 0" << *(*(arr + q) + i) << ' ';
		std::cout << std::endl;					
	}												
	else {
		for (int i = 0; i < MAXARR; i++)
			std::cout << ' ' << arr[q][i] << ' ';		// Это похоже на двумерный массив, но в действительности 
		std::cout << std::endl;							//является группой одномерных массивов.
	}
}

