#include <iostream>
#include "game.hpp"
#include <limits>
using std::cin;
using std::cout;
using std::endl;
using std::max;

/***********************************************
Description: Constructor of the game, sets scores, rounds to 0.
***********************************************/

Game::Game()
{
dice1Score = 0;
dice2Score = 0;
rounds = 0;

    player1 = 0; //this will determine if the user will be using a loaded die or regular for player1
    player2 = 0; //this will determine if the user will be using a loaded die or regular for player2
    dice1CurrentRoundScore = 0;
    dice1CurrentRoundScore = 0;
    
    
    
}

/***********************************************
Description: Menu function used to ask the user first which type of die they want to use.
Then how many sides, and then how many rounds. For each input, there is an input verification.
***********************************************/

void Game::menu()
{

    cout << "Will player 1 be using:" << endl;
    cout << "1. Regular die" << endl;
    cout << "2. Loaded die" << endl;
    player1 = inputValidation12();
    
    
    
    cout << "Will player 2 be using:" << endl;
    cout << "1. Regular die" << endl;
    cout << "2. Loaded die" << endl;
    player2 = inputValidation12(); //needs input validation
    
    cout << "Enter how many sides each user will be using? Please enter a number tween 4-100: " << endl;
    setSides(player1, player2);
    
    setRounds();
    
}


/************
 Description: This is where we decide what kind of die will be used and will then be created. 
 For this input validation I used the following link: https://stackoverflow.com/questions/20446373/cin-ignorenumeric-limitsstreamsizemax-n-max-not-recognize-it
 *************/

void Game::setRounds()
{
    cout << "Enter the number of rounds you want to play. Please enter a number between [1-100]: " << endl;

    int num; //variable to store the number entered by the user.
    
    //Prompt the user to enter an integer.
    



    //Prompt the user to enter an integer.
	cin >> num;

    //While the input entered is not an integer, prompt the user to enter an integer.
    while((!cin) || (num <= 0) || (num >= 100))
    {

        cout << "Error invalid input please try again " << endl;
        cout << "Please enter [1 - 100]: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> num;

    }
    
    rounds = num;
}


/***********************************************
Description: Function used to ask how many sides will be used.
***********************************************/
void Game::setDice()
{
    cout << "Will player 1 use a regular die or loaded die?" << endl;
    cin >> player1dieChoice; //needs input validation
    if (player1dieChoice == 1)
    {
        player1 = 1;
        
    }
    if (player1dieChoice == 2)
    {
        player1 = 2;
        
    }
    
    cout << "Will player 2 use a regular die or loaded die?" << endl;
    cin >> player2dieChoice; // needs input validation
    
    if (player2dieChoice == 1)
    {
        player1 = 1;
    }
    if (player2dieChoice == 2)
    {
        player1 = 2;
    }
    
    
    
}


/***********************************************
Description: used to decrease the rounds per game.
***********************************************/

void Game::decreaseRounds()
{
    rounds = rounds - 1;
}

void Game::winCheck()
{
    if (dice1Score > dice2Score)
    {
        cout << "Player 1 wins!" << endl;
    }
    if (dice2Score > dice1Score)
	{
        cout << "Player 2 wins!" << endl;
	}
    if (dice2Score == dice1Score)
	{
            cout << "Tie!" << endl;
	}
    
    
}
/***********************************
 Description: User decides how many sided die they want
***********************************/

void Game::setSides(int player1,int player2)
{
    if (player1 == 1)
    {
        
        cout << "How many sides would player1 like?\n";
        player1Die.setDice();
    }
    if (player1 == 2)
    {
        cout << "How many sides would player1 like?\n";
        player1LoadedDie.setDice();
    }
    if (player2 == 1)
    {
        cout << "How many sides would player2 like?\n";
        player2Die.setDice();
    }
    
    if (player2 == 2)
    {
        cout << "How many sides would player2 like?\n";
        player2LoadedDie.setDice();

    }
}
/***********************************
 Description: Checks who won the current round
***********************************/

void Game::currentRoundWin(int dice1roll, int dice2roll)
{
    if (currentRollDice1 > currentRollDice2)
    {
        dice1Score++;
		cout << "Player #1 Score: " << dice1Score << " Player #2 Score: " << dice2Score;
    }
    
    if (currentRollDice2 > currentRollDice1)
    {
        dice2Score++;
		cout << "Player #1 Score: " << dice1Score << " Player #2 Score: " << dice2Score;
    }
    
    if (currentRollDice1 == currentRollDice2)
    {
        dice1Score++;
        dice2Score++;
		cout << "Player #1 Score: " << dice1Score << " Player #2 Score: " << dice2Score;
    }



}



/***********************************
 Description: This will be called at the end of the playGame function to ask if they want to play again
 Input validation included in case the user enters anything by Y or N. I used the following link to help with this input validation: http://www.cplusplus.com/forum/general/160996/
***********************************/

void Game::inputValidationYN()
{
    cout << "Please enter [Y/N]: " << endl;
    char ch;
    cin >> ch;
    
    ch = toupper(ch);
    
    while (ch != 'Y' && ch != 'N')
    {
        cout << "Error invalid input please try again " << endl;
        cout << "Please enter [Y/N]: ";
        cin >> ch;
        ch = toupper(ch);
    }
    
    
    cout << "You entered " << ch << endl;
    if (ch == 'Y')
    {
        playGame();
    }
    
    if (ch == 'N')
    {
        exit(0);
    }

}

/***********************************
 Description: This input validation is used for the menu, in case the user enters anything but 1 or 2. 
 For this input validation I used: https://stackoverflow.com/questions/20446373/cin-ignorenumeric-limitsstreamsizemax-n-max-not-recognize-it this link.
***********************************/

int Game::inputValidation12()
{
    
    int num; //variable to store the number entered by the user.

    //Prompt the user to enter an integer.
	cin >> num;

    //While the input entered is not an integer, prompt the user to enter an integer.
    while((!cin) || (num >= 3) || (num <= 0))
    {

        cout << "Error invalid input please try again " << endl;
        cout << "Please enter [1 or 2]: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> num;

    }

    return num;
}

/***********************************************
Description: This function will call the menu function, and then while the rounds are > 0 it will roll a die for
each player.

For each roll it will keep score of the players rounds, and once the rounds are over it will compare
the scores during the rounds and declare the winner. Finally it will ask the user if they would like to
play again.
***********************************************/

void Game::playGame()
{
    menu();
/*******************************************
Resets the score before the start of the next set of rounds.
********************************************/
    dice1Score = 0;
    dice2Score = 0;
    dice1CurrentRoundScore = 0;
    dice2CurrentRoundScore = 0;
    
    while (rounds > 0)
    {
        if ((player1 == 1) && (player2 == 1)) //player 1 and 2 are using regular die
        {
            currentRollDice1 = player1Die.rollDice(player1Die.getSides());
            cout << "Player1 rolled with regular die: " << currentRollDice1;
            cout << endl;
            currentRollDice2 = player2Die.rollDice(player2Die.getSides());
            cout << "Player2 rolled with regular die: " << currentRollDice2 << endl;
            cout << endl;
            cin.get();
            decreaseRounds();
			cout << endl;
            currentRoundWin(currentRollDice1, currentRollDice2);
			cout << endl;
			cin.get();
        }

		        if ((player1 == 1) && (player2 == 2)) //player 1 is regular die, player2 is loadedDie
        {
            currentRollDice1 = player1Die.rollDice(player1Die.getSides());
            cout << "Player1 rolled with regular die: " << currentRollDice1;
            cout << endl;
            currentRollDice2 = player2LoadedDie.rollDice(player2LoadedDie.getSides());
            cout << "Player2 rolled with loaded die: " << currentRollDice2 << endl;
            cout << endl;
            cin.get();
            decreaseRounds();
            currentRoundWin(currentRollDice1, currentRollDice2);
			cout << endl;
			cin.get();
        }
        
        		        if ((player1 == 2) && (player2 == 2)) //both have loaded die
        {
            currentRollDice1 = player1LoadedDie.rollDice(player1LoadedDie.getSides());
            cout << "Player1 rolled with loaded die: " << currentRollDice1;
            cout << endl;
            currentRollDice2 = player2LoadedDie.rollDice(player2LoadedDie.getSides());
            cout << "Player2 rolled with loaded die: " << currentRollDice2 << endl;
            cout << endl;
            cin.get();
            decreaseRounds();
            currentRoundWin(currentRollDice1, currentRollDice2);
			cout << endl;
			cin.get();
        }

        		        if ((player1 == 2) && (player2 == 1)) //player 1 has loaded die, player 2 has regular die
        {
            currentRollDice1 = player1LoadedDie.rollDice(player1LoadedDie.getSides());
            cout << "Player1 rolled with loaded die: " << currentRollDice1;
            cout << endl;
            currentRollDice2 = player2Die.rollDice(player2Die.getSides());
            cout << "Player2 rolled regular die: " << currentRollDice2 << endl;
            cout << endl;
            cin.get();
            decreaseRounds();
            currentRoundWin(currentRollDice1, currentRollDice2);
			cout << endl;
			cin.get();
        }
        
    }
    winCheck(); //compares the scores of all of the rounds to see who won
	inputValidationYN(); //asks the user if they would like to play again.

}

