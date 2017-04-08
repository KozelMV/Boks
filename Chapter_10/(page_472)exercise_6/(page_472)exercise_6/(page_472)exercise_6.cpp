// (page_472)exercise_6.cpp : Defines the entry point for the console application.
/*
6. Создайте свою версию библиотечной функции strcmp(s1, s2), которая сравнивает две строки и возвращает -1, если s1 идет первой по алфавиту, 0,
если в s1 и s2 одинаковые значения, и 1, если s2 идет первой по алфавиту. Назовите вашу функцию compstr(). Она должна принимать в качестве ар-
гументов два указателя на строки char*, сравнивать эти строки посимвольно и возвращать число int. Напишите функцию main() для проверки
работы вашей функции с разными строками. Используйте указатели во всех возможных ситуациях.
-------------------------------------------------------------------------------------------------------------------------------------------------
-->	1.Написать функцию compstr(s1, s2)																											
	X	1.Принимать в качестве аргументов два указателя на строки char*																			
	X	2.Сравнивать эти строки посимвольно																										
	X	3.Возвращать число int																													
		X	1.Если s1 идет первой по алфавиту return: -1;																						
		X	2.Если в s1 и s2 одинаковые значения return: 0;																						
		X	3.Если s2 идет первой по алфавиту return: 1;																						
-->	2.Написать тест																																
	3.Проверка работы функции с разными строками																								
												!!! ИСПОЛЬЗОВАТЬ УКАЗАТЕЛИ !!!																	
-------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include "stdafx.h"
#include <iostream>
#include <cstring>

int main()
{
	int compstr(char *s1, char *s2);	//prototype

	char stringOne[] = "2";
	char stringTwo[] = "2";

	int myResult = compstr(stringOne, stringTwo);
	int hisResult = strcmp(stringOne, stringTwo);

	std::cout << "myResult  " << myResult << std::endl;
	std::cout << "hisResult " << hisResult << std::endl;

	system("pause");
    return 0;
}

int compstr(char *s1, char *s2) {
	int lengthS1 = strlen(s1);
	int lengthS2 = strlen(s2);

	if (lengthS1 < lengthS2)
		return -1;
	else {
		for (int i = 0; i < lengthS1; i++) {
			if (*(s1 + i) == *(s2 + i) && i + 1 == lengthS1)
				return 0;
			else if (*(s1 + i) > *(s2 + i))
				return 1;
			else if (*(s1 + i) < *(s2 + i))
				return -1;
		}
	}
	std::cout << "Crital ERROR - unknow value!" << std::endl;
	system("pause");
	exit(1);
}
