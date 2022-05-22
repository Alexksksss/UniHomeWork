
Lider::Lider()
{
	key = NULL;
	count = NULL;
	next = NULL;
	tr = NULL;
}

void Lider::AddTr(Lider * p)
{
	Trailer* T = new Trailer;
	T->ptr = p;
	T->next = tr;
	tr = T;
}

void Lider::DeleteTr(Lider * p)
{
	Trailer* T1, *T2 = p->tr;
	while (T2 != NULL) {
		T1 = T2;
		p->tr = T2->next;
		T2 = T2->next;
		delete T1;
	}
}

void Lider::PlusCount()
{
	if (tr != 0)
	{
		Trailer* T = tr;
		T->ptr->count++;
		while (T->next != 0){
			T = T->next;
			T->ptr->count++;
		}
		T->ptr->count++;
	}
}

void Lider::MinusCount()
{
	Trailer* T = tr;
	while (T != NULL) {
		T->ptr->count--;
		T = T->next;
	}
}

Graph::Graph()
{
	head = new Lider;
}

Graph::~Graph()
{
	Clear();
	delete head;//tail
}

Lider * Graph::FindKey(int k)
{
	Lider* L = head;
	int c = 0;
	if (!Empty())
	{
		for (L = L->next; L->key != k && L->next != NULL; L = L->next)
			c++;
		if (L->key != k)
			return 0;
		else
			return L;
	}
	else
		return 0;
}

void Graph::AddToHead(int k)
{
	Lider* L;
	L = new Lider;
	L->key = k;
	L->next = head->next;
	head->next = L;
}

void Graph::AddToTail(Lider * p)
{
	Lider* L = head;
	for (; L->next != NULL; L = L->next);
	L->next = p;
	p->next = 0;
}

Lider * Graph::FindCount(int k)
{
	int c = 0;
	Lider* L = head;
	if (!Empty())
	{
		for (L = L->next; L->count != k && L->next != NULL; L = L->next)
			c++;
		if (L->count != k)
			return 0;
		else
			return L;
	}
	else
		return 0;
}

void Graph::Del(Lider * p)
{
	if (p->tr != 0) 
		p->DeleteTr(p);
	Lider* L = head;
	while (L->next != p)
		L = L->next;
	if (p->next == NULL) 
		L->next = NULL;
	else
		L->next = p->next;
	delete p;
}

void Graph::Exlude(Lider * p)
{
	Lider* L = head;
	while (L->next != p)
		L = L->next;
	if (p->next == NULL)
		L->next = NULL;
	else
		L->next = p->next;
}

void Graph::Clear()
{
	while (!Empty())
		Del(head->next);
}

int Graph::FormGraph()
{
	int n = 0;
	int a, b;
	Lider* L1;
	Lider*L2;
	cout << "Enter 2 el: ";
	cin >> a >> b;
	while (a && b) {
		if (FindKey(a) == NULL) {
			AddToHead(a);
			L1 = head->next;
			n++;
		}
		else	L1 = FindKey(a);
		if (FindKey(b) == NULL) {
			AddToHead(b);
			L2 = head->next;
			n++;
		}
		else	L2 = FindKey(b);
		L2->count++;
		L1->AddTr(L2);
		cout << "enter 2 el: ";
		cin >> a >> b;
	}
	return n;
}

void Graph::SortGraph(Graph &L)
{
	Lider* L1, *L2;
	while (!Empty()){
		L1 = FindCount(0);
		if (L1 != NULL)
		{
			Exlude(L1);
			L.AddToTail(L1);
			L1->MinusCount();
		}
		else{
			cout << "Error in SortGraph";
			exit(-1);
		}
	}
	L2 = L.head->next;
	while (L2 != NULL){
		L2->PlusCount();
		L2 = L2->next;
	}
}

bool Graph::Empty()
{
	if(head->next!=NULL)
		return false;
	else return true;
}
