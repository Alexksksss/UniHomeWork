
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
#include <Windows.h>
#include <iostream>
#include <locale.h>
#include <string.h>
#include <queue>
using namespace std;
// функция формирования массива случайных чисел в диапазоне от lf до rt
void RandMas(int *mas, int n, int lf, int rt)
{
	srand(time(0));
	for (int i = 0; i < n; i++) mas[i] = rand() % (rt - lf + 1) + lf;
}
// функция вывода массива на печать
void PrintMas(int *mas, int n)
{
	for (int i = 0; i < n; i++) printf("%4d", mas[i]);
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// вывод бв

//Функция вывода булевого вектора
#define UI unsigned int
void OutputBV(UI x, int n)
{
	UI mask = 1; int i;
	mask <<= n - 1;
	for (i = 1; i <= n; i++, mask >>= 1)
		if (x&mask) printf("1");
		else putchar('0');
}
// ввод массива указатели
void Vvod(int*a, int n)
{
	for (int *p = a; p < a + n; p++) *p = rand() % 100;
}
// вывод массива указатели
void Vyvod(int*a, int n)
{
	int i = 0;
	for (int i = 0; i < n; i++) {

		printf("%3d", a[i]);
	}
	printf(" \n");
}

// ввод бв
UI Input2BV(char s[], int n)
{
	UI x = 0, mask = 1; int i;
	for (i = 0; i < n; i++)
	{
		x <<= 1;
		if (s[i] == '1') x++;
	}
	return x;
}

//ввод булевой матрицы

void InputBM(UI *bm, int m, int n)
{
	int i; char s[33];
	for (i = 0; i < m; i++)
	{
		fgets(s, sizeof(s), stdin);
		bm[i] = Input2BV(s, n);
	}
}
//вывод булевой матрицы

void OutputBM(UI* bm, int m, int n)
{
	int i;
	for (i = 0; i < m; i++)
	{
		OutputBV(bm[i], n);
		puts("");
	}
}

// Сортировка массива метоом пузырька
void SortBubble(int *a, int n) {
	int temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

//сортировка шейкером
void SortSheiker(int *a, int n)
{
	int left = 0, right = n - 1;
	int flag = 1;
	while ((left < right) && (flag = 1))
	{
		flag = 0;
		for (int i = left; i < right; i++)
		{
			if (a[i] > a[i + 1])
			{
				int t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;
				flag = 1;
			}
		}
		right--;
		for (int i = right; i > left; i--)
		{
			if (a[i - 1] > a[i])
			{
				int t = a[i];
				a[i] = a[i - 1];
				a[i - 1] = t;
				flag = 1;
			}
		}
		left++;
	}
}
