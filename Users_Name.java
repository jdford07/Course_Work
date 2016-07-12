//John David Ford
//2 June 2016

package second_assignment;

import java.util.Random;
import java.util.Scanner;


public class Users_Name
{

	public static void main(String[] args) 
	{
		String sFirstN;
		String sLastN;
		String sEnd;
		int Randnum; 
		
		Scanner scan = new Scanner(System.in);
		
		Random generator = new Random();
		
	
		System.out.println("Please Enter Your First Name: ");
		sFirstN = scan.next();
		
		System.out.println("Please Enter Your Last Name: ");
		sLastN = scan.next();
		
		System.out.println("You've Entered: Name: "+ sFirstN + " " + sLastN + ".");
		
		
		Randnum = generator.nextInt(90) + 10;
		
		sEnd = sFirstN.substring(0, 1) + sLastN.substring(0,5) + Randnum;
		
		
		System.out.println("The Finished Product is: " + sEnd);
		
		
		scan.close();
		
	}

}
