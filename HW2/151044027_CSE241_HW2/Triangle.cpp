
/*HW02 CREATED BY YUSUF PATOGLU - 151044027*/
//NOTE MY COMPILER DIDN'T LET ME TO DEFINE INLINE FUNCTIONS. 
//I DECIDED TO PUT THEM IN COMMENT LINE FOR ANY CASE OF FAILURE.
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
#include "Triangle.h"

Triangle::Triangle()
{
	setX1Coordinate(0); //default triangle function that sets zero to all coordinates.
	setY1Coordinate(0);
	setX2Coordinate(0);
	setY2Coordinate(0);
	setX3Coordinate(0);
	setY3Coordinate(0);
	setWidth(0);
	
}
Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	setX1Coordinate(x1); // six parameter constructor that initializes 6 different dots.
	setY1Coordinate(y1); 
	setX2Coordinate(x2);
	setY2Coordinate(y2);
	setX3Coordinate(x3);
	setY3Coordinate(y3);
}
double Triangle::getWidth(void) const //accessor function for coordinate.
{
	return width;
}
double Triangle::getX1Coordinate(void) const //accessor function for coordinate.
{
	return x1Coordinate;
}
double Triangle::getY1Coordinate(void) const //accessor function for coordinate.
{
	return y1Coordinate;
}
double Triangle::getX2Coordinate(void) const //accessor function for coordinate.
{
	return x2Coordinate;
}
double Triangle::getY2Coordinate(void) const //accessor function for coordinate.
{
	return y2Coordinate;
}
double Triangle::getX3Coordinate(void) const //accessor function for coordinate.
{
	return x3Coordinate;
}
double Triangle::getY3Coordinate(void) const //accessor function for coordinate.
{
	return y3Coordinate;
}


void Triangle::setWidth(double triangleWidth)  //Mutator function
{
	
	width = triangleWidth;
	
}
inline void Triangle::setX1Coordinate(double triangleX1) //Mutator function
{
	
	
		x1Coordinate = triangleX1;
	}
inline void Triangle::setY1Coordinate(double triangleY1) //Mutator function
{
	
		y1Coordinate = triangleY1;
	
}

inline void Triangle::setX2Coordinate(double triangleX2) //Mutator function
{
	
	
		x2Coordinate = triangleX2;
	
}
inline void Triangle::setY2Coordinate(double triangleY2) //Mutator function
{
	
	
		y2Coordinate = triangleY2;
	
}
inline void Triangle::setX3Coordinate(double triangleX3) //Mutator function
{
	
	
	x3Coordinate = triangleX3;
	
}
inline void Triangle::setY3Coordinate(double triangleY3) //Mutator function
{
	
	
		y3Coordinate = triangleY3;
	
}

string Triangle::triangleScript(void) //helper function for writing file.
{
	string Script;
	//<polygon points="50 160 55 180 70 180 "  stroke="green" fill="transparent" stroke-width="5"/>
	Script = std::string("<polygon points=\"") + to_string(x1Coordinate) + " " + to_string(y1Coordinate) + " " + to_string(x2Coordinate) + " " + to_string(y2Coordinate) + " "
	+ to_string(x3Coordinate) + " " + to_string(y3Coordinate) + "\"" + " stroke=\"green\"" +  " fill=\"brown\"" + "/>";

	return Script;
}
void Triangle::draw(std::ofstream &inputFile) //drawing function that writes single file object to file.
{
	std::string fileWriter;
	fileWriter = triangleScript();
	inputFile << fileWriter;
	inputFile << "\n";
}











