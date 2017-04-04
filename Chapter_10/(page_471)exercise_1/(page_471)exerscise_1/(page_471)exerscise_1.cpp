// (page_471)exerscise_1.cpp : Defines the entry point for the console application.
/*
Напишите программу, которая принимает группу чисел от пользователя и помещает их в массив типа float. После того как числа будут помещены в
массив, программа должна подсчитать их среднее арифметическое и вывести результат на дисплей. Используйте указатели везде, где только возможно.
*/

#include "stdafx.h"
#include <iostream>

int main()
{
	const short MAX = 3;
	float arr[MAX];
	float res = 0.0;

	for (short i = 0; i < MAX; i++) {
		std::cin >> *(arr + i);
		res += *(arr + i);
	}
	std::cout << (res / MAX) << '\n';

	system("pause");
    return 0;
}

