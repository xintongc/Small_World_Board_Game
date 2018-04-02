//
// Created by xintong cheng on 2018-03-29.
//

#ifndef SMALL_WORLD_DEFENSIVESTRATEGY_H
#define SMALL_WORLD_DEFENSIVESTRATEGY_H

#include "../Player.h"
#include "PlayerStrategy.h"

class DefensiveStrategy : public PlayerStrategy{
public:
    DefensiveStrategy();

    virtual ~DefensiveStrategy();

    void play() override;

    void firstConquestByStrategy(Player*, int i) override;
    void picks_raceByStrategy(Player*, ComboList &combo) override;
    void conquersByStrategy(Player*, int playerNum) override;
    void declineComboByStrategy(Player*, ComboList &combo) override;

    void redeployTokensByStrategy(Player *player) override;
    void conqueredRegion(Player* player, int regionID);
    void followingConquest(Player* player);
    void enemyLossesWithdrawals(Player* player, int regionID, int requiredTokens);
    void finalConquestAttempt(Player* player, int regionID);
};


#endif //SMALL_WORLD_DEFENSIVESTRATEGY_H
