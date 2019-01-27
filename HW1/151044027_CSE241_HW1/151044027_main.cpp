#include "source1.h"
using namespace std;
 //constant for PI
int main()
{
	double bigWidth, bigHeight, bigRadius; // required shape variables
	double smallWidth, smallHeight, smallRadius; //required shape variables.
	char mainContainer; 
	char smallContainer;

	cout << "Please enter the main container shape (R, C, T)\n"; //taking inputs

	mainContainer = getCharInput();

	if(mainContainer == 'R')
		rectangleInput(bigWidth,bigHeight);
	else if(mainContainer == 'C')
		circleInput(bigRadius);
	else
		triangleInput(bigWidth);

	cout << "Please enter the small shape(R, C, T)\n"; //taking inputs

	smallContainer = getCharInput();

	if(smallContainer == 'R')
		rectangleInput(smallWidth,smallHeight);
	else if(smallContainer == 'C')
		circleInput(smallRadius);
	else
		triangleInput(smallWidth);

	drawShapes(mainContainer, smallContainer, bigWidth, bigHeight, bigRadius, smallWidth, smallHeight, smallRadius);

	return 0;
}