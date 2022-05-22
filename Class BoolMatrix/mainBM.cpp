
typedef unsigned char UC;
#include <locale.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include "BM.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "					Task1					" << endl;
	BoolMatrix B1(4, 20);
	cout<<"B1=" << endl << B1 << endl;

	cout << "					Task2					" << endl;
	B1.Invert(0, 10, 8);
	B1.SetUp1(1, 14, 6);
	B1.SetUp1(2, 8, 6);
	for (int i = 0; i < 20; i++)
		if (i % 2 != 0)
			B1.SetUp1(3, i);
	cout << "B1=" << endl << B1 << endl;

	cout << "					Task3					" << endl;
	BoolMatrix B2(B1);
	cout << "B2=" << endl << B2 << endl;

	cout << "					Task4					" << endl;
	if (B1 == B2)
		cout << "B1 = B2" << endl;
	else
		cout << "B1 != B2" << endl;

	cout << "					Task5					" << endl;
	B2.ShiftRightEq(0, 6);
	B2.ShiftLeftEq(2, 6);
	B2.SetUp0(1, 16);
	B2.SetUp0(1, 18);
	for (int i = 0; i < 20; i++) 
		if (i % 2 == 0)
			B2.Invert(3, i);
	cout << "B2=" << endl << B2 << endl;

	cout << "					Task6					" << endl;
	BoolMatrix B3(4, 20);
	cout << "Enter B3" << endl;
	cin >> B3;
	cout << "B3=" << endl << B3 << endl;
	if (B2 == B3)
		cout << "B2 = B3" << endl;
	else
		cout << "B2 != B3" << endl;

	cout << "					Task7					" << endl;
	cout << "enter s: ";
	int p = 4;
	char** s = new char*[p];
	for (int i = 0; i < p; i++)
		s[i] = new char[200];
	for (int i = 0; i < p; i++)
		cin >> s[i];
	for (int i = 0; i < p; i++)
		cout << s[i];
	BoolMatrix B4(s, 4);//в задании b3
	cout << endl;
	cout << "B4=" << endl << B4 << endl;

	cout << "					Task8					" << endl;
	BoolMatrix C1, C2, C3, C4;
	cout << "C1=" << C1 << endl;
	if (C1 == B1)
		cout << "C1 = B1" << endl;
	else
		cout << "C1 != B1" << endl;

	cout << "					Task9					" << endl;
	C1 = B1 & B2; C2 = B1 | B2; C3 = B1 ^ B2; C4 = ~B4;
	cout << "C1 = B1 & B2 = " << endl << C1 << endl;
	cout << "C2 = B1 | B2 = " << endl << C2 << endl;
	cout << "C3 = B1 ^ B2 = " << endl << C3 << endl;
	cout << "C4 = ~B4 =" << endl << C4 << endl;

	cout << "					Task10					" << endl;
	B1 &= B2;
	cout << "B1 &= B2 = " << endl << B1 << endl;
	if (C1 == B1)
		cout << "C1 = B1" << endl;
	else
		cout << "C1 != B1" << endl;

	cout << "					Task11					" << endl;
	cout << "B1[1]=" << B1[1] << endl;
	int el = B1[1][19];
	cout << "B1[1][19]=" << el << endl;
	el = B1[1][18];
	cout << "B1[1][18]=" << el << endl;
	
	//cout << "B1[1][19]=" << B1[1][19] << endl;
	
	//cout << "B1[1][18]=" << B1[1][18] << endl;
	

	cout << "					Task12					" << endl;
	
	BoolVector X;
	X = B1.Disj();
	cout << "B1.Disj=" << endl << X << endl;
	X = B1.Xor();
	cout << "B1.Xor=" << endl << X << endl;
	
	cout << endl << endl;
	return 0;
}
