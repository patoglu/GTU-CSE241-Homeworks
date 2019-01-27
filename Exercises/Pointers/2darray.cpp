#include <iostream>

using namespace std;

int main()
{
	int d1,d2;
	cout << "Enter row and column of array in order. \n";
	cin >> d1 >> d2;

	int **m = new *int[d1];
	int i,j;
	for(i = 0 ; i < d1 ; ++i)
	{
		m[i] = new int [d2];
	}
	cout << "Enter input: " << endl;

	for(i = 0 ; i < d1 ; ++i)
	{
		for(j = 0 ; j < d2 ; ++j)
		{
			cin >> m[i][j];
		}
	}



	return 0;
}