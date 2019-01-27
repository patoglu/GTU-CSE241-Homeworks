import java.awt.Graphics;
/**
 * 
 * @author Sushi
 *PolygonDyn class that holds 2D points dynamically.
 */
public class PolygonDyn extends Polygon {
	public class Point2D
	{
		private int xCoordinate;
		private int yCoordinate;
		Point2D(int theXCoordinate, int theYCoordinate)
		{
			setTwoDx(theXCoordinate);
			setTwoDy(theYCoordinate);
		}
		public int getTwoDx() {
			return xCoordinate;
		}
		public void setTwoDx(int xCoordinate) {
			this.xCoordinate = xCoordinate;
		}
		public int getTwoDy() {
			return yCoordinate;
		}
		public void setTwoDy(int yCoordinate) {
			this.yCoordinate = yCoordinate;
		}
	}
	private Point2D [] connectedDots;
	int used; 
	int capacity;
	public PolygonDyn()
	{
		capacity = 100;
		connectedDots = new Point2D[capacity];
		used = 0;
	}
	public PolygonDyn(int theCapacity)
	{
		capacity = theCapacity;
		connectedDots = new Point2D[capacity];
		used = 0;
	}
	public PolygonDyn(Rectangle rectangleObject)
	{

		capacity = 4;
		connectedDots = new Point2D[capacity];
		int x1,y1;
		int x2,y2;
		int x3,y3;
		int x4,y4;
		int width;
		int height;

		width = (int)rectangleObject.getWidth();
		height = (int)rectangleObject.getHeight();
		x1 = (int)rectangleObject.getXCoordinate();
		y1 = (int)rectangleObject.getYCoordinate();


		x2 = x1;
		y2 = y1 + height;
		x3 = x1 + width;
		y3 = y1 + height;
		x4 = x1 + width;
		y4 = y1;


		connectedDots[0].setTwoDx(x1);
		connectedDots[0].setTwoDy(y1);

		connectedDots[1].setTwoDx(x2);
		connectedDots[1].setTwoDy(y2);

		connectedDots[2].setTwoDx(x3);
		connectedDots[2].setTwoDy(y3);

		connectedDots[3].setTwoDx(x4);
		connectedDots[3].setTwoDy(y4);
		used = 4;

	}
	
	public PolygonDyn(Triangle triangleObject)
	{
		int x1,y1,x2,y2,x3,y3;
		int width;
		capacity = 3;
		connectedDots = new Point2D[capacity];
		width = (int)triangleObject.getLength();
		x1 = (int)triangleObject.getX1Coordinate();
		y1 = (int)triangleObject.getY1Coordinate();
		x2 = (int)triangleObject.getX2Coordinate();
		y2 = (int)triangleObject.getY2Coordinate();
		x3 = (int)triangleObject.getX3Coordinate();
		y3 = (int)triangleObject.getY3Coordinate();

		connectedDots[0].setTwoDx(x1);
		connectedDots[0].setTwoDy(y1);

		connectedDots[1].setTwoDx(x2);
		connectedDots[1].setTwoDy(y2);

		connectedDots[2].setTwoDx(x3);
		connectedDots[2].setTwoDy(y3);
		used = 3;


	}
	
	public PolygonDyn(Circle circleObject)
	{
		
		double counterDegree = 0;
		capacity = 100;
		connectedDots = new Point2D[capacity];
		int x,y,radius;
		double tempx, tempy;
		x = (int)circleObject.getXCoordinate();
		y = (int)circleObject.getYCoordinate();
		radius = (int)circleObject.getRadius();
		for(int i = 0 ; i < 100 ; ++i)
		{
			counterDegree += 3.6;
			tempx = x + radius * Math.cos(counterDegree * 3.14 / 180);
			tempy = y + radius * Math.sin(counterDegree * 3.14 / 180);
			connectedDots[i].setTwoDx((int)tempx);
			connectedDots[i].setTwoDy((int)tempy);
			
		}

		used = 100;

	}
	@Override
	public double area() {
		// You can't calculate unknown area.
		return -1;
	}

	@Override
	public double perimeter() {
		// You can't calculate unknown perimeter
		return -1;
	}

	@Override
	public void increment() {
		for(int i = 0 ; i < used ; ++i)
		{
			connectedDots[i].setTwoDx(connectedDots[i].getTwoDx() + 1);
			connectedDots[i].setTwoDy(connectedDots[i].getTwoDy() + 1);
		}
		
	}

	@Override
	public void decrement() {
		for(int i = 0 ; i < used ; ++i)
		{
			connectedDots[i].setTwoDx(connectedDots[i].getTwoDx() - 1);
			connectedDots[i].setTwoDy(connectedDots[i].getTwoDy() - 1);
		}
		
	}

	@Override
	public void draw(Graphics graph) {
		// TODO Auto-generated method stub
		int polygonX [] = new int [used];
		int polygonY [] = new int [used];
		for(int i = 0 ; i < used ; ++i)
		{
			polygonX[i] = connectedDots[i].getTwoDx();
			polygonY[i] = connectedDots[i].getTwoDy();
		}
		graph.drawPolygon(polygonX, polygonY, used);
	}
	@Override
	public int toCompare(Shape genericShape) {
		// TODO Auto-generated method stub
		return 0;
	}

}
