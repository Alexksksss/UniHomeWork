class OSBinTree : public SBinTree
{
private:
	void CreateMatrix(int *p, int *q, int n, int **W, int **C, int **R);
	//n -- количество ключей -> размер массивов n+1

	Node *OTree(int *d, int i, int j, int **R, Node *p);

public:
	OSBinTree() : SBinTree() {};
	OSBinTree(int *d, int *p, int *q, int n);//+
	OSBinTree(const OSBinTree & T);//+
	OSBinTree & operator= (const OSBinTree & T);//+
	virtual ~OSBinTree() {};
};
