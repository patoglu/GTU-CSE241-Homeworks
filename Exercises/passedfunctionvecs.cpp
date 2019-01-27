#include <iostream>
#include <vector>

using namespace std;

void fillVector(vector <int> &vector);
void printVector(const vector <int> &vector);
void reverse(const vector <int> &vector);

int main()
{
	vector <int> myVector;
	fillVector(myVector);
	printVector(myVector);
	reverse(myVector);
	return 0;
}


void fillVector(vector <int> &vector) //Vectors is not passed as reference.
{									  //Reason is vector allocates very large amount of memory.
	cout << "Type in a list of numbers.(-1 to stop: ";
	int input;

	cin >> input;

	while(input != -1)
	{
		vector.push_back(input);
		cin >> input;
	}
}

void printVector(const vector <int> &vector)
{
	for(unsigned int i = 0 ; i < vector.size() ; ++i)
	{
		cout << i << ". element is: " << vector[i] << endl;
	}
}

void reverse(const vector <int> &vector)
{
	cout << "Vector reversed: ";

	for(unsigned int i = vector.size() - 1 ; i >= 0 ; i--)
	{
		cout << vector[i] << " ";
	}
}