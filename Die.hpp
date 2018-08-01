#ifndef DIE
#define DIE

class Die
{
friend class Game;
private:

int rollDice(int sides);


public:
Die(); 
int sides;
int currentDieRoll;
void setDice();
int getSides();
    int sideInputValidation();
    
    
friend void game(Die &game);

};
#endif
