//
// Created by xintong cheng on 2018-02-12.
//

#include "Player.h"
#include "Game.h"
#include "Dice.h"
#include "regions/MapRegions.h"
#include "decorator/BasicView.h"
#include "decorator/DominationView.h"
#include "decorator/HandsView.h"
#include "decorator/CoinsView.h"

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

Player::Player(int id, PlayerStrategy* strategy){
    this->id = id;
    totalTokens = 0;
    victoryCoins = 5;
    haveActiveCombo=false;
    haveDeclineCombo=false;
    this->strategy = strategy;
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
    orderNum = validateInt("Please select the orderNum of combo: ",1,6);

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

    }
}


void Player::picks_race(ComboList& combo) {
    Game* game = Game::getGame();
    game->Notify("Picks race", this);   //update player is picking race
    //cout<<"========================================"<<endl;
    combo.print();
    //cout<<"\nplayer"<<getId()<<" is picking race now: "<<endl;
    pickRace(combo);
    cout<<"\nplayer"<<getId()<<"\'s current status: "<<endl;
    currentStates();
    game->notifyHands();

}


void Player::declineCombo(ComboList &combo) {
    std::string str;
    bool cond = false;
    //cout<<"========================================"<<endl;
    //cout<<"\nplayer"<<getId()<<" is playing now: "<<endl;
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
            game->notifyHands();
        } else if (str == "n" || str == "N") {
            cond = true;
            reduceTokensToOneInActiveAndResetToken();
            currentStates();

            game->notifyHands();

            conquers(playerNum);
        } else
            cout << "invalid input, type again. " << endl;
    } while (!cond);
}


void Player::conquers(int playerNum){
    Game* game = Game::getGame();
    game->Notify("Conquers some regions", this);    //update player is conquering region
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


void Player::firstConquest(int playerNum){
    Game* game = Game::getGame();
    game->Notify("First conquers some regions", this);  ////update player is first conquering region

    int totalRegionNum = game->getRegionNumber();
    int regionID = validateInt("\nPlease select the Region you want to first conquest: ",1,totalRegionNum);


    MapRegions* playerRegions = MapRegions::getMapRegions();
    bool isBorder = playerRegions->getRegion(regionID)->isBorder();
    bool isEnemyRegion = playerRegions->getRegion(regionID)->getPopulation() != 0;
    int requiredTokes = requiredTokensToConquer(regionID);

    if(isBorder && isEnemyRegion){
        enemyLossesWithdrawals(regionID,requiredTokes);
    } else if(isBorder){
        conqueredRegion(regionID);
    } else{

        while(!isBorder){
            regionID = validateInt("Please choose again,your first conquest region must be a border region",1,totalRegionNum);
            isBorder = playerRegions->getRegion(regionID)->isBorder();
        }
        conqueredRegion(regionID);
    }
}


void Player::conqueredRegion(int regionID){
    Game* game = Game::getGame();
    game->Notify(" conqured a region", this);   //update player is conquering region

    int requiredTokens = basicRequiredTokens(regionID);
    MapRegions* playerRegions = MapRegions::getMapRegions();

    playerRegions->getRegion(regionID)->setOwner((Owner)id);
    playerRegions->getRegion(regionID)->setPopulation(requiredTokens);
    totalTokens = totalTokens - requiredTokens;

    game->NotifyStatistics();       //update player's percentage of owned regions
    game->NotifyBarGraph();         //update player's bar graph

    game->notifyConquerAndLoss();   //Display the percentage of regions owned/lost for each player

    followingConquest();
}

void Player::enemyLossesWithdrawals(int regionID, int requiredTokens){
    Game* game = Game::getGame();
    MapRegions* playerRegions = MapRegions::getMapRegions();
    game->NotifyStatistics();   //update player's percentage of owned regions
    game->NotifyBarGraph();     //update player's bar graph

    game->notifyConquerAndLoss();   //Display the percentage of regions owned/lost for each player

    int enemyPopulation = playerRegions->getRegion(regionID)->getPopulation();
    int enemyID = (int)playerRegions->getRegion(regionID)->getOwner();

    playerRegions->getRegion(regionID)->setOwner((Owner)id);    //set owner of conquer region to itself
    playerRegions->getRegion(regionID)->setPopulation(requiredTokens); //put populations to conquer region

    int enemyWithdrawalTokens = enemyPopulation/2;

    cout << "Player[" << enemyID <<"] your region [" << regionID << "] has been conqured by enemy, please redeploy" << endl;
    game->Players[enemyID].increaseTokens(enemyWithdrawalTokens);             //enemy put the withdrawed tokens to one region

    followingConquest();
}

void Player::reduceTokensToOneInDecline(){
    MapRegions* playerRegions = MapRegions::getMapRegions();

    for(int j = 1;j <= playerRegions->getRegionsSize();j++){
        if(ownedRegion(j)){
            playerRegions->getRegion(j)->setPopulation(1);
        }
    }
    totalTokens=0;
}

void Player::reduceTokensToOneInActiveAndResetToken(){
    int collectTokens;
    MapRegions* playerRegions = MapRegions::getMapRegions();

    for(int j = 1;j <= playerRegions->getRegionsSize();j++){
        if(ownedRegion(j)){
            if( playerRegions->getRegion(j)->getPopulation() > 1){
                collectTokens = playerRegions->getRegion(j)->getPopulation() - 1;
                totalTokens = totalTokens + collectTokens;
            }
            playerRegions->getRegion(j)->setPopulation(1);
        }
    }
}

void Player::redeployTokens(){


    int redeployAgain = false;
    char word;
    Game* game = Game::getGame();
    game->Notify("it's your turn to redeploy.Do you want to redeploy? If yes, please input y", this);   //update player is redeploying 
    cin >> word;
    if(word == 'y'){
        redeployAgain = true;
    }

    while (redeployAgain){
        int tokens = reduceTokens();
        increaseTokens(tokens);
        cout << "Player[" << id << "], Do you want redeploy again? Please input 'y' to redeploy, otherwise stop:" << endl;

        cin >> word;
        if(word == 'y'){
            redeployAgain = true;

        } else {
            redeployAgain = false;
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

    int regionSize = playerRegions->getRegionsSize();

//    cout << "regionSize: " << regionSize <<endl;

    int regionID = validateInt("which region you want to take out tokens?",1,regionSize);

    while(!ownedRegion(regionID)){
        regionID = validateInt("This region is not yours, please select your region again:",1,regionSize);
    }

    int currentPopulation = playerRegions->getRegion(regionID)->getPopulation();

    while (currentPopulation <= 1){
        regionID = validateInt("Only one tokens in this region, you cannot deploy this region, please choose regionID again:\n",1,regionSize);
    }

    cout << "How many tokens you want to take from Region[" << regionID << "] ?" << endl;
    int tokens;
    tokens = validateInt("",0,20);
    int leftTokens = playerRegions->getRegion(regionID)->getPopulation() - tokens;
    if(leftTokens < 1){
        tokens = validateInt("You need to leave at lease one population to keep the region. Please choose token number again:\n",0,20);
    }

    playerRegions->getRegion(regionID)->setPopulation(currentPopulation - tokens);
    return tokens;
}

void Player::increaseTokens(int n){
    MapRegions* playerRegions = MapRegions::getMapRegions();
    int regionSize = playerRegions->getRegionsSize();
    int regionID;
    regionID = validateInt("Please choose regions you want to put tokens:\n",1,regionSize);
    while (!ownedRegion(regionID)){
        regionID = validateInt("Please choose regions you want to put tokens:\n",1,regionSize);
    }

    int currentPopulation = playerRegions->getRegion(regionID)->getPopulation();
    playerRegions->getRegion(regionID)->setPopulation(currentPopulation + n);

}

void Player::followingConquest(){
    MapRegions* playerRegions = MapRegions::getMapRegions();

    int regionSize = playerRegions->getRegionsSize();

    int regionID;
    regionID = validateInt("Please input the region you want to conquerd:",1,regionSize);

    while(!connectedToConquestRegion(regionID)){
        regionID = validateInt("You unable to conquerd this region, since it is not connected to your owned regions\n",1,regionSize);
    }
    while(ownedRegion(regionID)){
        regionID = validateInt("This region is already conquered by you, please choose another region:",1,regionSize);
    }

    int requiredTokes = requiredTokensToConquer(regionID);

    if(enoughTokensToConquer(regionID)){
        if(playerRegions->getRegion(regionID)->getPopulation() != 0){
            cout << "You conqured emeny region" << endl;
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


void Player::finalConquestAttempt(int regionID){
    cout << "\nSince your tokens are not enough to conquer this region, this is your final conquest attempt" << endl;
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
    Game *game = Game::getGame();
    game->Notify("Scores.", this);      //update player's score
    cout <<"Player"<<getId()<<"\'s total score at this turn is: ";
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

    game->notifyCoins();    

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

double Player:: calculatePercentage(){
    MapRegions* playerRegions = MapRegions::getMapRegions();
    int regionCounter = 0;
    for(int j=1;j<=playerRegions->getRegionsSize();j++){
        if(ownedRegion(j)){
            regionCounter++;
        }
    }
    Game* game = Game::getGame();
    int regionNumber = game->getRegionNumber();

    double result = (double)regionCounter / regionNumber * 100;
    return result;

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

int Player::getTotalRegionNumber() const {
    Game* game = Game::getGame();
    return game->getRegionNumber();
}

void Player::showBarGraph(){
    int percentage = calculatePercentage();
    for(int i = 0; i < percentage; i++){
        cout << "*";
    }
}

int Player::validateInt(string str, int from, int to){

    bool done = false; 
    int n;
    while(!done){
        cout << str;
        try{
            cin >> n;
            if(cin.fail()){      //if the input is not a interger, throw exception
                cin.clear();    //This corrects the stream.
                cin.ignore();   //This skips the left over stream data.
                throw domain_error("wrong type");
            }
            if(n > to || n < from){  //if the input is not between to-from, throw exception
                throw domain_error("Invaild input. Please input again.");
            }

            done = true;
        }catch (exception& e){
            cout << "Standard exception: " << e.what() << endl;
        }

    }

    return n;

}



//=====================observer pattern part 1================================
//overriding method, showing each player's current status
void Player::Update(const std::string& str)
{
    cout<<"\n==== From Player observer pattern ==== ";
    cout <<"Player "<< getId() << ": " << str << endl;
}

//=====================observer pattern part 2[================================
//overriding method, showing percentage of the world is currently being controlled by each player
void Player::UpdateStatistics() {
    cout<<"==== From Statistic observer pattern ==== ";
    cout <<"Player "<< getId() << ": has " << calculatePercentage() << "% regions."<<endl;

}

//overriding method, showing bar graph depicting what percentage of the world is currently being controlled by each player
void Player::UpdateBarGraph(){
    cout<<"==== From Statistic observer pattern ==== ";
    cout <<"Player "<< getId() << ": ";
    showBarGraph();
    cout<<endl;

}


void Player::setStrategy(PlayerStrategy *strategy) {
    this->strategy = strategy;
}


//=====================strategy pattern part 3================================
void Player::firstConquestByStrategy(int playerNum){
    strategy->firstConquestByStrategy(this, playerNum);
}

void Player::picks_raceByStrategy(ComboList& combo){
    strategy->picks_raceByStrategy(this,combo);
}

void Player::conquersByStrategy(int playerNum){
    strategy->conquersByStrategy(this,playerNum);
}

void Player::declineComboByStrategy(ComboList &combo){
    strategy->declineComboByStrategy(this, combo);
}

void Player::redeployTokensByStrategy(){
    strategy->redeployTokensByStrategy(this);
}

//=====================decorator pattern part 4================================
void Player::showInfo(){
    BasicView* basicView = new BasicView();
    basicView->showInfo();
}

void Player::showInfo(Observer* observer) {
    DominationView *dominationView = new DominationView();
    dominationView->showInfo(observer);
}


void Player::showCoins(Observer* observer){
    CoinsView* coinsView = new CoinsView();
    coinsView->showCoins(observer);
}
void Player::showHands(Observer* observer){

    HandsView *handsView = new HandsView();
    handsView->showHands(observer);
}
