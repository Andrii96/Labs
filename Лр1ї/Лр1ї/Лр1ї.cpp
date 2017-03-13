// Ëð1¿.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#pragma once
#include <omp.h>
#include "targetver.h";
#include <windows.h>
#include <time.h>

using namespace std;

void Selection_Sort(int*, int);
void Selection_Sort_Async(int*, int);
void Swap(int*, int*);

int main()
{
	int number;
	int numbersArray1[10000];
	int numbersArray2[10000];
	cout << "Input number of elements" << endl;
	cin >> number;

	while (number > sizeof(numbersArray1) / sizeof(int)){
		system("cls");
		cout << "The number is too big, please enter another value." << endl;
		cin >> number;
	}

	cout << "Input array" << endl;
	srand((unsigned)time(NULL));
	for (int i = 0; i < number; i++)
	{
		int random = rand() % 100;
		numbersArray1[i]=random;
		numbersArray2[i] = numbersArray1[i];
	}


	int start = GetTickCount();
	for (int i = 0; i < number - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < number; j++)
		{
			if (numbersArray1[j] < numbersArray1[min])
			{
				min = j;
			}
		}

		Swap(&numbersArray1[i], &numbersArray1[min]);
	}
	int end = GetTickCount();
	/*cout << "Sorted array in one thread:" << endl;
	for (int i = 0; i < number; i++){
		cout << *(numbersArray1 + i) << ",";
	}*/
	cout << endl;
	cout << "Execution time in one thread: " << end - start  << "ms" << endl;
	
	long start1 = GetTickCount();
#pragma omp parallel for ordered
	for (int i = 0; i < number - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < number; j++)
		{

			if (numbersArray2[j] < numbersArray2[min])
			{
				min = j;
			}
		}
		Swap(&numbersArray2[i], &numbersArray2[min]);
	}

	long end1 = GetTickCount();

	/*cout << "Sorted array in two threads:" << endl;
	for (int i = 0; i < number; i++){
		cout << *(numbersArray2 + i) << ",";
	}*/
	cout << endl;
	cout << "Execution time in two threads:" << end1 - start1 << "ms" << endl;
	system("pause");
	return 0;
}

void Swap(int *value1, int*value2)
{
	int tmp;
	tmp = *value1;
	*value1 = *value2;
	*value2 = tmp;
}


