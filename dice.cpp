#include <iostream>
#include "Dice.h"
#include <ctime>

using namespace std;

Dice::Dice(){
    //cout << "Dice is created" <<endl;
}

Dice::~Dice()
{
    //cout << "Dice is being deleted" << endl;
}

//rolling dice with 0,0,0,1,2,3
void Dice::rollingDice(){
    std::srand(time(0));
    int x=(rand() % 6)+1;
    if (x==1||x==2||x==3)
        diceNum=x;
    else
        diceNum=0;
}

int Dice::getDiceNum() {
    return diceNum;
}

