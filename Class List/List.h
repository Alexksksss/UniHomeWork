class List;

class Node
{
	int key;
	Node *prev, *next;

public:
	Node() { key = 0; prev = NULL; next = NULL; } 		//конструктор по умолчанию
	Node(int k, Node *pr, Node *nxt){
		key = k; prev = pr; next = nxt;
	}  		//конструктор с аргументами

//конструктор по умолчанию и конструктор с аргументом можно объединить:
 //  Node(int k=0, Node *pr=0, Node *nxt=0)
//			 {key=k; prev=pr; next=nxt;}   

	int &Key() { return key; }

	//Первый вариант :
	Node *& Prev() { return prev; }
	Node *& Next() { return next; }

//	Второй вариант(реализуем на уроке) :
	friend class List;

};

class List
{
	Node *head, *tail;

public:

	List();
	List(int n);  	    		//формирование списка из n случайных чисел
	List(int *a, int n);		//формирование списка из массива n чисел
	List(const List &s);         	//конструктор копирования
	~List();
	List & operator= (const List &s);

	void AddAfter(int x, Node *pr);   	//добавление узла после заданного
	void AddToTail(int x);      		//добавление элемента в хвост
	void AddToHead(int x);     		//добавление элемента в голову
	void AddToTail(List S);      		//добавление списка в хвост
	void AddToHead(List S);   		//добавление списка в голову

	void Del(Node *p);    			//удаление элемента по указателю p
	void DelTail();             			//удаление элемента с хвоста
	void DelHead();           			//удаление элемента с головы

	Node *FindKey(int key);    		//поиск в списке по ключу
	Node *FindPos(int pos);     		//поиск в списке по позиции

	bool Empty();               		//проверка пустоты списка
	bool NotEmpty();        	    		//проверка непустоты списка
	void Clear();               	    		//очистка списка

	bool operator == (List S);    		//проверка равенства списков
	bool operator != (List S);     		//проверка неравенства списков

	Node *Max();                     		//нахождение max эл-та списка
	Node *Min();                      		//нахождение min эл-та списка
	void Sort();         	    			//сортировка (методом прямой вставки)

	void Scan(int n);                 		//ввод списка из n элементов
	void Print();                        		//печать списка

	friend ostream & operator << (ostream &r, List &X);
	friend istream & operator >> (istream &r, List &X);

};
