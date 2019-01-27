#ifndef POLYGONVEC_H
#define POLYGONVEC_H //including required libraries.
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
	class PolygonVect:public Polygon
	{
	public:
		PolygonVect();//default constructor.
		PolygonVect(const vector<Point2D> &twoDPoints);
		PolygonVect(const Point2D &point);
		PolygonVect(const Rectangle& rectangleObject);
		PolygonVect(const Triangle& triangleObject);
		PolygonVect(const Circle& circleObject); 
		PolygonVect(int theCapacity); //Polygon that creates an array with dynamic input.
		PolygonVect::Point2D& operator[](int theIndex);
		inline int getSize()const{
			return STLDots.size();
		}
		bool operator==(const PolygonVect& rtSide) const;
		bool operator!=(const PolygonVect& rtSide) const;
		const PolygonVect operator+(const PolygonVect& rtSide) const;
		friend ostream& operator <<(ostream& output, const PolygonVect& rtSide);
		PolygonVect& operator=(const PolygonVect& rightSide);
		virtual Shape* operator++() override;
		virtual Shape* operator++(int) override;
		virtual Shape* operator--() override;
		virtual Shape* operator--(int) override;
	private:
		vector <Polygon::Point2D> STLDots;
	};

}

#endif