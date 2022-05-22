
void OSBinTree::CreateMatrix(int * p, int * q, int n, int ** W, int ** C, int ** R)
{
	int i, j, t;
	for (i = 0; i < n + 1; i++)
		for (j = 0; j < n + 1; j++)
			W[i][j] = C[i][j] = R[i][j] = -1;

	//заполнение главной (t=0) диагонали в W и C
	for (i = 0; i < n + 1; i++)
		W[i][i] = C[i][i] = q[i];

	//заполнение первой (t=1) диагонали в W, C и R
	for (i = 0; i < n; i++)
	{
		j = i + 1;
		W[i][j] = W[i][i] + p[j] + q[j];
		C[i][j] = W[i][j] + C[i][i] + C[j][j];
		R[i][j] = j;
	}

	int min, k, k_min;
	//заполнение остальных (t=2,3,...,n) диагонали в W, C и R
	for (t = 2; t < n + 1; t++)
		for (i = 0; i < n + 1 - t; i++)
		{
			j = i + t;
			W[i][j] = W[i][j - 1] + p[j] + q[j];

			min = C[i][i] + C[i + 1][j]; k_min = i + 1;
			for (k = i + 2; k <= j; k++)
				if (C[i][k - 1] + C[k][j] < min)
				{
					min = C[i][k - 1] + C[k][j];
					k_min = k;
				}

			C[i][j] = W[i][j] + min;
			R[i][j] = k_min;

		}
}

Node * OSBinTree::OTree(int * d, int i, int j, int ** R, Node *p)
{
	if (i >= j) return NULL;
	int a = R[i][j];
	Node *q = new Node(d[a]);
	q->left = OTree(d, i, a - 1, R, q);
	q->right = OTree(d, a, j, R, q);
	q -> parent = p;
	return q;
}

OSBinTree::OSBinTree(int * d, int * p, int * q, int n)
{
	int **W;
	int **C;
	int **R;
	W = new int *[n + 1];
	C = new int *[n + 1];
	R = new int *[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		W[i] = new int[n + 1];
		C[i] = new int[n + 1];
		R[i] = new int[n + 1];
	}
	CreateMatrix(p, q, n, W, C, R);
	int i = 0, j = n;
	root = OTree(d, i, j, R, NULL);
}

OSBinTree::OSBinTree(const OSBinTree & T)
{
	if (T.root == NULL) root = NULL;
	else {
		root = new Node(T.root->key);
		Copy(T.root->left, root, 0);
		Copy(T.root->right, root, 1);
	}
}

OSBinTree & OSBinTree::operator=(const OSBinTree & T)
{
	this->BinTree:: operator=(T);
	return *this;
}
