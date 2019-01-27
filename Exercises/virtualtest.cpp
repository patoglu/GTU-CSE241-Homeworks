#include <iostream>
using namespace std;
class Base
{
public:
	virtual void myPureVirtual(void)const = 0;
	void toDo(void)const{ cout << "Diamond heart." << endl; }
	bool operator ==(const Base& shapeObject)const{
		if(shapeObject.x == x)
		{
			return true;
		}
		else
			return false;
	}
	void setCalculatedArea(double theX){x = theX;}
private:
	int x;

};

class Derived:Base
{
public:
	Derived()
	{
		setCalculatedArea(100);
	}
	void myPureVirtual(void)const{cout << "Faded" << endl;}
	void test(void)const{toDo();}
};

int main()
{
	Derived a;
	Derived b;
	a.test();
	a.myPureVirtual();
	if(a == b)
	{
		cout << " voah " << endl; //Olmadi.
	}
}