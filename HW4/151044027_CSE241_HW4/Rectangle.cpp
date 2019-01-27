/*HW02 CREATED BY YUSUF PATOGLU - 151044027*/
#include "Rectangle.h"

// UNNAMED NAMESPACE 
namespace
{
	bool checkCoordinateX(double theXCoordinate)
	{
		if(theXCoordinate < 0)
			return false;
		return true;
	}

	bool checkCoordinateY(double theYCoordinate)
	{
		if(theYCoordinate < 0)
			return false;
		return true;
	}
}
namespace PatogluRectangle
{
	double Rectangle::totalPerimeter = 0;
	double Rectangle::totalArea = 0;
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
		totalPerimeter += 2 * (width + height);
		totalArea += width * height;

	}

	//THEY ARE INLINE NOW.
	/*
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
	*/

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

	double Rectangle::getPerimeter(void) const
	{
		return 2 * (width + height);
	}
	double Rectangle::getArea(void) const
	{
		return width * height;
	}
	std::string Rectangle::rectangleScript(void) const // helper function 
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


	Rectangle Rectangle::operator++()
	{
		xCoordinate++;//Incrementing coordinates.
		yCoordinate++;//Incrementing coordinates.

		return Rectangle(xCoordinate, yCoordinate, width, height); //Returning new object.

	}
	Rectangle Rectangle::operator++(int ignoreThat)
	{
		double temp1 = xCoordinate;//Incrementing coordinates in temp values.
		double temp2 = yCoordinate;//Incrementing coordinates in temp values.

		xCoordinate++;
		yCoordinate++;

		return Rectangle(temp1, temp2, width, height); //Returning new object.
	}
	const Rectangle Rectangle::operator+(const double incrementSize) const
	{
		double tempWidth;
		double tempHeight;

		tempWidth = width + incrementSize;//Adding scalar variable to our width and height.
		tempHeight = height + incrementSize;//Adding scalar variable to our width and height.

		return Rectangle(xCoordinate,yCoordinate, tempWidth, tempHeight); //returning new object.

	}
	Rectangle Rectangle::operator--()
	{
		xCoordinate--;
		yCoordinate--;

		return Rectangle(xCoordinate, yCoordinate, width, height); //Returning new object

	}
	Rectangle Rectangle::operator--(int ignoreThat)
	{
		double temp1 = xCoordinate;
		double temp2 = yCoordinate;

		xCoordinate--;
		yCoordinate--;

		return Rectangle(temp1, temp2, width, height); //Returning object.
	}
	const Rectangle Rectangle::operator-(double decrementSize) const
	{
		int tempHeight;
		int tempWidth;
		if((decrementSize > width) || (decrementSize > height))
		{
			cout << "Decrement size is bigger than shapes value." << endl;
			return Rectangle(xCoordinate,yCoordinate, width, height);
		}
		else
		{
			tempHeight = height - decrementSize;
			tempWidth = width - decrementSize; 
			return Rectangle(xCoordinate, yCoordinate, tempWidth, tempHeight); //Returning new object.
		}
	}
	bool Rectangle::operator ==(const Rectangle& secondParameter) const
	{
		double tempWidth;
		double tempHeight;
		bool firstControl;
		bool secondControl;



		tempWidth = secondParameter.width;
		tempHeight = secondParameter.height;

		if(tempWidth * tempHeight == width * height)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Rectangle::operator !=(const Rectangle& secondParameter) const
	{
		double tempWidth;
		double tempHeight;
		bool firstControl;
		bool secondControl;



		tempWidth = secondParameter.width;
		tempHeight = secondParameter.height;

		if(tempWidth * tempHeight != width * height)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	ostream& operator<<(ostream& output, const Rectangle& rectangle)
	{
		output << rectangle.rectangleScript();
		return output;
	}


	double Rectangle::getTotalPerimeter(void)
	{
		return totalPerimeter;
	}
	double Rectangle::getTotalArea(void)
	{
		return totalArea;
	}

}


