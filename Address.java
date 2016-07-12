package third_assignment;

public class Address
{
	private String StreetAddress, city, state1;
	private long zip1;
	
	public Address(String street, String town, String state, long zip)
	{
		StreetAddress = street;
		city = town;
		state1 = state;
		zip1 = zip;
	}
	
	public String toString()
	{
		String result;
		result = StreetAddress;
		result += city+ "," +state1+" "+zip1;
		
		return result;
	}
}
