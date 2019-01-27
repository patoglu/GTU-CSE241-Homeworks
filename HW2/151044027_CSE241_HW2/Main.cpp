/*HW02 CREATED BY YUSUF PATOGLU - 151044027*/

#include <iostream>
#include "ComposedShape.h"
#include "Rectangle.h" //including required libraries.
#include "Circle.h"
#include "Triangle.h"
#include <fstream>

using namespace std;
//test driver file.

int main()
{
	ofstream filePointer; //creating file pointers for different objects. 
	filePointer.open("rectangleIntoRectangle.svg");

	Rectangle myRectangle(0,0,200,200); //Creating rectangle objects. 
	Rectangle yourRectangle(0,0,10,10); //Creating rectangle objects.

	
	ComposedShape rectangleIntoRectangle1(myRectangle, yourRectangle); //testing ComposedShape object.

	rectangleIntoRectangle1.optimalFit(); //testing ComposedShape object.

	rectangleIntoRectangle1.draw(filePointer); //testing ComposedShape object.

	filePointer.close(); //testing ComposedShape object.


	ofstream filePointer2; //creating file pointers for different objects.
	filePointer2.open("rectangleIntoCircle.svg");

	Circle myCircle(0,0,20);

	ComposedShape rectangleIntoCircle = ComposedShape(myRectangle, myCircle);

	rectangleIntoCircle.optimalFit();
	rectangleIntoCircle.draw(filePointer2);
	filePointer2.close();


	ofstream filePointer3; //creating file pointers for different objects.
	filePointer3.open("rectangleIntoTriangle.svg");
	Triangle myTriangle(0,0,0,0,0,0);
	myTriangle.setWidth(20);


	ComposedShape rectangleIntoTriangle = ComposedShape(myRectangle, myTriangle);

	rectangleIntoTriangle.optimalFit();
	rectangleIntoTriangle.draw(filePointer3);
	filePointer3.close();
	ofstream filePointer4; //creating file pointers for different objects.
	filePointer4.open("triangleIntoTriangle.svg");

	Triangle bigTriangle(0,0,0,0,0,0);
	bigTriangle.setWidth(200);
	Triangle smallTriangle(0,0,0,0,0,0);
	smallTriangle.setWidth(10);

	ComposedShape triangleIntoTriangle = ComposedShape(bigTriangle, smallTriangle);
	triangleIntoTriangle.optimalFit();
	triangleIntoTriangle.draw(filePointer4);
	filePointer4.close();
	
	ofstream filePointer5; //creating file pointers for different objects.
	filePointer5.open("triangleIntoRectangle.svg");

	ComposedShape triangleIntoRectangle = ComposedShape(bigTriangle, yourRectangle);

	triangleIntoRectangle.optimalFit();
	triangleIntoRectangle.draw(filePointer5);

	filePointer5.close();

	ofstream filePointer6; //creating file pointers for different objects.

	filePointer6.open("triangleIntoCircle.svg");
	ComposedShape circleIntoTriangle = ComposedShape(bigTriangle, myCircle);
	circleIntoTriangle.optimalFit();
	circleIntoTriangle.draw(filePointer6);

	filePointer6.close();

	ofstream filePointer7; //creating file pointers for different objects.
	filePointer7.open("circleIntoCircle.svg");

	Circle bigCircle(0,0,150);

	ComposedShape circleIntoCircle = ComposedShape(bigCircle, myCircle);

	circleIntoCircle.optimalFit();
	circleIntoCircle.draw(filePointer7);

	filePointer7.close();
	ofstream filePointer8; //creating file pointers for different objects.

	filePointer8.open("circleIntoRectangle.svg");
	Rectangle rectangle(0,0,60,30);
	ComposedShape circleIntoRectangle = ComposedShape(bigCircle, rectangle );
	circleIntoRectangle.optimalFit();
	circleIntoRectangle.draw(filePointer8);
	filePointer8.close();


	ofstream filePointer9; //creating file pointers for different objects.
	filePointer9.open("circleIntoTriangle.svg");

	ComposedShape triangleIntoCircle = ComposedShape(bigCircle, smallTriangle);
	triangleIntoCircle.optimalFit();
	triangleIntoCircle.draw(filePointer9);
	filePointer9.close();



	return 0;
}