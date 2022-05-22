
Arr::Arr()
{
	a = new int[1]; n = 1;

}

Arr::Arr(int N)
{
	a = new int[N];
	n = N;
}

Arr::Arr(int *b, int m)
{
	a = new int[m];
	for (int i = 0; i < m; i++)
		a[i] = b[i];
	n = m;

}

Arr::Arr(const Arr & x)
{
	n = x.n;
	a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = x.a[i];

}

Arr & Arr::operator=(const Arr & x)
{
	if (this != &x)
	{
		delete[]a;
		n = x.n;
		a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = x.a[i];
	}
	return *this;
}

Arr::~Arr()
{
	delete[]a;
}

void Arr::Scan(int m)
{
	cout << "enter " << m << " elements: ";
	if (n != m)
	{
		delete[]a;   n = m;
		a = new int[m];
	}
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void Arr::Print()
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

int & Arr::operator[](int i)
{
	if (i < 0) {
		cout << "incorrect index: i<0" << endl;
		return a[0];
	}
	if (i > n) {
		cout << "incorrect index: i>n" << endl;
		return a[n - 1];
	}
	return a[i];
}

int Arr::FindKey(int key)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == key)	return i;
	}
	return -1;
}

Arr & Arr::operator+=(int key)
{
	int i, *t;
	t = new int[n + 1];
	for (i = 0; i < n; i++)  t[i] = a[i];
	t[n] = key;
	delete[]a;
	a = t;
	n++;
	return *this;

}

Arr Arr::operator+(int key)
{	
	Arr Res(n + 1);
	for (int i = 0; i < n; i++)
		Res.a[i] = a[i];
	Res.a[n] = key;
	return Res;
}

Arr & Arr::operator+=(Arr b)
{
	int *t;
	t = new int[n + b.n];
	for (int i = 0; i < n; i++) t[i] = a[i];
	for (int i = n; i < n + b.n; i++) t[i] = b.a[i - n];
	delete[]a;
	a = t;
	n = n+b.n;
	return *this;
}

Arr Arr::operator+(Arr b)
{
	Arr Res(n + b.n);
	for (int i = 0; i < n; i++)
		Res.a[i] = a[i];
	for (int i = n; i < n + b.n; i++)
		Res.a[i] = b.a[i - n];
	return Res;
}

Arr & Arr::operator-=(int key)
{
	int pos = FindKey(key);
	if (pos + 1) 	this->ShiftLeft(pos);
	else	cout << ("There is no key in Arr");
	return *this;
}
	
Arr Arr::operator-(int key)
{
	Arr Res(n );
	for (int i = 0; i < n; i++) {
		Res.a[i] = a[i];
	}
	Res -= key;
	return Res;
}

Arr & Arr::DelPosEq(int pos)
{
	try {
		if (pos < 0 || pos >= n) {
			throw ("Incorrect pos");
		}
		this->ShiftLeft(pos);
	}
	catch (char* s) {
		cout << "Error: " << s << "; Deleting first";
		this->ShiftLeft(0);
		return *this;
	}
	return *this;
}

Arr Arr::DelPosNew(int pos)
{
	Arr Res(n);//=*this
	for (int i = 0; i < n; i++) {
		Res.a[i] = a[i];
	}
	try {
		if (pos < 0 || pos >= n) {
			throw ("Incorrect pos");
		}
		Res.ShiftLeft(pos);
	}
	catch (char* s) {
		cout << "Error: " << s << "; Deleting first";
		Res.ShiftLeft(0);
		return Res;
	}
	return Res;
}

bool Arr::operator==(Arr b)
{
	int flag = 0;
	if (n == b.n) {
		for (int i = 0; i < n; i++) {
			if (a[i] != b.a[i]) flag = -1;
		}
	}
	else flag = -1;
	if (flag == 0) return true;
	else return false;
}

bool Arr::operator!=(Arr b)
{
	return !(*this == b);
}

int Arr::Max()
{
	int max = a[0], nmax = 0;
	for (int i = 1; i < n; i++){
		if (a[i] > max) {
			max = a[i];
			nmax = i;
		}
	}
	return nmax;
}

int Arr::Min()
{
	int min = a[0], nmin = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
			nmin = i;
		}
	}
	return nmin;
}

void Arr::Sorting()
{
	SortBubble(a, n);
}

void Arr::ShiftLeft(int pos)
{
	for (int i = pos; i < n - 1; i++) {
		a[i] = a[i + 1];
	}
	n--;
}


ostream & operator<<(ostream & r, Arr & x)
{
	for (int i = 0; i < x.n; i++) {
		cout << x.a[i] << " ";
	}
	cout << "\n";
	return r;
}

istream & operator>>(istream & r, Arr & x)
{
	int m=4;   
	x.Scan(m);
	return r;

}
