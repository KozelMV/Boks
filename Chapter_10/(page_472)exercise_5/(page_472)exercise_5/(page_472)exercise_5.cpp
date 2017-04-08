// (page_472)exercise_5.cpp : Defines the entry point for the console application.
/*
Предположим, что в функции main() определены три локальных массива одинакового размера и типа (скажем, float). Первые два уже инициализи-
рованы значениями. Напишите функцию addarrays(), которая принимает вкачестве аргументов адреса грех массивов, складывает соответствующие
элементы двух массивов и помещает результат в третий массив. Четвертым аргументом этой функции может быть размерность массивов. На всем
протяжении программы используйте указатели.
x	1.Создать три локальных массива одинакового размера и типа float
x	2.Инициализировать значениями первые два массива
-->	3.Написать функцию addarrays()
	x	1.Принимаем в качестве аргумента адреса трех массивов
	x	2.Складываем элементы двух массивов и помещаем в третий
	-->	3.Четвертый аргумент функции размерность массивов
	!ИСПОЛЬЗОВАТЬ УКАЗАТЕЛИ!
*/

#include "stdafx.h"
#include <iostream>

int main()
{
	void addarrays(float* a1, float* a2, float* a3, int size); //prototype
	const int MAX = 3; //array size

	float arrOne[MAX] = { 2.2f, 3.3f, 4.4f };
	float arrTwo[MAX] = { 2.2f, 3.3f, 4.4f };
	float arrThree[MAX];

	addarrays(arrOne, arrTwo, arrThree, MAX);

	for (int i=0; i < MAX; i++) {
		std::cout << arrOne[i] << " ";
		std::cout << arrTwo[i] << " ";
		std::cout << arrThree[i] << " ";
	}

	std::cout<<std::endl;
	system("pause");
    return 0;
}

void addarrays(float* a1, float* a2, float* a3, int size) {
	
	for (int i = 0; i < size; i++) {
		*(a3 + i) = *(a1 + i) + *(a2 + i);
	}
	
}

