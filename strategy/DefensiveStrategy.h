//
// Created by xintong cheng on 2018-03-29.
//

#ifndef SMALL_WORLD_DEFENSIVESTRATEGY_H
#define SMALL_WORLD_DEFENSIVESTRATEGY_H

#include "../Player.h"
#include "PlayerStrategy.h"

class DefensiveStrategy : public PlayerStrategy, Player{
public:
//    DefensiveStrategy();
//
//    virtual ~DefensiveStrategy();

    void play() override;

    void firstConquestByStrategy(int i) override;

};


#endif //SMALL_WORLD_DEFENSIVESTRATEGY_H
