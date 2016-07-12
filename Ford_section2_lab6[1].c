//Lab 6: PhoneBook
//John David Ford
// 23 February 2016
// Section 2

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Phonebook
{
	char cFirstName[20];
	char cLastName[20];
	char cPhoneNumber [20];
	
}phone;

void addFriend(phone * );
void delFriend (phone * );
void displayBook (phone * );


int counter = 0;
char FileName[256];
FILE *pRead;
FILE *pWrite;

int main(void)
{
	
	phone *phonebook;
	phonebook = (phone*) malloc(sizeof(phone)*100);
	int ichoice = 0;
	
	if (phonebook == NULL)
	{
		printf("Something went wrong.\n");
		return 1; 
	}
	else
	{}
	
	do
	{
		printf("\t-Phonebook-\t\n");
		printf("(1) Add Friend\n");
		printf("(2) Delete Friend\n");
		printf("(3) Display Phone Book\n");
		printf("(4) Exit Phonebook\n");
		printf("Please choose an option.\n");
		scanf("%d", &ichoice);
	
	if(ichoice == 1)
	{
		addFriend(phonebook);
	}
	
	if(ichoice == 2)
	{
		delFriend(phonebook);
	}
	
	if(ichoice == 3)
	{
		displayBook(phonebook);
	}
	
	if(ichoice == 4)
	{
		printf("Exiting Phonebook.\n");
		return 0;
	}
	}while (ichoice <=5);
	
}

void addFriend (phone * phonebook)
{
	pWrite = fopen("Phonebook.dat", "a");
	if (pWrite == NULL)
	{
		perror("The following error occurred: ");
		exit(EXIT_FAILURE);
	}
	else
	{	
		counter ++;
		
		printf("\nFirst Name: \n");
		scanf("%s", phonebook[counter-1].cFirstName);
		printf("Last Name: \n");
		scanf("%s", phonebook[counter-1].cLastName);
		printf("Phone Number: \n");
		scanf("%s", phonebook[counter-1].cPhoneNumber);
		printf("Friend successfully added!\n");
		
		fprintf(pWrite,"%s\t%s\t%s \n", phonebook[counter-1].cFirstName, phonebook[counter-1].cLastName, phonebook[counter-1].cPhoneNumber);
		fclose(pWrite);
	}
}

void delFriend(phone*phonebook)
{
	int x = 0;
	int i = 0;
	char delFirstName[20];
	char delLastName[20];
	
	printf("First Name: \n");
	scanf("%s", delFirstName);
	printf("Last Name: \n");
	scanf("%s", delLastName);
	
	for (x = 0; x < counter; x++)
	{
		if(strcmp(delFirstName, phonebook[x].cFirstName) == 0)
		{
			if(strcmp(delLastName, phonebook[x].cLastName) == 0)
			{
			for (i = x; i < counter - 1; i++ )
			{
				strcpy(phonebook[i].cFirstName, phonebook[i+1].cFirstName);
				strcpy(phonebook[i].cLastName, phonebook[i+1].cLastName);
				strcpy(phonebook[i].cPhoneNumber, phonebook[i+1].cPhoneNumber);
			}
			printf("Friend Deleted successfully!\n");
			--counter;
			return;
			}
		}
	
	
	}
	printf("That friend was not found, please enter a different friend.\n");
}
void displayBook (phone * phonebook)
{
	int x = 0;
	printf("\n Phonebook Entries: \n");
	pRead = fopen("Phonebook.dat", "r");
	if ( pRead == NULL)
	{
		perror ("The following error occurred: ");
		exit(EXIT_FAILURE);
	}
	else
	{
		for( x = 0; x < counter; x++)
		{
			printf("\n%d\n", x+1);
			printf("Name: %s %s \n", phonebook[x].cFirstName, phonebook[x].cLastName);
			printf("Number: %s\n", phonebook[x].cPhoneNumber);
		}
	}
	fclose(pRead);
}

