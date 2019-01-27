#ifndef STUDENT_H
#define STUDENT_H


#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
	Student(); //Default constructor.
	Student(string name, char grade); //Overloaded constructor.
	~Student(); //destructor
	string getName(void) const; // getName return string.
	char getGrade(void) const; //getGrade return char.
	void setName(string name); //sets name of student.
	void setGrade(char grade); //sets grade of student.
private:
	string newName;
	char newGrade;
};

#endif