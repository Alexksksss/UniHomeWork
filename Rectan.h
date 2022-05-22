
class Rectan {
	int Ax, Ay, a, b;
public:
	Rectan();
	Rectan(int Ax,int Ay, int a, int b);

	void Input();//2) ввод / вывод;
	void Output();

	void Sq ();//3) нахождение площади;//int
	void P ();// 4) нахождение периметра;
	void Circle();//5) радиус описанной окружности;//float
	bool FourSquare(Rectan);// 6) проверка, является ли квадратом;
	Rectan Mult(Rectan,int c);// 7) умножение прямоугольника на число
	bool Equ (Rectan);// 8) проверка двух прямоугольников на равенство
	bool Similarity(Rectan);// 9) проверка двух прямоугольников на подобие
	void CenterO();//10)центр описанной окружности;
	bool Crossing(Rectan);// 11) проверка пересечения прямоугольников;
	//bool operatorRecCrossing(Rectan);//12*) нахождение прямоугольника пересечения;

};
