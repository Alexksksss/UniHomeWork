
BoolVector::BoolVector()
{
	n = 1;
	bv = new UC[n];
	bv[0] = 0;
}

BoolVector::BoolVector(int n1)
{
	m = n1 / 8; int k = n1 % 8;
	if (k)
		m++;
	bv = new UC[m];
	n = n1;
	for (int i = 0; i < m; i++)
		bv[i] = 0;
}

BoolVector::BoolVector(const char * s)
{
	n = strlen(s);
	m = n / 8; int k = n % 8;
	if (k) m++;
	bv = new UC[m];
	int is = 0, ib = 0;
	if (k) {
		is = Input(s, ib, is, k);
		ib++;
	}
	for (; ib < m; ib++)
		is = Input(s, ib, is, 8);
}

BoolVector::BoolVector( const char * s, int temp)
{
	int len = strlen(s);
	n = temp;
	m = n / 8;
	int k = n % 8;
	if (k) m++;
	bv = new UC[m];

	int ib, is;
	if (len >= n)
	{
		ib = 0;
		is = len - n;
		if (k) {
			is = Input(s, ib, is, k);
			ib++;
		}
		for (; is < len; ib++)
			is = Input(s, ib, is, 8);
	}
	else {
		int m2 = len / 8; 
		int k2 = len % 8; 
		is = 0;
		if (k2) m2++;

		for (ib = 0; ib < m - m2; ib++) {
			bv[ib] = 0;
		}
		if (k2) {
			is = Input(s, ib, 0, k2);
			ib++;
		}
		for (; is < len; ib++)
			is = Input(s, ib, is, 8);
	}
}

BoolVector::BoolVector(const BoolVector & x)
{
	n = x.n;
	m = x.m;
	bv = new UC[m];
	for (int i = 0; i < m; i++)
		bv[i] = x.bv[i];
}


int BoolVector::Input(const char* s, int ib, int is, int k)
{
	UC mask = 1;
	bv[ib] = 0;
	for (int i = 0; i < k; i++, is++)
	{
		bv[ib] <<= 1;
		if (s[is] == '1') 
			bv[ib] |= mask;
	}
	return is;
}

void BoolVector::Output(int ib, int k)
{
	UC mask = 1;
	mask <<= k - 1;
	for (int i = 0; i < k; i++)
	{
		if (bv[ib] & mask)
			cout<< '1';
		else cout << '0';
		mask >>= 1;
	}
}

BoolVector BoolVector::operator=(const BoolVector& x)// почему работает только с конст?
{
	if (this != &x)
	{
		if (m != x.m)
		{
			delete[]bv;
			m = x.m;
			bv = new UC[m];
		}
		for (int i = 0; i < m; i++)
			bv[i] = x.bv[i];
		n = x.n;
	}
	return *this;
}
void BoolVector::Scan(int temp)
{
	char* s; int m1, k;
	s = new char[temp];
	cin >> s;

	m1 = temp / 8; k = temp % 8;
	if (k) m1++;

	if (m != m1)
	{
		delete[]bv;
		m = m1;
		bv = new UC[m];
	}
	n = temp;
	int ib = 0, is = 0;
	if (k)
	{
		is = Input(s, ib, is, k);
		ib++;
	}
	for (; is < n; ib++)
		is = Input(s, ib, is, 8);
}

void BoolVector::Print()
{
	int k = n % 8; int i = 0;
	if (k)
	{
		Output(0, k); 
		i++;
	}
	for (; i < m; i++)
		Output(i, 8);
	cout << endl;
}

int BoolVector::Weight()
{
	int w = 0;
	UC mask = 1;
	for (int i = 0; i < m; i++, mask = 1)
		for (mask <<= 7; mask != 0; mask >>= 1)
			if (bv[i] & mask)	w++;
	return w;
}

UC BoolVector::operator[](int i)
{
	int m1 = i / 8, k = i % 8;
	UC mask = 1;
	mask <<= k;
	if (bv[m - 1 - m1] & mask) return 1;
	else return 0;
}

bool BoolVector::operator==(BoolVector &x)
{
	if (n != x.n) return false;
	for (int i = 0; i < m; i++)
		if (bv[i] != x.bv[i]) return false;
	return true;
}

bool BoolVector::operator!=(BoolVector &x)
{
	if (*this == x)return false;
	else return true;
}

bool BoolVector::operator<(BoolVector & y)
{
	if (n != y.n) return false;
	for (int i = 0; i < m; i++)
		if (bv[i] >= y.bv[i]) return false;
	return true;
}

bool BoolVector::operator>(BoolVector & y)
{
	if (n != y.n) return false;
	for (int i = 0; i < m; i++)
		if (bv[i] <= y.bv[i]) return false;
	return true;
}

BoolVector BoolVector::operator&(BoolVector & x)
{
	int N = n, j_res = m - 1;
	if (N > x.n) {
		N = x.n; 
		j_res = x.m - 1; 
	}
	BoolVector Res(N);
	int j, j_x;
	for (j = m - 1, j_x = x.m - 1; j_res >= 0; j--, j_x--, j_res--)
		Res.bv[j_res] = bv[j] & x.bv[j_x];
	return Res;
}

BoolVector & BoolVector::operator&=(BoolVector & x)
{
	BoolVector res;
	res = (*this & x);
	*this = res;
	return (*this);
}

BoolVector BoolVector::operator|(BoolVector & x)
{
	int n1 = n, j_res = m - 1;
	if (x.n > n1)
	{
		n1 = x.n;
		j_res = x.m - 1;
	}
	BoolVector res(n1);
	int j, j_x;
	for (j = m - 1, j_x = x.m - 1; ((j >= 0) && (j_x >= 0)); j--, j_x--, j_res--)
		res.bv[j_res] = bv[j] | x.bv[j_x];
	if (j >= 0)
		for (; j_res > 0; j_res--, j--)
			res.bv[j_res] = bv[j];
	if (j_x >= 0)
		for (; j_res > 0; j_res--, j_x--)
			res.bv[j_res] = bv[j_x];
	return res;

}

BoolVector & BoolVector::operator|=(BoolVector & x)
{
	BoolVector res;
	res = (*this) | x;
	*this = res;
	return *this; 
}

BoolVector BoolVector::operator^(BoolVector & x)
{
	int n1 = n, j_res = m - 1;
	if (x.n > n1)
	{
		n1 = x.n;
		j_res = x.m - 1;
	}
	BoolVector res(n1);
	int j, j_x;
	for (j = m - 1, j_x = x.m - 1; (j >= 0) && (j_x >= 0); j--, j_x--, j_res--)
		res.bv[j_res] = bv[j] ^ x.bv[j_x];
	if (j >= 0)
		for (; j_res > 0; j_res--, j--)
		{
			res.bv[j_res] = bv[j];
		}
	if (j_x >= 0)
		for (; j_res > 0; j_res--, j_x--)
		{
			res.bv[j_res] = bv[j_x];
		}

	return res;

}

BoolVector & BoolVector::operator^=(BoolVector & x)
{
	BoolVector res;
	res = (*this) ^ x;
	*this = res;
	return (*this);
}

BoolVector BoolVector::operator~()
{
	for (int i = 0; i < m; i++)
		bv[i] = ~bv[i];
	return *this;
}

BoolVector BoolVector::operator<<(int k)
{
	BoolVector res = (*this);
	if (k >= n) for (int i = 0; i < m; i++) bv[i] = 0;
	else {
		for (int i = n - 1; i >= k; i--) {
			if (res[i - k] == 1) {
				res.SetUp1(i);
			}
			else  res.SetUp0(i); 
		}
	}
	res.SetUp0(k, 0);
	return res;
}

BoolVector & BoolVector::operator<<=(int k)
{
	BoolVector res = *this;
	res = res << k;
	*this = res;
	return *this;
}

BoolVector BoolVector::operator>>(int k)
{
	int temp = k;
	int i;
	for (i = 0; temp < n; i++, temp++)
	{
		if (operator[](temp))
		{
			this->SetUp1(i);
		}
		else
		{
			this->SetUp0(i);
		}
	}
	for (; i < n; i++)
	{
		this->SetUp0(i);
	}
	return *this;
}

BoolVector BoolVector::operator>>=(int k)
{
	BoolVector res = *this;
	res = res >> k;
	*this = res;
	return *this;
}

BoolVector BoolVector::SetUp1(int pos)
{
	if (pos < 0 || pos >= n) cout << "incorrect index" << endl;
	else {
		int m1 = pos / 8, k = pos % 8;
		UC mask = 1;  mask <<= k;
		bv[m - 1 - m1] |= mask;
	}
	return (*this);
}

BoolVector BoolVector::SetUp0(int pos)
{
	if (pos < 0 || pos >= n) cout << "incorrect index" << endl;
	else {
		int m1 = pos / 8, k = pos % 8;
		UC mask = 1;  mask <<= k;
		mask = ~(mask);
		bv[m - 1 - m1] &= mask;
	}
	return (*this);
}

BoolVector BoolVector::Invert(int pos)
{
	if (pos < 0 || pos >= n) cout << "incorrect index" << endl;
	else {
		int m1 = pos / 8, k = pos % 8;
		UC mask = 1;  mask <<= k;
		bv[m - 1 - m1] ^= mask;
	}
	return (*this);
}

BoolVector BoolVector::SetUp1(int kol, int pos)
{
	for (int i = pos; (i < n) & (i < pos + kol); i++) {
		SetUp1(i);
	}
	return *this;
}

BoolVector BoolVector::SetUp0(int kol, int pos)
{
	for (int i = pos; (i < n) & (i < pos + kol); i++) {
		SetUp0(i);
	}
	return *this;
}

BoolVector BoolVector::Invert(int kol, int pos)
{
	for (int i = pos; (i < n) & (i < pos + kol); i++) {
		Invert(i);
	}
	return *this;
}
ostream & operator<<(ostream & r, BoolVector & V)
{
	V.Print(); return r;
}

istream & operator>>(istream & r, BoolVector & V)
{
	V.Scan(V.n); return r;
}
