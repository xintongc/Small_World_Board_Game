#include <iostream>
#include"MapLoader.h"
#include "Map.h"
#include "dice.h"

using namespace std;


int main() {


    MapLoader mapLoader;
    mapLoader.openFile("/Users/zncu/CLionProjects/small world/twoPlayer.map");
    mapLoader.readFile();
    mapLoader.closeInput();
//    mapLoader.displayMap();
    mapLoader.buildMap();





//    Map map = Map(24);
//    map.addEdge(1,2);
//    map.addEdge(1,6);
//    map.addEdge(2,3);
//    map.addEdge(2,6);
//    map.addEdge(2,7);
//
//    map.display();
//
//
//    Dice dice;
//    dice.rollingDice();     //one can request a dice being rolled
//    cout<<"The dice is being rolled. The number is: "<<dice.getDiceNum()<<endl;   // the container returns the right number of values



    return 0;
}