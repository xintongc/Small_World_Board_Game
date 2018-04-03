//
// Created by xintong cheng on 2018-04-02.
//

#include <iostream>
#include "BasicView.h"

using namespace std;

BasicView ::~BasicView(){

}

BasicView ::BasicView(){

}

 void BasicView ::Update(const std::string&){}
 void BasicView ::UpdateStatistics(){}
 void BasicView ::UpdateBarGraph(){}


 void BasicView ::showInfo(){
     std::cout << "==== From View of basicGameStasticsObserver==== ";
     std::cout<< "This is the " << ++turnRun << " turn of the game. \n" << endl;
 }

void BasicView:: showInfo(Observer*){
}

void BasicView:: showCoins(Observer* observer){}
void BasicView:: showHands(Observer* observer){}