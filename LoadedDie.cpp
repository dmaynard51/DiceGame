#include <iostream>
#include "LoadedDie.hpp"




int LoadedDie::rollDice(int sides)
{
int tempRoll;
tempRoll = ((rand() % sides + 1) * 1.5);

if (tempRoll >= sides)
{
	return sides;
}

if (tempRoll < sides)
{
	return tempRoll;
}
    return 0;
}
