// (page_472)exercise_3.cpp : Defines the entry point for the console application.
/*
»спользуйте массив указателей на строки, представл¤ющие собой названи¤ дней недели, из примера PTROSTR этой главы. 
Ќапишите функции дл¤ сортировки этих строк в алфавитном пор¤дке, использу¤ в качестве осно-
вы функции bsort() и order() из программы PTRSORT этой главы. 
—ортировать необходимо указатели на строки, а не сами строки.
*/

#include "stdafx.h"
#include <iostream>
#include <string> //strcmp()

int main()
{
	void bsort(char** ptr, int);    // прототип функции
	const int N = 7;         // размер массива
	char* arr[N] = { "Monday", "Tuesday" ,"Wednesday", "Thursday", "Friday", "Saturday", "Sunday" }; // массив дней дл¤ сортировки
	
	for (int j = 0; j < N; j++)
		std::cout << *(arr + j) << " ";
	std::cout << std::endl;

	bsort(arr, N);

	for (int j = 0; j < N; j++)
		std::cout << *(arr + j) << " ";
	std::cout << std::endl;

	system("pause");
	return 0;
}
//////////////////////////////////////////////////////////
void bsort(char** ptr, int n)
{
	void order(char**, char**);          // прототип функции
	int j, k;                        // индексы в нашем массиве

	for (j = 0; j < n - 1; j++)       // внешний цикл
		for (k = j + 1; k < n; k++) {    // внутренний цикл
			order(ptr+j, ptr+k);     // сортируем элементы лексикографически
		}
}
///////////////////////////////////////////////////////////
void order(char** numb1, char** numb2) 
{


	if (std::strcmp(*numb1, *numb2) > 0) 
	{
		char *temp = *numb1;
		*numb1 = *numb2;
		*numb2 = temp;
	}
}



