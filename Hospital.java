package fourth_assignment;

class HospitalEmployee
	{
		String name, address, phonenum;
		int empnumber;
		
		public HospitalEmployee (String name, String address, String phonenum, int empnumber)
			{
				this.name = name;
				this.address = address;
				this.phonenum = phonenum;
				this.empnumber = empnumber;
			}
		
		public void print()
			{
				System.out.println("Hospital Employee Information: ");
				System.out.println("Name: " +name);
				System.out.println("Address: "+address);
				System.out.println("Phone Number: "+phonenum);
				System.out.println("Employee Number: "+empnumber);
				
			}
	}

class PatientCare extends HospitalEmployee
	{
		int permitnum;
		String permitexpdate;
		
		public PatientCare (String name, String address, String phonenum, int empnumber, int permitnum, String permitexpdate)
			{
				super (name, address, phonenum, empnumber);
				this.permitnum = permitnum;
				this.permitexpdate = permitexpdate;
			}
	}

class Doctor extends PatientCare
	{
		public Doctor (String name, String address, String phonenum, int empnumber, int permitnum, String permitexpdate)
			{	
				super (name, address, phonenum, empnumber, permitnum, permitexpdate);
			}
		
		public void print()
			{
				System.out.println("Hospital Employee Information: ");
				System.out.println("Name: " +name);
				System.out.println("Address: "+address);
				System.out.println("Phone Number: "+phonenum);
				System.out.println("Employee Number: "+empnumber);
				System.out.println("Practice Permit Number: "+permitnum);
				System.out.println("Practice Permit Expiry Date: "+permitexpdate);
			}
	}
	
class Surgeon extends Doctor
	{
		public Surgeon (String name, String address, String phonenum, int empnumber, int permitnum, String permitexpdate)
			{
			super (name, address, phonenum, empnumber, permitnum, permitexpdate);
			}
	}



