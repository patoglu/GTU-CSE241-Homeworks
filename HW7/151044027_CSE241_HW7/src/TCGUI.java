import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

public class TCGUI extends JPanel{
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		g.setColor(Color.RED);
		Triangle outerTri = new Triangle(0,0,0,0,0,0,600);
		Circle innerCirc = new Circle(0,0,30);
		ComposedShape tryComp = new ComposedShape(outerTri, innerCirc);
		tryComp.optimalFit();
		tryComp.draw(g);
		
	}
}