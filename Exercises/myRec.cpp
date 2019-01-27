#include <iostream>
#include <vector>
using namespace std;
template <class T>
T aver(vector<T> vect)
{
	if(vect.size() == 1)
		return vect[0];
	T t = vect[vect.size() - 1];
	vect.pop_back();
	
	return (t + (aver(vect) * vect.size())) / (vect.size()+1);
}
int main()
{
	vector <int> arr;
	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
;


	int result = aver(arr);
	cout << "result is " << result << endl;

	return 0;
}