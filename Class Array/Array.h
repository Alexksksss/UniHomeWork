
class Arr {
	int*a;
	int n;
	
public:
	Arr();
	Arr(int n);
	Arr(int *b, int m);					//m -число эл-тов в массиве b

	
	Arr(const Arr &x);					//конструктор копирования
	Arr & operator = (const Arr &x);    //операция присвоения
	~Arr();								//деструктор

	void Scan(int m);				//ввод массива из m чисел
	void Print();					//вывод массива

	int & operator [] (int k);		//считывание элемента по позиции
	int FindKey(int key);			//поиск элемента key в массиве (возвращает индекс key или -1)
	
	Arr & operator += (int key);	 //добавляет key в конец массива a
	Arr operator + (int key);		//формирует массив b = a + key (в конец)
	Arr & operator += (Arr);		//добавление массива в конец массива a
	Arr operator + (Arr);			//формирует массив y=a+x
	Arr & operator -= (int key);	//удаление элемента key
	Arr operator - (int key);		//формирует новый массив b = a - key
	Arr & DelPosEq(int pos);		//удаление элемента с позиции pos
	Arr DelPosNew(int pos);			//формирует новый массив b, в котором удален элемент с позиции pos

	bool operator == (Arr); 		//проверка равенства массивов
	bool operator != (Arr);			//проверка неравенства массивов

	int Max();			//нахождение максимума в массиве, возвращает индекс максимального элемента
	int Min();   		// нахождение минимума в массиве
	void Sorting();		//сортировка массива

	friend ostream & operator << (ostream &r, Arr &x);
	friend istream & operator >> (istream &r, Arr &x);

private:
		void ShiftLeft(int pos);		 //сдвиг влево, начиная с позиции pos+1


};
