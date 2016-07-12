//John David Ford
//5-18-2016


package first_assignment;

import java.util.Scanner;

public class Coins {

	public static void main(String[] args)
	{
		int iQuarters;
		int iDimes;
		int iNickels;
		int iPennies;
		int itotalVal;
		int iDollars;
		int iCents;
		
		Scanner scan = new Scanner(System.in);
		
		System.out.println("Number of Quarters: ");
		iQuarters = scan.nextInt();
		
		System.out.println("Number of Dimes: ");
		iDimes = scan.nextInt();
		
		System.out.println("Number of Nickels: ");
		iNickels = scan.nextInt();
		
		System.out.println("Number of Pennies: ");
		iPennies = scan.nextInt();
		
		itotalVal = (iQuarters * 25) + (iDimes * 10) + (iNickels * 5) + (iPennies);
		
		iDollars = (itotalVal/100);
		iCents = (itotalVal) -(iDollars * 100);
		
		System.out.println(iQuarters+" Quater(s)  "+iDimes+" Dimes(s)  "+iNickels+" Nickel(s)  "+iPennies+" Pennie(s)  is "+iDollars+" Dollar(s) and "+iCents+" cents.");
		
	scan.close();
	

	}
}
