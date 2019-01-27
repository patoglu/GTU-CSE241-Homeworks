import java.awt.Graphics;

/**
 * @author Sushi
 *
 */
public class Circle implements Shape {
	private double radius;
	private double xCoordinate;
	private double yCoordinate;
	/**
	 * Circle default constructor
	 */
	Circle()
	{
		this(0,0,10);
	}
	/**
	 * 
	 * @param theXCoordinate specified x coordinate
	 * @param theYCoordinate specified y coordinate
	 * @param theRadius specified radius
	 */
	Circle(double theXCoordinate, double theYCoordinate, double theRadius)
	{
		if(theXCoordinate < 0 || theYCoordinate < 0 || theRadius < 0)
		{
			throw new IllegalArgumentException("Bad_Param");
		}
		setXCoordinate(theXCoordinate);
		setYCoordinate(theYCoordinate);
		setRadius(theRadius);
	}
	/**
	 * Returns the area of Circle.
	 */
	@Override
	public double area() {
		// TODO Auto-generated method stub
		return Math.PI * radius * radius;
	}

	/**
	 * Returns the area of Circle
	 */
	@Override
	public double perimeter() {
		// TODO Auto-generated method stub
		return Math.PI * 2 * radius; 
	}

	/**
	 * Increments the coordinates.
	 */
	@Override
	public void increment() {
		xCoordinate++;
		yCoordinate++;
		
	}
	/**
	 * Decrements the coordinates.
	 */
	@Override
	public void decrement() {
		xCoordinate--;
		yCoordinate--;
		
	}
	/**
	 * 
	 * @param theRadius radius value of circle
	 */
	public void setRadius(double theRadius)
	{
		radius = theRadius;
	}
	/**
	 * 
	 * @param theXCoordinate setter of xCoordinate
	 */
	public void setXCoordinate(double theXCoordinate)
	{
		xCoordinate = theXCoordinate;
	}
	/**
	 * 
	 * @param theYCoordinate setter of yCoordinate
	 */
	public void setYCoordinate(double theYCoordinate)
	{
		yCoordinate = theYCoordinate;
	}
	/**
	 * 
	 * @return returns theXCoordinate
	 */
	public double getXCoordinate()
	{
		return xCoordinate;
	}
	/**
	 * 
	 * @return returns theYCoordinate
	 */
	public double getYCoordinate()
	{
		return yCoordinate;
	}
	/**
	 * 
	 * @return returns theRadius
	 */
	public double getRadius()
	{
		return radius;
	}
	/**
	 * Overriding toString for Circle stats.
	 */
	@Override
	public String toString()
	{
		return "[CIRCLE]" + " = " + "(" + this.getXCoordinate() + " , " + this.getYCoordinate() + ") " + "Radius = " + this.getRadius();
	}
	/**
	 * Virtual draw function.
	 */
	public void draw(Graphics graph)
	{
		 xCoordinate = xCoordinate-(radius/2);
		 yCoordinate = yCoordinate-(radius/2);
		 graph.drawOval((int)xCoordinate, (int)yCoordinate, (int)(radius), (int)(radius));
	}
	/**
	 * toCompare method
	 */
	@Override
	public int toCompare(Shape genericShape) {
		if(this.area() > genericShape.area())
		{
			return 1;
		}
		return -1;
	}

}
