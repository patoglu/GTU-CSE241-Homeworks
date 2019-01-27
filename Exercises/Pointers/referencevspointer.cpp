#include <iostream>

using namespace std;

int main()
{
	int a = 123;
	int b = 20;

	int *p1 = &a;
	int *p2 = &b;


	cout << "a is " << a << endl;
	cout <<"b is " << b << endl;

	cout << "=============" << endl;
	cout << "p1 is " << p1 << endl;
	cout << "p2 is " << p2 << endl;
	cout << "=============" << endl;
	cout << "*p1 is " << *p1 << endl;
	cout << "*p2 is " << *p2 << endl;
	cout << "=============" << endl;
	cout << "a's adress " << &a << endl;
	cout << "b's adress " << &b << endl;
	cout << "=============" << endl;

	*p1 = *p2;
	b = 1;
	p1 = p2;
	cout << "big change." << endl;

	cout << "=============" << endl;
	cout << "p1 is " << p1 << endl;
	cout << "p2 is " << p2 << endl;
	cout << "=============" << endl;
	cout << "*p1 is " << *p1 << endl;
	cout << "*p2 is " << *p2 << endl;
	cout << "=============" << endl;
	cout << "a's adress " << &a << endl;
	cout << "b's adress " << &b << endl;
	cout << "=============" << endl;



	return 0;
}