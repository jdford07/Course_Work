package third_assignment;

import java.text.NumberFormat;

public class Account
{
		  private final double RATE = 0.035;  // interest rate of 3.5%

		  private long acctNumber;
		  private double balance;
		  private String name;

		  public Account (String owner, long account, double initial)
		  {
		     name = owner;
		     acctNumber = account;
		     balance = initial;
		  }
		  
		  String cat = "cat";
		  
		  
		  public double deposit (double amount)
		  {
			  if (amount >= 0)
			  { 
				 balance = balance + amount;
				 return balance;
			  }
			  else
			  {
				  System.out.println("You can't deposit a negative amount! Try Again.");
				  return balance;
			  }
			  
		  }
		  
		
		  public double withdraw (double amount, double fee)
		  {
			  if (amount > (balance - fee))
			  {
				  System.out.println("Not enough funds to withdraw: " +amount);
				  return balance;
			  }
			  else
			  {
		     balance = balance - amount - fee;
		     return balance;
			  }
		  }

		  public double addInterest ()
		  {
		     balance += (balance * RATE);
		     return balance;
		  }

		  public double getBalance ()
		  {
		     return balance;
		  }

		  public String toString ()
		  {	   
			 NumberFormat fmt = NumberFormat.getCurrencyInstance();
		     return (acctNumber + "\t" + name + "\t" + fmt.format(balance));
		  }
}
