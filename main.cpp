#include <iostream>

#include "Game.h"
#include "ComboList.h"

using namespace std;


int main() {

    Game game;
    game.initial();
    game.initialPlayer();


    ComboList combo;
    combo.setupCombo();

    cout<<"turn "<<game.getRound()<<": "<<endl;
    for(int i=0;i<game.Players.size();i++){
        combo.print();
        cout<<"==============================="<<endl;
        cout<<"player"<<i+1<<" is picking race. "<<endl;
        game.Players[i].picks_race(combo);
        game.Players[i].currentStates();
    }














    return 0;
}