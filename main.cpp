#include <iostream>
#include "Game.h"


using namespace std;


int main() {

    Game* game = Game::getGame();
    game->initial();
    game->initialPlayer();

//    Subject sub;
//    for(int i=1; i< game->Players.size();i++) {
//        Player *p = &game->Players[i];
//        PlayerObserver *pobs = new PlayerObserver(p);
//    }


//    for(int i=1; i< game->Players.size();i++) {
//        StatisticsObserver *statisticsObserver = new StatisticsObserver();
//        for (int j = 1; j < game->Players.size(); ++j) {
//            Player *p = &game->Players[i];
//            statisticsObserver->statisticsSubject.push_back(p);
//        }
//    }



    game->playGame();


   // delete pobs;


return 0;
}
