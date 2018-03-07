//
// Created by xintong cheng on 2018-02-27.
//

#ifndef SMALL_WORLD_GAME_H
#define SMALL_WORLD_GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include "Player.h"
#include "Map.h"



class Game {

private:

    vector<Player> Players;
    int round;
    Map map = Map(1);

public:
    Game();
    virtual ~Game();
    void createMap();

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


#endif //SMALL_WORLD_GAME_H
