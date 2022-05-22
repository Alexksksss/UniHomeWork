
Set::Set():BoolVector(256)
{
	M = 0;
}

Set::Set(char * s) : BoolVector(256)
{
	for (int i = 0; s[i]; i++) 
		SetUp1(s[i]);
	M = Weight();
}

Set::Set(const Set & x) : BoolVector(x)
{
	M = x.M;
}

Set & Set::operator=(const Set & S)
{
	if (this != &S) {
		BoolVector::operator=(S);
		M = Weight();
	}
	return *this;
}

Set Set::operator+(char ch)
{
	Set s = *this;
	s.SetUp1(ch);
	s.M = s.Weight();
	return s;
}

Set & Set::operator+=(char ch)
{
	SetUp1(ch);
	M = Weight();
	return *this;
}

Set Set::operator+(Set S)
{
	Set s = *this;
	s |= S;
	s.M = s.Weight();
	return s;
}

Set & Set::operator+=(Set S)
{
	*this |= S;
	M = Weight();
	return *this;
}

Set Set::operator-(char ch)
{
	Set s = *this;
	s.SetUp0((UC)ch);
	s.M = s.Weight();
	return s;
}

Set & Set::operator-=(char ch)
{
	SetUp0((UC)ch);
	M = Weight();
	return *this;
}

Set Set::operator-(Set S)
{
	Set s1 = *this;
	Set s2 = S*s1;
	s1 ^= s2;
	s1.M = s1.Weight();
	return s1;
}

Set & Set::operator-=(Set S)
{
	Set s1 = (*this) * S;
	*this ^= s1;
	M = Weight();
	return *this;
}

Set Set::operator*(Set S)
{
	Set s1 = *this;
	s1 &= S;
	s1.M = s1.Weight();
	return s1;
}

Set Set::operator*=(Set S)
{
	(*this) &= S;
	M = Weight();
	return *this;
}

Set Set::operator~()
{
	Set s1 = *this;
	s1.BoolVector::operator~();
	s1.M = s1.Weight();
	return s1;
}

bool Set::operator==(Set S)
{
	if (this->BoolVector::operator==(S))
		return true;
	return false;
}

bool Set::operator!=(Set S)
{
	if (this->BoolVector::operator!=(S))
		return true;
	return false;

}

int Set::Number()
{
	return M;
}

bool Set::FindKey(char ch)
{
	if (operator[]((UC)ch))
		return true;
	return false;
}

bool Set::Empty()
{
	if (M != 0)
		return false;
	else return true;
}

bool Set::NotEmpty()
{
	if (M != 0)
		return true;
	else return false;
}

void Set::Scan(int n)
{
	cout << "Enter " << n << " elements: ";
	char s[257];
	gets_s(s, 257);
	*this = Set(s);
}

void Set::Print()
{
	if (this->NotEmpty())
	{
		for (int i = 0; i < 256; i++)
			if (operator[](i))
				cout << char(i) << ' ';
	}
	else
		cout << "Set is Empty";
	cout << endl;
}

ostream & operator<<(ostream & r, Set & S)
{
	S.Print(); return r;
}

istream & operator>>(istream & r, Set & S)
{
	cout << "Enter elements   ";
	char s[257];
	gets_s(s, 257);
	S = Set(s);
	return r;
}
