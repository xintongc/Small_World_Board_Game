//
// Created by xintong cheng on 2018-03-29.
//

#ifndef SMALL_WORLD_AGGRESSIVESTRATEGY_H
#define SMALL_WORLD_AGGRESSIVESTRATEGY_H


#include "PlayerStrategy.h"

class AggressiveStrategy : public PlayerStrategy{
public:
    AggressiveStrategy();

    virtual ~AggressiveStrategy();
    void play();
};


#endif //SMALL_WORLD_AGGRESSIVESTRATEGY_H
