/*HW02 CREATED BY YUSUF PATOGLU - 151044027*/
#ifndef RECTANGLE_H_
#define RECTANGLE_H_ //including required libraries.
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

namespace PatogluRectangle
{
	class Rectangle
	{
	public:
		Rectangle(); //default constructor.
		Rectangle(double xLocation, double yLocation, double width, double height); // 4 parameter function to set our objects.
		double getPerimeter(void) const;
		double getArea(void) const;
		inline double getWidth(void) const{ return width;} //accessor functions.
		inline double getHeight(void) const{ return height; } //accessor functions.
		inline double getXCoordinate(void) const{ return xCoordinate; } //accessor functions.
		inline double getYCoordinate(void) const{ return yCoordinate;} //accessor functions.
		void setWidth(double rectangleWidth); //mutator functions.
		void setHeight(double rectangleHeight); //mutator functions.
		void setXCoordinate(double xLocation); //mutator functions.
		void setYCoordinate(double yLocation); //mutator functions.
		const Rectangle operator+(const double incrementSize) const; //
		const Rectangle operator-(const double decrementSize) const; //
		bool operator ==(const Rectangle& secondParameter) const; //
		bool operator !=(const Rectangle& secondParameter) const; //
		Rectangle operator++(void);
		Rectangle operator++(int);
		Rectangle operator--(void);
		Rectangle operator--(int);
		static double getTotalPerimeter(void);
		static double getTotalArea(void);
		void draw(ofstream &inputFile); //file writing function.
		friend ostream& operator<<(ostream& output, const Rectangle& rectangle);


	private:
		std::string rectangleScript(void) const; //helper function to write file.
		double xCoordinate;
		double yCoordinate; // private member variables.
		double width;
		double height;
		static double totalPerimeter;
		static double totalArea;
	};	
}
#endif /* RECTANGLE_H_ */