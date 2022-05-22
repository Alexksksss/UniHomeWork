#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <locale.h>
#include <math.h>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#define _USE_MATH_DEFINES 
using namespace std;
void RandMas(int *mas, int n, int lf, int rt);
void PrintMas(int *mas, int n);
void OutputBV(unsigned int x, int n);
void Vvod(int*a, int n);
void Vyvod(int*a, int n);
void InputBM(unsigned int *bm, int m, int n);
void OutputBM(unsigned int *bm, int m, int n);
unsigned int Input2BV(char s[], int n);
void SortBubble(int *a, int n);
void SortSheiker(int *a, int n);
/*struct Usel
{
	int key; // информационное поле (поле, содержащее любые данные)
	Usel *next; // указатель на следующий элемент
};
Usel* Push(Usel *head, int k);
Usel* Pop(Usel *head, int *k);
int Top(Usel *head);
bool Empty(Usel *head);
void Clear(Usel *head);*/
//коммивояжер
void change(int &t1, int &t2);
void Inversion(int*P, int n, int i);
bool Permutation(int *p, int n);
int Cost(int*p, int **mtrx, int n);
void swap(int* a, int* b);
