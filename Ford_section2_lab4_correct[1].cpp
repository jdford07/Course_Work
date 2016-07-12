//Lab 4: Advanced Calculator
//John David Ford
//2 February 2016
//Section 2

#include<stdio.h>

	float addTwoNumbers(float fUserFirst, float fUserSecond);
	float subtractTwoNumbers(float fUserFirst, float fUserSecond);
	float divideTwoNumbers(float fUserFirst, float fUserSecond);
	float multiplyTwoNumbers (float fUserFirst, float fUserSecond); 
	int ModulusTwoNumbers(int iUserFirst, int iUserSecond);
	int PrimeNumbers(int iUserFirst);
	int FactorialNumbers(int iUserFirst);
	float PowerNumbers(float fUserFirst, float fUserSecond);
	int i,j = 0;
	
	
	
main()
{
	int iOperationChoose = 0;
	float fUserFirst = 0;
	float fUserSecond =0;
	int iUserFirst = 0;
	int iUserSecond = 0; 
	int i, j; 
	int result;
	int primenumber = 0;
	int x = 0; 
	 
	
	while (iOperationChoose != 10)
	{
		printf("Calculator Menu\n (1)Addition\n (2)Subtraction\n (3)Multiplication\n (4)Division \n (5)Modulus\n (6)Prime Number Testing\n (7)Factorial\n (8)Power\n (9)Your Function\n (10) Exit\n\n");
		printf("Please choose an operation to perform:\n");
		scanf("%d", &iOperationChoose);
		if (iOperationChoose <1 || iOperationChoose > 10)
		{
			printf("Please choose a number between 1 and \n");
		}
		else
		{
			if(iOperationChoose == 10)
			{
				printf("Goodbye!\n");
			}
		}
		if (iOperationChoose == 1) //Addition Operation
		{
			printf("Please enter your first integer: \n");
			scanf("%f", &fUserFirst);
			printf("Please enter your second integer: \n");
			scanf("%f", &fUserSecond);
			printf("The result of %.2f + %.2f is = %.2f", fUserFirst, fUserSecond, addTwoNumbers(fUserFirst, fUserSecond));
			printf("\n");

		}
		if (iOperationChoose == 2) //Subtraction Operation
		{
			printf("Please enter your first integer: \n");
			scanf("%f", &fUserFirst);
			printf("Please enter your second integer: \n");
			scanf("%f", &fUserSecond);
			printf("The result of %.2f - %.2f = %.2f", fUserFirst, fUserSecond, subtractTwoNumbers(fUserFirst, fUserSecond));
			printf("\n");
			
		}
		if (iOperationChoose == 3) //Multiplication Operation
		{
			printf("Please enter your first integer: \n");
			scanf("%f", &fUserFirst);
			printf("Please enter your second integer: \n");
			scanf("%f", &fUserSecond);
			printf("The result of %.2f * %.2f = %.2f", fUserFirst, fUserSecond, multiplyTwoNumbers(fUserFirst, fUserSecond));
			printf("\n");
			
		}
		if (iOperationChoose == 4) //Division Operation
		{
			printf("Please enter your first integer: \n");
			scanf("%f", &fUserFirst);
			printf("Please enter your second integer: \n");
			scanf("%f", &fUserSecond);
			if (fUserSecond == 0) //Checking to see if User inputs 0 in the denominator 
			{
				printf("Cannot divide by 0\n"); //Statement not allowing division by 0
				printf("Please choose another integer other than 0.\n");
				printf("\n");
				
			}
			else
			{
					printf("The result of %.2f / %.2f = %.2f", fUserFirst, fUserSecond, divideTwoNumbers(fUserFirst, fUserSecond));
					printf("\n");
					
			} 
		}
		if (iOperationChoose == 5) //Modulus Operation
		{
			printf("Please enter your first integer: \n");
			scanf("%d", &iUserFirst);
			printf("Please enter your second integer: \n");
			scanf("%d", &iUserSecond);
			printf("\n");
			
			if(iUserSecond == 0)
			{
				printf("Cannot divide by 0\n"); //Statement declaring you can't divide by 0
				printf("\n");
				
			}
			else
			{
				printf("%d %% %d = %d", iUserFirst, iUserSecond, ModulusTwoNumbers(iUserFirst, iUserSecond));
				printf("\n");
			
			}
		}
		if (iOperationChoose == 6) //Prime Number Testing Operation
		{
			printf("Please enter an integer to test: \n");
			scanf("%d", &iUserFirst);
			
			if(iUserFirst == 0 || iUserFirst == 1)
			{
				printf("This integer is not valid.\n");
				printf("\n");
				
			}
			else
			{
				result = PrimeNumbers(iUserFirst);
				if (result == 0)
				{
					printf("\n%d is not a prime number. \n\n", iUserFirst);
				}
				else
				{
					printf("\n%d is a prime number!\n\n", iUserFirst);
				}
				
			}
		}
		if (iOperationChoose == 7) // Factorial Number Testing
		{
			printf("Please enter an integer: \n");
			scanf("%d",&iUserFirst);
			printf("The factorial of %d is: %d.\n", iUserFirst, FactorialNumbers(iUserFirst));
			printf("\n");
		}
			
	}
	return 0; 
}
	// Addition Function definition
		float addTwoNumbers(float fUserFirst, float fUserSecond)
		{
			return fUserFirst + fUserSecond;
		}
		
	// Subtraction Function definition
		float subtractTwoNumbers(float fUserFirst, float fUserSecond)
		{
			return fUserFirst - fUserSecond;
		}
	// Multiplication Function definition
		float multiplyTwoNumbers(float fUserFirst,float fUserSecond)
		{
			return fUserFirst * fUserSecond;
		}
	// Division Function definition
		float divideTwoNumbers(float fUserFirst, float fUserSecond)
		{
			return fUserFirst / fUserSecond;
		}	
	// Modulus Function definition
		int ModulusTwoNumbers (int iUserFirst, int iUserSecond)
		{
			return iUserFirst % iUserSecond;
		}
	// Prime Number Testing Function definition
		int PrimeNumbers(int iUserFirst)
		{
			for (i=2; i<iUserFirst; i++)
			{
				if (iUserFirst % i == 0)
				{
					j = 0;
					return 0;
					break;						
				}
				else
				{
					j = 1; 
				}
				if (j==1)
				{
					return 1;
					break;	
				}
			}
		}
	// Factorial Number Testing Function definition
		int FactorialNumbers(int iUserFirst)
		{
			int a;
			long result = 1;
			
			for(a = 1; a<=iUserFirst; a++)
			
			result = result * a ;
			
			return 0; 
		}
	//Power Number Testing Function definition
	
	//Fibonacci Sequence Testing Function definition
	
