// (page_358)exercise_11.cpp : Defines the entry point for the console application.
/*11.Помните структуру sterling? Мы встречались с ней в упражнении 10 главы 2 «Основы программирования на C++», в упражнении 11 главы 5 и
 в других местах.

x 1. Преобразуйте ее в класс, имеющий переменные для фунтов (типа long), шиллингов (типа int) и пенсов (типа int). 
  2. Создайте в классе следующие функции:
x 	2.1	 конструктор без аргументов;
x 	2.2	 конструктор с одним аргументом типа double  (для преобразования от десятичных фунтов);
x 	2.3	 конструктор с тремя аргументами: фунтами, шиллингами и пенсами;
x 	2.4	 метод getSterling() для получения от пользователя значений количества фунтов, шиллингов и пенсов в формате £9.19.11;
x 	2.5	 метод putSterling() для вывода значений количества фунтов, шиллин гов и пенсов в формате £9.19.11;
x 	2.6	 метод для сложения (sterling + sterling), используя перегруженную операцию +;
x 	2.7	 метод вычитания (sterling - sterling), используя перегруженную операцию -;
x 	2.8	 метод умножения (sterling * double), используя перегруженную операцию *;
x	2.9	 метод деления (sterling / sterling), используя перегруженную операцию /;
x	2.10 метод деления (sterling / double), используя перегруженную операцию /;
x 	2.11 операцию double  (для преобразования к типу double)

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
char dot = '.';
class sterling
{
private:
	long pounds; //1
	int shilling;
	int pens;
	double convMoney;
public:
	sterling() : pounds(0), shilling(0), pens(0), convMoney(0.0) {} //2.1
	sterling(double money): pounds((static_cast<long>(money))/20), shilling(static_cast<int>(money - (pounds*20))), pens(static_cast<int>( (money- (pounds*20+shilling) ) *100.1 )) {} //2.2
	sterling(long p, int s, int pen) :pounds(p), shilling(s), pens(pen) {} //2.3

	void getSterling() { //2.4
		std::cout << "Enter pounds (J9.19.11)" << "\nJ";
		std::cin >> pounds >> dot >> shilling >> dot >> pens;		
	}
	void putSterling() { //2.5
		std::cout << "J" << pounds << dot << shilling << dot << pens << std::endl;
	}
	
	operator double(){ //2.11
		return convMoney = static_cast<double>((pounds * 20) + shilling) + (static_cast<double>(pens)*0.01);
	}
	
	sterling operator+(sterling s2) //2.6
	{
		return sterling(double(sterling(pounds, shilling, pens)) + double(s2));
	}
	sterling operator-(sterling s2) //2.7
	{
		return sterling(double(sterling(pounds, shilling, pens)) - double(s2));
	}
	sterling operator*(double s2) //2.8
	{
		return sterling(double(sterling(pounds, shilling, pens)) * s2);
	}
	sterling operator/(sterling s2) //2.7
	{
		sterling temp;
		temp.pounds = pounds / s2.pounds;
		temp.shilling = shilling / s2.shilling;
		temp.pens = pens / s2.pens;
		return temp;
	}
	double operator/(double s2) //2.10
	{
		return double(double(sterling(pounds, shilling, pens)) / s2);
	}

};

int main()
{
	double resD;
	sterling s2(4,6,8), s1(2,2,2), res;

	res = s2 + s1;
	res.putSterling();

	res = s2 - s1;
	res.putSterling();

	resD = s2 * 2.0;
	std::cout << "_" << resD << std::endl;

	res = s2 / s1;
	res.putSterling();

	resD = s2 / 2.0;
	std::cout << "_" << resD << std::endl;

	system("pause");
}




