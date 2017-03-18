// (page_358)exercise_11.cpp : Defines the entry point for the console application.
/*11.Помните структуру sterling? Мы встречались с ней в упражнении 10 главы 2 «Основы программирования на C++», в упражнении 11 главы 5 и
 в других местах.

 1. Преобразуйте ее в класс, имеющий переменные для фунтов (типа long), шиллингов (типа int) и пенсов (типа int). 
 2. Создайте в классе следующие функции:
	2.1	 конструктор без аргументов;
	2.2	 конструктор с одним аргументом типа double  (для преобразования от десятичных фунтов);
	2.3	 конструктор с тремя аргументами: фунтами, шиллингами и пенсами;
	2.4	 метод getSterling() для получения от пользователя значений количества фунтов, шиллингов и пенсов в формате £9.19.11;
	2.5	 метод putSterling() для вывода значений количества фунтов, шиллин гов и пенсов в формате £9.19.11;
	2.6	 метод для сложения (sterling + sterling), используя перегруженную операцию +;
	2.7	 метод вычитания (sterling - sterling), используя перегруженную операцию -;
	2.8	 метод умножения (sterling * double), используя перегруженную операцию *;
	2.9	 метод деления (sterling / sterling), используя перегруженную операцию /;
	2.10 метод деления (sterling / double), используя перегруженную операцию /;
	2.11 операцию double  (для преобразования к типу double)

Выполнять вычисления вы можете, например, складывая отдельно данные объекта: сложить сначала пенсы, затем шиллинги и т. д. Однако легче
использовать операцию преобразования для преобразования объекта класса sterling к типу double, выполнить вычисления с типами double, а затем
преобразовать обратно к типу sterling. Таким образом, операция + выглядит похожей на эту:
 sterling sterling::operator+(sterling s2)
 {
	 return sterling(double(sterling(pounds, shillings, pense)) + double(s2));
 }
Так мы создадим две временных переменных типа double, одна происходит от объекта, который вызывает функцию, а другая от аргумента s2.
Эти переменные затем складываются, результат преобразовывается к типу sterling и возвращается.
Заметим, что мы использовали другой подход для класса sterling, нежели для класса bMoney. В классе sterling мы используем операции преобразова-
ния, таким образом отказавшись от возможности поиска неправильных операций, но получив простоту при записи перегружаемых математических операций.
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

struct sterling
{
	int pounds;
	int shilling;
	int pens;
};
sterling s1, s2, sum;
char dot;

sterling input(sterling);
sterling addition(sterling, sterling);
void output(sterling);

int main()
{
	s1 = input(s1);
	s2 = input(s2);
	sum = addition(s1, s2);
	output(sum);
	system("pause");
}

sterling input(sterling str)
{
	cout << "Enter pounds" << endl;
	cin >> str.pounds >> dot >> str.shilling >> dot >> str.pens;
	return str;
}

sterling addition(sterling str1, sterling str2)
{
	sterling sum;
	int sumpens = (str1.pounds * 20 * 12 + str1.shilling * 12 + str1.pens) + (str2.pounds * 20 * 12 + str2.shilling * 12 + str2.pens);
	sum.pounds = sumpens / (20 * 12);
	sum.shilling = sumpens % (20 * 12) / 12;
	sum.pens = sumpens % (20 * 12) % 12;
	return sum;
}

void output(sterling sum)
{
	cout << "All J" << sum.pounds << dot << sum.shilling << dot << sum.pens << endl;
}

