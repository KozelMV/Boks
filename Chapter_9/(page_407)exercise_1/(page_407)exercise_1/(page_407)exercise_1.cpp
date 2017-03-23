// (page_407)exercise_1.cpp : Defines the entry point for the console application.
/*ѕредставьте себе издательскую компанию, котора€ торгует книгами и аудио - запис€ми этих книг.—оздайте класс publication, в котором хран€тс€
название(строка) и цена(типа float) книги.ќт этого класса наследуютс€ еще два класса : book, который содержит информацию о количестве страниц
в книге(типа int), и type, который содержит врем€ записи книги в минутах (тип float).¬ каждом из этих трех классов должен быть метод getdata(),
через который можно получать данные от пользовател€ с клавиатуры, и putdata(), предназначенный дл€ вывода этих данных.
Ќапишите функцию main() программы дл€ проверки классов book и type. —оздайте их объекты в программе и запросите пользовател€ ввести и вы -
вести данные с использованием методов getdata() и putdata().*/


#include "stdafx.h"
#include <iostream>
#include <string>

class publication { //базовый класс
private: 
	std::string nameBook;
	float price;
public:
	void getdata() { //ввод данных
		std::cout << "Please enter the name book: " ;
		std::cin >> nameBook; 
		std::cout << "and its cost: $";
		std::cin >> price;
	}
	void putdata() { //вывод данных
		std::cout << nameBook << " _ _ _ " << price << '$' ;
	}
};

class book :private publication { 
protected:
	int pages;
public:
	void getdata() {
		publication::getdata();
		std::cout << "Please enter the number of pages: ";
		std::cin >> pages;
	}
	void putdata() {
		publication::putdata();
		std::cout << " (" << pages << ") pages" << std::endl;
	}
};

class type :private publication{
protected:
	float timeAudio;
public:
	void getdata() {
		publication::getdata();
		std::cout << "Please enter time the audio books: ";
		std::cin >> timeAudio;
	}
	void putdata() {
		publication::putdata();
		std::cout << " (" << timeAudio << ") time audio" << std::endl;
	}

};

int main()
{
	book b1;
	type t1;

	b1.getdata();
	t1.getdata();
	b1.putdata();
	t1.putdata();

	system("pause");
    return 0;
}

