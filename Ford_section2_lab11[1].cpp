//Lab 10: 3D Tic Tac Toe
//John David Ford
//Hunter Gray
//12 April 2016
//Section 2
 
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

class Block 
{
public:
    Block() : iNum(0) {};                 //Sets iNum to 0
    ~Block() {};                          //Empty
    int iReadNum() const { return iNum; };//Returns iNum
    void setValue(int iNewNum);           //Changes iNum to iNewNum

private:
    int iNum; //iNum can be -1, 0 or 1
};

void Block::setValue(int iNewNum) //Changes iNum
{
    if (iReadNum())
        return;
    else 
        iNum = iNewNum; //iNum takes on iNewNum
    return;
}

class Chunk //represents 3D playing Table
{
public:
    Chunk() {};   //Empty
    ~Chunk() {};  //Empty
    void displayChunk() const; //Displays the chunk in standard output
    int iGameDone() const;     //Returns 0-3 depending on how the game ends
    bool playSpot(int iVal, int iPlayerVal); //attempts to play a spot for the player. True is successful, false if not
    Block Grid[3][3][3]; 

private:     
    bool chunkFilled() const; //returns True is it's all filled up, false if not.
    int iGameWin() const;     //Returns -1, 0 or 1 depending if there is 3 in a row in the playing table
	char cInBlock(int iRow, int iColumn, int iTable) const;	//return X or O depending if spot is open and which player is playing a spot
};

void Chunk::displayChunk() const //prints the 3D table using cInBlock
{
    int a, b;
    
    cout << endl;
    
    for (a = 0; a < 3; a++) 
	{
        for (b = 0; b < 3; b++) 
		{
            cout << "   " << cInBlock(a, b, 0) << "\t";
            
            if (b < 2)
            {
                cout << "|";
            }
        }
			
        if (a < 2) 
		{
            cout << endl;
			cout << "------------------------" << endl;
		}
    }
    
    cout << endl;
    
    for (a = 0; a < 3; a++) 
	{
		cout << "\t\t\t";
		
        for (b = 0; b < 3; b++) 
		{
            cout << "   " << cInBlock(a, b, 1) << "\t";
            
            if (b < 2)
        	{
                cout << "|";
            }
        }	
        
        if (a < 2)
		{
            cout << endl << "\t\t\t";
			cout << "------------------------" << endl;
		}
    }
    
    cout << endl;
    
    for (a = 0; a < 3; a++) 
	{
	    cout << "\t\t\t\t\t\t";
	    
        for (b = 0; b < 3; b++) 
		{
            cout << "   " << cInBlock(a, b, 2) << "\t";
            
            if (b < 2)
            {
                cout << "|";
            }
        }	
        
        if (a < 2)
		 {
            cout << endl << "\t\t\t\t\t\t";
            
			cout <<"------------------------" << endl;
		}
    }
    
    cout << endl << endl; 
}

int Chunk::iGameDone() const //Checks if the game is done
{
    if (iGameWin() == -1)      //returns 1 if player 1 wins
        return 1;
        
    else if (iGameWin() == 1)  //returns 2 if player 2 wins
        return 2;
        
    else if (chunkFilled())    //Returns 3 if draw
        return 3;
        
    else                       //If game isn't dont return 0
        return 0;
}

bool Chunk::playSpot(int iVal, int iPlayerVal) //iVal = spot to be played. iPlayerVal = player playing spot
{
    int iTable = iVal / 9;
    int iRow = (iVal % 9) / 3;
    int iColumn = iVal % 3;
    
    if (Grid[iRow][iColumn][iTable].iReadNum()) //Return true if spot is successfully played
    {
        return false;                           //Return false is spot isn't successfully played
    }
    
    else 
	{
        Grid[iRow][iColumn][iTable].setValue(pow((-1), iPlayerVal)); //setValue(-1) is iPlayerVal = 1
        displayChunk();                                            //serValue(1) is iPlayerVal = 2
        
        return true;
    }
} 

bool Chunk::chunkFilled() const //Checks if the play table is full
{
    int a, b, c, counter = 0; //counter is +1 for every nonzero value in play table

    for (a = 0; a < 3; a++)
    
        for (b = 0; b < 3; b++)
        
            for (c = 0; c < 3; c++)
            
                if (Grid[a][b][c].iReadNum()) 
                     counter++;
    if (counter == 27) //if counter reaches max value of 27 return true otherwise return false
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Chunk::iGameWin() const //Checks for 3 in a row in the play table
{
    int a, b, c, counter;
 
    for (c = 0; c < 3; c++) //Cycling through each playtable; checking c = 0, 1, 2 and so on
	{
       
        for (a = 0; a < 3; a++) // Checking horizontal rows on each play table
		{
            counter = 0;
            
            for (b = 0; b < 3; b++) 
                counter += Grid[a][b][c].iReadNum();
                
            if (abs(counter) == 3)
                return abs(counter) / counter;
        }
      
        for (b = 0; b < 3; b++) // Checking vertical columns on each board.
		{
            counter = 0;
            
            for (a = 0; a < 3; a++)
                counter += Grid[a][b][c].iReadNum();
                
            if (abs(counter) == 3)
                return abs(counter) / counter;
        }
        
        counter = 0;
        
        for (a = 0; a < 3; a++) // Checking the right diagonal on each board.
		{
            b = a;
            
            counter += Grid[a][b][c].iReadNum();
        }
        
        if (abs(counter) == 3)
            return abs(counter) / counter;
            
        
        counter = 0;
        
        for (a = 0; a < 3; a++) // Checking the left diagonal on each board.
		{
            b = 2 - a;
            
            counter += Grid[a][b][c].iReadNum();
        }
        
        if (abs(counter) == 3)
            return abs(counter) / counter;
    }

    for (a = 0; a < 3; a++) //Checking straight up and down on each board & cycling through rows a = 0, 1, 2 and so on
	{
        
        for (b = 0; b < 3; b++) // Cycling through columns b = 0, 1, 2 and so on 
		{
            counter = 0;
            
            for (c = 0; c < 3; c++)
                counter += Grid[a][b][c].iReadNum();
                
            if (abs(counter) == 3)
                return abs(counter) / counter;
        }
        
        counter = 0;
        
        for (b = 0; b < 3; b++) // Checking the right bc diagonal in each row
		{
            c = b;
            
            counter += Grid[a][b][c].iReadNum();
        }
        
        if (abs(counter) == 3)
            return abs(counter) / counter;
       
        counter = 0;
        
        for (b = 0; b < 3; b++)  // Checking the left bc diagonal in each row
		{
            c = 2 - b;
            
            counter += Grid[a][b][c].iReadNum();
        }
        
        if (abs(counter) == 3)
            return abs(counter) / counter;
    }
    // Checking each column-slice : cycling through j = 0, 1, 2
    for (b = 0; b < 3; b++)
	{
       
        counter = 0;
        
        for (a = 0; a < 3; a++) // Checking the right ac diagonal in the column
		{
            c = a;
            
            counter += Grid[a][b][c].iReadNum();
        }
        
        if (abs(counter) == 3)
            return abs(counter) / counter; 
        
        counter = 0;
        
        for (a = 0; a < 3; a++) // Checking the left ac diagonal in the column
		{
            c = 2 - a;
            counter += Grid[a][b][c].iReadNum();
        }
        
        if (abs(counter) == 3)
            return abs(counter) / counter;
    }
    
// Four cross-cube diagonals (none of {i, j, k} constant).

    counter = 0;
    
    for (a = 0; a < 3; a++) //First Diagonal
	{
    	b = a;
        c = a;
        counter += Grid[a][b][c].iReadNum();
    }
    
    if (abs(counter) == 3)
        return abs(counter) / counter;
        
    counter = 0;
    
    for (a = 0; a < 3; a++) //Second Diagonal
	{
        b = 2 - a;
        c = a;
        counter += Grid[a][b][c].iReadNum();
    }
    
    if (abs(counter) == 3)
        return abs(counter) / counter;    
        
    counter = 0;
    
    for (a = 0; a < 3; a++) //Third Diagonal
	{
        b = a;
        c = 2 - a;
        counter += Grid[a][b][c].iReadNum();
    }
    
    if (abs(counter) == 3)
        return abs(counter) / counter;
		    
	counter = 0;
	
    for (a = 0; a < 3; a++) //Fourth Diagonal
	{
        b = 2 - a;
        c = 2 - a;
        counter += Grid[a][b][c].iReadNum();
    }
    
    if (abs(counter) == 3)
        return abs(counter) / counter;

    return 0; //If there wasn't a straight line found in the play table return 0
}

char Chunk::cInBlock(int iRow, int iColumn, int iTable) const //Returns X or O depeding on value of Grid[iRow][iColumn][iTable]
{
    switch (Grid[iRow][iColumn][iTable].iReadNum()) 
	{
        case -1:
            return 'X';
            
        case 1:
            return 'O';
            
        default:
            return ' ';
    }
}

class Player //Represents human player
{
public:
    Player();                     //Sets computer player giving computer a random number
    Player(int iAgainstComputer);
    //Player(int iAgainstComputer); //Sets human player
    ~Player() {};                 //Empty
    int iGetPlayerVal() const { return iPlayerVal; }; //returns iPlayerVal
    int iChooseSpot() const;                          //Gets playes choice of spot to play; computer chooses randomly

private:
    bool ComputerEnemy;
    bool ComputerEnemy2;
    int iPlayerVal;	   //can be 1 or 2
};

Player::Player() //Creates computer 
{
    ComputerEnemy = true;
    
    srand(time(0));
    iPlayerVal = rand() % 2 + 1;
}
Player::Player(int iAgainstComputer)
{
	ComputerEnemy2 = true;	
	srand(time(0));
	iPlayerVal = iAgainstComputer % 2 + 1;
}

//Player::Player(int iAgainstComputer) //Creates opponent against computer
//{
  //  ComputerEnemy = false;
    //iPlayerVal = iAgainstComputer % 2 + 1;
//}

int Player::iChooseSpot() const 
{
    int iBlockVal;
    
    if (ComputerEnemy) 
    {
		iBlockVal = rand() % 27;
	}
	
    if (ComputerEnemy2) 
	{
        int iRow = 0, iColumn = 0, iTable = 0;
        
        cout << "Which spot do you wish to play?" << endl;
        
        while (iTable < 1 || iTable > 3) 
		{
            cout << "Table 1, 2 or 3?";
            iTable = rand() % 27;
        }
        
        while (iRow < 1 || iRow > 3)
		{
            cout << "Row 1, 2 or 3?";
            iRow = rand() % 27;
        }
        
        while (iColumn < 1 || iColumn > 3) 
		{
            cout << "Column 1, 2 or 3?";
            iColumn = rand() % 27;
        }
        
		iBlockVal = (iTable - 1) * 9 + (iRow - 1) * 3 + (iColumn - 1);
    }
    return iBlockVal;
}

bool choiceYup(); //Function protocol

int main()
{
    bool keepPlaying = true;
    
    do 
	{
        Player ComputerisEnemy;                      //Computer player is made
        Player ComputerisEnemy2;
        //Player User(ComputerisEnemy.iGetPlayerVal());//User Player is made

        Chunk GameChunk; //3D playing table is made

        cout << endl << "Time to play some 3D Tic-Tac-Toe dude." << endl;

        if (ComputerisEnemy.iGetPlayerVal() == 1) //If Computer Player is player 1 then the computer will play first
		{
            cout << endl << "Unlucky. I get to play first." << endl;
     
            GameChunk.playSpot(ComputerisEnemy.iChooseSpot(), ComputerisEnemy.iGetPlayerVal()); //Chooses move
            
            cout << "That was my move, goodluck bro." << endl << endl;
        }
        
        else //If Computer Player is player 2 then the user player will play first after the empty play table is displayed
		{
            GameChunk.displayChunk();
            
            cout << "Wow man, you're pretty lucky. You get to go first." << endl << endl;
        }

        do //Repeat loop until end of game by GameChunk.iGameDone() returning nonzero
		{
            while (!GameChunk.playSpot(ComputerisEnemy2.iChooseSpot(), ComputerisEnemy2.iGetPlayerVal())) //User must choose a spot to play
            {
                cout << "Nope, Nope, Nope. Can't play there. That spot has been taken broshake." << endl << endl;
         	}
         	
            if (GameChunk.iGameDone() == 0) //Computer chooses a move if the game hasn't finished
			{
                cout << "I'll play this square:" << endl;
                
                while (!GameChunk.playSpot(ComputerisEnemy.iChooseSpot(), ComputerisEnemy.iGetPlayerVal())) {} //Repeat computer choice until it makes an allowable move
            }
            
        } while (GameChunk.iGameDone() == 0);
    
        int iGameFinal = GameChunk.iGameDone(); //Results are given by this

        if (iGameFinal == 3) //User is told how the game has ended
        {
            cout << "Shame, it's a DRAW. Time to square up and come at me again broheim.";
     	}
     	
        else 
		{
            cout << "Player " << iGameFinal << " WON!" << endl;
            
            if (iGameFinal == ComputerisEnemy.iGetPlayerVal()) 
            {
                cout << "That would be me." << endl << endl << "Better luck beating me next time bro.";
            }
            
            else if (iGameFinal == ComputerisEnemy2.iGetPlayerVal()) 
            {
                cout << "That would be you." << endl << endl << "Wow, you actually beat me. Nice goin dude.";
            }
            
        }
        
        cout << endl << endl;

        cout << "Wanna come at me crazy again? (Y/N) ";
        keepPlaying = choiceYup();
        
    } while (keepPlaying);
    
	cout << "Cya Later Dude" << endl << endl;
    return 0;
}

bool choiceYup() 
{
    char cUserInput[15] = {'\0'};
    
    while (*cUserInput != 'y' && *cUserInput != 'Y' && *cUserInput != 'n' && *cUserInput != 'N')
        cin >> cUserInput;
        
    if (*cUserInput == 'y' || *cUserInput == 'Y')
    {
        return true;
    }
    
    else
    {
        return false;
    }
}
