// TheBubbleSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	void bSort(int*, int); //prototype
	const int MAX = 10;
	int arr[MAX] = { 4,5,8,3,0,1,9,2,6,7 };
	
	bSort(arr, MAX);

	for ( int i = 0; i < MAX; i++){
		std::cout << arr[i] << " ";
	}
	
	system("pause");
    return 0;
}
void bSort(int *arr, int max) {
	void order(int*, int*); //prototype
	for (int i = 0; i < max-1; i++){
		for (int j = i+1; j < max; j++){
			order(arr + i, arr + j);
		}
	}
}

void order(int *numb1, int *numb2) { 
	if (*numb1 > *numb2) {
		int temp = *numb1;
		*numb1 = *numb2;
		*numb2 = temp;
	}
}

