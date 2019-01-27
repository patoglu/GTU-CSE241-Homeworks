import java.awt.Graphics;
import java.util.Vector;

public class ComposedShape implements Shape{
	private int shapeCount;
	private Rectangle myOuterRectangle;
	private Rectangle myInnerRectangle;
	private Triangle myOuterTriangle; //Triangle object for big shape
	private Triangle myInnerTriangle; //Triangle object for small shape.
	private Circle myOuterCircle; //Circle object for big shape.
	private Circle myInnerCircle; //Circle object for small shape.
	private Shape [] shapeReferences;
	
	private boolean oRiR = false; //flag members to make our fit and draw process easier.
	private boolean oRiT = false; //all settled false for default.
	private boolean oRiC = false; 
	private boolean oTiR = false; 
	private boolean oTiC = false; 
	private boolean oTiT = false; 
	private boolean oCiR = false; 
	private boolean oCiC = false;
	private boolean oCiT = false;
	private static final double SQRT3 = 1.73;
	/**
	 * Default cons
	 */
	
	public ComposedShape() // Default Composed Shape constructor.
	{

	}
	//in my model, I will create 9 different two parameter constructors.
	//which takes different type of objects to apply nine different combinations.
	//I have tested two simple constructors, one takes int and double 
	//other takes double and int in order.
	//It acts like two different constructors so I decided to make this model.
	public ComposedShape(Rectangle outerRectangle, Rectangle innerRectangle) 
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
	public ComposedShape(Rectangle outerRectangle, Triangle innerTriangle)
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
	public ComposedShape(Rectangle outerRectangle, Circle innerCircle)
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
	public ComposedShape(Triangle outerTriangle, Triangle innerTriangle)
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
	public ComposedShape(Triangle outerTriangle, Rectangle innerRectangle)
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
	public ComposedShape(Triangle outerTriangle, Circle innerCircle)
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
	public ComposedShape(Circle outerCircle, Circle innerCircle)
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
	public ComposedShape(Circle outerCircle, Triangle innerTriangle)
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
	public ComposedShape(Circle outerCircle, Rectangle innerRectangle)
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
	/**
	 * Overriding area method. Outer container's area is returned.
	 */
	@Override
	public double area() {

		if(oRiR) //Rectangle into rectangle situation.
		{
			return myOuterRectangle.area();
		}
		else if(oRiC) //rectangleinto circle situation.
		{
			return myOuterRectangle.area();
		}
		else if(oRiT)
		{
			return myOuterRectangle.area();
		}
		else if(oTiT) //triangle into triangle situatuon.
		{
			return myOuterTriangle.area();
		}
		else if(oTiR) //triangle is bigger one.(drawRectangleIntoTriangle.)
		{
			return myOuterTriangle.area();
		}
		else if(oTiC) //triangle into circle situation.
		{
			return myOuterTriangle.area();
		}
		else if(oCiT) //circle into triangle situations.
		{
			return myOuterCircle.area();
		}
		else if(oCiC) //circle into circle situation.
		{
			return myOuterCircle.area();
		}
		else if(oCiR) //circle into rectangle situation.
		{
			return myOuterCircle.area();
		}
		return -1;
	}
	/**
	 * Overriding perimeter method. Outer container shape's perimeter returned.
	 */
	@Override
	public double perimeter() {
		if(oRiR) //Rectangle into rectangle situation.
		{
			return myOuterRectangle.perimeter();
		}
		else if(oRiC) //rectangleinto circle situation.
		{
			return myOuterRectangle.perimeter();
		}
		else if(oRiT)
		{
			return myOuterRectangle.perimeter();
		}
		else if(oTiT) //triangle into triangle situatuon.
		{
			return myOuterTriangle.perimeter();
		}
		else if(oTiR) //triangle is bigger one.(drawRectangleIntoTriangle.)
		{
			return myOuterTriangle.perimeter();
		}
		else if(oTiC) //triangle into circle situation.
		{
			return myOuterTriangle.perimeter();
		}
		else if(oCiT) //circle into triangle situations.
		{
			return myOuterCircle.perimeter();
		}
		else if(oCiC) //circle into circle situation.
		{
			return myOuterCircle.perimeter();
		}
		else if(oCiR) //circle into rectangle situation.
		{
			return myOuterCircle.perimeter();
		}
		return -1;
	}
	/**
	 * Increments both small container and big container.
	 */
	@Override
	public void increment() {
		if(oRiR) //Rectangle into rectangle situation.
		{
			myOuterRectangle.increment();
			myInnerRectangle.increment();
		}
		else if(oRiC) //rectangleinto circle situation.
		{
			myOuterRectangle.increment();
			myInnerCircle.increment();
		}
		else if(oRiT)
		{
			myOuterRectangle.increment();
			myInnerTriangle.increment();
		}
		else if(oTiT) //triangle into triangle situatuon.
		{
			myOuterTriangle.increment();
			myInnerTriangle.increment();
		}
		else if(oTiR) //triangle is bigger one.(drawRectangleIntoTriangle.)
		{
			myOuterTriangle.increment();
			myInnerRectangle.increment();
		}
		else if(oTiC) //triangle into circle situation.
		{
			myOuterTriangle.increment();
			myInnerCircle.increment();
		}
		else if(oCiT) //circle into triangle situations.
		{
			myOuterCircle.increment();
			myInnerTriangle.increment();
		}
		else if(oCiC) //circle into circle situation.
		{
			myOuterCircle.increment();
			myInnerCircle.increment();
		}
		else if(oCiR) //circle into rectangle situation.
		{
			myOuterCircle.increment();
			myInnerRectangle.increment();
		}
	}
	/**
	 * Decrements both small and big container.
	 */
	@Override
	public void decrement() {
		if(oRiR) //Rectangle into rectangle situation.
		{
			myOuterRectangle.decrement();
			myInnerRectangle.decrement();
		}
		else if(oRiC) //rectangleinto circle situation.
		{
			myOuterRectangle.decrement();
			myInnerCircle.decrement();
		}
		else if(oRiT)
		{
			myOuterRectangle.decrement();
			myInnerTriangle.decrement();
		}
		else if(oTiT) //triangle into triangle situatuon.
		{
			myOuterTriangle.decrement();
			myInnerTriangle.decrement();
		}
		else if(oTiR) //triangle is bigger one.(drawRectangleIntoTriangle.)
		{
			myOuterTriangle.decrement();
			myInnerRectangle.decrement();
		}
		else if(oTiC) //triangle into circle situation.
		{
			myOuterTriangle.decrement();
			myInnerCircle.decrement();
		}
		else if(oCiT) //circle into triangle situations.
		{
			myOuterCircle.decrement();
			myInnerTriangle.decrement();
		}
		else if(oCiC) //circle into circle situation.
		{
			myOuterCircle.decrement();
			myInnerCircle.decrement();
		}
		else if(oCiR) //circle into rectangle situation.
		{
			myOuterCircle.decrement();
			myInnerRectangle.decrement();
		}
		
	}
	/**
	 * optimalFit function that places shapes carefully.
	 */
	public void optimalFit()
	{
		if(oRiR) //Rectangle into rectangle situation.
		{
			Vector<Rectangle> rrVector = new Vector<Rectangle>();
			double x = 0, y = 0;
			double bigWidth = myOuterRectangle.getWidth();
			double bigHeight = myOuterRectangle.getHeight();
			double smallWidth = myInnerRectangle.getWidth();
			double smallHeight = myInnerRectangle.getHeight();
			

			int widthCounter;
			int heightCounter;
			widthCounter = (int)(bigWidth / smallWidth);
			heightCounter = (int)(bigHeight / smallHeight);


			double remainingWidth, remainingHeight;

			double tempSmallWidth = smallHeight; //to determine best case.
			double tempSmallHeight = smallWidth; // to determine best case.

			int xCounter, yCounter; //first case
			int xCounter2, yCounter2; //other case
			
			xCounter =(int)(bigWidth / smallWidth);
			yCounter =(int) (bigHeight / smallHeight);

			xCounter2 = (int)(bigWidth / tempSmallWidth);
			yCounter2 = (int)(bigHeight / tempSmallHeight);
			
			if((xCounter * yCounter ) < (xCounter2 * yCounter2))
			{
				smallHeight = tempSmallHeight;
				smallWidth = tempSmallWidth;
				xCounter = xCounter2;
				yCounter = yCounter2;
			}


			

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
					Rectangle tempInnerRectangle = new Rectangle(x,y,myInnerRectangle.getWidth(), myInnerRectangle.getHeight());
					//Rectangle tempInnerRectangle(x,y,myInnerRectangle.getWidth(), myInnerRectangle.getHeight());
					rrVector.add(tempInnerRectangle);

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
			shapeReferences = new Shape[rrVector.size() + 1];
			shapeReferences[0] = myOuterRectangle;
			for(int i = 0 ; i < rrVector.size() ; ++i)
			{
				shapeReferences[i+1] = rrVector.get(i);
			}
			shapeCount = rrVector.size() + 1;
		}
		else if(oRiC) //rectangleinto circle situation.
		{
			Vector<Circle> rcVector = new Vector<Circle>();
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
					Circle tempInnerCircle = new Circle(x,y,myInnerCircle.getRadius());
					rcVector.add(tempInnerCircle);
					//Circle tempInnerCircle(x,y,myInnerCircle.getRadius());
					//myCircleVector.push_back(tempInnerCircle);
					x += 2 * radius;
				}
				x = radius;
				y += 2 * radius;
			}
			
			shapeReferences = new Shape[rcVector.size() + 1];
			shapeReferences[0] = myOuterRectangle;
			for(int i = 0 ; i < rcVector.size() ; ++i)
			{
				shapeReferences[i+1] = rcVector.get(i);
			}
			shapeCount = rcVector.size() + 1;
		}
		else if(oRiT)
		{
		Vector<Triangle> rtVector = new Vector<Triangle>();
		double x1, y1;
		double x2, y2;
		double x3, y3;
		boolean flag = true;
		int xCounter = 0;
		double smallWidth = myInnerTriangle.getLength();

		double bigWidth = myOuterRectangle.getWidth();
		double bigHeight = myOuterRectangle.getHeight();

		double smallWidthHeight = ((smallWidth / 2.0) * SQRT3); //setting initial values.
		int heightCounter = (int)(bigHeight / smallWidthHeight);
		int widthCounter = (int)(bigWidth / smallWidth);


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
				Triangle tempInnerTriangle = new Triangle(x1,y1,x2,y2,x3,y3);
				//Triangle tempInnerTriangle(x1,y1,x2,y2,x3,y3);
				rtVector.add(tempInnerTriangle);
				// writes small triangle shapes.
				if(bigWidth - x1 >= smallWidth)
				{
					flag = false;
					xCounter++;
					Triangle tempInnerTriangle2 = new Triangle(x1,y1,x3,y3,x1 + smallWidth, y1);
					rtVector.add(tempInnerTriangle2);
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
		shapeReferences = new Shape[rtVector.size() + 1];
		shapeReferences[0] = myOuterRectangle;
		for(int i = 0 ; i < rtVector.size() ; ++i)
		{
			shapeReferences[i+1] = rtVector.get(i);
		}
		shapeCount = rtVector.size() + 1;

		}
		else if(oTiT) //triangle into triangle situatuon.
		{
			Vector<Triangle> ttVector = new Vector<Triangle>();
			int triangleCounter = 0;
			double x1, y1;
			double x2, y2;
			double x3, y3;
			int k = 1;
			double bigWidth = myOuterTriangle.getLength();
			double smallWidth = myInnerTriangle.getLength();
			

			int triangleCount = (int)(bigWidth / smallWidth);
			int tempTriangleCount = triangleCount;
			double bigTriangleHeight = ((bigWidth / 2.0) * SQRT3);
			double smallTriangleHeight =  ((smallWidth / 2.0) * SQRT3);
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
					Triangle tempInnerTriangle = new Triangle(x1,y1,x2,y2,x3,y3);
					ttVector.add(tempInnerTriangle);
					//Triangle tempInnerTriangle(x1,y1,x2,y2,x3,y3);
					//myTriangleVector.push_back(tempInnerTriangle);
					//fileWriter = triangleScript(x1,y1,x2,y2,x3,y3);
					if(i == tempTriangleCount - 1)
					{
						//handles the overflow shape situation
					}
					else
					{
						Triangle tempInnerTriangle2 = new Triangle(x1,y1,x3,y3,x1 + smallWidth, y1);
						ttVector.add(tempInnerTriangle2);

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
			shapeReferences = new Shape[ttVector.size() + 1];
			shapeReferences[0] = myOuterTriangle;
			for(int i = 0 ; i < ttVector.size() ; ++i)
			{
				shapeReferences[i+1] = ttVector.get(i);
			}
			shapeCount = ttVector.size() + 1;

		}
		else if(oTiR) //triangle is bigger one.(drawRectangleIntoTriangle.)
		{
			Vector<Rectangle> trVector = new Vector<Rectangle>();
			int xCount, yCount;
			int k = 1;
		
			int rectangleCounter = 0;
			double tempSmallHeight = myInnerRectangle.getWidth();
			double smallHeight = myInnerRectangle.getHeight();
			double smallWidth = myInnerRectangle.getWidth();
			double sides = (SQRT3 * smallHeight) * 2.0 / 3.0;
			double bigWidth = myOuterTriangle.getLength();
			double bigTriangleHeight = ((bigWidth / 2.0) * SQRT3);
			double startingPointX = (SQRT3 * smallHeight) / 3.0;
			double tempStartingPointX = startingPointX;
			double tempBigWidth = bigWidth;


			yCount = (int)(bigTriangleHeight / smallHeight);
			xCount = (int)((bigWidth - sides) / smallWidth);


			myOuterTriangle.setLength(bigWidth / 2.0);
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
						//Rectangle tempInnerRectangle(startingPointX, bigTriangleHeight - smallHeight,smallWidth, tempSmallHeight);
						//myRectangleVector.push_back(tempInnerRectangle);
						Rectangle tempInnerRectangle = new Rectangle(startingPointX, bigTriangleHeight - smallHeight,smallWidth, tempSmallHeight);
						trVector.add(tempInnerRectangle);
					
					startingPointX += smallWidth;
				}
				rectangleCounter += xCount;
				k++;
				xCount = (int)((tempBigWidth - (k * sides)) / smallWidth);	

				smallHeight = tempSmallHeight * k;
				startingPointX = tempStartingPointX * k;


			}
			shapeReferences = new Shape[trVector.size() + 1];
			shapeReferences[0] = myOuterTriangle;
			for(int i = 0 ; i < trVector.size() ; ++i)
			{
				shapeReferences[i+1] = trVector.get(i);
			}
			shapeCount = trVector.size() + 1;
			
		}
		else if(oTiC) //triangle into circle situation.
		{
			Vector<Circle> tcVector = new Vector<Circle>();
			double radius = myInnerCircle.getRadius();
			double circleCounter = 0;
			double bigWidth = myOuterTriangle.getLength();
		    double bigTriangleHeight = ((bigWidth / 2.0) * SQRT3); //setting initial values.
			int xCount, yCount;
			double tempRadius = radius;
			double x = radius * SQRT3;
			double y = bigTriangleHeight - tempRadius;

			yCount = (int)(bigTriangleHeight / radius * 2);
			xCount = (int)((bigWidth - 2 * radius * SQRT3) / (2 * radius)); // calculating x and y counts.

			myOuterTriangle.setLength(bigWidth / 2.0);
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
				Circle tempInnerCircle = new Circle(x,y,radius);
				tcVector.add(tempInnerCircle);
				//fileWriter = circleScript(radius, x,  y); //writes the file.
				//outfile << fileWriter;
				//outfile << "\n";
				x += tempRadius * 2;
			}
			xCount--;
			y =  bigTriangleHeight - (j + 2) * radius * SQRT3 + tempRadius - tempRadius / SQRT3;
			x = radius + (j + 2) * radius;
		}
			shapeReferences = new Shape[tcVector.size() + 1];
			shapeReferences[0] = myOuterTriangle;
			for(int i = 0 ; i < tcVector.size() ; ++i)
			{
				shapeReferences[i+1] = tcVector.get(i);
			}
			shapeCount = tcVector.size() + 1;
			
		}
		else if(oCiT) //circle into triangle situations.
		{
			myOuterCircle.setRadius(100);
			myOuterCircle.setXCoordinate(100);
			myOuterCircle.setYCoordinate(100);
			shapeReferences = new Shape[1];
			shapeReferences[0] = myOuterCircle;
			shapeCount = 1;
			
		}
		else if(oCiC) //circle into circle situation.
		{
			Vector<Circle> ccVector = new Vector<Circle>();
			int circleCount = 0;
			int baseCircleCounter;
			double bigRadius = myOuterCircle.getRadius();
			double smallRadius = myInnerCircle.getRadius();
			baseCircleCounter = (int)(bigRadius / smallRadius);

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
					Circle tempInnerCircle = new Circle(smallRadius + incX,bigRadius - incY,  tempSmallRadius);
					ccVector.add(tempInnerCircle);

					//fileWriter = circleScript(tempSmallRadius, smallRadius + incX, bigRadius - incY); // specified calculation for filling circle.
					//outfile << fileWriter; 
					//outfile << "\n";
					Circle tempInnerCircle1 = new Circle( smallRadius + incX,bigRadius + incY, tempSmallRadius);
					ccVector.add(tempInnerCircle1);

					//fileWriter = circleScript(tempSmallRadius, smallRadius + incX, bigRadius + incY);
					//outfile << fileWriter; 
					//outfile << "\n";
					incX = 2* tempSmallRadius * (i + 1);
					circleCount+=2;
				}
				incX = 0;
				baseCircleCounter--;
				smallRadius = (j + 2) * tempSmallRadius;
				incY = (j + 1) * (tempSmallRadius * SQRT3); //increments x and y values.

			}
			shapeReferences = new Shape[ccVector.size() + 1];
			shapeReferences[0] = myOuterCircle;
			for(int i = 0 ; i < ccVector.size() ; ++i)
			{
				shapeReferences[i+1] = ccVector.get(i);
			}
			shapeCount = ccVector.size() + 1;
		
		}
		else if(oCiR) //circle into rectangle situation.
		{
			Vector<Rectangle> crVector = new Vector<Rectangle>();
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
				extraSpace = bigRadius - (Math.sqrt((bigRadius * bigRadius) - (smallHeight * smallHeight)));
				tempExtraSpace = extraSpace;
				tempBigRadius = bigRadius - (extraSpace);
				xCounter = 2 * (tempBigRadius / smallWidth);
				for(int i = 0 ; i < yCounter ; ++i)
				{
					for(int j = 0 ; j < xCounter ; ++j)
					{
						if(smallWidth < (2 * bigRadius - (tempExtraSpace + incX)))
						{
							Rectangle tempInnerRectangle = new Rectangle(tempExtraSpace + incX, bigRadius - incY ,myInnerRectangle.getWidth(), myInnerRectangle.getHeight());

							crVector.add(tempInnerRectangle);
							Rectangle tempInnerRectangle1 = new Rectangle(tempExtraSpace + incX, bigRadius + incY ,myInnerRectangle.getWidth(), myInnerRectangle.getHeight());
						
							crVector.add(tempInnerRectangle1);
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
				shapeReferences = new Shape[crVector.size() + 1];
				shapeReferences[0] = myOuterCircle;
				for(int i = 0 ; i < crVector.size() ; ++i)
				{
					shapeReferences[i+1] = crVector.get(i);
				}
				shapeCount = crVector.size() + 1;
			
			}
		}

	}
	/**
	 * gets the totalShape count
	 * @return the shape count
	 */
	public int getShapeCount() {
		return shapeCount;
	}
	/**
	 * sets the shapeCount on extraordinary situations.
	 * @param shapeCount
	 */
	public void setShapeCount(int shapeCount) {
		this.shapeCount = shapeCount;
	}
	/**
	 * overriding draw method for all shapes.
	 */
	public void draw(Graphics graph)
	 {
		 for(int i = 0 ; i < shapeCount ; ++i)
		 {
			 shapeReferences[i].draw(graph);
		 }
	 }
	
	/**
	 * getter of shapeReferences
	 * @return This shapeArray will be used for converting Polygons.
	 */
	public Shape[] getAllShapes()
	{
		return shapeReferences;
	}
	@Override
	/**
	 * toCompare Method of ComposedShape
	 */
	public int toCompare(Shape genericShape) {
		// TODO Auto-generated method stub
		if(this.area() > genericShape.area())
		{
			return 1;
		}
		return 0;
	}
}
