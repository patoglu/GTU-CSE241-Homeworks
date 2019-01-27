#include <iostream>
using namespace std;
int main()
{

	/*int v1 = 0;
	int *p1;
	int *p2;
	*p1 = *p2;
	cout << "Adress of *p1 before any initializiton " << p1 << endl;
	cout << "*p1 is before any initializiton " << *p1 << endl;
	cout << "Adress of *p2 before any initializiton " << p2 << endl;
	cout << "*p2 is before any initializiton " << *p2 << endl;

	p1 = &v1;
	*p1 = 42;
	cout << "v1 is " << v1 << " *p1 is " << *p1 << endl;

 */
/*==========================================================================================*/
	/*int *p1, *p2;

	p1 = new int;
	p2 = new int;

	*p1 = 10;
	*p2 = 20;

	cout << *p1 << " " << *p2 << endl; // 10 - 20
	p1 = p2; //now p1's adress is equal to p2's adress. So both will point to p2's adress.
	cout << *p1 << " " << *p2 << endl; //20-20
	//*p1 = 30; 
	*p2 = 30;
	cout << *p1 << " " << *p2 << endl; //30 -30*/
/*==========================================================================================*/


	int *p1, *p2;
	p1 = new int;
	p2 = new int;
	*p1 = 10;
	*p2 = 20;

	cout << *p1 << " " << *p2 << endl; //10 - 20

	*p1 = *p2; 
	cout << *p1 << " " << *p2 << endl; //20-20
	*p1 = 30;
	cout << *p1 << " " << *p2 << endl; //30-20

/*==========================================================================================*/
	


}