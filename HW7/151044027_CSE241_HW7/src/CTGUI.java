import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

public class CTGUI extends JPanel{
	public void paintComponent(Graphics g)
	{
		
			super.paintComponent(g);
			g.setColor(Color.RED);
			Circle outerCirc = new Circle(0,0,200);
			Triangle innerRect = new Triangle(0,0,0,0,0,0,10);
			ComposedShape tryComp = new ComposedShape(outerCirc, innerRect); 
			tryComp.optimalFit(); 
			tryComp.draw(g); 
		
	}
	
}