
SBinTree::SBinTree(int n)		//n - количество ключей, ключи случайны
{
	if (n == 0) root = NULL;
	else {
		root = new Node(rand() % 50);
		for (int i = 1; i < n; i++)	Add(rand() % 50, root);

	}
}

SBinTree::SBinTree(int * a, int n)//i
{
	if (n == 0) root = NULL;
	else {
		root = new Node(a[0]);
		  for (int i = 1; i < n; i++)	Add(a[i], root);
	}
}

SBinTree::SBinTree(const SBinTree &T)
{
	if (T.root == NULL) root = NULL;
	else {
		root = new Node(T.root->key);
			Copy(T.root->left, root, 0);
		Copy(T.root->right, root, 1);
	}
}

SBinTree & SBinTree::operator=(const SBinTree &T)//i
{
	
	this->BinTree:: operator=(T);
	//Clear();
	//delete root;
	//if (T.root == NULL) 
	//	root = NULL;
	//else {
	//	root = new Node(T.root->key);
	//	//B.root = b;
	//	Copy(T.root->left, root, 0);
	//	Copy(T.root->right, root, 1);
	//}
	return *this;
}


void SBinTree::Add(int k, Node *p)
//добавление узла с ключом k в дерево с корнем p
{
	Node *q;
	if (k < p->key)
		if (p->left == NULL)
		{
			q = new Node(k);
			p->left = q;
			q->parent = p;
		}
		else Add(k, p->left);
	else if (p->right == NULL)
	{
		q = new Node(k);
		p->right = q;
		q->parent = p;
	}
	else Add(k, p->right);
}

void SBinTree::Del(Node *p)  		//удаление узла p
{
	if (p == root) { DelRoot(); return; }
	Node *q = p->parent;
	//удаление листа
	if (p->left == NULL && p->right == NULL)
	{
		if (q->left == p) q->left = NULL;
		else q->right = NULL;
		delete p;
		return;
	}

	//у p нет левой ветви
	if (p->left == NULL)
	{
		if (q->left == p) q->left = p->right;
		else q->right = p->right;
		p->right->parent = q;
		delete p;
		return;
	}

	//у p нет правой ветви
	if (p->right == NULL)
	{
		if (q->left == p) q->left = p->left;
		else q->right = p->left;
		p->left->parent = q;
		delete p;
		return;
	}

	//у p есть оба поддерева
	Node *t = p->left;
	if (t->right == NULL)
	{
		t->parent = q;
		if (q->left == p) q->left = t;
		else q->right = t;
		t->right = p->right;
		p->right->parent = t;
	}
	else
	{
		while (t->right != NULL) t = t->right;
		t->parent->right = t->left;
		if (t->left != NULL)
			t->left->parent = t->parent;

		t->left = p->left;
		t->right = p->right;
		p->left->parent = t;
		p->right->parent = t;

		t->parent = q;
		if (q->left == p) q->left = t;
		else q->right = t;
	}

	delete p;
	return;
	
}
	

void SBinTree::DelRoot()
{
	if (root == NULL)
		return;

	if (root->left == NULL && root->right == NULL) {
		delete root;
		root = NULL;
		return;
	}
	if (root->left == NULL && root->right != NULL) {
		Node* q;
		q = root;
		root = q->right;
		root->parent = NULL;
		delete q;
		return;
	}
	if (root->left != NULL && root->right == NULL) {
		Node* q;
		q = root;
		root = q->left;
		root->parent = NULL;
		delete q;
		return;
	}
	Node* t, *q;
	if (root->left != NULL) {
		t = root->left;
	}
	else return;
	q = root;
	if (t->right == NULL) {
		t->parent = NULL;
		t->right = root->right;
		root->right->parent = t;
		root = t;
		delete q;
	}
	else {
		while (t->right != NULL)
			t = t->right;
		t->parent->right = t->left;
		if (t->left != NULL) {
			t->left->parent = t->parent;
		}
		t->left = root->left;
		t->right = root->right;
		root->left->parent = t;
		root->right->parent = t;
		t->parent = NULL;
		root = t;
		delete q;
	}
	return;
}

Node * SBinTree::FindKey(int k, Node * p)//i
{
	Node *tmp;
	tmp = p;
	if (p != NULL && p->key == k)
		return p;
	while(TRUE)
	{
		if (k > tmp->key) {
			if (tmp->right != NULL) {
				tmp = tmp->right;
					if (tmp->key == k)
						return tmp;
			}
			else return NULL;
		}
		else {
			if (tmp->left != NULL) {
				tmp = tmp->left;
				if (tmp->key == k)
					return tmp;
			}
			else return NULL;
		}
	}

}

Node * SBinTree::FindMax(Node * p)//i
{
	Node *tmp;
	tmp = p;
	while (tmp->right != NULL) {
		tmp = tmp->right;
	}
	return tmp;
}

Node * SBinTree::FindMin(Node * p)//i
{
	Node *tmp;
	tmp = p;
	while (tmp->left != NULL) {
		tmp = tmp->left;
	}
	return tmp;
}
