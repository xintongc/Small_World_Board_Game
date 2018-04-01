//
// Created by xintong cheng on 2018-03-29.
//

#include <iostream>
#include "AggressiveStrategy.h"


AggressiveStrategy::AggressiveStrategy() {}

AggressiveStrategy::~AggressiveStrategy() {

}

void AggressiveStrategy::play() {
    std::cout<< "AggressiveStrategy";
}



void AggressiveStrategy::pickRace(ComboList& combo){

    cout << "The Aggressive Strategy Player always choose the first combo list" << endl;

    int orderNum = 0;
    cout << "\nChoosing race \"" << combo.raceVector[orderNum - 1].getType()
         << "\" and power \"" << combo.powerVector[orderNum - 1].getType()
         << "\" from comboList vector" << endl;
    for (int i = 0; i < orderNum - 1; i++) {            //-----------accumulate combo coins-----------------
        combo.coinsVector[i]++;
    }

    setActiveRace(combo.raceVector[orderNum - 1]);      //-----------assignment of player's race, power, coins, tokens--------
    setActivePower(combo.powerVector[orderNum - 1]);
    setVictoryCoins(getVictoryCoins() + combo.coinsVector[orderNum - 1] - (orderNum-1));
    setTotalTokens(getActiveRace().getTokens() + getActivePower().getTokens());
    setHaveActiveCombo(true);

    combo.raceVector.erase(combo.raceVector.begin() + orderNum - 1);        //-----------delete selected elements----------
    combo.powerVector.erase(combo.powerVector.begin() + orderNum - 1);
    combo.coinsVector.erase(combo.coinsVector.begin() + orderNum - 1);
}

void AggressiveStrategy::firstConquestByStrategy(int playerNum){
    Game* game = Game::getGame();
    game->Notify("First conquers some regions", this);

    cout << "\nAggressiveStrategy player choose a empty region to do the first conquest: ";

    MapRegions* playerRegions = MapRegions::getMapRegions();
    int regionID;
    int totalRegionNum = getTotalRegionNumber();

    for (int i = 1; i <= totalRegionNum; ++i) {
        regionID = i;
        bool isBorder = playerRegions->getRegion(regionID)->isBorder();
        bool isEnemie = playerRegions->getRegion(regionID)->getPopulation() > 0;

        if(isBorder && !isEnemie ){
            conqueredRegion(regionID);
            break;
        }
    }

}

void AggressiveStrategy::followingConquest(){
    MapRegions* playerRegions = MapRegions::getMapRegions();

    cout << "Please input the region you want to conquerd:";
    int regionID;
    int totalRegionNum = getTotalRegionNumber();

    for (int i = 1; i <= totalRegionNum; ++i) {

    }


    while(!connectedToConquestRegion(regionID)){
        cout << "You unable to conquerd this region, since it is not connected to your owned regions" << endl;
        cin >> regionID;
    }
    while(ownedRegion(regionID)){
        cout << "This region is already conquered by you, please choose another region:";
        cin >> regionID;
    }

    int requiredTokes = requiredTokensToConquer(regionID);

    if(enoughTokensToConquer(regionID)){
        if(playerRegions->getRegion(regionID)->getPopulation() != 0){
            cout << "You conqured emeny region" << endl;
            enemyLossesWithdrawals(regionID, requiredTokes);
        } else {
            conqueredRegion(regionID);
        }
    } else {
        finalConquestAttempt(regionID);
    }
}

void AggressiveStrategy::picks_raceByStrategy(ComboList &combo) {

}

void AggressiveStrategy::conquersByStrategy(int playerNum) {

}

void AggressiveStrategy::declineComboByStrategy(ComboList &combo) {

}
