//
// Created by xintong cheng on 2018-03-29.
//

#ifndef SMALL_WORLD_MODERATESTRATEGY_H
#define SMALL_WORLD_MODERATESTRATEGY_H

#include "../Player.h"
#include "PlayerStrategy.h"

class ModerateStrategy : public PlayerStrategy, Player {
public:
    ModerateStrategy();

    virtual ~ModerateStrategy();

    void play() override;
};


#endif //SMALL_WORLD_MODERATESTRATEGY_H
