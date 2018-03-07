#include <iostream>

#include "Game.h"
using namespace std;


int main() {

    Game game;
    game.initial();
    game.listAllPairs();
    //game.printStacks();

    game.initialPowerVector();
    game.initialRaceVector();
    game.initialCoinsVector();

    game.printCurrentVectors();
    game.showStackTop();
    cout<<" "<<endl;

//    game.pickCombo();
//    game.printCurrentVectors();
//    cout<<" "<<endl;
//
//    game.replenishCombo();
//    game.printCurrentVectors();

    Player player;
    player.picks_race();
    game.printCurrentVectors();

    return 0;
}