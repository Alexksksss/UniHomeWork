
class Set :public BoolVector
{
	int M; 	 //кол-во элементов мн-ва

public:
	Set();
	Set(char *s);
	Set(const Set &);
	Set & operator= (const Set &);
	~Set() {};

	Set operator+ (char ch); 		// добавление эл-та к мн-ву  (создается новое мн-во)
	Set & operator+= (char ch); 	// добавление эл-та к мн-ву (меняется *this)
	Set operator+ (Set S); 		// объединение мн-в (создается новое мн-во)
	Set & operator+= (Set S); 	// объединение мн-в (меняется *this)

	Set operator- (char ch); 		// удаление эл-та из мн-ва (создается новое мн-во)
	Set & operator-= (char ch); 	// удаление эл-та из мн-ва (меняется *this)
	Set operator- (Set S); 		// разность мн-в (создается новое мн-во)
	Set & operator-= (Set S); 	// разность мн-в (меняется *this)

	Set operator* (Set S); 		//пересечение мн-в (создается новое мн-во)
	Set  operator*= (Set S); 		//объединение мн-в (меняется *this)

	Set operator~ ();			//дополнение до универсального
						   //универсальное мн-во - мн-во из 256 символов

	bool operator== (Set S);		//равенство мн-в
	bool operator!= (Set S);		//неравенство мн-в

	int Number();
	bool FindKey(char);    	//проверка принадлежности эл-та мн-ву

	bool Empty();        	      	//проверка пустоты множества
	bool NotEmpty();          	//проверка непустоты множества

	virtual void Scan(int) override;
	virtual void Print() override;

	friend ostream & operator<< (ostream &r, Set &S);
	friend istream & operator>> (istream &r, Set &S);
	operator int() { return M; }
}
