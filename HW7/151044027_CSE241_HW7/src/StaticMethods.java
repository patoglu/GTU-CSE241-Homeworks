import javax.swing.JFrame;

public class StaticMethods {
	public static void SortShapes()


	{
		Triangle myTriangle = new Triangle();
		Rectangle myRectangle = new Rectangle();
		Circle circ1 = new Circle(0,0,10);
		Circle circ2 = new Circle(0,0,2);
		Circle circ3 = new Circle(10,10,20);
		Circle circ4 = new Circle(1,1,1);
		Rectangle rect1 = new Rectangle(0,0,19,20);
		Rectangle rect2 = new Rectangle(0,0,1,4);
		Rectangle rect3 = new Rectangle(0,0,12,2);
		Rectangle rect4 = new Rectangle(0,0,122,2);
		System.out.println("Testing to Compare method...");
		Shape [] shapeArray = new Shape[10];
		shapeArray[0] = circ1;
		shapeArray[1] = circ2;
		shapeArray[2] = circ3;
		shapeArray[3] = circ4;
		shapeArray[4] = myTriangle;
		shapeArray[5] = rect1;
		shapeArray[6] = rect2;
		shapeArray[7] = rect3;
		shapeArray[8] = circ4;
		shapeArray[9] = rect4;
		
		System.out.println("Before sorting: ");
		for(int i = 0 ; i < 10 ; ++i)
		{
			System.out.print(shapeArray[i]);
			System.out.print(" AREA: ");
			System.out.println(shapeArray[i].area());
		}
		shapeArray[0] = rect2;
		shapeArray[1] = rect3;
		shapeArray[2] = rect1;
		shapeArray[3] = rect4;
		shapeArray[4] = rect3;
		shapeArray[5] = rect1;
		shapeArray[6] = rect2;
		shapeArray[7] = rect3;
		shapeArray[8] = rect4;
		shapeArray[9] = rect4;
		System.out.println("After sorting: ");
		for(int i = 0 ; i < 10 - 1 ; ++i)
		{
			for(int j = 0 ; j < 10 - 1 ; ++j)
			{
				if(shapeArray[j].area() > shapeArray[j+1].area())
				{
						Shape tempShape = new Rectangle();
						tempShape = shapeArray[j];
						shapeArray[j] = shapeArray[j+1];
						shapeArray[j+1] = tempShape;	
				}
			}
		}
		for(int i = 0 ; i < 10 ; ++i)
		{
			System.out.print(shapeArray[i]);
			System.out.print(" AREA: ");
			System.out.println(shapeArray[i].area());
		}
		Shape [] shapeCirc = new Shape[4];
		shapeCirc[0] = circ3;
		shapeCirc[1] = circ2;
		shapeCirc[2] = circ1;
		shapeCirc[3] = circ4;
		
		
		System.out.println("Before sorting: ");
		for(int i = 0 ; i < 4 ; ++i)
		{
			System.out.print(shapeCirc[i]);
			System.out.print(" AREA: ");
			System.out.println(shapeCirc[i].area());
		}
		for(int i = 0 ; i < 4 - 1 ; ++i)
		{
			for(int j = 0 ; j < 4 - 1 ; ++j)
			{
				if(shapeCirc[j].area() > shapeCirc[j+1].area())
				{
						Shape tempShape = new Circle();
						tempShape = shapeCirc[j];
						shapeCirc[j] = shapeCirc[j+1];
						shapeCirc[j+1] = tempShape;	
				}
			}
		}
		System.out.println("After sorting: ");
		for(int i = 0 ; i < 4 ; ++i)
		{
			System.out.print(shapeCirc[i]);
			System.out.print(" AREA: ");
			System.out.println(shapeCirc[i].area());
		}
	}
	public static void drawAll()
	{
		//Here I will return Shape references from ComposedShape object then I will draw them.
		Rectangle myRectangle = new Rectangle(0,0,200,200);
		Circle myCircle = new Circle(0,0,10);
		ComposedShape returnShapeRef = new ComposedShape(myRectangle, myCircle);
		returnShapeRef.optimalFit();
		//Creating new Shape references array.
		int shapeCount = returnShapeRef.getShapeCount();
		Shape shapeReferences[] = new Shape[shapeCount];
		shapeReferences = returnShapeRef.getAllShapes();
		
		for(int i = 0 ; i < shapeCount ; ++i)
		{
			System.out.println(shapeReferences[i]);
		}
	}
	public static void convertAll()
	{
		//Here I will return Shape references from ComposedShape object then I will draw them.
		Circle myCircle = new Circle(0,0,10);
		Rectangle myRect = new Rectangle(0,0,20,40);
		Triangle myTriangle = new Triangle(0,0,0,0,0,0);
		Shape convertAllShapes[] = new Shape[3];
		convertAllShapes[0] = myCircle;
		convertAllShapes[1] = myTriangle;
		convertAllShapes[2] = myRect;
		PolygonVect polygonConverted [] = new PolygonVect[3];
		//Converting to Polygon...
		for(int i = 0 ; i < 3 ; ++i)
		{
			polygonConverted[i] = new PolygonVect(myCircle);
		}
		
	}
}
