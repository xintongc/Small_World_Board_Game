//
// Created by xintong cheng on 2018-02-12.
//

#ifndef SMALL_WORLD_PLAYER_H
#define SMALL_WORLD_PLAYER_H


#include "Power/Power.h"
#include "Region.h"
#include "Race/Race.h"
#include "Dice.h"
#include <vector>

class Player {

public:
    Player();
    ~Player();

    Race race[11];
    Race lostTribe;
    Power power[11];
    Dice dice;
    bool turn[10];

    vector<Region> occupiedRegions;

    void picks_race();
    void conquers();
    void scores();
    int reinforcementDie();


    int getVictoryCoins() const;
    int getTotalTokens() const;
    void setVictoryCoins(int victoryCoins);
    void setTotalTokens(int totalTokens);

private:
    int victoryCoins;
    int totalTokens;

};


#endif //SMALL_WORLD_PLAYER_H
