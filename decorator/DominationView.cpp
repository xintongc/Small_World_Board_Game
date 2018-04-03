//
// Created by xintong cheng on 2018-04-02.
//

#include "DominationView.h"
using namespace std;

DominationView::DominationView(Observer *basicView) : ViewDecorator(basicView) {}

DominationView::DominationView() {}

DominationView::~DominationView() {

}
void DominationView::showInfo(){

}


void DominationView::showInfo(Observer* observer) {
    UpdateStatistics(observer);
}

void DominationView ::Update(const std::string&){}
void DominationView ::UpdateStatistics(){};


void DominationView ::UpdateStatistics(Observer* observer){
    cout<<"==== From Decorator pattern ==== ";
    cout <<"Player "<< ((Player*)observer)->getId() << ": has " << ((Player*)observer)->calculatePercentage() << "% regions."<<endl;

}
void DominationView ::UpdateBarGraph(){}


void DominationView:: showCoins(Observer* observer){}
void DominationView:: showHands(Observer* observer){}
