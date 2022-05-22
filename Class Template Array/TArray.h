template <class T> class Arr {
	T* a;
	int n;

public:
	Arr();
	Arr(int n);
	Arr(T *b, int m);					//m -число эл-тов в массиве b


	Arr(const Arr <T> &x);						//конструктор копирования
	Arr <T> & operator = (const Arr <T> &x);    //операция присвоения
	~Arr();										//деструктор

	void Scan(int m);				//ввод массива из m чисел
	void Print();					//вывод массива

	T & operator [] (int k);		//считывание элемента по позиции
	int FindKey(T key);			//поиск элемента key в массиве (возвращает индекс key или -1)

	Arr <T> & operator += (T key);		//добавляет key в конец массива a
	Arr <T> operator + (T key);			//формирует массив b = a + key (в конец)
	Arr <T> & operator += (Arr <T>);	//добавление массива в конец массива a
	Arr <T> operator + (Arr <T>);		//формирует массив y=a+x
	Arr <T> & operator -= (T key);		//удаление элемента key
	Arr <T> operator - (T key);			//формирует новый массив b = a - key

	Arr <T> & DelPosEq(int pos);		//удаление элемента с позиции pos
	Arr <T> DelPosNew(int pos);			//формирует новый массив b, в котором удален элемент с позиции pos

	bool operator == (Arr <T>); 		//проверка равенства массивов
	bool operator != (Arr <T>);			//проверка неравенства массивов

	int Max();			//нахождение максимума в массиве, возвращает индекс максимального элемента
	int Min();   		// нахождение минимума в массиве
	void Sorting();		//сортировка массива

	template <class T> friend ostream& operator << (ostream& r, Arr <T>& x);
	template <class T> friend istream& operator >> (istream& r, Arr <T>& x);

private:
	void ShiftLeft(int pos);		 //сдвиг влево, начиная с позиции pos+1
};

template <class T> Arr <T>::Arr()
{
	a = new T[1];
	n = 1;
}

template <class T> Arr <T>::Arr(int N)
{
	a = new T[N];
	n = N;
}

template <class T> Arr <T>::Arr(T* b, int m)
{
	a = new T[m];
	for (int i = 0; i < m; i++)
		a[i] = b[i];
	n = m;
}

template <class T> Arr <T>::Arr(const Arr<T>& x)
{
	n = x.n;
	a = new T[n];
	for (int i = 0; i < n; i++)
		a[i] = x.a[i];

}

template <class T> Arr<T>& Arr<T>::operator= (const Arr <T>& x) {
	if (this != &x)
	{
		delete[]a;
		n = x.n;
		a = new T[n];
		for (int i = 0; i < n; i++)
			a[i] = x.a[i];
	}
	return *this;
}

template <class T> Arr <T>:: ~Arr() {
	delete[]a;
}

template <class T> void Arr<T>::Scan(int m)
{
	cout << "enter " << m << " elements: ";
	if (n != m)
	{
		delete[]a;   n = m;
		a = new T[m];
	}
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

template <class T> void Arr<T>::Print()
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

template <class T> T& Arr<T>::operator[] (int i)
{
	if (i < 0) {
		cout << "incorrect index: i<0" << endl;
		return a[0];
	}
	if (i > n) {
		cout << "incorrect index: i>n" << endl;
		return a[n - 1];
	}
	return a[i];
}

template <class T> int Arr<T>::FindKey(T key)////t
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == key)	return i;
	}
	return -1;
}

template <class T> Arr <T>& Arr <T>::operator+= (T key)
{
	int i;
	T* t;
	t = new T[n + 1];
	for (i = 0; i < n; i++)  t[i] = a[i];
	t[n] = key;
	delete[]a;
	a = t;
	n++;
	return *this;
}

template <class T> Arr <T> Arr <T>::operator+ (T key)
{
	Arr Res(n + 1);
	for (int i = 0; i < n; i++)
		Res.a[i] = a[i];
	Res.a[n] = key;
	return Res;
}

template <class T> Arr <T>& Arr<T> ::operator+= (Arr  <T> b)
{
	T *t;
	t = new T[n + b.n];
	for (int i = 0; i < n; i++) t[i] = a[i];
	for (int i = n; i < n + b.n; i++) t[i] = b.a[i - n];
	delete[]a;
	a = t;
	n = n + b.n;
	return *this;
}

template <class T> Arr <T> Arr <T>::operator+ (Arr <T> b)
{
	Arr Res(n + b.n);
	for (int i = 0; i < n; i++)
		Res.a[i] = a[i];
	for (int i = n; i < n + b.n; i++)
		Res.a[i] = b.a[i - n];
	return Res;
}

template <class T> Arr <T>& Arr <T>:: operator-= (T key)
{
	int pos = FindKey(key);
	if (pos + 1) 	this->ShiftLeft(pos);
	else	cout << ("There is no key in Arr");
	return *this;
}

template <class T> Arr <T> Arr <T>::operator- (T key)
{
	Arr Res(n);
	for (int i = 0; i < n; i++) {
		Res.a[i] = a[i];
	}
	Res -= key;
	return Res;
}

template <class T> Arr <T>& Arr<T>::DelPosEq(int pos)
{
	try {
		if (pos < 0 || pos >= n) {
			throw ("Incorrect pos");
		}
		this->ShiftLeft(pos);
	}
	catch (char* s) {
		cout << "Error: " << s << "; Deleting first";
		this->ShiftLeft(0);
		return *this;
	}
	return *this;
}

template <class T> Arr <T> Arr <T>::DelPosNew(int pos)
{
	Arr Res(n);//=*this
	for (int i = 0; i < n; i++) {
		Res.a[i] = a[i];
	}
	try {
		if (pos < 0 || pos >= n) {
			throw ("Incorrect pos");
		}
		Res.ShiftLeft(pos);
	}
	catch (char* s) {
		cout << "Error: " << s << "; Deleting first";
		Res.ShiftLeft(0);
		return Res;
	}
	return Res;
}

template <class T> bool Arr<T>::operator== (Arr <T> b)
{
	int flag = 0;
	if (n == b.n) {
		for (int i = 0; i < n; i++) {
			if (a[i] != b.a[i]) flag = -1;
		}
	}
	else flag = -1;
	if (flag == 0) return true;
	else return false;
}

template <class T> bool Arr<T> ::operator!= (Arr <T> b)
{
	return !(*this == b);
}

template <class T> int Arr<T>::Max()
{
	int max = a[0], nmax = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
			nmax = i;
		}
	}
	return nmax;
}

template <class T> int Arr<T>::Min()
{
	int min = a[0], nmin = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
			nmin = i;
		}
	}
	return nmin;
}

template <class T> void Arr<T>::Sorting()
{
	T k;
	int t = n - 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < t - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				k = a[j + 1];
				a[j + 1] = a[j];
				a[j] = k;
			}
		}
}

template <class T> void Arr<T>::ShiftLeft(int pos)
{
	for (int i = pos; i < n - 1; i++) {
		a[i] = a[i + 1];
	}
	n--;
}


template <class T> ostream& operator<<(ostream& r, Arr<T>& x)
{
	for (int i = 0; i < x.n; i++) {
		cout << x.a[i] << " ";
	}
	cout << "\n";
	return r;
}

template <class T>  istream& operator >> (istream& r, Arr<T>& x)
{
	int m = 4;
	cout << "Enter " << m << " elements:";
	for (int i = 0; i < m; i++) {
		r >> x.a[i];
	}
	return r;

}
