/***********************************
 Name: Daniel Maynard
 Date: 7/13/17
 Program: This will first create a game class, which will contain class objects for die and loadedDie's. 
 Depending if the user wants to use a regular die or Loaded Die, it will then use them accordingly.

 The "loaded die" class is using the parent class of "die" for the sides object, set side function and get side function.

 "Loaded Die" will have it's own private role function because it will be different from "Die's" role function.

 The playGame function is called lastly, will roll the die, depending on if it's using a loaded or regular die, 
 until the rounds are over, and then present who won; and will ask the user if they want to play again.
 
 Press enter to go to the next roll/score.
***********************************/

#include <iostream>
#include "game.hpp"
using std::cout;
using std::cin;
using std::endl;


int main ()
{
    Game game;
    
    game.playGame();

return 0;
}



/**********

Original game design:

 Create classes:
 Class dice - parent class
 Public:
 Public: Int sides
 public: currentDieRoll
 setDice function
 Ask user how many sides it will have
 Private: void RollDice function
 Will randomly roll dice from 1-N
 Public
 Class loadedDice - child class
 Private: int RollDice function
 
 
 
 
 Class game (dice1, dice2) - friend to dice and loadedDice
 Private: dice1
 Private: dice2
 Private: rounds
 Private: dice1score
 Private: dice2score
 Void Public: Menu function
 
 How many rounds to play
    Each player Pick dice
 
 Play Game
 Quit
 
 Public Void playGame
 Public void setRounds
 Public void setDice
 Public decreaseRounds
 
 roundWinCheck
 gameWinCheck
 Public playGame
    Reset scores

 While (rounds > 0)
    Rolldice dice1
    Roledice dice2
    decreaseRounds
 
 If roleDice1 > roleDice2
 Dice1score++
 
 If roleDice2 > roleDice1
 Dice2score++
 
 If roleDice2 ==roleDice1
    Dice2score++
    Dice1score++
 
 VoidgameWinCheck
    If Dice1score > Dice2score
        Cout player1 wins
    If dice2score  > dice1score
        Cout player2 wins
 
 If Dice2score == Dice1score
    Cout tie

 Do you want to play again?
    Input validation yes or no
        If yes-> play game
**********/
