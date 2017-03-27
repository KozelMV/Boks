// (page_408)exercise_5.cpp : Defines the entry point for the console application.
// ������ ��������� ���� ������ ����������� � �������������� ������������
/*
1. �������� ����������� ����� employee2 �� �������� ������ employee �� ��������� EMPLOY ���� �����.
2. �������� � ����� ����� ���� compensation ���� double  � ���� period ���� enum ��� ����������� ������� ������ ������ ��������� : ���������, ����������� ��� ����������.��� ��������
�� ������ �������� ������ laborer, manager � scientist ���, ����� ��� ����� ������������ ������ ������ employee2.������ �������, ��� �� ������ ������� �������� ���������� ������ compensation � ���� ��� �������� -
��� ������� manager2, scientist2 � laborer2 ����� ��������������� �� ����
���.����� ����� ��������� ������������� ������������ � ������� ���, ����� ��� ��� ����� ������ ����� ������������ ������ compensation � �������������� ������� manager, scientist � laborer.����� ����� �����
�������� ����������� �������� �������.
*/

#include "stdafx.h"
#include <iostream>

const int LEN = 80;       // ������������ ����� �����
class compensation {
private:
double salary;
enum period { na, hWage, wSalary, mSalary };
public:
	compensation() :salary(0.0) {}
	short int entPer;
	void getdata() {
		std::cout << "  ������� �����: $"; std::cin >> salary;
		std::cout << "\t-������(���������(1), �����������(2), ��� � �����(3)): ";
		std::cin >> entPer;
}
	void putdata() const {
		std::cout << "\n  �����: $" << salary;
		std::cout << " -������: ";
		switch (entPer)
		{
		case na: std::cout << "n\a"; break;
		case hWage:	 std::cout << "���������\n";	break;
		case wSalary:std::cout << "�����������\n";	 break;
		case mSalary:std::cout << "��� � �����\n";	break;
		default:
			std::cout << "n\\a\n"; break;
		}
	}
};
class employee            // ����� ���������
{
private:
	char name[LEN];       // ��� ����������
	unsigned long number; // ����� ����������
public:
	void getdata()
	{
		std::cout << "\n  ������� �������: "; std::cin >> name;
		std::cout << "  ������� �����: ";     std::cin >> number;
	}
	void putdata() const
	{
		std::cout << "\n  �������: " << name;
		std::cout << "\n  �����: " << number;
	}
};
///////////////////////////////////////////////////////////
class manager : public employee // ��������
{
private:
	char title[LEN];      // ���������, �������� ����-���������
	double dues;          // ����� ������� � �����-����
public:
	void getdata()
	{
		employee::getdata();
		std::cout << "  ������� ���������: "; std::cin >> title;
		std::cout << "  ������� ����� ������� � �����-����: "; std::cin >> dues;
	}
	void putdata() const
	{
		employee::putdata();
		std::cout << "\n  ���������: " << title;
		std::cout << "\n  ����� ������� � �����-����: " << dues;
	}
};
class manager2 :public manager, public compensation  {

};
///////////////////////////////////////////////////////////
class scientist : public employee // ������
{
private:
	int pubs;                     // ���������� ����������
public:
	void getdata()
	{
		employee::getdata();
		std::cout << "  ������� ���������� ����������: "; std::cin >> pubs;
	}
	void putdata() const
	{
		employee::putdata();
		std::cout << "\n  ���������� ����������: " << pubs;
	}
};
class scientist2 :public compensation, public scientist {

};
///////////////////////////////////////////////////////////
class laborer : public employee   // �������
{
};
class laborer2 :public compensation, public laborer {
};
///////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "");
	manager2 m1;
	scientist2 s1;
	laborer2 l1;

	// ������ ���������� � ���������� �����������
	std::cout << std::endl;
	std::cout << "\n���� ���������� � ������ ���������";
	m1.manager::getdata();
	m1.compensation::getdata();


	std::cout << "\n���� ���������� � ������ ������";
	s1.scientist::getdata();
	s1.compensation::getdata();
	//
	std::cout << "\n���� ���������� � ������ �������";
	l1.laborer::getdata();
	l1.compensation::getdata();
	// ������� ���������� ���������� �� �����
	std::cout << "\n���������� � ������ ���������";
	m1.manager::putdata();
	m1.compensation::putdata();
	std::cout << "\n���������� � ������ ������";
	s1.scientist::putdata();
	s1.compensation::putdata();
	
	std::cout << "\n���������� � ������ �������";
	l1.laborer::putdata();
	l1.compensation::putdata();
	
	std::cout << std::endl;
	system("pause");
	return 0;
}

