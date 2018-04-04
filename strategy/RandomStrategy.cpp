#include "RandomStrategy.h"
#include <iostream>

using namespace std;


RandomStrategy::RandomStrategy() {}


RandomStrategy::~RandomStrategy() {}

void RandomStrategy::play() {
    std::cout << "RandomStrategy";
}


//overriding the method by calling itself method
//player pick race randomly
void RandomStrategy::picks_raceByStrategy(Player *player, ComboList &combo) {
    Game *game = Game::getGame();
    game->Notify("Picks race randomly", player);
    combo.print();

    std::srand(time(0));
    int orderNum = (rand() % 6) + 1;

    cout << "\nRandom number is " << orderNum <<endl
         << "Choosing race \"" << combo.raceVector[orderNum - 1].getType()
         << "\" and power \"" << combo.powerVector[orderNum - 1].getType()
         << "\" from comboList vector" << endl;
    for (int i = 0; i < orderNum - 1; i++) {
        combo.coinsVector[i]++;
    }

    player->setActiveRace(combo.raceVector[orderNum - 1]);
    player->setActivePower(combo.powerVector[orderNum - 1]);
    player->setVictoryCoins(player->getVictoryCoins() + combo.coinsVector[orderNum - 1] - (orderNum - 1));
    player->setTotalTokens(player->getActiveRace().getTokens() + player->getActivePower().getTokens());
    player->setHaveActiveCombo(true);

    combo.raceVector.erase(combo.raceVector.begin() + orderNum - 1);
    combo.powerVector.erase(combo.powerVector.begin() + orderNum - 1);
    combo.coinsVector.erase(combo.coinsVector.begin() + orderNum - 1);
    player->currentStates();
}

//overriding the method by calling player method
void RandomStrategy::conquersByStrategy(Player *player, int playerNum) {
    followingConquest(player);
}

//overriding the method, random strategy player don't decline combo
void RandomStrategy::declineComboByStrategy(Player *player, ComboList &combo) {
    Game *game = Game::getGame();
    game->Notify("Don't decline active combo", player);
    int playerNum = game->Players.size();

    player->reduceTokensToOneInActiveAndResetToken();
    player->currentStates();
    conquersByStrategy(player, playerNum);
}

//overriding the method, random strategy player conquer the region by random number
//random number range is based on map region numbers. In the first turn, player has to conquer board regions, 
//if random number is not a board, the system will keep generate a new random number until it can conquer a board region
void RandomStrategy::firstConquestByStrategy(Player *player, int i) {
    Game* game = Game::getGame();
    game->Notify("First conquers some regions by random", player);

    int regionNum = game->getRegionNumber();
    int regionID;
    std::srand(time(0));
    regionID = (rand() % regionNum) + 1;
    cout<<"Random number is "<<regionID<<endl;

    MapRegions* twoPlayerRegions = MapRegions::getMapRegions();
    bool isBorder = twoPlayerRegions->getRegion(regionID)->isBorder();

    if(isBorder){
        conqueredRegion(player, regionID);
    } else {
        while(!isBorder){
            cout << "Random again" << endl;
            regionID = (rand() % regionNum) + 1;
            isBorder = twoPlayerRegions->getRegion(regionID)->isBorder();
        }
        conqueredRegion(player, regionID);
    }

}

//heloing method for firstConquestByStrategy
void RandomStrategy::conqueredRegion(Player* player, int regionID){
    cout<<"Random number to conquer a region:"<< regionID <<endl;
    Game* game = Game::getGame();
    game->Notify("Conqured a region", player);

    int requiredTokens = player->basicRequiredTokens(regionID);
    MapRegions* playerRegions = MapRegions::getMapRegions();

    playerRegions->getRegion(regionID)->setOwner((Owner)player->getId());
    playerRegions->getRegion(regionID)->setPopulation(requiredTokens);
    player->setTotalTokens(player->getTotalTokens() - requiredTokens);

    game->NotifyStatistics();
    game->NotifyBarGraph();

    followingConquest(player);
}

//helping method for conqueredRegion
//it will generate random number to conquer a region
void RandomStrategy::followingConquest(Player* player){
    Game* game = Game::getGame();
    MapRegions* playerRegions = MapRegions::getMapRegions();

    cout << "\nRandomly choosing the region to conquerd:";
    int regionID;
    int regionNum = game->getRegionNumber();
    std::srand(time(0));
    regionID = (rand() % regionNum) + 1;
    cout<<regionID<<endl;

    //if the region is not connected with the current holding region, game will keep generate a number until it can conquer a region
    while(!player->connectedToConquestRegion(regionID)){
        cout << "You unable to conquerd this region, since it is not connected to your owned regions" << endl;
        regionID = (rand() % regionNum) + 1;
        cout << "\nRandomly choosing the region to conquerd:"<<regionID<<endl;
    }
    //if the region has been conquered by player, game will keep generate a number until it can conquer a region
    while(player->ownedRegion(regionID)){
        cout << "This region is already conquered by you, please choose another region:"<< endl;
        regionID = (rand() % regionNum) + 1;
        cout << "\nRandomly choosing the region to conquerd:"<<regionID<<endl;
    }

    int requiredTokes = player->requiredTokensToConquer(regionID);

    //for conquering a enemy region. if player has enough tokens, conquer this region and enemy redoly the tokens; else calling final conquest to rolling a die
    if(player->enoughTokensToConquer(regionID)){
        if(playerRegions->getRegion(regionID)->getPopulation() != 0){
            cout << "You conqured emeny region" << endl;
            enemyLossesWithdrawals(player, regionID, requiredTokes);
        } else {
            conqueredRegion(player, regionID);
        }
    } else {
        player->finalConquestAttempt(regionID);
    }
}

//overriding the method. Set default that player dont redeploy tokens every turn.
void RandomStrategy::redeployTokensByStrategy(Player* player){
    Game* game = Game::getGame();
    game->Notify("Don't redeploy tokens", player);
    player->showRegions();
}

//helping method for followingConquest.  
void RandomStrategy::enemyLossesWithdrawals(Player* player, int regionID, int requiredTokens){
    Game* game = Game::getGame();
    MapRegions* playerRegions = MapRegions::getMapRegions();
    game->NotifyStatistics();
    game->NotifyBarGraph();

    int enemyPopulation = playerRegions->getRegion(regionID)->getPopulation();
    int enemyID = (int)playerRegions->getRegion(regionID)->getOwner();

    playerRegions->getRegion(regionID)->setOwner((Owner)player->getId());    //set owner of conquer region to itself
    playerRegions->getRegion(regionID)->setPopulation(requiredTokens);       //put populations to conquer region

    int enemyWithdrawalTokens = enemyPopulation/2;

    cout << "Player[" << enemyID <<"] your region [" << regionID << "] has been conqured by enemy, please redeploy" << endl;

    game->Players[enemyID].increaseTokens(enemyWithdrawalTokens);             //enemy put the withdrawed tokens to one region
    playerRegions->display();
    followingConquest(player);
}
