
#include <locale.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include "SBT.h"
using namespace std;


int main(){
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(0));
	Node *p1;
	SBinTree B1(5);
	p1 = B1.GetRoot();

	cout<<endl << "				B1 Print				" << endl<<endl;
	B1.PrintTree(1, p1);
	SetConsoleTextAttribute(h, (0 << 4) + 15);
	cout << endl;

	cout << endl << "				B2 (ARRAY) Print				" << endl<<endl;
	Node *p2;
	int n;
	cout << "Enter n" << endl;
	cin >> n;
	int *a = new int[n];
	cout << "Enter a[i]: ( 13 2 8 63 12 )";
	for (int i = 0; i < n; i++)		cin >> a[i];
	cout << endl << "a= ";
	PrintMas(a, n);
	cout << endl << endl;
	SBinTree B2(a,n);
	p2 = B2.GetRoot();
	B2.PrintTree(1, p2);
	SetConsoleTextAttribute(h, (0 << 4) + 15);

	cout << endl << "				constructor and operator =				" << endl<<endl;
	SBinTree B3 = B1;
	Node *p3 = B3.GetRoot();
	cout << "constructor B3=B1 checking" << endl;
	B3.PrintTree(1, p3);
	SetConsoleTextAttribute(h, (0 << 4) + 15);
	cout << "operator = (B4=B2) checking" << endl;
	SBinTree B4;
	B4 = B2;
	Node *p4 = B4.GetRoot();
	B4.PrintTree(1, p4);
	SetConsoleTextAttribute(h, (0 << 4) + 15);
	


	cout << endl <<"				B1.FindMAx,FindMin				" << endl<<endl;
	Node *Max = B1.FindMax(p1);
	Node *Min = B1.FindMin(p1);
	cout << "B1.FindMax=" << Max->GetKey() << " B1.FindMin=" << Min->GetKey() << endl;

	cout << endl << "				B2.FindKey				" << endl;
	int k;
	cout << "Enter k for FindKey " << endl;
	cin >> k;
	if (B2.FindKey(k, p2) != NULL)
		cout << "There is " << k << " in B2" << endl;
	else cout << "There is no " << k << " in B2" << endl;

	cout << endl << "				B1.Add 5,8				" << endl<<endl;
	B1.Add(5, p1);
	B1.Add(8, p1);
	B1.PrintTree(1, p1);
	SetConsoleTextAttribute(h, (0 << 4) + 15);

	cout << endl << "				B1.Del 5				" << endl<<endl;
	Node *Del = B1.FindKey(5,p1);
	B1.Del(Del);
	p1 = B1.GetRoot();
	B1.PrintTree(1, p1);
	SetConsoleTextAttribute(h, (0 << 4) + 15);

	cout << endl << "				B1.DelRoot				" << endl<<endl;
	B1.DelRoot();
	Node *p11;
	p11 = B1.GetRoot();
	B1.PrintTree(1, p11);

	cout << endl << endl;
	return 0;
}
