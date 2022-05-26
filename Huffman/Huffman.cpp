
bool Code::Find(char ch, char p[])
{
	for (int i = 0; p[i]; i++)
		if (p[i] == ch)	return true;
	return false;
}

void Code::Copy(Node * q, Node * p, int f)
{
	if (q == NULL) return;
	Node *t = new Node(q->str, q->freq);
	if (f == 0) p->left = t;
	else p->right = t;
	Copy(q->left, t, 0);
	Copy(q->right, t, 1);
}

Code::Code(char p[])//c
{
	type = 0;
	//создание массива букв и их частот
	int i, TAB[256] = { 0 };
	for (i = 0; p[i]; i++)
		TAB[p[i]]++;

	//поиск 1-го (по ASCII) символа из p и создание головы списка
	char s[2]; s[1] = '\0';
	for (i = 0; i < 256 && TAB[i] == 0; i++);

	if (i == 256) { puts("string is empty"); head = NULL; return; }
	s[0] = i;
	head = new Node(s, TAB[i]);
	i++;

	//формирование упорядоченного по частоте линейного 
	//списка символов строки p
	for (; i < 256; i++)
		if (TAB[i] != 0)
		{
			s[0] = i;
			if (TAB[i] < head->freq) AddToHead(s, TAB[i]);
			else {
				Node *t = head;
				while (t->next && t->next->freq < TAB[i])
					t = t->next;
				if (t->next == NULL) AddToTail(s, TAB[i]);
				else AddAfter(t, s, TAB[i]);
			}
		}
}

Code::~Code()
{
	if (type == 0)	Clear();//список
	else
	{
		Node* q = head;
		while (q->left != NULL)	Clear(q, q->left);
		while (q->right != NULL)	Clear(q, q->right);
	}
	delete head;
}

Code::Code(const Code &X)
{
	Node *temp = X.head;
	while (temp->next != NULL){
		AddToTail(temp->str, temp->freq);
		temp = temp->next;
	}
}

Code & Code::operator=(const Code & X)
{
	if (this == &X)
		return *this;
	else {
		Clear();
		Node *temp = X.head;
		while (temp->next != NULL){
			AddToTail(temp->str, temp->freq);
			temp = temp->next;
		}
	}
	return *this;
}

void Code::AddToTail(char s[], int k)
{
	Node *temp = head;
	while (temp->next != NULL)	temp = temp->next;
	AddAfter(temp, s, k);
}

void Code::AddToTail(Node * p)
{
	Node *temp = head;
	while (temp->next != NULL)	temp = temp->next;
	temp->next = p;
}

void Code::AddToHead(char s[], int k)
{
	Node *temp = new Node(s, k, head);
	head = temp;
}

void Code::AddToHead(Node * p)
{
	p->next = head;
	head = p;
}

void Code::AddAfter(Node * pr, char s[], int k)
{
	Node *temp = new Node(s, k, pr->next);
	pr->next = temp;
}

void Code::AddAfter(Node * pr, Node * p)
{
	p->next = pr->next;
	pr->next = p;
}

void Code::DelHead()
{
	Node *temp = head;
	head = head->next;
	delete temp;
}

void Code::Clear()
{
	while (head != NULL)
		DelHead();//&
}

void Code::Clear(Node * pr, Node * t)
{	//удаление листа
	if (t->left == NULL && t->right == NULL)
	{
		if (pr->left == t) pr->left = NULL;
		else pr->right = NULL;
		delete t;
		return;
	}
	//у p нет левой ветви
	if (t->left == NULL)
	{
		if (pr->left == t) pr->left = t->right;
		else pr->right = t->right;
		delete t;
		return;
	}
	//у p нет правой ветви
	if (t->right == NULL)
	{
		if (pr->left == t) pr->left = t->left;
		else pr->right = t->left;
		delete t;
		return;
	}

	//у p есть оба поддерева
	Node *k = t->left, *p = t->left;
	if (k->right == NULL)
	{
		if (pr->left == t) pr->left = k;
		else pr->right = k;
		k->right = t->right;
	}
	else
	{
		while (k->right != NULL) k = k->right;
		while (p->right != k)p = p->right;
		p->right = k->left;
		k->left = t->left;
		k->right = t->right;
		if (pr->left == t)
			pr->left = k;
		else pr->right = k;
	}
	delete t;
	return;
}

bool Code::Empty()
{
	if (head == NULL)
		return true;
	else return false;
}

void Code::PrintList()
{
	for (Node* q = head; q; q = q->next)
		cout << q->str << "'" << q->freq << "'" << "  ";
	cout << endl;
}

void Code::PrintTree(int k, Node * p)
{
	if (p == NULL) return;
	PrintTree(k+15,p->right);
	for (int i = 0; i < k; i++) 
		cout << " ";
	cout << p->str << "'" << p->freq << "'" << endl;
	PrintTree( k + 15,p->left);
}

void Code::FormTree()//c	//преобразование списка в дерево
{
	if (head == NULL)
	{
		puts("list is empty"); return;
	}

	type = 1;
	Node *q, *p1, *p2, *t;
	int n1, n2, fr;
	char *s;

	while (head->next != 0)
	{//создание нового узла
		p1 = head;  p2 = head->next;
		n1 = strlen(p1->str); n2 = strlen(p2->str);
		s = new char[n1 + n2 + 1];
		strcpy_s(s, n1 + n2 + 1, p1->str);
		strcat_s(s, n1 + n2 + 1, p2->str);
		fr = p1->freq + p2->freq;
		q = new Node(s, fr, NULL, p1, p2);
		head = p2->next;
		delete[]s;

		//размещение q в списке;
		t = head;
		if (t == NULL) head = q;
		else {
			while (t->next && t->next->freq < fr)
				t = t->next;
			if (t->next == NULL) AddToTail(q);
			else AddAfter(t, q);
		}
	}
}

void Code::CodeText(char s[], char code[], int n)//c      //кодирование строки s
{
	if (type == 0) { puts("coding is impossible"); return; }

	//создание массива букв и их частот
	int i, TAB[256] = { 0 };
	for (i = 0; s[i]; i++)
		TAB[s[i]]++;

	//создание кодовой таблицы
	char CodeTAB[256][10];
	Node *t;
	for (i = 0; i < 256; i++)
		CodeTAB[i][0] = '\0';

	for (i = 0; i < 256; i++)
		if (TAB[i] != 0)
		{
			t = head;
				while (t->left || t->right)
					if (t->left && Find(i, t->left->str))
					{
						strcat_s(CodeTAB[i], 10, "0"); t = t->left;
					}
					else { strcat_s(CodeTAB[i], 10, "1"); t = t->right; }
		}

	//формирование закодированного текста:
	code[0] = '\0';
	for (i = 0; s[i]; i++)
		strcat_s(code, n, CodeTAB[s[i]]);
}

void Code::DecodeText(char code[], char s[], int n)
{
	s[0] = '\0';
	for (int i = 0; code[i]; )
	{
		Node *t = head;
		while (t->left || t->right)
		{
			if (code[i] == '0')	t = t->left;
			else t = t->right;
			i++;
		}
		strcat_s(s, n, t->str);
	}
}


