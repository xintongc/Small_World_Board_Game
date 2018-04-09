#include <iostream>
#include "Game.h"
#include "strategy/AggressiveStrategy.h"


#include "strategy/ModerateStrategy.h"
#include "strategy/DefensiveStrategy.h"



using namespace std;




int main() {


//    //playing game (will show observer pattern)
    Game* game = Game::getGame();
    game->initial();
    game->initialPlayer();
    game->playGame();

//    //playing game with strategy pattern
//    Game* game = Game::getGame();
//    game->initial();
//    game->initialStrategyPlayer();
//    game->playGameByStragegy();


    //two players play game
//    Game* game = Game::getGame();
//    game->twoPlayersTournaments();
//    game->playGameByStragegy();

//    //three players play game
//    Game* game = Game::getGame();
//    game->threePlayersTournaments();
//    game->playGameByStragegy();
//
//
//    //four players play game
//    Game* game = Game::getGame();
//    game->fourPlayersTournaments();
//    game->playGameByStragegy();
//
//
//
//    //five players play game
//    Game* game = Game::getGame();
//    game->fivePlayersTournaments();
//    game->playGameByStragegy();









return 0;

}
