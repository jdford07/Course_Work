package third_assignment;

public class CourseDriver
{
	public static void main(String[] args)
	{
		Course cc = new Course("Java");
	
		Address school = new Address(" 123 There ", "Double Crown Town", "WI", 50268);
	
		Address home1 = new Address(" 123 Here ", "Triple Crown City","WI", 50214);
		Student Kyle = new Student("Kyle", "Jones", home1, school, 99,90,87);
	
		Address home2 = new Address(" 567 Here ", "Triple Crown City","WI", 63529);
		Student Gabby = new Student("Gabby", "Hotpocket", home2, school, 62,85,73);
	
		Address home3 = new Address(" 890 Here ", "Triple Crown City","WI", 45061);
		Student Lina = new Student("Lina", "Karmichael", home3, school, 95,96,97);
	
		cc.addStudent(Kyle);
		cc.addStudent(Gabby);
		cc.addStudent(Lina);
	
		cc.roll();
	
		System.out.println("The average of all test scores taken by all students: "+cc.avg());
	}
	
	
}
