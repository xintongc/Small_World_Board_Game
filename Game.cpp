//
// Created by xintong cheng on 2018-02-27.
//

#include "Game.h"
#include <iostream>
#include <string>
#include <vector>
#include "MapLoader.h"

class MapLoader;

using namespace std;

Game::Game() {
    round=1;
}

Game::~Game() {
}

//--------D:/CLion-workspace/small_world/
void Game::initial() {
    int playerNumber = 0;

    cout << "How many playes in this game? Please enter a number between 2-5." << endl;
    cin >> playerNumber;
    while(playerNumber > 5 || playerNumber < 2){
        cout << "How many playes in this game? Please enter a number between 2-5." << endl;
        cin >> playerNumber;
    }
    NumOfPlayers = playerNumber;

    MapLoader mapLoader;

    switch (playerNumber){
        case 2:
            mapLoader.openFile("/Users/zncu/CLionProjects/small world/twoPlayer.map");
            break;
        case 3:
            mapLoader.openFile("D:/CLion-workspace/small_world/threePlayer.map");
            break;
        case 4:
            mapLoader.openFile("D:/CLion-workspace/small_world/fourPlayer.map");
            break;
        case 5:
            mapLoader.openFile("D:/CLion-workspace/small_world/fivePlayer.map");
            break;
    }
    mapLoader.readFile();
    mapLoader.closeInput();
    mapLoader.buildMap();
}

//------the right number of players is created, and set the total turns----------
void Game::initialPlayer() {
    round=1;

    Players.push_back(Player());
    Players.push_back(Player());

    switch (NumOfPlayers){
        case 2:
            totalTurns=10;
            break;
        case 3:
            totalTurns=10;
            Players.push_back(Player());
            break;
        case 4:
            totalTurns=9;
            Players.push_back(Player());
            Players.push_back(Player());
            break;
        case 5:
            totalTurns=8;
            Players.push_back(Player());
            Players.push_back(Player());
            Players.push_back(Player());
            break;
    }
    //cout<<Players.size()<<" players are created in the game. "<<endl;
}


bool Game::allPlayersFinishATurn() {
    for(int i=0;i<NumOfPlayers;i++){
        if (!Players[i].isPlayed())
            return false;
        else
            return true;
    }
}


void Game::startNewTurn() {
        int temp=0;
        int index=0;
        for(int i =0;i<NumOfPlayers;i++){       //--------------find who has the most coins and assign to turn maker----
            if(temp<Players[i].getVictoryCoins()){
                temp=Players[i].getVictoryCoins();
                index=i;
            }
        }
        setTurnMaker(Players[index]);           //useless
        setTurnMakerIndex(index);
        setRound(getRound()+1);                 //The First Player moves the Game Turn marker forward one spot on the Game Turn Track

        for(int i=0;i<NumOfPlayers;i++){        //------every new turn, set all players play status is false------------
            Players[i].setPlayed(false);
        }
        cout<<"\nturn maker is player"<<getTurnMakerIndex()+1<<". Turn "<<round<<" start now."<<endl;
}




//-------------getter and setter --------------------
int Game::getRound() const {
    return round;
}

void Game::setRound(int round) {
    Game::round = round;
}

const Player &Game::getTurnMaker() const {
    return turnMaker;
}

void Game::setTurnMaker(const Player &turnMaker) {
    Game::turnMaker = turnMaker;
}

int Game::getTotalTurns() const {
    return totalTurns;
}

void Game::setTotalTurns(int totalTurns) {
    Game::totalTurns = totalTurns;
}

int Game::getNumOfPlayers() const {
    return NumOfPlayers;
}

void Game::setNumOfPlayers(int NumOfPlayers) {
    Game::NumOfPlayers = NumOfPlayers;
}

int Game::getTurnMakerIndex() const {
    return turnMakerIndex;
}

void Game::setTurnMakerIndex(int turnMakerIndex) {
    Game::turnMakerIndex = turnMakerIndex;
}
