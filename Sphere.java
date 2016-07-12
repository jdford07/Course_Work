//John David Ford
//2 June 2016

package second_assignment;

import java.util.Scanner;
import java.text.DecimalFormat;


public class Sphere 
{

	public static void main(String[] args) 
	{
		double dRad;
		double dVol;
		double dSArea;
		
		Scanner scan = new Scanner(System.in);
		
		DecimalFormat fmt = new DecimalFormat("0.####");
		
		
		System.out.println("Please Enter the Radius of Your Sphere: ");
		dRad = scan.nextInt();
		
		
		dVol = ((4.0 / 3)*((Math.PI)*Math.pow(dRad, 3)));
		
		dSArea = ((4.0)*((Math.PI)*Math.pow(dRad, 2)));
		
		
		System.out.println("The Total Volume of Your Sphere is: " + fmt.format(dVol));
		
		System.out.println("The Total Surface Area of Your Sphere is: " + fmt.format(dSArea));
		
		
		scan.close();
	}
}
