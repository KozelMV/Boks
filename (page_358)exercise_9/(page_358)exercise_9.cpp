// (page_358)exercise_9.cpp : Defines the entry point for the console application.
// ������������ �������� ����������� �������, ������������
// ���� ������� ��� �������������
// ������������ ���������� �������� []

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
			std::cout << "\n��������� ������!\n"; 
			system("pause");  
			exit(1);
		}
		return arr[n];
	}
};
///////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "");
	safearray sa1;

	// ������ �������� ���������
	for (int j = 0; j < LIMIT+2; j++)
		sa1[j] = j * 10;    // ���������� ������� ����� �� ����� =

							// ���������� ��������
	for (int j = 0; j < LIMIT; j++)
	{
		int temp = sa1[j];  // ���������� ������� ������ �� ����� =
		std::cout << "������� " << j << " ����� " << temp << std::endl;
	}
	system("pause");

	return 0;
}
