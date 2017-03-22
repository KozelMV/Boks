// (page_358)exercise_10.cpp : Defines the entry point for the console application.
/*10.	Только для любителей математики: 
1.создайте класс Polar, который предназначен для хранения полярных координат (радиуса и угла). 
2.Перегрузите операцию + для выполнения сложения для объектов класса Polar. Сложение двух объектов выполняется путем сложения координат X объектов,
а затем координат Y. 
3.Результат будет координатами новой точки. 
4.Таким образом, вам нужно будет преобразовать полярные координаты к прямоугольным, сложить их, а затем обратно преобразовать прямоугольные ко-
ординаты результата к полярным.
*/

#include "stdafx.h"
#include <iostream>
#include <cmath> //cos(),sin(),tan() , sqrt()
#include <iomanip>

class Polar
{
private:
	long double rad; //Полярные координаты (Радиальная координат r (от 0 до беск))
	long double angle; //Полярные координаты (Угловая координат f (от 0 до 360) )
	long double decY; //Декардовые координаты
	long double decX; //Декардовые координаты
	
	//Перевести декартовые в полярные координаты (градусы)
	void convCooD_P()
	{
		rad = sqrt(decX * decX + decY * decY);
		angle = sin(decY/rad);
	}
public:
	//Конструктор
	Polar(long double a, long double r) :angle(a), rad(r) 
	{	//Перевести полярные координаты в декартовые (градусы)
		decX = rad * cos(angle);
		decY = rad * sin(angle);
	}
	Polar() :decX(), decY() {}
	//.2
	Polar operator+(Polar p) /*x=r*cos(f), y=r*sin(f)*/
	{
		Polar temp;
		
		temp.decX = decX + p.decX;
		temp.decY = decY + p.decY;

		temp.convCooD_P();

		return temp;
	}
	
	void showResult()
	{
		std::cout  << "x = " <<std::fixed << std::setprecision(10) << decX << "\ny= " << decY << std::endl;
		std::cout << "r = " << std::fixed << std::setprecision(10) << rad << "\nf = " << angle << std::endl;
	}
	
};

int main()
{
	setlocale(LC_ALL, "");
	Polar p1(45, 1.41421), p2(45, 1.41421), res;
	res = p1 + p2;
	res.showResult();
	system("pause");
    return 0;
}

