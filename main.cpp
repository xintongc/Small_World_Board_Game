#include <iostream>
#include "Game.h"
#include "strategy/AggressiveStrategy.h"


using namespace std;


int main() {

    Game* game = Game::getGame();
    game->initial();
//    game->initialPlayer();

    game->initialStrategyPlayer();


//    Player* player = new Player(1);
//    player->setStrategy(new AggressiveStrategy());
//    player->firstConquestByStrategy(2);



//    player->firstConquest(2);



//    game->playGame();

    game->playGameByStragegy();




return 0;
}
