
#include "Wealthy.h"
#include "../Player.h"
#include<iostream>
using namespace std;

Wealthy::Wealthy() {
    setTokens(4);
    setType("Wealthy");
    setPower("");
}


Wealthy::~Wealthy() {
}

void Wealthy::powerSkill() {
    cout<<"Collect 7 bonus Victory coins, once only, at the end of your first turn."<<endl;
    //
}

void Wealthy::power(Player& player) {
    player.setVictoryCoins(player.getVictoryCoins()+7);
}