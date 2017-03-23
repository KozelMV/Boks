// (page_408)exercise_3.cpp : Defines the entry point for the console application.
/*������� � ������� book, type � publication �� ���������� 1. 
x	1. �������� ������� ����� sales, � ������� ���������� ������, ��������� �� ���� �������� ���� float, ���� ����� �������� ����� ��������� ��������� ���� ��
��������� ��� ������. 
x	2. �������� � ����� ������ getdata() ��� ��������� �������� ��������� �� ������������ � putdata() ��� ������ ���� ����.
-->	3. �������� ������ book � type ���, ����� ��� ����� ������������ ����� �������: publications � sales. ������� ������� book � type ������ �������
� �������� ������ � �������� ������ � ������� ������ �������. 
x	4.�������� ������� main() ��� �������� �������� ������� book � type, ����� �������������� ����������� �����/������ ������.
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
class book :private publication, sales { //�����������(��������) �����
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
class type :private publication, sales { //�����������(��������) �����
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

