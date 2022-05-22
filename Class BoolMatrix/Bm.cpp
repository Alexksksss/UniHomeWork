
int BoolMatrix::Max(char ** s, int m)
{
	int max = strlen(s[0]);
	for (int i = 0; i < m; i++)
		if (strlen(s[i]) > max)
			max = strlen(s[i]);
	return max;
}

BoolMatrix::BoolMatrix()
{
	m = 1; n = 1;
	BM = new BoolVector[m];
	BoolVector B(1);
	BM[0] = B;
}

BoolMatrix::BoolMatrix(int m1, int n1)
{
	m = m1; n = n1;
	BM = new BoolVector[m];
	for (int i = 0; i < m; i++)
	{
		BoolVector B(n); 
		BM[i] = B;
	}
}

BoolMatrix::BoolMatrix(char **s, int m1)
{
	m = m1;
	n = Max(s, m1);
	BM = new BoolVector[m];
	for (int i = 0; i < m; i++)
		BM[i] = BoolVector(s[i], n);
}

BoolMatrix::BoolMatrix(const BoolMatrix &X)
{
	m = X.m;  n = X.n;
	BM = new BoolVector[m];
	for (int i = 0; i < m; i++)
		BM[i] = X.BM[i];
}

BoolMatrix & BoolMatrix::operator=(const BoolMatrix &B)
{
	if (this != &B)
	{
		if (m != B.m)
		{
			delete[]BM;
			m = B.m;
			BM = new BoolVector[m];
		}
		for (int i = 0; i < m; i++)
			BM[i] = B.BM[i];
		n = B.n;
	}
	return *this;
}

BoolMatrix::~BoolMatrix()
{
	delete[]BM;
}

void BoolMatrix::Scan(int a, int b)
{
	if (m != a)
	{
		delete[]BM;
		m = a;
		BM = new BoolVector[m];
	}
	for (int i = 0; i < a; i++)
	{
		BM[i].Scan(b);
		cout << endl;
	}
}

void BoolMatrix::Print()
{
	for (int i = 0; i < m; i++)
		cout << BM[i]<<" "<< endl;
}

BoolVector & BoolMatrix::operator[](int i)
{
	try
	{
		if (i < 0) throw 0;
		if (i >= m) throw "index >= m";
		return BM[i];
	}
	catch (int i)
	{
		cout << "index < 0" << endl;
		return BM[0];
	}
	catch (char* s)
	{
		cout << s << endl;
		return BM[m - 1];
	}
	catch (...)
	{
		cout << "incorrect index" << endl;
		exit(-1);
	}
}

bool BoolMatrix::operator==(BoolMatrix & B)
{
	if (m != B.m || n != B.n) return false;
	for (int i = 0; i < m; i++)
		if (BM[i] != B.BM[i]) return false;
	return true;
}

bool BoolMatrix::operator!=(BoolMatrix & B)
{
	if (*this == B) return false;
	else return true;
}

BoolMatrix BoolMatrix::SetUp1(int i, int j)
{
		if (i < 0 || i >= m)
			cout << "Error! Incorrect i";
		else if (j < 0 || j >= n)
			cout << "Error! Incorrect j";
		else BM[i] = BM[i].SetUp1(j);
		return *this;
}

BoolMatrix BoolMatrix::SetUp0(int i, int j)
{
	if (i < 0 || i >= m)
		cout << "Error! Incorrect i";
	else if (j < 0 || j >= n)
		cout << "Error! Incorrect j";
	else BM[i] = BM[i].SetUp0(j);
	return *this;
}

BoolMatrix BoolMatrix::Invert(int i, int j)
{
	if (i < 0 || i >= m)
		cout << "Error! Incorrect i";
	else if (j < 0 || j >= n)
		cout << "Error! Incorrect j";
	else BM[i] = BM[i].Invert(j);
	return *this;
}

BoolMatrix BoolMatrix::SetUp1(int i, int pos, int kol)
{
	BM[i].SetUp1(kol, pos);
	return *this;
}

BoolMatrix BoolMatrix::SetUp0(int i, int pos, int kol)
{
	BM[i].SetUp0(kol, pos);
	return *this;
}

BoolMatrix BoolMatrix::Invert(int i, int pos, int kol)
{
	BM[i].Invert(kol, pos);
	return *this;
}

BoolMatrix BoolMatrix::operator&(BoolMatrix & X)
{
	if (m != X.m)
	{
		cout << "Error";
		BoolMatrix res = *this;
		return res;
	}
	int n1 = n;
	if (n1 < X.n) n1 = X.n;
	BoolMatrix res(m, n1);
	for (int i = 0; i < m; i++)
		res.BM[i] = BM[i] & X.BM[i];
	return res;
}

BoolMatrix & BoolMatrix::operator&=(BoolMatrix & X)
{
	BoolMatrix res = (*this) & X;
	*this = res;
	return *this;
}

BoolMatrix BoolMatrix::operator|(BoolMatrix & X)
{
	if (m != X.m)
	{
		cout << "Error";
		BoolMatrix res = *this;
		return res;
	}
	int n1 = n;
	if (n1 < X.n) n1 = X.n;
	BoolMatrix res(m, n1);
	for (int i = 0; i < m; i++)
		res.BM[i] = BM[i] | X.BM[i];
	return res;
}

BoolMatrix & BoolMatrix::operator|=(BoolMatrix & X)
{
	BoolMatrix res = (*this) & X;
	*this = res;
	return *this;
}

BoolMatrix BoolMatrix::operator^(BoolMatrix & X)
{
	if (m != X.m)
	{
		cout << "Error";
		BoolMatrix res = *this;
		return res;
	}
	int n1 = n;
	if (n1 < X.n) n1 = X.n;
	BoolMatrix res(m, n1);
	for (int i = 0; i < m; i++)
		res.BM[i] = BM[i] ^ X.BM[i];
	return res;
}

BoolMatrix & BoolMatrix::operator^=(BoolMatrix & X)
{
	BoolMatrix res = (*this) & X;
	*this = res;
	return *this;
}

BoolMatrix BoolMatrix::operator~()
{
	for (int i = 0; i < m; i++)
		~BM[i];
	return *this;
}

BoolMatrix BoolMatrix::ShiftRight(int i, int k)
{
	BoolMatrix Res = *this;
	Res.BM[i] >>= k;
	return Res;
}

BoolMatrix BoolMatrix::ShiftLeft(int i, int k)
{
	BoolMatrix Res = *this;
	Res.BM[i] <<= k;
	return Res;
}

BoolMatrix & BoolMatrix::ShiftRightEq(int i, int k)
{
	BM[i] >>= k;
	return *this;
}

BoolMatrix & BoolMatrix::ShiftLeftEq(int i, int k)
{
	BM[i] <<= k;
	return *this;
}

BoolVector BoolMatrix::Conj()
{
	BoolVector BV1 = BM[0];
	for (int i = 1; i < m; i++)
		BV1 &= BM[i];
	return BV1;
}

BoolVector BoolMatrix::Disj()
{
	BoolVector BV1(n);
	for (int i = 0; i < m; i++)
		BV1 |= BM[i];
	return BV1;
}



BoolVector BoolMatrix::Xor()
{
	BoolVector BV1(n);
	for (int i = 0; i < m; i++)
		BV1 ^= BM[i];
	return BV1;
}
ostream & operator<<(ostream & r, BoolMatrix & x)
{
	x.Print();
	return r;
}

istream & operator>>(istream & r, BoolMatrix & x)
{
	x.Scan(x.m, x.n);
	return r;
}
