package third_assignment;

public class TaskDriver {

	public static void main(String[] args) 
	{
		Task task1 = new Task("Walk the dog" ,1, "Minimal");
		Task task2 = new Task("Take out the trash",2, "Low");
		Task task3 = new Task("Go workout",3, "Average");
		Task task4 = new Task("Cook dinner",4, "Important");
		Task task5 = new Task("Finish homework", 5, "Extreme");
		
		System.out.println(""+task1.getPriority());
		System.out.println("");
		System.out.println(""+task2.getPriority());
		System.out.println("");
		System.out.println(""+task3.getPriority());
		System.out.println("");
		System.out.println(""+task4.getPriority());
		System.out.println("");
		System.out.println(""+task5.getPriority());
		
	}

}
