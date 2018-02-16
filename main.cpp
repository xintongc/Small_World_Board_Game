#include <iostream>
#include"MapLoader.h"
#include "Map.h"
#include "dice.h"

using namespace std;


int main() {




//Part 1

//    Map map = Map(24);
//    map.addEdge(1,2);
//    map.addEdge(1,6);
//    map.addEdge(2,3);
//    map.addEdge(2,6);
//    map.addEdge(2,7);
//
//    map.display();


//Part 1 + 2

    MapLoader mapLoader;
    mapLoader.openFile("/Users/zncu/CLionProjects/small world/twoPlayer.map"); //invaildMap1    twoPlayer
    mapLoader.readFile();
    mapLoader.closeInput();
    mapLoader.buildMap();




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


    return 0;
}
