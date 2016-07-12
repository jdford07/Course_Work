//John David Ford
//5-18-2016

package first_assignment;

import java.util.Scanner;

public class Time_Duration {

	public static void main(String[] args) 
	{
		double dtimeHrs;
		double dtimeMins;
		double dtimeSecs;
		double dtimeTotal;
		
		Scanner scan = new Scanner(System.in);
		
		System.out.println("Enter the number of Hours: ");
		dtimeHrs = scan.nextInt();
		
		System.out.println("Enter the number of Minutes: ");
		dtimeMins = scan.nextInt();
		
		System.out.println("Enter the number of Seconds: ");
		dtimeSecs = scan.nextInt();
		
		dtimeTotal = (dtimeHrs * 3600) + (dtimeMins * 60) + (dtimeSecs);
		
		System.out.println(dtimeHrs + " Hours(s)  " + dtimeMins + " Minutes(s)  " + dtimeSecs +" Second(s) is equal to: " + dtimeTotal + " seconds" );
		
		
		scan.close();

	}

}
