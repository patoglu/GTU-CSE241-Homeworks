#include <iostream>
#include <cmath>
#include "Polygon.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h" 
#include <vector>

using namespace std;
using namespace PatogluTriangle;
using namespace PatogluRectangle;
using namespace PatogluCircle;

namespace PatogluPolygon
{
	Polygon::Polygon()
	{
		capacity = 100;
		connectedDots = new Point2D[capacity];
		used = 0;
	}
	Polygon::Polygon(int theCapacity)
	{
		capacity = theCapacity;
		connectedDots = new Point2D[capacity];
		used = 0;
	}

	Polygon::Polygon(const vector<Point2D> &twoDPoints)
	{
		capacity = twoDPoints.size();
		connectedDots = new Point2D[capacity];

		for(auto i = 0 ;  i < capacity ; ++i)
		{
			connectedDots[i].setTwoDx(twoDPoints[i].getTwoDx());
			connectedDots[i].setTwoDy(twoDPoints[i].getTwoDy());
		}
		used = capacity;

	}
	Polygon::Polygon(const Point2D &point)
	{
		capacity = 1;
		connectedDots = new Point2D[capacity];
		
			connectedDots->setTwoDx(point.getTwoDx());
			connectedDots->setTwoDy(point.getTwoDy());
		
		used = 1;
	}

	Polygon::Polygon(const Rectangle& rectangleObject)
	{

		capacity = 4;
		connectedDots = new Point2D[capacity];
		double x1,y1;
		double x2,y2;
		double x3,y3;
		double x4,y4;
		double width;
		double height;





		width = rectangleObject.getWidth();
		height = rectangleObject.getHeight();
		x1 = rectangleObject.getXCoordinate();
		y1 = rectangleObject.getYCoordinate();

		/*x2 = x1 + width;
		y2 = y1;
		x3 = x1;./
		y3 = y1 + height;
		x4 = x1 + width;
		y4 = y1 + height;*/ //Computer doesnt think the way that I think...

		x2 = x1;
		y2 = y1 + height;
		x3 = x1 + width;
		y3 = y1 + height;
		x4 = x1 + width;
		y4 = y1;


		connectedDots[0].setTwoDx(x1);
		connectedDots[0].setTwoDy(y1);

		connectedDots[1].setTwoDx(x2);
		connectedDots[1].setTwoDy(y2);

		connectedDots[2].setTwoDx(x3);
		connectedDots[2].setTwoDy(y3);

		connectedDots[3].setTwoDx(x4);
		connectedDots[3].setTwoDy(y4);
		used = 4;

	}
	Polygon::Polygon(const Triangle& triangleObject)
	{
		double x1,y1,x2,y2,x3,y3;
		double width;
		capacity = 3;
		connectedDots = new Point2D[capacity];
		width = triangleObject.getWidth();
		x1 = triangleObject.getX1Coordinate();
		y1 = triangleObject.getY1Coordinate();
		x2 = triangleObject.getX2Coordinate();
		y2 = triangleObject.getY2Coordinate();
		x3 = triangleObject.getX3Coordinate();
		y3 = triangleObject.getY3Coordinate();

		connectedDots[0].setTwoDx(x1);
		connectedDots[0].setTwoDy(y1);

		connectedDots[1].setTwoDx(x2);
		connectedDots[1].setTwoDy(y2);

		connectedDots[2].setTwoDx(x3);
		connectedDots[2].setTwoDy(y3);
		used = 3;


	}
	Polygon::Polygon(const Circle& circleObject)
	{
		
		double counterDegree = 0;
		capacity = 100;
		connectedDots = new Point2D[capacity];
		double x,y,radius;
		double tempx, tempy;
		x = circleObject.getXCoordinate();
		y = circleObject.getYCoordinate();
		radius = circleObject.getRadius();
		for(auto i = 0 ; i < 100 ; ++i)
		{
			counterDegree += 3.6;
			tempx = x + radius * cos(counterDegree * 3.14 / 180);
			tempy = y + radius * sin(counterDegree * 3.14 / 180);
			connectedDots[i].setTwoDx(tempx);
			connectedDots[i].setTwoDy(tempy);
			
		}

		used = 100;

	}

	Polygon& Polygon::operator=(const Polygon& rightSide)
	{
		if(capacity!= rightSide.capacity)
		{
			delete [] connectedDots;
			connectedDots = new Point2D[rightSide.capacity];
		}
		
		
			capacity = rightSide.capacity;
			used = rightSide.used;
			for(auto i = 0; i < used ; ++i)
			{

				connectedDots[i].setTwoDx(rightSide.connectedDots[i].getTwoDx());
				connectedDots[i].setTwoDy(rightSide.connectedDots[i].getTwoDy());
			}
		
		return *this;
	}
	Polygon::Polygon(const Polygon& pfaObject):capacity(pfaObject.capacity), used(pfaObject.used)
	{
		connectedDots = new Point2D[capacity];
		for(auto i = 0; i < used ; ++i)
		{
			connectedDots[i].setTwoDx(pfaObject.connectedDots[i].getTwoDx());
			connectedDots[i].setTwoDy(pfaObject.connectedDots[i].getTwoDy());
		}
	}
	Polygon::~Polygon()
	{
		delete [] connectedDots;
	}
	Polygon::Point2D& Polygon::operator[](int theIndex)
	{
		return connectedDots[theIndex];
	}

	int Polygon:: getCapacity() const
	{
		return capacity;
	}
	int Polygon:: getUsed() const
	{
		return used;
	}
	bool Polygon::operator==(const Polygon& rtSide) const
	{
		bool isEqual = true;
		for(auto i = 0 ; i < capacity ; ++i)
		{
			if((connectedDots[i].getTwoDx() == rtSide.connectedDots[i].getTwoDx()) && (connectedDots[i].getTwoDy() == rtSide.connectedDots[i].getTwoDy()))
			{
				//very good.
			}
			else
				isEqual = false;
		}
		return isEqual;
	}
	bool Polygon::operator!=(const Polygon& rtSide) const
	{
		bool isEqual = true;
		for(auto i = 0 ; i < capacity ; ++i)
		{
			if((connectedDots[i].getTwoDx() == rtSide.connectedDots[i].getTwoDx()) && (connectedDots[i].getTwoDy() == rtSide.connectedDots[i].getTwoDy()))
			{
				//very good.
			}
			else
				isEqual = false;
		}
		return !(isEqual);
	}
	const Polygon Polygon::operator+(const Polygon& rtSide) const
	{
		int i;
		int rtSideCapacity;
		int totalCapacity;
		rtSideCapacity = rtSide.capacity;
		totalCapacity = capacity + rtSideCapacity;
		Polygon bigPolygon(totalCapacity);
	

		for(i = 0 ; i < capacity; ++i)
		{
			bigPolygon.connectedDots[i] = connectedDots[i];
		}
		for(auto j = i ; j < totalCapacity ; ++j)
		{
			i = 0;
			i++;
			bigPolygon.connectedDots[j] = rtSide.connectedDots[i];
		}
		bigPolygon.used = totalCapacity;

		
		return bigPolygon;
	}
	ostream& operator<<(ostream& output, const Polygon& rtSide)
	{
		//<polygon points="200,10 250,190 160,210" style="fill:lime;stroke:purple;stroke-width:1" />
		output << "<polygon points =\"";
		for(auto i = 0; i < rtSide.used ; ++i)
		{
			//output << "rtUsed " << rtSide.used << endl; 
			//output << " " << rtSide.connectedDots->getTwoDx() << ',' << rtSide.connectedDots->getTwoDy();
			if(i < rtSide.used - 1)
				output << " " << rtSide.connectedDots[i].getTwoDx() << ',' << rtSide.connectedDots[i].getTwoDy() << ',';
			else
				output << " " << rtSide.connectedDots[i].getTwoDx() << ',' << rtSide.connectedDots[i].getTwoDy();
		}

		//output << " " << rtSide.connectedDots[1].getTwoDx() << ',' << rtSide.connectedDots[1].getTwoDy();



		output << "\"";
		output << " style=\"fill:lime;stroke:purple;stroke-width:1\" />";


		return output;
	}

	void Polygon::Point2D::setTwoDx(double theTwoDx)
	{
		twoDx = theTwoDx;
	}
	void Polygon::Point2D::setTwoDy(double theTwoDy)
	{
		twoDy = theTwoDy;
	}
	double Polygon::Point2D::getTwoDx() const
	{
		return twoDx;
	}
	double Polygon::Point2D::getTwoDy() const
	{
		return twoDy;
	}
	Polygon::Point2D::Point2D()
	{
		twoDx = 10;
		twoDy = 10;
	}
}

	