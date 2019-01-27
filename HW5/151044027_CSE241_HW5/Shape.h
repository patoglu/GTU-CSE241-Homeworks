/*HW06 CREATED BY YUSUF PATOGLU - 151044027*/
#ifndef SHAPE_H_
#define SHAPE_H_ //including required libraries.
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
using namespace std;
/* #Shape abstract class for all shapes.
   #Since all shapes are shape I can make comparison between shapes.
   #For example comparing between Rectangle - Rectangle and Rectangle - Circle.
   #This is not late binding I'm doing. This is compilation time process.
   #I didn't mark my operators as virtual. But area and perimeter functions are equal.
   #I will redefine logic operators in derived classes. Actually there is no need to do that.
   #But just in case I will let them stay there. I need to make some downcasting Shape -> DerivedShape
   #to apply this.

   #If you want to compare two derived class objects, for examples rectangles.
   #Create two rectangle object as usual way and derived class' comparison operator will be used.
   #If you want to compare two based class objects like rectangle and triangle.
   #Create two shape objects using pointers then assign them to rectangle and triangles addresses.
   #So base class' comparison operator will be used.
*/
namespace PatogluShape
{
	class Shape
	{
	public:
		virtual Shape* operator++() = 0;
		virtual Shape* operator++(int) = 0;
		virtual Shape* operator--() = 0;
		virtual Shape* operator--(int) = 0;
		virtual inline double area()const
		{
			return calculatedArea;
		}
		virtual inline double perimeter()const
		{
			return calculatedPerimeter;
		}
		inline bool operator ==(const Shape& shapeObject)const
		{
			int oneCond = shapeObject.area();
			int twoCond = area();
			return (oneCond == twoCond);	
		}
		bool operator !=(const Shape& shapeObject)const
		{
			int oneCond = shapeObject.area();
			int twoCond = area();
			return (oneCond != twoCond);
		}
		bool operator <(const Shape& shapeObject)const
		{
			int oneCond = shapeObject.area();
			int twoCond = area();
			return (oneCond < twoCond);
		}
		bool operator >(const Shape& shapeObject)const
		{
			int oneCond = shapeObject.area();
			int twoCond = area();
			return (oneCond > twoCond);
		}
		friend ostream& operator<<(ostream &out, const Shape &shape)
		{
			return shape.print(out,shape);
		}
		virtual ostream& print(std::ostream& out, const Shape& printedShape) const
		{
			out << "Shape object doesn't return any SVG..." << endl;
			return out;
		}



	protected:	
		double calculatedArea;
		double calculatedPerimeter;
	};	
	//ostream& operator<<(ostream& output, const Shape& shape);
}
#endif /*SHAPE_H_ */