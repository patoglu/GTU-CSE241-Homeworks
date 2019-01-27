#include <iostream>

using namespace std;
void fillArray(int a[], int size);
int search(int a[], int size, int target);

int main()
{
	
	cout << "This program searches a list of numbers." << endl;

	int arraySize;

	cout << "How many numbers will be on the list? You decide! " << endl;
	cin >> arraySize;

	int *a;
	a = new int[arraySize];

	fillArray(a, arraySize);

	int target;
	cout << "Enter a value for search" << endl;
	cin >> target;

	int location = search(a,arraySize, target);
	if(location == -1)
		cout << "The number is not in the list." << endl;
	else
		cout << "Target found in " << location << "." << "place in the array. " << endl;

	delete [] a;

	return 0;






	return 0;
}

void fillArray(int a[], int size)
{
	cout << "Enter " << size << " of integers..." << endl;
	for(int i = 0 ; i < size ; ++i)
	{
		cin >> a[i];
	}
}
int search(int a[], int size, int target)
{
	int index = 0;

	while((a[index] != target) && index < size)
		index++;

	if(index == size)
		index = -1;
	else
		return index;
}
