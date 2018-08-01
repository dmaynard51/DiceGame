

#include <iostream>
#include "Die.hpp"
#include "LoadedDie.hpp"

class Game
{
private:
int dice1Score;
int dice2Score;
    
    int player1;
    int player2;
    
    int dice1CurrentRoundScore;
    int dice2CurrentRoundScore;
    
    int currentRollDice1;
    int currentRollDice2;
    
    Die player1Die; // regular dice picked
    Die player2Die; // regular dice picked
    LoadedDie player1LoadedDie; //loaded dice picked
    LoadedDie player2LoadedDie; //loaded dice picked

    
int rounds;
    int player1dieChoice;
int player2dieChoice;

public:
Game(); //need to add die and loadDie to this class
void menu();
void playGame();
void setRounds();
void setDice();
void decreaseRounds();
void winCheck();
    void setSides(int player1, int player2);
    
    void currentRoundWin(int dice1roll, int dice2roll);

    char ch; //used to press enter for the next move.

void inputValidationYN();
    int inputValidation12();
    
    


};
