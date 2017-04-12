// (page_473)exercise_9.cpp : Defines the entry point for the console application.
/*
Допустим, что нам нужно сохранить 100 целых чисел так, чтобы иметь к
ним легкий доступ. Допустим, что при этом у нас есть проблема: память
нашего компьютера так фрагментирована, что может хранить массив, наи-
большее количество элементов в котором равно десяти (такие проблемы
действительно появляются, хотя обычно это происходит с объектами, зани-
мающими большое количество памяти). Вы можете решить эту проблему,
определив 10 разных массивов по 10 элементов в каждом и массив из
10 указателей на эти массивы. Массивы будут иметь имена a0, a1, a2 и т. д.
Адрес каждого массива будет сохранен в массиве указателей типа int*, ко-
торый называется ар. Вы сможете получить доступ к отдельному целому
используя выражение ap[j][к], где j является номером элемента массива
указателей, а к — номером элемента в массиве, на который этот указатель
указывает. Это похоже на двумерный массив, но в действительности яв-
ляется группой одномерных массивов.
Заполните группу массивов тестовыми данными (скажем, номерами 0, 10,
20 и т. д.), а затем выведите их, чтобы убедиться, что все работает пра-
вильно.
*/
/*
X	1. Сохранить 100 целых чисел
	X	1. Определить 10 массивов с именами a0, a1, a2 и т. д. по 10 элементов
	X	2. Заполните группу массивов тестовыми данными
	X	3. Определить массив int* ар из 10 указателей на массивы
X	2. Получить доступ используя выражение ap[j][к]
-->	3. Убедиться, что все работает правильно
*/
#include "stdafx.h"
#include <iostream>
const short MAXARR = 10;

int a0[MAXARR];
int a1[MAXARR];
int a2[MAXARR];
int a3[MAXARR];
int a4[MAXARR];
int a5[MAXARR];
int a6[MAXARR];
int a7[MAXARR];
int a8[MAXARR];
int a9[MAXARR];

int* ap[MAXARR] = { a0,a1,a3,a3,a4,a5,a6,a7,a8,a9 };

int main()
{
	void fillArray(int *arr[],int q); //прототип
	void arrShow(int *arr[], int q);  //прототип
	
	for (int q = 0; q < MAXARR; q++) // Наполняем массив данными от 0 до 99
		fillArray(ap,q);

	for (int i = 0; i < MAXARR; i++) // Выводим данные из массивов на экран
		arrShow(ap, i);

	system("pause");									   
    return 0;
}

int forFillArray = 0;
void fillArray(int *arr[],int q) { // Наполняем массив данными от 0 до 99
		for (int i = 0; i < MAXARR; i++) {
			arr[q][i] = i + forFillArray;
		}
		forFillArray += 10;
}

void arrShow(int *arr[], int q) { //Выводим данные на экран
	std::cout << "address " << arr[q] << " a" << q;
	if (q < 1) { 									//для красоты :) добавляем 0 к данным с нулевого массива
		for (int i = 0; i < MAXARR; i++)			//для красоты :) добавляем 0 к данным с нулевого массива
			std::cout << " 0" << arr[q][i] << ' ';	//для красоты :) добавляем 0 к данным с нулевого массива
		std::cout << std::endl;						//для красоты :) добавляем 0 к данным с нулевого массива
	}												//для красоты :) добавляем 0 к данным с нулевого массива
	else {
		for (int i = 0; i < MAXARR; i++)
			std::cout << ' ' << arr[q][i] << ' ';		// Это похоже на двумерный массив, но в действительности 
		std::cout << std::endl;							//является группой одномерных массивов.
	}
}