
class BoolMatrix
{
	BoolVector *BM;
	int m, n;                      	//m – кол-во строк матрицы
										   //n – кол-во столбцов матрицы

	//вспомогательная функция, нужна в конструкторе
	int Max(char **s, int m);

public:
	//конструктры, деструктор, оператор присвоения
	BoolMatrix();
	BoolMatrix(int, int);
	BoolMatrix(char **, int);
	BoolMatrix(const BoolMatrix &);
	BoolMatrix & operator= (const BoolMatrix &);
	~BoolMatrix();

	void Scan(int, int);             	//ввод, вывод
	void Print();

	BoolVector  & operator[] (int );
	bool operator== (BoolMatrix &);
	bool operator!= (BoolMatrix &);

	//Изменение одной или нескольких компонент матрицы
	BoolMatrix SetUp1(int, int);   		//установить в 1  [i][j] элемент
	BoolMatrix SetUp0(int, int);   		//сбросить в 0  [i][j] элемент
	BoolMatrix Invert(int, int); 			//инвертировать [i][j] элемент
	BoolMatrix SetUp1(int i, int pos, int kol);
	//установить kol элементов матрицы в i-й строке, начиная с pos
	BoolMatrix SetUp0(int i, int pos, int kol);
	//сбросить kol элементов матрицы в i-й строке, начиная с pos
	BoolMatrix Invert(int i, int pos, int kol);
	//инвертировать kol элементов матрицы в i-й строке, начиная с pos

	BoolMatrix operator &(BoolMatrix &X);
	//построчная конъюнкция матриц, создается новая матрица
	BoolMatrix & operator &=(BoolMatrix &X);
	//построчная конъюнкция матриц, изменяется *this 
	BoolMatrix operator |(BoolMatrix &X);
	//построчная дизъюнкция матриц, создается новая матрица
	BoolMatrix & operator |=(BoolMatrix &X);
	//построчная дизъюнкция матриц, изменяется *this 
	BoolMatrix operator ^(BoolMatrix &X);
	//построчная XOR матриц, создается новая матрица
	BoolMatrix & operator ^=(BoolMatrix &X);
	//построчная XOR матриц, изменяется *this 
	BoolMatrix operator ~();                	//инверсия всей матрицы

	BoolMatrix ShiftRight(int i, int k);
	//сдвиг вправо эл-тов i-й строки на k, создается новая матрица
	BoolMatrix ShiftLeft(int i, int k);
	//сдвиг влево эл-тов i-й строки на k, создается новая матрица
	BoolMatrix & ShiftRightEq(int i, int k);
	//сдвиг вправо эл-тов i-й строки на k, изменяется матрица *this
	BoolMatrix & ShiftLeftEq(int i, int k);
	//сдвиг влево эл-тов i-й строки на k, изменяется матрица *this


	BoolVector Conj();   	    	//конъюнкция всех строк матрицы(and)
	BoolVector Disj();         	//дизъюнкция всех строк матрицы(or)
	BoolVector Xor();		    	//Xor всех строк матрицы

	friend ostream & operator << (ostream &r, BoolMatrix &x);
	friend istream & operator >> (istream &r, BoolMatrix &x);
}
