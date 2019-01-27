#include "Student.h"

Student::Student()
{
	newGrade = ' ';
}
Student::Student(string name, char grade)
{
	newName = name;
	newGrade = grade;
}
Student::~Student()
{
	
}

string Student::getName(void) const
{
	return newName;
}

char Student::getGrade(void) const
{
	return newGrade;
}

void Student::setName(string name)
{
	newName = name;
}
void Student::setGrade(char grade)
{
	newGrade = grade;
}