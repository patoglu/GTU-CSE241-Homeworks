#include <iostream>
#include <vector>

using namespace std;

int main()
{

	vector <int> myVector;

	myVector.push_back(3);
	myVector.push_back(2);
	myVector.push_back(2);
	myVector.push_back(1);
	myVector.push_back(5);
	myVector.push_back(4);
	myVector.push_back(3);



	cout << "Vector: ";

	for(unsigned int i = 0 ; i < myVector.size() ; ++i)
	{
		cout << myVector[i] << " ";
	}

	myVector.insert(myVector.begin() + 3, 5);
	cout << endl;

	for(unsigned int i = 0 ; i < myVector.size() ; ++i)
	{
		cout << myVector[i] << " ";
	}

	if(myVector.empty())
	{
		cout << endl << "Is Empty! ";
	}
	else
	{
		cout << endl << "Is not Empty!";
	}

	myVector.clear();


	
	if(myVector.empty())
	{
		cout << endl << "Is Empty! ";
	}
	else
	{
		cout << endl << "Is not Empty!";
	}

}