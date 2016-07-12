package fourth_assignment;

import javax.swing.JPanel;
import javax.swing.Timer;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class CarMove extends JPanel
	{
	
		private javax.swing.Timer timer;
		private int DELAY = 20;
		
		private int x1 = 275, x2 = 75, x3 = 345, x4 = 375;
		private int y1 = 250, y2 = 235;
		private int[] xCMid = {100,300,300,100};
		private int[] yCMid = {150,150,275,275};
			
		private int[] xCFront = {300,400,400,300};
		private int[] yCFront = {200,200,275,275};
			
		private int[] xCBack = {75,100,100,75};
		private int[] yCBack = {200,200,275,275};
		
		public CarMove()
			{
				timer = new Timer(DELAY, new CarMoveListener());
			
				setBackground(Color.gray);
				setPreferredSize(new Dimension(500,500));
				
				timer.start();
			}
		
		public void paintComponent(Graphics page)
			{
		
				super.paintComponent(page);
			
				page.setColor(Color.orange);
				page.fillPolygon(xCMid, yCMid, xCMid.length);
				page.setColor(Color.orange);
				page.fillPolygon(xCFront, yCFront, xCFront.length);
				page.setColor(Color.orange);
				page.fillPolygon(xCBack, yCBack, xCBack.length);
			
				page.setColor(Color.black);
				page.fillOval(x1, y1, 50, 50);
				page.setColor(Color.black);
				page.fillOval(x2, y1, 50, 50);
			
				page.setColor(Color.white);
				page.fillOval(x3, y2, 25, 25);
				page.setColor(Color.white);
				page.fillOval(x4, y2, 25, 25);
			
				page.setColor(Color.black);
				page.drawPolygon(xCFront, yCFront, xCFront.length);
				page.setColor(Color.black);
				page.drawPolygon(xCBack, yCBack, xCBack.length);
				page.setColor(Color.black);
				page.drawPolygon(xCMid, yCMid, xCMid.length);
				
			}
		
	private class CarMoveListener implements ActionListener
	{
		public void actionPerformed (ActionEvent event)
		{
			for (int a = 0; a < xCFront.length; a++)
				{
					xCFront[a] = xCFront[a] + 5;
					xCBack[a] = xCBack[a] + 5;
					xCMid[a] = xCMid[a] + 5;
				}
			x1 = x1 + 5;
			x2 = x2 + 5;
			x3 = x3 + 5;
			x4 = x4 + 5;

			
			repaint();
		}
	}
}

			
				

