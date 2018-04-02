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

//void AggressiveStrategy::pickRace(ComboList& combo){
//
////    cout << "The Aggressive Strategy Player always choose the first combo list" << endl;
////
////    int orderNum = 1;
////    cout << "\nChoosing race \"" << combo.raceVector[orderNum - 1].getType()
////         << "\" and power \"" << combo.powerVector[orderNum - 1].getType()
////         << "\" from comboList vector" << endl;
////    for (int i = 0; i < orderNum - 1; i++) {            //-----------accumulate combo coins-----------------
////        combo.coinsVector[i]++;
////    }
////
////    setActiveRace(combo.raceVector[orderNum - 1]);      //-----------assignment of player's race, power, coins, tokens--------
////    setActivePower(combo.powerVector[orderNum - 1]);
////    setVictoryCoins(getVictoryCoins() + combo.coinsVector[orderNum - 1] - (orderNum-1));
////    setTotalTokens(getActiveRace().getTokens() + getActivePower().getTokens());
////    setHaveActiveCombo(true);
////
////    combo.raceVector.erase(combo.raceVector.begin() + orderNum - 1);        //-----------delete selected elements----------
////    combo.powerVector.erase(combo.powerVector.begin() + orderNum - 1);
////    combo.coinsVector.erase(combo.coinsVector.begin() + orderNum - 1);
//}

void AggressiveStrategy::firstConquestByStrategy(Player* player,int i){

    cout << "\nAggressiveStrategy firstConquestByStrategy" << endl;

    Game* game = Game::getGame();
    game->Notify("First conquers some regions", player);

    cout << "\nAggressiveStrategy player choose a unoccupied region to do the first conquest: "<< endl;

    MapRegions* playerRegions = MapRegions::getMapRegions();
    int regionID;
    int totalRegionNum = player->getTotalRegionNumber();
    bool getRegionID = false;

    for (int i = 1; i <= totalRegionNum; ++i) {
        regionID = i;
        bool isBorder = playerRegions->getRegion(regionID)->isBorder();
        bool isEnemie = playerRegions->getRegion(regionID)->getPopulation() > 0;

        if(isBorder && !isEnemie && !player->ownedRegion(regionID)){
            cout << "Region[" << i << "] been choosen." << endl;
            conqueredRegion(player, regionID);
            getRegionID = true;
            break;
        }
    }

    if(!getRegionID){
        for (int i = 1; i <= totalRegionNum; ++i) {
            regionID = i;
            bool isBorder = playerRegions->getRegion(regionID)->isBorder();
            bool isEnemie = playerRegions->getRegion(regionID)->getPopulation() > 0;

            if(isBorder && isEnemie && !player->ownedRegion(regionID)){
                cout << "Region[" << i << "] been choosen." << endl;
                conqueredRegion(player, regionID);
                break;
            }
        }
    }

}

void AggressiveStrategy::conqueredRegion(Player* player, int regionID){
    Game* game = Game::getGame();
    game->Notify(" conqured a region", player);

    int requiredTokens = player->basicRequiredTokens(regionID);
    MapRegions* playerRegions = MapRegions::getMapRegions();

    playerRegions->getRegion(regionID)->setOwner((Owner)player->getId());
    playerRegions->getRegion(regionID)->setPopulation(requiredTokens);
    int totalTokens = player->getTotalTokens() - requiredTokens;
    player->setTotalTokens(totalTokens);

    game->NotifyStatistics();
    game->NotifyBarGraph();

    followingConquest(player);
}

void AggressiveStrategy::followingConquest(Player* player){
    MapRegions* playerRegions = MapRegions::getMapRegions();

    cout << "AggressiveStrategy Player choose an unoccupied region to conquer:";
    int regionID;
    int totalRegionNum = player->getTotalRegionNumber();
    bool getRegionID = false;



    for (int i = 1; i <= totalRegionNum; ++i) {
        regionID = i;
        bool isEnemie = (playerRegions->getRegion(regionID)->getPopulation() > 0);

        if(player->connectedToConquestRegion(i) && !isEnemie && !player->ownedRegion(regionID)){
            cout << "AggressiveStrategy Player choose region[" << i << "] to conquer" <<endl;
            regionID = i;
            getRegionID = true;
            break;
        }
    }

    if(!getRegionID){
        for (int i = 1; i <= totalRegionNum; ++i) {
            regionID = i;
            bool isEnemie = (playerRegions->getRegion(regionID)->getPopulation() > 0);

            if(player->connectedToConquestRegion(i) && isEnemie && !player->ownedRegion(regionID)){
                cout << "AggressiveStrategy Player choose region[" << i << "] to conquer" <<endl;
                regionID = i;
                break;
            }
        }
    }

    int requiredTokes = player->requiredTokensToConquer(regionID);

    if(player->enoughTokensToConquer(regionID)){
        if(playerRegions->getRegion(regionID)->getPopulation() != 0){
            cout << "You conqured emeny region" << endl;
            enemyLossesWithdrawals(player, regionID, requiredTokes);
        } else {
            conqueredRegion(player, regionID);
        }
    } else {
        finalConquestAttempt(player, regionID);
    }
}

void AggressiveStrategy::finalConquestAttempt(Player* player, int regionID){
    cout << "\nSince your tokens are not enough to conquer this region, this is your final conquest attempt" << endl;
    cout << "Reinforcement Die is rolling...\n";
    int dieNum = player->reinforcementDie();
    cout << "The number you rolled is: " << dieNum << endl;
    int lastAttemptTokens = dieNum + player->getTotalTokens();
    cout << "After adding the die number, you have "<< lastAttemptTokens << " tokens" << endl;

    if (player->enoughTokensToConquerInFinalAttempt(regionID, dieNum)){
        player->setOwnerAndRegionPopulation(regionID,lastAttemptTokens);
        cout << "You conqued this region" << endl;
    } else {
        cout << "Sorry, you don't have enough tokens to conquer this region." << endl;
    }
    player->showRegions();
}

void AggressiveStrategy::enemyLossesWithdrawals(Player* player, int regionID, int requiredTokens){
    Game* game = Game::getGame();
    MapRegions* playerRegions = MapRegions::getMapRegions();
    game->NotifyStatistics();
    game->NotifyBarGraph();

    int enemyPopulation = playerRegions->getRegion(regionID)->getPopulation();
    int enemyID = (int)playerRegions->getRegion(regionID)->getOwner();

    playerRegions->getRegion(regionID)->setOwner((Owner)player->getId());    //set owner of conquer region to itself
    playerRegions->getRegion(regionID)->setPopulation(requiredTokens); //put populations to conquer region

    int enemyWithdrawalTokens = enemyPopulation/2;

    cout << "Player[" << enemyID <<"] your region [" << regionID << "] has been conqured by enemy, please redeploy" << endl;
    game->Players[enemyID].increaseTokens(enemyWithdrawalTokens);             //enemy put the withdrawed tokens to one region

    playerRegions->display();
}
void AggressiveStrategy::conquersByStrategy(Player* player, int playerNum) {
    followingConquest(player);
}

void AggressiveStrategy::declineComboByStrategy(Player* player,ComboList &combo) {
    Game *game = Game::getGame();
    game->Notify("Don't decline active combo", player);
    int playerNum = game->Players.size();

    //cout << "Don't decline combo" << endl;
    player->reduceTokensToOneInActiveAndResetToken();
    player->currentStates();
    conquersByStrategy(player, playerNum);
}

void AggressiveStrategy::redeployTokensByStrategy(Player *player) {
    player->redeployTokens();
}
