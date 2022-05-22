
#include <locale.h>
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <array>
#include "library-litvak.h"

using namespace std;

int main()
{
	
start:
	setlocale(LC_ALL, "RU");
	cout << " 1 4  1 6  2 1  2 3  2 7  3 4  5 3  6 5  7 8  8 5  9 4  9 5  9 6  0 0" << endl;
	cout << " 1 2  1 5  1 7  2 6  3 9  4 2  4 8  5 3  7 4  8 3  8 6  9 6  8 9  0 0" << endl;
	Graph G, G1;
	int n,i=0;
	n = G.FormGraph();
	G.SortGraph(G1);
	int *a = new int[n];
	Lider*L = G1.head->next;
	while (L != NULL) {
		a[i] = L->key;
		L = L->next;
		i++;
	}
	cout << endl;
	PrintMas(a, n);


	cout << endl << endl;
	cout << "Хотите запустить программу заново? (y - да, любая другая клавиша - выйти из программы)" << endl;
	char ch;
	cin >> ch;
	if (ch == 'y') { system("cls"); goto start; }
	cout << endl << endl;
	return 0;
}
