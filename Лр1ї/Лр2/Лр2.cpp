// Ëð2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#pragma once

#include "omp.h"
#include <stdio.h>
#include <tchar.h>
#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	const int N = 80000;
	int mas[N], sum[N];

	for (int i = 0; i < N; i++)
		mas[i] = 1 + rand() % 1000;

	sum[0] = mas[0];

	int start = GetTickCount();

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < i; j++)
			sum[j] = sum[j - 1] + mas[i];
	}

	int end = GetTickCount();

	cout << endl << "One thread: " << end - start << " ms\n\n";

	start = GetTickCount();

#pragma omp parallel for

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < i; j++)
			sum[j] = sum[j - 1] + mas[i];
	}

	end = GetTickCount();

	cout << endl << "Two threads: " << end - start << "ms\n\n";
	system("pause");
	return 0;
}

