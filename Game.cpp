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

Game* Game::game = 0;
Game* Game::getGame(){
    if(game == 0){
        game = new Game;
    }
    return game;
}

Game::Game() {
    round=1;
}

Game::~Game() {
}

//D:/CLion-workspace/small_world/
//Users/zncu/CLionProjects/small world/
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
            mapLoader.openFile("/Users/zncu/CLionProjects/small world/threePlayer.map");
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


void Game::initialPlayer() {
    round=1;

    Players.push_back(Player(0));
    Players.push_back(Player(1));
    Players.push_back(Player(2));

    switch (NumOfPlayers){
        case 2:
            totalTurns=10;
            break;
        case 3:
            totalTurns=3;
            Players.push_back(Player(3));
            break;
        case 4:
            totalTurns=9;
            Players.push_back(Player(3));
            Players.push_back(Player(4));
            break;
        case 5:
            totalTurns=8;
            Players.push_back(Player(3));
            Players.push_back(Player(4));
            Players.push_back(Player(5));
            break;
    }
}


bool Game::allPlayersFinishATurn() {
    for(int i=1;i<=NumOfPlayers;i++){
        if (!Players[i].isPlayed())
            return false;
        else
            return true;
    }
}


void Game::startNewTurn() {
        int temp=0;
        int index=0;
        for(int i=1;i<=NumOfPlayers;i++){       //--------------find who has the most coins and assign to turn maker----
            if(temp<Players[i].getVictoryCoins()){
                temp=Players[i].getVictoryCoins();
                index=i;
            }
        }

        setTurnMakerIndex(index);
        setRound(getRound()+1);                 //The First Player moves the Game Turn marker forward one spot on the Game Turn Track

        for(int i=1;i<=NumOfPlayers;i++){        //------every new turn, set all players play status is false------------
            Players[i].setPlayed(false);
        }
        if(getRound() <= getTotalTurns()){
            cout<<"\nTurn maker is player"<<getTurnMakerIndex()<<". Turn "<<round<<" start now."<<endl;
        } else{
            cout << "\nGame end." << endl;
        }
}

void Game::endingGame() {
    int temp=0;
    int Winnerindex=0;
    for(int i =1;i<=NumOfPlayers;i++){
        if(temp<Players[i].getVictoryCoins()){
            temp=Players[i].getVictoryCoins();
            Winnerindex=i;
        }
    }
    cout<<"The winner is player"<<Winnerindex<<endl;
}

void Game::playGame() {
    ComboList combo;
    combo.setupCombo();
    int firstPlayerIndex;

    do {
        if (getRound() == 1) {                                      //---------------round 1--------------------------------
            cout << "\nTurn " << getRound()<< endl;

            for (int i = 1; i < Players.size(); i++) {
                Players[i].picks_race(combo, i);
                Players[i].conquers();
                Players[i].scores(i);

            }
            if (allPlayersFinishATurn())                            //--------------ensure every players play-----------
                startNewTurn();

        }
//----------------------------------------------------------------------------------------------------------------------
        if (getRound() <= getTotalTurns()) {                        //--------------round 2-8/9/10 ---------------------
            cout << "\nTurn " << getRound()<< endl;
            cout<<"========================================"<<endl;

            firstPlayerIndex = getTurnMakerIndex();                 //1. redefine each turn's turn maker (create new one each time, avoid reassign issue)------

            if(Players[firstPlayerIndex].isHaveActiveCombo()){     //2. if player has active combo, ask whether to decline
                Players[firstPlayerIndex].declineCombo(combo, firstPlayerIndex);
            } else{                                                //3. if player has no active combo, pick race
                Players[firstPlayerIndex].picks_race(combo, firstPlayerIndex);
            }

            Players[firstPlayerIndex].conquers();
            Players[firstPlayerIndex].scores(firstPlayerIndex);

//----------------------------------------------------------------------------------------------------------------------
            for (int i = 1; i < Players.size(); i++) {             //4. rest players play--------------------------
                if (i != firstPlayerIndex) {
                    if(Players[i].isHaveActiveCombo()){
                        Players[i].declineCombo(combo, i);
                    } else{
                        Players[i].picks_race(combo, i);
                    }
                    Players[i].conquers();
                    Players[i].scores(i);
                }
                else{
                    continue;
                }
            }
            if (allPlayersFinishATurn())
                startNewTurn();
        }
    } while (getRound() <= getTotalTurns());

    endingGame();

}



//-------------getter and setter --------------------
int Game::getRound() const {
    return round;
}

void Game::setRound(int round) {
    Game::round = round;
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
