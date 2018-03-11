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

    static Game* game;
    Game();
    int round;
    int NumOfPlayers;
    int totalTurns;
    int turnMakerIndex;

public:
//    Game();
    static Game* getGame();
    virtual ~Game();
    void initial();
    void initialPlayer();
    void createMap();

    void playGame();
    void startNewTurn();
    bool allPlayersFinishATurn();
    void endingGame();

    int getRound() const;
    int getTotalTurns() const;
    int getNumOfPlayers() const;
    int getTurnMakerIndex() const;

    void setRound(int round);
    void setTotalTurns(int totalTurns);
    void setNumOfPlayers(int playerNumber);
    void setTurnMakerIndex(int turnMakerIndex);

    vector<Player> Players;

};


#endif //SMALL_WORLD_GAME_H
