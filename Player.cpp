//
// Created by xintong cheng on 2018-02-12.
//

#include "Player.h"

Player::Player() {
    totalTokens = 0;
    victoryCoins = 5;

    cout << "Player is created"<<endl;
}

Player::~Player() {
}

void Player::conquers(){
    cout<<"conquers is called"<<endl;
}

void Player::scores(){

}

int Player::reinforcementDie() {
    dice.rollingDice();
    return dice.getDiceNum();
}



int Player::getVictoryCoins() const {
    return victoryCoins;
}

int Player::getTotalTokens() const {
    return totalTokens;
}


void Player::setVictoryCoins(int victoryCoins) {
    Player::victoryCoins = victoryCoins;
}

void Player::setTotalTokens(int totalTokens) {
    Player::totalTokens = totalTokens;
}


