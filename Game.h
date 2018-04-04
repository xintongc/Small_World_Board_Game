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


class Game : public Subject{

private:
    static Game* game;
    Game();
    int round;
    int NumOfPlayers;
    int totalTurns;
    int turnMakerIndex;
    int regionNumber;
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
    int getRegionNumber() const;

    void setRound(int round);
    void setTotalTurns(int totalTurns);
    void setNumOfPlayers(int playerNumber);
    void setTurnMakerIndex(int turnMakerIndex);

    vector<Player> Players;
    
    //overriding subject method
    //display a header showing what player and what phase is currently being played
    void Notify(const std::string &str, Observer *);

    //for strategy pattern
    void initialStrategyPlayer();
    void selectStrategy();
    void playGameByStragegy();

    //for observer pattern without decorator
    void notifyTurn(Observer *);

};


#endif //SMALL_WORLD_GAME_H
