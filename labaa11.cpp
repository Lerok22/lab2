#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include<time.h>
using namespace std;
void qs(int* items, int left, int right);
char res[200] = "result.txt";
FILE* file;
void shell(int* items, int count)
{

    int i, j, gap, k;
    int x, a[5];

    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;
    time_t start = clock();
    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
    time_t stop = clock();
    file = fopen(res, "a+");
    cout << endl << "Время сортировки shell программы:" << (stop - start) / 1000.0 << "секунд" << endl;
    fprintf(file, "\nВремя сортировки shell программы:%lf", (double)(stop - start) / CLOCKS_PER_SEC);
}

int compare(const void* x1, const void* x2)
{
    return (*(int*)x1 - *(int*)x2);
}

void osnov(int n) {

    time_t time1, time2;
    

    int* arr11 = new int[n];
    int* arr12 = new int[n]; 
    int* arr13 = new int[n];
    int* arr21 = new int[n];
    int* arr22 = new int[n];
    int* arr23 = new int[n];
    int* arr31 = new int[n];
    int* arr32 = new int[n];
    int* arr33 = new int[n];
    int* arr41 = new int[n];
    int* arr42 = new int[n];
    int* arr43 = new int[n];

    for (int i = 0; i < n; i++)
    {
        arr11[i] = 10 + rand() % 90;
        arr12[i] = 10 + rand() % 90;
        arr13[i] = 10 + rand() % 90;
    }

    for (int i = 0; i < n; i++)
    {
        arr21[i] = i + 1;
        arr22[i] = i + 1;
        arr23[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        arr31[i] = n - i;
        arr32[i] = n - i;
        arr33[i] = n - i;
    }

    for (int i = 0; i < n; i++)
    {
        if (i < n / 2) {
            arr41[i] = i + 1;
            arr42[i] = i + 1;
            arr43[i] = i + 1;
        }
        else {
            arr41[i] = n - i;
            arr42[i] = n - i;
            arr43[i] = n - i;
        }


    }

    shell(arr11, n);
    time_t start = clock();
    qs(arr12, 0, n - 1);
    time_t stop = clock();
    time1 = clock();
    qsort(arr13, n, sizeof(int), compare);
    time2 = clock();
    
    
        file = fopen(res,"a+");
       cout << "Время сортировки qsort программы: " << (time2 - time1) / CLOCKS_PER_SEC << endl;
       fprintf(file, "\nВремя сортировки qsort программы:%lf",(double) (time2 - time1) / CLOCKS_PER_SEC);
    cout << endl << "Время сортировки qs программы:" << (stop - start) / 1000.0 << "секунд" << endl;
    fprintf(file, "\nВремя сортировки qs программы:%lf", (double)(stop - start) / CLOCKS_PER_SEC);

    shell(arr21, n);
    start = clock();
    qs(arr22, 0, n - 1);
    stop = clock();
    time1 = clock();
    qsort(arr23, n, sizeof(int), compare);
    time2 = clock();
    cout << "Время сортировки qsort программы: " << (time2 - time1) / CLOCKS_PER_SEC << endl;
    fprintf(file, "\nВремя сортировки qsort программы:%f", (double)(time2 - time1) / CLOCKS_PER_SEC);
    cout << endl << "Время сортировки qs программы:" << (stop - start) / 1000.0 << "секунд" << endl;
    fprintf(file, "\nВремя сортировки qs программы:%f", (double)(stop - start) / CLOCKS_PER_SEC);

    shell(arr31, n);
    start = clock();
    qs(arr32, 0, n - 1);
    stop = clock();
    time1 = clock();
    qsort(arr33, n, sizeof(int), compare);
    time2 = clock();
    cout << "Время сортировки qsort программы: " << (time2 - time1) / CLOCKS_PER_SEC << endl;
    fprintf(file, "\nВремя сортировки qsort программы:%f", (double)(time2 - time1) / CLOCKS_PER_SEC);
    cout << endl << "Время сортировки qs программы:" << (stop - start) / 1000.0 << "секунд" << endl;
    fprintf(file, "\nВремя сортировки qs программы:%f", (double)(stop - start) / CLOCKS_PER_SEC);

    shell(arr41, n);
    start = clock();
    qs(arr42, 0, n - 1);
    stop = clock();
    time1 = clock();
    qsort(arr43, n, sizeof(int), compare);
    time2 = clock();
    cout << "Время сортировки qsort программы: " << (time2 - time1) / CLOCKS_PER_SEC << endl;
    fprintf(file, "\nВремя сортировки qsort программы:%lf", (double)(time2 - time1) / CLOCKS_PER_SEC);
    cout << endl << "Время сортировки qs программы:" << (stop - start) /1000.0 << "секунд" << endl;
    fprintf(file, "\nВремя сортировки qs программы:%lf", (double)(stop - start) / CLOCKS_PER_SEC);

    fclose(file);
    delete[] arr11;
}

int main(void)
{
    setlocale(LC_ALL, "rus");
   
    cout<<endl << "100 elements" << endl;
    osnov(100);
    cout << endl << "200 elements" << endl;
    osnov(200);
    cout << endl << "400 elements" << endl;
    osnov(400);
    cout << endl << "1000 elements" << endl;
    osnov(1000);
    cout << endl << "2000 elements" << endl;
    osnov(2000);
    cout << endl << "4000 elements" << endl;
    osnov(4000);

}
void qs(int items[], int left, int right) //вызов функции: qs(items, 0, count-1);
{
    int i, j;
    int x, y;



    i = left; j = right;

    /* выбор компаранда */
    x = items[(left + right) / 2];
   
    do {
        while ((items[i] < x) && (i < right)) i++;

        while ((x < items[j]) && (j > left)) j--;

        if (i <= j)
        {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
    //delete[] items;
    //cout << endl << "Время сортировки qs программы:" << (stop - start) / 1000.0 << "секунд" << endl;
}