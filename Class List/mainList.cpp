
#include <locale.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include "library-litvak.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "					Task1					" << endl;
	List S1;
	S1.AddToHead(1);
	S1.AddToTail(10);
	cout << "S1= ";
	S1.Print();
	cout << endl;

	cout << "					Task2					" << endl;
	List S2(6);
	cout << endl;
	cout << "S2= " << S2<<endl;
	Node *Max, *min;
	Max = S2.Max();
	min = S2.Min();
	int x = min->Key();
	cout << "Max= " << Max->Key()<<endl;
	cout << "Min= " << min->Key()<<endl;
	

	//while (S2.NotEmpty()) {//Sorting
		//Node*Max;
		//Max = S2.Max();
		//int x;
		//x = Max->Key();
		//S2New.AddToHead(x);
	//	S2.Del(Max);
	//}
	
	S2.Sort();
	//S2 = S2New.Sort(S2);
	cout << "S2=" << S2 <<endl;
	//cout << "S2New=" << S2New<<endl;

	cout << "					Task3					" << endl;
	if (S2.FindPos(2) != 0) {
		cout << "S2.FindPos(2)=" << S2.FindPos(2)->Key() << endl;
		S2.Del(S2.FindPos(2));
	}
	cout << "S2=" << S2 << endl;

	cout << "					Task4					" << endl;
	if (S2.FindPos(6) != 0) {
		cout << "S2.FindPos(6)=" << S2.FindPos(6)->Key() << endl;
	}
	else
		cout << "In List less than 6 el" << endl;
	S2.DelTail();
	cout << "S2.DelTail()=" << S2 << endl;

	cout << "					Task5					" << endl;
	List S3;
	S3 = S1;
	cout << "S3=" << S3 << endl;
	if (S1 != S3)	cout << "S1=S3" << endl;
	else cout << "S1!=S3" << endl;
	if ((S3.FindKey(15)) != 0)//Случай, когда нет вхождения рассмотрен в функции
		cout << "There is 15 in S3" << endl;

	cout << "					Task6					" << endl;
	S3.DelHead();
	S3.Del(S3.FindKey(10));
	cout << "S3=" << S3 << endl;// проверка на пустоту уже заложена в функции, но функции работают
	//if (S3.Empty())
	//	cout << "S3 is empty" << endl;
	//if (S3.NotEmpty())
	//	cout << "S3 not empty" << endl;

	cout << "					Task7					" << endl;
	int arr7[6];
	RandMas(arr7, 6, 1, 20);
	cout << "Array from task 7=";
	PrintMas(arr7, 6);
	cout << endl;
	List S4(arr7, 6);
	cout << "S4=" << S4 << endl;
	if (S4.FindKey(25))//проверка на обратное условие в функции
		cout << "There is 25 in S4" << endl;
	Node *temp;
	temp = S4.FindPos(4-1);
	S4.AddAfter(25, temp);
	cout << "S4=" << S4 << endl;
	cout << "					Task8					" << endl;
	List S5(S2);
	cout << "S5=" << S5 << endl;
	if (S5.FindKey(4)) {
		cout << "There is 4 in S5"<< endl;
		S5.Del(S5.FindKey(4));
	}
	else S5.AddToTail(4);
	cout << "S5=" << S5 << endl;

	cout << "					Task9					" << endl;
	S5.Clear();
	cout << "Enter numbers for S5" << endl;
	cin >> S5;
	if (S4 != S5)	cout << "S4!=S5" << endl;
	else cout << "S4=S5" << endl;

	cout << "					Task10					" << endl;
	S5.AddToTail(S4);
	S5.AddToHead(S1);
	cout << "S5=" << S5 << endl;
	cout << endl << endl;
	return 0;
}
