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

//---------!!!!!!!has problem, player cann't use game methods and variables---------------
void Player::picks_race() {
    Game game;
    int number;
    do{
        cout<<"Please select the number of combo: ";
        cin>>number;
        if(number>0 && number<6)
        {
            cout<<"You choose race "<<game.raceVector[number-1].getType()<<" and power "<<game.powerVector[number-1].getType()<<" from combo vector"<<endl;

            for(int i=0;i<number-1;i++){  //-----------accumulate coins---------------
                game.coinsVector[i]++;
            }

            activeRace=game.raceVector[number-1];
            activePower=game.powerVector[number-1];
            setVictoryCoins(game.coinsVector[number-1]);

            game.raceVector.erase(game.raceVector.begin()+number-1);
            game.powerVector.erase(game.powerVector.begin()+number-1);
            game.coinsVector.erase(game.coinsVector.begin()+number-1);
        }
        else if(number==6)
        {
            for(int i=0;i<5;i++){  //-----------accumulate coins---------------
                game.coinsVector[i]++;
            }

            int temp1=0;
            int temp2=0;

            if (!game.raceStack.empty()){
                temp1= game.raceStack.top();
            }
            if (!game.powerStack.empty()){
                temp2= game.powerStack.top();
            }
            cout<<"You choose race "<<game.switchRace(temp1).getType()<<" and power "<<game.switchRace(temp2).getType()<<" from combo stack"<<endl;
            activeRace=game.switchRace(temp1);
            activePower=game.switchPower(temp2);
        }
        else
        {
            cout<<"Invalid number"<<endl;
            continue;
        }
    }while(number<1 || number>6);

    game.replenishCombo();

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




