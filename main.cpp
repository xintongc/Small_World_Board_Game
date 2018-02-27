#include <iostream>
#include"MapLoader.h"
#include "Map.h"
#include "Dice.h"
#include "Combo.h"
#include "Race/Amazons.h"

using namespace std;


int main() {


//    MapLoader mapLoader;
//    mapLoader.openFile("/Users/zncu/CLionProjects/small world/twoPlayer.map");
//    mapLoader.readFile();
//    mapLoader.closeInput();
////    mapLoader.displayMap();
//    mapLoader.buildMap();


//    Map map = Map(9);
//    map.addEdge(1,2);
//    map.addEdge(1,6);
//    map.addEdge(2,3);
//    map.addEdge(2,6);
//    map.addEdge(2,7);
//
//    map.display();
//
    //part 3
//    Dice dice;
//    dice.rollingDice();     //one can request a dice being rolled
//    cout<<"The dice is being rolled. The number is: "<<dice.getDiceNum()<<endl;   // the container returns the right number of values

    //part 4
//    Player player1;
//    cout<<"Player1 rolling the dice is "<<player1.reinforcementDie()<<endl;
//    cout<<"Players's coins are "<<player1.getCoins()<<endl;
//    player1.conquers();

    //part 5
//    Amazons amazons1;
//    cout<<"amazons1's tokens are "<<amazons1.getTokens()<<endl;
//
//    Flying flying;
//    cout<<"flying's tokens are "<<flying.getTokens()<<endl;
//
//    Mountains mountains;

//    Combo co;
//    co.initial();
//    co.listAllPairs();
//    //co.printStacks();
    vector <Combo> fivePairs = co.initialCombo();
//    co.stackTop();
//
    for(int i=0;i<5;i++){
        fivePairs[i].getComboPower();
        fivePairs[i].getComboRace();

        cout<<fivePairs[i].getComboRace().getTokens()<<endl;
        cout<<fivePairs[i].getComboRace().getSkill()<<endl;
    }

     fivePairs[1].getComboRace();

    Amazons amazons;
    Race* r = &amazons;
    r->raceSkill();

    return 0;
}