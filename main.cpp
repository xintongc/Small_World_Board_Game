#include <iostream>
#include "Game.h"
#include "strategy/AggressiveStrategy.h"
#include "strategy/ModerateStrategy.h"
#include "strategy/DefensiveStrategy.h"


using namespace std;


int main() {

    Game* game = Game::getGame();
    game->initial();
//    game->initialPlayer();
//    game->playGame();

    game->initialStrategyPlayer();
    game->playGameByStragegy();






return 0;
}
