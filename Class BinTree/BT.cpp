
Node* BinTree::Tree(int n, Node* p)
//построение идеально сбалансированного дерева
//с n вершинами, p - предок вершины дерева
{
	if (n == 0) return NULL;
	Node* q = new Node(rand() % 50);
	int nL, nR;
	nL = (n - 1) / 2; nR = n - 1 - nL;
	q->left = Tree(nL, q);
	q->right = Tree(nR, q);
	q->parent = p;
	return q;
}

BinTree::BinTree(int n)			//n - количество ключей, ключи случайны
{
	root = Tree(n, NULL);
}


BinTree::BinTree(int * a, int n)//я
{
	int i = 0;
	root = TreeMas(NULL, n, a, i);

}


Node * BinTree::TreeMas(Node * p, const int & n, const int * a, int & i)//я
{
	Node* q = new Node(a[i], p);
	int nL = (n - 1) / 2;
	int nR = n - 1 - nL;
	if (i < n) {
		if (nL)
		{
			++i;
			q->left = TreeMas(q, nL, a, i);
		}
		if (nR)
		{
			++i;
			q->right = TreeMas(q, nR, a, i);
		}
	}
	return q;
}

void BinTree::Copy(Node* q, Node* p, int f)
//копирование дерева с корнем q, p - узел, к которому 
//присоединяется копия
//f=0 - копируемое дерево будет левым потомком для p;
//f=1 - копируемое дерево будет правым потомком для p.
{
	if (q == NULL) return;
	Node* t = new Node(q->key);
	t->parent = p;
	if (f == 0) p->left = t;
	else p->right = t;
	Copy(q->left, t, 0);
	Copy(q->right, t, 1);
}


BinTree::BinTree(const BinTree& T)
{
	if (T.root == NULL) root = NULL;
	else {
		root = new Node(T.root->key);
		Copy(T.root->left, root, 0);
		Copy(T.root->right, root, 1);
	}
}

BinTree & BinTree::operator=(const BinTree &T)//я//----
{
	
	if (this == &T) {
		return *this;
	}
	Clear();
	delete root;
	if (T.root == NULL) {
		root = NULL;
	}
	else {
		root = new Node(T.root->key);
		//B.root = b;
		Copy(T.root->left, root, 0);
		Copy(T.root->right, root, 1);
	}
	return *this;


}

BinTree::~BinTree()//я
{
	Clear();
	delete root;
}

void BinTree::Clear()//я
{
	if (root == NULL) return;
	Node* q = root;
	while (root->left != NULL)	Del(root->left);
	while (root->right != NULL)	Del(root->right);
}

void BinTree::PrintTree(int k, Node* p)
//вывод дерева на консоль, 
//k - отступ от левой границы консоли
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (0 << 4) + 6);
	if (p == NULL) { 
		return;
	}
	PrintTree(k + 5, p->right);
	for (int i = 0; i < k; i++) cout << ' ';
	cout << p->key << endl;
	PrintTree(k + 5, p->left);
	
}

void BinTree::Add(int k, Node* p)
//добавление узла с ключом k в дерево с корнем p
{
	if (p->left == NULL)
	{
		Node* q = new Node(k);
		p->left = q;  q->parent = p;
		return;
	}
	if (p->right == NULL)
	{
		Node* q = new Node(k);
		p->right = q;  q->parent = p;
		//другой вариант:
		 //Node *q=new Node (k, NULL, NULL, p);
		 //p->right=q;
		return;
	}
	if (rand() % 2) Add(k, p->left);
	else Add(k, p->right);
}

void BinTree::Del(Node* p) 		//удаление узла p
{
	if (p == root) {
		DelRoot();
		return;
	}
	Node* q = p->parent;
	//удаление листа
	if (p->left == NULL && p->right == NULL)
	{
		if (q->left == p) q->left = NULL;
		else q->right = NULL;
		delete p;
		return;
	}
	//у p нет левой ветви
	if (p->left == NULL && p->right != NULL)
	{
		if (q->left == p) q->left = p->right;
		else q->right = p->right;
		p->right->parent = q;
		delete p;
		return;
	}
	//у p нет правой ветви
	if (p->left != NULL && p->right == NULL)
	{
		if (q->left == p) q->left = p->left;
		else q->right = p->left;
		p->left->parent = q;
		delete p;
		return;
	}

	//у p есть оба поддерева
	Node* t = p;
	while (t->left != NULL) t = t->left;

	//вырезаем t из дерева
	if (t->right == NULL)
		t->parent->left = NULL;
	else {
		t->parent->left = t->right;
		t->right->parent = t->parent;
	}
	//заменяем p узлом t
	t->left = p->left;
	t->right = p->right;
	t->parent = q;

	if (q->left == p) q->left = t;
	else q->right = t;

	if (p->left != NULL)
		p->left->parent = t;

	p->right->parent = t;
	delete p;
	return;
}

void BinTree::DelRoot()//я
{
	if (root == NULL) 
		return;
	if (root->left == NULL && root->right == NULL){
		delete root;
		root = NULL;
		return;
	}
	if (root->left == NULL && root->right != NULL){
		Node* q;
		q= root;
		root = q->right;
		root->right->parent = NULL;
		delete q;
		return;
	}
	if (root->left != NULL && root->right == NULL){
		Node* q;
		q= root;
		root = q->left;
		root->left->parent = NULL;
		delete q;
		return;
	}
	Node* t;
	t= root;
	while (t->left != NULL) t = t->left;

	if (t->right == NULL)
		t->parent->left = NULL;
	else {
		t->parent->left = t->right;
		t->right->parent = t->parent;
	}
	t->left = root->left;
	t->right = root->right;
	t->parent = NULL;

	if (root->left != NULL)
		root->left->parent = t;
	root->right->parent = t;
	delete root;
	root = t;
	return;
	
}
	

void BinTree::TreeTravelsalLCR(Node* p)
{

	if (p == NULL) return;
	TreeTravelsalLCR(p->left);
	cout << p->key << ", ";
	TreeTravelsalLCR(p->right);
}

void BinTree::TreeTravelsalCLR(Node * p)//я
{
	if (p == NULL) return;
	cout << p->key << ", ";
	TreeTravelsalCLR(p->left);
	TreeTravelsalCLR(p->right);
}

void BinTree::TreeTravelsalRCL(Node * p)//я
{
	if (p == NULL) return;
	TreeTravelsalRCL(p->right);
	cout << p->key << ", ";
	TreeTravelsalRCL(p->left);
}

void BinTree::WidthTravelSal(Node * p)
{
	if (p == NULL) return;
	for (int i = 0; i < FindHight(p); i++)
		ForWidth(p, i);
}

void BinTree::ForWidth(Node* p, int i)
{
	if (p == NULL) return;
	if (i == 0) cout << p->key << ", ";
	else if (i > 0)
	{
		ForWidth(p->left, i - 1);
		ForWidth(p->right, i - 1);
	}
}

Node* BinTree::FindKey(int k, Node* p)//я
{
	Node *tmp;
	if (p != NULL) {
		if (p->key == k) {
			return p;
		}
		if (p->left != NULL) {
			tmp = FindKey(k, p->left);
			if (tmp)
				return tmp;
		}
		if (p->right != NULL) {
			tmp = FindKey(k, p->right);
			if (tmp)
				return tmp;
		}	
	}
	return NULL;
}

Node* BinTree::FindMax(Node* p)//я
{
	if (p == NULL) return NULL;
	Node *max = p;
	Node *left = FindMax(p->left);
	Node * right = FindMax(p->right);
	if (left && left->key > max->key) max = left;
	if (right && right->key > max->key) max = right;
	return max;
}
Node* BinTree::FindMin(Node* p)//я
{
	if (p == NULL) return NULL;
	Node *min = p;
	Node *left = FindMin(p->left);
	Node *right = FindMin(p->right);
	if (left && left->key < min->key) min = left;
	if (right && right->key < min->key) min = right;
	return min;
}

int BinTree::FindHight(Node * p)//я
{
	if (p != NULL) {
		int l, r;
		l = FindHight(p->left);
		r = FindHight(p->right);
		if (l > r) return l + 1;
		else return r + 1;
	}
	return 0;
}

int BinTree::Count(Node * p)//я
{
		int l, r;
		if (p != NULL) {
			if (p->left == NULL && p->right == NULL)
				return 1;
			if (p->left != NULL)
				l = Count(p->left);
			else l = 0;
			if (p->right != NULL)
				r = Count(p->right);
			else r = 0;
			return l + r + 1;
		}
		else return 0;
}
