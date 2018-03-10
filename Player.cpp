//
// Created by xintong cheng on 2018-02-12.
//

#include "Player.h"
#include "Game.h"
#include "Dice.h"

//constructor, default 5 coins for player 
Player::Player() {
    totalTokens = 0;
    victoryCoins = 50;
    //cout << "Player is created"<<endl;
}

Player::~Player() {
}

void Player::currentStates() {
    cout<<"\nactive race: "<<getActiveRace().getType()<<" "<<getActiveRace().getTokens()<<endl;
    cout<<"active power: "<<getActivePower().getType()<<" "<<getActivePower().getTokens()<<endl;
    cout<<"total tokens: "<<getTotalTokens()<<endl;
    cout<<"victory coins: "<<getVictoryCoins()<<endl;


}

//============so far, pick race and for each turn coins change done================================
void Player::pickRace(ComboList& combo) {
    int orderNum;
    do{
        cout<<"\nPlease select the orderNum of combo: ";
        cin>>orderNum;

        //----------check whether have enough coins to select combo----------
//        if(victoryCoins < orderNum){
//            cout<<"Your victory coins are not enough to select the combo. "<<endl;
//            continue;
//        }
//        else {
            if (orderNum > 0 && orderNum < 6) {                     //====================pick from vector==============
                cout << "\nYou choose race \"" << combo.raceVector[orderNum - 1].getType()
                     << "\" and power \"" << combo.powerVector[orderNum - 1].getType()
                     << "\" from comboList vector" << endl;
                for (int i = 0; i < orderNum - 1; i++) {            //-----------accumulate combo coins-----------------
                    combo.coinsVector[i]++;
                }

                setActiveRace(combo.raceVector[orderNum - 1]);      //-----------assignment of player's race, power, coins, tokens--------
                setActivePower(combo.powerVector[orderNum - 1]);
                setVictoryCoins(getVictoryCoins() + combo.coinsVector[orderNum - 1] - (orderNum-1));
                setTotalTokens(getActiveRace().getTokens() + getActivePower().getTokens());

                combo.raceVector.erase(combo.raceVector.begin() + orderNum - 1);        //-----------delete selected elements----------
                combo.powerVector.erase(combo.powerVector.begin() + orderNum - 1);
                combo.coinsVector.erase(combo.coinsVector.begin() + orderNum - 1);

            }
            else if (orderNum == 6) {                               //===================pick from stack================
                for (int i = 0; i < 5; i++) {                       //-----------accumulate combo coins-----------------
                    combo.coinsVector[i]++;
                }

                int temp1 = 0;
                int temp2 = 0;

                if (!combo.raceStack.empty()) {                     //----------------delete elements from stack--------
                    temp1 = combo.raceStack.top();
                    combo.raceStack.pop();
                }
                if (!combo.powerStack.empty()) {
                    temp2 = combo.powerStack.top();
                    combo.powerStack.pop();
                }
                cout << "\nYou choose race \"" << combo.switchRace(temp1).getType() << "\" and power \""
                     << combo.switchPower(temp2).getType() << "\" from combo stack. " << endl;

                activeRace = combo.switchRace(temp1);               //-----------assignment of player's race, power, coins, tokens-----
                activePower = combo.switchPower(temp2);
                setTotalTokens(getActiveRace().getTokens() + getActivePower().getTokens());
                setVictoryCoins(getVictoryCoins() - 5);
            }
            else {
                cout << "Invalid number. " << endl;
                continue;
            }
      //  }
    }while(orderNum<1 || orderNum>6);

    combo.replenishCombo();                                         //-----------------------replenish combo------------

}


void Player::picks_race(ComboList& combo, int index) {
    cout<<"\n==============================="<<endl;
    combo.print();
    cout<<"player"<<index<<" is picking race. "<<endl;
    pickRace(combo);
    cout<<"player"<<index<<"\'s current status: "<<endl;
    currentStates();
}


void Player::conquers(){
    cout<<"conquer"<<endl;
}

void Player::scores(){
    cout<<"score"<<endl;

    setPlayed(true);                //----------finish play----------------------------
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

bool Player::isPlayed() const {
    return played;
}

void Player::setPlayed(bool played) {
    Player::played = played;
}




