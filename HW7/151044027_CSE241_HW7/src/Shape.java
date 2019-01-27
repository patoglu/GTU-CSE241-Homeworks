import java.awt.Graphics;
import java.util.List;
import java.util.Set;

/**
 * 
 */

/**
 * @author Sushi
 *Interface file for Shape. 
 *Common methods are listed.
 */
public interface Shape extends Comparable{
	/**
	 * 
	 * @return the area of shape.
	 */
	public double area();
	/**
	 * 
	 * @return the perimeter of shape.
	 */
	public double perimeter();
	/**
	 * increments the coordinates.
	 */
	public void increment();
	/**
	 * decrements the coordinates
	 */
	public void decrement();
	/**
	 * 
	 * @param graph draws shapes with graphics object.
	 */
	public void draw(Graphics graph);
}
