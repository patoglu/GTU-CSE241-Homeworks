
/*HW02 CREATED BY YUSUF PATOGLU - 151044027*/
#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_
#include <vector>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Polygon.h"
//enum Shapes {rectangle, triangle, circle};

using namespace PatogluTriangle;
using namespace PatogluRectangle;
using namespace PatogluCircle;
using namespace PatogluPolygon;

namespace PatogluComposedShape
{
	class ComposedShape
	{
	//class ShapeElem;
	public:
		ComposedShape(); //Default Constructor for ComposedShape
		//in my model, I will create 9 different two parameter constructors.
		//which takes different type of objects to apply nine different combinations.
		//I have tested two simple constructors, one takes int and double 
		//other takes double and int in order.
		ComposedShape(Rectangle outerRectangle, Rectangle innerRectangle);
		ComposedShape(Rectangle outerRectangle, Triangle innerTriangle);
		ComposedShape(Rectangle outerRectangle, Circle innerCircle);
		ComposedShape(Triangle outerTriangle, Triangle innerTriangle);
		ComposedShape(Triangle outerTriangle, Rectangle innerRectangle);
		ComposedShape(Triangle outerTriangle, Circle innerCircle);
		ComposedShape(Circle outerCircle, Circle innerCircle);
		ComposedShape(Circle outerCircle, Triangle innerTriangle);
		ComposedShape(Circle outerCircle, Rectangle innerRectangle);
		//const ComposedShape operator +=(const ShapeElem& shape);
		void optimalFit(void); //optimal fit function that fills shapes to vectors carefully.
		//my draw function draws the bigger shape for one time. After that calls vector of shapes one by one.
		//then they calling their draw function.
		void draw(std::ofstream &inputFile); 
		/*class ShapeElem
		{
		public:
			//ShapeElem();
			ShapeElem(const Rectangle &rect)
			{
				//anyShape = rect;
				//gelen rectangle i void pointer a ata.
				//anyShapeType = rectangle;
				//enumi set et.

			}
			ShapeElem(const Triangle &tri)
			{
				//anyShape = tri;
				//anyShapeType = triangle;
			}
			ShapeElem(const Circle &circ)
			{
				//anyShape = circ;
				//anyShapeType = circle;

			}
			double getPer()//sonuc = anyShape
			{	
				/*if(anyShapeType == rectangle)
				{
					return (Rectangle*)(anyShape)->getPerimeter();
				}
				else if(anyShapeType == triangle)
				{
					return (Triangle*)(anyShape)->getPerimeter();
				}
				else if(anyShapeType == circle)
				{
					return (Circle*)(anyShape)->getPerimeter();
				}*/
				
			//}
			//double getSpace()
			//{
				/*if(anyShapeType == rectangle)
				{
					return (Rectangle*)(anyShape)->getArea();
				}
				else if(anyShapeType == triangle)
				{
					return (Triangle*)(anyShape)->getArea();
				}
				else if(anyShapeType == circle)
				{
					return (Circle*)(anyShape)->getArea();
				}*/
			//}

			/*friend ostream& operator<<(ostream& output)
			{
				if(anyShapeType == rectangle)
				{
					ostream << (Rectangle*)(anyShape);
					return ostream;
				}
				else if(anyShapeType == triangle)
				{
					ostream << (Triangle*)(anyShape);
					return ostream;
				}
				else if(anyShapeType == circle)
				{
					ostream << (Circle*)(anyShape);
					return ostream;
				}
			}*/
		//private:
			//void *anyShape;
			//Shapes anyShapeType;
		//};

	private:
		
		bool oRiR = false; //flag members to make our fit and draw process easier.
		bool oRiT = false; //all setted false for default.
		bool oRiC = false; 
		bool oTiR = false; 
		bool oTiC = false; 
		bool oTiT = false; 
		bool oCiR = false; 
		bool oCiC = false;
		bool oCiT = false; 
		
		//ShapeElem bigShape;
		//ShapeElem smallShape;
		Rectangle myOuterRectangle;
		Rectangle myInnerRectangle;
		//Rectangle object for small shape.
		

		Triangle myOuterTriangle; //Triangle object for big shape
		Triangle myInnerTriangle; //Triangle object for small shape.

		Circle myOuterCircle; //Circle object for big shape.
		Circle myInnerCircle; //Circle object for small shape.

		vector <Polygon> shapesConnected;


		string beginningScript(void); //helper file functions.
		string endScript(void); //helper file functions.
	};




	/* 

	1
	2
	3
	4
	5
	*/

}

#endif /*COMPOSEDSHAPE*/