package fourth_assignment;

import javax.swing.JFrame;

public class CarDriver
{

	public static void main(String[] args) 
	{
		JFrame  frame = new JFrame("Car");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Car panel = new Car();
		
		frame.getContentPane().add(panel);
		frame.pack();
		frame.setVisible(true);

	}

}
