// (page_531)exercise_1.cpp : Defines the entry point for the console application.
/*
*1. Пусть имеется та же издательская компания, которая описана в упражне-
нии 1 главы 9, которая продает и книги, и аудио версии печатной продук -
ции.Как и в том упражнении, создайте класс publication, хранящий название
(фактически, строку) и цену(типа float) публикации.Создайте два порож -
денных класса : book, в котором происходит изменение счетчика страниц(ти -
па int), и tape, в котором происходит изменение счетчика записанных на
кассету минут.Каждый из классов должен иметь метод getdata(), запраши -
вающий информацию у пользователя, и putdata() для вывода данных на экран.
*/

#include "stdafx.h"
#include <iostream>
#include <string>

class publication {
private:
	std::string name;
	float price;
public:
	virtual void getdata() {
		std::cout << "Please enter a name book: "; std::cin >> name;
		std::cout << "Please enter a price book: "; std::cin >> price;
	}
	virtual void putdata() {
		std::cout << "Name book: \"" << name << "\" " << " =" << price << '$';
	}
};
class book : public publication {
private:
	int countPage;
public:
	void getdata() {
		publication::getdata();
		std::cout << "Please enter a number pages: "; std::cin >> countPage;
	}
	void putdata() {
		publication::putdata();
		std::cout << " number pages: =" << countPage << std::endl;
	}
};
class tape : public publication {
private:
	int time;
public:
	void getdata() {
		publication::getdata();
		std::cout << "Please enter a number minutes: "; std::cin >> time;
	}
	void putdata() {
		publication::putdata();
		std::cout << " number minutes: =" << time << std::endl;
	}
};

int main()
{
	publication* arrBook[100];
	int q = 0;
	char esc;
	do{	
		std::cout << " \'a\'udio or \'p\'age book"; std::cin >> esc;
		if (esc == 'a') 
			arrBook[q] = new book;		
		else 
			arrBook[q] = new tape;
		arrBook[q++]->getdata();
		
		
		std::cout << "Enter \'q\' to do exit!"; std::cin >> esc;
	} while (esc != 'q');

	for(int i = 0 ; i<q;i++)
		arrBook[i]->putdata();
	system("pause");
    return 0;
}

