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
        player.currentStates();
        player.picks_race(combo);
        cout<<"turn "<<i<<"\t: ";
        cout<<player.getActiveRace().getType()<<" "<<player.getActiveRace().getTokens()<<"\t";
        cout<<player.getActivePower().getType()<<" "<<player.getActivePower().getTokens()<<"\t";
        cout<<player.getTotalTokens()<<endl;
        cout<<"coins "<<player.getVictoryCoins()<<endl;
        combo.print(); //after pick-race, check current combo

    }














    return 0;
}