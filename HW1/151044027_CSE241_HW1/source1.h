#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#ifndef SOURCE1_H
#define SOURCE1_H
using namespace std;
const int PI = 3.14; //constant for PI
char getCharInput(void); //gets only one character from user. Other different user enter situations are all handled.
void rectangleInput(double& width, double& height); //gets required inputs, errors handled.
void triangleInput(double& width);//gets required inputs, errors handled.
void circleInput(double& radius);//gets required inputs, errors handled.
void drawCircleIntoRectangle(double bigHeight, double bigWidth, double radius); //draws circle into rectangle
void drawRectangleIntoRectangle(double bigHeight, double bigWidth, double smallHeight, double smallWidth); // draws rectangle into rectangle
void drawTriangleIntoRectangle(double bigHeight, double bigWidth, double smallWidth); // drawsTriangleIntoRectangle
void drawTriangleIntoTriangle(double bigWidth, double smallWidth); //draws triangle into triangle
void drawRectangleIntoTriangle(double bigWidth, double smallWidth, double smallHeight); // draws rectangle into triangle
void drawCircleIntoTriangle(double bigWidth, double radius); //draws circle into triangle
void drawCircleIntoCircle(double bigRadius, double smallRadius); // draws circle into circle
void drawRectangleIntoCircle(double bigRadius, double smallHeight, double smallWidth); // draws rectangle into circle
void drawTriangleIntoCircle(double bigRadius, double smallWidth); // draws triangle into circle.
void drawShapes(char mainContainer, char smallContainer, double bigWidth, double bigHeight, double bigRadius,
				double smallWidth, double smallHeight, double smallRadius); //drawing shapes function
string beginningScript(void); // returns string with xml format
string endScript(void); // returns string with xml format
string rectangleScript(double width, double height, double xCoordinate, double yCoordinate); // returns rectangle script
string triangleScript(double x1, double y1, double x2, double y2, double x3, double y3); // returns triangle script
string circleScript(double radius, double xCoordinate, double yCoordinate); // returns circle script.

#endif //SOURCE1_H