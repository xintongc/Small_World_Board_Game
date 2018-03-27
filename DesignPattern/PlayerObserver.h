//
// Created by yanra on 2018-03-27.
//

#ifndef SMALL_WORLD_PLAYEROBSERVER_H
#define SMALL_WORLD_PLAYEROBSERVER_H


#include "Observer.h"
#include "../Player.h"

class PlayerObserver: public Observer {
public:
    PlayerObserver();
    ~PlayerObserver();
    PlayerObserver(Player* player);
    void Update();
    void display();

private:
    Player* playerSubject;
};


#endif //SMALL_WORLD_PLAYEROBSERVER_H
