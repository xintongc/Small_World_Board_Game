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
    haveActiveCombo=false;
    haveDeclineCombo=false;
}

Player::~Player() {
}

void Player::currentStates() {
    if(isHaveActiveCombo()){
        cout<<"active race: "<<getActiveRace().getType()<<" "<<getActiveRace().getTokens()<<endl;
        cout<<"active power: "<<getActivePower().getType()<<" "<<getActivePower().getTokens()<<endl;
    } else{
        cout<<"active race: empty."<<endl;
        cout<<"active power: empty."<<endl;
    }

   if(isHaveDeclineCombo()){
       cout<<"decline race: "<<getDeclineRace().getType()<<endl;
       cout<<"decline power: "<<getDeclinePower().getType()<<endl;
   } else{
       cout<<"decline race: empty."<<endl;
       cout<<"decline power: empty."<<endl;
   }

    cout<<"total tokens: "<<getTotalTokens()<<endl;
    cout<<"victory coins: "<<getVictoryCoins()<<endl;


}

//============so far, pick race and for each turn coins change done================================
void Player::pickRace(ComboList& combo) {
    int orderNum;
    do{
        cout<<"Please select the orderNum of combo: ";
        cin>>orderNum;

        //----------check whether have enough coins to select combo----------
//        if(victoryCoins < orderNum){
//            cout<<"Your victory coins are not enough to select the combo. "<<endl;
//            continue;
//        }
            if (orderNum > 0 && orderNum < 7) {                     //====================pick from vector==============
                cout << "\nChoosing race \"" << combo.raceVector[orderNum - 1].getType()
                     << "\" and power \"" << combo.powerVector[orderNum - 1].getType()
                     << "\" from comboList vector" << endl;
                for (int i = 0; i < orderNum - 1; i++) {            //-----------accumulate combo coins-----------------
                    combo.coinsVector[i]++;
                }

                setActiveRace(combo.raceVector[orderNum - 1]);      //-----------assignment of player's race, power, coins, tokens--------
                setActivePower(combo.powerVector[orderNum - 1]);
                setVictoryCoins(getVictoryCoins() + combo.coinsVector[orderNum - 1] - (orderNum-1));
                setTotalTokens(getActiveRace().getTokens() + getActivePower().getTokens());
                setHaveActiveCombo(true);

                combo.raceVector.erase(combo.raceVector.begin() + orderNum - 1);        //-----------delete selected elements----------
                combo.powerVector.erase(combo.powerVector.begin() + orderNum - 1);
                combo.coinsVector.erase(combo.coinsVector.begin() + orderNum - 1);

            } else {
                cout << "Invalid number. " << endl;
                continue;
            }
    }while(orderNum<1 || orderNum>6);
}


void Player::picks_race(ComboList& combo, int index) {
    cout<<"========================================"<<endl;
    combo.print();
    cout<<"\nplayer"<<index<<" is picking race now: "<<endl;
    pickRace(combo);
    cout<<"\nplayer"<<index<<"\'s current status: "<<endl;
    currentStates();
}


void Player::declineCombo(ComboList &combo, int index) {
    std::string str;
    bool cond = false;
    cout<<"========================================"<<endl;
    cout<<"\nplayer"<<index<<" is playing now: "<<endl;

    do {
        cout << "Do you want to decline your current combo? (y/n)";
        cin >> str;
        if (str == "y" || str == "Y") {
            if (haveDeclineCombo) {                   //if already have declined combo, clear it and add it to combo vector
                combo.raceVector.push_back(declineRace);
                combo.powerVector.push_back(declinePower);
                haveDeclineCombo = false;
            }
            declineRace = activeRace;                 //set current active combo to declined combo
            declinePower = activePower;
            haveDeclineCombo = true;
            haveActiveCombo = false;
            cond = true;
            currentStates();
        } else if (str == "n" || str == "N") {
            cond = true;
            currentStates();
        } else
            cout << "invalid input, type again. " << endl;
    } while (!cond);


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

bool Player::isHaveDeclineCombo() const {
    return haveDeclineCombo;
}

void Player::setHaveDeclineCombo(bool haveDeclineCombo) {
    Player::haveDeclineCombo = haveDeclineCombo;
}

bool Player::isHaveActiveCombo() const {
    return haveActiveCombo;
}

void Player::setHaveActiveCombo(bool haveActiveCombo) {
    Player::haveActiveCombo = haveActiveCombo;
}




