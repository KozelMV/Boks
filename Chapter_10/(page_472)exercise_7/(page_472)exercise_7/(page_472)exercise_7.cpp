// (page_472)exercise_7.cpp : Defines the entry point for the console application.
/*
7.	������������� ����� person �� ��������� PERSORT ���� ����� ���, ����� �� ������� � ���� 
�� ������ ��� ��������, �� � �������� � ��� �������� � ���� ���� salary ���� float. ��� 
����� ���������� �������� ������ setName() � printName() �� setData() � printData(), ������� 
� ��� ����������� ����� � ������ �������� salary, ��� ��� ����� ������� � ������. ��� ����� 
����������� ����� getSalary(). ��������� ���������, �������� ������� salsort(), ������� 
��������� ��������� ������� persPtr �� ��������� ��������. ���������� �������� ��� ���������� 
� ������� salsort(), �� ������� ������ �������, ��� ��� ������� � ��������� PERSORT. ��� ����
�� ���������, ��� �������� -> ����� ������� ���������, ��� �������� *, � ��� ����� ����� ��������
			if((*(pp + j))->getSalary() > (*(pp + k))->getSalary())
				{  ������ ��������� �������  }
*/
/*
X	1. �������� ����� person �� ��������� PERSORT
X	2. �������� �����
	X	1. �������� �������� � �������� � ���� ���� salary ���� float
	X	2. �������� ������ setName() � printName() �� setData() � printData()
		X	1. �������� ���� � ����� �������� salary
	X	3. ������� ����� getSalary()
-->	3. ��������� ���������, �������� ������� salsort()
	-->	- ��������� ��������� ������� persPtr �� ��������� ��������
		- �������� ��� ���������� � ������� salsort()
! if((*(pp + j))->getSalary() > (*(pp + k))->getSalary()) !
! �������� -> ����� ������� ���������, ��� �������� * !
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
