//
// Created by xintong cheng on 2018-03-29.
//

#include <iostream>
#include "ModerateStrategy.h"

ModerateStrategy::ModerateStrategy() {}

ModerateStrategy::~ModerateStrategy() {}

void ModerateStrategy::play() {
    std::cout << "ModerateStrategy";
}

void ModerateStrategy::firstConquestByStrategy(Player* player,int i) {
    player->firstConquest(i);
}

void ModerateStrategy::picks_raceByStrategy(Player* player, ComboList &combo) {
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
    player->reduceTokensToOneInDecline();
    player->setDeclineRace(player->getActiveRace());
    player->setDeclinePower(player->getActivePower());
    player->setHaveDeclineCombo(true);
    player->setHaveActiveCombo(false);
    player->currentStates();
}

void ModerateStrategy::redeployTokensByStrategy(Player * player) {
    player->redeployTokens();
}