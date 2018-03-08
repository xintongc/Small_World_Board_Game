//
// Created by yanra on 2018-02-16.
//

#ifndef SMALL_WORLD_COMBO_H
#define SMALL_WORLD_COMBO_H


#include "Race/Race.h"
#include "Power/Power.h"
#include <stack>
#include <vector>
using namespace std;


class Combo {

public:
    Combo();
    ~Combo();

    bool raceUsed[15];
    bool powerUsed[21];
    
    stack <int> raceStack;
    stack <int> powerStack;
    vector <Race> raceVector;
    vector <Power> powerVector;
    vector <int> coinsVector;

    void initial();
    void listAllPairs();
    void showStackTop();
    void printStacks();
    vector <Race> initialRaceVector();
    vector <Power> initialPowerVector();
    vector <int> initialCoinsVector();
    void printCurrentVectors();
    void replenishCombo();

    Race switchRace(int);
    Power switchPower(int);


};


#endif //SMALL_WORLD_COMBO_H
