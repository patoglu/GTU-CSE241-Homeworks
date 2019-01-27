import java.awt.Graphics;
import java.util.ArrayList;



public class PolygonVect extends Polygon{
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
	private ArrayList<Point2D> connectedDots;
	public PolygonVect()
	{
	}
	public PolygonVect(int theCapacity)
	{
		connectedDots = new ArrayList<Point2D>();
	}
	public PolygonVect(Rectangle rectangleObject)
	{
		connectedDots = new ArrayList<Point2D>();
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


		connectedDots.get(0).setTwoDx(x1);
		connectedDots.get(0).setTwoDy(y1);

		connectedDots.get(1).setTwoDx(x2);
		connectedDots.get(1).setTwoDy(y2);

		connectedDots.get(2).setTwoDx(x3);
		connectedDots.get(2).setTwoDy(y3);

		connectedDots.get(3).setTwoDx(x4);
		connectedDots.get(3).setTwoDy(y4);

	}
	
	public PolygonVect(Triangle triangleObject)
	{
		int x1,y1,x2,y2,x3,y3;
		int width;

		connectedDots = new ArrayList<Point2D>();
		width = (int)triangleObject.getLength();
		x1 = (int)triangleObject.getX1Coordinate();
		y1 = (int)triangleObject.getY1Coordinate();
		x2 = (int)triangleObject.getX2Coordinate();
		y2 = (int)triangleObject.getY2Coordinate();
		x3 = (int)triangleObject.getX3Coordinate();
		y3 = (int)triangleObject.getY3Coordinate();

		connectedDots.get(0).setTwoDx(x1);
		connectedDots.get(0).setTwoDy(y1);

		connectedDots.get(1).setTwoDx(x2);
		connectedDots.get(1).setTwoDy(y2);

		connectedDots.get(2).setTwoDx(x3);
		connectedDots.get(2).setTwoDy(y3);


	}
	
	public PolygonVect(Circle circleObject)
	{
		
		double counterDegree = 0;
		
		connectedDots = new ArrayList<Point2D>();
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
			connectedDots.get(i).setTwoDx((int)tempx);
			connectedDots.get(i).setTwoDy((int)tempy);
			
		}
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
		for(int i = 0 ; i < connectedDots.size() ; ++i)
		{
			connectedDots.get(i).setTwoDx(connectedDots.get(i).getTwoDx() + 1);
			connectedDots.get(i).setTwoDy(connectedDots.get(i).getTwoDy() + 1);
		}
		
	}

	@Override
	public void decrement() {
		for(int i = 0 ; i < connectedDots.size() ; ++i)
		{
			connectedDots.get(i).setTwoDx(connectedDots.get(i).getTwoDx() - 1);
			connectedDots.get(i).setTwoDy(connectedDots.get(i).getTwoDy() - 1);
		}
		
	}

	@Override
	public void draw(Graphics graph) {
		// TODO Auto-generated method stub
		int polygonX [] = new int [connectedDots.size()];
		int polygonY [] = new int [connectedDots.size()];
		for(int i = 0 ; i < connectedDots.size() ; ++i)
		{
			polygonX[i] = connectedDots.get(i).getTwoDx();
			polygonY[i] = connectedDots.get(i).getTwoDy();
		}
		graph.drawPolygon(polygonX, polygonY, connectedDots.size());
	}
	@Override
	public int toCompare(Shape genericShape) {
		// TODO Auto-generated method stub
		return 0;
	}
}
