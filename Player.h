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

    vector<Region> occupiedRegions;

    void picks_race();
    void conquers();
    void scores();
    int reinforcementDie();


    int getVictoryCoins() const;
    int getTotalTokens() const;
    void setVictoryCoins(int victoryCoins);
    void setTotalTokens(int totalTokens);

    const Race &getActiveRace() const;
    const Race &getDeclineRace() const;
    const Power &getActivePower() const;
    const Power &getDeclinePower() const;
    void setActiveRace(const Race &activeRace);
    void setDeclineRace(const Race &declineRace);
    void setActivePower(const Power &activePower);
    void setDeclinePower(const Power &declinePower);


private:
    int victoryCoins;
    int totalTokens;
    Race activeRace;
    Race declineRace;
    Power activePower;
    Power declinePower;
};


#endif //SMALL_WORLD_PLAYER_H
