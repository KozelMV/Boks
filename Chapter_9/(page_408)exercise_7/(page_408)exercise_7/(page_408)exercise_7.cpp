// (page_408)exercise_7.cpp : Defines the entry point for the console application.
// ������������ � ����������� �������
/*
�������� ��������� COUNTEN2 �� ���� �����. � ��� ����� �����������
� ��������� �������, ��������� ���������� ��������. ��������� �����-
�������, �������� ����������� ������������� ����������� �������� ���
������� ���������� � ����������. (�������� ����������� �������� ��
������� ����� � ����� 8.)

*/

#include "stdafx.h"
#include <iostream>

///////////////////////////////////////////////////////////
class Counter
{
protected:     // ��������, ��� ��� �� ������� ������������ private
	unsigned int count;              // �������
public:
	Counter() : count()              // ����������� ��� ����������
	{ }
	Counter(int c) : count(c)        // ����������� � ����� ����������
	{ }
	unsigned int get_count() const   // ��������� ��������
	{
		return count;
	}
	Counter operator++()             // �������� ����������
	{
		return Counter(++count);
	}
};
///////////////////////////////////////////////////////////
class CountDn : public Counter
{
public:
	CountDn() : Counter()            // ����������� ��� ����������
	{ }
	CountDn(int c) : Counter(c)      // ����������� � ����� ����������
	{ }
	CountDn operator--()             // �������� ����������
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
	CountDn c1;                         // ���������� ������ CountDn
	CountDn c2(100);
	postCount c4(50);

	std::cout << "\nc4 = " << c4.get_count();
	c4++; c4++;
	std::cout << "\nc4 = " << c4.get_count();
	c4--;
	std::cout << "\nc4 = " << c4.get_count();

	std::cout << "\nc1 = " << c1.get_count();// ������� �������� �� �����
	std::cout << "\nc2 = " << c2.get_count();

	++c1; ++c1; ++c1;                   // ����������� c1
	std::cout << "\nc1 = " << c1.get_count();// ���������� ���������

	--c2; --c2;                         // ��������� c2
	std::cout << "\nc2 = " << c2.get_count();  // ���������� ���������

	CountDn c3 = --c2;   // ������� ���������� c3 �� ������ c2
	std::cout << "\nc3 = " << c3.get_count();// ���������� ��������

	std::cout << std::endl;

	system("pause");
	return 0;
}



