import java.awt.Graphics;

public class Triangle implements Shape {
	private double length;
	private double x1Coordinate;
	private double y1Coordinate;
	private double x2Coordinate;
	private double y2Coordinate;
	private double x3Coordinate;
	private double y3Coordinate;
	private static final double SQRT3 = 1.73;
	public Triangle()
	{
		this(0,0,0,0,0,0,10);
	}
	public Triangle(double theX1Coordinate, double theY1Coordinate, double theX2Coordinate, double theY2Coordinate, double theX3Coordinate, double theY3Coordinate, double theLength)
	{
		if(theX1Coordinate < 0 || theY1Coordinate < 0 || theX2Coordinate < 0 || theY2Coordinate < 0 || theX3Coordinate < 0 || theY3Coordinate < 0)
		{
			throw new IllegalArgumentException("bad_param!");
		}
		{
			
		}
		setX1Coordinate(theX1Coordinate);
		setX2Coordinate(theX2Coordinate);
		setY1Coordinate(theY1Coordinate);
		setY2Coordinate(theY2Coordinate);
		setX3Coordinate(theX3Coordinate);
		setY3Coordinate(theY3Coordinate);
		setLength(theLength);
	}
	public Triangle(double theX1Coordinate, double theY1Coordinate, double theX2Coordinate, double theY2Coordinate, double theX3Coordinate, double theY3Coordinate)
	{
		setX1Coordinate(theX1Coordinate);
		setX2Coordinate(theX2Coordinate);
		setY1Coordinate(theY1Coordinate);
		setY2Coordinate(theY2Coordinate);
		setX3Coordinate(theX3Coordinate);
		setY3Coordinate(theY3Coordinate);
		setLength(0);
	}
	@Override
	public double area() {
		// TODO Auto-generated method stub
		return (length * length * SQRT3) / 4.0;
	}

	@Override
	public double perimeter() {
		// TODO Auto-generated method stub
		return 3 * length;
	}

	@Override
	public void increment() {
		setX1Coordinate(getX1Coordinate() + 1);
		setY1Coordinate(getY1Coordinate() + 1);
		setX2Coordinate(getX2Coordinate() + 1);
		setY2Coordinate(getY2Coordinate() + 1);
		setX3Coordinate(getX3Coordinate() + 1);
		setY3Coordinate(getY3Coordinate() + 1);
		
	}

	@Override
	public void decrement() {
		setX1Coordinate(getX1Coordinate() - 1);
		setY1Coordinate(getY1Coordinate() - 1);
		setX2Coordinate(getX2Coordinate() - 1);
		setY2Coordinate(getY2Coordinate() - 1);
		setX3Coordinate(getX3Coordinate() - 1);
		setY3Coordinate(getY3Coordinate() - 1);
		
	}
	public double getX1Coordinate() {
		return x1Coordinate;
	}
	public void setX1Coordinate(double x1Coordinate) {
		this.x1Coordinate = x1Coordinate;
	}
	public double getY1Coordinate() {
		return y1Coordinate;
	}
	public void setY1Coordinate(double y1Coordinate) {
		this.y1Coordinate = y1Coordinate;
	}
	public double getX2Coordinate() {
		return x2Coordinate;
	}
	public void setX2Coordinate(double x2Coordinate) {
		this.x2Coordinate = x2Coordinate;
	}
	public double getY2Coordinate() {
		return y2Coordinate;
	}
	public void setY2Coordinate(double y2Coordinate) {
		this.y2Coordinate = y2Coordinate;
	}
	public double getX3Coordinate() {
		return x3Coordinate;
	}
	public void setX3Coordinate(double x3Coordinate) {
		this.x3Coordinate = x3Coordinate;
	}
	public double getY3Coordinate() {
		return y3Coordinate;
	}
	public void setY3Coordinate(double y3Coordinate) {
		this.y3Coordinate = y3Coordinate;
	}
	public void setLength(double theLength)
	{
		length = theLength;
	}
	public double getLength()
	{
		return length;
	}
	@Override
	public String toString()
	{
		return "[TRIANGLE]" + " = " + "(" + this.getX1Coordinate() + " , " + this.getY1Coordinate() + " , " + this.getX2Coordinate() + " , " + this.getY2Coordinate() + " , "+ this.getX3Coordinate() + " , " + this.getY3Coordinate()  + ") " + "Length = " + this.getLength();
	}
	public void draw(Graphics graph)
	{
		 graph.drawPolygon(new int[] {(int)x1Coordinate, (int)x2Coordinate, (int)x3Coordinate},new int[] {(int)y1Coordinate, (int)y2Coordinate, (int)y3Coordinate}, 3);
	}
	@Override
	public int toCompare(Shape genericShape) {
		if(this.area() > genericShape.area())
		{
			return 1;
		}
		return 0;
	}
}	
