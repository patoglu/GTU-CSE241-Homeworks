import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

public class RRGUI extends JPanel{
	public void paintComponent(Graphics g)
	{
			super.paintComponent(g);
			g.setColor(Color.RED);
			Rectangle outerRect = new Rectangle(0,0,600,600);
			Rectangle innerRect = new Rectangle(0,0,20,20);
			ComposedShape tryComp = new ComposedShape(outerRect, innerRect);
			tryComp.optimalFit();
			tryComp.draw(g);	
	}
	
}