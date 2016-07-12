//John David Ford
//2 June 2016

package second_assignment;


public class Flight
{		
		private String sAirlineN;
		private String sFlightStart;
		private String sFlightEnd;
		private int iFlightNum;
		
		
	public Flight(String sAirlineN, String sFlightStart, String sFlightEnd, int iFlightNum)
		{
			this.sAirlineN = sAirlineN;
			this.sFlightStart = sFlightStart;
			this.sFlightEnd = sFlightEnd;
			this.iFlightNum = iFlightNum;
		}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------	
	
	public String getAirlineName()
		{
			return sAirlineN;
		}
	
	
	public String getFlightStart()
		{
			return sFlightStart;
		}	

	
	public String getFlightEnd()
		{
			return sFlightEnd;
		}
	
	
	public int getFlightNumber()
		{
			return iFlightNum;
		}
		
	
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------	
	public void setAirlineName(String sAirlineN)
		{
			this.sAirlineN = sAirlineN;
		}
	public void setFlightStart(String sFlightStart)
		{
			this.sFlightStart = sFlightStart;
		}

	
	public void setFlightEnd (String sFlightEnd)
		{
			this.sFlightEnd = sFlightEnd;
		}
	

	public void setFlightNumber(int iFlightNum)
		{
			this.iFlightNum = iFlightNum;
		}
	
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
	public String toString()
		{
			return "You Will be Flying " + sAirlineN + " To " + sFlightEnd + " From " +sFlightStart + " On Flight " + iFlightNum + " .";
		}
}


			
