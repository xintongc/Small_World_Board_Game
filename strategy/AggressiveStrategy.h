//
// Created by xintong cheng on 2018-03-29.
//

#ifndef SMALL_WORLD_AGGRESSIVESTRATEGY_H

#define SMALL_WORLD_AGGRESSIVESTRATEGY_H
#include "PlayerStrategy.h"
#include "../Player.h"
#include "../Game.h"
#include "../regions/MapRegions.h"

//A concrete Strategy that implements an aggressive operation
class AggressiveStrategy : public PlayerStrategy{
public:
    AggressiveStrategy();
    virtual ~AggressiveStrategy();

    void play();
//    void pickRace(ComboList& combo);
    void followingConquest(Player*);
    void firstConquestByStrategy(Player*, int i) override;
    void picks_raceByStrategy(Player*, ComboList &combo) override;
    void conquersByStrategy(Player*, int playerNum) override;
    void declineComboByStrategy(Player*, ComboList &combo) override;
    void conqueredRegion(Player* player, int regionID);
    void enemyLossesWithdrawals(Player* player, int regionID, int requiredTokens);
    void finalConquestAttempt(Player* player, int regionID);

    void redeployTokensByStrategy(Player *player) override;
};


#endif //SMALL_WORLD_AGGRESSIVESTRATEGY_H
