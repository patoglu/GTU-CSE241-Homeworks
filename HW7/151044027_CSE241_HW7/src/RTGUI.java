import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

public class RTGUI extends JPanel{
	public void paintComponent(Graphics g)
	{
			super.paintComponent(g);
			g.setColor(Color.RED);
			Rectangle outerRect = new Rectangle(0,0,600,600);
			Triangle innerTri = new Triangle(0,0,0,0,0,0,20);
			ComposedShape tryComp = new ComposedShape(outerRect, innerTri);
			tryComp.optimalFit();
			tryComp.draw(g);
		
		
		
	}
	
}