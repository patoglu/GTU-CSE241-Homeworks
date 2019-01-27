import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

public class CCGUI extends JPanel{
	public void paintComponent(Graphics g)
	{
		
			super.paintComponent(g);
			g.setColor(Color.RED);
			Circle outerCirc = new Circle(0,0,200);
			Circle innerCirc = new Circle(0,0,20);
			ComposedShape tryComp = new ComposedShape(outerCirc, innerCirc); 
			tryComp.optimalFit(); 
			tryComp.draw(g); 
		
	}
	
}