
List::List()
{
	head = new Node;
	tail = new Node(0, head, NULL);
	head->next = tail;//1
}

List::List(int n)
{
	head = new Node;
	tail = new Node(0, head, 0);
	head->next = tail;//2
	int x;
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		x = rand() % 100; 
		AddToTail(x);
	}
}

List::List(int * a, int n)
{
	head = new Node;
	tail = new Node(-1, head, NULL);
	head->next = tail;
	for (int i = 0; i < n; i++)
		AddToTail(a[i]);
}

List::List(const List & s)
{
	head = new Node;
	tail = new Node(0, head, 0);
	head->next = tail;
	Node* t = s.head->next;
	while (t != s.tail)
	{
		AddToTail(t->key);
		t = t->next;
	}
}

List::~List()
{
	Clear();
	delete head;
	delete tail;
}

List & List::operator=(const List & x)
{
	if (this != &x)
	{
		Clear();
		Node* s = x.head->next;
		while (s != x.tail)
		{
			AddToTail(s->key);
			s = s->next;
		}
	}
	return *this;
}

void List::AddAfter(int x, Node * pr)
{
	Node* q = new Node(x, pr, pr->next);
	pr->next = q;
	q->next->prev = q;
}

void List::AddToTail(int x)
{
	AddAfter(x, tail->prev);
}

void List::AddToHead(int x)
{
	AddAfter(x, head);
}

void List::AddToTail(List S)
{
	Node* q = S.head->next;
	while (q != S.tail)
	{
		AddToTail(q->key);
		q = q->next;
	}
}

void List::AddToHead(List S)
{
	Node* q = S.tail->prev;
	while (q != S.head)
	{
		AddToHead(q->key);
		q = q->prev;
	}
}

void List::Del(Node * p)
{
	Node* p1 = p->prev;
	Node* p2 = p->next;
	p1->next = p2;
	p2->prev = p1;
	delete p;
}

void List::DelTail()
{
	Del(tail->prev);
}

void List::DelHead()
{
	Del(head->next);
}

Node * List::FindKey(int key)
{
	Node* q = this->head->next;
	while (q != this->tail) {
		if (q->key == key) {
			return q;
		}
		q = q->next;
	}
	cout << "There is no key ("<<key<<") in List" << endl;
	return 0;
}

Node * List::FindPos(int pos)
{
	Node *q = this->head->next;
	int i = 0;
	while (q != this->tail && i < pos)
	{
		i++; q = q->next;
	}

	if (q == tail) {
		cout << "Error out of list" << endl;
		return 0;
	}
		if (i == pos) 
			return q;//
}

bool List::Empty()
{
	if (this->head->next == this->tail) {
		return true;
	}
	return false;
}

bool List::NotEmpty()
{
	if (this->head->next != this->tail) {
		return true;
	}
	return false;
}

void List::Clear()
{
	while (tail->prev != head)	DelTail();
}

bool List::operator==(List S)
{
	Node* q1 = this->head->next, *q2 = S.head->next;
	if (q1 == this->tail && q2 == S.tail) return true;

	while (q1 != this->tail && q2 != S.tail) {
		if (q1->key != q2->key)
			return false;
		q1 = q2->next;
		q2 = q2->next;
	}
	if (q1 == this->tail && q2 == S.tail) 
		return true;

	return false;
}

bool List::operator!=(List S)
{
	if (*this == S) 
		return false;
	return true;
}

Node * List::Max()
{
	Node *Max = NULL;
	Node *q = head->next;
	if (Empty()==true) {
		cout << "List is empty" << endl;
		return Max;
	}
	Max = q;
	q = q->next;
	while (q != tail) {
		if (q->key > Max->key) {
			Max = q;
		}
		q = q->next;
	}
	return Max;
}

Node * List::Min()
{
	Node *Min = NULL;
	Node *q = head->next;
	if (Empty()==true) {
		cout << "List is empty" << endl;
		return Min;
	}
	Min = q;
	q = q->next;
	while (q != tail) {
		if (q->key < Min->key) {
			Min = q;
		}
		q = q->next;
	}
	return Min;
}

void List::Sort()
{
	List Temp;
	Node * M;
	while (this->NotEmpty()) {//Sorting
		M = Max();
		Temp.AddToHead(M->key);
		Del(M);
	}
	*this = Temp;
}

void List::Scan(int n)
{
	Clear();
	int i, x;
	cout << "Enter List: ";
	for (i = 0; i < n; i++)
	{
		cin >> x;
		AddToTail(x);
	}
}

void List::Print()
{
	Node* p = head->next;
	if (Empty())
		cout << " IS Empty"<<endl;
	while (p != tail)
	{
		cout << p->key << " ";
		p = p->next;
	}
}

ostream & operator<<(ostream & r, List & X)
{
	X.Print();
	return r;
}
istream & operator>>(istream & r, List & X)
{
	int n; 
	cout << "Enter n: ";
	cin >> n;
	X.Scan(n);
	return r;
}
