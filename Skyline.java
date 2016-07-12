package second_assignment;

import javax.swing.JFrame;

public class Skyline 
{

	public static void main(String[] args)
		{
			JFrame frame = new JFrame ("Skyline");
			frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			frame.setSize(900, 400);
			frame.setVisible(true);
			Star stars = new Star (500,75,250);
			frame.add(stars);
		}

}
