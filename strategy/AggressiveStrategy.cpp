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

        if(isBorder && !isEnemie && !player->ownedRegion(regionID)){  // The priority of AggressiveStrategy player is choosing an unoccupied region to conquer
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

            if(isBorder && isEnemie && !player->ownedRegion(regionID)){ //if all unoccupied regions are not available, the player will conquer enemys' regions
                cout << "Region[" << i << "] been choosen." << endl;
                conqueredRegion(player, regionID);
                break;
            }
        }
    }

}

void AggressiveStrategy::conqueredRegion(Player* player, int regionID){ //conquered this region, mark this region to this player's and put tokens to this region
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

    followingConquest(player); //After play take this region, the player will continue his/her conquer
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
        if(playerRegions->getRegion(regionID)->getPopulation() != 0){  // if the region is owned by enemy and the player have enough tokens conquer this enemy's region, he/she occupied enemy's region
            cout << "You conqured emeny region" << endl;
            enemyLossesWithdrawals(player, regionID, requiredTokes);
        } else {
            conqueredRegion(player, regionID); // if the region is not owned by enemy and player have enough tokes to conquer, the player conqured this region
        }
    } else {
        finalConquestAttempt(player, regionID); // if the player do not have enough tokens to conquer, it will do the final conquest attempt
    }
}

void AggressiveStrategy::finalConquestAttempt(Player* player, int regionID){
    cout << "\nSince your tokens are not enough to conquer this region, this is your final conquest attempt" << endl;
    cout << "Reinforcement Die is rolling...\n";
    int dieNum = player->reinforcementDie();
    cout << "The number you rolled is: " << dieNum << endl; // The player rolling the Reinforcement Die to try the final conquest
    int lastAttemptTokens = dieNum + player->getTotalTokens();
    cout << "After adding the die number, you have "<< lastAttemptTokens << " tokens" << endl;

    if (player->enoughTokensToConquerInFinalAttempt(regionID, dieNum)){ // if the player rolled enough number to conquer the region, the region will be occupied by the player
        player->setOwnerAndRegionPopulation(regionID,lastAttemptTokens);
        cout << "You conqued this region" << endl;
    } else {                                                           // if the player do not have enough number to conquer, the player will not occupy this region
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
void AggressiveStrategy::conquersByStrategy(Player* player, int playerNum) {  // do the conquer by strategy
    followingConquest(player);
}

void AggressiveStrategy::declineComboByStrategy(Player* player,ComboList &combo) {
    Game *game = Game::getGame();
    game->Notify("Don't decline active combo", player);  // AggressiveStrategy player never decline an combo, the player will hold every thing until the game ends
    int playerNum = game->Players.size();

    //cout << "Don't decline combo" << endl;
    player->reduceTokensToOneInActiveAndResetToken();
    player->currentStates();
    conquersByStrategy(player, playerNum);
}

void AggressiveStrategy::redeployTokensByStrategy(Player *player) {
    player->redeployTokens();
}
