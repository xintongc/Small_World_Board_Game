#include <iostream>
#include "dice.h"
#include <ctime>

using namespace std;

Dice::Dice(){
    cout << "Dice is created" <<endl;
}

Dice::~Dice()
{
    cout << "Dice is being deleted" << endl;
}

void Dice::rollingDice(){
    std::srand(time(0));
    int x=(rand() % 6)+1;     //no value outside of the 0-3 range is ever returned
    if (x==1||x==2||x==3)
        diceNum=x;
    else
        diceNum=0;
}

int Dice::getDiceNum() {
    return diceNum;
}

