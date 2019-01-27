import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

public class RCGUI extends JPanel{
	public void paintComponent(Graphics g)
	{
			super.paintComponent(g);
			g.setColor(Color.RED);
			Rectangle outerRect = new Rectangle(0,0,600,600);
			Circle innerCirc = new Circle(0,0,20);
			ComposedShape tryComp = new ComposedShape(outerRect, innerCirc);
			tryComp.optimalFit();
			tryComp.draw(g);
		
	}
}