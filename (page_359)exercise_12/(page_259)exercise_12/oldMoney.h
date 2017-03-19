#include "stdafx.h"
#include <iostream>

char dot = '.';
class sterling
{
private:
	long pounds; //1
	int shilling;
	int pens;
	long double convMoney;
public:
	sterling() : pounds(0), shilling(0), pens(0), convMoney(0.0) {} //2.1
	sterling(long double money): pounds((static_cast<long>(money))/20), shilling(static_cast<int>(money - (pounds*20))), pens(static_cast<int>( (money- (pounds*20+shilling) ) *100.1 )) {} //2.2
	sterling(long p, int s, int pen) :pounds(p), shilling(s), pens(pen) {} //2.3

	void getSterling() { //2.4
		std::cout << "Enter pounds (J9.19.11)" << "\nJ";
		std::cin >> pounds >> dot >> shilling >> dot >> pens;		
	}
	void putSterling() { //2.5
		std::cout << "J" << pounds << dot << shilling << dot << pens << std::endl;
	}
	
	operator double(){ //2.11
		return convMoney = static_cast<long double>((pounds * 20) + shilling) + (static_cast<long double>(pens)*0.01);
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