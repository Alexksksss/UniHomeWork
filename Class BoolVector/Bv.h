typedef unsigned char UC;

class BoolVector
{
	protected:
	UC *bv;
	int n, m;		   //n -длина булева вектора,
				   	   //m - количество элементов в массиве bv
					   //связь n и m: m=n/8 если n%8=0;
					   // m=n/8+1, если n%8!=0

	int Input( const char *, int , int , int );		//формирование элемента массива bv
	void Output(int, int);                   		 //вывод элемента массива bv

public:

	//конструкторы, деструктор, перегрузка оператора присвоения
	BoolVector();
	BoolVector(int n1);          			//n1 - длина булева вектора
	BoolVector(const char *s);
	BoolVector( const char *s, int n);			//strlen(s)!=n
	BoolVector(const BoolVector &);
	BoolVector operator= (const BoolVector &);
	virtual ~BoolVector() { delete[]bv; }

	//ввод, вывод, вес, определение k-й компоненты
	virtual void Scan(int);
	virtual void Print();
	int Weight();
	UC operator[] (int);

	//сравнение
	bool operator== (BoolVector &);
	bool operator!= (BoolVector &);
	bool operator< (BoolVector &y);   	//x<y если x[i]<=y[i]
	bool operator> (BoolVector &y);		 //x>y если x[i]>=y[i]

   //побитовые операции
	BoolVector operator & (BoolVector &x);		//создается новый вектор and
	BoolVector & operator &=(BoolVector &x);		//изменяется *this
	BoolVector operator |(BoolVector &x);			//создается новый вектор or
	BoolVector & operator |=(BoolVector &x);		//изменяется *this
	BoolVector operator ^(BoolVector &x);			//создается новый вектор xor
	BoolVector & operator ^=(BoolVector &x);		//изменяется *this
	BoolVector operator ~();						//изменяется *thi not
	BoolVector operator <<(int);					//создается новый вектор
	BoolVector  & operator <<=(int);				//изменяется *this
	BoolVector operator >>(int);					//создается новый вектор
	BoolVector operator >>=(int);				//изменяется *this


	//Изменение одной компоненты вектора
	BoolVector SetUp1(int pos);        	//установить в 1 компоненту pos
	BoolVector SetUp0(int pos);        	//сбросить в 0 компоненту pos
	BoolVector Invert(int pos);           	//инвертировать компоненту pos

	//Изменение нескольких компонент вектора
	BoolVector SetUp1(int kol, int pos);
	//установить kol компонент начиная с позиции pos, изменяется *this
	BoolVector SetUp0(int kol, int pos);
	//сбросить  kol компонент начиная с позиции pos, изменяется *this
	BoolVector Invert(int kol, int pos);
	//инвертировать kol компонент начиная с позиции pos, изменяется *this

	friend ostream & operator<< (ostream &r, BoolVector &V);
	friend istream & operator>> (istream &r, BoolVector &V);

}
