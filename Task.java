package third_assignment;

public class Task implements Priority
	{
		private String priority, input;
		private int difficulty;
	
	public Task(String input, int difficulty, String priority)
	{
		this.input = input;
		this.priority = priority;
		this.difficulty = difficulty;
		
		if (priority == "Extreme")
		{
			difficulty = 5;
		}
		
		if (priority == "Important")
		{
			difficulty = 4;
		}
		
		if (priority == "Average")
		{
			difficulty = 3;
		}
		
		if (priority == "Low")
		{
			difficulty = 2;
		}
		
		if (priority == "Minimal")
		{
			difficulty = 1;
		}
		
	}

	public void setPriority(int difficulty)
	{
		this.difficulty = difficulty;
	}
	
	public String toString()
		{
			return input+ " has Priority Level: " + difficulty + ", " + priority;
		}
	public int getPriority()
	{
		System.out.println(toString());
		System.out.print("Final Numeric Priority: ");
		return difficulty;
	}

	

}


