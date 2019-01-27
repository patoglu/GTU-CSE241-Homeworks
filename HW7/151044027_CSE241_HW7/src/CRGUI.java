import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

public class CRGUI extends JPanel{
	public void paintComponent(Graphics g)
	{
		
			super.paintComponent(g);
			g.setColor(Color.RED);
			Circle outerCirc = new Circle(0,0,200);
			Rectangle innerRect = new Rectangle(0,0,40,20);
			ComposedShape tryComp = new ComposedShape(outerCirc, innerRect); 
			tryComp.optimalFit(); 
			tryComp.draw(g); 
		
	}
	
}