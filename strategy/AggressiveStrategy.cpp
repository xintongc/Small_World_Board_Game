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

void AggressiveStrategy::picks_raceByStrategy(ComboList &combo) {
    Game* game = Game::getGame();
    game->Notify("Picks race", this);
    //cout<<"========================================"<<endl;
    combo.print();
    //cout<<"\nplayer"<<getId()<<" is picking race now: "<<endl;
    pickRace(combo);
    cout<<"\nplayer"<<getId()<<"\'s current status: "<<endl;
    currentStates();
}

void AggressiveStrategy::pickRace(ComboList& combo){

    cout << "The Aggressive Strategy Player always choose the first combo list" << endl;

    int orderNum = 1;
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

    cout << "\nAggressiveStrategy player choose a unoccupied region to do the first conquest: "<< endl;

    MapRegions* playerRegions = MapRegions::getMapRegions();
    int regionID;
    int totalRegionNum = getTotalRegionNumber();

    for (int i = 1; i <= totalRegionNum; ++i) {
        regionID = i;
        bool isBorder = playerRegions->getRegion(regionID)->isBorder();
        bool isEnemie = playerRegions->getRegion(regionID)->getPopulation() > 0;

        if(isBorder && !isEnemie ){
            cout << "Region[" << i << "] been choosen." << endl;
            conqueredRegion(regionID);
            break;
        }
    }

}

void AggressiveStrategy::followingConquest(){
    MapRegions* playerRegions = MapRegions::getMapRegions();

    cout << "AggressiveStrategy Player choose an unoccupied region to conquer:";
    int regionID;
    int totalRegionNum = getTotalRegionNumber();

    for (int i = 1; i <= totalRegionNum; ++i) {
        if(connectedToConquestRegion(i)){
            cout << "AggressiveStrategy Player choose region[" << i << "] to conquer" <<endl;
            regionID = i;
            break;
        }
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



void AggressiveStrategy::conquersByStrategy(int playerNum) {
    followingConquest();
}

void AggressiveStrategy::declineComboByStrategy(ComboList &combo) {
    std::string str;
    bool cond = false;
    //cout<<"========================================"<<endl;
    //cout<<"\nplayer"<<getId()<<" is playing now: "<<endl;
    Game* game = Game::getGame();
    int playerNum = game->Players.size();
    do {
        cout << "Do you want to decline your current combo? (y/n)";
        cin >> str;
        if (str == "y" || str == "Y") {
            if (haveDeclineCombo) {                   //if already have declined combo, clear it and add it to combo vector
                combo.raceVector.push_back(declineRace);
                combo.powerVector.push_back(declinePower);
                haveDeclineCombo = false;
            }
            reduceTokensToOneInDecline();
            setDeclineRace(activeRace);                 //set current active combo to declined combo
            setDeclinePower(activePower);
            haveDeclineCombo = true;
            haveActiveCombo = false;
            cond = true;
            currentStates();
        } else if (str == "n" || str == "N") {
            cond = true;
            reduceTokensToOneInActiveAndResetToken();
            currentStates();
            conquers(playerNum);
        } else
            cout << "invalid input, type again. " << endl;
    } while (!cond);
}
