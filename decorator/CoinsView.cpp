//
// Created by xintong cheng on 2018-04-02.
//

#include "CoinsView.h"
#include "../Player.h"
#include <iostream>
using namespace std;

CoinsView::CoinsView() {}

CoinsView::CoinsView(Observer *basicView) : ViewDecorator(basicView) {}

CoinsView::~CoinsView() {

}
void CoinsView ::Update(const std::string&){}
void CoinsView ::UpdateStatistics(){}
void CoinsView ::UpdateBarGraph(){}
void CoinsView:: showInfo(Observer*){
}

void CoinsView:: showCoins(Observer* observer){
    cout<<"==== From Decorator pattern ==== ";
    cout <<"Player "<< ((Player*)observer)->getId() << " has "<<((Player*)observer)->getVictoryCoins()<<" coins."<<endl;
}
void CoinsView:: showHands(Observer* observer){}


void CoinsView ::showInfo(){

}