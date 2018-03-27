//
// Created by yanra on 2018-03-27.
//

#include "PlayerObserver.h"
#include "../Player.h"
#include <iostream>
using namespace std;

PlayerObserver::PlayerObserver() {};

PlayerObserver::~PlayerObserver() {
    playerSubject->Detach(this);
};

PlayerObserver::PlayerObserver(Player *player) {
    playerSubject=player;
    playerSubject->Attach(this);
}

void PlayerObserver::Update()
{
    display();
}

void PlayerObserver::display()
{
    cout <<"Player "<< playerSubject->getId() << " starts to play the game. " << endl;
}

