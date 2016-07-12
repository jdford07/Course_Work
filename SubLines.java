package third_assignment;

import java.awt.*;
import javax.swing.JPanel;
import java.util.Random;

public class SubLines extends JPanel
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	public SubLines()
		{
			setBackground(Color.black);
			setPreferredSize(new Dimension(500,250));
		}
	public void paintComponent(Graphics lines)
	{
		int x,y = 0;
		int counter = 0;
		Random generator = new Random();
		
		super.paintComponent(lines);
		
		lines.setColor(Color.yellow);
		
		do 
		{
			int i = 10;
			y += i;
			x = generator.nextInt(155)+55;
			lines.drawLine(0, y, x, y);
			counter++;
		} while (counter <= 20);
		
	}
}