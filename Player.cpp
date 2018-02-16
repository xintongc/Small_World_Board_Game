//
// Created by xintong cheng on 2018-02-12.
//

#include "Player.h"
#include "dice.h"

//constructor, default 5 coins for player 
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

//player rolling a dice
int Player::reinforcementDie() {
    dice.rollingDice();
    return dice.getDiceNum();
}

int Player::getTokens(){
    return totalTokens;
}

int Player::getCoins() {
    return victoryCoins;
}
