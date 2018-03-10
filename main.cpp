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
    Player turnMaker;
    int firstPlayerIndex;

    // not test yet
    do {
        if (game.getRound() == 1) {                             //---------------round 1--------------------------------

            cout << "\nturn " << game.getRound() << ": " << endl;

            for (int i = 0; i < game.Players.size(); i++) {
                game.Players[i].picks_race(combo, i);
                game.Players[i].conquers();
                game.Players[i].scores();
            }
            if (game.allPlayersFinishATurn())
                game.startNewTurn();

        }
        else if (game.getRound() <= game.getTotalTurns()) {     //----------round 2-8/9/10 -----------------------------

            cout << "\nturn " << game.getRound() << ": " << endl;

            turnMaker = game.getTurnMaker();                    //----------define each turn's turn maker and play------

            firstPlayerIndex = game.getTurnMakerIndex();
            turnMaker.picks_race(combo, firstPlayerIndex);
            turnMaker.conquers();
            turnMaker.scores();

            for (int i = 0; i < game.Players.size(); i++) {     //------------rest players play-------------------------
                if (i != firstPlayerIndex) {
                    game.Players[i].picks_race(combo, i);
                    game.Players[i].conquers();
                    game.Players[i].scores();
                }
                else{
                    continue;
                }
            }

            if (game.allPlayersFinishATurn())
                game.startNewTurn();

        }
        else{                                                   //----------round finish, show end message--------------
            cout << "game end" << endl;
        }
    } while (game.getRound() <= game.getTotalTurns());















    return 0;
}