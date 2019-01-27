import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

public class TRGUI extends JPanel{
	public void paintComponent(Graphics g)
	{
			super.paintComponent(g);
			g.setColor(Color.RED);
			Triangle outerTri = new Triangle(0,0,0,0,0,0,600);
			Rectangle innerRect = new Rectangle(0,0,20,20);
			ComposedShape tryComp = new ComposedShape(outerTri, innerRect);
			tryComp.optimalFit();
			tryComp.draw(g);
		
	}
}