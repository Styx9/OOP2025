class Number
{
	friend Number operator+(const Number& lhs, const Number& rfs);
	friend Number operator-(const Number& lhs, const Number& rfs);
	char* number;
	int base;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int number);
	~Number();

	// add operators and copy/move constructor
	Number(const Number& source);
	Number(Number&& source);
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
	bool operator>(Number& rhs) const;
	bool operator<(Number& rhs) const;
	bool operator==(Number& rhs) const;
	char operator[](int index) const;
	void operator+=(Number& rhs);
	void operator--();
	void operator--(int value);
	Number& operator=(const Number& rhs); // Copy assignment
	Number& operator=(Number&& rhs); // Move assignment
	Number& operator=(int value);
	Number& operator=(const char* value);
};
