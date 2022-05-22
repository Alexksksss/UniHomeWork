
class SBinTree : public BinTree
{
public:
	SBinTree() : BinTree() {};
	SBinTree(int n);//+
	//n - количество ключей, ключи случайны
	SBinTree(int *a, int n);//+
	//a - массив ключей, n - количество ключей
	SBinTree(const SBinTree&);//+
	SBinTree & operator= (const SBinTree&T);//+
	virtual ~SBinTree() { 
		//cout << "destructor works" << endl;
	};

	virtual void Add(int k, Node *p) override;//+
	//добавление узла с ключом k в дерево с корнем p
	virtual void Del(Node *p) override;//+ 		//удаление узла p
	virtual void DelRoot() override; 			//удаление корня

	virtual Node *FindKey(int k, Node *p) override;//+
	//поиск узла с ключом k в дереве с корнем p
	virtual Node *FindMax(Node *p) override;//+
	//поиск узла с max ключом в дереве с корнем p
	virtual Node *FindMin(Node *p) override;//+
	//поиск узла с min ключом в дереве с корнем p
};
