
/*HW02 CREATED BY YUSUF PATOGLU - 151044027*/
#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_
#include <vector>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
class ComposedShape
{
public:
	ComposedShape(); //Default Constructor for ComposedShape
	//in my model, I will create 9 different two parameter constructors.
	//which takes different type of objects to apply nine different combinations.
	//I have tested two simple constructors, one takes int and double 
	//other takes double and int in order.
	//It acts like two different constructors so I decided to make this model.
	ComposedShape(Rectangle outerRectangle, Rectangle innerRectangle);
	ComposedShape(Rectangle outerRectangle, Triangle innerTriangle);
	ComposedShape(Rectangle outerRectangle, Circle innerCircle);
	ComposedShape(Triangle outerTriangle, Triangle innerTriangle);
	ComposedShape(Triangle outerTriangle, Rectangle innerRectangle);
	ComposedShape(Triangle outerTriangle, Circle innerCircle);
	ComposedShape(Circle outerCircle, Circle innerCircle);
	ComposedShape(Circle outerCircle, Triangle innerTriangle);
	ComposedShape(Circle outerCircle, Rectangle innerRectangle);
	void optimalFit(void); //optimal fit function that fills shapes to vectors carefully.
	//my draw function draws the bigger shape for one time. After that calls vector of shapes one by one.
	//then they calling their draw function.
	void draw(std::ofstream &inputFile); 

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
	
	Rectangle myOuterRectangle; //Rectangle object for big shape.
	Rectangle myInnerRectangle; //Rectangle object for small shape.
	vector <Rectangle> myRectangleVector; //Vectors of rectangles.

	Triangle myOuterTriangle; //Triangle object for big shape
	Triangle myInnerTriangle; //Triangle object for small shape.
	vector <Triangle> myTriangleVector; //Vectors of triangles.

	Circle myOuterCircle; //Circle object for big shape.
	Circle myInnerCircle; //Circle object for small shape.
	vector <Circle> myCircleVector; //Vectors if circless.

	string beginningScript(void); //helper file functions.
	string endScript(void); //helper file functions.
};






#endif /*COMPOSEDSHAPE*/