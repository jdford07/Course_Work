package third_assignment;

public class Student
{
	private String	firstName, lastName;
	private Address	homeAddress, schoolAddress;
	private int tscore1, tscore2, tscore3;

	public Student()
	{
		tscore1 = 0;
		tscore2 = 0;
		tscore3 = 0;
	}

	public Student(String first, String last, Address home, Address school, int test1, int test2, int test3)
	{
		firstName = first;
		lastName = last;
		homeAddress = home;
		schoolAddress = school;
		tscore1 = test1;
		tscore2 = test2;
		tscore3 = test3;
	}

	public void setTScore(int test, int scores)
	{
		if (test == 1)
		{
			tscore1 = scores;
		}
		else if (test == 2)
		{
			tscore2 = scores;
		}
		else if (test == 3)
		{
			tscore3 = scores; 
		}
		else
		{
			System.out.println("Limit of 3 tests. You can't enter more than 3.");
			System.exit(0);
		}
	}
	
	public int getTScore(int test)
	{
		int scores = -1;
		if (test == 1)
		{
			scores = tscore1;
		}
		else if (test == 2)
		{
			scores = tscore2;
		}
		else if (test == 3)
		{
			scores = tscore3; 
		}
		else
		{
			System.out.println("Limit of 3 tests. You can't enter more than 3.");
			System.exit(0);
		}
		return scores;
	}
	
	public double avg()
	{
		double totalsum = tscore1 + tscore2 + tscore3;
		return totalsum /3;
	}
	
	public String toString()
	{
		String result;

		result = firstName + " " + lastName + "\n";
		result += "Home Address:" + homeAddress +"\n";
		result += "School Address:" + schoolAddress+"\n";
		result += "Three test scores:\nTest 1: "+getTScore(1)+"\nTest 2: "+getTScore(2)+"\nTest 3: "+getTScore(3)+"\n";
		result += "The average of all Test scores: " +avg()+"\n\n";
		return result;
	}
}
