#include "Money.h"

int main()
{

	Money yourAmount, myAmount(10,9);
	yourAmount.input();
	cout << "Your money: \n";
	yourAmount.output();

	cout << "My money: \n";

	myAmount.output();
	cout << endl;
	cout << "Nice now we both have moneys. Let's compare them...\n";
	cout << endl;

	if(myAmount == yourAmount)
	{
		cout << "WTF ? We have same money amount..." << endl;

	}
	else
	{
		cout << "As expected one of us is richer..." << endl;
	}
	cout << endl;

	cout << "Let's check what happens if we combine our strengths" << endl;
	cout << endl;

	(yourAmount + myAmount).output();
	cout << endl;
	cout << endl;
	cout << "I want to see the level between us." << endl;
	cout << endl;

	(yourAmount - myAmount).output();
	cout << endl;
	cout << endl;

	

	







	return 0;
}