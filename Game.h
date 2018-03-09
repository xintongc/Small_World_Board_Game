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
    Map map = Map(1);
    vector<Player> Players;
    Player turnMaker;
    int round;
    int totalTurns;
    int playerNumber;

public:
    Game();
    virtual ~Game();
    void createMap();

    void startNewTurn();
    bool allPlayersFinishATurn();


    const Player &getTurnMaker() const;
    int getRound() const;
    int getTotalTurns() const;
    int getPlayerNumber() const;

    void setRound(int round);
    void setTurnMaker(const Player &turnMaker);
    void setTotalTurns(int totalTurns);
    void setPlayerNumber(int playerNumber);

};


#endif //SMALL_WORLD_GAME_H
