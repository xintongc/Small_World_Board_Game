//
// Created by xintong cheng on 2018-03-29.
//

#ifndef SMALL_WORLD_STATISTICSPUBLISHER_H
#define SMALL_WORLD_STATISTICSPUBLISHER_H


#include "../DesignPattern/Subject.h"
#include "../Game.h"
#include "../regions/MapRegions.h"

class StatisticsPublisher : public Subject{

    Game* game = Game::getGame();
    MapRegions* mapRegions = MapRegions::getMapRegions();

private:
    int playerNum = game->getNumOfPlayers();
    int totalRegions = mapRegions->getRegionsSize();
    vector<Player> players;


};


#endif //SMALL_WORLD_STATISTICSPUBLISHER_H
