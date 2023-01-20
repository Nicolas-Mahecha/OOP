#include "Dice.h"
#include <stdlib.h>
#include <ctime>
Dice::Dice(){

}
int Dice::rollDice(){
    value = rand() % 6 + 1;
}

