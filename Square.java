//John David Ford
//5-18-2016


package first_assignment;

import java.util.Scanner;

public class Square {

	public static void main(String[] args)
	{
		int iLength;
		int iArea;
		int iPerimeter;
		
		Scanner scan = new Scanner(System.in);
		
		System.out.println("Length of Square side:  ");
		iLength = scan.nextInt();
		
		iArea = iLength * iLength;
		iPerimeter = iLength * 4;
		
		System.out.println("The Area of the Square is: " +iArea);
		System.out.println("The Perimeter of the Square is: " +iPerimeter);
		
		scan.close();
		
	}

}
