#include <iostream>
#include "Map.h"
#include "dice.h"
#include "Player.h"

using namespace std;


int main() {

    Map map = Map(24);
//    map.addEdge(1,2);
//    map.addEdge(1,6);
//    map.addEdge(2,3);
//    map.addEdge(2,6);
//    map.addEdge(2,7);

    //map.display();

    Player player1;
    cout<<"Player1 rolling the dice is "<<player1.reinforcementDie()<<endl;
    cout<<player1.getCoins()<<endl;

//    Dice dice;
//    dice.rollingDice();     //one can request a dice being rolled
//    cout<<"The dice is being rolled. The number is: "<<dice.getDiceNum()<<endl;   // the container returns the right number of values

    return 0;
}