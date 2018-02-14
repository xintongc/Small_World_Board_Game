#include <iostream>
#include"MapLoader.h"
#include "Map.h"
#include "dice.h"


using namespace std;


int main() {


    MapLoader mapLoader;
    mapLoader.openFile("/Users/zncu/CLionProjects/small world/twoPlayer.map");  //twoPlayer.map  //test.txt
    mapLoader.readFile();
    mapLoader.closeInput();
    mapLoader.buildMap();







//    Dice dice;
//    dice.rollingDice();     //one can request a dice being rolled
//    cout<<"The dice is being rolled. The number is: "<<dice.getDiceNum()<<endl;   // the container returns the right number of values



    return 0;
}