
#include <locale.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include "BT.h"

using namespace std;


int main()
{
	srand(time(0));
	int k;
	Node *p;
	BinTree B1(10);
	p = B1.GetRoot();
	cout << "				B1 Print				" << endl;
	B1.PrintTree(1, p);
	cout << endl;
	
	cout << "				B1 FindKey				" << endl;
	Node *p1;
	p1 = p;
	cout << "Enter k for FindKey" << endl;
	cin >> k;
	if (B1.FindKey(k, p1)!=NULL)
		cout << "There is "<<k<<" in B1"<<endl;
	else cout << "There is no " << k << " in B1"<<endl;

	cout << "				B1 Max,Min				" << endl;
	Node *qmax=B1.FindMax(p);
	cout <<"B1 max= " <<qmax->GetKey()<<endl;
	Node *qmin = B1.FindMin(p);
	cout << "B1 min= " << qmin->GetKey() << endl;

	cout << "				B1 FindHeight				" << endl;
	cout<<"Height of B1 is "<<B1.FindHight(p)<<endl;

	cout << "				B1 Count				" << endl;
	cout << "Count  is " << B1.Count(p) << endl;
	
	cout << "				B1 left root right				" << endl;
	B1.TreeTravelsalLCR(p);
	cout << endl;

	cout << "				B1 root left right				" << endl;
	B1.TreeTravelsalCLR(p);
	cout << endl;

	cout << "				B1 right root left				" << endl;
	B1.TreeTravelsalRCL(p);
	cout << endl;

	cout << "				B1 Width				" << endl;
	B1.WidthTravelSal(p);
	cout << endl;

	cout << "				B1 = B2				" << endl;
	BinTree B2 = B1;//конструктор
	Node *p2 = B2.GetRoot();
	B2.PrintTree(1, p2);

	cout << "				B1=B2				" << endl;
	BinTree B4;
	B4 = B1;
	Node*p4 = B4.GetRoot();
	B4.PrintTree(1,p4);

	cout << "				B1.Clear				" << endl;
	B1.Clear();
	B1.PrintTree(1, p);

	cout << "				B3				" << endl;
	BinTree B3(10);
	Node *p3;
	p3=B3.GetRoot();
	B3.PrintTree(1, p3);
	cout << "				B3.DelRoot				" << endl;
	B3.DelRoot();
	Node *p33;
	p33 = B3.GetRoot();
	B3.PrintTree(1, p33);

	cout << endl;
	cout << "				B1.Add				" << endl;
	p = B1.GetRoot();
	B1.Add(5, p);
	B1.Add(8, p);
	B1.PrintTree(1, p);

	cout << "				B1.Del				" << endl;
	cout << "Enter k for deleting" << endl;
	int kdel;
	cin >> kdel;
	cout << endl;
	Node *pdel = B1.FindKey(kdel, p);
	if (pdel != NULL) {
		B1.Del(pdel);
	}
	else cout << "There is no such key in a tree" << endl;
	B1.PrintTree(1, p);

	cout << endl << endl;
	return 0;
}
