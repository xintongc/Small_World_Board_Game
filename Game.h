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
    int round;
    int NumOfPlayers;
    int totalTurns;
    int turnMakerIndex;

public:
    Game();
    virtual ~Game();
    void initial();
    void initialPlayer();
    void createMap();

    void startNewTurn();
    bool allPlayersFinishATurn();
    void endingGame();

    const Player &getTurnMaker() const;
    int getRound() const;
    int getTotalTurns() const;
    int getNumOfPlayers() const;
    int getTurnMakerIndex() const;

    void setRound(int round);
    void setTurnMaker(const Player &turnMaker);
    void setTotalTurns(int totalTurns);
    void setNumOfPlayers(int playerNumber);
    void setTurnMakerIndex(int turnMakerIndex);

    vector<Player> Players;
    Player turnMaker;

};


#endif //SMALL_WORLD_GAME_H
