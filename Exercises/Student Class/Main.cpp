#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

using namespace std;

void fillVector(vector<Student>& newMyClass); //fillVector - fill in student information.
void printVector(const vector<Student>& newMyClass);
int main()
{
	vector <Student> myClass;
	fillVector(myClass);
	printVector(myClass);
	return 0;
}

void fillVector(vector<Student>& newMyClass)
{
	string name;
	char grade;
	cout << "How many students are in your class?" << endl;
	int classSize;

	cin >> classSize;

	for(int i = 0 ; i < classSize ; ++i)
	{
		cout << "Student Name: " << endl;
		cin >> name;
		cout << "Enter Student Grade " << endl;
		cin >> grade; 
		Student newStudent(name, grade);
		newMyClass.push_back(newStudent);
	}
}

void printVector(const vector<Student>& newMyClass)
{
	for(unsigned int i = 0 ; i < newMyClass.size() ; ++i)
	{
		cout << "Student Name: " << newMyClass[i].getName() << endl;
		cout << "Student Grade: " << newMyClass[i].getGrade() << endl;
	}
}
