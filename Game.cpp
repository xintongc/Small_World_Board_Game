//
// Created by xintong cheng on 2018-02-27.
//

#include "Game.h"
#include "Race/Amazons.h"
#include "Race/Dwarves.h"
#include "Race/Elves.h"
#include "Race/Ghouls.h"
#include "Race/Giants.h"
#include "Race/Halflings.h"
#include "Race/Humans.h"
#include "Race/Orcs.h"
#include "Race/Ratmen.h"
#include "Race/Skeletons.h"
#include "Race/Sorcerers.h"
#include "Race/Tritons.h"
#include "Race/Trolls.h"
#include "Race/Wizards.h"
#include "Power/Alchemist.h"
#include "Power/Berserk.h"
#include "Power/Bivouacking.h"
#include "Power/Commando.h"
#include "Power/Diplomat.h"
#include "Power/DragonMaster.h"
#include "Power/Flying.h"
#include "Power/Forest.h"
#include "Power/Fortified.h"
#include "Power/Heroic.h"
#include "Power/Hill.h"
#include "Power/Merchant.h"
#include "Power/Mounted.h"
#include "Power/Pillaging.h"
#include "Power/Seafaring.h"
#include "Power/Spirit.h"
#include "Power/Stout.h"
#include "Power/Swamp.h"
#include "Power/Underworld.h"
#include "Power/Wealthy.h"
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include "MapLoader.h"

class MapLoader;

using namespace std;

Game::Game() {}


Game::~Game() {
}

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
            mapLoader.openFile("/Users/zncu/CLionProjects/small world/threePlayer.map");
            break;
        case 4:
            mapLoader.openFile("/Users/zncu/CLionProjects/small world/fourPlayer.map");
            break;
        case 5:
            mapLoader.openFile("/Users/zncu/CLionProjects/small world/fivePlayer.map");
            break;
    }
    mapLoader.readFile();
    mapLoader.closeInput();
    map = mapLoader.buildMap();
}

}
