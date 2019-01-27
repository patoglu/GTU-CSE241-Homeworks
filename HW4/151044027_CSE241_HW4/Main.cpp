#include <iostream>
#include "Polyline.h"
#include "Polygon.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "ComposedShape.h"

using namespace std;
using namespace PatogluTriangle;
using namespace PatogluRectangle;
using namespace PatogluCircle;
using namespace PatogluComposedShape;
using namespace PatogluPolygon;
using namespace PatogluPolyline;

void polyLineTest();
int main()
{

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

	cout << " TESTING POLYGON FUNCTIONS. " << endl;

	vector <Polygon::Point2D> billieJean;


	Polygon::Point2D point;



	point.setTwoDx(10);
	point.setTwoDy(20);


	billieJean.push_back(point);

	Polygon::Point2D point2;
	point2.setTwoDx(5);
	point.setTwoDy(10);
	billieJean.push_back(point2);

	vector <Polygon::Point2D> beatIt;

	point.setTwoDx(50);
	point.setTwoDy(100);

	point2.setTwoDx(100);
	point2.setTwoDy(200);

	beatIt.push_back(point);

	beatIt.push_back(point2);

	Polygon myPoly(billieJean);
	Polygon yourPoly(beatIt);




	cout << "myPoly is " << myPoly << endl;

	cout << "yourPoly is " << yourPoly << endl;

	Polygon alonePoly = myPoly + yourPoly;

	cout << "alonePoly is " << alonePoly << endl;


	polyLineTest();


	Polygon arrayOfPolygons[5];

	ComposedShape arrayOfComposedShape[5];


	cout << "Testing == operator" << endl;

	if(myPoly == yourPoly)
	{
		cout << "They're equal" << endl;
	}
	else
	{
		cout << "They're not equal." << endl;
	}

	cout <<"Let's create two equal polygon objects" << endl;

	Polygon p1,p2;

	if(p1 == p2)
	{
		cout << "They're equal" << endl;
	}
	else
	{
		cout << "They're not equal" << endl;
	}

	cout << "Testing three shape conversion constructors..." << endl;


	Polygon rectPoly(bigRectangle);
	Polygon triPoly(bigTriangle);
	Polygon circlePoly(bigCircle);

	cout << "RECT POLY HAS : " << endl;

	cout << rectPoly << endl;

	cout << "TRI POLY HAS : " << endl;


	cout << triPoly << endl;

	cout << "CIRCLE POLY HAS : " << endl;

	cout << circlePoly << endl;

	cout << "Testing assignment operator. " << endl;

	rectPoly = circlePoly;
	cout << "\n\n\n";
	cout << "Now printing rectPoly which became a circle poly." << endl;

	cout << "\n\n\n";
	cout << rectPoly << endl;
	cout << "\n\n\n";

	cout << "Testing array operator of Polygon...." << endl;

	cout << circlePoly[0] << endl;
	cout << circlePoly[1] << endl;
	cout << circlePoly[2] << endl;
	cout << circlePoly[3] << endl;
	cout << circlePoly[4] << endl;
	cout << circlePoly[5] << endl;


	cout << "Polyline tests made in polyLineTest function. So calling polyLineTest() function" << endl;



	polyLineTest();





	return 0;
}

void polyLineTest()
{

	ofstream filePointer;
	filePointer.open("Polyline.svg");

	vector <Polyline::Point2D> polyLineVector;


	Polyline::Point2D point3;
	Polyline::Point2D point4;



	Polyline::Point2D point5;
	Polyline::Point2D point6;


	Polyline::Point2D point7;
	Polyline::Point2D point8;


	Polyline::Point2D point9;
	Polyline::Point2D point10;


	
	point3.setTwoDx(10);
	point3.setTwoDy(10);

	point4.setTwoDx(43);
	point4.setTwoDy(34);

	point5.setTwoDx(65);
	point5.setTwoDy(65);


	point6.setTwoDx(89);
	point6.setTwoDy(90);

	point7.setTwoDx(123);
	point7.setTwoDy(123);

	point8.setTwoDx(155);
	point8.setTwoDy(147);

	point9.setTwoDx(198);
	point9.setTwoDy(189);

	point10.setTwoDx(231);
	point10.setTwoDy(253);



	polyLineVector.push_back(point3);
	polyLineVector.push_back(point4);

	polyLineVector.push_back(point5);
	polyLineVector.push_back(point6);

	polyLineVector.push_back(point7);
	polyLineVector.push_back(point8);

	polyLineVector.push_back(point9);
	polyLineVector.push_back(point10);

	Polyline newPolyline(polyLineVector);
	filePointer << "<?xml version=\"1.0\" standalone=\"no\"?> <svg width=\"300\" height=\"300\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;


	filePointer << newPolyline << endl;

	filePointer << "</svg>";

	Polyline oldPolyLine(polyLineVector);

	cout << "both polylines are equal. Testing == operator." << endl;


	if(newPolyline == oldPolyLine)
	{
		cout << "both equal " << endl;
	}
	else
		cout << "not equal " << endl;

	cout << "Adding new element to newPolyline so they'll not equal" << endl;
	polyLineVector.push_back(point9);
	polyLineVector.push_back(point10);
	Polyline newnewPolyline(polyLineVector);

	if(newnewPolyline == oldPolyLine)
	{
		cout << "both equal " << endl;
	}
	else
		cout << "not equal " << endl;


	cout << "Testing << operator"  << endl;

	cout << newnewPolyline << endl;


	cout << "Testing + operator " << endl;

	cout << newnewPolyline + oldPolyLine << endl;


	cout << "Testing = operator " << endl;

	newnewPolyline= oldPolyLine;

	cout << newnewPolyline << endl;
	
}