/*HW02 CREATED BY YUSUF PATOGLU - 151044027*/
#include "Rectangle.h"





Rectangle::Rectangle() //default constructor that initializes member variables with random values.
{
	setXCoordinate(0);
	setYCoordinate(0);
	setWidth(20);
	setHeight(10);

}
Rectangle::Rectangle(double xLocation, double yLocation, double width, double height)
{
	setXCoordinate(xLocation); //4 parameter constructor that initializes all variables.
	setYCoordinate(yLocation);
	setWidth(width);
	setHeight(height);
}

double Rectangle::getWidth(void) const //accessor function.
{
	return width;
}

 double Rectangle::getHeight(void) const //accessor function.
{
	return height;
}

double Rectangle::getXCoordinate(void) const //accessor function.
{
	return xCoordinate;
}

double Rectangle::getYCoordinate(void) const //accessor function.
{
	return yCoordinate;
}


void Rectangle::setWidth(double rectangleWidth) //mutator function.
{
	
		width = rectangleWidth;
}

void Rectangle::setHeight(double rectangleHeight) //mutator function.
{
	
		height = rectangleHeight;
	
}
void Rectangle::setXCoordinate(double xLocation) //mutator function.
{
	
		xCoordinate = xLocation;
}

void Rectangle::setYCoordinate(double yLocation) //mutator function.
{
	
		yCoordinate = yLocation;
}
std::string Rectangle::rectangleScript(void) // helper function 
{
	std::string Script;
	Script = std::string("<rect x=\"") + to_string(xCoordinate) + "\"" + " y=\"" + to_string(yCoordinate) + "\""
	+ " width=\"" + to_string(width) + "\"" + " height=\"" + to_string(height) + "\"" + " stroke=\"red\"" +
	 " fill=\"yellow\" " + " />";
	//<rect x="10" y="10" width="30" height="30" stroke="black" fill="transparent" stroke-width="5"/>
	return Script;
} 

void Rectangle::draw(ofstream &inputFile) //drawing function to draw single object to file.
{
	std::string fileWriter;
	fileWriter = rectangleScript();
	inputFile << fileWriter;
	inputFile << "\n";
}


