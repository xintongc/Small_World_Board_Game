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

void AggressiveStrategy::picks_raceByStrategy(Player* player, ComboList &combo) {
    player->picks_race(combo);
}

void AggressiveStrategy::pickRace(ComboList& combo){

//    cout << "The Aggressive Strategy Player always choose the first combo list" << endl;
//
//    int orderNum = 1;
//    cout << "\nChoosing race \"" << combo.raceVector[orderNum - 1].getType()
//         << "\" and power \"" << combo.powerVector[orderNum - 1].getType()
//         << "\" from comboList vector" << endl;
//    for (int i = 0; i < orderNum - 1; i++) {            //-----------accumulate combo coins-----------------
//        combo.coinsVector[i]++;
//    }
//
//    setActiveRace(combo.raceVector[orderNum - 1]);      //-----------assignment of player's race, power, coins, tokens--------
//    setActivePower(combo.powerVector[orderNum - 1]);
//    setVictoryCoins(getVictoryCoins() + combo.coinsVector[orderNum - 1] - (orderNum-1));
//    setTotalTokens(getActiveRace().getTokens() + getActivePower().getTokens());
//    setHaveActiveCombo(true);
//
//    combo.raceVector.erase(combo.raceVector.begin() + orderNum - 1);        //-----------delete selected elements----------
//    combo.powerVector.erase(combo.powerVector.begin() + orderNum - 1);
//    combo.coinsVector.erase(combo.coinsVector.begin() + orderNum - 1);
}

void AggressiveStrategy::firstConquestByStrategy(Player* player,int i){

//    cout << "AggressiveStrategy firstConquestByStrategy" << endl;
//
//    Game* game = Game::getGame();
//    game->Notify("First conquers some regions", this);
//
//    cout << "\nAggressiveStrategy player choose a unoccupied region to do the first conquest: "<< endl;
//
//    MapRegions* playerRegions = MapRegions::getMapRegions();
//    int regionID;
//    int totalRegionNum = getTotalRegionNumber();
//
//    for (int i = 1; i <= totalRegionNum; ++i) {
//        regionID = i;
//        bool isBorder = playerRegions->getRegion(regionID)->isBorder();
//        bool isEnemie = playerRegions->getRegion(regionID)->getPopulation() > 0;
//
//        if(isBorder && !isEnemie ){
//            cout << "Region[" << i << "] been choosen." << endl;
//            conqueredRegion(regionID);
//            break;
//        }
//    }

}

void AggressiveStrategy::followingConquest(){
//    MapRegions* playerRegions = MapRegions::getMapRegions();
//
//    cout << "AggressiveStrategy Player choose an unoccupied region to conquer:";
//    int regionID;
//    int totalRegionNum = getTotalRegionNumber();
//
//    for (int i = 1; i <= totalRegionNum; ++i) {
//        if(connectedToConquestRegion(i)){
//            cout << "AggressiveStrategy Player choose region[" << i << "] to conquer" <<endl;
//            regionID = i;
//            break;
//        }
//    }
//
//    int requiredTokes = requiredTokensToConquer(regionID);
//
//    if(enoughTokensToConquer(regionID)){
//        if(playerRegions->getRegion(regionID)->getPopulation() != 0){
//            cout << "You conqured emeny region" << endl;
//            enemyLossesWithdrawals(regionID, requiredTokes);
//        } else {
//            conqueredRegion(regionID);
//        }
//    } else {
//        finalConquestAttempt(regionID);
//    }
}



void AggressiveStrategy::conquersByStrategy(Player* player, int playerNum) {
    followingConquest();
}

void AggressiveStrategy::declineComboByStrategy(Player* player,ComboList &combo) {
  //  Player::declineComboByStrategy(combo);
}
