/*HW02 CREATED BY YUSUF PATOGLU - 151044027*/
#ifndef RECTANGLE_H_
#define RECTANGLE_H_ //including required libraries.
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
class Rectangle
{
	public:
		Rectangle(); //default constructor.
		Rectangle(double xLocation, double yLocation, double width, double height); // 4 parameter function to set our objects.
		double getWidth(void) const; //accessor functions.
		double getHeight(void) const; //accessor functions.
		double getXCoordinate(void) const; //accessor functions.
		double getYCoordinate(void) const; //accessor functions.
		void setWidth(double rectangleWidth); //mutator functions.
		void setHeight(double rectangleHeight); //mutator functions.
		void setXCoordinate(double xLocation); //mutator functions.
		void setYCoordinate(double yLocation); //mutator functions.
		void draw(ofstream &inputFile); //file writing function.

	private:
		std::string rectangleScript(void); //helper function to write file.
		double xCoordinate;
		double yCoordinate; // private member variables.
		double width;
		double height;
};

#endif /* RECTANGLE_H_ */	