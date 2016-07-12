//John David Ford
//2 June 2016
package second_assignment;

import java.awt.Color;
import java.awt.Graphics;
import java.util.Random;
import javax.swing.JPanel;

public class Star extends JPanel
	{
		public int width;
		public int x;
		public int y;
		Random rand = new Random();
		
		public Star(int Startx, int Starty, int Startwidth)
			{
				x = Startx;
				y = Starty;
				width = Startwidth;
			
			}
		
		public void draw(Graphics Graph)
			{
				this.setBackground(Color.BLACK);
				Graph.setColor(Color.YELLOW);
				Graph.drawLine(x, y, (x + (width/3)), (y + ((width/3)*2)));
				Graph.drawLine(x, y, (x - (width/3)), (y + ((width/3)*2)));
				Graph.drawLine((x+(width/3)), y + ((width/3)*2), (x-(width/2)), (y+(width/4)));
				Graph.drawLine((x-(width/2)), (y+(width/4)), (x+(width/2)), (y+(width/4)));
				Graph.drawLine((x+(width/2)), (y+(width/4)), (x-(width/3)), (y+((width/3)*2)));
			}
		
		public void paintComponent(Graphics Graph)
			{
				super.paintComponent(Graph);
				draw(Graph);
			
				for (int a = 0; a < 20; a++)
					{
						drawStars(Graph);
				
					}
			}
	
		public void drawStars(Graphics Graph)
			{
				int newwidth = rand.nextInt((150-10) + 1) +10;
				int newx = rand.nextInt((850-150) + 1) + 150;
				int newy = rand.nextInt((380-20) + 1) + 20;
				Graph.setColor(Color.YELLOW);
				Graph.drawLine(newx, newy, (newx + (newwidth/3)), (newy + ((newwidth/3)*2)));
				Graph.drawLine(newx, newy, (newx - (newwidth/3)), (newy + ((newwidth/3)*2)));
				Graph.drawLine((newx+(newwidth/3)), newy + ((newwidth/3)*2), (newx-(newwidth/2)), (newy+(newwidth/4)));
				Graph.drawLine((newx-(newwidth/2)), (newy+(newwidth/4)), (newx+(newwidth/2)), (newy+(newwidth/4)));
				Graph.drawLine((newx+(newwidth/2)), (newy+(newwidth/4)), (newx-(newwidth/3)), (newy+((newwidth/3)*2)));
			
			}
	}
