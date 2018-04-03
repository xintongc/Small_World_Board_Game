//
// Created by xintong cheng on 2018-02-12.
//

#ifndef SMALL_WORLD_PLAYER_H
#define SMALL_WORLD_PLAYER_H


#include <vector>
#include "Power/Power.h"
#include "Race/Race.h"
#include "ComboList.h"
#include "Map.h"
#include "DesignPattern/Subject.h"
#include "strategy/PlayerStrategy.h"
//#include "Game.h"

class PlayerStrategy;
class Player : public Observer {

public:
    Player();
    Player(int id);
    Player(int id, PlayerStrategy* strategy);
    ~Player();

    vector<Region> occupiedRegions;

    void pickRace(ComboList&);
    void picks_race(ComboList&);
    void conquers(int);


//    bool isBorder(MapRegions* regions,int regionID); //need improve later
    void conqueredRegion(int regionID);
    void firstConquest(int playerNum);
    Map* chooseMap(int playerNum); //return map according to player number
    void enemyLossesWithdrawals(int regionID, int requiredTokens);
    void redeployTokens();
    void redeployInLoss(int n);
    int reduceTokens();
    void increaseTokens(int n);

    void followingConquest();
    bool connectedToConquestRegion(int regionID);
    int basicRequiredTokens(int regionID);
    int requiredTokensToConquer(int regionID);

    bool enoughTokensToConquer(int regionID);
    bool enoughTokensToConquerInFinalAttempt(int regionID , int die);

    void finalConquestAttempt(int regionID);
    bool ownedRegion(int regionID);
//    bool emptyRegion(int regionID);
//    void firstConqueredRegion(int regionID);
    void setOwnerAndRegionPopulation(int regionID, int population);
    void showRegions();

    void reduceTokensToOneInDecline();
    void reduceTokensToOneInActiveAndResetToken();


    void scores();
    int reinforcementDie();
    void currentStates();
    void declineCombo(ComboList&);

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
    int getTotalRegionNumber() const;
    int getId() const;

    void setActiveRace(const Race &activeRace);
    void setDeclineRace(const Race &declineRace);
    void setActivePower(const Power &activePower);
    void setDeclinePower(const Power &declinePower);
    void setPlayed(bool played);
    void setHaveDeclineCombo(bool haveDeclineCombo);
    void setHaveActiveCombo(bool haveActiveCombo);
    void setId(int id);

//    int getTotalRegionPercentage() const;
//    void setTotalRegionPercentage(int totalRegionPercentage);

    ////design pattern
    void Update(const std::string&);
    void UpdateStatistics();
    double calculatePercentage();
    void UpdateBarGraph();
    void showBarGraph();

    ///strategt pattern
    void setStrategy(PlayerStrategy *strategy);
    void firstConquestByStrategy(int);
    void picks_raceByStrategy(ComboList& combo);
    void conquersByStrategy(int playerNum);
    void declineComboByStrategy(ComboList &combo);
    void redeployTokensByStrategy();

    void showInfo();
    void showInfo(Observer*);

    void showCoins(Observer* observer);
    void showHands(Observer* observer);

protected:
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
    PlayerStrategy * strategy;


};


#endif //SMALL_WORLD_PLAYER_H
