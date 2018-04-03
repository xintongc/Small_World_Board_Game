//
// Created by xintong cheng on 2018-04-02.
//

#include "HandsView.h"
#include "../Player.h"
#include <iostream>
using namespace std;

HandsView::HandsView() {}

HandsView::~HandsView() {}

HandsView::HandsView(Observer *basicView) : ViewDecorator(basicView) {}


void HandsView ::Update(const std::string&){}
void HandsView ::UpdateStatistics(){}
void HandsView ::UpdateBarGraph(){}

void HandsView::showInfo(){}
void HandsView::showInfo(Observer* observer) {}
void HandsView:: showCoins(Observer* observer){}


void HandsView:: showHands(Observer* observer){cout<<"==== From Decorator pattern ==== ";
    cout <<"Player "<< ((Player*)observer)->getId() << ": has"<<endl;
    cout<<"active race" << ((Player*)observer)->getActiveRace().getType()<<endl;
    cout<<"active power" << ((Player*)observer)->getActivePower().getType()<<endl;
    cout<<"decline race" << ((Player*)observer)->getDeclineRace().getType()<<endl;
    cout<<"decline race" << ((Player*)observer)->getDeclinePower().getType()<<endl;
}