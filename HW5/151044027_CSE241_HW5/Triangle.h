/*HW02 CREATED BY YUSUF PATOGLU - 151044027*/
//NOTE MY COMPILER DIDN'T LET ME TO DEFINE INLINE FUNCTIONS. 
//I DECIDED TO PUT THEM IN COMMENT LINE FOR ANY CASE OF FAILURE.
#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <iostream>
#include <fstream> //Including required libraries.
#include <stdlib.h>
#include "Shape.h"
using namespace std;
namespace PatogluShape
{
class Triangle : public Shape
{
	public:
		Triangle(); //Default constructor.
		Triangle(double theWidth);
		Triangle(double x1, double y1, double x2, double y2, double x3, double y3); //3 parameter constructor to test our objects.
		inline double getWidth(void) const{return width;} //accessor function 
		inline double getX1Coordinate(void) const{return x1Coordinate;} //accessor function
		inline double getY1Coordinate(void) const{return y1Coordinate;} //accessor function
		inline double getX2Coordinate(void) const{return x2Coordinate;} //accessor function
		inline double getY2Coordinate(void) const{return y2Coordinate;} //accessor function
		inline double getX3Coordinate(void) const{return x3Coordinate;} //accessor function
		inline double getY3Coordinate(void) const{return y3Coordinate;} //accessor function
		//double getArea()const;
		//double getPerimeter()const;
	    void setWidth(double triangleWidth); //mutator function
		void setX1Coordinate(double triangleX1); //mutator function
		void setY1Coordinate(double triangleY1); //mutator function                  
		void setX2Coordinate(double triangleX2); //mutator function
		void setY2Coordinate(double triangleY2); //mutator function
		void setX3Coordinate(double triangleX3); //mutator function
		void setY3Coordinate(double triangleY3); //mutator function

		const Triangle operator+(const double incrementSize) const; //
		const Triangle operator-(const double decrementSize) const; //
		//bool operator ==(const Triangle& secondParameter) const; //
		//bool operator !=(const Triangle& secondParameter) const; //
		
		//Triangle operator++(void);
		//Triangle operator++(int);
		//Triangle operator--(void);
		//Triangle operator--(int);
		//static double getTotalPerimeter(void);
		//static double getTotalArea(void);
		virtual double area() const override;
		virtual double perimeter() const override;
		virtual ostream& print(ostream& out, const Shape& printedShape) const override;
		bool operator ==(const Shape& shapeObject) const; //
		bool operator !=(const Shape& shapeObject) const;
		bool operator <(const Shape& shapeObject) const;
		bool operator >(const Shape& shapeObject) const;
		virtual Shape* operator++() override;
		virtual Shape* operator++(int ignoreMe) override;
		virtual Shape* operator--() override;
		virtual Shape* operator--(int ignoreMe) override;		

		// friend ostream& operator<<(ostream& output, const Triangle& triangle);
		void draw(std::ofstream &inputFile);
	private:
		double x1Coordinate;//member variables
		double y1Coordinate;
		double x2Coordinate;
		double y2Coordinate;
		double x3Coordinate;
		double y3Coordinate;
		double width;
		static double totalPerimeter;
		static double totalArea;
		std::string triangleScript(void)const; //helper function to write file.
	};	
}


#endif /* TRIANGLE_H_ */





















