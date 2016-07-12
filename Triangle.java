//John David Ford
// 2 June 2016

package second_assignment;

import java.util.Scanner;
import java.text.DecimalFormat;

public class Triangle 
{

	public static void main(String[] args) 
	{
		double TriSideA;
		double TriSideB;
		double TriSideC;
		double TriArea;
		double TriPerimeter;
		double TriSideTotal;
		
		
		Scanner scan = new Scanner(System.in);
		
		DecimalFormat fmt = new DecimalFormat("0.###");
		
		
		System.out.println("Length of Side A: ");
		TriSideA = scan.nextInt();
		
		System.out.println("Length of Side B: ");
		TriSideB = scan.nextInt();
		
		System.out.println("Length of Side C: ");
		TriSideC = scan.nextInt();
		
		
		TriPerimeter = (TriSideA + TriSideB + TriSideC)/2;
		
		TriSideTotal = (TriPerimeter)*((TriPerimeter - TriSideA)*(TriPerimeter - TriSideB)*(TriPerimeter - TriSideC));
		
		TriArea = Math.sqrt(TriSideTotal);
		
		
		System.out.println("The Area of Your Triangle Using Heron's Formula is: " + fmt.format(TriArea));
		
		
		scan.close();
		
	}

}
