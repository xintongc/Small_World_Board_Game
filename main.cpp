#include <iostream>

#include "Game.h"
#include "Combo.h"
#include "ComboList.h"

using namespace std;


int main() {

//    Game game;
//    game.initial();
//    game.listAllPairs();
//    //game.printStacks();
//
//    game.initialPowerVector();
//    game.initialRaceVector();
//    game.initialCoinsVector();
//
//    game.printCurrentVectors();
//    game.showStackTop();
//    cout<<" "<<endl;

//    game.pickCombo();
//    game.printCurrentVectors();
//    cout<<" "<<endl;
//
//    game.replenishCombo();
//    game.printCurrentVectors();


//    game.printCurrentVectors();

    ComboList combo;
    combo.setupCombo();
    combo.print();
    Player player;
    player.picks_race(combo);
    combo.print();












    return 0;
}