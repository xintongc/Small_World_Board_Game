//
// Created by xintong cheng on 2018-04-02.
//

#include "ViewDecorator.h"
ViewDecorator::ViewDecorator() {}
ViewDecorator::ViewDecorator(Observer *basicView) : basicView(basicView) {}
ViewDecorator::~ViewDecorator() {

}

void ViewDecorator ::Update(const std::string&){}
void ViewDecorator ::UpdateStatistics(){}
void ViewDecorator ::UpdateBarGraph(){}


void ViewDecorator ::showInfo(){
    basicView->showInfo();
}

void ViewDecorator ::showInfo(Observer* observer){}
void ViewDecorator:: showCoins(Observer* observer){}
void ViewDecorator:: showHands(Observer* observer){}