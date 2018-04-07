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

//    Player* player = new Player(1);
//    player->setStrategy(new AggressiveStrategy());
//    player->firstConquestByStrategy(2);

//    ComboList combo;
//    Player* player = new Player(1);
//    player->setStrategy(new ModerateStrategy());
//    player->picks_raceByStrategy(combo);



// strategy pattern driver
//    ComboList combo;
//    combo.setupCombo();
//    Player player1(1, new AggressiveStrategy());
//    Player player2(2, new DefensiveStrategy());
//    Player player3(3, new ModerateStrategy());








return 0;
}
