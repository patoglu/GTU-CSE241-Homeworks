#include <iostream>
#include <stdlib.h>
using namespace std;

class PFArrayD
{
public:
	PFArrayD();
	//Init capacity to 50.
	explicit PFArrayD(int capacityValue);
	//Init capacity to capacity Value.
	PFArrayD(const PFArrayD& pfaObject);
	void addElement(double element);
	bool full(void) const {return capacity == used;}
	//returns true if array is full, false otherwise.
	int getCapacity(void) const {return capacity;}
	//accessor function that returns used variable.
	int getNumberUsed(void) const{return used;}
	void emptyArray(void) const;
	//empties the array.
	double& operator[](int index);
	const double& operator[](int index) const;

	PFArrayD& operator ++();
	PFArrayD& operator =(const PFArrayD& rightSide);
	~PFArrayD();
private:
	double *a;
	int capacity;
	int used;
};

PFArrayD::PFArrayD():capacity(50), used(0)
{
	a = new double[capacity];
}

PFArrayD::PFArrayD(int capacityValue):capacity(capacityValue), used(0)
{
	a = new double[capacity];
}

PFArrayD::PFArrayD(const PFArrayD& pfaObject)
	:capacity(pfaObject.getCapacity()), used(pfaObject.getNumberUsed())
{
	a = new double(capacity);
	for(int i = 0 ; i < used ; ++i)
	
		a[i] = pfaObject.a[i];
}	

void PFArrayD::addElement(double element)
{
	if(used >= capacity)
	{
		double *p = new double[capacity * 2];
		capacity *= 2;
		cout << "ikiye katladim :d" << endl;
		for(int i = 0 ; i < used ; ++i)
		{
			p[i] = a[i];
		}
		delete [] a;

		a = p;
	}
	else
	{
		a[used] = element;
		used++;
	}
}

double& PFArrayD::operator[](int index)
{
	if(index >= used || index < 0)
	{
		cout << "What kind of mess is this ?" << endl;
		exit(0);
	}
	else
	{
		return a[index];
	}
}
const double& PFArrayD::operator[](int index) const
{
	if(index >= used || index < 0)
	{
		cout << "What kind of mess is this ?" << endl;
		exit(0);
	}
	else
	{
		return a[index];
	}
}

PFArrayD& PFArrayD::operator =(const PFArrayD& rightSide)
{
	if(capacity != rightSide.capacity)
	{
		delete [] a;
		a = new double[rightSide.capacity];
	}
	else
	{
		capacity = rightSide.capacity;
		used = rightSide.used;
		for(int i = 0 ; i < used ; ++i)
		{
			a[i] = rightSide.a[i];
		}
	return *this;
	}
}

PFArrayD::~PFArrayD()
{
	cout << "Gittim aq" << endl;
	delete [] a;
}

PFArrayD& PFArrayD::operator++()
{
	double *p = new double[capacity + 1];
	capacity+=1;
	for(int i = 0; i < used ; ++i)
	{
		p[i] = a[i];
	}
	delete [] a;
	a = p;
	

}

void testArray()
{
	int cap;
	cout << "Enter capacity of super array." << endl;
	cin >> cap;
	PFArrayD temp(cap);
	cout << "Enter up to " << cap << "non negative numbers." << endl;
	cout << "Place negative number at the end." << endl;

	double next;
	cin >> next;
	while((next >= 0))
	{
		temp.addElement(next);
		cin >> next;
	}

	cout << "You entered the following " << temp.getNumberUsed() << " numbers:" << endl;
	int index;
	int count = temp.getNumberUsed();

	for(index = 0 ; index < count ; ++index)
		cout << temp[index] << " ";
	cout << endl;


	//cout << "1" << endl;
}
int main()
{
	/*cout << "Let's get ready to the rummbleeeeeeeeee" << endl;
	char ans;
	do
	{
		testArray();
		cout << "Test again? (y/n) " ;
		cin >> ans;
	} while((ans == 'y') || (ans == 'Y'));
	*/

	PFArrayD myArray(5);
	cout <<"Before push back array capacity is: " << myArray.getCapacity() << " and used is " << myArray.getNumberUsed() << endl;

	myArray.addElement(1);
	myArray.addElement(2);
	myArray.addElement(3);
	for(int i = 0 ; i < myArray.getNumberUsed() ; ++i)
	{
		cout << myArray[i] << endl;
	}
	cout <<"After push back array capacity is: " << myArray.getCapacity() << " and used is " << myArray.getNumberUsed() << endl;

	++myArray;
	for(int i = 0 ; i < myArray.getCapacity() ; ++i)
	{
		cout << myArray[i] << endl;
	}
	cout <<"After after push back array capacity is: " << myArray.getCapacity() << " and used is " << myArray.getNumberUsed() << endl;
	return 0;

}


























