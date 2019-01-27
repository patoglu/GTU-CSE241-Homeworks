/*HW02 CREATED BY YUSUF PATOGLU - 151044027*/
//NOTE MY COMPILER DIDN'T LET ME TO DEFINE INLINE FUNCTIONS. 
//I DECIDED TO PUT THEM IN COMMENT LINE FOR ANY CASE OF FAILURE.
#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <iostream>
#include <fstream> //Including required libraries.
#include <stdlib.h>
using namespace std;
class Triangle
{
	public:
		Triangle(); //Default constructor.
		Triangle(double x1, double y1, double x2, double y2, double x3, double y3); //3 parameter constructor to test our objects.
		double getWidth(void) const; //accessor function 
		double getX1Coordinate(void) const; //accessor function
		double getY1Coordinate(void) const; //accessor function
		double getX2Coordinate(void) const; //accessor function
		double getY2Coordinate(void) const; //accessor function
		double getX3Coordinate(void) const; //accessor function
		double getY3Coordinate(void) const; //accessor function
	    void setWidth(double triangleWidth); //mutator function
		void setX1Coordinate(double triangleX1); //mutator function
		void setY1Coordinate(double triangleY1); //mutator function                  
		void setX2Coordinate(double triangleX2); //mutator function
		void setY2Coordinate(double triangleY2); //mutator function
		void setX3Coordinate(double triangleX3); //mutator function
		void setY3Coordinate(double triangleY3); //mutator function
		void draw(std::ofstream &inputFile);
	private:
		double x1Coordinate;//member variables
		double y1Coordinate;
		double x2Coordinate;
		double y2Coordinate;
		double x3Coordinate;
		double y3Coordinate;
		double width;
		std::string triangleScript(void); //helper function to write file.
};

#endif /* TRIANGLE_H_ */





















