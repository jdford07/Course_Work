package fourth_assignment;

import java.io.*;

public class Arbitrary_Integers 
{

	@SuppressWarnings("deprecation")
	public static void main(String[] args) throws IOException
	{
		DataInputStream streamin = new DataInputStream(System.in);
		final int MAX = 50;
		final int MIN = 0;
		
		int[] stream = new int[MAX + 1];
		
		for ( int a = 0; a <stream.length; a++)
			{
				stream[a] = 0;
			}
		
		System.out.println("Please enter integers ranging from Zero to Fifty (0-50)");
		System.out.println("If you wish to stop entering integers enter an integer out of the current range.");
		System.out.println("Please Enter an Integer: ");
		int valuein = Integer.parseInt(streamin.readLine());
		
		
		while ( valuein >= MIN && valuein <= MAX)
			{
				stream[valuein] = stream[valuein] + 1;
				
				System.out.println("Please Enter an Integer: ");
				valuein = Integer.parseInt(streamin.readLine());
			}
		
		System.out.println("\n This is how many of each integer were entered: ");
		
		for (int b = 0; b < stream.length; b++)
		{
			if (stream[b] > 0)
			{
				System.out.println(b + ": " + stream[b]);
			}
		}
		
		
	}

}
