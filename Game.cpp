//
// Created by xintong cheng on 2018-02-27.
//

#include "Game.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;


void Game::createMap() {
    int playerNumber = 0;

    cout << "How many playes in this game? Please enter a number between 2-5." << endl;
    cin >> playerNumber;

    while(playerNumber > 5 || playerNumber < 2){
        cout << "How many playes in this game? Please enter a number between 2-5." << endl;
    }

    MapLoader mapLoader;

    switch (playerNumber){
        case 2:
            mapLoader.openFile("/Users/zncu/CLionProjects/small world/twoPlayer.map");
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
    }
    mapLoader.readFile();
    mapLoader.closeInput();
    map = mapLoader.buildMap();
    map.display();
}


Game::~Game() {

}



