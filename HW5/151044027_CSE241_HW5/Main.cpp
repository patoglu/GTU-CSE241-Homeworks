#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Polygon.h"
#include "PolygonDyn.h"
#include "PolygonVect.h"
#include "ComposedShape.h"
#include "Shape.h"

using namespace std;
using namespace PatogluShape;
void sortShapes(vector <Shape*> Shapes);
void printAll(vector <Shape*> Shapes);
void printPoly(vector <Shape*> Shapes);
vector <Shape*> convertAll(vector <Shape*> Shapes);
void sortShapes(vector <Shape*> Shapes);

int main()
{
	PolygonDyn::Point2D point;
	PolygonDyn myPoly(point);

	cout << myPoly << endl;
	cout << point.getTwoDx() << endl;
	cout << point.getTwoDy() << endl;
	Rectangle myRectangle(0,0,10,21);
	PolygonDyn yourPoly(myRectangle);

	cout << myRectangle.area() << endl;
	Rectangle yourRectangle(0,0,21,10);
	Shape *myShape = new Rectangle(0,0,100,3.14);
	Shape *yourShape = new Rectangle(0,0,20,10);
	Shape *shapeOfYou = new Circle(0,0,10);

	cout << "Comparing two functions, yourShape and shapeOfYou Shape objects. They're Rectangle and Circle actually." << endl;
	if(*myShape == *shapeOfYou)
	{
		cout <<"True  " << endl;
	}
	else
	{
		cout << myShape -> area() << endl;
		cout << shapeOfYou -> area() << endl;
	}
	//Circle myCircle(0,0,10);

	cout << "RECT BEGIN" << endl;
	cout << *(++yourRectangle) << endl;
	cout << *(++yourRectangle) << endl;
	cout << *(++yourRectangle) << endl;
	cout << *(++yourRectangle) << endl;
	++yourRectangle;
	cout << yourRectangle << endl;
	cout << *(++yourRectangle) << endl;
	yourRectangle--;
	cout << yourRectangle << endl;
	cout << "RECT END" << endl;

	cout << "CIRC BEGIN" << endl;
	Circle myCircle(0,0,20);
	Circle yourCircle(10,10,20);
	cout << yourCircle << endl;
	cout << myCircle << endl;	

	cout << *(yourCircle++) << endl;
	cout << *(myCircle++) << endl;
	cout << yourCircle << endl;
	cout << myCircle << endl;	
	cout << "CIRC END" << endl;	

	if(myCircle == yourCircle)
	{
		cout << "These are equal m8" << endl;
	}
	else
	{
		cout <<"mmm sorry" << endl;
	}

	cout << "TRI BEGIN" << endl;
	Triangle myTriangle(20);
	Triangle yourTriangle(20);

	cout << myTriangle << endl;
	cout << yourTriangle << endl;
	if(myTriangle == yourTriangle)
	{
		cout << "Areas are equal " << endl;
	}
	else
	{
		cout << "Not really " << endl;
	}
	myTriangle++;
	yourTriangle++;
	cout << myTriangle << endl;
	cout << yourTriangle << endl;
	cout << *(++myTriangle) << endl;
	cout << *(++yourTriangle) << endl;
	cout << "TRI END" << endl;


	cout << "VECT TEST BEGIN " << endl;

	PolygonVect vectPoly;
	cout << vectPoly.getSize() << endl;
	PolygonVect vectPolyRect(myTriangle);
	cout << vectPolyRect << endl;
	cout << vectPoly + vectPolyRect << endl;
	vectPoly = vectPolyRect;
	cout << "Again " << vectPoly << endl;

	
	ofstream filePointer1; //creating file pointers for different objects. 
	filePointer1.open("RectangleRectangle.svg");

	ofstream filePointer2; //creating file pointers for different objects. 
	filePointer2.open("RectangleTriangle.svg");

	ofstream filePointer3; //creating file pointers for different objects. 
	filePointer3.open("RectangleCircle.svg");

	ofstream filePointer4; //creating file pointers for different objects. 
	filePointer4.open("TriangleRectangle.svg");

	ofstream filePointer5; //creating file pointers for different objects. 
	filePointer5.open("TriangleTriangle.svg");

	ofstream filePointer6; //creating file pointers for different objects. 
	filePointer6.open("TriangleCircle.svg");

	ofstream filePointer7; //creating file pointers for different objects. 
	filePointer7.open("CircleRectangle.svg");

	ofstream filePointer8; //creating file pointers for different objects. 
	filePointer8.open("CircleTriangle.svg");

	ofstream filePointer9; //creating file pointers for different objects. 
	filePointer9.open("CircleCircle.svg");

	ofstream filePointer10;
	filePointer10.open("DefaultConsProduce.svg");



	Rectangle bigRectangle(0,0,200,100);
	Rectangle smallRectangle(0,0,10,10);

	Triangle bigTriangle(0,0,0,0,0,0);
	bigTriangle.setWidth(200);
	Triangle smallTriangle(0,0,0,0,0,0);
	smallTriangle.setWidth(10);


	Circle bigCircle(0,0,90);

	Circle smallCircle(0,0,10);

	
	ComposedShape RectangleRectangle(bigRectangle, smallRectangle);


	ComposedShape RectangleTriangle(bigRectangle, smallTriangle);


	ComposedShape RectangleCircle(bigRectangle, smallCircle);


	ComposedShape TriangleRectangle(bigTriangle, smallRectangle);


	ComposedShape TriangleCircle(bigTriangle, smallCircle);


	ComposedShape TriangleTriangle(bigTriangle, smallTriangle);


	ComposedShape CircleRectangle(bigCircle, smallRectangle);


	ComposedShape CircleCircle(bigCircle, smallCircle);


	ComposedShape CircleTriangle(bigCircle, smallTriangle);

	ComposedShape defaultOne;


	RectangleRectangle.optimalFit();
	RectangleTriangle.optimalFit();
	RectangleCircle.optimalFit();
	TriangleRectangle.optimalFit();
	TriangleTriangle.optimalFit();
	TriangleCircle.optimalFit();
	CircleRectangle.optimalFit();
	CircleTriangle.optimalFit();
	CircleCircle.optimalFit();
	defaultOne.optimalFit();


	defaultOne.draw(filePointer10);
	
	RectangleRectangle.draw(filePointer1);
	RectangleTriangle.draw(filePointer2);
	RectangleCircle.draw(filePointer3);


	TriangleRectangle.draw(filePointer4);
	TriangleTriangle.draw(filePointer5);
	TriangleCircle.draw(filePointer6);

	CircleRectangle.draw(filePointer7);
	CircleTriangle.draw(filePointer8);
	CircleCircle.draw(filePointer9);

	cout << "POLYGONVECT TEST BEGIN" << endl;

	PolygonVect myPolyVec(myRectangle);
	cout << "Printing myPolyVec " << endl;
	cout << myPolyVec << endl;
	PolygonVect yourPolyVec(yourRectangle);

	cout << "TESTING COMPARISON OPERATORS OF POLYGON" << endl;

	if(myPolyVec == yourPolyVec)
	{
		cout << "These are equal" << endl;
	}
	else
	{
		cout << "These are not equal" << endl;
	}
	cout << "Now assigning them to each other they must be equal.." << endl;

	myPolyVec = yourPolyVec;


	if(myPolyVec == yourPolyVec)
	{
		cout << "These are equal" << endl;
	}
	else
	{
		cout << "These are not equal" << endl;
	}


	cout << "Testing + operator of Vector polygons " << endl;

	myPolyVec = myPolyVec + yourPolyVec;

	cout << "Printing myPolyVec + yourPolyVec = " << myPolyVec << endl;

	cout << "POLYGONDYN TEST BEGIN" << endl;


	PolygonDyn myPolyDyn(myRectangle);
	cout << "Printing myPolyDyn " << endl;
	cout << myPolyDyn << endl;
	PolygonDyn yourPolyDyn(yourRectangle);

	cout << "TESTING COMPARISON OPERATORS OF POLYGON" << endl;

	if(myPolyDyn == yourPolyDyn)
	{
		cout << "These are equal" << endl;
	}
	else
	{
		cout << "These are not equal" << endl;
	}
	cout << "Now assigning them to each other they must be equal.." << endl;

	myPolyDyn = yourPolyDyn;


	if(myPolyDyn == yourPolyDyn)
	{
		cout << "These are equal" << endl;
	}
	else
	{
		cout << "These are not equal" << endl;
	}

	cout << "Creating array of random Polygons" << endl;

	PolygonDyn arrayPoly[5];

	for (int i = 0; i < 5; ++i)
	{
		arrayPoly[i] = yourPolyDyn;
		cout << arrayPoly[i] << endl;
	}


	vector <Shape*> myShapeVector;
	myShapeVector = RectangleCircle.getShapeVect();

	for(auto i = 0 ; i < myShapeVector.size() ; ++i)
	{
		cout << myShapeVector.size() << endl;;
		cout << *(myShapeVector[i]) << endl;
	}

	printAll(myShapeVector);

	vector <Shape*> myShapeVector2;
	myShapeVector2 = convertAll(myShapeVector);
	return 0;
}

void printAll(vector <Shape*> Shapes) // You can print all shapes with this. Just send the required Shape vector.
{
	ofstream filePointer1; //creating file pointers for different objects. 
	filePointer1.open("RectangleCircleGLOBAL.svg");
	string Script = std::string("<?xml version=\"1.0\" standalone=\"no\"?>" )+ "\n" +
		+ "<svg width=\"300\" height=\"300\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">";
	filePointer1 << Script << endl;	
	for(auto i = 0 ; i < Shapes.size() ; ++i)
	{
		filePointer1 << *(Shapes[i]) << endl;
	}
	filePointer1 << "</svg>";

}

vector <Shape*> convertAll(vector <Shape*> Shapes)
{
	vector <PolygonVect*> returnShapes;
	returnShapes.resize(Shapes.size());
	for(auto i = 0; i < Shapes.size() ; ++i)
	{
		//returnShapes[i] = &Shapes[i];
	}

	return Shapes;
}

void sortShapes(vector <Shape*> Shapes)
{
	/*for(auto i = 0; i < Shapes.size() ; ++i)
	{
		for(auto j = 0; j < Shapes.size() ; ++j)
		{
			if(Shapes[i].Area() < Shapes[i+1].Area())
			{
				Shape* tempShape;
				Shapes[i] = Shapes[i+1];
			}
		}
	}
	*/
}