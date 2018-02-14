//
// Created by xintong cheng on 2018-02-12.
//

#include "Player.h"

Player::Player() {
    totalTokens = 0;
    victoryCoins = 5;
    cout << "create a player"<<endl;
}

Player::~Player() {
}


void Player::conquers(){

}

void Player::scores(){

}

int Player::reinforcementDie() {
    //int x = rand() % 4;
    Dice dice;
    dice.rollingDice();
    return dice.getDiceNum();
}

int Player::getTokens(){
    return totalTokens;
}

int Player::getCoins() {
    return victoryCoins;
}
