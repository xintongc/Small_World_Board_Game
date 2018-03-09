#include <iostream>

#include "Game.h"
#include "ComboList.h"

using namespace std;


int main() {

    Game game;
    game.initial();

    ComboList combo;
    combo.setupCombo();
    combo.print();
    Player player;

    //----test diff turns-----------
    for(int i=0;i<4;i++){
//    game.setTotalTurns(4);
//    while(game.getRound()<game.getTotalTurns()){
        player.picks_race(combo);
        cout<<"turn "<<game.getRound()<<": ";
        player.currentStates();
        combo.print(); //after pick-race, check current combo

    }














    return 0;
}