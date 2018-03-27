#include <iostream>
#include "Game.h"
#include "ComboList.h"
#include "Game.h"
#include "ComboList.h"
#include "regions/MapRegions.h"

using namespace std;

int main() {

    Game* game = Game::getGame();
    game->initial();
    game->initialPlayer();

    MapRegions* playerRegions = MapRegions::getMapRegions();
    playerRegions->info();
    playerRegions->createThreePlayerRegions();
    playerRegions->display();

    game->playGame();
    game->endingGame();









    return 0;
}