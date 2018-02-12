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
    diceNum=std::rand() % 4;     //no value outside of the 0-3 range is ever returned
}

int Dice::getDiceNum() {
    return diceNum;
}

int main() {
    Dice dice;
    dice.rollingDice();     //one can request a dice being rolled
    cout<<"The dice is being rolled. The number is: "<<dice.getDiceNum()<<endl;   // the container returns the right number of values


    return 0;
}