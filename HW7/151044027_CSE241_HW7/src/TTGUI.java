import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

public class TTGUI extends JPanel{
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		g.setColor(Color.RED);
		Triangle outerTri = new Triangle(0,0,0,0,0,0,600);
		Triangle innerTri = new Triangle(0,0,0,0,0,0,20);
		ComposedShape tryComp = new ComposedShape(outerTri, innerTri);
		tryComp.optimalFit();
		tryComp.draw(g);
		
	}
}