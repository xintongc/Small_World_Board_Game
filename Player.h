//
// Created by xintong cheng on 2018-02-12.
//

#ifndef SMALL_WORLD_PLAYER_H
#define SMALL_WORLD_PLAYER_H


#include "Power/Power.h"
#include "regions/Region.h"
#include "Race/Race.h"
#include "ComboList.h"
#include "Map.h"
#include "regions/MapRegions.h"
#include <vector>

class Player {

public:
    Player();
    Player(int id);
    ~Player();

    vector<Region> occupiedRegions;

    void pickRace(ComboList&);
    void picks_race(ComboList&, int);
    void conquers();




//    bool isBorder(MapRegions* regions,int regionID); //need improve later
    void conqueredRegion(int regionID);
    void firstConquest(int playerNum);
    Map* chooseMap(int playerNum); //return map according to player number
    void enemyLossesWithdrawals(int regionID, int requiredTokens);
    void redeployTokens(int n);
    void followingConquest();
    bool connectedToConquestRegion(int regionID);
    int basicRequiredTokens(int regionID);
    int requiredTokensToConquer(int regionID);
    bool enoughTokensToConquer(int regionID);
    void finalConquestAttempt();
    bool ownedRegion(int regionID);
    bool emptyRegion(int regionID);



    void scores();
    int reinforcementDie();
    void currentStates();
    void declineCombo(ComboList&, int);

    void iterateMapRegions(int, Landform);
    void iterateMapRegions(int, LandMark);
    void iterateMapRegions(int);


    int getVictoryCoins() const;
    int getTotalTokens() const;
    void setVictoryCoins(int victoryCoins);
    void setTotalTokens(int totalTokens);

    const Race &getActiveRace() const;
    const Race &getDeclineRace() const;
    const Power &getActivePower() const;
    const Power &getDeclinePower() const;
    bool isPlayed() const;
    bool isHaveDeclineCombo() const;
    bool isHaveActiveCombo() const;

    void setActiveRace(const Race &activeRace);
    void setDeclineRace(const Race &declineRace);
    void setActivePower(const Power &activePower);
    void setDeclinePower(const Power &declinePower);
    void setPlayed(bool played);
    void setHaveDeclineCombo(bool haveDeclineCombo);
    void setHaveActiveCombo(bool haveActiveCombo);

    int getId() const;
    void setId(int id);

private:
    int id;
    int victoryCoins;
    int totalTokens;
    Race activeRace;
    Race declineRace;
    Power activePower;
    Power declinePower;
    bool played;
    bool haveDeclineCombo;
    bool haveActiveCombo;
};


#endif //SMALL_WORLD_PLAYER_H
