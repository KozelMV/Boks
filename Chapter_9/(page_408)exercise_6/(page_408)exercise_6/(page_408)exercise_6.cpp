// (page_408)exercise_6.cpp : Defines the entry point for the console application.
/*
�������� ��������� ARROVER3 �� ����� 8. �������� ����� safearay ����� �� �, ��������� ������������, ������� � ���� ����������� ��� ������ -
������ ���������� ������� � ������ ������� ������� � ������������.
��� ������ �� ���������� 9 �� ����� 8, �� ����������� ����, ��� ��������� ������������ ��� �������� ������ ������(����� ������� ���
safehilo) ������ ����������� ��������� ������.
*/

#include "stdafx.h"
#include <iostream>
#include <process.h>      // ��� ������� exit
const int LIMIT = 100;    // ������ �������
///////////////////////////////////////////////////////////
class safearray
{
private:
	int arr[LIMIT];
public:

	// �������� ��������, ��� ������� ���������� ������!
	int& operator[](int n)
	{
		if (n < 0 || n >= LIMIT)
		{
			std::cout << "\n��������� ������!"; exit(1);
		}
		return arr[n];
	}
};
class safehilo : public safearray {
private:
	int str, fin;
public:
	//����������� � ���� �����������
	safehilo() : str(0), fin(100){
		void check();
	}
	safehilo(short int s, short int f) : str(s), fin(f){
		void check();
	}
	void check() {
		if (str >= LIMIT)
			str = str % LIMIT;
		if (fin > LIMIT)
			fin = fin % LIMIT;
	}
	int down() { return str; };
	int top() { return fin; };
};
///////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "");
	safehilo sa1(5,10);

	// ������ �������� ���������
	for (int j = sa1.down(); j <= sa1.top(); j++)
		sa1[j] = j * 10;    // ���������� ������� ����� �� ����� =

							// ���������� ��������
	for (int j = sa1.down(); j <= sa1.top(); j++)
	{
		int temp = sa1[j];  // ���������� ������� ������ �� ����� =
		std::cout << "������� " << j << " ����� " << temp << std::endl;
	}

	system("pause");
	return 0;
}

