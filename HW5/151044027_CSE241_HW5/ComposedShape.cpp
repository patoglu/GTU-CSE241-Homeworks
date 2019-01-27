#include "ComposedShape.h"
#include <iostream>
#include <string>
#include <vector> //including required libraries.
#include <fstream>
#include <cmath>
#include "PolygonDyn.h"
namespace PatogluShape
{
	ComposedShape::ComposedShape() // Default Composed Shape constructor.
	{
		oRiR = false;  
		oRiT = false; 
		oRiC = true; 
		oTiR = false; 
		oTiC = false; 
		oTiT = false;
		oCiR = false; 
		oCiC = false; 
	    oCiT = false; 
	    cout << "For default constructor, I will produce Rectangle into Circle." << endl;

	    Rectangle defaultRectangle(0,0,200,100);
	    Circle defaultCircle(0,0,10);
	    myOuterRectangle = defaultRectangle;
	    myInnerCircle = defaultCircle;


	}
	//in my model, I will create 9 different two parameter constructors.
	//which takes different type of objects to apply nine different combinations.
	//I have tested two simple constructors, one takes int and double 
	//other takes double and int in order.
	//It acts like two different constructors so I decided to make this model.
	ComposedShape::ComposedShape(Rectangle outerRectangle, Rectangle innerRectangle) 
	{
		oRiR = true;  //I will use this flags in optimal fit and draw function
		oRiT = false; //with this it will make sense to write or fit specific objects.
		oRiC = false; 
		oTiR = false; 
		oTiC = false; 
		oTiT = false; 
		oCiR = false; 
		oCiC = false; 
	    oCiT = false; 

	    myOuterRectangle = outerRectangle; //assigning my private member objects.
	    myInnerRectangle = innerRectangle;
	    //bigShape = ShapeElem(outerRectangle);
	    //smallShape = ShapeElem(innerRectangle);

	}
	ComposedShape::ComposedShape(Rectangle outerRectangle, Triangle innerTriangle)
	{
		oRiR = false;  
		oRiT = true; 
		oRiC = false; 
		oTiR = false; 
		oTiC = false; 
		oTiT = false; 
		oCiR = false; 
		oCiC = false; 
	    oCiT = false; 


	    myOuterRectangle = outerRectangle; //assigning my private member objects.
	    myInnerTriangle = innerTriangle;
	    //bigShape = ShapeElem(outerRectangle);
	    //smallShape = ShapeElem(innerRectangle);
	}
	ComposedShape::ComposedShape(Rectangle outerRectangle, Circle innerCircle)
	{
		oRiR = false;  
		oRiT = false; 
		oRiC = true; 
		oTiR = false; 
		oTiC = false; 
		oTiT = false;
		oCiR = false; 
		oCiC = false; 
	    oCiT = false; 


	    myOuterRectangle = outerRectangle;//assigning my private member objects.
	    myInnerCircle = innerCircle;
	    //bigShape = ShapeElem(outerRectangle);
	    //smallShape = ShapeElem(innerCircle);
	    
	}
	ComposedShape::ComposedShape(Triangle outerTriangle, Triangle innerTriangle)
	{
		oRiR = false;  
		oRiT = false; 
		oRiC = false; 
		oTiR = false; 
		oTiC = false; 
		oTiT = true;; 
		oCiR = false; 
		oCiC = false; 
	    oCiT = false; 

	   
	    myOuterTriangle = outerTriangle;//assigning my private member objects.
	    myInnerTriangle = innerTriangle;

	   	//bigShape = ShapeElem(outerRectangle);
	    //smallShape = ShapeElem(innerRectangle);

	}
	ComposedShape::ComposedShape(Triangle outerTriangle, Rectangle innerRectangle)
	{
		oRiR = false;  
		oRiT = false; 
		oRiC = false; 
		oTiR = true; 
		oTiC = false; 
		oTiT = false; 
		oCiR = false; 
		oCiC = false; 
	    oCiT = false; 

	    
	    myOuterTriangle = outerTriangle;//assigning my private member objects.
	    myInnerRectangle = innerRectangle;
	    //bigShape = ShapeElem(outerTriangle);
	    //smallShape = ShapeElem(innerRectangle);

	}
	ComposedShape::ComposedShape(Triangle outerTriangle, Circle innerCircle)
	{
		oRiR = false; 
		oRiT = false; 
		oRiC = false; 
		oTiR = false; 
		oTiC = true; 
		oTiT = false; 
		oCiR = false; 
		oCiC = false; 
	    oCiT = false; 
	   


	    myOuterTriangle = outerTriangle; //assigning my private member objects.
	    myInnerCircle = innerCircle;
	    //bigShape = ShapeElem(outerTriangle);
	    //smallShape = ShapeElem(innerCircle);

	}
	ComposedShape::ComposedShape(Circle outerCircle, Circle innerCircle)
	{
		oRiR = false;  
		oRiT = false; 
		oRiC = false; 
		oTiR = false; 
		oTiC = false; 
		oTiT = false; 
		oCiR = false; 
		oCiC = true; 
	    oCiT = false; 
	    
	    myOuterCircle = outerCircle;
	    myInnerCircle = innerCircle;

		//bigShape = ShapeElem(outerCircle);
	    //smallShape = ShapeElem(innerCircle);

	}
	ComposedShape::ComposedShape(Circle outerCircle, Triangle innerTriangle)
	{
		oRiR = false;  
		oRiT = false; 
		oRiC = false; 
		oTiR = false; 
		oTiC = false; 
		oTiT = false; 
		oCiR = false; 
		oCiC = false; 
	    oCiT = true; 
	   
	    myOuterCircle = outerCircle;
	    myInnerTriangle = innerTriangle;

	  	//bigShape = ShapeElem(outerCircle);
	    //smallShape = ShapeElem(innerTriangle);

	}
	ComposedShape::ComposedShape(Circle outerCircle, Rectangle innerRectangle)
	{
		oRiR = false;
		oRiT = false; 
		oRiC = false; 
		oTiR = false; 
		oTiC = false; 
		oTiT = false; 
		oCiR = true; 
		oCiC = false; 
	    oCiT = false; 

	    

	    myOuterCircle = outerCircle; //assigning my private member objects.
	    myInnerRectangle = innerRectangle;
	    //bigShape = ShapeElem(outerCircle);
	    //smallShape = ShapeElem(innerRectangle);

	}
	vector<Shape*> ComposedShape::getShapeVect(void)
	{
		return shapes;
	}
	void ComposedShape::optimalFit(void)
	{
		
		double x,y = 0;

		if(oRiR) //Rectangle into rectangle situation.
		{
			
			double bigWidth = myOuterRectangle.getWidth();
			double bigHeight = myOuterRectangle.getHeight();
			double smallWidth = myInnerRectangle.getWidth();
			double smallHeight = myInnerRectangle.getHeight();
			

			int widthCounter;
			int heightCounter;
			widthCounter = bigWidth / smallWidth;
			heightCounter = bigHeight / smallHeight;


			double remainingWidth, remainingHeight;

			double tempSmallWidth = smallHeight; //to determine best case.
			double tempSmallHeight = smallWidth; // to determine best case.

			int xCounter, yCounter; //first case
			int xCounter2, yCounter2; //other case

			if((xCounter * yCounter ) < (xCounter2 * yCounter2))
			{
				smallHeight = tempSmallHeight;
				smallWidth = tempSmallWidth;
				xCounter = xCounter2;
				yCounter = yCounter2;
			}


			xCounter = bigWidth / smallWidth;
			yCounter = bigHeight / smallHeight;

			xCounter2 = bigWidth / tempSmallWidth;
			yCounter2 = bigHeight / tempSmallHeight;

			if((xCounter * yCounter ) < (xCounter2 * yCounter2))
			{
				smallHeight = tempSmallHeight;
				smallWidth = tempSmallWidth;
				xCounter = xCounter2;
				yCounter = yCounter2;
			}
		
			for(int i = 0 ; i < yCounter ; ++i)
			{
				for(int j = 0 ; j < xCounter ; ++j)
				{	

					//Rectangle tempInnerRectangle(x,y,myInnerRectangle.getWidth(), myInnerRectangle.getHeight());
					//shapesConnected.push_back(tempInnerRectangle);
					Shape* tempInnerRectangle = new Rectangle(x,y,myInnerRectangle.getWidth(), myInnerRectangle.getHeight());
					shapes.push_back(tempInnerRectangle);
					
					//ShapeElem tempInnerRectangle(x,y)
					
					x += smallWidth;
				}
			y += smallHeight;
			x = 0;
		}



			/*for(int i = 0 ; i < 10 ; ++i)
			{
				Rectangle tempInnerRectangle(x,y,myInnerRectangle.getWidth(), myInnerRectangle.getHeight());
				//tempInnerRectangle.getWidth();
				//myInnerRectangle = tempInnerRectangle;
				
				myRectangleVector.push_back(tempInnerRectangle);
				
				//Rectangle tempInnerRectangle;
				//tempInnerRectangle.setHeight(myInnerRectangle.getHeight());
				//tempInnerRectangle.setWidth(myInnerRectangle.getWidth());
				//myRectangleVector.push_back(tempInnerRectangle);

			}*/
		
		}
		else if(oRiC) //rectangleinto circle situation.
		{
			
			
			double bigWidth = myOuterRectangle.getWidth();
			double bigHeight = myOuterRectangle.getHeight();
			
			double radius = myInnerCircle.getRadius();
			double xCounter = (bigWidth / (radius*2)); 
			double yCounter = (bigHeight / (radius*2)); 
			double x = radius;
			double y = radius;
			for(int i = 0 ; i < yCounter ; ++i)
			{
				for(int j = 0 ; j < xCounter ; ++j)
				{

					Shape* tempInnerCircle = new Circle(x,y,myInnerCircle.getRadius());
					shapes.push_back(tempInnerCircle);
					x += 2 * radius;
				}
				x = radius;
				y += 2 * radius;
			}
			
		}
		else if(oRiT)
		{
		
		double x1, y1;
		double x2, y2;
		double x3, y3;
		bool flag = true;
		int xCounter = 0;
		double smallWidth = myInnerTriangle.getWidth();

		double bigWidth = myOuterRectangle.getWidth();
		double bigHeight = myOuterRectangle.getHeight();

		double smallWidthHeight = ((smallWidth / 2.0) * sqrt(3)); //setting initial values.
		int heightCounter = bigHeight / smallWidthHeight;
		int widthCounter = bigWidth / smallWidth;


		x1 = smallWidth / 2.0; //setting initial values for triangles all coordinates.
		y1 = 0;
		x2 = 0;
		y2 = smallWidthHeight;
		x3 = smallWidth;
		y3 = smallWidthHeight;

		for(int j = 0 ; j < heightCounter ; ++j) //main iteration to fit small shapes.
		{
			for(int i = 0 ; i < widthCounter ; ++i)
			{
				flag = true;
				Shape* tempInnerTriangle = new Triangle(x1,y1,x2,y2,x3,y3);
				shapes.push_back(tempInnerTriangle);
				//Triangle tempInnerTriangle(x1,y1,x2,y2,x3,y3);
				//shapesConnected.push_back(tempInnerTriangle);
				// writes small triangle shapes.
				if(bigWidth - x1 >= smallWidth)
				{
					flag = false;
					xCounter++;
					//Triangle tempInnerTriangle(x1,y1,x3,y3,x1 + smallWidth, y1);
					//shapesConnected.push_back(tempInnerTriangle);
					Shape* tempInnerTriangle = new Triangle(x1,y1,x3,y3,x1 + smallWidth, y1);
					shapes.push_back(tempInnerTriangle);
					//fileWriter = triangleScript(x1,y1,x3,y3,x1 + smallWidth, y1); // writes small reversed triangle shapes.
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
		
		}
		else if(oTiT) //triangle into triangle situatuon.
		{
			
			int triangleCounter = 0;
			double x1, y1;
			double x2, y2;
			double x3, y3;
			int k = 1;
			double bigWidth = myOuterTriangle.getWidth();
			double smallWidth = myInnerTriangle.getWidth();
			

			int triangleCount = bigWidth / smallWidth;
			int tempTriangleCount = triangleCount;
			double bigTriangleHeight = ((bigWidth / 2.0) * sqrt(3));
			double smallTriangleHeight =  ((smallWidth / 2.0) * sqrt(3));
			myOuterTriangle.setX1Coordinate(bigWidth / 2.0);
			myOuterTriangle.setY1Coordinate(0);
			myOuterTriangle.setX2Coordinate(0);
			myOuterTriangle.setY2Coordinate(bigTriangleHeight);
			myOuterTriangle.setX3Coordinate(bigWidth);
			myOuterTriangle.setY3Coordinate(bigTriangleHeight);

			 // calculating initial values of coordinates.

			//Triangle tempInnerTriangle(bigWidth / 2.0, 0, 0, bigTriangleHeight, bigWidth, bigTriangleHeight);
			//myTriangleVector.push_back(tempInnerTriangle);


			//fileWriter = triangleScript(bigWidth / 2.0, 0, 0, bigTriangleHeight, bigWidth, bigTriangleHeight); //writes main shape to a file
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
					Shape* tempInnerTriangle1 = new Triangle(x1,y1,x2,y2,x3,y3);
					shapes.push_back(tempInnerTriangle1);

					//Triangle tempInnerTriangle1(x1,y1,x2,y2,x3,y3);
					//shapesConnected.push_back(tempInnerTriangle1);
					//fileWriter = triangleScript(x1,y1,x2,y2,x3,y3);
					if(i == tempTriangleCount - 1)
					{
						//handles the overflow shape situation
					}
					else
					{
						Shape* tempInnerTriangle2 = new Triangle(x1,y1,x3,y3,x1 + smallWidth, y1);
						shapes.push_back(tempInnerTriangle2);

						//Triangle tempInnerTriangle2(x1,y1,x3,y3,x1 + smallWidth, y1);
						//shapesConnected.push_back(tempInnerTriangle2);
						//fileWriter = triangleScript(x1,y1,x3,y3,x1 + smallWidth, y1);
						//outfile << fileWriter;
						//outfile << "\n";
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
			
		
		}
		else if(oTiR) //triangle is bigger one.(drawRectangleIntoTriangle.)
		{
			
			int xCount, yCount;
			int k = 1;
		
			int rectangleCounter = 0;
			double tempSmallHeight = myInnerRectangle.getWidth();
			double smallHeight = myInnerRectangle.getHeight();
			double smallWidth = myInnerRectangle.getWidth();
			double sides = (sqrt(3) * smallHeight) * 2.0 / 3.0;
			double bigWidth = myOuterTriangle.getWidth();
			double bigTriangleHeight = ((bigWidth / 2.0) * sqrt(3));
			double startingPointX = (sqrt(3) * smallHeight) / 3.0;
			double tempStartingPointX = startingPointX;
			double tempBigWidth = bigWidth;


			yCount = bigTriangleHeight / smallHeight;
			xCount = (bigWidth - sides) / smallWidth;


			myOuterTriangle.setWidth(bigWidth / 2.0);
			myOuterTriangle.setX1Coordinate(bigWidth / 2.0);
			myOuterTriangle.setY1Coordinate(0);
			myOuterTriangle.setX2Coordinate(0);
			myOuterTriangle.setY2Coordinate(bigTriangleHeight);
			myOuterTriangle.setX3Coordinate(bigWidth);
			myOuterTriangle.setY3Coordinate(bigTriangleHeight);

			
			//myOuter
			//fileWriter = triangleScript(bigWidth / 2.0, 0, 0, bigTriangleHeight, bigWidth, bigTriangleHeight);
			//outfile << fileWriter;
			//outfile << "\n";
			
			for(int j = 0 ; j < yCount; ++j) //main iteration
			{
				for(int i = 0 ; i < xCount ; ++i)
				{
						//fileWriter = rectangleScript(smallWidth, tempSmallHeight,startingPointX, bigTriangleHeight - smallHeight);
						//outfile << fileWriter;
						//outfile << "\n";
						Shape* tempInnerRectangle = new Rectangle(startingPointX, bigTriangleHeight - smallHeight,smallWidth, tempSmallHeight);
						shapes.push_back(tempInnerRectangle);
						//Rectangle tempInnerRectangle(startingPointX, bigTriangleHeight - smallHeight,smallWidth, tempSmallHeight);
						//shapesConnected.push_back(tempInnerRectangle);
						
					
					startingPointX += smallWidth;
				}
				rectangleCounter += xCount;
				k++;
				xCount = ((tempBigWidth - (k * sides)) / smallWidth);	

				smallHeight = tempSmallHeight * k;
				startingPointX = tempStartingPointX * k;


			}
			

			
		}
		else if(oTiC) //triangle into circle situation.
		{
			
			double radius = myInnerCircle.getRadius();
			double circleCounter = 0;
			double bigWidth = myOuterTriangle.getWidth();
		    double bigTriangleHeight = ((bigWidth / 2.0) * sqrt(3)); //setting initial values.
			int xCount, yCount;
			double tempRadius = radius;
			double x = radius * sqrt(3);
			double y = bigTriangleHeight - tempRadius;

			yCount = bigTriangleHeight / radius * 2;
			xCount = (bigWidth - 2 * radius * sqrt(3)) / (2 * radius); // calculating x and y counts.

			myOuterTriangle.setWidth(bigWidth / 2.0);
			myOuterTriangle.setX1Coordinate(bigWidth / 2.0);
			myOuterTriangle.setY1Coordinate(0);
			myOuterTriangle.setX2Coordinate(0);
			myOuterTriangle.setY2Coordinate(bigTriangleHeight);
			myOuterTriangle.setX3Coordinate(bigWidth);
			myOuterTriangle.setY3Coordinate(bigTriangleHeight);
			
			//fileWriter = triangleScript(bigWidth / 2.0, 0, 0, bigTriangleHeight, bigWidth, bigTriangleHeight);
			for(int j = 0 ; j <= yCount ; ++j)
			{
				for(int i = 0 ; i <= xCount ; ++i)
				{
				circleCounter++;
				//Circle tempInnerCircle(x,y,radius);
				//shapesConnected.push_back(tempInnerCircle);

				Shape* tempInnerCircle = new Circle(x,y,radius);
				shapes.push_back(tempInnerCircle);
				//fileWriter = circleScript(radius, x,  y); //writes the file.
				//outfile << fileWriter;
				//outfile << "\n";
				x += tempRadius * 2;
			}
			xCount--;
			y =  bigTriangleHeight - (j + 2) * radius * sqrt(3) + tempRadius - tempRadius / sqrt(3);
			x = radius + (j + 2) * radius;
		}
		
		}
		else if(oCiT) //circle into triangle situations.
		{
			
			myOuterCircle.setRadius(100);
			myOuterCircle.setXCoordinate(100);
			myOuterCircle.setYCoordinate(100);
			Shape* tempInnerCircle = new Circle(myOuterCircle.getXCoordinate(),myOuterCircle.getYCoordinate(),myOuterCircle.getRadius());
			shapes.push_back(tempInnerCircle);
			//shapesConnected.push_back(myOuterCircle);
			
		}
		else if(oCiC) //circle into circle situation.
		{
			
			int circleCount = 0;
			int baseCircleCounter;
			double bigRadius = myOuterCircle.getRadius();
			double smallRadius = myInnerCircle.getRadius();
			baseCircleCounter = bigRadius / smallRadius;

			double incX = 0;
			double incY = 0;
			double y1;
			double tempSmallRadius = smallRadius;


			myOuterCircle.setRadius(bigRadius);
			myOuterCircle.setXCoordinate(bigRadius);
			myOuterCircle.setYCoordinate(bigRadius);
			//fileWriter = circleScript(bigRadius, bigRadius, bigRadius);

			y1 = baseCircleCounter / 2.0; // setting initial value for y coordinates.
			for(int j = 0; j < y1; ++j){
				for(int i = 0 ; i < baseCircleCounter ; ++i)
				{
					//Circle tempInnerCircle(smallRadius + incX,bigRadius - incY,  tempSmallRadius);
					//shapesConnected.push_back(tempInnerCircle);
					Shape* tempInnerCircle = new Circle(smallRadius + incX,bigRadius - incY,  tempSmallRadius);
					shapes.push_back(tempInnerCircle);	

					//fileWriter = circleScript(tempSmallRadius, smallRadius + incX, bigRadius - incY); // specified calculation for filling circle.
					//outfile << fileWriter; 
					//outfile << "\n";
					//Circle temp1InnerCircle( smallRadius + incX,bigRadius + incY, tempSmallRadius);
					//shapesConnected.push_back(temp1InnerCircle);
					Shape* temp1InnerCircle = new Circle( smallRadius + incX,bigRadius + incY, tempSmallRadius);
					shapes.push_back(temp1InnerCircle);

					//fileWriter = circleScript(tempSmallRadius, smallRadius + incX, bigRadius + incY);
					//outfile << fileWriter; 
					//outfile << "\n";
					incX = 2* tempSmallRadius * (i + 1);
					circleCount+=2;
				}
				incX = 0;
				baseCircleCounter--;
				smallRadius = (j + 2) * tempSmallRadius;
				incY = (j + 1) * (tempSmallRadius * sqrt(3)); //increments x and y values.

			}

			
		}
		else if(oCiR) //circle into rectangle situation.
		{
			
			double incX = 0; 
			double incY = 0;
			double smallHeight = myInnerRectangle.getHeight();
			double smallWidth = myInnerRectangle.getWidth();
			double bigRadius = myOuterCircle.getRadius();
			double tempBigRadius = bigRadius;
			double yCounter = (2 * bigRadius / smallHeight);
			double xCounter = 0;
			double tempExtraSpace;
			double extraSpace;
			

			myOuterCircle.setRadius(bigRadius);
			myOuterCircle.setXCoordinate(bigRadius);
			myOuterCircle.setYCoordinate(bigRadius);

			if(smallHeight < bigRadius)
			{
				extraSpace = bigRadius - (sqrt((bigRadius * bigRadius) - (smallHeight * smallHeight)));
				tempExtraSpace = extraSpace;
				tempBigRadius = bigRadius - (extraSpace);
				xCounter = 2 * (tempBigRadius / smallWidth);
				for(int i = 0 ; i <(yCounter / 2) - 1; ++i)
				{
					for(int j = 0 ; j < xCounter ; ++j)
					{
						if(smallWidth < (2 * bigRadius - (tempExtraSpace + incX)))
						{
							Shape* tempInnerRectangle = new Rectangle(tempExtraSpace + incX, bigRadius - incY ,myInnerRectangle.getWidth(), myInnerRectangle.getHeight());
							shapes.push_back(tempInnerRectangle);

							//Rectangle tempInnerRectangle(tempExtraSpace + incX, bigRadius - incY ,myInnerRectangle.getWidth(), myInnerRectangle.getHeight());
							//shapesConnected.push_back(tempInnerRectangle);

							Shape* tempInnerRectangle1 = new Rectangle(tempExtraSpace + incX, bigRadius + incY ,myInnerRectangle.getWidth(), myInnerRectangle.getHeight());
							shapes.push_back(tempInnerRectangle1);


							//Rectangle tempInnerRectangle1(tempExtraSpace + incX, bigRadius + incY ,myInnerRectangle.getWidth(), myInnerRectangle.getHeight() );
							//shapesConnected.push_back(tempInnerRectangle1);
							//fileWriter = rectangleScript(smallWidth, smallHeight, tempExtraSpace + incX, bigRadius - incY );
							
							//fileWriter = rectangleScript(smallWidth, smallHeight, tempExtraSpace + incX, bigRadius + incY );
							
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
		}
		

	}
	//my draw function draws the bigger shape for one time. After that calls vector of shapes one by one.
	// then they calling their draw function.

	void ComposedShape::draw(std::ofstream &inputFile) 
	{
		string fileWriter;
		fileWriter = beginningScript();
		inputFile << fileWriter;
		inputFile << "\n";
		if(oRiR)
		{
			fileWriter = std::string("<rect x=\"") + to_string(0) + "\"" + " y=\"" + to_string(0) + "\""
			+ " width=\"" + to_string(myOuterRectangle.getWidth()) + "\"" + " height=\"" + to_string(myOuterRectangle.getHeight()) + "\"" + " stroke=\"red\"" +
		 	" fill=\"yellow\" " + " />";
			inputFile << fileWriter;
			inputFile << '\n';
			for(auto i = 0 ; i < shapes.size() ; ++i)
			{
				inputFile << *(shapes[i]);
				//shapesConnected[i].draw(inputFile); //drawing vector of rectangles.
				inputFile << "\n";
			}
		}
		else if(oRiC)
		{

			fileWriter = std::string("<rect x=\"") + to_string(0) + "\"" + " y=\"" + to_string(0) + "\""
			+ " width=\"" + to_string(myOuterRectangle.getWidth()) + "\"" + " height=\"" + to_string(myOuterRectangle.getHeight()) + "\"" + " stroke=\"red\"" +
		 	" fill=\"yellow\" " + " />";
		 	inputFile << fileWriter;
			inputFile << '\n';
			for(auto i = 0 ; i < shapes.size() ; ++i)
			{
				cout << "..." << *(shapes[i]) << endl;
				inputFile << *(shapes[i]);
				//shapesConnected[i].draw(inputFile); //drawing vector of rectangles.
				inputFile << "\n";
			}

		}
		else if(oRiT)
		{

			fileWriter = std::string("<rect x=\"") + to_string(0) + "\"" + " y=\"" + to_string(0) + "\""
			+ " width=\"" + to_string(myOuterRectangle.getWidth()) + "\"" + " height=\"" + to_string(myOuterRectangle.getHeight()) + "\"" + " stroke=\"red\"" +
		 	" fill=\"yellow\" " + " />";
		 	inputFile << fileWriter;
			inputFile << "\n";
			for(auto i = 0 ; i < shapes.size() ; ++i)
			{

				inputFile <<  *(shapes[i]);
				//shapesConnected[i].draw(inputFile); //drawing vector of rectangles.
				inputFile << "\n";
			}

		}
		else if(oTiT)
		{

			 //returns the modified script.
			//<polygon points="50 160 55 180 70 180 "  stroke="green" fill="transparent" stroke-width="5"/>
			string fileWriter = std::string("<polygon points=\"") + to_string(myOuterTriangle.getX1Coordinate()) + " " + to_string(myOuterTriangle.getY1Coordinate()) + " " + to_string(myOuterTriangle.getX2Coordinate()) + " " + to_string(myOuterTriangle.getY2Coordinate()) + " "
			+ to_string(myOuterTriangle.getX3Coordinate()) + " " + to_string(myOuterTriangle.getY3Coordinate()) + "\"" + " stroke=\"green\"" +  " fill=\"brown\"" + "/>";

			inputFile << fileWriter;
			inputFile << "\n";

			for(auto i = 0 ; i < shapes.size() ; ++i) //drawing vector of triangles.
			{
				inputFile <<  *(shapes[i]);
				//shapesConnected[i].draw(inputFile); //drawing vector of rectangles.
				inputFile << "\n";
			}

		}
		else if(oTiR)
		{
			 //returns the modified script.
			//<polygon points="50 160 55 180 70 180 "  stroke="green" fill="transparent" stroke-width="5"/>
			fileWriter = std::string("<polygon points=\"") + to_string(myOuterTriangle.getX1Coordinate()) + " " + to_string(myOuterTriangle.getY1Coordinate()) + " " + to_string(myOuterTriangle.getX2Coordinate()) + " " + to_string(myOuterTriangle.getY2Coordinate()) + " "
			+ to_string(myOuterTriangle.getX3Coordinate()) + " " + to_string(myOuterTriangle.getY3Coordinate()) + "\"" + " stroke=\"green\"" +  " fill=\"brown\"" + "/>";
			inputFile << fileWriter;
			inputFile << "\n";
	 		for(auto i = 0 ; i <shapes.size(); ++i) //drawing vector of rectangles.
			{

				inputFile <<  *(shapes[i]);
				//shapesConnected[i].draw(inputFile); //drawing vector of rectangles.
				inputFile << "\n";
			}

			
		}

		else if(oTiC)
		{

			string fileWriter = std::string("<polygon points=\"") + to_string(myOuterTriangle.getX1Coordinate()) + " " + to_string(myOuterTriangle.getY1Coordinate()) + " " + to_string(myOuterTriangle.getX2Coordinate()) + " " + to_string(myOuterTriangle.getY2Coordinate()) + " "
			+ to_string(myOuterTriangle.getX3Coordinate()) + " " + to_string(myOuterTriangle.getY3Coordinate()) + "\"" + " stroke=\"green\"" +  " fill=\"brown\"" + "/>";

			inputFile << fileWriter;
			inputFile << "\n";

			for(auto i = 0 ; i < shapes.size() ; ++i) 
			{
				inputFile <<  *(shapes[i]);
				//shapesConnected[i].draw(inputFile); //drawing vector of rectangles.
				inputFile << "\n";
			}
		}
		else if(oCiT)
		{
			int i = 0;
			string fileWriter = std::string("<circle cx=\"") + to_string(myOuterCircle.getXCoordinate()) + "\"" +" cy=\"" + to_string(myOuterCircle.getYCoordinate()) + "\""
		+ " r=\"" + to_string(myOuterCircle.getRadius()) + "\"" + " stroke=\"blue\"" +  " fill=\"purple \"" + " />";
			inputFile <<  *(shapes[i]);
				//shapesConnected[i].draw(inputFile); //drawing vector of rectangles.
			inputFile << "\n";

			//Still I can not draw circle into triangle. I really hate it actually...

		}
		else if(oCiC)
		{
			string fileWriter = std::string("<circle cx=\"") + to_string(myOuterCircle.getXCoordinate()) + "\"" +" cy=\"" + to_string(myOuterCircle.getYCoordinate()) + "\""
		+ " r=\"" + to_string(myOuterCircle.getRadius()) + "\"" + " stroke=\"blue\"" +  " fill=\"purple \"" + " />";
			inputFile << fileWriter;
			inputFile << "\n";

			for(auto i = 0 ; i < shapes.size() ; ++i)
			{
				inputFile << *(shapes[i]);
				//shapesConnected[i].draw(inputFile); //drawing vector of rectangles.
				inputFile << "\n";
			}
		}
		else if(oCiR)
		{
			string fileWriter = std::string("<circle cx=\"") + to_string(myOuterCircle.getXCoordinate()) + "\"" +" cy=\"" + to_string(myOuterCircle.getYCoordinate()) + "\""
		+ " r=\"" + to_string(myOuterCircle.getRadius()) + "\"" + " stroke=\"blue\"" +  " fill=\"purple \"" + " />";
			inputFile << fileWriter;
			inputFile << "\n";

			for(auto i = 0 ; i < shapes.size() ; ++i)
			{
				inputFile <<  *(shapes[i]);
				//shapesConnected[i].draw(inputFile); //drawing vector of rectangles.
				inputFile << "\n";
			}
		}


		fileWriter = endScript();
		inputFile << fileWriter;
		inputFile << "\n";
		

	}

	string ComposedShape::beginningScript(void) //Helper function of ComposedShape class that writes beginning of default script.
	{
		string Script = std::string("<?xml version=\"1.0\" standalone=\"no\"?>" )+ "\n" +
		+ "<svg width=\"300\" height=\"300\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">";
		return Script;
	}


	string ComposedShape::endScript(void) //Helper function of Composed Shape class that writes end of default script.
	{
		string Script = "</svg>";
		return Script;
	}

	Shape* ComposedShape:: operator++() 
	{
		Shape *a;
		cerr << "You shouldn't increment Polygon objects." << endl;
		return a;
	}
	Shape* ComposedShape:: operator++(int) 
	{
		Shape *a;
		cerr << "You shouldn't increment Polygon objects." << endl;
		return a;
	}
	Shape* ComposedShape:: operator--() 
	{
		Shape *a;
		cerr << "You shouldn't increment Polygon objects." << endl;
		return a;
	}
	Shape* ComposedShape::operator--(int) 
	{
		Shape *a;
		cerr << "You shouldn't increment Polygon objects." << endl;
		return a;
	}
	
}
//in my model, I will create 9 different two parameter constructors.
//which takes different type of objects to apply nine different combinations.
//I have tested two simple constructors, one takes int and double 
//other takes double and int in order.
//It acts like two different constructors so I decided to make this model.

