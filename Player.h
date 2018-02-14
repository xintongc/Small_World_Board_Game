//
// Created by xintong cheng on 2018-02-12.
//

#ifndef SMALL_WORLD_PLAYER_H
#define SMALL_WORLD_PLAYER_H


#include "Power/Power.h"
#include "Region.h"
#include "Race/Race.h"
#include <vector>

class Player {

public:
    Player();
    ~Player();

private:
    Race activeRace;
    Race lostTribe;
    Power power;
    int victoryCoin;
    vector<Region> occupiedRegions;


};


#endif //SMALL_WORLD_PLAYER_H
