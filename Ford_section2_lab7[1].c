// Lab 7: Advanced PhoneBook
// John David Ford
// 2 March 2016
// Section 2


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Phonebook                  //Structure for Phonebook Entries 
{
	char cFirstName[100];
	char cLastName[100];
	char cPhoneNumber[16];
}entries;

void addFriend (entries *, int *, int *); //Function Prototypes for Menu Options
void delFriend (entries *, int *);
void showBook (entries *, int *);
void sortBook (entries *, int *);
void findFriend (entries *, int *);
void randomFriend (entries *, int *);
void delAll (int *, int *);
void SaveAll (entries *, int*);
void LoadAll (entries **, int *, int *);



int main()
{		

	entries *phone;
	phone = (entries*) malloc(sizeof(entries)*100); //allocating memory 
	
	if (phone == NULL)                   //testing for valid results of memory allocation
	{
		printf("No memory available.\n");
	}
	else
	{
	}
	
	
	int ichoice = 0; 
	int iLength = 0;
	int iFull = 0; 
	
	do
	{
		printf("\t Please Choose an Option\n"); //Menu Options
		printf("(1) Add Friend\n");
		printf("(2) Delete Friend\n");
		printf("(3) Display Phone Book \n");
		printf("(4) Alphabetically Sort Phone Book\n");
		printf("(5) Find a Friend\n");
		printf("(6) Randomly Select a Friend\n");
		printf("(7) Delete All Friends \n");
		printf("(8) Save All Friends \n");
		printf("(9) Load All Friends \n");
		printf("(10) Exit Phonebook\n");
		scanf("%d", &ichoice);                  //Gathering choice selection
		
	if (ichoice == 1)
	{
		addFriend(phone, &iLength, &iFull);     //Executing addFriend function after chosing option 1
	}
	
	if (ichoice ==2 )
	{
		delFriend(phone, &iLength);
	}
		
	if (ichoice == 3)
	{
		showBook(phone, &iLength);
	}	
		
	if (ichoice == 4)
	{
		sortBook(phone, &iLength);
	}	
	
	if (ichoice == 5)
	{
		findFriend(phone, &iLength);
	}
	
	if (ichoice == 6)
	{
		randomFriend(phone, &iLength);
	}

	if (ichoice == 7)
	{
		delAll(&iLength, &iFull);
	}
	
	if (ichoice == 8)
	{
		SaveAll (phone, &iLength);
	}
	
	if (ichoice == 9)
	{
		LoadAll (&phone, &iLength, &iFull);
	}
	if (ichoice == 10 )
	{
		printf("Exiting Phonebook.\n");
		return 0; 
	}
	}while (ichoice <= 10);	

	free (phone);
}

void addFriend (entries *phone, int *iFull,int *iLength)
{
	printf("You have chosen to add a Friend.\n");
	
	if (*iLength == *iFull)                  // If the length of the array is equal to the max amount the array can hold more memory must be obtained
	{
		entries *NewPhone =NULL;
		NewPhone = (entries *) realloc(phone, (*iFull + 1) * sizeof(entries));
		
		if (NewPhone != NULL)                // If realloc() succeeds then phone takes on a new memory location
		{                                    // The maximum storage of iFull is now increased by 1 to show there's more room available
			phone = NewPhone;
			(*iFull)++;
		}
		
		else                                 //If realloc() fails an out of memory message is printed
		{
			perror("Sorry, Out of memory!");
			exit(EXIT_FAILURE);
		}
	}
	
	char *cUInput = NULL; //Users input will be put into cUInput string
	int iMax = 1000;  //Max characters that cUInput can store
	
	while (cUInput == NULL && iMax > 0)
	{
		cUInput = (char *) calloc(iMax + 1, sizeof(char));
		iMax -= 10; 
	}
	
	if (cUInput != NULL) //If cUInput was allocated memory then the user can now input data into the cUInput string
	{
		printf ("First Name: \n");
		scanf("%s", cUInput);
		strncpy((phone + *iLength)->cFirstName, cUInput, 99);
		printf("Last Name: \n");
		scanf("%s", cUInput);
		strncpy((phone + *iLength)->cLastName, cUInput, 99);
		printf("Phone Number: \n");
		scanf("%s", cUInput);
		strncpy((phone + *iLength)->cPhoneNumber, cUInput, 15);
		
		(*iLength)++;   //Incrementing iLength by 1 to display that an entry has been added to the phonebook.  
		printf("Friend Successfully Added!\n");
	}
	
	else
	{
		perror("Sorry, out of memory!\n");  //If cUInput was allocated memory the program will be stopped
		exit(EXIT_FAILURE);
	}
	
	free(cUInput); //Any memory allocated to cUInput is now freed
}

void delFriend (entries *phone, int *iLength)
{
	if (*iLength > 0)
	{
		printf("You have chosen to delete a Friend.\n");
		
		char *cUInputFirst = NULL; //Memory allocation similar to cUInput
		char *cUInputLast = NULL; // Takes 2 variables since first and last name match the record for deleting contact
		int iMax = 1000; 
		
		while ((cUInputLast == NULL||cUInputFirst == NULL) && iMax > 0)
		{
			cUInputLast = (char *) calloc(iMax + 1, sizeof(char)); 
			cUInputFirst = (char *) calloc (iMax + 1, sizeof(char));
			iMax -= 10; 
		}
		
		if (cUInputLast != NULL && cUInputFirst != NULL) // Can move on if memory is allocated for first and last name strings.
		{
			printf("First Name: \n");
			scanf("%s", cUInputFirst);
			printf("Last Name: \n");
			scanf("%s", cUInputLast);
			
			
			int look = 1;
			
			while ((strcmp((phone + look)->cLastName, cUInputLast) || strcmp((phone + look)-> cFirstName, cUInputFirst)) && look < *iLength)
				look++;
				// Loop looks through array of the phonebook and deletes any entry matching First and Last name
				
			if ( look < *iLength)
			{
				int move;
				for (move = look; move < *iLength - 1; move++)
				{
					strcpy((phone + move)->cFirstName, (phone + move + look)->cFirstName);
					strcpy((phone + move)->cLastName, (phone + move + look)->cLastName);
					strcpy((phone + move)->cPhoneNumber, (phone + move + look)->cPhoneNumber);
				}
				(*iLength)--;
				printf ("Friend Successfully deleted!\n");
				//Shirting array elements by 1 in the index and decrementing the length by 1
				//Entry wished to delete is either overwritten or ignored if it's at the end of teh array
			}
			else
			{
				printf("Friend not found.\n"); //If a match to the record isn't found
				
			}
		}
		
		else
		{
			perror("Sorry, Out of Memory!\n"); //If cUInputFirst and cUInputLast aren't allocated memory, stop the program
			exit(EXIT_FAILURE);
		}
		
		free(cUInputFirst); //Allocated memory is freed for both strings
		free(cUInputLast);
	}
	
	else
	{
		printf("No Friends to Delete.\n");
	}

}

void showBook (entries *phone, int *iLength)
{
	int iamount = 0; 
	if(*iLength > 1)
	{
		printf("Here's a list of all %d of your Friends: \n", *iLength);
		for (iamount = 0; iamount < *iLength; iamount++) //printing of the Phone Record List
		{
			printf("\n%s \t%s \t%s \n", (phone + iamount)->cFirstName, (phone + iamount)->cLastName, (phone + iamount)->cPhoneNumber);
		}
	}
	
	else
	{
		printf("There are no Friends to Display.\n");
	}
}

void sortBook (entries *phone, int *iLength)
{
	int iamount;
	
	if(*iLength > 1)                  //List is only sorted if the amount of contacts is more than 1.
	{
		char cChoice = '\0';          //store users choice of First or Last name Sorting
		int iSwapContacts;            //Indicates whether 2 variables have been swapped in previous list pass throughs
		entries TempoHold = {""};     //Holds entry so it's not overwritten when being swapped
		
		printf("How would you like to sort your Friends?\n");
		printf("(1) By First Name\n");
		printf("(2) By Last Name\n");
		scanf("%s", &cChoice);    //Obtaining users choice after menu is displayed
		
		do //Passthrough of array of 'entries' the adjacent entries are compared and swapped if they're not in correct order. 
		   //Process will repeat if entries had been rpeviously swapped & list will be sorted once array is passed through w/o a swap.
		{ 
			iSwapContacts = 0;
			iamount = 0;
			while (iamount < *iLength -1) 
			{
				int iNeededSwap = 0; //Indicates whether entry indexed by iamount should be exchnaged with entry in position after.
				switch (cChoice)
				{
					case '1':
						iNeededSwap = strcmp((phone + iamount)->cFirstName, (phone + iamount + 1)->cFirstName) > 0;
						break;
					case '2':
						iNeededSwap = strcmp((phone + iamount)->cLastName, (phone + iamount + 1)->cLastName) > 0;	
						break; 
				}
				if (iNeededSwap)     //If the function needs to exchange, this will do it. 
				{
					TempoHold = *(phone + iamount);
					*(phone + iamount) = *(phone + iamount + 1);
					*(phone + iamount + 1) = TempoHold;
					iSwapContacts = 1;
					
				}
				iamount++;
			}
			
		}while (iSwapContacts);
		
	}
	printf("Here's a list of all %d of your Friends sorted: \n", *iLength);
	for (iamount = 0; iamount < *iLength; iamount++) //printing of the sorted Phone Record List
	{
		printf("\n%s \t%s \t%s \n", (phone + iamount)->cFirstName, (phone + iamount)->cLastName, (phone + iamount)->cPhoneNumber);
	}
	
}

void findFriend (entries *phone, int *iLength)
{
	if (*iLength > 0) //will search if there is more than 1 friend stored
	{
		char *cUInput = NULL; //Memory allocation just as in previous functions
		int iMax = 1000;
		
		while (cUInput == NULL && iMax > 0)
		{
			cUInput = (char *) calloc(iMax + 1, sizeof(char));
			iMax -= 10;
		}
		
		if (cUInput != NULL) //will proceed to user input if cUInput was allocated memory
		{
			int iChoice = 0;
			int iFound = 0;
			int iamount = 0;
			
			printf("(1) Search by First Name.\n");
			printf("(2) Search by Last Name.\n");
			printf("(3) Search by Phone Number. \n");
			scanf("%d", &iChoice);
			
			if (iChoice == 1)
			{
				printf("First Name: \n");
				scanf("%s", cUInput);
				while (iamount < *iLength)
				{
					if(!strcmp ((phone + iamount)->cFirstName, cUInput))
					{
						printf("%s\t %s\t %s\n", (phone + iamount)->cFirstName, (phone + iamount)->cLastName, (phone + iamount)->cPhoneNumber);
						iFound = 1;
					}
					
					iamount++;
				}
			}
			
			if (iChoice == 2)
			{
				printf("Last Name: \n");
				scanf("%s", cUInput);
				while (iamount < *iLength)
				{
					if(!strcmp ((phone + iamount)->cLastName, cUInput))
					{
						printf("%s\t %s\t %s\n", (phone + iamount)->cFirstName, (phone + iamount)->cLastName, (phone + iamount)->cPhoneNumber);
						iFound = 1;
					}
					
					iamount++;
				}
			}
			
			if(iChoice == 3)
			{
				printf("Phone Number: \n");
				scanf("%s", cUInput);
				while (iamount < *iLength)
				{
					if(!strcmp ((phone + iamount)->cPhoneNumber, cUInput))
					{
						printf("%s\t %s\t %s\n", (phone + iamount)->cFirstName, (phone + iamount)->cLastName, (phone + iamount)->cPhoneNumber);
						iFound = 1;
					}
					
					iamount++;
				}
			}
			
			if(!iFound) //If iFound isn't set to 1 then no match will be found 
			{
				printf("No Friend found.\n");
			}
			
		}
		
		else
		{
			perror("Sorry! Not enough Memory!\n"); //If no memory was allocated the program will be stopped
			exit(EXIT_FAILURE);
		}
		
		free(cUInput); // Freeing memory that was allocated.
	}
	
	else
	{
		printf ("There are no Friends to choose.\n"); //If *iLength is equal to 0
	}
}

void randomFriend (entries *phone, int *iLength)
{

	if(*iLength > 0)
	{
		srand(time(NULL));
		int irandom = rand() % *iLength;
		printf ("Here's your random Friend:\n");
		printf("\n%s \t%s \t%s\n", (phone + irandom)->cFirstName, (phone + irandom)->cLastName, (phone + irandom)->cPhoneNumber);
		//displays a random index from the array of 'entries'
	}
	
	else
	{
		printf("There are no Friends to choose.\n"); //If there are no entries that are currently in the record
	}
}
 
void delAll (int *iLength, int *iFull)
{
    // If no entries are stored, the request is declined and the user is informed.
    if (*iLength > 0) {
        
        // The user chooses whether to confirm the decision to delete all contacts.
        char cConfirm = '\0';
        printf ("\nDo you wish to delete all of your friends?");
        printf ("\n\t(1) Yes");
        printf ("\n\t(2) No\n");
        scanf("%s", &cConfirm, '2');

        /* If the user chooses to continue deleting all contacts, the following
         * procedure is executed: the length and capacity counters of the PhoneBook
         * are both set to zero.
         */
        if (cConfirm == '1') {
            *iLength = 0;
            *iFull = 0;
            printf ("All Friends have been deleted successfully.\n");
    	}
    	else
            printf ("All friends have been retained successfully.\n");
    }
    else
        printf ("You have no friends to delete.\n");
}

void SaveAll (entries *phone, int *iLength)
{
    // The function will not attempt to save contacts if none are in memory.
    if (*iLength > 0) 
	{

        /* The constant string pointer cDefaultName stores the default file location.
         * cFileChoice stores the user's choice: whether 1) to enter a file location
         * or 2) accept the default file location. The FILE pointer pWrite will hold
         * the address of the filestream where the data will be saved.
         */
        const char *cDefault = "friends.dat";
        char cChoice = '\0';
        char cFile[51] = "";
        FILE *pWrite = NULL;
        
        // The user chooses whether to specify a path or accept the default.
        printf ("\nWhere do you wish to save your friends?");
        printf ("\n\t(1) Specify a file path.");
        printf ("\n\t(2) Use default path.\n");
        scanf("%s", &cChoice, '2');
		
        /* If the user chose to enter a file location, then she is prompted
         * for one and the input is saved as cInputString and copied to
         * cFileName.  If she chose to accept the default, then cDefaultFileName
         * is copied to cFileName.
         */
        if (cChoice == '1') {
            char *cUI = NULL;	
            int iMax = 1000;
            while (cUI == NULL && iMax > 0) {
                cUI = (char *) calloc(iMax + 1, sizeof(char)); 
                iMax -= 10;
            }

            if (cUI != NULL) {
                printf ("Filename? ");
                scanf ("%s", cUI);
                strncpy (cFile, cUI, 50);
            }
            else {
                // If cInputString was not allocated memory, terminate the program.
                perror("Sorry! No memory.");
                exit(EXIT_FAILURE); 
            }
            // Allocated memory is freed from cInputString. 
            free(cUI);
        }
        else 
            strncpy (cFile, cDefault, 50);

        // The file is opened for writing, and the filestream is saved as pWrite.
        pWrite = fopen(cFile, "w");

        // If the file was opened successfully, we continue. Otherwise, an error is printed.
        if (pWrite != NULL) {

            // The first field of data written to the file is the number of entries. 
            fprintf (pWrite, "%d\n", *iLength);

            // Now, the entries are written to the file using a for-loop.
            int a;
            for (a = 0; a < *iLength; a++) 
                fprintf (pWrite, "%s\t%s\t%s\n", (phone + a)->cFirstName, (phone + a)->cLastName, (phone + a)->cPhoneNumber);
		
            // Finally, the file is closed, and a message is printed to the user.
            fclose (pWrite);
            printf ("Friends successfully saved to %s.\n", cFile);
        }
        else 
            printf ("Invalid Request!.\n");
    }
    // If no contacts are in memory, then an error is printed to the user and the program continues.
    else
        printf ("You have no friends to save.\n");
}

void LoadAll (entries **phone, int *iLength, int *iFull)
{
    char cConfirm = '1';

    /* If there are contacts in memory, the user is asked whether to proceed
     * with loading from the file, which will overwrite the stored contacts.
     */
    if (*iLength > 0) {
        printf ("\nYour currently stored friends will be lost. Continue?");
        printf ("\n\t(1) Yes");
        printf ("\n\t(2) No\n");
        scanf("%s", &cConfirm, '2');
    }

    /* If there were no contacts stored in memory, or if the user decided
     * to overwrite them, then the procedure continues.  Otherwise, loading
     * the contacts is aborted and the contacts stored in memory are retained.
     */
    if (cConfirm == '1') {
        const char *cDefault = "friends.dat";
        char cChoice = '\0';
        char cFile[51] = "";
        FILE *pRead = NULL; 

        // The user chooses whether to specify a path or accept the default.
        printf ("\nWhere are your friends currently saved?");
        printf ("\n\t(1) Specify a path.");
        printf ("\n\t(2) Use default path.\n");
        scanf("%s", &cChoice, '2');

        // If the user chose to specify a path:		

        if (cChoice == '1') {
            char *cUI = NULL;	
            int iMax = 1000;
            while (cUI == NULL && iMax > 0) {
                cUI = (char *) calloc(iMax + 1, sizeof(char)); 
                iMax -= 10;
            }

            if (cUI != NULL) {
                    // Get the user's path choice and copy it to cFileName.
                    printf ("File name?\n ");
                    scanf ("%s", cUI);
                    strncpy (cFile, cUI, 50);
                }
            else {
                // If cInputString was not allocated memory, terminate the program.
                perror("Sorry! No memory.");
                exit(EXIT_FAILURE); 
            }
            // Allocated memory is freed from cInputString. 
            free(cUI);
        }
        else
            // If the user chose to accept the default path: 
            strncpy (cFile, cDefault, 50);

        // Open the file for reading.
        pRead = fopen(cFile, "r");

        /* If the file was opened successfully, begin loading data.  Otherwise
         * issue an error.
         */
        if (pRead != NULL) {
            /* Read the first field in the data file as an integer.  This will be
             * the number of records which will be stored.  Since struct array
             * may not hold enough space for this many records, this value must
             * be used to allocate space.
             */
            int iNewFull = 0;
            fscanf (pRead, "%d", &iNewFull);

            entries *NewPhone = NULL;
            NewPhone = (entries *) realloc(*phone, iNewFull * sizeof(entries));

            /* If the allocation was successful, then the struct array is moved to the
             * the new pointer, and the new capacity is recorded.
             */
            if (NewPhone != NULL) {
                *phone = NewPhone;
                *iFull= iNewFull;
            }
            else {
                // If the allocation was unsuccesful, the program ends.
                perror ("Sorry! No memory.");
                exit(EXIT_FAILURE);
            }
            
            /* Now, the data can be read into the array of ContactType.  The integer
             * value at the beginning of the file determined how many entries will be
             * read.
             */
            int b;
            for (b = 0; b < *iFull; b++) 
                fscanf (pRead, "%s%s%s", (*phone + b)->cFirstName, (*phone + b)->cLastName, (*phone + b)->cPhoneNumber);
            
            /* The length of the list of entries is recorded as *iCap, the number of 
             * entries saved.
             */
            *iLength = *iFull;
            // Close the file and notify the user that the contacts have been loaded.
            fclose (pRead);
            printf ("Friends successfully loaded from %s.\n", cFile);
        }
        else {
            // If the file could not be opened, notify the user.
            printf ("Invalid Request.\n");
            printf ("Currently stored friends have been successfully retained.\n");
        }
    }
    else
        // If the user chose not to overwrite stored contacts, notify her and continue execution.
        printf ("Currently stored friends have been successfully retained.\n");
}
