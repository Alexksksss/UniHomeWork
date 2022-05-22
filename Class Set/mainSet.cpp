
#include <locale.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include "Set.h"

using namespace std;


int main()
{
	cout << "					Task1					" << endl;
	char s[257];
	cout << "Enter string: " << endl;
	gets_s(s, 256);
	Set S1(s);
	cout << "S1= ";
	S1.Print();
	int count = S1.Number();
	cout << endl << "S1.Number= " << count << endl;

	cout << "					Task2					" << endl;
	Set S2(S1);
	cout << "S2= " << S2 << endl;
	if (S1 == S2) cout << "S1==S2" << endl;
	else cout << "S1!=S2" << endl;

	cout << "					Task3					" << endl;
	if (S2.FindKey('o'))
		S2 -= 'o';
	else S2 += 'o';
	if (S2.FindKey('a'))
		S2 -= 'a';
	else S2 += 'a';
	cout << "S2= " << S2 << endl;
	if (S1 == S2) cout << "S1==S2" << endl;
	else cout << "S1!=S2" << endl;

	cout << "					Task4					" << endl;
	Set S3;
	cout << "S3= " << S3 << endl;
	if (S3.Empty())
		cout << "S3 is empty" << endl;
	else cout << "S3 is not empty" << endl;

	cout << "					Task5					" << endl;
	cout << "Enter S3" << endl;
	S3.Scan(6);
	if (S3.Empty())
		cout << "S3 is empty" << endl;
	else cout << "S3 is not empty" << endl;
	cout << "S3= " << S3 << endl;

	cout << "					Task6					" << endl;
	Set S4 = S3 - 'y' + 'i';
	cout << "S4= " << S4 << endl;

	cout << "					Task7					" << endl;
	Set T1;
	T1 = S2 + S4;
	Set T2;
	T2 = S2 * S4;
	Set T3;
	T3 = S2 - S4;
	cout << "T1= " << T1 << endl;
	cout << "T2= " << T2 << endl;
	cout << "T3= " << T3 << endl;

	cout << "					Task8					" << endl;
	Set T4;
	T4 = ~S2;
	Set T5;
	T5 = T4 * T2;
	cout << "T4= " << T4 << endl;
	cout << "T5= " << T5 << endl;

	cout << "					Task9					" << endl;
	Set S5;
	cin >> S5;
	cout << "S5= " << S5 << endl;

	cout << "					Task10					" << endl;
	S5 = S5 * S1;
	cout << "S5= " << S5 << endl;

	cout << "					Task11					" << endl;
	S5 = S5 + T2;
	cout << "S5= " << S5 << endl;

	cout << "					Task12					" << endl;
	Set S6;
	S6 = S1;
	cout << "S6= " << S6 << endl;
	if (S5 == S6) cout << "S5==S6" << endl;
	else cout << "S5!=S6" << endl;


	cout << endl << endl;
	return 0;
}
