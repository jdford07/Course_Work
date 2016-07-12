package second_assignment;


class FlightTest
{
	public static void main(String[] args)
	{
		Flight First = new Flight ("American Airlines","Louisville", " New York", 90816);
		Flight Second = new Flight ("American Airlines", "New York", "Boston" , 90816);
		Flight Third = new Flight ("United Airlines", "Boston", "Detroit", 53164);
		Flight Fourth = new Flight ("Frontier", "Detroit", "London, England", 85147);
		Flight Fifth = new Flight ("New England Airlines", "London, England", "Louisville", 63259);
			
		System.out.println(First);
		System.out.println(Second);
		System.out.println(Third);
		System.out.println(Fourth);
		System.out.println(Fifth);

	}
}
