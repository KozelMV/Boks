// (page_472)exercise_3.cpp : Defines the entry point for the console application.
/*
����������� ������ ���������� �� ������, �������������� ����� �������� ���� ������, �� ������� PTROSTR ���� �����. 
�������� ������� ��� ���������� ���� ����� � ���������� �������, ��������� � �������� ����-
�� ������� bsort() � order() �� ��������� PTRSORT ���� �����. 
����������� ���������� ��������� �� ������, � �� ���� ������.
*/

#include "stdafx.h"
#include <iostream>

int main()
{
	void bsort(char*, int);    // �������� �������
	const int N = 7;         // ������ �������
	char* arr[N] = { "Monday", "Tuesday" ,"Wednesday", "Thursday", "Friday", "Saturday", "Sunday" }; // ������ ��� ����������

	bsort(*arr, N);

	for (int j = 0; j < N; j++)
		std::cout << *(arr + j) << " ";
	std::cout << std::endl;

	system("pause");
	return 0;
}
//////////////////////////////////////////////////////////
void bsort(char* ptr, int n)
{
	void order(char*, char*);          // �������� �������
	int j, k;                        // ������� � ����� �������

	for (j = 0; j < n - 1; j++)       // ������� ����
		for (k = j + 1; k < n; k++)     // ���������� ����
			order((ptr + j), (ptr + k));     // ��������� ��������
}
///////////////////////////////////////////////////////////
void order(char* numb1, char* numb2) 
{


	if (*numb1 > *numb2)  // ���� ������ ����� ������, �� ������ �� �������
	{
		char *temp[1];
		*temp[0] = *numb1;
		*numb1 = *numb2;
		*numb2 = *temp[0];
	}
}



