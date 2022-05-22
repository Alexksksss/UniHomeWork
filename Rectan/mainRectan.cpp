
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <array>
#include <stdio.h>
#include "Rectan.h"
using namespace std;

int main() {

	setlocale(LC_ALL, "russian");

	Rectan Q1,Q2,Q3,Q4,Q5,Q6,Q7,Q8;
	Q1.Input();
	cout<<"№1"<<endl; 
	Q1.Output();

	Q1.Sq();

	Q1.P();

	Q1.Circle();

	if (Q1.FourSquare(Q1) == true)	cout << "Q1-квадрат" << endl;
	else cout << "Q1- не квадрат" << endl;

	int c;
	cout << "Введите с- число, на которое умножится прямоугольник. с= ";
	cin >> c;
	Q2=Q1.Mult(Q1,c);
	cout<<"№2"<<endl;
	Q2.Output();

	cout << "Введите данные прямоугольников для проверки на равенство"<<endl;
	Q3.Input();
	cout<<"№3"<<endl;
	Q3.Output();
	Q4.Input();
	cout<<"№4"<<endl;
	Q4.Output();
	if (Q3.Equ(Q4) == true)	cout << "Q3=Q4" << endl;
	else cout << "Q3!=Q4" << endl;
	
	cout << "Введите данные прямоугольников для проверки на подобие" << endl;
	Q5.Input();
	cout<<"№5"<<endl;
	Q5.Output();
	Q6.Input();
	cout<<"№6"<<endl;
	Q6.Output();
	if (Q5.Similarity(Q6) == true)	cout << "Q5 подобен Q6" << endl;
	else cout << "Q5 не подобен Q6" << endl;

	Q6.CenterO();

	
	cout << "Введите данные прямоугольников для проверки на пересечение" << endl;
	Q7.Input();
	Q7.Output();
	Q8.Input();
	Q8.Output();
	if (Q7.Crossing(Q8) == true)	cout << "Q7 пересекает Q8" << endl;
	else cout << "Q7 не пересекает Q8" << endl;
	cout << endl;
	system("pause");
	return 0;
}
