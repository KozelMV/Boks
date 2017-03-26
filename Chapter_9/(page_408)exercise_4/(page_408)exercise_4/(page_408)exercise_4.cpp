// (page_408)exercise_4.cpp : Defines the entry point for the console application.
/*    Предположим, что издатель из упражнений 1 и 3 решил добавить к своей продукции версии книг на компьютерных дисках для тех, кто любит чи-
тать книги на своих компьютерах.
v	1.Добавьте класс disk, который, как book и type, является производным класса publication. 
v	2.Класс disk должен включать в себя те же функции, что и в других классах. 
v	3.Полем только этого класса будет тип диска: CD или DVD. 
v	4.Для хранения этих данных вы можете ввести тип enum. 
-->	5.Пользователь должен выбрать подходящий тип, набрав на клавиаtype с или d.
*/

#include "stdafx.h"
#include <iostream>
#include <string>

class publication { //базовый(родительский) класс
private:
	std::string nameBook;
	float price;
public:
	void getdata() { //ввод данных
		std::cout << "Please enter the name book: ";
		std::cin >> nameBook;
		std::cout << "and its cost: $";
		std::cin >> price;
	}
	void putdata() { //вывод данных
		std::cout << nameBook << " _ _ _ " << price << '$';
	}
};
class sales {	//базовый(родительский) класс
private:
	float tCost[3];
public:
	void getdata() {
		for (int i = 0; i < 3; i++) {
			std::cout << "Pleace enter total cost: " << i + 1 << "monts: ";
			std::cin >> tCost[i];
		}
	}
	void putdata() {
		std::cout << std::endl;
		for (int i = 0; i < 3; i++)
			std::cout << "\nThe " << i + 1 << " month total cost = $" << tCost[i];
		std::cout << std::endl;
	}
};
class paperBook :private publication, sales { //производный(дочерний) класс
private:
	int pages;
public:
	void getdata() {
		publication::getdata();
		std::cout << "Please enter the number of pages: ";
		std::cin >> pages;
		sales::getdata();
	}
	void putdata() {
		publication::putdata();
		std::cout << " (" << pages << ") pages" << std::endl;
		sales::putdata();
	}
};
class audioBook :private publication, sales { //производный(дочерний) класс
private:
	float timeAudio;
public:
	void getdata() {
		publication::getdata();
		std::cout << "Please enter time the audio books: ";
		std::cin >> timeAudio;
		sales::getdata();
	}
	void putdata() {
		publication::putdata();
		std::cout << " (" << timeAudio << ") time audio" << std::endl;
		sales::putdata();
	}

};
class computerBook : private publication, sales {
private:
	enum type { na ,cd ,dvd};
public:
	short userType = 0;
	void getdata() {
		publication::getdata();
		std::cout << "Please enter type the computer-book (\'c\' or \'d\'): ";
		char entType;
		std::cin >> entType;
			switch (entType) {
			case 'c': userType = cd; break;
			case 'd': userType = dvd; break;
			default:
				userType = na;
			}
			sales::getdata();
	}
	void putdata() {
		publication::putdata();
		std::cout << "Computer-book type: ";
		switch (userType){
		case na:  std::cout << "n\\a" <<std::endl;break;
		case cd:  std::cout << "cd"   <<std::endl;break;
		case dvd: std::cout << "dvd"  <<std::endl;break;
		default:
			std::cout << "n'\a" << std::endl; break;
		}
		sales::putdata();
	}
};

int main()
{
	paperBook b1;
	audioBook t1;
	computerBook cb1;
	
	
	b1.getdata();
	t1.getdata();
	cb1.getdata();
	std::cout << std::endl;
	b1.putdata();
	t1.putdata();
	cb1.putdata();

	system("pause");
	return 0;
}

