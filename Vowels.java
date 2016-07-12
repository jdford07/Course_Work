package third_assignment;

import java.util.Scanner;

public class Vowels 
{

	public static void main(String[] args) 
	{
		String User;
		int a = 0, e = 0, i = 0, o = 0, u = 0;
		int non = 0;

		Scanner input = new Scanner(System.in);
		
		System.out.println("Enter a phrase.");
		User = input.nextLine();
		
		for (int x = 0; x < User.length(); x++)
		{
			char y = Character.toLowerCase(User.charAt(x));
		
			switch (y)
			{
			case 'a':
				a++;
				break;
			
			case 'e':
				e++;
				break;
				
			case 'i':
				i++;
				break;
			
			case 'o':
				o++;
				break;
			
			case 'u':
				u++;
				break;
			
			default:
				non++;
				break;
			}
		}
		System.out.println("a: " + a);
		System.out.println("e: " + e);
		System.out.println("i: " + i);
		System.out.println("o: " + o);
		System.out.println("u: " + u);
		System.out.println("non: " + non);
		
		input.close();
	}

}
