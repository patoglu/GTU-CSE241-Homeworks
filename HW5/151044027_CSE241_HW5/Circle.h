/*HW02 CREATED BY YUSUF PATOGLU - 151044027*/
#ifndef CIRCLE_H_
#define CIRCLE_H_
#include "Shape.h"
#include <iostream> //Required libraries for circle.h
#include <fstream>
#include <stdlib.h>
using namespace std;
//NOTE MY COMPILER DIDN'T LET ME TO DEFINE INLINE FUNCTIONS. 
//I DECIDED TO PUT THEM IN COMMENT LINE FOR ANY CASE OF FAILURE.

namespace PatogluShape
{
	class Circle:public Shape
	{
		public:
			Circle(); //default constructor for circle.
			Circle(double xLocation, double yLocation, double circleRadius); // 3 parameter constructor to test our objects.
			inline double getXCoordinate(void) const{ return xCoordinate;} //accessor functions. 
			inline double getYCoordinate(void) const{ return yCoordinate; } //accessor functions.
			inline double getRadius(void) const{ return radius;} //accessor functions.
			void setXCoordinate(double xLocation); //mutator functions.
			void setYCoordinate(double yLocation); //mutator functions.
			void setRadius(double circleRadius); //mutator functions.
			//double getPerimeter(void) const;
			//double getSpace(void) const;
			const Circle operator+(const double incrementSize) const; //
			const Circle operator-(const double decrementSize) const; //
			bool operator ==(const Shape& shapeObject) const; //
			//bool operator ==(const Shape& shapeObject) const;
			bool operator !=(const Shape& shapeObject) const;
			bool operator <(const Shape& shapeObject) const;
			bool operator >(const Shape& shapeObject) const;
			//bool operator ==(const Circle& secondParameter) const; //
			//bool operator !=(const Circle& secondParameter) const; //
			//Circle operator++(void);
			//Circle operator++(int);
			//Circle operator--(void);
			//Circle operator--(int);
			virtual double area() const override;
			virtual double perimeter() const override;
			virtual ostream& print(ostream& out, const Shape& printedShape) const override;
			//static double getTotalPerimeter(void);
			//static double getTotalArea(void);
			virtual Shape* operator++() override;
			virtual Shape* operator++(int ignoreMe) override;
			virtual Shape* operator--() override;
			virtual Shape* operator--(int ignoreMe) override;
			//friend ostream& operator<<(ostream& output, const Circle& circle);

			void draw(std::ofstream &inputFile); //draw function to write single object to file.
		private:
			double xCoordinate; //private members 
			double yCoordinate;
			double radius;
			static double totalPerimeter;
			static double totalArea;
			std::string circleScript(void)const; // helper function to write file.
	};	
}


#endif /* CIRCLE_H_ */