#ifndef POLYGON_H_
#define POLYGON_H_
#include <vector>
#include <iostream>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
using namespace std;
using namespace PatogluTriangle;
using namespace PatogluRectangle;
using namespace PatogluCircle;

namespace PatogluPolygon
{
	class Point2D;
	class Polygon
	{

	public:
		class Point2D
		{
			public:
				Point2D();
				void setTwoDx(double the2Dx);
				void setTwoDy(double the2Dy);
				double getTwoDx() const;
				double getTwoDy() const;

			private:
				double twoDx;
				double twoDy;
		};
		Polygon();//default constructor.
		Polygon(const vector<Point2D> &twoDPoints);
		Polygon(const Point2D &point);
		Polygon(const Rectangle& rectangleObject);
		Polygon(const Triangle& triangleObject);
		Polygon(const Circle& circleObject); 
		Polygon(int theCapacity); //Polygon that creates an array with dynamic input.
		Polygon::Point2D& operator[](int theIndex);
		int getCapacity() const;
		int getUsed() const;
		bool operator==(const Polygon& rtSide) const;
		bool operator!=(const Polygon& rtSide) const;
		const Polygon operator+(const Polygon& rtSide) const;
		friend ostream& operator <<(ostream& output, const Polygon& rtSide);
		Polygon& operator=(const Polygon& rightSide);
		Polygon(const Polygon& pfaObject);
		~Polygon();

		
	private:
		Polygon::Point2D* connectedDots;
		int used;
		int capacity;

	};
}

#endif