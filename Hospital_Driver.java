package fourth_assignment;

public class Hospital_Driver 
{

	public static void main(String[] args)
	{
		HospitalEmployee hospemp1 = new HospitalEmployee("Mary Coeburn", "4786 Dairy Lane", "909-871-8167", 2137845);
		PatientCare pat1 = new PatientCare("Josh Heffinstein", "7212 Milk That Cow Drive", "909-789-1231", 8907123, 13546, "May 7th 2056");
		Doctor doc1 = new Doctor("Bob Hart", "1505 Save That Cow Lane", "909-678-1271", 8091231, 32454, "April 9th 2083");
		Surgeon surg1 = new Surgeon("Ellie Death", "4658 That Cow Died Drive", "909-784-1325", 1325671, 78952, "August 6th 2165");
		
		hospemp1.print();
		System.out.println("--------------------------------------");
		pat1.print();
		System.out.println("--------------------------------------");
		doc1.print();
		System.out.println("--------------------------------------");
		surg1.print();
		
	}

}
