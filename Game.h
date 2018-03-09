//
// Created by xintong cheng on 2018-02-27.
//

#ifndef SMALL_WORLD_GAME_H
#define SMALL_WORLD_GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include "Player.h"
#include "Map.h"



class Game {

private:

    vector<Player> Players;
    int round;
    int NumOfPlayers;
    Map map = Map(1);

public:
    Game();
    virtual ~Game();
    void initial();
};


#endif //SMALL_WORLD_GAME_H
