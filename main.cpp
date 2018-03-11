#include <iostream>
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
    playerRegions->createTwoPlayerRegions();
    playerRegions->display();
    game->Players[1].setTotalTokens(5);
    game->Players[2].setTotalTokens(5);

    game->Players[1].conquerRegion(1);
    game->Players[1].conquerRegion(2);

    game->Players[2].conquerRegion(3);
    game->Players[2].conquerRegion(4);

    playerRegions->display();

    game->Players[1].enemyLossesWithdrawals(3,2);







//    Player* player = new Player();
//    player->setId(2);
//    player->setTotalTokens(2);
//    player->conquerRegion(6);

//    cout << endl;
//    player->firstConquest(2);


//    Map* map = Map::getMap(24);
//    map->display();


return 0;
}
