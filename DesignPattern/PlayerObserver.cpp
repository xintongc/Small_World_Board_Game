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

void PlayerObserver::UpdateStatistics() {}

void PlayerObserver::Update(const std::string& str)
{
    display(str);
}

void PlayerObserver::display(const std::string& str)
{
    cout<<"\n==== From observer pattern ==== ";
    cout <<"Player "<< playerSubject->getId() << ": " << str << endl;
}

