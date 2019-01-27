#ifndef POLYGONDYN_H
#define POLYGONDYN_H //including required libraries.
#include <iostream>
#include <cmath>
#include "Polygon.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h" 
#include <vector>
using namespace std;
namespace PatogluShape
{
	class PolygonDyn:public Polygon
	{
	public:
		PolygonDyn();//default constructor.
		PolygonDyn(const vector<Point2D> &twoDPoints);
		PolygonDyn(const Point2D &point);
		PolygonDyn(const Rectangle& rectangleObject);
		PolygonDyn(const Triangle& triangleObject);
		PolygonDyn(const Circle& circleObject); 
		PolygonDyn(int theCapacity); //Polygon that creates an array with dynamic input.
		PolygonDyn::Point2D& operator[](int theIndex);
		int getCapacity() const;
		int getUsed() const;
		bool operator==(const PolygonDyn& rtSide) const;
		bool operator!=(const PolygonDyn& rtSide) const;
		const PolygonDyn operator+(const PolygonDyn& rtSide) const;
		friend ostream& operator <<(ostream& output, const PolygonDyn& rtSide);
		PolygonDyn& operator=(const PolygonDyn& rightSide);
		PolygonDyn(const PolygonDyn& pfaObject);
		~PolygonDyn();
		virtual Shape* operator++() override;
		virtual Shape* operator++(int) override;
		virtual Shape* operator--() override;
		virtual Shape* operator--(int) override;
	private:
		Polygon::Point2D* connectedDots;
		int used;
		int capacity;
	};

}

#endif


