//Lab 3: Calculator
//John David Ford
//2 February 2016
//Section 2

#include<stdio.h>

main()
{
	int iOperationChoose = 0;
	float fUserFirst = 0;
	float fUserSecond =0;
	int iUserFirst = 0;
	int iUserSecond = 0; 
	int i, j; 
	 
	
	while (iOperationChoose != 7)
	{
		printf("Calculator Menu\n (1)Addition\n (2)Subtraction\n (3)Multiplication\n (4)Division \n (5)Modulus\n (6)Prime Number Testing\n (7)Exit\n\n");
		printf("Please choose an operation to perform:\n");
		scanf("%d", &iOperationChoose);
		if (iOperationChoose <1 || iOperationChoose > 10)
		{
			printf("Please choose a number between 1 and \n");
		}
		else
		{
		if(iOperationChoose == 7)
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
			printf("The result of %.2f + %.2f is = %.2f", fUserFirst, fUserSecond, fUserFirst + fUserSecond);
			printf("\n");

		}
		if (iOperationChoose == 2) //Subtraction Operation
		{
			printf("Please enter your first integer: \n");
			scanf("%f", &fUserFirst);
			printf("Please enter your second integer: \n");
			scanf("%f", &fUserSecond);
			printf("The result of %.2f - %.2f = %.2f", fUserFirst, fUserSecond, fUserFirst - fUserSecond);
			printf("\n");
			
		}
		if (iOperationChoose == 3) //Multiplication Operation
		{
			printf("Please enter your first integer: \n");
			scanf("%f", &fUserFirst);
			printf("Please enter your second integer: \n");
			scanf("%f", &fUserSecond);
			printf("The result of %.2f * %.2f = %.2f", fUserFirst, fUserSecond, fUserFirst * fUserSecond);
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
					printf("The result of %.2f / %.2f = %.2f", fUserFirst, fUserSecond, fUserFirst / fUserSecond);
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
				printf("%d %% %d = %d", iUserFirst, iUserSecond, iUserFirst % iUserSecond);
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
			for (i=2; i<iUserFirst; i++)
			{
			
					if (iUserFirst % i == 0)
					{
						j = 0;
						printf("n%d is not a prime number: %d * %d = %d \n\n", iUserFirst, i, iUserFirst/i, iUserFirst);
						break;
						
					}
					else
					{
						j = 1; 
					}
					if (j==1)
					{
						printf("\n%d is a Prime number. \n\n", iUserFirst);
						break;
					}
				}
			}
		}
			
	}
	return 0; 
}
