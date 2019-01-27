#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	const int arrSize = 5;

	string stringArr[arrSize] = {"RED", "GREEN", "BLUE", "VIOLET", "YELLOW"};
	string *sPtr = nullptr;

	sPtr = &stringArr[0];



	for(int i = 0 ; i < arrSize ; ++i)
	{
		cout << sPtr << " " << *sPtr << endl;
		sPtr++;
	}
	






	return 0;
}