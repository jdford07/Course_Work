package fourth_assignment;

import javax.swing.JPanel;
import java.awt.*;

public class Car extends JPanel
	{
		private int[] xCMid = {100,300,300,100};
		private int[] yCMid = {150,150,275,275};
		
		private int[] xCFront = {300,400,400,300};
		private int[] yCFront = {200,200,275,275};
		
		private int[] xCBack = {75,100,100,75};
		private int[] yCBack = {200,200,275,275};
		
		public Car()
			{
				setBackground(Color.gray);
				setPreferredSize(new Dimension(500,500));
			}
	
public void paintComponent(Graphics page)
	{
		super.paintComponent(page);
		
		page.setColor(Color.orange);
		page.fillPolygon(xCMid, yCMid, 4);
		page.setColor(Color.orange);
		page.fillPolygon(xCFront, yCFront, 4);
		page.setColor(Color.orange);
		page.fillPolygon(xCBack, yCBack, 4);
		
		page.setColor(Color.black);
		page.fillOval(275, 250, 50, 50);
		page.setColor(Color.black);
		page.fillOval(75, 250, 50, 50);
		
		page.setColor(Color.white);
		page.fillOval(345, 235, 25, 25);
		page.setColor(Color.white);
		page.fillOval(375, 235, 25, 25);
		
		page.setColor(Color.black);
		page.drawPolygon(xCFront, yCFront, 4);
		page.setColor(Color.black);
		page.drawPolygon(xCBack, yCBack, 4);
		page.setColor(Color.black);
		page.drawPolygon(xCMid, yCMid, 4);
		
	}
}
