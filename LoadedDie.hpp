#include <iostream>
#include "Die.hpp"

class LoadedDie: public Die 
{
friend class Game; //since this class inherits the public functions of Die (ie sides, getSides, setDice)
private:
int rollDice(int sides);

void game(LoadedDie &game); 

};
