#include <iostream>
#include "Game.h"


using namespace std;


int main() {

    Game* game = Game::getGame();
    game->initial();
    game->initialPlayer();
    game->playGame();





return 0;
}
