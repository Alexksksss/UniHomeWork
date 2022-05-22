
#include <locale.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include "OSBT.h"
using namespace std;
int main() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(0));

	cout << "						B1.PrintTree					" << endl;
	int d[6] = { -1,10,20,30,40,50 };
	int p[6] = { -1,2,1,1,5,3 };
	int q[6] = { 1,10,1,4,10,6 };
	int n1 = 5;
	OSBinTree B1(d, p, q, n1);
	Node *p1 = B1.GetRoot();
	B1.PrintTree(1, p1);
	SetConsoleTextAttribute(h, (0 << 4) + 15);
	cout << endl;

	cout << endl << "				constructor and operator =				" << endl << endl;
	OSBinTree B3 = B1;
	Node *p3 = B3.GetRoot();
	cout << "constructor B3=B1 checking" << endl;
	B3.PrintTree(1, p3);
	SetConsoleTextAttribute(h, (0 << 4) + 15);
	cout << "operator = (B4=B1) checking" << endl;
	OSBinTree B4;
	B4 = B1;
	Node *p4 = B4.GetRoot();
	B4.PrintTree(1, p4);
	SetConsoleTextAttribute(h, (0 << 4) + 15);

	

	cout << endl << endl;
	return 0;
}
