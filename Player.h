//
// Created by xintong cheng on 2018-02-12.
//

#ifndef SMALL_WORLD_PLAYER_H
#define SMALL_WORLD_PLAYER_H


#include "Power/Power.h"
#include "Region.h"
#include "Race/Race.h"
#include "dice.h"
#include <vector>

class Player {

public:
    Player();
    ~Player();

    int reinforcementDie();
    int getCoins();
    void conquers();
private:
    Race activeRace;

    Race lostTribe;
    Power power;
    Dice dice;
    vector<Region> occupiedRegions;
    void picks_race();
    void scores();
    int getTokens();

    int victoryCoins;
    int totalTokens;
};


#endif //SMALL_WORLD_PLAYER_H
