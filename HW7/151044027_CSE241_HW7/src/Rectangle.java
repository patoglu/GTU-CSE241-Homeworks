import java.awt.Graphics;
import java.awt.Graphics2D;

public class Rectangle implements Shape {
	private double width;
	private double height;
	private double xCoordinate;
	private double yCoordinate;
	
	public Rectangle()
	{
		setWidth(10);
		setHeight(10);
		setXCoordinate(0);
		setYCoordinate(0);
	}
	public Rectangle(double theXCoordinate, double theYCoordinate, double theWidth, double theHeight)
	{
		if(theXCoordinate < 0 || theYCoordinate < 0 || theWidth < 0 || theHeight < 0)
		{
			throw new IllegalArgumentException("Bad Param!");
		}
		setWidth(theWidth);
		setHeight(theHeight);
		setXCoordinate(theXCoordinate);
		setYCoordinate(theYCoordinate);
		
	}
	@Override
	 public double area() {
		return (width * height);
	}

	@Override
	public double perimeter() {
		return ((width + height) * 2);
	}

	@Override
	public void increment() {
		xCoordinate++;
		yCoordinate++;
		
	}

	@Override
	public void decrement() {
		xCoordinate--;
		yCoordinate--;
		
	}
	public void setWidth(double theWidth)
	{
		width = theWidth;
	}
	public void setHeight(double theHeight)
	{
		height = theHeight;
	}
	public void setXCoordinate(double theXCoordinate)
	{
		xCoordinate = theXCoordinate;
	}
	public void setYCoordinate(double theYCoordinate)
	{
		yCoordinate = theYCoordinate;
	}
	public double getXCoordinate()
	{
		return xCoordinate;
	}
	public double getYCoordinate()
	{
		return yCoordinate;
	}
	public double getWidth()
	{
		return width;
	}
	public double getHeight()
	{
		return height;
	}
	@Override
	 public void draw(Graphics graph)
	 {
		 graph.drawRect((int)xCoordinate, (int)yCoordinate, (int)width, (int)height);
	 }
	@Override
	public int toCompare(Shape genericShape) {
		if(this.area() > genericShape.area())
		{
			return 1;
		}
		return 0;
	}
	@Override
	public String toString()
	{
		return "[RECTANGLE]" + " = " + "(" + this.getXCoordinate() + " , " + this.getYCoordinate() + ") " + "Width = " + this.getWidth()+ " Height = " + this.getHeight();
	}
}
