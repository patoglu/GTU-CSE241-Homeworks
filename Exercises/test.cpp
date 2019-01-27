#include <iostream>

using namespace std;


class Base
{
public:
	Base()
	{
		cout << "Base default constructor." << endl;
		a = 10;
	}
	Base(int addNum)
	{
		cout << "Base parameterized constructor." << endl;
		a = addNum;
	}

	virtual void showNumber(void) const
	{
		cout << "Printing in the base class " << a << endl;
	}
	int getNumber(void) const
	{
		return a;
	}

private:
	int a;
};

class Derived : public Base
{
public:
	Derived():Base()
	{
		cout << "Derived non param constructor" << endl;
	}
	void showNumber(void) const
	{
		cout << "Printing the number in Derived " << getNumber() << endl;
	}

private:

};
void globalPrint(const Base& globalObject)
{
	cout << "Printing the goddamn global..." << endl;
	globalObject.showNumber();
}

int main(void)
{
	Derived a;
	globalPrint(a);

	return 0;
}