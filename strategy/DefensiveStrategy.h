//
// Created by xintong cheng on 2018-03-29.
//

#ifndef SMALL_WORLD_DEFENSIVESTRATEGY_H
#define SMALL_WORLD_DEFENSIVESTRATEGY_H


#include "PlayerStrategy.h"

class DefensiveStrategy : public PlayerStrategy {
public:
    DefensiveStrategy();

    virtual ~DefensiveStrategy();

    void play() override;
};


#endif //SMALL_WORLD_DEFENSIVESTRATEGY_H
