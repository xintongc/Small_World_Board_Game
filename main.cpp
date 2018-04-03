#include <iostream>
#include "Game.h"
#include "strategy/AggressiveStrategy.h"


using namespace std;


int main() {

    Game* game = Game::getGame();
    game->initial();
    game->initialPlayer();
    game->playGame();

//    game->initialStrategyPlayer();
//    game->playGameByStragegy();


//    Player* player = new Player(1);
//    player->setStrategy(new AggressiveStrategy());
//    player->firstConquestByStrategy(2);



//    player->firstConquest(2);








return 0;
}
