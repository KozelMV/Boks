// (page_408)exercise_3.cpp : Defines the entry point for the console application.
/*Начните с классов book, type и publication из упражнения 1. 
x	1. Добавьте базовый класс sales, в котором содержится массив, состоящий из трех значений типа float, куда можно записать общую стоимость проданных книг за
последние три месяца. 
x	2. Включите в класс методы getdata() для получения значений стоимости от пользователя и putdata() для вывода этих цифр.
-->	3. Измените классы book и type так, чтобы они стали производными обоих классов: publications и sales. Объекты классов book и type должны вводить
и выводить данные о продажах вместе с другими своими данными. 
x	4.Напишите функцию main() для создания объектов классов book и type, чтобы протестировать возможности ввода/вывода данных.
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
class book :private publication, sales { //производный(дочерний) класс
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
class type :private publication, sales { //производный(дочерний) класс
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

int main()
{
	book b1;
	type t1;

	b1.getdata();
	t1.getdata();
	std::cout << std::endl;
	b1.putdata();
	t1.putdata();

	system("pause");
    return 0;
}

