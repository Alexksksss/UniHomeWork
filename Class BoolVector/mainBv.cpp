
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <array>
#include <stdio.h>
#include "Bv.h"
using namespace std;
int main() {
	//1//
	cout << "					Task1					" << endl;
	BoolVector B1,B2(10),B3("111011101110"), B4("111011101110", 10), B5("111011101110", 16);
	cout << "B1= " << B1 << endl;
	cout << "B2= " << B2 << endl;
	cout << "B3= " << B3 << endl;
	cout << "B4= " << B4 << endl;
	cout << "B5= " << B5 << endl;
	//2//
	cout << "					Task2					" << endl;
	cout << "Weight B3=" << B3.Weight() << endl;
	cout << "Weight B5=" << B5.Weight() << endl;
	if (B3 == B5) cout << "B3=B5";
	if (B3 != B5) cout << "B3!=B5";
	cout << endl;
	//3//
	cout << "					Task3					" << endl;
	BoolVector B6 = B5;
	cout << "B5= " << B5 << endl;
	cout << "B6= " << B6 << endl;
	//4//
	cout << "					Task4					" << endl;
	cout << "1001100111";
	cout << "Enter B2:";//1001100111
	cin >> B2;
	cout << "B2= " << B2 << endl;
	//5//
	cout << "					Task5					" << endl;
	B1 = B2;
	cout << "B1= " << B1 << endl;
	if (B1 == B2) cout << "B1=B2";
	if (B1 != B2) cout << "B1!=B2";
	cout << endl;
	//6//
	cout << "					Task6					" << endl;
	BoolVector V1, V2, V3;
	V1 = B1 & B3, V2 = B1 | B3, V3 = B1 ^ B3;
	cout << "V1 = B1 & B3=  " << V1 << endl;
	cout << "V2 = B1 | B3=  " << V2 << endl;
	cout << "V3 = B1 ^ B3= " << V3 << endl;
	//7//
	cout << "					Task7					" << endl;
	B1 &= B3;
	cout << "B1= (B1 &= B3) = " << B1 << endl;
	if (B1 == V1) cout << "B1=V1";
	if (B1 != V1) cout << "B1!=V1";
	cout << endl;
	//8//
	cout << "					Task8					" << endl;
	B2 |= B3;
	cout << "B2= (B2 |= B3) = " << B2 << endl;
	if (B2 == V2) cout << "B2=V2";
	if (B2 != V2) cout << "B2!=V2";
	cout << endl;
	//9//
	cout << "					Task9					" << endl;
	cout << "B1= " << B1 << endl;
	~B1;
	cout << "~B1= " << B1 << endl;
	int B14, B15;
	B14 = B1[4];
	B15 = B1[5];
	cout << "B1[4]= " << B14 << endl;
	cout << "B1[5]= " << B15 << endl;
	//10//
	cout << "					Task10					" << endl;
	B1.SetUp1(11); 
	cout << "B1= " << B1 << endl;
	B1.SetUp0(7);
	cout << "B1= " << B1 << endl;
	B1.Invert(9);
	cout << "B1= " << B1 << endl;
	//11//
	cout << "					Task11					" << endl;
	B1.SetUp1(3, 5);
	cout << "B1.SetUp(3,5)= " << B1 << endl;
	B1.Invert(3, 1);
	cout << "B1.Invert(3,1)= " << B1 << endl;
	//12//
	cout << "					Task12					" << endl;
	BoolVector V4;
	V4 = B1 << 4;
	cout << "V4 = (B1 << 4) = " << V4 << endl;
	B1 = B1 >> 4;
	cout << "B1 = (B1 >> 4) = " << B1 << endl;
	if (V4 == B1) cout << "V4=B1";
	if (V4 != B1) cout << "V4!=B1";


	cout << endl;
	system("pause");
	return 0;
}
