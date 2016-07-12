//Lab 5: Interactive Story
//John David Ford
//18 February 2016
//Section 2

#include <stdio.h>


int main()
{
	char cUserName[16];
	char cUserFirstinp[16];
	char cUserSecondinp[16];
	char cUserThirdinp[16];
	char cUserFourthinp[16];
	char cUserFifthinp[16];
	int iRandomItem1 = 0;
	int iRandomItem2 = 0;
	int iAge = 0;
	
	srand(time(NULL));
	iRandomItem1 = rand()%6;
	iRandomItem2 = rand()%3;
	char *cColorItem[6] = {"laptop", "Ford Thundebird", "camaro", "mustang", "house", "chair"};
	char *cSportsTeam[6] = {"at their house", "at the bar", "in a chair", "with their spouse", "alone", "on the couch"};
	char *cShapeItem[6] = {"fruit", "towels", "buildings", "people", "airplanes", "cellphones"};
	char *cRestaurantFood[6] = {"the bread", "the pasta", " the cheese", "the chocolate cake", "the steak", "the fruit"};
	char *cDrink[6] = {"cup", "jug", "pot", "glass", "jar", " plastic container"};
	char *cAge[3] = {"young", "old", "aged"};
	
	printf("What is your name?\n");
	scanf("%s", cUserName);
	printf("How old are you?\n");
	scanf("%d",&iAge);
	printf("What is your favorite color?\n");
	scanf("%s", cUserFirstinp);
	printf("What is your favorite sports team?\n");
	scanf("%s", cUserSecondinp);
	printf("What is your favorite shape?\n");
	scanf("%s",cUserThirdinp);
	printf("What is your favorite restaurant?\n");
	scanf("%s",cUserFourthinp);
	printf("What is your favorite drink?\n");
	scanf("%s",cUserFifthinp);

	
	printf("\nGreat! Let the magic happen!\n");
	
	printf("\n%s is %d years %s and is very attatched to their %s %s. \n", cUserName, iAge, cAge[iRandomItem2], cUserFirstinp, cColorItem[iRandomItem1]);
	printf("They also enjoy watching the %s %s. \n", cUserSecondinp, cSportsTeam[iRandomItem1]);
	printf("Who would've thought they enjoy %s shaped %s. \n", cUserThirdinp, cShapeItem[iRandomItem1]);
	printf("Wow, they also can't get enough of %s from %s. \n", cRestaurantFood[iRandomItem1], cUserFourthinp);
	printf("Finally, they really enjoy %s in their favorite %s. \n", cUserFifthinp, cDrink[iRandomItem1]);
	
	
	return 0;
}


