
#include <iostream>
using namespace std;

struct Trailer;
struct Lider {

	int key, count;
	Lider * next;
	Trailer *tr;

	Lider();
	
	void AddTr(Lider*p);
	void DeleteTr(Lider*p);
	void PlusCount();
	void MinusCount();


};
struct Trailer {
	Lider *ptr;
	Trailer *next;
	Trailer() { ptr = NULL; next = NULL; }
};
struct Graph {

	Lider *head;
	Graph();
	~Graph();

	Lider *FindKey(int k);
	void AddToHead(int k);
	void AddToTail(Lider *p);

	Lider* FindCount(int k);//finding node which count ==k
	void Del(Lider *p);//удаление узла for Clear For destructor
	void Exlude(Lider *p);//исключение узла из списка без удаления
	void Clear();

	int FormGraph();//формирование  //1
	void SortGraph(Graph &);   //2
	bool Empty();
};
