//
// Created by xintong cheng on 2018-02-12.
//

#include "Player.h"
#include "Game.h"
#include "Dice.h"
#include "regions/MapRegions.h"

Player::Player() {
    totalTokens = 0;
    victoryCoins = 5;
    haveActiveCombo=false;
    haveDeclineCombo=false;
}

//constructor, default 5 coins for player 
Player::Player(int id) {
    this->id = id;
    totalTokens = 0;
    victoryCoins = 5;
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


void Player::picks_race(ComboList& combo) {
    cout<<"========================================"<<endl;
    combo.print();
    cout<<"\nplayer"<<getId()<<" is picking race now: "<<endl;
    pickRace(combo);
    cout<<"\nplayer"<<getId()<<"\'s current status: "<<endl;
    currentStates();
}


void Player::declineCombo(ComboList &combo) {
    std::string str;
    bool cond = false;
    cout<<"========================================"<<endl;
    cout<<"\nplayer"<<getId()<<" is playing now: "<<endl;
    Game* game = Game::getGame();
    int playerNum = game->Players.size();
    do {
        cout << "Do you want to decline your current combo? (y/n)";
        cin >> str;
        if (str == "y" || str == "Y") {
            if (haveDeclineCombo) {                   //if already have declined combo, clear it and add it to combo vector
                combo.raceVector.push_back(declineRace);
                combo.powerVector.push_back(declinePower);
                haveDeclineCombo = false;
            }
            reduceTokensToOneInDecline();
            setDeclineRace(activeRace);                 //set current active combo to declined combo
            setDeclinePower(activePower);
            haveDeclineCombo = true;
            haveActiveCombo = false;
            cond = true;
            currentStates();
        } else if (str == "n" || str == "N") {
            cond = true;
            currentStates();
            reduceTokensToOneInActiveAndResetToken();
            conquers(playerNum);
        } else
            cout << "invalid input, type again. " << endl;
    } while (!cond);
}


void Player::conquers(int playerNum){
    cout << "Player[" << id <<"] is start conquer" << endl;
    followingConquest();
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
        conqueredRegion(n);
    } else{
        while(!isBorder){
            cout << "Please choose again,your first conquest region must be a border region" << endl;
            cin >> n;
            isBorder = twoPlayerRegions->getRegion(n)->isBorder();
        }
    }
}


void Player::conqueredRegion(int regionID){
    int requiredTokens = basicRequiredTokens(regionID);
    MapRegions* playerRegions = MapRegions::getMapRegions();

    playerRegions->getRegion(regionID)->setOwner((Owner)id);
    playerRegions->getRegion(regionID)->setPopulation(requiredTokens);
    totalTokens = totalTokens - requiredTokens;

    followingConquest();
}

void Player::enemyLossesWithdrawals(int regionID, int requiredTokens){
    Game* game = Game::getGame();
    MapRegions* playerRegions = MapRegions::getMapRegions();

    int enemyPopulation = playerRegions->getRegion(regionID)->getPopulation();
    int enemyID = (int)playerRegions->getRegion(regionID)->getOwner();

    playerRegions->getRegion(regionID)->setOwner((Owner)id);    //set owner of conquer region to itself
    playerRegions->getRegion(regionID)->setPopulation(requiredTokens); //put populations to conquer region

    int enemyWithdrawalTokens = enemyPopulation/2;

    game->Players[enemyID].increaseTokens(enemyWithdrawalTokens);             //enemy put the withdrawed tokens to one region

    playerRegions->display();
}

void Player::reduceTokensToOneInDecline(){
    MapRegions* playerRegions = MapRegions::getMapRegions();

    for(int j = 1;j <= playerRegions->getRegionsSize();j++){
        if(ownedRegion(j)){
            playerRegions->getRegion(j)->setPopulation(1);
        }
    }
}

void Player::reduceTokensToOneInActiveAndResetToken(){
    int collectTokens;
    MapRegions* playerRegions = MapRegions::getMapRegions();

    for(int j = 1;j <= playerRegions->getRegionsSize();j++){
        if(ownedRegion(j)){
            if( playerRegions->getRegion(j)->getPopulation() > 1){
                collectTokens = playerRegions->getRegion(j)->getPopulation() - 1;
            }
            playerRegions->getRegion(j)->setPopulation(1);
        }
    }
    totalTokens = totalTokens + collectTokens;
}

void Player::redeployTokens(){
    int redeployAgain = false;
    char word;
    cout << "Player[" << id << "], it's your turn to redeploy. Do you want to redeploy? If yes, please input y" << endl;
    cin >> word;
    if(word == 'y'){
        redeployAgain == true;
    }

    while (redeployAgain){
        int tokens = reduceTokens();
        increaseTokens(tokens);
        cout << "Player[" << id << "], Do you want redeploy again? Please input 'y' to redeploy, otherwise stop:" << endl;

        cin >> word;
        if(word == 'y'){
            redeployAgain == true;

        } else {
            redeployAgain == false;
            break;
        }
        showRegions();
    }
    cout << "The regions after redeployed is:" << endl;
    showRegions();
}

int Player::reduceTokens(){
    MapRegions* playerRegions = MapRegions::getMapRegions();
    playerRegions->display();
    int regionID;
    cout << "which region you want to take out tokens?";
    cin >> regionID;

    while(!ownedRegion(regionID)){
        cout << "This region is not yours, please select your region again:";
        cin >> regionID;
    }

    int currentPopulation = playerRegions->getRegion(regionID)->getPopulation();

    while (currentPopulation <= 1){
        cout << "Only one tokens in this region, you cannot deploy this region, please choose regionID again:" << endl;
        cin >> regionID;
    }

    cout << "How many tokens you want to take from Region[" << regionID << "] ?" << endl;
    int tokens;
    cin >> tokens;
    int leftTokens = playerRegions->getRegion(regionID)->getPopulation() - tokens;
    if(leftTokens < 1){
        cout << "You need to leave at lease one population to keep the region. Please choose token number again:" << endl;
        cin >> tokens;
    }

    playerRegions->getRegion(regionID)->setPopulation(currentPopulation - tokens);
    return tokens;
}

void Player::increaseTokens(int n){
    MapRegions* playerRegions = MapRegions::getMapRegions();
    cout << "Please choose regions you want to put tokens:"<< endl;
    int regionID;
    cin >> regionID;
    while (!ownedRegion(regionID)){
        cout << "This region is not owned by you, please choose RegionID again:" << endl;
        cin >> regionID;
    }

    int currentPopulation = playerRegions->getRegion(regionID)->getPopulation();
    playerRegions->getRegion(regionID)->setPopulation(currentPopulation + n);

}

void Player::redeployInLoss(int n){
    int total = n;
    int left = n;
    int put;
    while(left > 0){
        cout << "How many tokens you want to put this time?" << endl;
        cin >> put;
        increaseTokens(put);
        left = total - put;
    }
}

void Player::followingConquest(){
    MapRegions* playerRegions = MapRegions::getMapRegions();

    cout << "Please input the region you want to conquerd:";
    int regionID;
    cin >> regionID;
    while(!connectedToConquestRegion(regionID)){
        cout << "You unable to conquerd this region, since it is not connected to your owned regions" << endl;
        cin >> regionID;
    }
    while(ownedRegion(regionID)){
        cout << "This region is already conquered by you, please choose another region:";
        cin >> regionID;
    }

    int requiredTokes = requiredTokensToConquer(regionID);

    if(enoughTokensToConquer(regionID)){
        if(playerRegions->getRegion(regionID)->getPopulation() != 0){
            enemyLossesWithdrawals(regionID, requiredTokes);
        } else {
            conqueredRegion(regionID);
        }
    } else {
        finalConquestAttempt(regionID);
    }
}

bool Player::ownedRegion(int regionID) {
    MapRegions* playerRegions = MapRegions::getMapRegions();
    return id == (int)playerRegions->getRegion(regionID)->getOwner();
}

//bool Player::emptyRegion(int regionID){
//    MapRegions* playerRegions = MapRegions::getMapRegions();
//    return playerRegions->getRegion(regionID)->getPopulation();
//}

void Player::finalConquestAttempt(int regionID){
    cout << "Since your tokens are not enough to conquer this region, this is your final conquest attempt" << endl;
    cout << "Reinforcement Die is rolling...\n";
    int dieNum = reinforcementDie();
    cout << "The number you rolled is: " << dieNum << endl;
    int lastAttemptTokens = dieNum + totalTokens;
    cout << "After adding the die number, you have "<< lastAttemptTokens << " tokens" << endl;

    if (enoughTokensToConquerInFinalAttempt(regionID, dieNum)){
        setOwnerAndRegionPopulation(regionID,lastAttemptTokens);
        cout << "You conqued this region" << endl;
    } else {
        cout << "Sorry, you don't have enough tokens to conquer this region." << endl;
    }
    showRegions();

}

bool Player::enoughTokensToConquerInFinalAttempt(int regionID , int die){
    return (totalTokens + die >= requiredTokensToConquer(regionID));
}

void Player::setOwnerAndRegionPopulation(int regionID, int population){
    MapRegions* playerRegions = MapRegions::getMapRegions();
    playerRegions->getRegion(regionID)->setPopulation(population);
    playerRegions->getRegion(regionID)->setOwner((Owner)id);
}

int Player::basicRequiredTokens(int regionID){
    int requiredTokens = 2;
    MapRegions* playerRegions = MapRegions::getMapRegions();

    if(playerRegions->getRegion(regionID)->isLostTribes()){
        requiredTokens++;
    }

    if(playerRegions->getRegion(regionID)->hasMountain()){
        requiredTokens ++;
    }
    return requiredTokens;
}

int Player::requiredTokensToConquer(int regionID){

    MapRegions* playerRegions = MapRegions::getMapRegions();
    int requiredTokens = basicRequiredTokens(regionID);
    int population = playerRegions->getRegion(regionID)->getPopulation();

    if(population > 0 && !ownedRegion(regionID)){
        requiredTokens = requiredTokens + population;
    }
    return requiredTokens;
}

bool Player::enoughTokensToConquer(int regionID){
    return totalTokens >= requiredTokensToConquer(regionID);
}

bool Player::connectedToConquestRegion(int regionID){
    vector<int> ownedRegions;

    MapRegions* playerRegions = MapRegions::getMapRegions();
    for (int i = 1; i <= playerRegions->getRegionsSize(); ++i) {

        if(playerRegions->getRegion(i)->getOwnerID() == getId()){
            ownedRegions.push_back(i);
        }
    }

    Game* game = Game::getGame();
    int playerNum = game->getNumOfPlayers();

    Map* map = chooseMap(playerNum);

    for (int i = 0; i < ownedRegions.size(); ++i) {
        if(map->connected(regionID,ownedRegions[i])){
            return true;
        }
    }
    return false;
}

void Player::showRegions() {
    cout << endl;
    cout << endl;
    MapRegions* playerRegions = MapRegions::getMapRegions();
    playerRegions->info();
    playerRegions->display();
}

void Player::scores() {
    cout <<"\nPlayer"<<getId()<<"\'s total score at this turn is: ";
    Game *game = Game::getGame();
    int i=getId();
    iterateMapRegions(i);                   //------player receives 1 coin from each Region his occupy on the map--------

    if (game->Players[i].getActiveRace().getType() == "Dwarves") {      //------player collect additional Victory coins by Race/Power benefit--------
        iterateMapRegions(i, LandMark::Mine);
    } else if (game->Players[i].getActiveRace().getType() == "Humans") {
        iterateMapRegions(i, Landform::FarmLand);
    } else if (game->Players[i].getActiveRace().getType() == "Wizards") {
        iterateMapRegions(i, LandMark::Magic);
    }

    if (game->Players[i].getActivePower().getType() == "Alchemist") {
        game->Players[i].setVictoryCoins(game->Players[i].getVictoryCoins() + 2);
    } else if (game->Players[i].getActivePower().getType() == "Forest") {
        iterateMapRegions(i, Landform::Forest);
    } else if (game->Players[i].getActivePower().getType() == "Hill") {
        iterateMapRegions(i, Landform::Hill);
    } else if (game->Players[i].getActivePower().getType() == "Merchant") {
        iterateMapRegions(i);
    } else if (game->Players[i].getActivePower().getType() == "Swamp") {
        iterateMapRegions(i, Landform::Swamp);
    } else if (game->Players[i].getActivePower().getType() == "Wealthy") {
        if (game->getRound() == 1) {
            game->Players[i].setVictoryCoins(game->Players[i].getVictoryCoins() + 7);
        }
    }
    cout<<game->Players[i].getVictoryCoins()<<endl;

    setPlayed(true);                //----------finish play----------------------------
}

void Player::iterateMapRegions(int playerID, Landform x){                       //Collect 1 bonus Victory coin for Landform Region you occupy
    MapRegions* playerRegions = MapRegions::getMapRegions();
    Game* game = Game::getGame();

    for(int j=1;j<=playerRegions->getRegionsSize();j++){
        if(playerRegions->getRegion(j)->getOwnerID()==game->Players[playerID].getId() && playerRegions->getRegion(j)->getLandform()==x){
            game->Players[playerID].setVictoryCoins(game->Players[playerID].getVictoryCoins()+1);
        }
    }
}



void Player::iterateMapRegions(int playerID, LandMark x){                       //Collect 1 bonus Victory coin for Landmark Region you occupy
    MapRegions* playerRegions = MapRegions::getMapRegions();
    Game* game = Game::getGame();

    for(int j=1;j<=playerRegions->getRegionsSize();j++){
        if(playerRegions->getRegion(j)->getOwnerID()==game->Players[playerID].getId() && playerRegions->getRegion(j)->getLandMark()==x){
            game->Players[playerID].setVictoryCoins(game->Players[playerID].getVictoryCoins()+1);
        }
    }
}

void Player::iterateMapRegions(int playerID){                                   //Collect 1 bonus Victory coin for any Region you occupy
    MapRegions* playerRegions = MapRegions::getMapRegions();
    Game* game = Game::getGame();

    for(int j=1;j<=playerRegions->getRegionsSize();j++){
        if(playerRegions->getRegion(j)->getOwnerID()==game->Players[playerID].getId()){
            game->Players[playerID].setVictoryCoins(game->Players[playerID].getVictoryCoins()+1);
        }
    }
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




