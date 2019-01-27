/*HW02 CREATED BY YUSUF PATOGLU - 151044027*/
//NOTE MY COMPILER DIDN'T LET ME TO DEFINE INLINE FUNCTIONS. 
//I DECIDED TO PUT THEM IN COMMENT LINE FOR ANY CASE OF FAILURE.
#include <iostream> 
#include <stdlib.h> //Including required libraries.
#include <fstream>
using namespace std;
#include "Circle.h"
namespace PatogluShape
{
	const double PI = 3.14;

	double Circle::totalArea = 0;
	double Circle::totalPerimeter = 0;

	Circle::Circle() //default constructor that initializes coordinates to common values.
	{
		setXCoordinate(0);
		setYCoordinate(0);
		setRadius(10);
		Circle::totalPerimeter += 2 * PI * radius;
		Circle::totalArea +=  PI * radius * radius;
		calculatedPerimeter = (getRadius() * 2 * PI);
		calculatedArea = (getRadius() * getRadius() * PI);

	}
	Circle::Circle(double xLocation, double yLocation, double circleRadius) //3 parameter constructor to test our objects.
	{
		setXCoordinate(xLocation);
		setYCoordinate(yLocation);
		setRadius(circleRadius);
		calculatedPerimeter = (getRadius() * 2 * PI);
		calculatedArea = (getRadius() * getRadius() * PI);		
	}
	/*double Circle::getXCoordinate(void) const //accessor function
	{
		return xCoordinate;
	}
	double Circle::getYCoordinate(void) const //accessor function
	{
		return yCoordinate;
	}
	double Circle::getRadius(void) const //accessor function
	{
		return radius;
	}
	*/
	void Circle::setXCoordinate(double xLocation) //mutator function
	{
		
			xCoordinate = xLocation;
	}
	void Circle::setYCoordinate(double yLocation) //mutator function
	{
		
		
			yCoordinate = yLocation;
	}

	void Circle::setRadius(double circleRadius) //mutator function
	{
		try
		{
			if(circleRadius < 0)
			{
				throw circleRadius;
			}
			radius = circleRadius;
		}
		catch(int ex)
		{
			cerr << "Exception!!" << endl;
		}
	}
	string Circle::circleScript()const //Helper function about writing files.
	{
		string Script;
		//<circle cx="25" cy="75" r="20" stroke="red" fill="transparent" stroke-width="5"/>
		Script = std::string("<circle cx=\"") + to_string(xCoordinate) + "\"" +" cy=\"" + to_string(yCoordinate) + "\""
		+ " r=\"" + to_string(radius) + "\"" + " stroke=\"blue\"" +  " fill=\"purple \"" + " />";

		return Script; 
	}
	void Circle::draw(std::ofstream &inputFile) // draw function to draw single object.
	{
		std::string fileWriter;
		fileWriter = circleScript();
		inputFile << fileWriter;
		inputFile << "\n";
	}
	/*Circle Circle::operator++()
	{
		xCoordinate++;
		yCoordinate++;

		return Circle(xCoordinate, yCoordinate, radius);

	}*/
	/*double Circle::getPerimeter(void) const
	{
		return 2 * 3.14 * radius;
	}
	double Circle::getSpace(void) const
	{
		return 3.14 * radius * radius;
	}*/
	/*
	Circle Circle::operator++(int ignoreThat)
	{
		double temp1 = xCoordinate;
		double temp2 = yCoordinate;

		xCoordinate++;
		yCoordinate++;

		return Circle(temp1, temp2, radius);
	}
	const Circle Circle::operator+(double incrementSize) const
	{
		double tempRadius = radius;

		tempRadius += incrementSize;

		return Circle(xCoordinate,yCoordinate, tempRadius);

	}
	Circle Circle::operator--()
	{
		xCoordinate--;
		yCoordinate--;

		return Circle(xCoordinate, yCoordinate, radius);

	}
	Circle Circle::operator--(int ignoreThat)
	{
		double temp1 = xCoordinate;
		double temp2 = yCoordinate;

		xCoordinate--;
		yCoordinate--;

		return Circle(temp1, temp2, radius);
	}
	*/
	Shape* Circle::operator++(void) 
	{
		
		xCoordinate++;
		yCoordinate++;
		Shape *myShape = new Circle(getXCoordinate(),getYCoordinate(),getRadius());
		return myShape;
		
		//newRectangle.setXCoordinate(xCoordinate++);
		//newRectangle.setYCoordinate(yCoordinate++);
		//tmp = &newRectangle;
	
	}
	Shape* Circle::operator++(int ignoreMe)
	{
		Shape *myShape = new Circle(getXCoordinate(),getYCoordinate(),getRadius());
		xCoordinate++;
		yCoordinate++;
		return myShape;		
	}
	Shape* Circle::operator--()
	{
		xCoordinate--;
		yCoordinate--;
		Shape *myShape = new Circle(getXCoordinate(),getYCoordinate(),getRadius());
		return myShape;
	}
	Shape* Circle::operator--(int ignoreMe)
	{
		Shape *myShape = new Circle(getXCoordinate(),getYCoordinate(),getRadius());
		xCoordinate--;
		yCoordinate--;
		return myShape;
	}

	const Circle Circle::operator-(double decrementSize) const
	{

		if(decrementSize > radius)
		{
			cout << "Size of object is smaller than decrementSize..." << endl;
		} 
		else
		{
			return Circle(xCoordinate, yCoordinate,radius - decrementSize);
		}
	}


	bool Circle::operator ==(const Shape& shapeObject) const
	{
		cout << "Circle == operator" << endl;
		const Circle *r = dynamic_cast <const Circle *>(&shapeObject);
	 	if(r == nullptr)
	 	{
	 		return false;
	 	}
	 	else
	 	{
	 		if(area() == (r->radius * r->radius) * PI)
	 		{
	 			return true;
	 		}
	 		else
	 		{
	 			return false;
	 		}
	 	}
	 }
	 bool Circle::operator !=(const Shape& shapeObject) const
	 {
	 	cout << "Circle != operator" << endl;
	 	const Circle *r = dynamic_cast <const Circle *>(&shapeObject);
	 	if(r == nullptr)
	 	{
	 		return false;
	 	}
	 	else
	 	{
	 		if(area() == (r->radius * r->radius) * PI)
	 		{
	 			return false;
	 		}
	 		else
	 		{
	 			return true;
	 		}
	 	}
	 }
	 bool Circle::operator <(const Shape& shapeObject) const
	 {
	 	const Circle *r = dynamic_cast <const Circle *>(&shapeObject);
	 	if(r == nullptr)
	 	{
	 		return false;
	 	}
	 	else
	 	{
	 		if(area() < (r->radius * r->radius) * PI)
	 		{
	 			return true;
	 		}
	 		else
	 		{
	 			return false;
	 		}
	 	}
	 }
	 bool Circle::operator >(const Shape& shapeObject) const
	 {
	 	const Circle *r = dynamic_cast <const Circle *>(&shapeObject); //Downcasting
	 	if(r == nullptr)
	 	{
	 		return false;
	 	}
	 	else
	 	{
	 		if(area()> (r->radius * r->radius) * PI)
	 		{
	 			return true;
	 		}
	 		else
	 		{
	 			return false;
	 		}
	 	}
	}
	ostream& Circle::print(std::ostream& output, const Shape& printedShape) const 
	{
		Circle newCircle(getXCoordinate(),getYCoordinate(),getRadius());
		Shape *myShape;
		myShape = &newCircle;
		output << newCircle.circleScript();
		return output;
	}
	double Circle::area()const
	{
		return getRadius() * getRadius() * PI;
	}
	double Circle::perimeter()const
	{
		//calculatedPerimeter == (width + height) * 2;
		return (getRadius() * PI * 2);
	}
	/*bool Circle::operator ==(const Circle& secondParameter) const
	{
		if(secondParameter.radius * secondParameter.radius * PI == (radius * radius * PI))
			return true;
		else
			return false;

	}
	bool Circle::operator !=(const Circle& secondParameter) const
	{
		if(secondParameter.radius * secondParameter.radius * PI != radius * radius * PI)
			return true;
		else
			return false;
	}*/
	/*ostream& operator<<(ostream& output, const Circle& circle)
	{
		output << circle.circleScript();
		return output;
	}
	*/
	/*double Circle::getTotalPerimeter()
	{
		return totalPerimeter;
	}
	double Circle::getTotalArea()
	{
		return totalArea;
	}*/
}
