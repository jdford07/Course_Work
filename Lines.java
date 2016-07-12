package third_assignment;


import javax.swing.JFrame;


public class Lines {

	public static void main(String[] args) 
	{
		JFrame frame = new JFrame("Parallel Lines");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		SubLines panel1 = new SubLines();
		
		frame.getContentPane().add(panel1);
		
		
		frame.pack();
		frame.setVisible(true);
		

	}

}
