//John David Ford
//5-18-2016


package first_assignment;

import java.awt.Graphics;
import javax.swing.JApplet;

public class Einstein_Edit extends JApplet
{
	private static final long serialVersionUID= 1L;
	
	public void paint(Graphics page)
	{
		super.paint(page);
		page.drawRect(50, 50, 40, 40); // square
		page.drawRect(60, 80, 225, 30); // rectangle
		page.drawOval(274, 98, 20, 20); // circle
		page.drawLine(35, 60, 100, 120); // line

		page.drawString("Out of clutter, find simplicity.", 110, 70);
		page.drawString("-- Albert Einstein", 130, 100);

	}

}
