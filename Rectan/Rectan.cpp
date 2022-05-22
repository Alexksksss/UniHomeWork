
Rectan::Rectan() {
	Ax = 0; Ay = 0; a = 1; b = 1;
}
Rectan::Rectan(int AX, int AY, int aa, int bb)
{
	Ax = AX;
	Ay = AY;
	a = aa;
	b = bb;
}
void Rectan::Input()
{
	cout << "Введите Ax,Ay:  ";
	cin >> Ax>>Ay;
	cout << "Введите a,b:  ";
	cin >> a >>b;
}

void Rectan::Output()
{
	cout << "Ширина(x) прямоугольника= " << a << endl;
	cout << "Длина(y) прямоугольника= " << b << endl;
	cout << "Координата точки А= (" << Ax<<";"<<Ay<<") " << endl;

}

void Rectan::Sq()// площадь
{
	cout << "Площадь прямоугольника= " <<  a * b << endl;
}

void Rectan::P()//периметр
{
	cout << "Периметр прямоугольника= " << 2 * (a+b) << endl;
}

void Rectan::Circle()//радиус опис окр
{
	cout << "Радиус описанной около прямоугольника окружности= " << sqrt(a*a + b * b) / 2 << endl;
}

bool Rectan::FourSquare(Rectan Q)//является ли квадратом
{
	if (a == b)  return true; 
	else return false;
}

Rectan Rectan::Mult(Rectan Q,int c)//умножение на число
{
	a = a * c;
	b = b * c;
	return *this;
}

bool Rectan::Equ(Rectan Q)//проверка двуХ на равенство
{
	if (a == Q.a&&b == Q.b) return true;
	else return false;
}

bool Rectan::Similarity(Rectan Q)// проверка на подобие
{
	if ((a / Q.a==b / Q.b) || (a / Q.b==b / Q.a)) return true;
	else return false;
}

void Rectan::CenterO()//центр опис окруж
{
	cout << "Центр описанной окружности= (" << Ax+ (a / 2)<<";"<< Ay+(b / 2)<<")"<<endl;
}

bool Rectan::Crossing(Rectan Q)//пересечение
{
	if ((Q.Ax < Ax + a && Ax + a < Q.Ax + Q.a && Ay < Q.Ay && Q.Ay < Ay + b) || (Ax < Q.Ax && Q.Ax < Ax + a && Q.Ay < Ay && Ay < Q.Ay + Q.b) || (Q.Ax < Ax && Ax < Q.Ax + Q.a&&Ax < Q.Ay && Q.Ay < Ay + b) || (Q.Ax < Ax && Ax < Q.Ax + Q.a && Q.Ay < Ay && Ay < Q.Ay + Q.b)) 
	//if((Ax+a>Q.Ax && Ay+b>Q.Ay)||( Ax<Q.Ax + Q.a && Ay < Q.Ay + Q.b)||( Ax<Q.Ax+Q.a && Ay+b>Q.Ay)||(Ax+a>Q.Ax && Ay<Q.Ay+Q.b))
	return true;
	else return false;
}
