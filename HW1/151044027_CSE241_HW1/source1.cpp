#include "source1.h"
using namespace std;
void drawShapes(char mainContainer, char smallContainer, double bigWidth, double bigHeight, double bigRadius,
				double smallWidth, double smallHeight, double smallRadius)
{
	//R C T
	//R C T
	/*Here I will declare situations for all cases.
	 * There will be 9 total situations.
	 * I will define 9 different specific functions for all situations,
	 * I will call these functions inside this function.
	 * This will help me prevent doing calculating errors for shapes
	 * So I can be more specific on shapes calculations.
	 */
	//this condition for rectangle inside rectangle.
	if(mainContainer == 'R' && smallContainer == 'R')
	{
		drawRectangleIntoRectangle(bigHeight, bigWidth, smallHeight, smallWidth);
	}
	//this condition for rectangle inside circle.
	else if (mainContainer == 'R' && smallContainer == 'C')
	{
		drawCircleIntoRectangle(bigHeight, bigWidth, smallRadius);
	}
	//this condition for rectangle inside triangle.
	else if (mainContainer == 'R' && smallContainer == 'T')
	{
		drawTriangleIntoRectangle(bigHeight, bigWidth, smallWidth);
	}
	//this condition for circle inside rectangle.
	else if (mainContainer == 'C' && smallContainer == 'R')
	{
		drawRectangleIntoCircle(bigRadius, smallHeight, smallWidth);

	}
	//this condition for circle inside circle.
	else if (mainContainer == 'C' && smallContainer == 'C')
	{
		drawCircleIntoCircle(bigRadius, smallRadius);
	}
	//this condition for circle inside triangle.
	else if (mainContainer == 'C' && smallContainer == 'T')
	{

	}
	////this condition for triangle inside rectangle.
	else if (mainContainer == 'T' && smallContainer == 'R')
	{
		drawRectangleIntoTriangle(bigWidth, smallWidth, smallHeight);

	}
	//this condition for triangle inside circle.
	else if (mainContainer == 'T' && smallContainer == 'C')
	{
		drawCircleIntoTriangle(bigWidth, smallRadius);
	}
	//this condition for triangle inside triangle.
	else
	{
		drawTriangleIntoTriangle(bigWidth, smallWidth);
	}
}

void rectangleInput(double& width, double& height) // error handling mechanism for rectangle input.
{
	cout << "Please enter the width";
	cin >> width;
	if(width < 0)
	{
		cout << "Width can not be smaller than zero! Exiting program...";
		exit(0);
	}
	else if(cin.fail())
	{


		cout << "Please enter only numbers for width input. Exiting program...";
		exit(0);
	}


	cout << "Please enter the height";
	cin >> height;
	if(height < 0)
	{
		cout << "Height can not be smaller than zero! Exiting program...";
		exit(0);
	}
	else if(cin.fail())
	{
		cout << "Please enter only numbers for height input. Exiting program...";
		exit(0);
	}

}
void triangleInput(double& width) //error handling mechanism for triangle input.
{
	cout << "Please enter the width";
	cin >> width;
	if(width < 0)
	{
		cout << "Width can not be smaller than zero! Exiting program...";
		exit(0);
	}
	else if(cin.fail())
	{
		cout << "Please enter only numbers for width input. Exiting program...";
		exit(0);
	}
}
void circleInput(double& radius) // error handling mechanism for circle input.
{
	cout << "Please enter the radius";
	cin >> radius;
	if(radius < 0)
	{
		cout << "radius can not be smaller than zero! Exiting program...";
		exit(0);
	}
	else if(cin.fail())
	{
		cout << "Please enter only numbers for radius input. Exiting program...";
		exit(0);
	}
}

char getCharInput(void) //getting valid inputs from user. If wrong data type or input entered loop continues until true input.
{
	bool flag = true;
	bool upperCaseFlag = true;
	string userInput;
	char charInput;
	while(flag){
		if(upperCaseFlag)
		{
			//this is nice
		}
		cin >> userInput;
		if(userInput.length() > 1) //checks user input greater than one or not.
			cout << "Please enter only char!" << endl;
		else
		{
			charInput = userInput[0];
			if(charInput == 'R' || charInput == 'C' || charInput == 'T')
			{
				flag = false;
			}
				else
				{
					upperCaseFlag = false;
					cout << "Please enter only R, C or T with upper case letters." << endl;
				}
		}
	}
	return charInput;
}
void drawCircleIntoRectangle(double bigHeight, double bigWidth, double radius)
{
	ofstream outfile;
	outfile.open("output.svg"); //opens file
	string fileWriter;
	double xCoordinate, yCoordinate;
	int xCounter, yCounter;
	

	xCounter = (bigWidth / (radius*2));
	yCounter = (bigHeight / (radius*2));
	int smallShapeCount = xCounter * yCounter;

	cout << "I can fit at most " << smallShapeCount << " small shapes into the main container. The empty area in container is ";
	cout << bigHeight * bigWidth - (smallShapeCount * PI * radius * radius) << ".\n";


	xCoordinate = radius; //setting initial radius
	yCoordinate = radius; 

	fileWriter = beginningScript(); //writes beginning script to file

	outfile << fileWriter;
	outfile << "\n";

	if(radius * 2 > bigHeight || radius * 2 > bigWidth)
	{
		cout << "Can't fit that circle into Rectangle...\n"; //program exits on invalid situation.
		exit(0);
	}
	else
	{
		fileWriter = rectangleScript(bigWidth, bigHeight, 0,0);
		outfile << fileWriter;
		outfile << "\n";

		for(int i = 0 ; i < yCounter ; ++i) //main iteration that calculates most circles into rectangle.
		{
			for(int j = 0 ; j < xCounter ; ++j)
			{
				fileWriter = circleScript(radius, xCoordinate, yCoordinate);
				outfile << fileWriter;
				outfile << "\n";
				xCoordinate += 2 * radius; //incerements x coordinate
			}
			xCoordinate = radius;
			yCoordinate += 2 * radius; // increments y coordinate.
		}



	}
	fileWriter = endScript();
	outfile << endScript(); //writes endscript to file
	outfile.close(); // closes file
}
void drawTriangleIntoRectangle(double bigHeight, double bigWidth, double smallWidth)
{
	double x1, y1;
	double x2, y2;
	double x3, y3;
	bool flag = true;
	int xCounter = 0;
	double smallWidthHeight = ((smallWidth / 2.0) * sqrt(3)); //setting initial values.
	int heightCounter = bigHeight / smallWidthHeight;
	int widthCounter = bigWidth / smallWidth;

	ofstream outfile; //opening file
	string fileWriter;
	outfile.open("output.svg");


	x1 = smallWidth / 2.0; //setting initial values for triangles all coordinates.
	y1 = 0;
	x2 = 0;
	y2 = smallWidthHeight;
	x3 = smallWidth;
	y3 = smallWidthHeight;

	fileWriter = beginningScript(); //writing beginning script to file
	outfile << fileWriter;
	outfile << "\n";
	fileWriter = rectangleScript(bigWidth, bigHeight, 0, 0); //writing maincontainers script to file
	outfile << fileWriter;
	outfile << "\n";
	for(int j = 0 ; j < heightCounter ; ++j) //main iteration to fit small shapes.
	{
		for(int i = 0 ; i < widthCounter ; ++i)
		{
			flag = true;
			fileWriter = triangleScript(x1,y1,x2,y2,x3,y3); // writes small triangle shapes.
			outfile << fileWriter;
			outfile << "\n";
			if(bigWidth - x1 >= smallWidth)
			{
				flag = false;
				xCounter++;
				fileWriter = triangleScript(x1,y1,x3,y3,x1 + smallWidth, y1); // writes small reversed triangle shapes.
				outfile << fileWriter;
				outfile << "\n";
			}


			x1 += smallWidth; //updating x values of triangles.
			x2 += smallWidth;
			x3 += smallWidth;
		}
		x1 = smallWidth / 2.0;
		y1 += (smallWidthHeight);
		x2 = 0;
		x3 = smallWidth;
		y2 += (smallWidthHeight);
		y3 += (smallWidthHeight); //updating y values of triangles.
	}
	if(flag == true) // if last shape is not reverse triangle then handle calculating remaining area with using flag.
	{
		cout << "I can fit at most " << heightCounter * (widthCounter - 2) * 2 << " small shapes into the main container. The empty area in container is ";
		cout << bigHeight * bigWidth - heightCounter *(widthCounter - 2) * smallWidth * smallWidthHeight  << ".\n";
	}
	else
	{
		cout << "I can fit at most " << heightCounter * (widthCounter) * 2 << " small shapes into the main container. The empty area in container is ";
		cout << bigHeight * bigWidth - heightCounter *(widthCounter) * smallWidth * smallWidthHeight  << ".\n";
	}
	


	fileWriter = endScript(); //writes end script.
	outfile << fileWriter;
	outfile.close(); //closes file.

}
void drawRectangleIntoRectangle(double bigHeight, double bigWidth, double smallHeight, double smallWidth)
{
	ofstream outfile;
	outfile.open("output.svg"); //opens file
	string fileWriter;
	double xCoordinate = 0, yCoordinate = 0;

	double tempSmallWidth = smallHeight; //to determine best case.
	double tempSmallHeight = smallWidth; // to determine best case.

	int xCounter, yCounter; //first case
	int xCounter2, yCounter2; //other case
	cout << bigWidth << " " << bigHeight << endl;
	cout << smallWidth <<" " << smallHeight << endl;


	xCounter = bigWidth / smallWidth;
	yCounter = bigHeight / smallHeight;

	xCounter2 = bigWidth / tempSmallWidth;
	yCounter2 = bigHeight / tempSmallHeight;

	if((xCounter * yCounter ) < (xCounter2 * yCounter2))
	{
		smallHeight = tempSmallHeight; //sets correct values to width and height.
		smallWidth = tempSmallWidth;
		xCounter = xCounter2;
		yCounter = yCounter2;
	}


	fileWriter = beginningScript(); //writes beginning script to file.

	outfile << fileWriter;
	outfile << "\n";
	fileWriter = rectangleScript(bigWidth, bigHeight, xCoordinate, yCoordinate);
	outfile << fileWriter;
	outfile << "\n";
	for(int i = 0 ; i < yCounter ; ++i) //main iteration to fits small shapes.
	{
		for(int j = 0 ; j < xCounter ; ++j)
		{
			
			fileWriter = rectangleScript(smallWidth, smallHeight, xCoordinate, yCoordinate);
			outfile << fileWriter;
			outfile << "\n";
			xCoordinate += smallWidth; //updating xcoordinate.
		}
		yCoordinate += smallHeight; //updating ycoordinate.
		xCoordinate = 0;
	}
	cout << "I can fit at most " <<  xCounter * yCounter << " small shapes into the main container. The empty area in container is ";
	cout << bigWidth * bigHeight - xCounter * yCounter * smallWidth * smallHeight<< ".\n"; //printing shape count and 
																						   // remaining area.

	fileWriter = endScript();
	outfile << endScript(); //writes end script to file.

	outfile.close(); // closes file.

}

void drawTriangleIntoTriangle(double bigWidth, double smallWidth)
{
	int triangleCounter = 0;
	double x1, y1;
	double x2, y2;
	double x3, y3;
	int k = 1;
	ofstream outfile;
	outfile.open("output.svg");
	string fileWriter;
	int triangleCount = bigWidth / smallWidth;
	int tempTriangleCount = triangleCount;
	double bigTriangleHeight = ((bigWidth / 2.0) * sqrt(3));
	double smallTriangleHeight =  ((smallWidth / 2.0) * sqrt(3)); // calculating initial values of coordinates.



	fileWriter = beginningScript(); //writes beginning script to a file.

	outfile << fileWriter;
	outfile << "\n";
	fileWriter = triangleScript(bigWidth / 2.0, 0, 0, bigTriangleHeight, bigWidth, bigTriangleHeight); //writes main shape to a file
	outfile << fileWriter;
	outfile << "\n";
	x1 = smallWidth / 2.0;
	y1 = bigTriangleHeight - smallTriangleHeight;
	x2 = 0;
	y2 = bigTriangleHeight;
	x3 = smallWidth;
	y3 = bigTriangleHeight;
	for(int j = 0 ; j < triangleCount ; j++) //mainiteration
	{
		for(int i =  0 ; i  < tempTriangleCount ; i++)
		{
			fileWriter = triangleScript(x1,y1,x2,y2,x3,y3);
			outfile << fileWriter;
			outfile << "\n";
			if(i == tempTriangleCount - 1)
			{
				//handles the overflow shape situation
			}
			else
			{
				fileWriter = triangleScript(x1,y1,x3,y3,x1 + smallWidth, y1);
				outfile << fileWriter;
				outfile << "\n";
			}
			
			x1 += smallWidth; //updates the x values.
			x2 += smallWidth; 
			x3 += smallWidth;

		}
		triangleCounter+=tempTriangleCount;
		triangleCounter+=tempTriangleCount - 1;  //calculates the triangle count.
		tempTriangleCount--;

	x1 = (smallWidth / 2.0) * k + smallWidth / 2.0;
	y1 -= smallTriangleHeight;
	x2 = (smallWidth / 2.0) * k;
	y2 -= smallTriangleHeight;
	x3 = (smallWidth / 2.0) * k + smallWidth;
	y3 -= smallTriangleHeight;
	k++;
	}
	double bigSpace =  ((bigWidth * bigWidth * sqrt(3)) / 4.0);
	double smallSpace = triangleCounter * ((smallWidth * smallWidth * sqrt(3)) / 4.0);
	cout << "I can fit at most " <<  triangleCounter << " small shapes into the main container. The empty area in container is ";
	cout << bigSpace - smallSpace << ".\n";
	
	fileWriter = endScript(); //writes end script to file.

	outfile << fileWriter;
	outfile.close(); // closes the file


}


void drawRectangleIntoTriangle(double bigWidth, double smallWidth, double smallHeight)
{
	int xCount, yCount;
	int k = 1;
	
	int rectangleCounter = 0;

	ofstream outfile;
	outfile.open("output.svg"); // opens the file
	string fileWriter;
	fileWriter = beginningScript(); //writes beginning script.
	outfile << fileWriter;
	outfile << "\n";
	double tempSmallHeight = smallHeight;
	double sides = (sqrt(3) * smallHeight) * 2.0 / 3.0;
	double bigTriangleHeight = ((bigWidth / 2.0) * sqrt(3));
	double startingPointX = (sqrt(3) * smallHeight) / 3.0;
	double tempStartingPointX = startingPointX;
	double tempBigWidth = bigWidth;


	yCount = bigTriangleHeight / smallHeight;
	xCount = (bigWidth - sides) / smallWidth;

	fileWriter = triangleScript(bigWidth / 2.0, 0, 0, bigTriangleHeight, bigWidth, bigTriangleHeight);
	outfile << fileWriter;
	outfile << "\n";
	for(int j = 0 ; j < yCount; ++j) //main iteration
	{
		for(int i = 0 ; i < xCount ; ++i)
		{
				fileWriter = rectangleScript(smallWidth, tempSmallHeight,startingPointX, bigTriangleHeight - smallHeight);
				outfile << fileWriter;
				outfile << "\n";

			
			startingPointX += smallWidth;
		}
		rectangleCounter += xCount;
		k++;
		xCount = ((tempBigWidth - (k * sides)) / smallWidth);	

		smallHeight = tempSmallHeight * k;
		startingPointX = tempStartingPointX * k;


	}
	double bigSpace = ((bigWidth * bigWidth * sqrt(3)) / 4.0);
	double smallSpace = smallWidth * tempSmallHeight * rectangleCounter;
	fileWriter = endScript();
	outfile << fileWriter;
	cout << "I can fit at most " <<  rectangleCounter << " small shapes into the main container. The empty area in container is ";
	cout << bigSpace - smallSpace << ".\n";
	outfile.close();

}


void drawCircleIntoTriangle(double bigWidth, double radius)
{
	double circleCounter = 0;
	ofstream outfile;
	outfile.open("output.svg"); // opens the file
	string fileWriter;
	fileWriter = beginningScript();
	outfile << fileWriter;
	outfile << "\n";
	double bigTriangleHeight = ((bigWidth / 2.0) * sqrt(3)); //setting initial values.
	int xCount, yCount;
	double tempRadius = radius;
	double x = radius * sqrt(3);
	double y = bigTriangleHeight - tempRadius;

	yCount = bigTriangleHeight / radius * 2;
	xCount = (bigWidth - 2 * radius * sqrt(3)) / (2 * radius); // calculating x and y counts.

	
	fileWriter = triangleScript(bigWidth / 2.0, 0, 0, bigTriangleHeight, bigWidth, bigTriangleHeight);
	outfile << fileWriter;
	outfile << "\n";
	for(int j = 0 ; j <= yCount ; ++j)
	{
		for(int i = 0 ; i <= xCount ; ++i)
		{
			circleCounter++;
			fileWriter = circleScript(radius, x,  y); //writes the file.
			outfile << fileWriter;
			outfile << "\n";
			x += tempRadius * 2;
		}
		
		
		
		xCount--;
		y =  bigTriangleHeight - (j + 2) * radius * sqrt(3) + tempRadius - tempRadius / sqrt(3);
		x = radius + (j + 2) * radius;
	}

	double bigSpace = ((bigWidth * bigWidth * sqrt(3)) / 4.0);
	double smallSpace = (PI * radius * radius) * circleCounter;

	cout << "I can fit at most " <<  circleCounter << " small shapes into the main container. The empty area in container is ";
	cout << bigSpace - smallSpace << ".\n"; //writing tshape count and small shape counts.

	fileWriter = endScript();
	outfile << fileWriter;
	outfile << "\n";


}

void drawCircleIntoCircle(double bigRadius, double smallRadius)
{

	int circleCount = 0;
	ofstream outfile;
	outfile.open("output.svg"); //opens the file
	string fileWriter;
	int baseCircleCounter;
	baseCircleCounter = bigRadius / smallRadius;
	fileWriter = beginningScript();
	double incX = 0;
	double incY = 0;
	double y1;
	double tempSmallRadius = smallRadius;
	outfile << fileWriter;
	outfile << "\n";

	fileWriter = circleScript(bigRadius, bigRadius, bigRadius);

	outfile << fileWriter;
	outfile << "\n";

	y1 = baseCircleCounter / 2.0; // setting initial value for y coordinates.
	for(int j = 0; j < y1; ++j){
		for(int i = 0 ; i < baseCircleCounter ; ++i)
		{
			fileWriter = circleScript(tempSmallRadius, smallRadius + incX, bigRadius - incY); // specified calculation for filling circle.
			outfile << fileWriter; 
			outfile << "\n";
			fileWriter = circleScript(tempSmallRadius, smallRadius + incX, bigRadius + incY);
			outfile << fileWriter; 
			outfile << "\n";
			incX = 2* tempSmallRadius * (i + 1);
			circleCount+=2;
		}
		incX = 0;
		baseCircleCounter--;
		smallRadius = (j + 2) * tempSmallRadius;
		incY = (j + 1) * (tempSmallRadius * sqrt(3)); //increments x and y values.

	}
	
	

	

	double bigSpace = PI * bigRadius * bigRadius;
	double smallSpace = circleCount * (tempSmallRadius * tempSmallRadius * PI);
	outfile << fileWriter;
	outfile << "\n";

	fileWriter = endScript();

	outfile << fileWriter;

	outfile << "\n";

	cout << "I can fit at most " <<  circleCount << " small shapes into the main container. The empty area in container is ";
	cout << bigSpace - smallSpace << ".\n"; //printing the result.
	outfile.close();

}

void drawRectangleIntoCircle(double bigRadius, double smallHeight, double smallWidth)
{
	double incX = 0; 
	double incY = 0;

	double tempBigRadius = bigRadius;
	double extraSpace;
	ofstream outfile;
	outfile.open("output.svg");
	string fileWriter;
	double yCounter = (2 * bigRadius / smallHeight);
	double xCounter = 0;
	double tempExtraSpace;
	fileWriter = beginningScript();

	outfile << fileWriter;
	outfile << "\n";

	fileWriter = circleScript(bigRadius, bigRadius, bigRadius);
	outfile << fileWriter;
	outfile << "\n";

	if(smallHeight < bigRadius)
	{
		extraSpace = bigRadius - (sqrt((bigRadius * bigRadius) - (smallHeight * smallHeight)));
		tempExtraSpace = extraSpace;
		tempBigRadius = bigRadius - (extraSpace);
		xCounter = 2 * (tempBigRadius / smallWidth);
		for(int i = 0 ; i < yCounter ; ++i)
		{
			for(int j = 0 ; j < xCounter ; ++j)
			{
				if(smallWidth < (2 * bigRadius - (tempExtraSpace + incX)))
				{
					fileWriter = rectangleScript(smallWidth, smallHeight, tempExtraSpace + incX, bigRadius - incY );
					outfile << fileWriter;
					outfile << "\n";
					fileWriter = rectangleScript(smallWidth, smallHeight, tempExtraSpace + incX, bigRadius + incY );
					outfile << fileWriter;
					outfile << "\n";
					incX = (j + 1) * (smallWidth);
				}
				
			}
			tempExtraSpace = extraSpace + ((i+1) * (smallWidth / 2.0));
			xCounter--;
			incX = extraSpace;
			//incX = (i + 1) * (smallWidth / 2.0);
			incY = (i + 1) * (smallHeight);
		} 
	}
	fileWriter = endScript();
	outfile << fileWriter;
}

void drawTriangleIntoCircle(double bigRadius, double smallWidth)
{
	//I will implement this function on HW2.

}
string rectangleScript(double width, double height, double xCoordinate, double yCoordinate)
{
	string Script; // returns the modified script
	Script = std::string("<rect x=\"") + to_string(xCoordinate) + "\"" + " y=\"" + to_string(yCoordinate) + "\""
	+ " width=\"" + to_string(width) + "\"" + " height=\"" + to_string(height) + "\"" + " stroke=\"red\"" +
	 " fill=\"yellow\" " + " />";
	//<rect x="10" y="10" width="30" height="30" stroke="black" fill="transparent" stroke-width="5"/>
	return Script;
}

string circleScript(double radius, double xCoordinate, double yCoordinate)
{
	string Script; //returns the modified script.
	//<circle cx="25" cy="75" r="20" stroke="red" fill="transparent" stroke-width="5"/>
	Script = std::string("<circle cx=\"") + to_string(xCoordinate) + "\"" +" cy=\"" + to_string(yCoordinate) + "\""
	+ " r=\"" + to_string(radius) + "\"" + " stroke=\"blue\"" +  " fill=\"purple \"" + " />";

	return Script;
}
string triangleScript(double x1, double y1, double x2, double y2, double x3, double y3)
{
	string Script; //returns the modified script.
	//<polygon points="50 160 55 180 70 180 "  stroke="green" fill="transparent" stroke-width="5"/>
	Script = std::string("<polygon points=\"") + to_string(x1) + " " + to_string(y1) + " " + to_string(x2) + " " + to_string(y2) + " "
	+ to_string(x3) + " " + to_string(y3) + "\"" + " stroke=\"green\"" +  " fill=\"brown\"" + "/>";

	return Script;
}
string beginningScript(void)
{	//returns the modified script.
	string Script = std::string("<?xml version=\"1.0\" standalone=\"no\"?>" )+ "\n" +
	+ "<svg width=\"500\" height=\"500\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">";
	return Script;
}

string endScript(void)
{
	//returns the modified script.
	string Script = "</svg>";
	return Script;

}