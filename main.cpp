#include <iostream>
#include "Game.h"
#include "strategy/AggressiveStrategy.h"


using namespace std;


int main() {

    //playing game (will show observer pattern)
    Game* game = Game::getGame();
    game->initial();
    game->initialPlayer();
    game->playGame();

    //playing game with strategy pattern
//    Game* game = Game::getGame();
//    game->initial();
//    game->initialStrategyPlayer();
//    game->playGameByStragegy();
    //









    return 0;
}
