//
// Created by xintong cheng on 2018-03-29.
//

#include <iostream>
#include "ModerateStrategy.h"
#include "../regions/MapRegions.h"

ModerateStrategy::ModerateStrategy() {}

ModerateStrategy::~ModerateStrategy() {}

void ModerateStrategy::play() {
    std::cout << "ModerateStrategy";
}

void ModerateStrategy::firstConquestByStrategy(Player* player,int i) {
    player->firstConquest(i);
}

void ModerateStrategy::picks_raceByStrategy(Player* player, ComboList &combo) {
    Game* game = Game::getGame();
    if(game->getRound()==3 && player->getDeclineRace().getType()=="Ghouls"){
        player->setTotalTokens(0);
    }
    player->picks_race(combo);
}

void ModerateStrategy::conquersByStrategy(Player* player, int playerNum) {
    player->conquers(playerNum);


}

void ModerateStrategy::declineComboByStrategy(Player* player,ComboList &combo) {
    Game* game = Game::getGame();
    game->Notify("Decline active combo", player);

    if (player->isHaveDeclineCombo()){
        combo.raceVector.push_back(player->getDeclineRace());
        combo.powerVector.push_back(player->getDeclinePower());
        player->setHaveDeclineCombo(false);
    }

    player->setDeclineRace(player->getActiveRace());
    player->setDeclinePower(player->getActivePower());
    player->setHaveDeclineCombo(true);
    player->setHaveActiveCombo(false);

    if(game->getRound()==2 && player->getDeclineRace().getType()=="Ghouls"){
        player->reduceTokensToOneInActiveAndResetToken();
        player->currentStates();
        int playerNum = game->Players.size();
        conquersByStrategy(player, playerNum);
    }
    else{
        player->reduceTokensToOneInDecline();
        player->currentStates();
    }


}

void ModerateStrategy::redeployTokensByStrategy(Player * player) {
    player->redeployTokens();
}

