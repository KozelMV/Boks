// (page_472)exercise_7.cpp : Defines the entry point for the console application.
/*
7.	Модифицируйте класс person из программы PERSORT этой главы так, чтобы он включал в себя 
не только имя человека, но и сведения о его зарплате в виде поля salary типа float. Вам 
будет необходимо изменить методы setName() и printName() на setData() и printData(), включив 
в них возможность ввода и вывода значения salary, как это можно сделать с именем. Вам также 
понадобится метод getSalary(). Используя указатели, напишите функцию salsort(), которая 
сортирует указатели массива persPtr по значениям зарплаты. Попробуйте вместить всю сортировку 
в функцию salsort(), не вызывая других функций, как это сделано в программе PERSORT. При этом
не забывайте, что операция -> имеет больший приоритет, чем операция *, и вам нужно будет написать
			if((*(pp + j))->getSalary() > (*(pp + k))->getSalary())
				{  меняем указатели местами  }
*/
/*
X	1. Копируем класс person из программы PERSORT
X	2. Изменить класс
	X	1. Добавить свединья о зарплате в виде поля salary типа float
	X	2. Изменить методы setName() и printName() на setData() и printData()
		X	1. Включить ввод и вывод значения salary
	X	3. Создать метод getSalary()
-->	3. Используя указатели, написать функцию salsort()
	-->	- сортирует указатели массива persPtr по значениям зарплаты
		- вместить всю сортировку в функцию salsort()
! if((*(pp + j))->getSalary() > (*(pp + k))->getSalary()) !
! операция -> имеет больший приоритет, чем операция * !
----------------------------------------------------------------------------------
*/

#include "stdafx.h"
#include <iostream>
#include <string>

const int MAXPERSONS = 100; //Max persons in array

class person {
protected:
	std::string name; //person's name
	float salary; // person's salary
public:
	person(std::string n, float s) : name(n), salary(s) {} //constructor
	void setData() { //set the name and salary
		std::cout << "Enter name: "; std::cin >> name;
		std::cout << "Enter salary: "; std::cin >> salary;
	}
	void printData() { //get the name and salary
		std::cout << name << ' ';
		std::cout  << salary << "$" << std::endl;
	}
	float getSalary() {
		return salary;
	}
	std::string getName() {
		return name;

	}
};

int main() {
	void salSort(person **persPtr, int i); //prorotype
	person* persPtr[MAXPERSONS];

	int i = 5; //for enter users. write value "i = 0"
	/*-----> close. for enter users <------*/
	persPtr[0]=new person("Maks",2.0);
	persPtr[1]=new person("Pit",4.0);
	persPtr[2]=new person("Jimi",3.0);
	persPtr[3]=new person("Suit",5.0);
	persPtr[4]=new person("Kir",1.0);
	/*-----> --------------------- <------*/

	/*-----> open enter for users <------*/
	//char choice;
	//do {							//put persons in array
	//	persPtr[i] = new person;    //make new object
	//	persPtr[i]->setData(); i++; //set name and salary
	//	std::cout << "Enter another? (y\\n): ";	std::cin >> choice;
	//} while (choice == 'y');
	
	salSort(persPtr,i);

	for (int q = 0; q < i; q++) {  //Print name and salary
		std::cout << "\t#" << q + 1 << ". ";
		persPtr[q]->printData();
	}

	system("pause");
    return 0;
}

void salSort(person **pp, int i) { //sort persons in salary
	/*-----> open for test <------*/
	//void test(person **pp, int j, int k, bool b);

		for (int j = 0; j < i-1; j++) {
			for (int k = j+1; k < i; k++) {
				/*-----> open for test <------*/
				//test(pp, j, k, false);
				if (((*(pp + j))->getSalary()) > ((*(pp + k))->getSalary())) {
					/*-----> open for test <------*/
					//test(pp, j, k,true);
					person *temp = *(pp + k);
					*(pp + k) = *(pp + j);
					*(pp + j) = temp;
				}
			}
		}
}
/*-----> open for test <------*/
//void test(person **pp, int j, int k,bool b) {
//	std::cout << (*(pp + j))->getSalary() << " > " << (*(pp + k))->getSalary();
//	if(b)
//		std::cout << " swapping\n";
//	else
//		std::cout << "\n";
//	system("pause");
//}
/*-----> ------------- <------*/
