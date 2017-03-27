// (page_408)exercise_7.cpp : Defines the entry point for the console application.
// конструкторы в производных классах
/*
Вспомним программу COUNTEN2 из этой главы. В ней можно увеличивать
и уменьшать счетчик, используя префиксные операции. Используя насле-
дование, добавьте возможность использования постфиксных операций для
случаев увеличения и уменьшения. (Описание постфиксных операций вы
сможете найти в главе 8.)

*/

#include "stdafx.h"
#include <iostream>

///////////////////////////////////////////////////////////
class Counter
{
protected:     // заметьте, что тут не следует использовать private
	unsigned int count;              // счетчик
public:
	Counter() : count()              // конструктор без параметров
	{ }
	Counter(int c) : count(c)        // конструктор с одним параметром
	{ }
	unsigned int get_count() const   // получение значения
	{
		return count;
	}
	Counter operator++()             // оператор увеличения
	{
		return Counter(++count);
	}
};
///////////////////////////////////////////////////////////
class CountDn : public Counter
{
public:
	CountDn() : Counter()            // конструктор без параметров
	{ }
	CountDn(int c) : Counter(c)      // конструктор с одним параметром
	{ }
	CountDn operator--()             // оператор уменьшения
	{
		return CountDn(--count);
	}
};
///////////////////////////////////////////////////////////
class postCount :public Counter {
public:
	postCount () : Counter() {}
	postCount (int x) : Counter(x) {}

	postCount operator++(int)
	{
		return (count++);
	}
	postCount operator--(int)
	{
		return (count--);
	}
};

int main()
{
	CountDn c1;                         // переменные класса CountDn
	CountDn c2(100);
	postCount c4(50);

	std::cout << "\nc4 = " << c4.get_count();
	c4++; c4++;
	std::cout << "\nc4 = " << c4.get_count();
	c4--;
	std::cout << "\nc4 = " << c4.get_count();

	std::cout << "\nc1 = " << c1.get_count();// выводим значения на экран
	std::cout << "\nc2 = " << c2.get_count();

	++c1; ++c1; ++c1;                   // увеличиваем c1
	std::cout << "\nc1 = " << c1.get_count();// показываем результат

	--c2; --c2;                         // уменьшаем c2
	std::cout << "\nc2 = " << c2.get_count();  // показываем результат

	CountDn c3 = --c2;   // создаем переменную c3 на основе c2
	std::cout << "\nc3 = " << c3.get_count();// показываем значение

	std::cout << std::endl;

	system("pause");
	return 0;
}



