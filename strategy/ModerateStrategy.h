//
// Created by xintong cheng on 2018-03-29.
//

#ifndef SMALL_WORLD_MODERATESTRATEGY_H
#define SMALL_WORLD_MODERATESTRATEGY_H

#include "../Player.h"
#include "PlayerStrategy.h"
#include "../Game.h"

class ModerateStrategy : public PlayerStrategy {
public:
    ModerateStrategy();

    virtual ~ModerateStrategy();

    void play() override;

    void firstConquestByStrategy(Player*, int i) override;
    void picks_raceByStrategy(Player*, ComboList &combo) override;
    void conquersByStrategy(Player*, int playerNum) override;
    void declineComboByStrategy(Player*, ComboList &combo) override;
    void redeployTokensByStrategy(Player*) override ;
};


#endif //SMALL_WORLD_MODERATESTRATEGY_H
