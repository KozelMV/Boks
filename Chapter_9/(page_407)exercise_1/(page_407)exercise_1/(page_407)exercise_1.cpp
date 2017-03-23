// (page_407)exercise_1.cpp : Defines the entry point for the console application.
/*����������� ���� ������������ ��������, ������� ������� ������� � ����� - �������� ���� ����.�������� ����� publication, � ������� ��������
��������(������) � ����(���� float) �����.�� ����� ������ ����������� ��� ��� ������ : book, ������� �������� ���������� � ���������� �������
� �����(���� int), � type, ������� �������� ����� ������ ����� � ������� (��� float).� ������ �� ���� ���� ������� ������ ���� ����� getdata(),
����� ������� ����� �������� ������ �� ������������ � ����������, � putdata(), ��������������� ��� ������ ���� ������.
�������� ������� main() ��������� ��� �������� ������� book � type. �������� �� ������� � ��������� � ��������� ������������ ������ � �� -
����� ������ � �������������� ������� getdata() � putdata().*/


#include "stdafx.h"
#include <iostream>
#include <string>

class publication { //������� �����
private: 
	std::string nameBook;
	float price;
public:
	void getdata() { //���� ������
		std::cout << "Please enter the name book: " ;
		std::cin >> nameBook; 
		std::cout << "and its cost: $";
		std::cin >> price;
	}
	void putdata() { //����� ������
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

