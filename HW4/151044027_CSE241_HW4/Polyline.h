#ifndef POLYLINE_H_
#define POLYLINE_H_
#include <vector>
#include <iostream>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
using namespace std;


using namespace PatogluTriangle;
using namespace PatogluRectangle;
using namespace PatogluCircle;

namespace PatogluPolyline
{
	class Point2D;
	class Polyline
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
		Polyline();//default constructor.
		Polyline(const vector<Point2D> &twoDPoints);
		Polyline(const Point2D &point);
		Polyline(const Rectangle& rectangleObject);
		Polyline(const Triangle& triangleObject);
		Polyline(const Circle& circleObject); 
		Polyline(int theCapacity); //Polyline that creates an array with dynamic input.
		Polyline::Point2D& operator[](int theIndex);
		int getCapacity() const;
		int getUsed() const;
		bool operator==(const Polyline& rtSide) const;
		bool operator!=(const Polyline& rtSide) const;
		const Polyline operator+(const Polyline& rtSide) const;
		friend ostream& operator <<(ostream& output, const Polyline& rtSide);
		Polyline& operator=(const Polyline& rightSide);
		Polyline(const Polyline& pfaObject);
		~Polyline();

		
	private:
		Polyline::Point2D* connectedDots;
		int used;
		int capacity;

	};

}

#endif