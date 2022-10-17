#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<ctime>
#include <locale.h>
#include <iostream>

using namespace std;

int main(void)

{
	setlocale(LC_ALL, "rus");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	//clock_t start, end; // объявляем переменные для определения времени выполнения

	int i = 0, j = 0, r, n;
	printf("введите количество элементов:");
	scanf_s("%d",&n);
	int elem_c;
	int** c = (int**)malloc(n * sizeof(int)); 
	for (int i = 0; i <= n; i++)
	{
		c[i] = (int*)malloc(n * sizeof(int));
	}

	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	int** a = (int**)malloc(n * sizeof(int));
	for (int i = 0; i <= n; i++)
	{
		a[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i <= n; i++)
	{

		for (int r = 0; r <= n; r++)
		{
			a[i][r] = rand() % 51 - 40;
			//printf("%-5d  ", a[i][j]);

		}

	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	int** b = (int**)malloc(n * sizeof(int));
	for (int r = 0; r <= n; r++)
	{
		b[r] = (int*)malloc(n * sizeof(int));
	}
	for (int r = 0; r <= n; r++)
	{

		for (int j = 0; j <= n; j++)
		{
			b[r][j] = rand() % 51 - 40;
			//printf("%-5d  ", b[r][j]);

		}

	}
	time_t start = clock();
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			elem_c = 0;
			for (r = 0; r < n; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}

	time_t stop = clock();
	cout << endl << "Время сортировки:" << (stop - start) / 1000.0 << "секунд" << endl;
	return(0);
}
