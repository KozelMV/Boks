// (page_472)exercise_4.cpp : Defines the entry point for the console application.
/*
Добавьте деструктор в программу LINKLIST. Он должен удалять все элементы списка при удалении объекта класса linklist. Элементы должны
удаляться по очереди, в соответствии с их расположением в списке. Протестируйте деструктор путем вывода сообщения об удалении каждого из
элементов списка; удалено должно быть также количество элементов, какое было положено в список (деструктор вызывается автоматически для
каждого существующего объекта).
	1.Скопировать LINKLIST
-->	2.Добавить деструктор
		-Удалять все элементы списка при удалении объекта класса
	-->	-Элементы должны удаляться по очереди
	3.Тест деструктора
*/

#include "stdafx.h"
#include <iostream>
///////////////////////////////////////////////////////////
const int MAX = 100;

struct link   // один элемент списка
{
	int data;   // некоторые данные
	link* next; // указатель на следующую структуру
};
///////////////////////////////////////////////////////////
class linklist // список
{
private:
	link* first;
	void* arrAddress[MAX];
	int countArr = 0;
public:
	linklist() { // конструктор без параметров
		first = NULL;
	}   // первого элемента пока нет
	~linklist() { //деструктор
		link* clr = first;           // начинаем с первого элемента
		while (clr)                   // пока есть данные
		{
			std::cout << "To clear address" << '(' << clr << ')' << "with value = " << clr->data << std::endl;
			link* temp = clr;
			clr = clr->next;
			delete temp;
		}
		system("pause");
	}
	void additem(int d);  // добавление элемента
	void display();       // показ данных
};
///////////////////////////////////////////////////////////
void linklist::additem(int d)    // добавление элемента
{
	link* newlink = new link;      // выделяем память
	arrAddress[countArr++] = newlink;	//save all address in array
	newlink->data = d;             // запоминаем данные
	newlink->next = first;         // запоминаем значение first
	first = newlink;               // first теперь указывает на новый элемент
}
///////////////////////////////////////////////////////////
void linklist::display()
{
	link* current = first;           // начинаем с первого элемента
	while (current)                   // пока есть данные
	{
		std::cout << current->data << std::endl; // печатаем данные
		current = current->next;       // двигаемся к следующему элементу
	}
}
///////////////////////////////////////////////////////////
int main()
{
	linklist li;       // создаем переменную-список

	li.additem(25);    // добавляем туда несколько чисел
	li.additem(36);
	li.additem(49);
	li.additem(64);
	li.display();      // показываем список

	system("pause");
	return 0;
}


