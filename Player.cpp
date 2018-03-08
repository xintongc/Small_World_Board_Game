//
// Created by xintong cheng on 2018-02-12.
//

#include "Player.h"
#include "Game.h"

//constructor, default 5 coins for player 
Player::Player() {
    totalTokens = 0;
    victoryCoins = 5;
    //cout << "Player is created"<<endl;
}

Player::~Player() {
}

void Player::picks_race(ComboList& combo) {
    int orderNum;
    do{
        cout<<"\nPlease select the orderNum of combo: ";
        cin>>orderNum;
        if(orderNum>0 && orderNum<6)
        {
            cout<<"\nYou choose race \""<<combo.raceVector[orderNum-1].getType()
                <<"\" and power \""<<combo.powerVector[orderNum-1].getType()
                <<"\" from comboList vector"<<endl;
            for(int i=0;i<orderNum-1;i++){  //-----------accumulate coins---------------
                combo.coinsVector[i]++;
            }

            setActiveRace(combo.raceVector[orderNum-1]);
            setActivePower(combo.powerVector[orderNum-1]);
            setVictoryCoins(combo.coinsVector[orderNum-1]);

            combo.raceVector.erase(combo.raceVector.begin()+orderNum-1);
            combo.powerVector.erase(combo.powerVector.begin()+orderNum-1);
            combo.coinsVector.erase(combo.coinsVector.begin()+orderNum-1);
        }
        else if(orderNum==6)
        {
            for(int i=0;i<5;i++){  //-----------accumulate coins---------------
                combo.coinsVector[i]++;
            }

            int temp1=0;
            int temp2=0;

            if (!combo.raceStack.empty()){
                temp1= combo.raceStack.top();
            }
            if (!combo.powerStack.empty()){
                temp2= combo.powerStack.top();
            }
            cout<<"\nYou choose race \""<<combo.switchRace(temp1).getType()<<"\" and power \""<<combo.switchRace(temp2).getType()<<"\" from combo stack. "<<endl;
            activeRace=combo.switchRace(temp1);
            activePower=combo.switchPower(temp2);
        }
        else
        {
            cout<<"Invalid number. "<<endl;
            continue;
        }
    }while(orderNum<1 || orderNum>6);

    combo.replenishCombo();

}





void Player::conquers(){
    cout<<"conquers is called"<<endl;
}

void Player::scores(){

}

//player rolling a dice
int Player::reinforcementDie() {
    Dice dice;
    dice.rollingDice();
    return dice.getDiceNum();
}

//------------getter and setter-------------------------
int Player::getVictoryCoins() const {
    return victoryCoins;
}

void Player::setVictoryCoins(int victoryCoins) {
    Player::victoryCoins = victoryCoins;
}

int Player::getTotalTokens() const {
    return totalTokens;
}

void Player::setTotalTokens(int totalTokens) {
    Player::totalTokens = totalTokens;
}

const Race &Player::getActiveRace() const {
    return activeRace;
}

void Player::setActiveRace(const Race &activeRace) {
    Player::activeRace = activeRace;
}

const Race &Player::getDeclineRace() const {
    return declineRace;
}

void Player::setDeclineRace(const Race &declineRace) {
    Player::declineRace = declineRace;
}

const Power &Player::getActivePower() const {
    return activePower;
}

void Player::setActivePower(const Power &activePower) {
    Player::activePower = activePower;
}

const Power &Player::getDeclinePower() const {
    return declinePower;
}

void Player::setDeclinePower(const Power &declinePower) {
    Player::declinePower = declinePower;
}




