#include "PolygonVect.h"

namespace PatogluShape
{
	PolygonVect::PolygonVect()
	{
		STLDots.resize(100);
	}
	//default constructor.
	PolygonVect::PolygonVect(const vector<Point2D> &twoDPoints)
	{
		STLDots.resize(twoDPoints.size());
		for(auto i = 0 ; i < twoDPoints.size() ; ++i)
		{
			STLDots[i].setTwoDx(twoDPoints[i].getTwoDx());
			STLDots[i].setTwoDy(twoDPoints[i].getTwoDy());
		}
	}
	PolygonVect::PolygonVect(const Point2D &point)
	{
		STLDots.resize(1);
		STLDots[0].setTwoDx(point.getTwoDx());
		STLDots[0].setTwoDy(point.getTwoDy());
	}

	PolygonVect::PolygonVect(const Rectangle& rectangleObject)
	{
		STLDots.resize(4);
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
		x2 = x1;
		y2 = y1 + height;
		x3 = x1 + width;
		y3 = y1 + height;
		x4 = x1 + width;
		y4 = y1;

		STLDots[0].setTwoDx(x1);
		STLDots[0].setTwoDy(y1);

		STLDots[1].setTwoDx(x2);
		STLDots[1].setTwoDy(y2);

		STLDots[2].setTwoDx(x3);
		STLDots[2].setTwoDy(y3);

		STLDots[3].setTwoDx(x4);
		STLDots[3].setTwoDy(y4);

	}
	PolygonVect::PolygonVect(const Triangle& triangleObject)
	{
		double x1,y1,x2,y2,x3,y3;
		double width;
		STLDots.resize(3);
		width = triangleObject.getWidth();
		x1 = triangleObject.getX1Coordinate();
		y1 = triangleObject.getY1Coordinate();
		x2 = triangleObject.getX2Coordinate();
		y2 = triangleObject.getY2Coordinate();
		x3 = triangleObject.getX3Coordinate();
		y3 = triangleObject.getY3Coordinate();

		STLDots[0].setTwoDx(x1);
		STLDots[0].setTwoDy(y1);

		STLDots[1].setTwoDx(x2);
		STLDots[1].setTwoDy(y2);

		STLDots[2].setTwoDx(x3);
		STLDots[2].setTwoDy(y3);
	}
	PolygonVect::PolygonVect(const Circle& circleObject)
	{
		double counterDegree = 0;
		STLDots.resize(100);
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
			STLDots[i].setTwoDx(tempx);
			STLDots[i].setTwoDy(tempy);
			
		}		
	}

	PolygonVect::PolygonVect(int theCapacity)
	{
		STLDots.resize(theCapacity);
	} //Polygon that creates an array with dynamic input.
	PolygonVect::Point2D& PolygonVect::operator[](int theIndex)
	{
		return STLDots[theIndex];
	}
	bool PolygonVect::operator==(const PolygonVect& rtSide) const
	{
		bool isEqual = true;
		for(auto i = 0 ; i < STLDots.size() ; ++i)
		{
			if((STLDots[i].getTwoDx() == rtSide.STLDots[i].getTwoDx()) && (STLDots[i].getTwoDy() == rtSide.STLDots[i].getTwoDy()))
			{
				//very good.
			}
			else
				isEqual = false;
		}
		return isEqual;
	}
	bool PolygonVect::operator!=(const PolygonVect& rtSide) const
	{
		bool isEqual = true;
		for(auto i = 0 ; i < STLDots.size() ; ++i)
		{
			if((STLDots[i].getTwoDx() == rtSide.STLDots[i].getTwoDx()) && (STLDots[i].getTwoDy() == rtSide.STLDots[i].getTwoDy()))
			{
				//very good.
			}
			else
				isEqual = false;
		}
		return !(isEqual);
	}

	const PolygonVect PolygonVect::operator+(const PolygonVect& rtSide) const
	{
		int i;
		int rtSideCapacity;
		int totalCapacity;
		rtSideCapacity = rtSide.STLDots.size();
		totalCapacity = STLDots.size() + rtSideCapacity;
		PolygonVect bigPolygon(totalCapacity);
	

		for(i = 0 ; i < STLDots.size(); ++i)
		{
			bigPolygon.STLDots[i] = STLDots[i];
		}
		for(auto j = i ; j < bigPolygon.STLDots.size() ; ++j)
		{
			i = 0;
			i++;
			bigPolygon.STLDots[j] = rtSide.STLDots[i];
		}

		
		return bigPolygon;
	}
	ostream& operator <<(ostream& output, const PolygonVect& rtSide)
	{
		//<polygon points="200,10 250,190 160,210" style="fill:lime;stroke:purple;stroke-width:1" />
		output << "<polygon points =\"";
		for(auto i = 0; i < rtSide.STLDots.size() ; ++i)
		{
			//output << "rtUsed " << rtSide.used << endl; 
			//output << " " << rtSide.connectedDots->getTwoDx() << ',' << rtSide.connectedDots->getTwoDy();
			if(i < rtSide.STLDots.size() - 1)
				output << " " << rtSide.STLDots[i].getTwoDx() << ',' << rtSide.STLDots[i].getTwoDy() << ',';
			else
				output << " " << rtSide.STLDots[i].getTwoDx() << ',' << rtSide.STLDots[i].getTwoDy();
		}
		//output << " " << rtSide.connectedDots[1].getTwoDx() << ',' << rtSide.connectedDots[1].getTwoDy();
		output << "\"";
		output << " style=\"fill:lime;stroke:purple;stroke-width:1\" />";
		return output;

	}
	PolygonVect& PolygonVect::operator=(const PolygonVect& rightSide)
	{
		if(STLDots.size()!= rightSide.STLDots.size())
		{
			STLDots.clear();
			
			STLDots.resize(rightSide.STLDots.size());
		}
		
			for(auto i = 0; i <rightSide.STLDots.size() ; ++i)
			{

				STLDots[i].setTwoDx(rightSide.STLDots[i].getTwoDx());
				STLDots[i].setTwoDy(rightSide.STLDots[i].getTwoDy());
			}
		
		return *this;
	}

	Shape* PolygonVect:: operator++() 
	{
		Shape *a;
		cerr << "You shouldn't increment Polygon objects." << endl;
		return a;
	}
	Shape* PolygonVect:: operator++(int) 
	{
		Shape *a;
		cerr << "You shouldn't increment Polygon objects." << endl;
		return a;
	}
	Shape* PolygonVect:: operator--() 
	{
		Shape *a;
		cerr << "You shouldn't increment Polygon objects." << endl;
		return a;
	}
	Shape* PolygonVect::operator--(int) 
	{
		Shape *a;
		cerr << "You shouldn't increment Polygon objects." << endl;
		return a;
	}


}