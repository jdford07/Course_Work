package third_assignment;

public class Course 
{
	private String course;
	private int students;
	private Student stud1, stud2, stud3; 
	
	public Course(String cName)
	{
		course = cName;
		students = 0;
	}

	public void addStudent(Student studs)
	{
		
		switch (students)
		{
		case 0:
			stud1 = studs;
			break;
		case 1:
			stud2 = studs;
			break;
		case 2:
			stud3 = studs;
			break;
		default:
			System.out.println("Should have three students.");
		}
		
		students++;
	}
	
	public double avg()
	{
		return (stud1.avg() + stud2.avg() + stud3.avg())/3;
	}
	
	public void roll()
	{
		String result = "";
		result += "Course Name: "+course+"\n";
		result += "The Students Taking this Course: \n\n";
		result += "Student 1 Information: "+stud1+"\n";
		result += "Student 2 Information: "+stud2+"\n";
		result += "Student 3 Information: "+stud3+"\n";
		
		System.out.println(result);
	}
}
