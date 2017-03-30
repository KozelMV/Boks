// persort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <Windows.h>
class person
{
protected:
	std::string name;
public:
	void setName() {
		std::cout << "Введите имя: "; std::cin >> name;
	}
	void printName() {
		std::cout << std::endl << name;
	}
	std::string getName() {
		return name;
	}

};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	void bSort(person**, int);// prortotype
	person* persPtr[100];
	int n = 0;

	char choice;
	do
	{
		persPtr[n] = new person;
		persPtr[n]->setName();
		n++;
		std::cout << "Продолжить ввод?(y\\n): "; std::cin >> choice;
	} while (choice == 'y');

	std::cout << "\nНеотсортированный список: ";
	for (int j = 0; j < n; j++)
		persPtr[j]->printName();
	bSort(persPtr, n);
	std::cout << "\nОтсартированный список";
	for (int j = 0; j < n; j++)
		persPtr[j]->printName();

	system("pause");
    return 0;
}

void bSort(person**pp, int n) {
	void order(person**, person**); //prototype
	int j, k;
	for (j = 0; j < n - 1; j++) {
		for (k = j + 1; k < n; k++)
			order(pp + j, pp + k);
	}
}
void order(person** pp1, person** pp2) {
	if ( (*pp1)->getName() > (*pp2)->getName() )
	{
		person*tempptr = *pp1;
		*pp1 = *pp2;
		*pp2 = tempptr;
	}
}
