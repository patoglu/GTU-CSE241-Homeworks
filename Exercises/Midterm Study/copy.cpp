#include <iostream>

using namespace std;

class A
{
public:
	A() { cout << "Constructor called."<<endl;};
	A(const A& other) {cout << "Copy constructor called."<<endl;};
	A& operator =(const A& other) { cout << "Assignment called " << endl; return *this;};
};

int main()
{
	cout << "MAIN   --  Default const" << endl;
	A first;
	cout << "MAIN   --  Default const" << endl;
	A second;
	cout << "MAIN   --  Copy Assignment" << endl;
	first = second;
	cout << "MAIN   --  First Copy Const then copy Assignment" << endl;
	second = A(first);
	cout << "MAIN   --  Copy Constructor." << endl;
	A third = second;
	cout << "MAIN   --  Copy Constructor" << endl;
	A fourth = A(second);



}