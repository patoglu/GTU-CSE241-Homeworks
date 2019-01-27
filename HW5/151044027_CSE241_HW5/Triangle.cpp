
/*HW02 CREATED BY YUSUF PATOGLU - 151044027*/
//NOTE MY COMPILER DIDN'T LET ME TO DEFINE INLINE FUNCTIONS. 
//I DECIDED TO PUT THEM IN COMMENT LINE FOR ANY CASE OF FAILURE.
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Triangle.h"
using namespace std;


namespace PatogluShape
{
	const double SQRT3 = 1.73;
	Triangle::Triangle()
	{
		setX1Coordinate(0); //default triangle function that sets zero to all coordinates.
		setY1Coordinate(0);
		setX2Coordinate(0);
		setY2Coordinate(0);
		setX3Coordinate(0);
		setY3Coordinate(0);
		setWidth(0);
		calculatedArea = 0;
		
	}
	Triangle::Triangle(double theWidth)
	{
		setX1Coordinate(0); //default triangle function that sets zero to all coordinates.
		setY1Coordinate(0);
		setX2Coordinate(0);
		setY2Coordinate(0);
		setX3Coordinate(0);
		setY3Coordinate(0);
		width = theWidth;
		calculatedArea = getWidth() * getWidth() * SQRT3;
	}
	Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
	{
		setX1Coordinate(x1); // six parameter constructor that initializes 6 different dots.
		setY1Coordinate(y1); 
		setX2Coordinate(x2);
		setY2Coordinate(y2);
		setX3Coordinate(x3);
		setY3Coordinate(y3);
		calculatedArea = 0;
	}

	// THEY ARE INLINE.
	/*double Triangle::getWidth(void) const //accessor function for coordinate.
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
	*/


	void Triangle::setWidth(double triangleWidth)  //Mutator function
	{
		try
		{
			if(triangleWidth < 0)
			{
				throw triangleWidth;
			}
			width = triangleWidth;
		}
		catch(int ex)
		{
			cerr << "Exception!!" << endl;
		}
		
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

	/*double Triangle::getArea() const{
		return width * width * 1.73 / 3.0;
	}
	double Triangle::getPerimeter() const{
		return width * 3;
	}*/

	string Triangle::triangleScript(void) const //helper function for writing file.
	{
		string Script;
		//<polygon points="50 160 55 180 70 180 "  stroke="green" fill="transparent" stroke-width="5"/>
		Script = std::string("<polygon points=\"") + to_string(x1Coordinate) + " " + to_string(y1Coordinate) + " " + to_string(x2Coordinate) + " " + to_string(y2Coordinate) + " "
		+ to_string(x3Coordinate) + " " + to_string(y3Coordinate) + "\"" + " stroke=\"green\"" +  " fill=\"brown\"" + "/>";

		return Script;
	}
	const Triangle Triangle::operator+(const double incrementSize) const
	{
		return Triangle(width + incrementSize);
	}
	const Triangle Triangle::operator-(const double decrementSize) const
	{
		if(width < decrementSize)
		{
			cout << "Decrement size is bigger than width.." << endl;
		}
		else
		{
			return Triangle(width - decrementSize);
		}
	}
	Shape* Triangle::operator++(void) 
	{
		
		x1Coordinate++;
		x2Coordinate++;
		x3Coordinate++;
		y1Coordinate++;
		y2Coordinate++;
		y3Coordinate++;


		Shape *myShape = new Triangle(getX1Coordinate(),getY1Coordinate(),getX2Coordinate(),getY2Coordinate(),getX3Coordinate(),getY3Coordinate());
		
		//newRectangle.setXCoordinate(xCoordinate++);
		//newRectangle.setYCoordinate(yCoordinate++);
		//tmp = &newRectangle;
	
	}
	Shape* Triangle::operator++(int ignoreMe)
	{
		Shape *myShape = new Triangle(getX1Coordinate(),getY1Coordinate(),getX2Coordinate(),getY2Coordinate(),getX3Coordinate(),getY3Coordinate());
		x1Coordinate++;
		x2Coordinate++;
		x3Coordinate++;
		y1Coordinate++;
		y2Coordinate++;
		y3Coordinate++;
		return myShape;		
	}
	Shape* Triangle::operator--()
	{
		x1Coordinate++;
		x2Coordinate++;
		x3Coordinate++;
		y1Coordinate++;
		y2Coordinate++;
		y3Coordinate++;
		Shape *myShape = new Triangle(getX1Coordinate(),getY1Coordinate(),getX2Coordinate(),getY2Coordinate(),getX3Coordinate(),getY3Coordinate());
		return myShape;
	}
	Shape* Triangle::operator--(int ignoreMe)
	{
		Shape *myShape = new Triangle(getX1Coordinate(),getY1Coordinate(),getX2Coordinate(),getY2Coordinate(),getX3Coordinate(),getY3Coordinate());	
		x1Coordinate++;
		x2Coordinate++;
		x3Coordinate++;
		y1Coordinate++;
		y2Coordinate++;
		y3Coordinate++;
		return myShape;
	}
	/*bool Triangle::operator ==(const Triangle& secondParameter) const
	{
		if(width == secondParameter.width)
			return true;
		else
			return false;
	}
	bool Triangle::operator !=(const Triangle& secondParameter) const
	{
		if(width == secondParameter.width)
			return false;
		else
			return true;

	}*/
	/*
	Triangle Triangle::operator++()
	{
		x1Coordinate++;
		y1Coordinate++;
		x2Coordinate++;
		y2Coordinate++;
		x3Coordinate++;
		y3Coordinate++;
		return Triangle(x1Coordinate, y1Coordinate, x2Coordinate, y2Coordinate, x3Coordinate, y3Coordinate);
	}
	Triangle Triangle::operator++(int ignoreThat)
	{
		double temp1 = x1Coordinate;
		double temp2 = y1Coordinate;
		double temp3 = x2Coordinate;
		double temp4 = y2Coordinate;
		double temp5 = x3Coordinate;
		double temp6 = y3Coordinate;


		x1Coordinate++;
		y1Coordinate++;
		x2Coordinate++;
		y2Coordinate++;
		x3Coordinate++;
		y3Coordinate++;

		return Triangle(temp1, temp2, temp3, temp4, temp5, temp6);

	}
	Triangle Triangle::operator--()
	{
		x1Coordinate--;
		y1Coordinate--;
		x2Coordinate--;
		y2Coordinate--;
		x3Coordinate--;
		y3Coordinate--;
		return Triangle(x1Coordinate, y1Coordinate, x2Coordinate, y2Coordinate, x3Coordinate, y3Coordinate);
	}
	Triangle Triangle::operator--(int ignoreThat)
	{
		double temp1 = x1Coordinate;
		double temp2 = y1Coordinate;
		double temp3 = x2Coordinate;
		double temp4 = y2Coordinate;
		double temp5 = x3Coordinate;
		double temp6 = y3Coordinate;


		x1Coordinate--;
		y1Coordinate--;
		x2Coordinate--;
		y2Coordinate--;
		x3Coordinate--;
		y3Coordinate--;

		return Triangle(temp1, temp2, temp3, temp4, temp5, temp6);
	}
	*/

	bool Triangle::operator ==(const Shape& shapeObject) const
	{
		cout << "Triangle == operator" << endl;
		const Triangle *r = dynamic_cast <const Triangle *>(&shapeObject);
	 	if(r == nullptr)
	 	{
	 		return false;
	 	}
	 	else
	 	{
	 		if(area() == ((r->width * r->width) * SQRT3) / 4.0)
	 		{
	 			return true;
	 		}
	 		else
	 		{
	 			return false;
	 		}
	 	}
	 }
	 bool Triangle::operator !=(const Shape& shapeObject) const
	 {
	 	cout << "Triangle != operator" << endl;
	 	const Triangle *r = dynamic_cast <const Triangle *>(&shapeObject);
	 	if(r == nullptr)
	 	{
	 		return false;
	 	}
	 	else
	 	{
	 		if(area() == ((r->width * r->width) * SQRT3) / 4.0)
	 		{
	 			return false;
	 		}
	 		else
	 		{
	 			return true;
	 		}
	 	}
	 }
	 bool Triangle::operator <(const Shape& shapeObject) const
	 {
	 	const Triangle *r = dynamic_cast <const Triangle *>(&shapeObject);
	 	if(r == nullptr)
	 	{
	 		return false;
	 	}
	 	else
	 	{
	 		if(area() < ((r->width * r->width) * SQRT3) / 4.0)
	 		{
	 			return true;
	 		}
	 		else
	 		{
	 			return false;
	 		}
	 	}
	 }
	 bool Triangle::operator >(const Shape& shapeObject) const
	 {
	 	const Triangle *r = dynamic_cast <const Triangle *>(&shapeObject); //Downcasting
	 	if(r == nullptr)
	 	{
	 		return false;
	 	}
	 	else
	 	{
	 		if(area() > ((r->width * r->width) * SQRT3) / 4.0)
	 		{
	 			return true;
	 		}
	 		else
	 		{
	 			return false;
	 		}
	 	}
	}
	ostream& Triangle::print(std::ostream& output, const Shape& printedShape) const 
	{
		Triangle newTriangle(getX1Coordinate(),getY1Coordinate(),getX2Coordinate(),getY2Coordinate(),getX3Coordinate(),getY3Coordinate());
		Shape *myShape;
		myShape = &newTriangle;
		output << newTriangle.triangleScript();
		return output;
	}
	double Triangle::area()const
	{
		return (getWidth() * getWidth() * SQRT3) / 4.0;
	}
	double Triangle::perimeter()const
	{
		//calculatedPerimeter == (width + height) * 2;
		return (getWidth() * 3);
	}
	/*ostream& operator<<(ostream& output, const Triangle& triangle)
	{
		output << triangle.triangleScript();
		return output;
	}*/
	void Triangle::draw(std::ofstream &inputFile) //drawing function that writes single file object to file.
	{
		std::string fileWriter;
		fileWriter = triangleScript();
		inputFile << fileWriter;
		inputFile << "\n";
	}
	/*double Triangle::getTotalPerimeter(void)
	{
		return totalPerimeter;
	}
	double Triangle::getTotalArea(void)
	{
		return totalArea;
	}*/
}












