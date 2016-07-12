package fourth_assignment;

import javax.swing.JFrame;

public class CarMoveDriver
{

	public static void main(String[] args) 
	{
		JFrame  frame = new JFrame("Moving Car");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		CarMove panel = new CarMove();
		
		frame.getContentPane().add(panel);
		frame.pack();
		frame.setVisible(true);

	}

}
