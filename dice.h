//
// Created by yanra on 2018-02-10.
//

#ifndef CLION_WORKSPACE_DICE_H
#define CLION_WORKSPACE_DICE_H
class Dice{
public:
    Dice();
    ~Dice();
    void rollingDice();
    int getDiceNum();
private:
    int diceNum;
};

#endif //CLION_WORKSPACE_DICE_H
