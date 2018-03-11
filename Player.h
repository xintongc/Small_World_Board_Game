//
// Created by xintong cheng on 2018-02-12.
//

#ifndef SMALL_WORLD_PLAYER_H
#define SMALL_WORLD_PLAYER_H


#include "Power/Power.h"
#include "regions/Region.h"
#include "Race/Race.h"
#include "ComboList.h"
#include <vector>

class Player {

public:
    Player();
    ~Player();

    vector<Region> occupiedRegions;

    void pickRace(ComboList&);
    void picks_race(ComboList&, int);
    void conquers();

    void firstConquest();

    void scores();
    int reinforcementDie();
    void currentStates();

    int getVictoryCoins() const;
    int getTotalTokens() const;
    void setVictoryCoins(int victoryCoins);
    void setTotalTokens(int totalTokens);

    const Race &getActiveRace() const;
    const Race &getDeclineRace() const;
    const Power &getActivePower() const;
    const Power &getDeclinePower() const;
    bool isPlayed() const;
    void setActiveRace(const Race &activeRace);
    void setDeclineRace(const Race &declineRace);
    void setActivePower(const Power &activePower);
    void setDeclinePower(const Power &declinePower);
    void setPlayed(bool played);


private:
    int victoryCoins;
    int totalTokens;
    Race activeRace;
    Race declineRace;
    Power activePower;
    Power declinePower;
    bool played;
};


#endif //SMALL_WORLD_PLAYER_H
