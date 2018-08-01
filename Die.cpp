#include "Die.hpp"
#include <iostream>
#include <cmath>
#include <limits>
using std::cin;
using std::cout;
using std::endl;
using std::max;


/***********************************************
Description: This constructor will create a die with starting sides of 0.
***********************************************/

Die::Die()
{
sides = 0;

}


/***********************************************
Description: This function will set the sides of the dice.
***********************************************/
void Die::setDice()
{
    
        
    int num; //variable to store the number entered by the user.

    //Prompt the user to enter an integer.
	cin >> num;

    //While the input entered is not an integer, prompt the user to enter an integer.
    while((!cin) || (num <= 3) || (num >= 101))
    {

        cout << "Error invalid input please try again " << endl;
        cout << "Please enter [4-100]: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> num;

    }
    
    sides = num;
    
}


/***********************************************
Description: This function will take roll the dice of a normal die
***********************************************/

int Die::rollDice(int sides)
{

return (rand() % sides + 1);
}


/***********************************************
Description: This function will return the sides of the die
***********************************************/

int Die::getSides()
{
    return sides;
}


