//
// Created by xintong cheng on 2018-02-12.
//

#include "Player.h"
#include "Game.h"
#include "Dice.h"
#include "regions/MapRegions.h"

//constructor, default 5 coins for player 
Player::Player(int id) {
    this->id = id;
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

Map* Player::chooseMap(int playerNum){
    if(playerNum == 2){
        return Map::getMap(24);
    } else if(playerNum == 3){
        return Map::getMap(31);
    }else if(playerNum == 4){
        return Map::getMap(40);
    }else if(playerNum == 5){
        return Map::getMap(48);
    }
}

//bool Player::isBorder(MapRegions* regions,int regionID){
//    return regions->getRegion(regionID)->isBorder();
//}  not working (functin pointer)

void Player::firstConquest(int playerNum){
    cout << "Please select the Region you want to first conquest." << endl;
    int n;
    cin >> n;

    MapRegions* twoPlayerRegions = MapRegions::getMapRegions();
    bool isBorder = twoPlayerRegions->getRegion(n)->isBorder();

    if(isBorder){
        conquerRegion(n);
    } else{
        while(!isBorder){
            cout << "Please choose again,your first conquest region must be a border region" << endl;
            cin >> n;
  //          isBorder = isBorder(twoPlayerRegions,n);
            isBorder = twoPlayerRegions->getRegion(n)->isBorder();
        }
    }
}

void Player::conquerRegion(int regionID){
    int requiredTokens = 2;
    MapRegions* playerRegions = MapRegions::getMapRegions();

    if(playerRegions->getRegion(regionID)->isLostTribes()){
        requiredTokens++;
    }

    if(playerRegions->getRegion(regionID)->hasMountain()){
        requiredTokens ++;
    }

    if(requiredTokens > totalTokens){
        cout << "You don't have enough tokens to conquer this region, please choose again" << endl;
        cin >> regionID;
        conquerRegion(regionID);
    } else {
        playerRegions->getRegion(regionID)->setOwner((Owner)id);
        playerRegions->getRegion(regionID)->setPopulation(requiredTokens);
        totalTokens = totalTokens - requiredTokens;
    }

}

void Player::enemyLossesWithdrawals(int regionID, int requiredTokens){
    Game* game = Game::getGame();
    MapRegions* playerRegions = MapRegions::getMapRegions();

    int enemyPopulation = playerRegions->getRegion(regionID)->getPopulation();
    int enemyID = (int)playerRegions->getRegion(regionID)->getOwner();

    playerRegions->getRegion(regionID)->setOwner((Owner)id);    //set owner of conquer region to self
    playerRegions->getRegion(regionID)->setPopulation(requiredTokens); //put populations to conquer region

    int enemyWithdrawalTokens = game->Players[enemyID].getTotalTokens()/2;
    int enemyAvailableTokens = game->Players[enemyID].getTotalTokens();
    int enemyLeftTokens = enemyAvailableTokens - enemyWithdrawalTokens;
    game->Players[enemyID].setTotalTokens(enemyLeftTokens);             //withdrawl enemy's tokens
    game->Players[enemyID].redeployTokens(enemyLeftTokens);  //let enemy redeploy the tokens

}

void Player::redeployTokens(int tokens){
    MapRegions* playerRegions = MapRegions::getMapRegions();
    playerRegions->display();
    int regionID;
    cout << "Player[" << id << "], your region is been conquerd, please select your left regions to redeploy your tokens:";
    cin >> regionID;

    while(playerRegions->getRegion(regionID)->getId() != id){
        cout << "This region is not yours, please select your region again:";
        cin >> regionID;
    }

    int currentPopulation = playerRegions->getRegion(regionID)->getPopulation();
    playerRegions->getRegion(regionID)->setPopulation(currentPopulation + tokens);  //redeploy tokens to select regions which owned by player

}

//void Player::followingConquest(){
//
//}

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

int Player::getId() const {
    return id;
}

void Player::setId(int id) {
    Player::id = id;
}




