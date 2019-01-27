/*HW02 CREATED BY YUSUF PATOGLU - 151044027*/
#ifndef CIRCLE_H_
#define CIRCLE_H_
#include <iostream> //Required libraries for circle.h
#include <fstream>
#include <stdlib.h>
using namespace std;
//NOTE MY COMPILER DIDN'T LET ME TO DEFINE INLINE FUNCTIONS. 
//I DECIDED TO PUT THEM IN COMMENT LINE FOR ANY CASE OF FAILURE.
class Circle
{
	public:
		Circle(); //default constructor for circle.
		Circle(double xLocation, double yLocation, double circleRadius); // 3 parameter constructor to test our objects.
		double getXCoordinate(void) const; //accessor functions. 
		double getYCoordinate(void) const; //accessor functions.
		double getRadius(void) const; //accessor functions.
		void setXCoordinate(double xLocation); //mutator functions.
		void setYCoordinate(double yLocation); //mutator functions.
		void setRadius(double circleRadius); //mutator functions.
		void draw(std::ofstream &inputFile); //draw function to write single object to file.
	private:
		double xCoordinate; //private members 
		double yCoordinate;
		double radius;
		std::string circleScript(void); // helper function to write file.
};

#endif /* CIRCLE_H_ */