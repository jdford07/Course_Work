//Lab 9: Tic Tac Toe
//John David Ford
//21 March 2016
//Section 2

 
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;


class Square //sets private iNum to 0
{            //Represents a square on the playing board
    int iNum;

public:          //Returns private iNum
    int iNumRead() const { return iNum; };
    void setValue(int iNewValue);

    Square() : iNum(0) {};
};

void Square::setValue(int iNewNum) //Checks if iNum value is nonzero
{                                        //If iNum is nonzero it will assign value of iNewNum
    if (iNumRead())
        return;
    else 
        iNum = iNewNum;
    return;
}

class Table //Represents a Tic Tac Toe board with private 3x3 array
{
    Square Grid[3][3];
    bool tableFull() const;
    int iGameChamp() const;
    char cSquareSpot(int iRow, int iColumn) const;	
	
public:
    void dispTable() const;
    int iGameDone() const;
    bool playSpot(int iVal, int iPlayerVal);
};

bool Table::tableFull() const //looking to see if board is filled or not
{
    int a, b, counter = 0;

    for (a = 0; a < 3; a++) //Each nonzero board square increments counter by 1
        for (b = 0; b < 3; b++)
            if (Grid[a][b].iNumRead()) 
                counter++;

    if (counter == 9)
        return true;
    else
        return false;
}

int Table::iGameChamp() const
{
    int a, b, counter;

    for (a = 0; a < 3; a++) //Checking rows
	{
        counter = 0;
        for (b = 0; b < 3; b++) 
        {
            counter += Grid[a][b].iNumRead();
    	}
        if (abs(counter) == 3)
        {
            return abs(counter) / counter;
        }
    }

    for (b = 0; b < 3; b++) //Checking columns
	{
        counter = 0;
        for (a = 0; a < 3; a++)
        {
            counter += Grid[a][b].iNumRead();
        }
        if (abs(counter) == 3)
        {
            return abs(counter) / counter;
        }
    }

    counter = 0; //checking diagonal
    for (a = 0; a < 3; a++)
    {
        counter += Grid[a][a].iNumRead();
    }
    if (abs(counter) == 3)
    {
        return abs(counter) / counter;
    }

    counter = 0; //checking diagonal
    for (a = 0; a < 3; a++)
    {
        counter += Grid[a][2 - a].iNumRead();
	}
    if (abs(counter) == 3)
    {
        return abs(counter) / counter;
	}
    return 0; //return 0 if no straight was found
}


char Table::cSquareSpot(int iRow, int iColumn) const //Decides which character to put in spot on Board
{
    int iLocal = Grid[iRow][iColumn].iNumRead();
    if (iLocal) 
	{
        if (iLocal == -1) 
            return 'X';   
        else if (iLocal == 1)
            return 'O';
    }
    else
        return ' ';
}

void Table::dispTable() const //Prints board layout
{
    int a, b;
    cout << endl;
    for (a = 0; a < 3; a++) 
	{
        for (b = 0; b < 3; b++) 
		{
            cout << "   " << cSquareSpot(a, b) << "\t";
            if (b < 2)
            {
                cout << "|";
            }
        }	
        if (a < 2)
        {
            cout << endl << "------------------------" << endl;
        }
    }
    cout << endl << endl; 
}


int Table::iGameDone() const //Checks to see if game has finished
{
    if (iGameChamp() == -1) 
        return 1;
        
    else if (iGameChamp() == 1)
        return 2;
        
    else if (tableFull())
        return 3;
        
    else
        return 0;
}

bool Table::playSpot(int iVal, int iPlayerVal) //iVal represents square to be played & iPlayerVal represents who has claimed spot
{
    int iRow = iVal / 3;
    int iColumn = iVal % 3;
    if (Grid[iRow][iColumn].iNumRead())
        return false; //If a square has already been played
    else 
	{
        Grid[iRow][iColumn].setValue(pow((-1), iPlayerVal));
        dispTable();
        return true;
    }
} 

class Player 
{
    bool ComputerPlayer; //indiciated whether player is/isnt computer
	
public:
    int iPlayerVal;
    int iSquareChoice() const;

    Player();
    Player(int iComputerEnemy);
};

int Player::iSquareChoice() const //Determines which spot is chosen
{
    int iSquareSpot;
    if (ComputerPlayer) //Random spot is chosen
	{
        iSquareSpot = rand() % 9;
    }
    
    else 
	{
        int iRow = 0, iColumn = 0;
        cout << "Please pick the square you wish to play." << endl;
        
        while (iRow < 1 || iRow > 3) 
		{
            cout << "Row (1-3): ";
            cin >> iRow;
        }
        
        while (iColumn < 1 || iColumn > 3) 
		{
            cout << "Column (1-3): ";
            cin >> iColumn;
        }
        
        iSquareSpot = (iRow - 1) * 3 + (iColumn - 1);
    }
    
    return iSquareSpot;
}

Player::Player() //Creates computer player
{
    ComputerPlayer = true;
    srand(time(0));
    iPlayerVal = rand() % 2 + 1;
}

Player::Player(int iComputerEnemy) //Creates opponent
{
    ComputerPlayer = false;
    iPlayerVal = iComputerEnemy % 2 + 1;
}


int main()
{
    Player Computer; //Computer player is made
    Player User(Computer.iPlayerVal); //User is made

    Table Board;

    cout << "It's time to play some Tic Tac Toe." << endl;

    if (Computer.iPlayerVal == 1)  //Computer plays first
	{
        cout << endl << "Computer goes first." << endl;

        while (!Board.playSpot(Computer.iSquareChoice(), Computer.iPlayerVal)) {}
        cout << "I've made my move." << endl << endl;
    }
    
    else
	{
        Board.dispTable();
        cout << "You get to go first." << endl << endl;
    }

    do 
	{
        while (!Board.playSpot(User.iSquareChoice(), User.iPlayerVal))
        {
            cout << "That spot is already taken." << endl << endl;
        }
            
        if (Board.iGameDone() == 0) 
		{
            cout << "I'll play this spot:" << endl;
            while (!Board.playSpot(Computer.iSquareChoice(), Computer.iPlayerVal)) {}
        }
    } while (Board.iGameDone() == 0);
    
    int iFinalGame = Board.iGameDone();

    if (iFinalGame == 3) 
    {
        cout << "It's a Draw.";
    }
    else 
	{
        cout << "Player " << iFinalGame << " won!" << endl;
        
        if (iFinalGame == Computer.iPlayerVal) 
		{
           cout << "That's me." << endl << endl << "Better luck next time.";
       	}
        else if (iFinalGame == User.iPlayerVal)
		{
            cout << "That's you." << endl << endl << "Good game.";
        }
    }
    cout << endl << endl;

    return 0;
}
