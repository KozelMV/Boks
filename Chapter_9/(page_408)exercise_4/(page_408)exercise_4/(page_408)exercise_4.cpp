// (page_408)exercise_4.cpp : Defines the entry point for the console application.
/*    �����������, ��� �������� �� ���������� 1 � 3 ����� �������� � ����� ��������� ������ ���� �� ������������ ������ ��� ���, ��� ����� ��-
���� ����� �� ����� �����������.
v	1.�������� ����� disk, �������, ��� book � type, �������� ����������� ������ publication. 
v	2.����� disk ������ �������� � ���� �� �� �������, ��� � � ������ �������. 
v	3.����� ������ ����� ������ ����� ��� �����: CD ��� DVD. 
v	4.��� �������� ���� ������ �� ������ ������ ��� enum. 
-->	5.������������ ������ ������� ���������� ���, ������ �� ������type � ��� d.
*/

#include "stdafx.h"
#include <iostream>
#include <string>

class publication { //�������(������������) �����
private:
	std::string nameBook;
	float price;
public:
	void getdata() { //���� ������
		std::cout << "Please enter the name book: ";
		std::cin >> nameBook;
		std::cout << "and its cost: $";
		std::cin >> price;
	}
	void putdata() { //����� ������
		std::cout << nameBook << " _ _ _ " << price << '$';
	}
};
class sales {	//�������(������������) �����
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
class paperBook :private publication, sales { //�����������(��������) �����
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
class audioBook :private publication, sales { //�����������(��������) �����
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

